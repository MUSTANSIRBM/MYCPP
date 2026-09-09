#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_set>
// Linked lists code!
// struct Node {
//     int data;
//     Node* next;
//     Node(int value) {
//         data = value;
//         next = nullptr;
//     }
// };
//
// class Linkedlist {
// private:
//     Node* head;
// public:
//     Linkedlist() {
//         head = nullptr;
//     }
//
//     ~Linkedlist() {
//         while (head != nullptr) {
//             Node* temp = head;
//             head = head->next;
//             delete temp;
//         }
//     }
//
//     void Insert_front(int value) {
//         Node* newnode = new Node(value);
//         newnode->next = head;
//         head = newnode;
//     }
//
//     void Insert_back(int value) {
//         Node* newnode = new Node(value);
//         if (head == nullptr) {
//             head = newnode;
//             return;
//         }
//         Node* temp = head;
//         while (temp->next != nullptr) {
//             temp = temp->next;
//         }
//         temp->next = newnode;
//     }
//     void display() {
//         Node*temp = head;
//         while (temp!=nullptr) {
//             std::cout<<temp->data<<std::endl;
//             temp = temp ->next;
//         }
//     }
//     void Insert_at_Position(int value, int pos) {
//         if (pos == 1) {
//             Insert_front(value);
//             return;
//         }
//         Node* newnode = new Node(value);
//         Node*temp = head;
//         for (int i = 0;i<pos-1;i++) {
//             if (temp==nullptr){\
//                 delete newnode;
//                 return;
//         }
//             temp = temp->next;
//         }
//         newnode->next = temp->next;
//         temp->next = newnode;
//     }
// };
//
// int main() {
//     Linkedlist l;
//     l.Insert_front(10);
//     l.Insert_front(20);
//     l.Insert_front(30);
//     l.Insert_back(40);
//     l.display();
//     return 0;
// }
// Doubly Linkedlist
//struct Node {
//    int data;
//    Node* next;
//    Node* prev;
//    Node(int value) {
//        data = value;
//        next = nullptr;
//        prev = nullptr;
//    }
//};
//class DLinkedlist {
//private:
//    Node* head;
//public:
//    DLinkedlist() {
//        head = nullptr;
//    }
//
//    ~DLinkedlist() {
//        while (head != nullptr) {
//            Node* temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//    void insert_front(int value) {
//        Node* newnode = new Node(value);
//        if (head == nullptr) {
//            head = newnode;
//            return;
//        }
//        newnode->next = head;
//        if (head != nullptr) {
//            head->prev = newnode;
//        }
//        head = newnode;
//    }
//
//
//    void display() {
//        Node* temp = head;
//        if (head == nullptr)return;
//        while (temp != nullptr) {
//            std::cout << temp->data << std::endl;
//            temp = temp->next;
//        }
//    }
//    void revdisplay() {
//        Node* temp = head;
//        if (head == nullptr)return;
//        while (temp->next != nullptr) {
//            temp = temp->next;
//        }
//        while (temp != nullptr) {
//            std::cout << temp->data << std::endl;
//            temp = temp->prev;
//        }
//    }
//    void insert_back(int value) {
//        Node* newnode = new Node(value);
//        if (head == nullptr) {
//            head = newnode;
//            return;
//        }
//        Node* temp = head;
//        while (temp->next != nullptr) {
//            temp = temp->next;
//        }
//        temp->next = newnode;
//        newnode->prev = temp;
//    }
//
//    void insert_at_position(int value, int pos) {
//        
//        if (pos == 1) {
//            insert_front(value);
//            return;
//        }
//        Node* newnode = new Node(value);
//        Node* temp = head;
//        for (int i = 0;i < pos - 1;i++) {
//                if (temp==nullptr){\
//                    delete newnode;
//                    return;
//            }
//                temp = temp->next;
//            }
//            newnode->next = temp->next;
//            newnode->prev = temp;
//            if (temp->next != nullptr) {
//                temp->next->prev = newnode;
//            }
//            temp->next = newnode;
//    }
//
//    void delete_at_value(int target_value) { // Pass the integer data instead!
//        if (head == nullptr) return;
//
//        Node* temp = head;
//        while (temp != nullptr && temp->data != target_value) {
//            temp = temp->next;
//        }
//        if (temp == nullptr)return;
//        if (head == temp) {
//            head = head->next;
//            if (head != nullptr)head->prev = nullptr;
//            delete temp;
//            return;
//        }
//        if (temp->prev != nullptr) temp->prev->next = temp->next;
//        if (temp->next != nullptr) temp->next->prev = temp->prev;
//        delete temp;
//    }
//   
//
//};
//int main() {
//    DLinkedlist dl;
//    dl.insert_front(10);
//    dl.insert_front(20);
//    dl.insert_front(30);
//    dl.insert_front(40);
//    dl.insert_at_position(25,2);
//    dl.delete_at_value(25);
//    dl.display();
//    std::cout << "     ----- " << std::endl;
//    //dl.revdisplay();
//    return 0;
//}
//
//
//struct Node {
//	int data;
//	Node* next;
//	Node(int value) {
//		data = value;
//		next = nullptr;
//	}
//};class stack {
//private:
//Node* top;public:
//	stack() {
//		top = nullptr;
//	}
//	~stack() {
//		while (top != nullptr) {
//			pop();
//		}
//	}
//	void push(int value) {
//		Node* newnode = new Node(value);
//		newnode->next = top;
//		top = newnode;
//	}
//
//	void pop() {
//		if (top == nullptr) {
//			std::cout << "Stack Underflow" << std::endl;
//			return;
//		}
//		Node* temp = top;
//		top = top->next;
//		delete temp;
//	}
//
//	int peek() {
//		if (top == nullptr) {
//			return -1;
//		}
//		Node* temp = top;
//		return temp->data;
//	}
//	bool isEmpty() {
//		if (top == nullptr) {
//			std::cout << "stack empty!" << std::endl;
//			return true;
//		}
//		else {
//			std::cout << "stack not empty!" << std::endl;
//			return false;
//		}
//	}
//};int main() {
//	stack s;
//	s.push(10);
//	s.push(20);
//	s.push(30);
//	s.push(40);
//	s.pop();
//	s.peek();
//	s.isEmpty();
// return 0;
// 
//}
//
//struct Node {
//	int data;
//	Node* next;
//	Node(int value) {
//		data = value;
//		next = nullptr;
//	}
//};
//
//class stack {
//private:
//	static const int max = 5;
//	int array[max];
//	int top;
//public:
//	stack() {
//		top = -1;
//	}
//	~stack() {
//		while (top != -1) {
//			pop();
//		}
//	}
//	void push(int value) {
//		if (top == max - 1) {
//			std::cout << "Stack Overflow" << std::endl;
//			return;
//		}
//		top++;
//		array[top] = value;
//		std::cout << "pushed value:" << value << " into stack!" << std::endl;
//	}
//	
//	void pop() {
//		if (top == -1) {
//			std::cout << "Stack Underflow" << std::endl;
//			return;
//		}
//		std::cout << "removing top value:" << array[top] << " from stack!" << std::endl;
//		top--;
//
//	}
//
//	int peek() {
//		if (top == -1) { 
//			return -1; 
//		}
//		return array[top];
//	}
//	bool isEmpty() {
//		if (top == -1) {
//			std::cout << "stack empty!" << std::endl;
//			return true;
//		}
//		else {
//			std::cout << "stack not empty!" << std::endl;
//			return false;
//		}
//	}
//	bool isFull() {
//		return top == max - 1;
//	}
//};
//
//int main() {
//	stack s;
//	s.push(10);
//	s.push(20);
//	s.push(30);
//	s.push(40);
//	s.pop();
//	s.peek();
//	s.isEmpty();
//	s.isFull();
// return 0;
// 
//}
//
//struct Node {
//	int data;
//	Node* next;
//	Node(int value) {
//		data = value;
//		next = nullptr;
//	}
//};
//class Queue {
//private:
//	Node* front;
//	Node* rear;
//public:
//	Queue() {
//		front = nullptr;
//		rear = nullptr;
//	}
//	~Queue() {
//		Node* temp = front;
//		while (front != nullptr) {
//			Dequeue();
//		}
//	}
//
//	void enQueue(int value) {
//		Node* newnode = new Node(value);
//		if (front == nullptr) {
//			front = rear = newnode;
//			return;
//		}
//		rear->next = newnode;
//		rear = newnode;
//	}
//	void Dequeue(){
//		if (front == nullptr) {
//			std::cout << "Queue overflow!" << std::endl;
//			return;
//		}
//		Node* temp = front;
//		front = front->next;
//		if (front == nullptr) {
//			std::cout << "Queue empty!"<<std::endl;
//			rear = nullptr;
//		}
//		delete temp;
//	}
//	void display(){
//		if (front == nullptr) {
//			std::cout << "Queue is empty." << std::endl;
//			return;
//		}
//		Node* temp = front;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//	int peek() {
//		if (front == nullptr)return -1;
//		return front->data;
//	}
//	bool isEmpty() {
//		if (front == nullptr) { 
//			std::cout << "Queue is empty!" << std::endl;
//			return true;
//		}
//		else {
//			std::cout << "Queue is not empty!" << std::endl;
//			return false;
//		}
//	}
//};
//
//int main() {
//	Queue Q;
//	Q.enQueue(10);
//	Q.enQueue(20);
//	Q.enQueue(30);
//	Q.enQueue(40);
//	Q.display();
//	Q.peek();
//	Q.isEmpty();
// return 0;
//}
//
//struct Node {
//	int data;
//	Node* next;
//	Node(int value) {
//		data = value;
//		next = nullptr;
//	}
//};
//
//class SQ {
//private:
//	static const int max = 5;
//	int array[max];
//	int front;
//	int rear;
//	int current_size;
//public:
//	SQ() {
//		front = 0;
//		rear = -1;
//		current_size = 0;
//	}
//
//	void enqueue(int value) {
//		if (current_size == max) {
//			std::cout << "Queue overflow" << std::endl;
//			return;
//		}
//		rear = (rear + 1) % max;
//		array[rear] = value;
//		current_size++;
//	}
//	void dequeue() {
//		if (current_size == 0) {
//			std::cout << "Queue Overflow" << std::endl;
//			return;
//		}
//		front = (front + 1) % max;
//		current_size--;
//	}
//	int peek() {
//		return array[front];
//	}
//};
//
//int main() {
//	SQ sq;
//	sq.enqueue(10);
//	sq.enqueue(20);
//	sq.enqueue(30);
//	sq.enqueue(40);
//	sq.dequeue();
//	sq.peek();
//	return 0;
//}

//struct TreeNode {
//	int data;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int value) {
//		data = value;
//		left = nullptr;
//		right = nullptr;
//	}
//};
//
//class BST {
//private:
//	TreeNode* root;
//
//	void destroy(TreeNode* node) {
//		if (node == nullptr)return;
//		destroy(node->left);
//		destroy(node->right);
//		delete node;
//	}
//
//	void PRE(TreeNode* node) {
//		if (node == nullptr)return;
//		std::cout << node->data << " " << std::endl;
//		PRE(node->left);
//		PRE(node->right);
//	}
//
//	void IOD(TreeNode* node) {
//		if (node == nullptr)return;
//		IOD(node->left);
//		std::cout << node->data << " " << std::endl;
//		IOD(node->right);
//	}
//
//	void POD(TreeNode* node) {
//		if (node == nullptr)return;
//		POD(node->left);
//		POD(node->right);
//		std::cout << node->data << " " << std::endl;
//	}
//public:
//
//	BST() {
//		root = nullptr;
//	}
//
//	~BST() {
//		destroy(root);
//		root = nullptr;
//	}
//
//	void insert(int value) {
//		TreeNode* newnode = new TreeNode(value);
//		if (root == nullptr) {
//			root = newnode;
//			return;
//		}
//		TreeNode* current = root;
//		TreeNode* parent = nullptr;
//		while (current != nullptr) {
//			parent = current;
//			if (value < current->data) {
//				current = current->left;
//			}
//			else if (value > current->data) {
//				current = current->right;
//			}
//			else {
//				std::cout << "value already exists" << std::endl;
//				delete newnode;
//				return;
//			}
//		}
//		if (value < parent->data) {
//			parent->left = newnode;
//		}
//		else {
//			parent->right = newnode;
//		}
//	}
//
//	bool search(int target) {
//		TreeNode* current = root;
//		while (current != nullptr) {
//			if (target == current->data) {
//				std::cout << "found it!" << std::endl;
//				return true;
//			}
//			else if (target < current->data) {
//				current = current->left;
//			}
//			else if (target > current->data){
//				current = current->right;
//			}
//		}
//		std::cout << "value not found!" << std::endl;
//		return false;
//	}
//
//	void display() {
//		int chc;
//		std::cout << "Press 1:to see Pre-Order Output\nPress 2:to see In-Order Output\nPress 3:to see Post-Order Output\n" << std::endl;
//		std::cin >> chc;
//		std::cout << " " << std::endl;
//		switch (chc) {
//		case 1:
//			std::cout << "Pre-Order Output:\n" << std::endl;
//			PRE(root);
//			break;
//		case 2:
//			std::cout << "In-Order Output:\n" << std::endl;
//			IOD(root);
//			break;
//		case 3:
//			std::cout << "Post-Order Output:\n" << std::endl;
//			POD(root);
//			break;
//		}
//	}
//};
//int main() {
//	BST T;
//	T.insert(50);
//	T.insert(30);
//	T.insert(60);
//	T.insert(25);
//	T.insert(55);
//	T.search(55);
//	T.display();


//class MaxHeap {
//private:
//	int* arr;
//	int capacity;
//	int size;
//public:
//	MaxHeap(int cap) {
//		capacity = cap;
//		size = 0;
//		arr = new int[capacity];
//	}
//	~MaxHeap(){
//		delete[] arr;
//	}
//	void insert(int value) {
//		if (size== capacity){
//			std::cout << "Heap overflow" << std::endl;
//			return;
//		}
//		arr[size] = value;
//		int i = size;
//		size++;
//		while (i > 0 && arr[i] > arr[(i - 1) / 2]) {
//			std::swap(arr[i], arr[(i - 1) / 2]);
//			i = (i - 1) / 2;
//		}
//	}
//	void display() {
//		for (int i = 0;i < size;i++) {
//			std::cout << arr[i] << " ";
//		}
//		std::cout << std::endl;
//	}
//	void extractMax() {
//		if (size == 0) {
//			std::cout << "Heap is empty!" << std::endl;
//			return;
//		}
//		arr[0] = arr[size - 1];
//		size--;
//
//		int i = 0;
//		while (true) {
//			int left = 2 * i + 1;
//			int right = 2 * i + 2;
//			int largest = i;			
//			if (left < size && arr[left] > arr[largest]) {
//				largest = left;
//			}
//			if (right < size && arr[right] > arr[largest]) {
//				largest = right;
//			}
//			if (largest == i) {
//				break;
//			}
//			std::swap(arr[i], arr[largest]);
//			i = largest;
//		}
//	}
//	int getMax() {
//		if (size == 0) {
//			std::cout << "Heap is empty!" << std::endl;
//			return -1;
//		}
//		std::cout<<arr[0];
//	}
//	int getsize() {
//		return size;
//	}
//};
//
//int main() {
//	MaxHeap heap(10);
//	heap.insert(5);
//	heap.insert(10);
//	heap.insert(15);
//	heap.insert(20);
//	heap.insert(25);
//	heap.extractMax();
//	heap.display();
//	heap.getMax();
//}

//struct TrieNode {
//	TrieNode* children[26];
//	bool isEndOfWord;
//	TrieNode() {
//		isEndOfWord = false;
//		for (int i = 0;i < 26;i++) {
//			children[i] = nullptr;
//		}
//	}
//};
//
//class Trie{
//private:
//	TrieNode* root;
//public:
//	Trie() {
//		root = new TrieNode();
//	}
//	void insert(std::string word) {
//		TrieNode* current = root;
//		for (int i = 0;i < word.length();i++) {
//			char ch = word[i];
//			int index = ch - 'a';
//			if (current->children[index] == nullptr) {
//				current->children[index] = new TrieNode();
//			}
//			current = current->children[index];
//		}
//		current->isEndOfWord = true;
//	}
//	bool search(std::string word) {
//		TrieNode* current = root;
//		for (int i = 0;i < word.length();i++) {
//			char ch = word[i];
//			int index = ch - 'a';
//			if (current->children[index] == nullptr) {
//				return false; 
//			}
//			current = current->children[index];
//		}
//		return current->isEndOfWord;
//	}
//	bool startswith(std::string prefix) {
//		TrieNode* current = root;
//		for (int i = 0;i < prefix.length();i++) {
//			char ch = prefix[i];
//			int index = ch - 'a';
//			if (current->children[index] == nullptr) {
//				return false;
//			}
//			current = current->children[index];
//		}
//		return true;
//	}
//};
//
//int main() {
//	Trie trie;
//	trie.insert("cat");
//	trie.insert("car");
//
//	std::cout << trie.search("cat") << std::endl;
//	std::cout << trie.search("can") << std::endl;
//	std::cout << trie.search("ca") << std::endl; 
//	std::cout << trie.startswith("ca") << std::endl;
//	std::cout << trie.startswith("do") << std::endl;
//}


//class MaxHeap {
//private:
//	std::vector<int> arr;
//public:
//	MaxHeap() {
//	arr.reserve(10);
//	}
//	void insert(int value) {
//		arr.push_back(value);
//		int i = arr.size() - 1;
//		while (i > 0 && arr[i] > arr[(i - 1) / 2]) {
//			std::swap(arr[i], arr[(i - 1) / 2]);
//			i = (i - 1) / 2;
//		}
//	}
//	void display() {
//		for (int i = 0;i < arr.size();i++) {
//			std::cout << arr[i] << " ";
//		}
//		std::cout << std::endl;
//	}
//	void extractMax() {
//		if (arr.empty()) {
//			std::cout << "Heap is empty!" << std::endl;
//			return;
//		}
//		arr[0] = arr[arr.size() - 1];
//		arr.pop_back();
//		int i = 0;
//		while (true) {
//			int left = 2 * i + 1;
//			int right = 2 * i + 2;
//			int largest = i;
//			if (left < arr.size() && arr[left] > arr[largest]) {
//				largest = left;
//			}
//			if (right < arr.size() && arr[right] > arr[largest]) {
//				largest = right;
//			}
//			if (largest == i) {
//				break;
//			}
//			std::swap(arr[i], arr[largest]);
//			i = largest;
//		}
//	}
//	int getMax() {
//		if (arr.empty()) {
//			std::cout << "Heap is empty!" << std::endl;
//			return -1;
//		}
//		std::cout << arr[0];
//	}
//	int getsize() {
//		return arr.size();
//	}
//};
//
//int main() {
//	MaxHeap heap;
//	heap.insert(5);
//	heap.insert(10);
//	heap.insert(15);
//	heap.insert(20);
//	heap.insert(25);
//	heap.extractMax();
//	heap.display();
//	heap.getMax();
//}
//class Graph {
//private:
//	std::vector<std::vector<int>> adj;
//public:
//	Graph(int vertices) {
//		adj.resize(vertices);
//	}
//	void AddEdge(int u, int v) {
//		if (u >= adj.size()) {
//			adj.resize(u + 1);
//		}
//		if (v >= adj.size()) {
//			adj.resize(v + 1);
//		}
//		adj[u].push_back(v);
//		adj[v].push_back(u);
//	}
//	void display() {
//		for (int i = 0;i < adj.size();i++) {
//			std::cout << "vertex " << i << ":";
//			for (int neighor : adj[i]) {
//				std::cout << neighor << " ";
//			}
//			std::cout << std::endl;
//		}
//	}
//    void BFS(int startVertex) {
//        std::vector<bool> visited(adj.size(), false);
//        std::queue<int> q;
//
//        visited[startVertex] = true;
//        q.push(startVertex);
//
//        while (!q.empty()) {
//            int current = q.front();
//            q.pop();
//            std::cout << current << " ";
//
//            for (int neighbor : adj[current]) {
//                if (!visited[neighbor]) {
//                    visited[neighbor] = true;
//                    q.push(neighbor);
//                }
//            }
//        }
//    }
//	void DFSHelper(int v, std::vector<bool>& visited) {
//		visited[v] = true;
//		std::cout << v << std::endl;
//		for (int neighbor : adj[v]) {
//			if (!visited[neighbor]) {
//				DFSHelper(neighbor, visited);
//			}
//		}
//	}
//	void DFS(int startvertex) {
//		std::vector<bool> visited(adj.size(), false);
//		DFSHelper(startvertex, visited);
//	}
//};
//
//
//class HEAP {
//private:
//	std::vector<int> arr;
//public:
//	HEAP() {
//		arr.reserve(100);
//	}
//	void insert(int value) {
//		arr.push_back(value);
//		int i = arr.size() - 1;
//		while (i > 0 && arr[i] > arr[(i - 1) / 2]) {
//			std::swap(arr[i], arr[(i - 1) / 2]);
//			i = (i - 1) / 2;
//		}
//	}
//	void display() {
//		if (arr.empty()) {
//			std::cout << "Heap empty..." << std::endl;
//			return;
//		}
//		for (int i = 0;i < arr.size();i++) {
//			std::cout << arr[i] << std::endl;
//		}
//	}
//	void MaxExtract() {
//		if (arr.empty()) {
//			std::cout << "Heap empty..." << std::endl;
//			return;
//		}
//		arr[0] = arr[arr.size() - 1];
//		arr.pop_back();
//		int i = 0;
//		while (true) {
//			int left = 2 * i + 1;
//			int right = 2 * i + 2;
//			int largest = i;
//			if (left < arr.size() && arr[left] >arr[largest]) {
//				largest = left;
//			}
//			if (right < arr.size() && arr[right] >arr[largest]) {
//				largest = right;
//			}
//			if (largest == i) {
//				break;
//			}
//			std::swap(arr[i], arr[largest]);
//			i = largest;
//		}
//	}	

//class Graph {
//private:
//	std::vector<std::vector<std::pair<int, int>>> adj;
//public:
//	Graph(int vertices) {
//		adj.resize(vertices);
//	}
//	void AddEdges(int u, int v, int w) {
//		if (u >= adj.size()) {
//			adj.resize(u + 1);
//		}
//		if (v >= adj.size()) {
//			adj.resize(v + 1);
//		}
//		adj[u].push_back({ v,w });
//		adj[v].push_back({ u,w });
//	}
//	void display() { 
//		for (int i = 0;i < adj.size();i++) {
//			std::cout << "vertex " << i << std::endl;
//			for (auto neighbor: adj[i]){
//				std::cout << "(" << neighbor.first << ", " << neighbor.second << ") "<<std::endl;
//			}
//		}
//	}
//	void Dijksra(int start) {
//		
//		std::vector<int> dist(adj.size(), INT_MAX);
//		dist[start] = 0;
//		
//		std::priority_queue<
//			std::pair<int, int>,
//			std::vector<std::pair<int, int>>,
//			std::greater<std::pair<int, int>>
//		> pq;
//
//		pq.push({ 0,start });
//		std::cout << "starting at vertex: "<<start << std::endl;
//		
//		while (!pq.empty()) {
//			int cost = pq.top().first;
//			int current = pq.top().second;
//			pq.pop();
//		
//			if (cost > dist[current]) {
//				continue;
//			}
//			std::cout << "Visiting " << current << " (cost: " << cost << ")" << std::endl;
//			for (auto neighbor : adj[current]) {
//				
//				int next = neighbor.first;
//				int weight = neighbor.second;
//				int newcost = dist[current] + weight;
//				
//				if (newcost < dist[next]) {
//					dist[next] = newcost;
//					pq.push({ newcost,next });
//				}
//			}
//		}	
//		
//		for (int i = 0;i < dist.size();i++) {
//			if (dist[i] == INT_MAX) {
//				std::cout << "INF!" << std::endl;
//			}
//			else {
//				std::cout <<"costs: " << dist[i] << std::endl;
//			}
//		}
//	}
//};
//// A* 4D
//class Graph {
//private:
//	std::vector<std::vector<std::pair<int, int>>> adj;
//public:
//	Graph(int vertices) {
//		adj.resize(vertices);
//	}
//	void addEdge(int u, int v, int w) {
//		if (u >= adj.size()) {
//			adj.resize(u + 1);
//		}
//		if (v >= adj.size()) {
//			adj.resize(v + 1);
//		}
//		adj[u].push_back({ v,w });
//		adj[v].push_back({ u,w });
//	}
//	int huristic(int node, int goal, const std::vector<std::pair<int, int>>& coords) {
//		int dx = std::abs(coords[node].first - coords[goal].first);
//		int dy = std::abs(coords[node].second - coords[goal].second);
//		return dx + dy;
//	}
//	void Astar(int start, int goal, const std::vector<std::pair<int, int>>& coords) {
//		int n = adj.size();
//		std::vector<int> dist(n, INT_MAX);
//		std::vector<int> parent(n, -1);
//		dist[start] = 0;
//		std::priority_queue<
//			std::pair<int, int>,
//			std::vector<std::pair<int, int>>,
//			std::greater<std::pair<int, int>>
//		> pq;
//		pq.push({ huristic(start,goal,coords),start });
//		while (!pq.empty()) {
//			int f = pq.top().first;
//			int current = pq.top().second;
//			pq.pop();
//			if (current == goal) {
//				std::cout << "Goal reached!\n";
//				break;
//			}
//			for (auto neighbor : adj[current]) {
//				int next = neighbor.first;
//				int weight = neighbor.second;
//				int newcost = dist[current] + weight;
//				
//				if (newcost < dist[next]) {
//					dist[next] = newcost;
//					parent[next] = current;
//					int h = huristic(next, goal, coords);
//					int f_new = newcost + h;
//					pq.push({ f_new,next });
//				}
//			}
//		}
//		std::cout << "Path: ";
//		std::vector<int> path;
//		for (int at = goal; at != -1; at = parent[at]) {
//			path.push_back(at);
//		}
//		for (int i = path.size() - 1; i >= 0; i--) {
//			std::cout << path[i] << " ";
//		}
//		std::cout << "\nCost: " << dist[goal] << std::endl;
//	}
//};
//int main() {
//	Graph g(6);
//	g.addEdge(0, 1, 2);
//	g.addEdge(0, 2, 4);
//	g.addEdge(1, 3, 3);
//	g.addEdge(2, 3, 1);
//	g.addEdge(3, 4, 5);
//	g.addEdge(4, 5, 2);      
//	std::vector<std::pair<int, int>> coords = {
//		{0, 0},  
//		{1, 0},  
//		{0, 1},  
//		{1, 1},   
//		{2, 1},  
//		{3, 1}   
//	};
//	std::cout << "=== A* from 0 to 5 ===\n";
//	g.Astar(0, 5, coords);
//
//	return 0;
//}


// A* 4D and 8D and waypoint and smooth pathing!
//struct Point {
//	float x, y;
//	Point(float _x = 0.0f,float _y = 0.0f){
//		 x = _x ;
//		 y = _y ;
//	}
//};
//class Graph {
//private:
//	std::vector<std::vector<std::pair<int, int>>> adj;
//	int movement_choice = 1;
//public:
//	Graph(int vertices) {
//		adj.resize(vertices);
//	}
//	void setmovemet(int choice) {
//		movement_choice = choice;
//	}
//	void addEdge(int u, int v, int w) {
//		if (u >= adj.size()) {
//			adj.resize(u + 1);
//		}
//		if (v >= adj.size()) {
//			adj.resize(v + 1);
//		}
//		adj[u].push_back({ v,w });
//		adj[v].push_back({ u,w });
//	}
//	float huristic(int node, int goal, const std::vector<std::pair<int, int>>& coords) {
//		int dx, dy;
//		if (movement_choice == 1) {
//			dx = std::abs(coords[node].first - coords[goal].first);
//			dy = std::abs(coords[node].second - coords[goal].second);
//			return dx + dy;
//		}
//		if (movement_choice == 2 || movement_choice == 3) {
//			dx = coords[node].first - coords[goal].first;
//			dy = coords[node].second - coords[goal].second;
//			return std::sqrtf(static_cast<float>(dx * dx + dy * dy));
//		}
//		return 0.0f;
//	}
//	void Astar(int start, int goal, const std::vector<std::pair<int, int>>& coords) {
//		int n = adj.size();
//		std::vector<int> dist(n, INT_MAX);
//		std::vector<int> parent(n, -1);
//		dist[start] = 0;
//		std::priority_queue<
//			std::pair<float, int>,
//			std::vector<std::pair<float, int>>,
//			std::greater<std::pair<float, int>>
//		> pq;
//		pq.push({ huristic(start,goal,coords),start });
//		while (!pq.empty()) {
//			float f = pq.top().first;
//			int current = pq.top().second;
//			pq.pop();
//			if (current == goal) {
//				std::cout << "Goal reached!\n";
//				break;
//			}
//			for (auto neighbor : adj[current]) {
//				int next = neighbor.first;
//				int weight = neighbor.second;
//				int g = dist[current] + weight;
//
//				if (g < dist[next]) {
//					dist[next] = g;
//					parent[next] = current;
//					float h = huristic(next, goal, coords);
//					float f_new = g + h;
//					pq.push({ f_new,next });
//				}
//			}
//		}
//		std::cout << "Path: ";
//		std::vector<int> path;
//		for (int at = goal; at != -1; at = parent[at]) {
//			path.push_back(at);
//		}
//		for (int i = path.size() - 1; i >= 0; i--) {
//			std::cout << path[i] << " ";
//		}
//		std::cout << "\nCost: " << dist[goal] << std::endl;
//	}
//
//	
//bool hasLineOfSight(int from, int to, const std::vector<Point>& coords) {
//    return true;
//}
//
//std::vector<int> smoothPath(const std::vector<int>& path, const std::vector<Point>& coords) {
//    if (path.size() < 3) {
//        return path;
//    }
//
//    std::vector<int> smoothed;
//    smoothed.push_back(path[0]);
//
//    int current = 0;
//    int next = 1;
//
//    while (next < path.size()) {
//        while (next < path.size() - 1 && hasLineOfSight(path[current], path[next + 1], coords)) {
//            next++;
//        }
//
//        smoothed.push_back(path[next]);
//        current = next;
//        next++;
//    }
//
//    if (smoothed.back() != path.back()) {
//        smoothed.push_back(path.back());
//    }
//
//    return smoothed;
//}
//};
//int main() {
//	Graph g(8);
//	int choice ;
//	std::cout << "enter number according to your choice of way to find:\n1:4D way\n2:8Dway\n3:waypoint way\n4:smooth pathing!" << std::endl;
//	std::cin >> choice;
//	switch (choice) {
//	case 1: {
//		  std::vector<std::pair<int, int>> coords = {
//					{0, 0}, // 0
//					{1, 0}, // 1
//					{2, 0}, // 2
//					{0, 1}, // 3
//				    {1, 1}, // 4
//					{2, 1}, // 5
//					{0, 2}, // 6
//					{1, 2}, // 7
//					{2, 2}  // 8
//		  };
//		  g.addEdge(0, 1, 1);
//		  g.addEdge(1, 2, 1);
//		  g.addEdge(2, 5, 1);
//		  g.addEdge(3, 0, 1);
//		  g.addEdge(4, 0, 1);
//		  g.addEdge(5, 8, 1);
//		  g.addEdge(6, 3, 1);
//		  g.addEdge(7, 6, 1);
//		  g.addEdge(8, 7, 1);
//		  g.setmovemet(choice);
//		  g.Astar(0, 8, coords);
//		  break;
//	}
//	case 2: {
//		std::vector<std::pair<int, int>> coords = {
//				{0, 0}, // 0
//				{1, 0}, // 1
//				{2, 0}, // 2
//				{0, 1}, // 3
//				{1, 1}, // 4
//				{2, 1}, // 5
//				{0, 2}, // 6
//				{1, 2}, // 7
//				{2, 2}  // 8
//		};
//		g.addEdge(0, 4, 1);  // Diagonal: bottom-left → center
//		g.addEdge(1, 5, 1);  // Diagonal: bottom-center → right-center
//		g.addEdge(2, 4, 1);  // Diagonal: bottom-right → center
//		g.addEdge(3, 7, 1);  // Diagonal: left-center → top-center
//		g.addEdge(4, 8, 1);  // Diagonal: center → top-right
//		g.addEdge(5, 7, 1);  // Diagonal: right-center → top-center
//		g.addEdge(0, 3, 1);  // Already added (vertical)
//		g.addEdge(1, 4, 1);  // Already added (vertical)
//		g.addEdge(2, 5, 1);  // Already added (vertical)
//		g.addEdge(3, 6, 1);  // Already added (vertical)
//		g.addEdge(4, 7, 1);  // Already added (vertical)
//		g.addEdge(5, 8, 1);  // Already added (vertical)
//		g.setmovemet(choice);
//		//g.Astar(0, 5, coords);
//		g.Astar(0, 8, coords);
//		break;
//	}
//		case 3 :{
//			std::vector<std::pair<int, int>> coords = {
//				 {0, 0},    // Node 0: Castle
//				 {15, 0},   // Node 1: Bridge
//				 {5, 5},    // Node 2: Camp (diagonal!)
//				 {0, 20},   // Node 3: Village
//				 {40, 10}   // Node 4: Town
//			};
//			g.addEdge(0, 1, 10);
//			g.addEdge(3, 4, 10);
//			g.addEdge(0, 3, 10);
//			g.addEdge(1, 4, 10);
//
//			// DIAGONAL shortcut
//			g.addEdge(0, 2, 7);
//			g.addEdge(2, 4, 7);
//			g.setmovemet(choice);
//			g.Astar(0, 4, coords);
//			break;
//		}
//		case 4: {
//			std::vector<std::pair<int, int>> coords = {
//				{0, 0},   // Node 0: Start
//				{2, 0},   // Node 1
//				{4, 0},   // Node 2 (not used)
//				{2, 2},   // Node 3
//				{4, 2}    // Node 4: Goal
//			};
//
//			g.addEdge(0, 1, 10);   // 0 → 1
//			g.addEdge(1, 3, 10);   // 1 → 3
//			g.addEdge(3, 4, 10);   // 3 → 4
//
//			// Optional: Direct edge from 0 to 4 (to test skipping)
//			// g.addEdge(0, 4, 100);  // Long path, should be skipped
//
//			g.setmovemet(2);  // Euclidean heuristic
//			g.Astar(0, 4, coords);
//
//			// Smooth the path
//			std::vector<Point> pointCoords = {
//				{0, 0},   // Node 0
//				{2, 0},   // Node 1
//				{4, 0},   // Node 2
//				{2, 2},   // Node 3
//				{4, 2}    // Node 4
//			};
//			std::vector<int> path = { 0, 1, 3, 4 };
//			std::vector<int> smoothed = g.smoothPath(path, pointCoords);
//
//			std::cout << "Original path: 0 1 3 4\n";
//			std::cout << "Smoothed path: ";
//			for (int p : smoothed) std::cout << p << " ";
//			std::cout << std::endl;
//
//			break;
//		}
//		default:
//			std::cout << "choose a valid option!" << std::endl;
//	}
//
//
//	return 0;
//}


////NavMesh
//struct polygon {
//	int id;
//	float centerX, centerY;
//	std::vector<int> neighbors;
//	std::vector<float> costs;
//};
//class NavMesh {
//private:
//	std::vector<polygon> polygons;
//	std::unordered_set<int> BlockedPolygons;
//public:
//	void addPolygon(int id, float x, float y) {
//		polygons.push_back({ id,x,y,{}, {} });
//	}
//	void addConnection(int from, int to, float cost) {
//		for (auto& p : polygons) {
//			if (p.id == from) {
//				p.neighbors.push_back(to);
//				p.costs.push_back(cost);
//			}
//			if (p.id == to) {
//				p.neighbors.push_back(from);
//				p.costs.push_back(cost);
//			}
//		}
//	}
//	void BlockPolygon(int id) {
//		BlockedPolygons.insert(id);
//		std::cout << "Polygon " << id << " is now Blocked!" << std::endl;
//	}
//	void UnBlockedPolygon(int id){
//		BlockedPolygons.erase(id);
//		std::cout << "Polygon " << id << " is now UnBlocked!" << std::endl;
//	}
//	void BlockChunks(std::vector<int> ChunkId) {
//		for (int id : ChunkId) {
//			BlockPolygon(id);
//		}
//		std::cout << "Chunk of map is now BLOCKED!\n";
//	}
//	void UnBlockChunks(std::vector<int> ChunkId) {
//		for (int id : ChunkId) {
//			UnBlockedPolygon(id);
//		}
//		std::cout << "Chunk of map is now UNBLOCKED!\n";
//	}
//	bool isBlocked(int id){
//		return BlockedPolygons.find(id) != BlockedPolygons.end();
//	}
//	float heuristic(int from, int goal) {
//		int dx = polygons[from].centerX - polygons[goal].centerX;
//		int dy = polygons[from].centerY - polygons[goal].centerY;
//		return std::sqrtf(static_cast<float>(dx * dx + dy * dy));
//	}
//	void aStar(int start, int goal) {
//		if (isBlocked(start)){
//			std::cout << "Start polygon is BLOCKED! Cannot start.\n";
//			return;
//		}
//		if (isBlocked(goal)) {
//			std::cout << "goal polygon is BLOCKED! Cannot reach.\n";
//			return;
//		}
//		int n = polygons.size();
//		std::vector<float> dist(n, INT_MAX);
//		std::vector<int> parent(n, -1);
//		dist[start] = 0;
//
//		std::priority_queue<
//			std::pair<float, int>,
//			std::vector<std::pair<float, int>>,
//			std::greater<std::pair<float, int>>
//		> pq;
//
//		pq.push({ heuristic(start, goal), start });
//		while (!pq.empty()) {
//			float f = pq.top().first;
//			int current = pq.top().second;
//			pq.pop();
//
//			if (current == goal) {
//				std::cout << "Goal polygon reached!\n";
//				break;
//			}
//
//			for (int i = 0; i < polygons[current].neighbors.size(); i++) {
//				int next = polygons[current].neighbors[i];
//				float weight = polygons[current].costs[i];
//
//				if (isBlocked(next)) {
//					std::cout << "  Polygon " << next << " is BLOCKED! Skipping.\n";
//					continue;
//				}
//
//				float g = dist[current] + weight;
//
//				if (g < dist[next]) {
//					dist[next] = g;
//					parent[next] = current;
//					float h = heuristic(next, goal);
//					float f_new = g + h;
//					pq.push({ f_new, next });
//				}
//			}
//		}
//
//		// Print path
//		std::cout << "Path: ";
//		std::vector<int> path;
//		for (int at = goal; at != -1; at = parent[at]) {
//			path.push_back(at);
//		}
//		for (int i = path.size() - 1; i >= 0; i--) {
//			std::cout << path[i] << " ";
//		}
//		std::cout << "\nCost: " << dist[goal] << std::endl;
//	}
//};

// ========================TESTING AI BEHAVIOUR CODE====================================
//======================================================================================
//======================================================================================
//======================================================================================
//enum class AIState {
//    IDLE,
//    PATROL,
//    CHASE,
//    ATTACK,
//    FLEE,
//    DEAD
//};
//
//class Enemy {
//private:
//    AIState currentState;
//    float health;
//    float detectionRange;
//    float attackRange;
//    float speed;
//    std::vector<int> patrolPath;
//    int patrolIndex;
//
//public:
//    Enemy() : currentState(AIState::IDLE), health(100.0f),
//        detectionRange(20.0f), attackRange(5.0f), speed(2.0f), patrolIndex(0) {
//    }
//
//    AIState getState() const { return currentState; }
//    float getHealth() const { return health; }
//
//    void setState(AIState newState) { currentState = newState; }
//
//    void updateIdle() {
//        std::cout << "Enemy is IDLE. Looking around...\n";
//        if (isPlayerDetected()) {
//            setState(AIState::CHASE);
//            std::cout << "Player detected! Switching to CHASE.\n";
//        }
//    }
//
//    void updatePatrol() {
//        std::cout << "Enemy is PATROLLING...\n";
//        if (patrolPath.empty()) {
//            setState(AIState::IDLE);
//            return;
//        }
//        if (isPlayerDetected()) {
//            setState(AIState::CHASE);
//            std::cout << "Player detected! Switching to CHASE.\n";
//        }
//    }
//
//    void updateChase() {
//        std::cout << "Enemy is CHASING the player!\n";
//        moveTowardPlayer();
//        if (isInAttackRange()) {
//            setState(AIState::ATTACK);
//            std::cout << "In attack range! Switching to ATTACK.\n";
//        }
//        if (!isPlayerDetected()) {
//            setState(AIState::PATROL);
//            std::cout << "Lost the player! Switching to PATROL.\n";
//        }
//    }
//
//    void updateAttack() {
//        std::cout << "Enemy is ATTACKING the player!\n";
//        attackPlayer();
//        if (!isInAttackRange()) {
//            setState(AIState::CHASE);
//            std::cout << "Player escaped! Switching to CHASE.\n";
//        }
//        if (health < 20.0f) {
//            setState(AIState::FLEE);
//            std::cout << "Health low! Switching to FLEE.\n";
//        }
//    }
//
//    void updateFlee() {
//        std::cout << "Enemy is FLEEING from danger!\n";
//        moveAwayFromPlayer();
//        if (health > 50.0f) {
//            setState(AIState::PATROL);
//            std::cout << "Safe! Switching to PATROL.\n";
//        }
//    }
//
//    void updateDead() {
//        std::cout << "Enemy is DEAD. Game over.\n";
//    }
//
//    void update() {
//        switch (currentState) {
//        case AIState::IDLE:    updateIdle(); break;
//        case AIState::PATROL:  updatePatrol(); break;
//        case AIState::CHASE:   updateChase(); break;
//        case AIState::ATTACK:  updateAttack(); break;
//        case AIState::FLEE:    updateFlee(); break;
//        case AIState::DEAD:    updateDead(); break;
//        }
//    }
//    bool isPlayerDetected() {
//        static int frame = 0;
//        frame++;
//        if (frame % 5 == 0) return true;  // Simulate detection
//        return false;
//    }
//
//    bool isInAttackRange() {
//        static int frame = 0;
//        frame++;
//        if (frame % 7 == 0) return true;
//        return false;
//    }
//
//    void moveTowardPlayer() {
//        std::cout << "  Moving toward player...\n";
//    }
//
//    void moveAwayFromPlayer() {
//        std::cout << "  Moving away from player...\n";
//    }
//
//    void attackPlayer() {
//        std::cout << "  *ATTACK!* -10 HP to player!\n";
//    }
//};
//======================================================================================
//======================================================================================
//======================================================================================
//navmesh with AI Behaviour!
struct Polygon {
    int id;
    float centerX, centerY;
    std::vector<int> neighbors;
    std::vector<float> costs;
};

class NavMesh {
private:
    std::vector<Polygon> polygons;
    std::unordered_set<int> BlockedPolygons;

public:
    void addPolygon(int id, float x, float y) {
        polygons.push_back({ id, x, y, {}, {} });
    }

    void addConnection(int from, int to, float cost) {
        for (auto& p : polygons) {
            if (p.id == from) {
                p.neighbors.push_back(to);
                p.costs.push_back(cost);
            }
            if (p.id == to) {
                p.neighbors.push_back(from);
                p.costs.push_back(cost);
            }
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
        float dx = polygons[from].centerX - polygons[goal].centerX;
        float dy = polygons[from].centerY - polygons[goal].centerY;
        return std::sqrtf(dx * dx + dy * dy);
    }

    // A* returns the path (list of polygon IDs)
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

        int n = polygons.size();
        std::vector<float> dist(n, INT_MAX);
        std::vector<int> parent(n, -1);
        dist[start] = 0;

        std::priority_queue<
            std::pair<float, int>,
            std::vector<std::pair<float, int>>,
            std::greater<std::pair<float, int>>
        > pq;

        pq.push({ heuristic(start, goal), start });

        while (!pq.empty()) {
            float f = pq.top().first;
            int current = pq.top().second;
            pq.pop();

            if (current == goal) {
                break;
            }

            for (int i = 0; i < polygons[current].neighbors.size(); i++) {
                int next = polygons[current].neighbors[i];
                float weight = polygons[current].costs[i];

                if (isBlocked(next)) {
                    continue;
                }

                float g = dist[current] + weight;

                if (g < dist[next]) {
                    dist[next] = g;
                    parent[next] = current;
                    float h = heuristic(next, goal);
                    float f_new = g + h;
                    pq.push({ f_new, next });
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

    std::pair<float, float> getPolygonCenter(int id) {
        for (auto& p : polygons) {
            if (p.id == id) {
                return { p.centerX, p.centerY };
            }
        }
        return { 0, 0 };
    }
};

enum class AIState {
    IDLE,
    PATROL,
    CHASE,
    ATTACK,
    FLEE,
    DEAD
};

class Enemy {
private:
    AIState currentState;
    float health;
    float detectionRange;
    float attackRange;
    float speed;
    float x, y;
    std::vector<int> patrolPath;
    int patrolIndex;
    NavMesh& navMesh;
    std::vector<int> currentPath;
    int currentPathIndex;
    float playerX, playerY;
    int playerPolygonId;

public:
    Enemy(NavMesh& nav) : currentState(AIState::IDLE), health(100.0f),
        detectionRange(20.0f), attackRange(5.0f), speed(2.0f),
        x(5.0f), y(5.0f), patrolIndex(0), navMesh(nav),
        currentPathIndex(0), playerX(0.0f), playerY(0.0f), playerPolygonId(3) {
    }

    void setPatrolPath(const std::vector<int>& path) {
        patrolPath = path;
        patrolIndex = 0;
    }

    void setPlayerPosition(float px, float py, int Playerpolygonid) {
        playerX = px;
        playerY = py;
        playerPolygonId = Playerpolygonid;
    }

    AIState getState() const { return currentState; }
    float getHealth() const { return health; }

    void setState(AIState newState) {
        std::cout << "  Switching to: " << stateToString(newState) << "\n";
        currentState = newState;
        currentPath.clear();
        currentPathIndex = 0;
    }

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
        return distance < attackRange;uj
    }

    void moveToPolygon(int polygonId) {
        auto center = navMesh.getPolygonCenter(polygonId);
        float targetX = center.first;
        float targetY = center.second;
        float dx = targetX - x;
        float dy = targetY - y;
        float distance = std::sqrtf(dx * dx + dy * dy);
        if (distance > 0.1f) {
            x += (dx / distance) * speed;
            y += (dy / distance) * speed;
            std::cout << "  Moving to polygon " << polygonId
                << " (" << x << ", " << y << ")\n";
        }
        else {
            std::cout << "  Reached polygon " << polygonId << "\n";
        }
    }

    int getCurrentPolygon() {
        if (!currentPath.empty() && currentPathIndex < currentPath.size()) {
            return currentPath[currentPathIndex];
        }
        return 0;
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
            currentPath = navMesh.aStar(start, goal);
            currentPathIndex = 0;

            if (currentPath.empty()) {
                std::cout << "  No path to patrol point " << patrolIndex << "\n";
                patrolIndex = (patrolIndex + 1) % patrolPath.size();
                return;
            }

            std::cout << "  Patrolling to polygon " << goal << "\n";
        }

        int nextPolygon = currentPath[currentPathIndex];
        moveToPolygon(nextPolygon);

        auto center = navMesh.getPolygonCenter(nextPolygon);
        float dx = center.first - x;
        float dy = center.second - y;
        if (std::sqrtf(dx * dx + dy * dy) < 0.5f) {
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

        if (currentPath.empty() || currentPathIndex >= currentPath.size()) {
            int start = getCurrentPolygon();
            int goal = playerPolygonId;
            currentPath = navMesh.aStar(start, goal);
            currentPathIndex = 0;

            if (currentPath.empty()) {
                std::cout << "  No path to player!\n";
                return;
            }
        }

        int nextPolygon = currentPath[currentPathIndex];
        moveToPolygon(nextPolygon);

        auto center = navMesh.getPolygonCenter(nextPolygon);
        float dx = center.first - x;
        float dy = center.second - y;
        if (std::sqrtf(dx * dx + dy * dy) < 0.5f) {
            currentPathIndex++;
        }

        if (isInAttackRange()) {
            setState(AIState::ATTACK);
        }

        if (!isPlayerDetected()) {
            setState(AIState::PATROL);
        }
    }

    void updateAttack() {
        std::cout << "ATTACK! -10 HP to player!\n";
        health -= 5.0f;

        if (!isInAttackRange()) {
            setState(AIState::CHASE);
        }

        if (health < 20.0f) {
            setState(AIState::FLEE);
        }
    }

    void updateFlee() {
        std::cout << "Fleeing from player!\n";
        int start = getCurrentPolygon();
        int goal = 0;
        currentPath = navMesh.aStar(start, goal);
        currentPathIndex = 0;

        if (!currentPath.empty()) {
            int nextPolygon = currentPath[currentPathIndex];
            moveToPolygon(nextPolygon);
        }

        if (health > 50.0f) {
            setState(AIState::PATROL);
        }
    }

    void updateDead() {
        std::cout << "Enemy is DEAD! Game over.\n";
    }

    void update() {
        switch (currentState) {
        case AIState::IDLE:    updateIdle(); break;
        case AIState::PATROL:  updatePatrol(); break;
        case AIState::CHASE:   updateChase(); break;
        case AIState::ATTACK:  updateAttack(); break;
        case AIState::FLEE:    updateFlee(); break;
        case AIState::DEAD:    updateDead(); break;
        }
    }
};

int main() {
    NavMesh nav;

    nav.addPolygon(0, 5, 5);    // Room A (Start)
    nav.addPolygon(1, 15, 5);   // Corridor
    nav.addPolygon(2, 5, 15);   // Room B
    nav.addPolygon(3, 15, 15);  // Room C (Goal)

    nav.addConnection(0, 1, 10);
    nav.addConnection(0, 3, 37);
    nav.addConnection(1, 2, 10);
    nav.addConnection(1, 3, 10);
    nav.addConnection(2, 3, 15);

    Enemy enemy(nav);
    enemy.setPatrolPath({ 0, 1, 2, 3 });

    for (int i = 0; i <= 15; i++) {
        std::cout << "--- Frame " << i << " ---\n";
        float simplayerX = 15.0f;
        float simplayerY = 15.0f;
        int simplayerpolygon = 3;
        enemy.setPlayerPosition(simplayerX, simplayerY, simplayerpolygon);
        enemy.update();
        std::cout << "\n";
    }

    return 0;
}

