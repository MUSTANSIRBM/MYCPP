#include <iostream>
#include <string>
#include <fstream>

struct Song {
	std::string name;
	std::string artist;
	Song* next;
	Song* prev;
	Song(std::string S_name, std::string A_name):
		name(S_name),
		artist(A_name),
		next(nullptr),
		prev(nullptr){}
};

class Playlist {
private:
	Song* head;
	Song* tail;
	Song* curr;
public:
	
	Playlist() {
		head = nullptr;
		tail = nullptr;
		curr = head;
	}
	
	~Playlist() {
		if (head != nullptr) {
			tail->next = nullptr;
			while (head != nullptr) {
				Song* temp = head;
				head = head->next;
				delete temp;
			}
		}
	}
	
	void addSong(std::string title, std::string artist) {
		Song* newSong = new Song(title, artist);
		if (head == nullptr) {
			head = tail = curr = newSong;
			head->next = head;
			head->prev = head;
		}
		else {
			newSong->prev = tail;
			newSong->next = head;
			tail->next = newSong;
			head->prev = newSong;
			tail = newSong;

		}
	}
	
	void playnext() {
		if (curr == nullptr)return;
		curr = curr->next;
		std::cout << "--> " << curr->name<< " " << curr->artist << " <--" << std::endl;
	}
	
	void playprev() {
		if (curr == nullptr)return;
		curr = curr->prev;
		std::cout << "--> " << curr->name << curr->artist << " <--" << std::endl;

	}

	void removeSong(std::string title) {
		if (head == nullptr)return;
		Song* temp = head;
		bool flag = false;
		do {
			std::cout << "Checking: [" << temp->name << "] against [" << title << "]" << std::endl;

			if (temp->name == title) {
				flag = true;
				break;
			}
			temp = temp->next;
		} while (temp != head);
		if (flag) {
			if (head->next == head) {
				head = tail = curr = nullptr;
			}
			else {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				if (temp == head) head = temp->next;
				if (temp == tail) tail = temp->prev;
				if (temp == curr) curr = temp->next;
			}

			delete temp; 
			std::cout << "Success: Removed from memory." << std::endl;
		}
	}
	void saveFile(std::string filename) {
		std::ofstream outFile(filename); 
		if (!outFile.is_open()) return;
		if (head == nullptr) {
			outFile.close();
			return;
		}
		Song* temp = head;
		do {
			outFile << temp->name << "|" << temp->artist << "\n";
			temp = temp->next;
		} while (temp != head);
		outFile.close();
	}
	
	void loadFile(std::string filename) {
		std::ifstream inFile(filename);
		if (!inFile.is_open()) return;
		std::string line;
		while (std::getline(inFile, line)) {
			if (line.empty()) continue;
			size_t pipePos = line.find('|');
			if (pipePos != std::string::npos) {
				std::string s = line.substr(0, pipePos);
				std::string a = line.substr(pipePos + 1);
				addSong(s, a);
			}
		}
		inFile.close();
	}
	void showPlaylist() {
		if (head == nullptr) return;
		Song* temp = head;
		do {
			if (temp == curr) {
				std::cout << "--> " << "Song :" << temp->name << " By " << temp->artist << std::endl;
			}
			else {
				std::cout << "Song :" << temp->name << " By " << temp->artist << std::endl;
			}
			temp = temp->next;
		} while (temp != head);
	}
};


int main() {
	Playlist myHits;
	std::string filename = "playlist.json";
	myHits.loadFile(filename);

	int choice = 0;

	while (1) {
		std::cout << "\n--- Spotify Menu ---" << std::endl;
		std::cout << "1. To Add Song\n2. To go Next track\n3. To go Previous track\n4. To Show playlist\n5. To see the playlist \n6. To Remove a Song\n7. To saveFile\n8. To Exit" << std::endl;
		std::cout << "Choice: ";
		std::cin >> choice;
	switch (choice) {
	case 1: {
		std::string S, A;
		std::cin.ignore(); 

		std::cout << "Enter Song Name: ";
		std::getline(std::cin, S);

		std::cout << "Enter Artist Name: ";
		std::getline(std::cin, A);

		myHits.addSong(S, A);
		break;
	}
		case 2:
			myHits.playnext();
			break;
		case 3:
			myHits.playprev();
			break;
		case 4:
			myHits.showPlaylist();
			break;
		case 5:
			myHits.showPlaylist();
			break;
		case 6: {
			std::string name;
			std::getline(std::cin >> std::ws, name);
			myHits.removeSong(name);
			myHits.saveFile(filename); 
			break;
		}

		case 7:
			myHits.saveFile(filename);
			break;
		case 8:
			std::cout << "Goodbye!" << std::endl;
			std::exit(0);

		default:
			std::cout << "Invalid choice!" << std::endl;
		}
	}
	return 0;
}
