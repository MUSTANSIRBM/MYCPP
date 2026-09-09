#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <chrono>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <cmath>
#include <type_traits>
#include <variant>
#include <limits>
    
class Enemy;

struct Vector3 {
    float x, y, z;
};

struct Portal {
    Vector3 left;
    Vector3 right;
};

struct Polygon {
    int id;
    float centerX, centerY, centerZ;
    std::vector<int> neighbors;
    std::vector<float> costs;
    std::vector<Vector3> vertices;
};

enum class AIState {
    IDLE,
    PATROL,
    CHASE,
    ATTACK,
    FLEES, // Renamed to FLEE in logic
    FLEE = FLEES,
    DEAD
};

enum class BTNodeStatus {
    SUCCESS,
    FAILURE,
    RUNNING
};

enum class BlackboardKey {
    PLAYER_POSITION,
    PLAYER_POLYGON,
    ENEMY_POSITION,
    ENEMY_HEALTH,
    ENEMY_AMMO,
    TARGET_POLYGON,
    ALLY_HEALTH,
    IS_DEAD,
    IS_IN_COMBAT
};

using BlackboardValue = std::variant<int, float, bool, Vector3, std::string>;

class Blackboard {
private:
    std::unordered_map<BlackboardKey, BlackboardValue> data;
public:
    template<typename T>
    void set(BlackboardKey key, T value) {
        data[key] = value;
    }

    template<typename T>
    T get(BlackboardKey key) const {
        auto it = data.find(key);
        if (it == data.end()) return T{};

        if (const T* val = std::get_if<T>(&it->second)) {
            return *val;
        }
        return T{};
    }

    bool has(BlackboardKey key) const {
        return data.find(key) != data.end();
    }

    void remove(BlackboardKey key) {
        data.erase(key);
    }

    void clear() {
        data.clear();
    }
};

class BTNode {
public:
    virtual BTNodeStatus execute(Enemy* enemy) = 0;
    virtual ~BTNode() {}
};

class Selector : public BTNode {
private:
    std::vector<BTNode*> children;
public:
    Selector(const std::vector<BTNode*>& nodes) : children(nodes) {}
    ~Selector() override {
        for (auto child : children) {
            delete child;
        }
    }
    BTNodeStatus execute(Enemy* enemy) override {
        for (auto child : children) {
            BTNodeStatus status = child->execute(enemy);
            if (status == BTNodeStatus::SUCCESS) return BTNodeStatus::SUCCESS;
            if (status == BTNodeStatus::RUNNING) return BTNodeStatus::RUNNING;
        }
        return BTNodeStatus::FAILURE;
    }
};

class Sequence : public BTNode {
private:
    std::vector<BTNode*> children;
public:
    Sequence(const std::vector<BTNode*>& nodes) : children(nodes) {}
    ~Sequence() override {
        for (auto child : children) {
            delete child;
        }
    }
    BTNodeStatus execute(Enemy* enemy) override {
        for (auto child : children) {
            BTNodeStatus status = child->execute(enemy);
            if (status == BTNodeStatus::FAILURE) return BTNodeStatus::FAILURE;
            if (status == BTNodeStatus::RUNNING) return BTNodeStatus::RUNNING;
        }
        return BTNodeStatus::SUCCESS;
    }
};

class ConditionNode : public BTNode {
private:
    bool (Enemy::* condition)();
public:
    ConditionNode(bool (Enemy::* cond)()) : condition(cond) {}
    BTNodeStatus execute(Enemy* enemy) override;
};

class ActionNode : public BTNode {
private:
    void (Enemy::* action)();
public:
    ActionNode(void (Enemy::* act)()) : action(act) {}
    BTNodeStatus execute(Enemy* enemy) override;
};

struct Entrance {
    int id;
    int polygon1, polygon2;
    int cluster1, cluster2;
    Vector3 position;
    Entrance(int _id, int p1, int p2, int c1, int c2, Vector3 pos) : id(_id),
        polygon1(p1), polygon2(p2),
        cluster1(c1), cluster2(c2),
        position(pos) {
    }
};

struct Cluster {
    int id;
    float centerx, centery, centerz;
    std::vector<int> polygonids;
    std::vector<int> entranceids; // Fixed typo

    std::unordered_map<int, std::unordered_map<int, std::vector<int>>> intrapaths;
    std::unordered_map<int, std::unordered_map<int, float>> intracosts;
};

class NavMesh {
private:
    std::vector<Polygon> polygons;
    std::unordered_set<int> BlockedPolygons;

    std::vector<float> dist;
    std::vector<int> parent;
    std::vector<bool> inOpenlist;
    std::vector<bool> inClosedlist;
    int mapsize;

    std::vector<Cluster> clusters;
    std::vector<Entrance> entrances; 
    int clusterSize;
    bool hpaInitialized; 

    std::unordered_map<int, int> polygonToClusterMap;

public:
    NavMesh() : mapsize(0), clusterSize(2), hpaInitialized(false) {}

    void finalizeMap() { 
        mapsize = polygons.size();
        dist.resize(mapsize);
        parent.resize(mapsize);
        inOpenlist.resize(mapsize, false);
        inClosedlist.resize(mapsize, false);
    }

    void resetbuffers() {
        std::fill(dist.begin(), dist.end(), std::numeric_limits<float>::max());
        std::fill(parent.begin(), parent.end(), -1);
        std::fill(inOpenlist.begin(), inOpenlist.end(), false);
        std::fill(inClosedlist.begin(), inClosedlist.end(), false);
    }

    void addPolygon(int id, float x, float y, float z, const std::vector<Vector3>& verts = {}) {
        polygons.push_back({ id, x, y, z, {}, {}, verts });
    }

    void addCluster(int id, const std::vector<int>& polygonids) { 
        Cluster cluster;
        cluster.id = id;
        cluster.polygonids = polygonids;

        float sumx = 0.0f, sumy = 0.0f, sumz = 0.0f;
        for (int polyid : polygonids) {
            Vector3 center = getPolygonCenter(polyid);
            sumx += center.x;
            sumy += center.y;
            sumz += center.z;
            polygonToClusterMap[polyid] = id; 
        }

        cluster.centerx = sumx / static_cast<float>(polygonids.size());
        cluster.centery = sumy / static_cast<float>(polygonids.size());
        cluster.centerz = sumz / static_cast<float>(polygonids.size());

        clusters.push_back(cluster);

        std::cout << "Cluster [" << id << "] created at ("
            << cluster.centerx << ", " << cluster.centery << ", " << cluster.centerz
            << ") containing " << polygonids.size() << " polygons: { ";
        for (int pid : polygonids) {
            std::cout << pid << " ";
        }
        std::cout << "}\n";
    }

    void findEntrances() { // Fixed typo
        std::cout << "\n=====================================================\n";
        std::cout << ">>> FINDING CLUSTER ENTRANCES <<<\n";
        std::cout << "=====================================================\n";

        entrances.clear();
        int entranceId = 0;

        for (auto& cluster : clusters) {
            for (int polyid : cluster.polygonids) {
                for (size_t i = 0; i < polygons[polyid].neighbors.size(); i++) {
                    int neighborid = polygons[polyid].neighbors[i];

                    // O(1) Cluster lookup
                    auto it = polygonToClusterMap.find(neighborid);
                    if (it == polygonToClusterMap.end()) continue;
                    int neighborcluster = it->second;

                    // Cross-cluster connection found
                    if (neighborcluster != cluster.id) {
                        Vector3 pos1 = getPolygonCenter(polyid);
                        Vector3 pos2 = getPolygonCenter(neighborid);
                        Vector3 entrancepos = {
                            (pos1.x + pos2.x) / 2.0f,
                            (pos1.y + pos2.y) / 2.0f,
                            (pos1.z + pos2.z) / 2.0f
                        };

                        bool exists = false;
                        for (const auto& e : entrances) {
                            if ((e.polygon1 == polyid && e.polygon2 == neighborid) ||
                                (e.polygon1 == neighborid && e.polygon2 == polyid)) {
                                exists = true;
                                break;
                            }
                        }

                        if (!exists) {
                            Entrance e(entranceId++, polyid, neighborid, cluster.id, neighborcluster, entrancepos);
                            entrances.push_back(e);

                            cluster.entranceids.push_back(e.id);
                            clusters[neighborcluster].entranceids.push_back(e.id);

                            std::cout << "  Entrance [" << e.id << "]: "
                                << "Polygon " << polyid << " (Cluster " << cluster.id << ") "
                                << "<-> Polygon " << neighborid << " (Cluster " << neighborcluster << ")\n";
                            std::cout << "    Position: (" << entrancepos.x << ", "
                                << entrancepos.y << ", " << entrancepos.z << ")\n";
                        }
                    }
                }
            }
        }

        std::cout << "\nTotal Entrances Created: " << entrances.size() << "\n";
        std::cout << "=====================================================\n\n";
    }

    void computeIntraPaths() { // Fixed typo
        std::cout << "\n=====================================================\n";
        std::cout << ">>> COMPUTING INTRA-CLUSTER PATHS <<<\n";
        std::cout << "=====================================================\n";

        for (auto& cluster : clusters) {
            std::cout << "Cluster [" << cluster.id << "]:\n";

            for (size_t i = 0; i < cluster.entranceids.size(); i++) {
                for (size_t j = i + 1; j < cluster.entranceids.size(); j++) {
                    int entrance1id = cluster.entranceids[i];
                    int entrance2id = cluster.entranceids[j];

                    Entrance& e1 = entrances[entrance1id];
                    Entrance& e2 = entrances[entrance2id];

                    int startpoly = (std::find(cluster.polygonids.begin(), cluster.polygonids.end(), e1.polygon1) != cluster.polygonids.end()) ? e1.polygon1 : e1.polygon2;
                    int goalpoly = (std::find(cluster.polygonids.begin(), cluster.polygonids.end(), e2.polygon1) != cluster.polygonids.end()) ? e2.polygon1 : e2.polygon2;

                    std::vector<int> path = aStar(startpoly, goalpoly);

                    if (!path.empty()) {
                        float cost = dist[goalpoly]; // Read immediately before next aStar call!

                        cluster.intrapaths[entrance1id][entrance2id] = path;
                        cluster.intrapaths[entrance2id][entrance1id] = path;
                        cluster.intracosts[entrance1id][entrance2id] = cost;
                        cluster.intracosts[entrance2id][entrance1id] = cost;

                        std::cout << "  Entrance " << entrance1id << " <-> Entrance " << entrance2id
                            << " | Cost: " << cost << " | Path Length: " << path.size() << "\n";
                    }
                }
            }
            std::cout << "\n";
        }
        std::cout << "=====================================================\n\n";
    }

    void initializeHPA() { // Fixed typo
        std::cout << "\n";
        std::cout << "=====================================================\n";
        std::cout << "         INITIALIZING HPA* SYSTEM                    \n";
        std::cout << "=====================================================\n";

        if (clusters.empty()) {
            std::cout << "ERROR: No clusters defined! Use addCluster() first.\n";
            return;
        }
        findEntrances();
        computeIntraPaths();

        hpaInitialized = true;

        std::cout << "=====================================================\n";
        std::cout << "✅ HPA* INITIALIZATION COMPLETE!\n";
        std::cout << "   - Clusters: " << clusters.size() << "\n";
        std::cout << "   - Entrances: " << entrances.size() << "\n";
        std::cout << "   - System Ready for Hierarchical Pathfinding\n";
        std::cout << "=====================================================\n\n";
    }

    std::vector<int> hpaStar(int start, int goal) { // Fixed typo & completely rewritten
        std::cout << "\n=====================================================\n";
        std::cout << ">>> HPA* PATHFINDING: " << start << " → " << goal << " <<<\n";
        std::cout << "=====================================================\n";

        if (!hpaInitialized) {
            std::cout << "ERROR: HPA* not initialized! Falling back to regular A*\n";
            return aStar(start, goal);
        }

        if (start == goal) return { start };

        auto startIt = polygonToClusterMap.find(start);
        auto goalIt = polygonToClusterMap.find(goal);

        if (startIt == polygonToClusterMap.end() || goalIt == polygonToClusterMap.end()) {
            std::cout << "ERROR: Start or goal polygon not in any cluster!\n";
            return aStar(start, goal);
        }

        int startClusterId = startIt->second;
        int goalClusterId = goalIt->second;

        std::cout << "Start Polygon " << start << " is in Cluster " << startClusterId << "\n";
        std::cout << "Goal Polygon " << goal << " is in Cluster " << goalClusterId << "\n";

        if (startClusterId == goalClusterId) {
            std::cout << "Both in same cluster! Using direct A*\n";
            std::cout << "=====================================================\n\n";
            return aStar(start, goal);
        }

        std::vector<int> startEntrances;
        std::vector<int> goalEntrances;

        for (const auto& e : entrances) {
            if (e.cluster1 == startClusterId || e.cluster2 == startClusterId) {
                startEntrances.push_back(e.id);
            }
            if (e.cluster1 == goalClusterId || e.cluster2 == goalClusterId) {
                goalEntrances.push_back(e.id);
            }
        }

        std::cout << "Start Cluster Entrances: ";
        for (int eid : startEntrances) std::cout << eid << " ";
        std::cout << "\nGoal Cluster Entrances: ";
        for (int eid : goalEntrances) std::cout << eid << " ";
        std::cout << "\n\n";

        // --- ABSTRACT GRAPH A* SEARCH ---
        struct AbstractNode {
            int entranceId;
            float gCost;
            float fCost;
            bool operator>(const AbstractNode& other) const {
                return fCost > other.fCost;
            }
        };

        std::priority_queue<AbstractNode, std::vector<AbstractNode>, std::greater<AbstractNode>> abstractPQ;
        std::unordered_map<int, float> abstractG;
        std::unordered_map<int, int> abstractParent;

        auto heuristicEntrance = [&](int eId, int targetClusterId) {
            const Entrance& e = entrances[eId];
            Vector3 eCenter = e.position;
            Vector3 gCenter = getClusterCenter(targetClusterId);
            float dx = eCenter.x - gCenter.x;
            float dy = eCenter.y - gCenter.y;
            float dz = eCenter.z - gCenter.z;
            return std::sqrt(dx * dx + dy * dy + dz * dz);
            };

        // Initialize PQ with start entrances
        for (int seId : startEntrances) {
            const Entrance& se = entrances[seId];
            int poly = (se.cluster1 == startClusterId) ? se.polygon1 : se.polygon2;
            std::vector<int> p = aStar(start, poly);
            if (!p.empty()) {
                float g = dist[poly]; // Read immediately!
                abstractG[seId] = g;
                abstractParent[seId] = -1;
                abstractPQ.push({ seId, g, g + heuristicEntrance(seId, goalClusterId) });
            }
        }

        int bestGoalEntranceId = -1;
        float bestTotalCost = std::numeric_limits<float>::max();

        while (!abstractPQ.empty()) {
            AbstractNode current = abstractPQ.top();
            abstractPQ.pop();

            // Lazy deletion check
            if (current.fCost > abstractG[current.entranceId] + heuristicEntrance(current.entranceId, goalClusterId) + 0.01f) {
                continue;
            }

            const Entrance& ce = entrances[current.entranceId];
            bool isGoalEntrance = (ce.cluster1 == goalClusterId || ce.cluster2 == goalClusterId);

            if (isGoalEntrance) {
                int goalPoly = (ce.cluster1 == goalClusterId) ? ce.polygon1 : ce.polygon2;
                std::vector<int> p = aStar(goalPoly, goal);
                if (!p.empty()) {
                    float costToGoal = dist[goal]; // Read immediately!
                    float totalCost = current.gCost + costToGoal;
                    if (totalCost < bestTotalCost) {
                        bestTotalCost = totalCost;
                        bestGoalEntranceId = current.entranceId;
                    }
                }
                // Optimization: If current path cost already exceeds best found, stop searching
                if (current.gCost >= bestTotalCost) {
                    break;
                }
                continue;
            }

            // Expand neighbors: other entrances in the SAME cluster(s)
            auto expandCluster = [&](int clusterId) {
                const Cluster& cluster = clusters[clusterId];
                for (int nextEId : cluster.entranceids) {
                    if (nextEId == current.entranceId) continue;

                    auto it1 = cluster.intrapaths.find(current.entranceId);
                    if (it1 == cluster.intrapaths.end()) continue;
                    auto it2 = it1->second.find(nextEId);
                    if (it2 == it1->second.end()) continue;

                    float edgeCost = cluster.intracosts.at(current.entranceId).at(nextEId);
                    float nextG = current.gCost + edgeCost;

                    if (abstractG.find(nextEId) == abstractG.end() || nextG < abstractG[nextEId]) {
                        abstractG[nextEId] = nextG;
                        abstractParent[nextEId] = current.entranceId;
                        abstractPQ.push({ nextEId, nextG, nextG + heuristicEntrance(nextEId, goalClusterId) });
                    }
                }
                };

            expandCluster(ce.cluster1);
            expandCluster(ce.cluster2);
        }

        if (bestGoalEntranceId == -1) {
            std::cout << "No valid entrance path found! Falling back to A*\n";
            std::cout << "=====================================================\n\n";
            return aStar(start, goal);
        }

        std::cout << "\nBest abstract path found! Refining...\n";

        // Reconstruct abstract path
        std::vector<int> abstractPath;
        int curr = bestGoalEntranceId;
        while (curr != -1) {
            abstractPath.push_back(curr);
            curr = abstractParent[curr];
        }
        std::reverse(abstractPath.begin(), abstractPath.end());

        // --- PATH REFINEMENT (STITCHING) ---
                // --- PATH REFINEMENT (STITCHING) ---
        std::vector<int> finalPath;

        int firstEId = abstractPath.front();
        const Entrance& firstE = entrances[firstEId];
        int startPoly = (firstE.cluster1 == startClusterId) ? firstE.polygon1 : firstE.polygon2;

        std::vector<int> p1 = aStar(start, startPoly);
        if (!p1.empty()) {
            finalPath = p1;
        }
        else {
            return aStar(start, goal);
        }

        if (abstractPath.size() == 1) {
            // Single entrance bridges both clusters directly
            int goalPoly = (firstE.cluster1 == goalClusterId) ? firstE.polygon1 : firstE.polygon2;

            std::vector<int> pMid = aStar(startPoly, goalPoly);
            for (size_t j = 1; j < pMid.size(); j++) {
                finalPath.push_back(pMid[j]);
            }

            std::vector<int> p3 = aStar(goalPoly, goal);
            for (size_t j = 1; j < p3.size(); j++) {
                finalPath.push_back(p3[j]);
            }
        }
        else {
            // 2. Between entrances (using precomputed intrapaths)
            for (size_t i = 0; i < abstractPath.size() - 1; i++) {
                int e1Id = abstractPath[i];
                int e2Id = abstractPath[i + 1];

                const Entrance& e1 = entrances[e1Id];
                const Entrance& e2 = entrances[e2Id];
                int sharedClusterId = -1;
                if (e1.cluster1 == e2.cluster1 || e1.cluster1 == e2.cluster2) sharedClusterId = e1.cluster1;
                else if (e1.cluster2 == e2.cluster1 || e1.cluster2 == e2.cluster2) sharedClusterId = e1.cluster2;

                if (sharedClusterId != -1) {
                    const Cluster& cluster = clusters[sharedClusterId];
                    auto it1 = cluster.intrapaths.find(e1Id);
                    if (it1 != cluster.intrapaths.end()) {
                        auto it2 = it1->second.find(e2Id);
                        if (it2 != it1->second.end()) {
                            for (size_t j = 1; j < it2->second.size(); j++) {
                                finalPath.push_back(it2->second[j]);
                            }
                        }
                    }
                }
            }

            // 3. Last entrance to goal
            int lastEId = abstractPath.back();
            const Entrance& lastE = entrances[lastEId];
            int goalPoly = (lastE.cluster1 == goalClusterId) ? lastE.polygon1 : lastE.polygon2;
            std::vector<int> p3 = aStar(goalPoly, goal);
            for (size_t j = 1; j < p3.size(); j++) {
                finalPath.push_back(p3[j]);
            }
        }

        std::cout << "Final HPA* Path: ";
        for (int p : finalPath) std::cout << p << " → ";
        std::cout << "Goal\n";
        std::cout << "=====================================================\n\n";

        return finalPath;
    }

    Vector3 getClusterCenter(int id) { // Fixed typo
        for (auto& c : clusters) {
            if (c.id == id) {
                return { c.centerx, c.centery, c.centerz };
            }
        }
        return { 0.0f, 0.0f, 0.0f };
    }

    std::pair<Vector3, Vector3> findSharedEdge(int from, int to) {
        auto& polyA = polygons[from];
        auto& polyB = polygons[to];
        std::vector<Vector3> sharedVerts;

        for (const auto& vA : polyA.vertices) {
            for (const auto& vB : polyB.vertices) {
                float dx = vA.x - vB.x;
                float dy = vA.y - vB.y;
                float dz = vA.z - vB.z;
                float dist = sqrtf(dx * dx + dy * dy + dz * dz);
                if (dist < 0.001f) {
                    sharedVerts.push_back(vA);
                    break;
                }
            }
        }
        if (sharedVerts.size() >= 2) return { sharedVerts[0], sharedVerts[1] };

        Vector3 centerA = { polyA.centerX, polyA.centerY, polyA.centerZ };
        Vector3 centerB = { polyB.centerX, polyB.centerY, polyB.centerZ };
        return { centerA, centerB };
    }

    void addConnection(int from, int to, float cost) {
        for (auto& p : polygons) {
            if (p.id == from) { p.neighbors.push_back(to); p.costs.push_back(cost); }
            if (p.id == to) { p.neighbors.push_back(from); p.costs.push_back(cost); }
        }
    }

    void BlockPolygon(int id) {
        BlockedPolygons.insert(id);
        std::cout << "Polygon " << id << " is now Blocked!" << std::endl;
    }

    void UnBlockedPolygon(int id) {
        BlockedPolygons.erase(id);
        std::cout << "Polygon " << id << " is now UnBlocked!" << std::endl;
    }

    void BlockChunks(std::vector<int> ChunkId) {
        for (int id : ChunkId) {
            BlockPolygon(id);
        }
        std::cout << "Chunk of map is now BLOCKED!\n";
    }

    void UnBlockChunks(std::vector<int> ChunkId) {
        for (int id : ChunkId) {
            UnBlockedPolygon(id);
        }
        std::cout << "Chunk of map is now UNBLOCKED!\n";
    }

    bool isBlocked(int id) {
        return BlockedPolygons.find(id) != BlockedPolygons.end();
    }

    float heuristic(int from, int goal) {
        Vector3 p1 = getPolygonCenter(from);
        Vector3 p2 = getPolygonCenter(goal);
        float dx = p1.x - p2.x;
        float dy = p1.y - p2.y;
        float dz = p1.z - p2.z;
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }

    std::vector<int> aStar(int start, int goal) {
        std::vector<int> emptyPath;

        if (isBlocked(start)) {
            std::cout << "  Start polygon " << start << " is BLOCKED!\n";
            return emptyPath;
        }
        if (isBlocked(goal)) {
            std::cout << "  Goal polygon " << goal << " is BLOCKED!\n";
            return emptyPath;
        }

        resetbuffers();

        std::priority_queue<
            std::pair<float, int>,
            std::vector<std::pair<float, int>>,
            std::greater<std::pair<float, int>>
        > pq;

        dist[start] = 0;
        inOpenlist[start] = true;
        pq.push({ heuristic(start, goal), start });

        while (!pq.empty()) {
            float f = pq.top().first;
            int current = pq.top().second;
            pq.pop();

            if (f != dist[current] + heuristic(current, goal)) {
                continue;
            }

            if (inClosedlist[current]) {
                continue;
            }

            inClosedlist[current] = true;

            if (current == goal) {
                break;
            }

            for (size_t i = 0; i < polygons[current].neighbors.size(); i++) {
                int next = polygons[current].neighbors[i];
                float weight = polygons[current].costs[i];

                if (isBlocked(next)) {
                    continue;
                }

                if (inClosedlist[next]) {
                    continue;
                }

                float g = dist[current] + weight;

                if (g < dist[next]) {
                    dist[next] = g;
                    parent[next] = current;
                    float h = heuristic(next, goal);
                    float f_new = g + h;

                    if (!inOpenlist[next]) {
                        pq.push({ f_new, next });
                        inOpenlist[next] = true;
                    }
                }
            }
        }

        std::vector<int> path;
        for (int at = goal; at != -1; at = parent[at]) {
            path.push_back(at);
        }
        std::reverse(path.begin(), path.end());

        return path;
    }

    Vector3 getPolygonCenter(int id) {
        for (auto& p : polygons) {
            if (p.id == id) return { p.centerX, p.centerY, p.centerZ };
        }
        return { 0.0f, 0.0f, 0.0f };
    }

    bool hasLineOfSight(int from, int to) {
        return !isBlocked(from) && !isBlocked(to);
    }

    std::vector<int> smoothPath(const std::vector<int>& path) {
        if (path.size() < 3) return path;
        std::vector<int> smoothed;
        smoothed.push_back(path[0]);
        size_t current = 0;
        while (current < path.size() - 1) {
            size_t next = current + 1;
            while (next < path.size() - 1 && hasLineOfSight(path[current], path[next + 1])) next++;
            smoothed.push_back(path[next]);
            if (current == next) break;
            current = next;
        }
        return smoothed;
    }

    std::vector<Portal> getPortals(const std::vector<int>& path) { // Fixed typo
        std::vector<Portal> Portals;
        for (size_t i = 0; i < path.size() - 1; i++) {
            int from = path[i];
            int to = path[i + 1];
            auto [left, right] = findSharedEdge(from, to);

            float dx = right.x - left.x;
            float dy = right.y - left.y;
            float dz = right.z - left.z;
            float portalwidth = sqrtf(dx * dx + dy * dy + dz * dz) / 2.0f;

            Vector3 fromcenter = getPolygonCenter(from);
            Vector3 tocenter = getPolygonCenter(to);
            Vector3 mid = {   
                    (fromcenter.x + tocenter.x) / 2.0f,
                    (fromcenter.y + tocenter.y) / 2.0f, 
                    (fromcenter.z + tocenter.z) / 2.0f 
                };
            Vector3 dir = { 
                    tocenter.x - fromcenter.x,
                    tocenter.y - fromcenter.y,
                    tocenter.z - fromcenter.z 
                };
            float len = sqrtf(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
            if (len > 0.001f) { 
                    dir.x /= len; 
                    dir.y /= len; 
                    dir.z /= len; 
                }

            Vector3 up = { 0.0f, 0.0f, 1.0f };
            Vector3 prep = { 
                    dir.y * up.z - dir.z * up.y,
                    dir.z * up.x - dir.x * up.z,
                    dir.x * up.y - dir.y * up.x 
                };
            
            float perplen = sqrtf(prep.x * prep.x + prep.y * prep.y + prep.z * prep.z);
            if (perplen > 0.001f) { 
                    prep.x /= perplen;
                    prep.y /= perplen;
                    prep.z /= perplen; 
                }

            Portal portal;
            portal.left = { 
                    mid.x - prep.x * portalwidth,
                    mid.y - prep.y * portalwidth,
                    mid.z - prep.z * portalwidth 
                };
            portal.right = { 
                    mid.x + prep.x * portalwidth,
                    mid.y + prep.y * portalwidth,
                    mid.z + prep.z * portalwidth 
                };
            
            Portals.push_back(portal);
        }
        return Portals;
    }

    float cross2D(Vector3 a, Vector3 b, Vector3 c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }
    bool isLeftOfLine(Vector3 a, Vector3 b, Vector3 point) { return cross2D(a, b, point) > 0.0f; }
    bool isRightOfLine(Vector3 a, Vector3 b, Vector3 point) { return cross2D(a, b, point) < 0.0f; }

    std::vector<Vector3> funnelAlgorithm(const std::vector<int>& path) {
        std::vector<Vector3> smoothenPath;
        if (path.size() < 2) {
            for (int id : path) smoothenPath.push_back(getPolygonCenter(id));
            return smoothenPath;
        }

        std::vector<Portal> portals = getPortals(path);
        Vector3 start = getPolygonCenter(path[0]);
        Vector3 goal = getPolygonCenter(path[path.size() - 1]);

        Vector3 apex = start;
        Vector3 left = start;
        Vector3 right = start;
        int leftIndex = 0;
        int rightIndex = 0;
        smoothenPath.push_back(start);

        for (int i = 0; i < static_cast<int>(portals.size()); i++) {
            Vector3 portalleft = portals[i].left;
            Vector3 portalright = portals[i].right;

            if (isLeftOfLine(apex, right, portalleft)) { left = portalleft; leftIndex = i; }
            if (isRightOfLine(apex, left, portalright)) { right = portalright; rightIndex = i; }

            if (isLeftOfLine(apex, left, right)) {
                smoothenPath.push_back(left);
                apex = left; left = apex; right = apex; i = leftIndex; continue;
            }
            if (isRightOfLine(apex, right, left)) {
                smoothenPath.push_back(right);
                apex = right; left = apex; right = apex; i = rightIndex; continue;
            }
        }
        smoothenPath.push_back(goal);
        return smoothenPath;
    }
};

class steering {
public:
    static Vector3 normalize(const Vector3& v) {
        float len = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
        if (len > 0.001f) {
            return { v.x / len, v.y / len, v.z / len };
        }
        return { 0.0f,0.0f,0.0f };
    }

    static float magnitude(const Vector3& v) {
        return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    }

    static Vector3 scale(const Vector3& v, float s) {
        return { v.x * s, v.y * s, v.z * s };
    }

    static Vector3 subtract(const Vector3& a, const Vector3& b) {
        return { a.x - b.x, a.y - b.y, a.z - b.z };
    }

    static Vector3 add(const Vector3& a, const Vector3& b) {
        return { a.x + b.x, a.y + b.y, a.z + b.z };
    }

    static Vector3 truncate(const Vector3& v, float max) {
        float len = magnitude(v);
        if (len > max) {
            return scale(v, max / len);
        }
        return v;
    }

    static Vector3 seek(const Vector3& target, const Vector3& position, const Vector3& velocity, float maxspeed) {
        Vector3 desired = scale(normalize(subtract(target, position)), maxspeed);
        return subtract(desired, velocity);
    }

    static Vector3 flee(const Vector3& target, const Vector3& position, const Vector3& velocity, float maxspeed) {
        Vector3 desired = scale(normalize(subtract(position, target)), maxspeed);
        return subtract(desired, velocity);
    }

    static Vector3 arrive(const Vector3& target, const Vector3& position, const Vector3& velocity, float maxspeed, float slowingRadius) {
        Vector3 desired = subtract(target, position);
        float distance = magnitude(desired);
        if (distance > 0.001f) {
            float speed = maxspeed;
            if (distance < slowingRadius) {
                speed = maxspeed * (distance / slowingRadius);
            }
            desired = normalize(desired);
            desired = scale(desired, speed);

            Vector3 steer = subtract(desired, velocity);
            return steer;
        }
        return { 0.0f,0.0f,0.0f };
    }

    static Vector3 separation(const std::vector<Vector3>& neighbors, const Vector3& position) {
        Vector3 steer = { 0, 0, 0 };
        for (const auto& neighbor : neighbors) {
            Vector3 diff = subtract(position, neighbor);
            float dist = magnitude(diff);

            if (dist > 0.001f && dist < 10.0f) {
                steer = add(steer, scale(normalize(diff), 1.0f / dist));
            }
        }
        return steer;
    }

    static Vector3 alignment(const std::vector<Vector3>& neighbors, const Vector3& velocity) {
        if (neighbors.empty()) return { 0,0,0 };
        Vector3 Avgvelocity = { 0,0,0 };
        for (auto& neighbor : neighbors) {
            Avgvelocity = add(Avgvelocity, neighbor);
        }
        Avgvelocity = scale(Avgvelocity, 1.0f / neighbors.size());
        return subtract(Avgvelocity, velocity);
    }

    static Vector3 cohesion(const std::vector<Vector3>& neighbors, const Vector3& position) {
        if (neighbors.empty()) return { 0.0f, 0.0f, 0.0f };
        Vector3 center = { 0, 0, 0 };
        for (const auto& neighbor : neighbors) {
            center = add(center, neighbor);
        }
        center = scale(center, 1.0f / static_cast<float>(neighbors.size()));
        return subtract(center, position);
    }

    static Vector3 flocking(const std::vector<Vector3>& neighborPositions, const std::vector<Vector3>& neighborVelocities,
        const Vector3& position, const Vector3& velocity) {
        Vector3 sep = separation(neighborPositions, position);
        Vector3 ali = alignment(neighborVelocities, velocity);
        Vector3 coh = cohesion(neighborPositions, position);

        Vector3 steer = add(scale(sep, 1.5f), add(scale(ali, 1.0f), scale(coh, 1.0f)));
        return steer;
    }
};

class Enemy {
private:
    AIState currentState;
    float health;
    float detectionRange;
    float attackRange;
    float speed;
    float x, y, z;
    std::vector<int> patrolPath;
    int patrolIndex;
    NavMesh& navMesh;
    std::vector<int> currentPath;
    size_t currentPathIndex;
    float playerX, playerY, playerZ;
    int playerPolygonId;
    float repathCooldown;
    float timeSinceLastRepath;
    int lastKnownPlayerPolygon;
    int lastValidPolygonId;
    Vector3 velocity;
    float slowingRadius;
    std::vector<Enemy*> allEnemies;
    float neighborRadius;
    BTNode* root;
    Blackboard personalBlackboard;
    Blackboard& sharedBlackboard;
    int ammo;
public:
    Enemy(NavMesh& nav, Blackboard& globalBb) : sharedBlackboard(globalBb),
        currentState(AIState::IDLE),
        health(100.0f),
        detectionRange(20.0f),
        attackRange(2.5f),
        speed(2.0f),
        x(5.0f),
        y(5.0f),
        z(0.5f),
        patrolIndex(0),
        navMesh(nav),
        currentPathIndex(0),
        playerX(0.0f), playerY(0.0f), playerZ(0.0f),
        playerPolygonId(3),
        repathCooldown(0.5f),
        timeSinceLastRepath(0.0f),
        lastKnownPlayerPolygon(-1),
        lastValidPolygonId(0),
        velocity({ 0.0f,0.0f,0.0f }),
        slowingRadius(5.0f),
        ammo(30),
        neighborRadius(15.0f),
        root(nullptr) {
        buildBehaviorTree();
    }

    ~Enemy() {
        delete root;
    }

    std::vector<Vector3> getNeighborPositions() {
        std::vector<Vector3> positions;
        Vector3 myPos = getPosition();
        for (Enemy* other : allEnemies) {
            if (other == this) continue;
            if (other->getState() == AIState::DEAD) continue;

            if (steering::magnitude(steering::subtract(other->getPosition(), myPos)) < neighborRadius) {
                positions.push_back(other->getPosition());
            }
        }
        return positions;
    }

    std::vector<Vector3> getNeighborVelocities() {
        std::vector<Vector3> velocities;
        Vector3 myPos = getPosition();
        for (Enemy* other : allEnemies) {
            if (other == this) continue;
            if (other->getState() == AIState::DEAD) continue;

            if (steering::magnitude(steering::subtract(other->getPosition(), myPos)) < neighborRadius) {
                velocities.push_back(other->velocity);
            }
        }
        return velocities;
    }

    void buildBehaviorTree() {
        ConditionNode* isDeadCond = new ConditionNode(&Enemy::isDead);
        ConditionNode* isLowHpCond = new ConditionNode(&Enemy::isHealthLow);
        ConditionNode* isPlayerDetectedCond = new ConditionNode(&Enemy::isPlayerDetected);
        ConditionNode* isInAttackRangeCond = new ConditionNode(&Enemy::isInAttackRange);

        ActionNode* doDead = new ActionNode(&Enemy::doDead);
        ActionNode* doFlee = new ActionNode(&Enemy::doFlee);
        ActionNode* doAttack = new ActionNode(&Enemy::doAttack);
        ActionNode* doChase = new ActionNode(&Enemy::doChase);
        ActionNode* doPatrol = new ActionNode(&Enemy::doPatrol);

        Sequence* seqDead = new Sequence({ isDeadCond, doDead });
        Sequence* seqFlee = new Sequence({ isLowHpCond, doFlee });

        Sequence* seqAttack = new Sequence({ isInAttackRangeCond, doAttack });
        Selector* selCombatAction = new Selector({ seqAttack, doChase });
        Sequence* seqCombat = new Sequence({ isPlayerDetectedCond, selCombatAction });

        root = new Selector({ seqDead, seqFlee, seqCombat, doPatrol });
    }

    void runBT() {
        if (root) root->execute(this);
    }

    void setPosition(float px, float py, float pz) {
        x = px;
        y = py;
        z = pz;
    }

    Vector3 getPosition() const {
        return { x, y, z };
    }

    void setEnemyList(std::vector<Enemy*>& Enemies) {
        allEnemies = Enemies;
    }

    void setPatrolPath(const std::vector<int>& path) {
        patrolPath = path;
        patrolIndex = 0;
    }

    void setPlayerPosition(float px, float py, float pz, int Playerpolygonid) {
        playerX = px;
        playerY = py;
        playerZ = pz;
        playerPolygonId = Playerpolygonid;
    }

    void setState(AIState state) { currentState = state; }
    AIState getState() const { return currentState; }
    float getHealth() const { return health; }

    std::string stateToString(AIState state) {
        switch (state) {
        case AIState::IDLE:   return "IDLE";
        case AIState::PATROL: return "PATROL";
        case AIState::CHASE:  return "CHASE";
        case AIState::ATTACK: return "ATTACK";
        case AIState::FLEE:   return "FLEE";
        case AIState::DEAD:   return "DEAD";
        }
        return "UNKNOWN";
    }

    bool isPlayerDetected() {
        float dx = playerX - x;
        float dy = playerY - y;
        float distance = std::sqrtf(dx * dx + dy * dy);
        return distance < detectionRange;
    }

    bool isInAttackRange() {
        float dx = playerX - x;
        float dy = playerY - y;
        float distance = std::sqrtf(dx * dx + dy * dy);
        return distance < attackRange;
    }

    void moveToPolygon(int polygonId) {
        Vector3 center = navMesh.getPolygonCenter(polygonId);
        float targetX = center.x;
        float targetY = center.y;
        float targetZ = center.z;
        float dx = targetX - x;
        float dy = targetY - y;
        float dz = targetZ - z;
        float distance = std::sqrtf(dx * dx + dy * dy + dz * dz);
        if (distance > 0.1f) {
            float currentStep = std::min(speed, distance);
            x += (dx / distance) * currentStep;
            y += (dy / distance) * currentStep;
            z += (dz / distance) * currentStep;
            std::cout << "  Moving to polygon " << polygonId
                << " (" << x << ", " << y << ", " << z << ")\n";
        }
        else {
            lastValidPolygonId = polygonId;
            std::cout << "  Reached polygon " << polygonId << "\n";
        }
    }

    int getCurrentPolygon() {
        if (!currentPath.empty() && currentPathIndex < currentPath.size()) {
            return currentPath[currentPathIndex];
        }
        return lastValidPolygonId;
    }

    void updateIdle() {
        std::cout << "Idle...\n";
        if (isPlayerDetected()) {
            setState(AIState::CHASE);
        }
    }

    void updatePatrol() {
        if (patrolPath.empty()) {
            setState(AIState::IDLE);
            return;
        }

        if (currentPath.empty() || currentPathIndex >= currentPath.size()) {
            int start = getCurrentPolygon();
            int goal = patrolPath[patrolIndex];

            std::vector<int> rawPath = navMesh.aStar(start, goal);

            std::vector<int> smoothPolygonpath = navMesh.smoothPath(rawPath);
            std::vector<Vector3> smoothpoints = navMesh.funnelAlgorithm(smoothPolygonpath);
            currentPath = smoothPolygonpath;
            currentPathIndex = 0;

            if (currentPath.empty()) {
                std::cout << "  No path to patrol point " << patrolIndex << "\n";
                patrolIndex = (patrolIndex + 1) % patrolPath.size();
                return;
            }

            std::cout << "  Patrolling to polygon " << goal << "\n";
        }

        int nextPolygon = currentPath[currentPathIndex];

        auto center = navMesh.getPolygonCenter(nextPolygon);
        float dx = center.x - x;
        float dy = center.y - y;
        float dz = center.z - z;
        if (std::sqrtf(dx * dx + dy * dy + dz * dz) < 0.5f) {
            currentPathIndex++;
            if (currentPathIndex >= currentPath.size()) {
                patrolIndex = (patrolIndex + 1) % patrolPath.size();
                currentPath.clear();
            }
        }

        if (isPlayerDetected()) {
            setState(AIState::CHASE);
        }
    }

    void updateChase() {
        std::cout << "Chasing player!\n";

        bool hasNoPath = currentPath.empty() || currentPathIndex >= currentPath.size();
        bool timerExpired = (timeSinceLastRepath >= repathCooldown);
        bool playerMoved = (playerPolygonId != lastKnownPlayerPolygon);

        if (hasNoPath || (timerExpired && playerMoved)) {
            int start = getCurrentPolygon();
            int goal = playerPolygonId;

            std::vector<int> rawPath = navMesh.aStar(start, goal);

            if (rawPath.empty()) {
                std::cout << "  [Pathfinding] No valid path available to target!\n";
                timeSinceLastRepath = 0.0f;
                return;
            }

            currentPath = navMesh.smoothPath(rawPath);
            currentPathIndex = 0;
            timeSinceLastRepath = 0.0f;
            lastKnownPlayerPolygon = playerPolygonId;
        }

        if (currentPathIndex < currentPath.size()) {
            int nextPolygon = currentPath[currentPathIndex];
            auto center = navMesh.getPolygonCenter(nextPolygon);

            float dx = center.x - x;
            float dy = center.y - y;
            if (std::sqrtf(dx * dx + dy * dy) < 0.5f) {
                lastValidPolygonId = nextPolygon;
                currentPathIndex++;
            }
        }
    }

    float attackCooldown = 1.0f;
    float timeSinceLastAttack = 1.0f;
    void updateAttack() {
        std::cout << "ATTACK! -10 HP to player!\n";
        health -= 25.0f;
    }

    void updateFlee() {
        std::cout << "Fleeing from player!\n";
        int start = getCurrentPolygon();
        int goal = 0;

        std::vector<int> rawPath = navMesh.aStar(start, goal);
        currentPath = navMesh.smoothPath(rawPath);

        if (currentPath.empty()) {
            Vector3 playerPos = { playerX, playerY, playerZ };
            Vector3 currentPos = { x, y, z };
            Vector3 fleeSteer = steering::flee(playerPos, currentPos, velocity, speed);
            velocity = steering::add(velocity, fleeSteer);
            return;
        }

        if (currentPathIndex >= currentPath.size()) {
            currentPathIndex = 0;
        }

        int nextPolygon = currentPath[currentPathIndex];
        auto center = navMesh.getPolygonCenter(nextPolygon);
        float dx = center.x - x;
        float dy = center.y - y;
        float dz = center.z - z;

        if (std::sqrtf(dx * dx + dy * dy + dz * dz) < 0.5f) {
            currentPathIndex++;
        }

        if (start == 0 && std::sqrtf(dx * dx + dy * dy + dz * dz) < 0.5f) {
            health = 100.0f;
            setState(AIState::PATROL);
        }
    }

    bool isDead() {
        return health <= 0.0f;
    }

    bool isHealthLow() {
        return health < 30.0f;
    }

    void doAttack() {
        setState(AIState::ATTACK);
        updateAttack();
    }

    void doDead() {
        setState(AIState::DEAD);
        updateDead();
    }

    void doFlee() {
        setState(AIState::FLEE);
        updateFlee();
    }

    void doChase() {
        setState(AIState::CHASE);
        updateChase();
    }

    void doPatrol() {
        setState(AIState::PATROL);
        updatePatrol();
    }

    void updateMovement(const Vector3& target, float deltaTime) {
        if (currentState == AIState::DEAD) {
            velocity = { 0.0f, 0.0f, 0.0f };
            std::cout << "  [Steering] Enemy is DEAD at Pos: (" << x << ", " << y << ", " << z << ")\n";
            return;
        }

        Vector3 currentPos = { x, y, z };
        Vector3 steer;

        std::vector<Vector3> neighborPositions = getNeighborPositions();
        std::vector<Vector3> neighborVelocities = getNeighborVelocities();

        if (currentState == AIState::CHASE) {
            Vector3 seekForce = steering::seek(target, currentPos, velocity, speed);
            Vector3 flockForce = steering::flocking(neighborPositions, neighborVelocities, currentPos, velocity);
            steer = steering::add(seekForce, flockForce);
        }
        else if (currentState == AIState::FLEE) {
            steer = steering::arrive(target, currentPos, velocity, speed, slowingRadius);
        }
        else {
            steer = steering::flocking(neighborPositions, neighborVelocities, currentPos, velocity);
        }

        velocity = steering::add(velocity, steer);
        velocity = steering::truncate(velocity, speed);

        x += velocity.x * deltaTime;
        y += velocity.y * deltaTime;
        z = 0.5f;

        velocity = steering::scale(velocity, 0.85f);

        std::cout << "  [Steering] Pos: (" << x << ", " << y << ", " << z << ")\n";
    }

    void updateDead() {
        std::cout << "Enemy is DEAD! Game over.\n";
    }

    void update(float deltaTime) {
        personalBlackboard.set<Vector3>(BlackboardKey::ENEMY_POSITION, { x, y, z });
        personalBlackboard.set<float>(BlackboardKey::ENEMY_HEALTH, health);
        personalBlackboard.set<bool>(BlackboardKey::IS_DEAD, isDead());
        personalBlackboard.set<int>(BlackboardKey::ENEMY_AMMO, ammo);

        if (sharedBlackboard.has(BlackboardKey::PLAYER_POSITION)) {
            Vector3 playerpos = sharedBlackboard.get<Vector3>(BlackboardKey::PLAYER_POSITION);
            playerX = playerpos.x;
            playerY = playerpos.y;
            playerZ = playerpos.z;
        }

        if (currentState == AIState::CHASE) {
            timeSinceLastRepath += deltaTime;
        }
        else {
            timeSinceLastRepath = repathCooldown;
        }

        runBT();
    }
};

BTNodeStatus ConditionNode::execute(Enemy* enemy) {
    return (enemy->*condition)() ? BTNodeStatus::SUCCESS : BTNodeStatus::FAILURE;
}

BTNodeStatus ActionNode::execute(Enemy* enemy) {
    (enemy->*action)();
    return BTNodeStatus::SUCCESS;
}



int main() {
    NavMesh nav;
    Blackboard globalBlackboard;

    nav.addPolygon(0, 5.0f, 5.0f, 5.0f, {
        {0.0f, 0.0f, 0.0f},
        {10.0f, 0.0f, 0.0f},
        {10.0f, 10.0f, 0.0f},
        {0.0f, 10.0f, 0.0f}
        });

    nav.addPolygon(1, 15.0f, 5.0f, 5.0f, {
        {10.0f, 0.0f, 0.0f},
        {20.0f, 0.0f, 0.0f},
        {20.0f, 10.0f, 0.0f},
        {10.0f, 10.0f, 0.0f}
        });

    nav.addPolygon(2, 5.0f, 15.0f, 8.0f, {
        {0.0f, 10.0f, 0.0f},
        {10.0f, 10.0f, 0.0f},
        {10.0f, 20.0f, 0.0f},
        {0.0f, 20.0f, 0.0f}
        });

    nav.addPolygon(3, 15.0f, 15.0f, 10.0f, {
        {10.0f, 10.0f, 0.0f},
        {20.0f, 10.0f, 0.0f},
        {20.0f, 20.0f, 0.0f},
        {10.0f, 20.0f, 0.0f}
        });

    nav.addConnection(0, 1, 10.0f);
    nav.addConnection(0, 3, 37.0f);
    nav.addConnection(1, 2, 10.0f);
    nav.addConnection(1, 3, 10.0f);
    nav.addConnection(2, 3, 15.0f);

    nav.finalizeMap(); // Fixed typo

    // ==================== DEFINE CLUSTERS ====================
    std::cout << "\n=====================================================\n";
    std::cout << ">>> DEFINING HPA* CLUSTERS <<<\n";
    std::cout << "=====================================================\n";

    nav.addCluster(0, { 0, 1 });  // Bottom row cluster (Fixed typo)
    nav.addCluster(1, { 2, 3 });  // Top row cluster (Fixed typo)

    std::cout << "=====================================================\n\n";

    // ==================== INITIALIZE HPA* ====================
    nav.initializeHPA(); // Fixed typo

    // ==================== HPA* PATHFINDING TEST ====================
    std::cout << "\n=====================================================\n";
    std::cout << ">>> TESTING HPA* PATHFINDING (Polygon 0 to 3) <<<\n";
    std::cout << "=====================================================\n";

    int hpaStart = 0;
    int hpaGoal = 3;
    std::vector<int> hpaPath = nav.hpaStar(hpaStart, hpaGoal); // Fixed typo

    std::cout << "HPA* Final Polygon Path: ";
    for (size_t i = 0; i < hpaPath.size(); ++i) {
        std::cout << hpaPath[i] << (i < hpaPath.size() - 1 ? " -> " : "");
    }
    std::cout << "\n=====================================================\n\n";

    // ==================== FUNNEL ALGORITHM TEST ====================
    std::cout << "=====================================================\n";
    std::cout << ">>> TESTING FUNNEL ALGORITHM PATH SMOOTHING <<<\n";
    std::cout << "=====================================================\n";

    int start = 0;
    int goal = 3;

    std::vector<int> rawPath = nav.aStar(start, goal);

    std::cout << "Raw A* Polygon Path: ";
    for (int id : rawPath) {
        std::cout << id << " -> ";
    }
    std::cout << "Goal\n";

    std::vector<Vector3> smoothWaypoints = nav.funnelAlgorithm(rawPath);

    std::cout << "Funnel Algorithm Output Waypoints (3D):\n";
    for (size_t i = 0; i < smoothWaypoints.size(); ++i) {
        std::cout << "  Waypoint [" << i << "]: ("
            << smoothWaypoints[i].x << ", "
            << smoothWaypoints[i].y << ", "
            << smoothWaypoints[i].z << ")\n";
    }
    std::cout << "=====================================================\n\n";

    std::vector<Enemy*> enemyPtrs;
    enemyPtrs.reserve(4);

    for (int i = 0; i < 4; i++) {
        Enemy* newEnemy = new Enemy(nav, globalBlackboard);
        newEnemy->setPatrolPath({ 0, 1, 2, 3 });
        newEnemy->setState(AIState::PATROL);
        enemyPtrs.push_back(newEnemy);
    }

    enemyPtrs[0]->setPosition(5.0f, 5.0f, 0.5f);
    enemyPtrs[1]->setPosition(8.0f, 6.0f, 0.5f);
    enemyPtrs[2]->setPosition(4.0f, 9.0f, 0.5f);
    enemyPtrs[3]->setPosition(9.0f, 4.0f, 0.5f);

    for (auto* e : enemyPtrs) {
        e->setEnemyList(enemyPtrs);
    }

    float deltaTime = 0.5f;
    float playerX = 40.0f, playerY = 40.0f, playerZ = 10.0f;
    int playerPolygon = 3;

    for (auto* e : enemyPtrs) {
        e->setPlayerPosition(playerX, playerY, playerZ, playerPolygon);
    }

    std::cout << "================ STARTING SIMULATION ================\n\n";

    // ==================== PHASE 1: Patrol ====================
    std::cout << ">>> PHASE 1: Enemies Patrolling safely <<<\n";
    for (int frame = 1; frame <= 3; frame++) {
        std::cout << "--- Frame " << frame << " ---\n";
        for (auto* e : enemyPtrs) {
            e->update(deltaTime);
            Vector3 target = nav.getPolygonCenter(e->getCurrentPolygon());
            e->updateMovement(target, deltaTime);
        }
        std::cout << "\n";
    }

    // ==================== PHASE 2: Player detected ====================
    std::cout << ">>> PHASE 2: Player moves into Detection Range (Room C) <<<\n";
    playerX = 15.0f; playerY = 15.0f; playerZ = 10.0f;

    for (auto* e : enemyPtrs) {
        e->setPlayerPosition(playerX, playerY, playerZ, playerPolygon);
    }

    for (int frame = 4; frame <= 7; frame++) {
        std::cout << "--- Frame " << frame << " ---\n";
        for (auto* e : enemyPtrs) {
            e->update(deltaTime);
            Vector3 target = (e->getState() == AIState::CHASE)
                ? Vector3{ playerX, playerY, playerZ }
            : nav.getPolygonCenter(e->getCurrentPolygon());
            e->updateMovement(target, deltaTime);
        }
        std::cout << "\n";
    }

    // ==================== PHASE 3: Block Corridor ====================
    std::cout << ">>> PHASE 3: Suddenly blocking Corridor (Polygon 1)! <<<\n";
    nav.BlockChunks({ 1 });

    for (int frame = 8; frame <= 10; frame++) {
        std::cout << "--- Frame " << frame << " ---\n";
        for (auto* e : enemyPtrs) {
            e->update(deltaTime);
            Vector3 target = (e->getState() == AIState::CHASE)
                ? Vector3{ playerX, playerY, playerZ }
            : nav.getPolygonCenter(e->getCurrentPolygon());
            e->updateMovement(target, deltaTime);
        }
        std::cout << "\n";
    }

    // ==================== PHASE 4: Combat ====================
    std::cout << ">>> PHASE 4: Enemies engage in Combat and Health drops <<<\n";
    int combatFrame = 11;
    bool allFleeing = false;

    while (!allFleeing && combatFrame < 40) {
        std::cout << "--- Frame " << combatFrame++ << " (Combat/Flee Tick) ---\n";
        allFleeing = true;

        for (auto* e : enemyPtrs) {
            std::cout << "Enemy Health: " << e->getHealth() << " HP\n";
            e->update(deltaTime);

            Vector3 target = (e->getState() == AIState::CHASE)
                ? Vector3{ playerX, playerY, playerZ }
            : nav.getPolygonCenter(e->getCurrentPolygon());
            e->updateMovement(target, deltaTime);

            if (e->getState() != AIState::FLEE && e->getHealth() > 0) {
                allFleeing = false;
            }
        }
        std::cout << "\n";
    }

    // ==================== PHASE 5: Escape ====================
    std::cout << ">>> PHASE 5: Enemies escaping back to Room 0 safely <<<\n";
    nav.UnBlockChunks({ 1 });

    for (int frame = combatFrame; frame < combatFrame + 5; frame++) {
        std::cout << "--- Frame " << frame << " ---\n";
        for (auto* e : enemyPtrs) {
            e->update(deltaTime);
            Vector3 target = (e->getState() == AIState::FLEE)
                ? nav.getPolygonCenter(e->getCurrentPolygon())
                : Vector3{ playerX, playerY, playerZ };
            e->updateMovement(target, deltaTime);
        }
        std::cout << "\n";
    }

    for (Enemy* e : enemyPtrs) {
        delete e;
    }
    enemyPtrs.clear();

    std::cout << "================ SIMULATION CONCLUDED ================\n";
    return 0;
}