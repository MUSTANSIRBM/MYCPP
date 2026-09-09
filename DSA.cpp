#include <iostream>
#include <string>
#include <utility>
//struct Node {
//	int data;
//	Node* next;
//	Node(int val) :data(val),next(nullptr) {}
//};
//class Linkedlists {
//private:
//	Node* head;
//public:
//	Linkedlists() {
//		head = nullptr;
//	}
//	~Linkedlists() {
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//
//	void push_front(int val) {
//		Node* newNode = new Node(val);
//		newNode->next = head;
//		head = newNode;
//	}
//	void display() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data<< std::endl;
//			temp = temp->next;
//		}
//	}
//
//	void deleteNode(int val) {
//		// Case 1: List is empty, nothing to do
//		if (head == nullptr) return;
//
//		// Case 2: The value is at the HEAD (The first node)
//		if (head->data == val) {
//			Node* temp = head;
//			head = head->next; // Move head to the next one
//			delete temp;       // Delete the old head
//			return;
//		}
//
//		// Case 3: The value is somewhere in the middle
//		Node* curr = head;
//		Node* prev = nullptr;
//
//		// Search for the node
//		while (curr != nullptr && curr->data != val) {
//			prev = curr;       // prev moves to where curr was
//			curr = curr->next; // curr moves forward
//		}
//
//		// If we reached the end and didn't find it
//		if (curr == nullptr) return;
//
//		// We found it! 'curr' is the node to delete. 'prev' is the one before it.
//		prev->next = curr->next; // The detailed "Patching" step
//		delete curr;             // Goodbye node
//	}
//};
//int main() {
//	Linkedlists list;
//	list.push_front(100);
//	list.push_front(200);
//	list.push_front(300);
//	list.deleteNode(300);
//	list.display();
//
//}




//struct Node {
	//int data;
	//Node* next;
	//Node(int val) : data(val), next(nullptr){}
//};
//class Linkedlist {
//private:
//	Node* head;
//public:
	//Linkedlist() {
	//	head = nullptr;
	//}
	//~Linkedlist() {
	//	Node* temp = head;
	//	while (head != nullptr) {
	//		head = head->next;
	//		delete temp;
	//		temp = head;
	//	}
	//}


	//void Push_front(int val){
	//	Node* newNode = new Node(val);
	//	newNode->next = head;
	//	head = newNode;
	//}

	//void Display() {
	//	Node* temp = head;
	//	while (temp != nullptr) {
	//		std::cout << temp->data << std::endl;
	//		temp= temp->next;
	//	}
	//}

	//void insertAfter(int searchVal, int newVal) {
		//Node* curr = head;
		//while (curr != nullptr && curr->data != searchVal) {
			//curr =curr->next;
		//}

		//if (curr == nullptr) {
			//return;
		//}
		//Node* newNode = new Node(newVal);
		//newNode->next = curr->next;
		//curr->next = newNode;
	//}

	//void insertBefore(int searchVal, int newVal) {
		//if (head->data == searchVal) {
			//Push_front(newVal);
			//return;
		//}

		//Node* curr = head;
		//Node* prev = nullptr;

		//while (curr != nullptr && curr->data != searchVal) {
			//prev = curr;       
			//curr = curr->next; 
		//}
		//if (curr == nullptr) return;
		//Node* newNode = new Node(newVal);
		//newNode->next = curr; 
		//prev->next = newNode;
	 //}
//};
//int main() {
//	Linkedlist list;
//	list.Push_front(10);
//	list.Push_front(20);
//	list.Push_front(30);
//	list.insertAfter(20, 25);
//	list.insertBefore(10, 5);
//	list.Display();
//}



//struct Node {
//	int data;
//	Node* next;
//	Node(int val) : data(val), next(nullptr) {}
//};
//class LinkedList {
//private:
//	Node* head;
//public:
//	LinkedList() {
//		head= nullptr;
//	}
//	~LinkedList() {
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void Push_front(int val) {
//		Node* newNode = new Node(val);
//		newNode->next = head;
//		head = newNode;
//	}
//	void Display() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//	void InsertAfter(int searchVal, int Newval) {
//		Node* curr = head;
//		while (curr != nullptr && curr->data != searchVal) {
//			curr = curr->next;
//		}
//		if (curr == nullptr) return;
//		Node* newNode = new Node(Newval);
//		newNode->next = curr->next;
//		curr->next = newNode;
//	}
//
//	void deleteTail() {
//		if (head == nullptr) return;
//
//		if (head->next == nullptr) {
//			delete head;
//			head = nullptr;
//			return;
//		}
//		Node* temp = head;
//
//		while (temp->next->next != nullptr) {
//			temp = temp->next;
//		}
//		delete temp->next;
//		temp->next= nullptr;
//	}
//	void InserBefore(int searchVal, int newVal) {
//		
//		if (head == nullptr) return;
//		if (head->data == searchVal) {
//			Push_front(newVal);
//			return;
//		}
//		Node* curr = head;
//		Node* prev = nullptr;
//		while (curr != nullptr && curr->data != searchVal) {
//			prev = curr;
//			curr = curr->next;
//		}
//		if (curr == nullptr) return;
//		Node* newNode = new Node(newVal);
//		newNode->next = curr;
//		prev->next = newNode;
//
//
//	}
//	bool search(int target) {
//		Node* temp = head;
//		while (temp != nullptr) {
//			if (temp->data == target) {
//				return true;
//			}
//		temp = temp->next;
//			
//		}
//		return false;
//	}
//};
//int main() {
//	LinkedList list;
//	list.Push_front(100);
//	list.Push_front(200);
//	list.Push_front(300);
//	list.InsertAfter(200, 250);
//	list.InserBefore(200, 150);
//	if (list.search(100)) {
//		std::cout << "Found 100!" << std::endl;
//	}
//	else {
//		std::cout << "100 not in list." << std::endl;
//	}
//	list.Display();
//	
//}



//struct Node {
//	int data;
//	Node* next;
//	Node(int val) : data(val),next(nullptr){}
//};
//class Linked {
//private:
//	Node* head;
//public:
//	Linked() {
//		head = nullptr;
//	}
//
//	~Linked() {
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void Push_front(int val) {
//		Node* Newnode = new Node(val);
//		Newnode->next = head;
//		head = Newnode;
//	}
//	void Display() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//	void InsertAfter(int SearchVal, int NewVal) {
//		Node* curr = head;
//		while (curr != nullptr && curr->data != SearchVal) {
//			curr = curr->next;
//		}
//		if (curr == nullptr)return;
//		Node* NewNode = new Node(NewVal);
//		NewNode->next = curr->next;
//		curr->next = NewNode;
//	}
//	void InsertBefore(int SearchVal, int NewVal) {
//		Node* curr = head;
//		Node* prev = curr;
//		if (head == nullptr)return;
//		if (curr->data == SearchVal) {
//			Push_front(NewVal);
//			return;
//		}
//		while (curr != nullptr && curr->data != SearchVal) {
//			prev = curr;
//			curr = curr->next;
//		}
//		if (curr == nullptr)return;
//		Node* NewNode = new Node(NewVal);
//		NewNode->next = curr;
//		prev->next = NewNode;
//	}
//	void DeleteTail() {
//		if (head == nullptr)return;
//		if (head->next == nullptr) {
//			delete head;
//			head = nullptr;
//			return;
//		}
//		Node* temp = head;
//		while (temp->next->next != nullptr) {
//			temp = temp->next;
//		}
//		delete temp->next;
//		temp->next = nullptr;
//	}
//	bool search(int target) {
//		Node* temp = head;
//		while (temp != nullptr) {
//			if (temp->data == target) {
//				return true;
//			}
//			temp = temp->next;
//		}
//		return false;
//	}
//};
//int main(){
//	Linked list;
//	list.Push_front(100);
//	list.Push_front(200);
//	list.Push_front(300);
//	list.InsertBefore(200, 250);
//	list.InsertAfter(200, 150);
//	if (list.search(150)) {
//		std::cout << "found 150!" << std::endl;
//	}
//	else {
//		std::cout << "100 not in list." << std::endl;
//	}
//	list.Display();
//	return 0;
//}







//struct Node{
//	int data;
//	Node* next;
//	Node(int val):data(val), next(nullptr){}
//};
//class Linkedlists{
//private:
//	Node* head;
//public:
//	Linkedlists() {
//		head = nullptr;
//	}
//	~Linkedlists() {
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void Push_front(int val) {
//		Node* Newnode = new Node(val);
//		Newnode->next = head;
//		head = Newnode;
//	}
//	void Display() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//	void InsertAfter(int S_val, int N_val) {
//		Node* curr = head;
//		if (head == nullptr)return;
//		while (curr != nullptr && curr->data != S_val) {
//			curr = curr->next;
//		}
//		if (curr == nullptr) return;
//		Node* NewNode = new Node(N_val);
//		NewNode->next = curr->next;
//		curr->next = NewNode;
//	}
//	void Insertbefore(int S_val, int N_val) {
//		Node* curr = head;
//		Node* prev = curr;
//		if (head == nullptr) return;
//		if (curr->data == S_val) {
//			Push_front(N_val);
//			return;
//		}
//		while (curr != nullptr && curr->data != S_val) {
//			prev = curr;
//			curr = curr->next;
//		}
//		if (curr == nullptr)return;
//		Node* NewNode = new Node(N_val);
//		NewNode->next = curr;
//		prev->next = NewNode;
//	}
//	void DeleteTail() {
//		if (head == nullptr)return;
//		if (head->next == nullptr) {
//			delete head;
//			head = nullptr;
//			return;
//		}
//		Node* temp = head;
//		while (temp->next->next != nullptr) {
//			temp = temp->next;
//		}
//		delete temp->next;
//		temp->next = nullptr;
//	}
//	bool Search(int target) {
//		Node* temp = head;
//		while (temp != nullptr) {
//			if (temp->data == target) {
//				return true;
//			}
//			temp = temp->next;
//		}
//		return false;
//	}
//};
//
//int main() {
//	Linkedlists list;
//	list.Push_front(100);
//	list.Push_front(200);
//	list.Push_front(300);
//	list.InsertAfter(100, 250);
//	list.Insertbefore(200, 150);
//	if (list.Search(150)) {
//		std::cout << "found 150!" << std::endl;
//	}
//	else {
//		std::cout << "100 not in list." << std::endl;
//	}
//	list.Display();
//	return 0;
//}


//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//	Node(int val):data(val),next(nullptr),prev(nullptr){}
//};
//
//class DoublyLinkedList {
//private:
//	Node* head;
//public:
//	DoublyLinkedList() {
//		head = nullptr;
//	}
//	~DoublyLinkedList() {
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void Push_front(int val) {
//		Node* newNode = new Node(val);
//		newNode->next = head; 
//		if (head != nullptr) {
//			head->prev = newNode;
//			newNode->next = head; 
//		}
//		head = newNode;
//	}
//	void Push_back(int val) {
//		Node* newNode = new Node(val);
//		if (head == nullptr) {
//			head = newNode;
//			return;
//		}
//		Node* temp = head;
//		while (temp->next != nullptr) {
//			temp = temp->next;
//		}
//		temp->next =  newNode;
//		newNode->prev = temp;
//	}
//	void Display() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//
//	void deletehead() {
//		if (head == nullptr)return;
//		Node* temp = head;
//		head = head->next;
//		if (head != nullptr) {
//			head->prev = nullptr;
//		}
//		delete temp;
//	}
//
//	void InsertAfter(int S_val, int N_val) {
//		if (head == nullptr)return;
//		Node* curr = head;
//		while (curr != nullptr && curr->data != S_val) {
//			curr = curr->next;
//		}
//		if (curr == nullptr)return;
//		Node* newnode = new Node(N_val);
//		newnode->next = curr->next;
//		newnode->prev = curr;
//		curr->next = newnode;
//		if (newnode->next != nullptr) {
//			newnode->next->prev = newnode;
//		}
//	}
//	void DisplayReverse() {
//		Node* temp = head;
//		if (temp == nullptr)return;
//		while (temp->next != nullptr) {
//			temp = temp->next;
//		}
//		while (temp != nullptr) {
//			std::cout << temp->data<< " " << std::endl;
//			temp = temp->prev;
//		}
//	}
//};
//
//int main() {
//	DoublyLinkedList List;
//	List.Push_back(100);
//	List.Push_back(200);
//	List.Push_back(300);
//	List.Push_front(100);
//	List.Push_front(200);
//	List.Push_front(300);
//	List.Display();
//	//List.DisplayReverse();
//	return 0;
//}


//struct Node {
//	int data;
//	Node* next;
//	Node(int val): data(val),next(nullptr){}
//};
//class Linkedlist {
//private:
//	Node* head;
//public:
//	Linkedlist() {
//		head = nullptr;
//	}
//	~Linkedlist() {
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void Push_front(int val) {
//		Node* newNode = new Node(val);
//		newNode->next = head;
//		head = newNode;
//	}
//	void Display() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//	void InsertAfter(int S_val, int N_val) {
//		if (head == nullptr)return;
//		Node* curr = head;
//		while (curr != nullptr && curr->data != S_val) {
//			curr = curr->next;
//		}
//		if (curr == nullptr)return;
//		Node* newNode = new Node(N_val);
//		newNode->next = curr->next;
//		curr->next = newNode;
//	}
//	void InsertBefore(int S_val, int N_val) {
//		if (head == nullptr)return;
//		Node* curr = head;
//		Node* prev = curr;
//		if (curr->data == S_val) {
//			Push_front(N_val);
//			return;
//		}
//		while(curr==nullptr && curr->data !=S_val){
//			prev = curr;
//			curr = curr->next;
//		}
//		if (curr == nullptr)return;
//		Node* newNode = new Node(N_val);
//		newNode->next = curr;
//		prev->next = newNode;
//	}
//};
//
//
//
//int main() {
//	Linkedlist list;
//	list.Push_front(100);
//	list.Push_front(200);
//	list.Push_front(300);
//	list.InsertAfter(200, 150);
//	list.Display();
//}

//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//	Node(int val) :data(val), prev(nullptr), next(nullptr){}
//};
//
//class DoublyLinkedList {
//private:
//	Node* head;
//public:
//	DoublyLinkedList() {
//		head = nullptr;
//	}
//	~DoublyLinkedList() {
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void Push_front(int val) {
//		Node* newNode = new Node(val);
//		newNode->next = head;
//		if (head != nullptr) {
//			head->prev = newNode;
//		}
//		head = newNode;
//	}
//	void Push_back(int val) {
//		Node* newNode = new Node(val);
//		if (head == nullptr) {
//			head = newNode;
//			return;
//		}
//		Node* temp = head;
//		while (temp->next != nullptr) {
//			temp = temp->next;
//		}
//		temp->next = newNode;
//		newNode->prev = temp;
//	}
//	void DisplayForward() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//	void DisplayReverse() {
//		Node* temp = head;
//		if (head == nullptr)return;
//		while (temp->next != nullptr) {
//			temp = temp->next;
//		}
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->prev;
//		}
//	}
//	void DeleteHead() {
//		if (head == nullptr)return;
//		Node* temp = head;
//		head = head->next;
//		if (head!= nullptr) {
//			head->prev = nullptr;
//		}
//		delete temp;
//	}
//	void Deletetail() {
//		if (head == nullptr)return;
//		if (head->next == nullptr) {
//			delete head;
//			head = nullptr;
//			return;
//		}
//		Node* temp = head;
//		while (temp->next != nullptr) {
//			temp=temp->next;
//		}
//		temp->prev->next = nullptr;
//		delete temp;
//	}
//	void DeleteNode(int val) {
//		if (head == nullptr) return;
//		Node* temp = head;
//		while (temp != nullptr && temp->data != val) {
//			temp = temp->next;
//		}
//		if (temp == nullptr)return;
//		if (temp == head) {
//			DeleteHead();
//			return;
//		}
//		if (temp->prev != nullptr) {
//			temp->prev->next = temp->next;
//		}
//
//		if (temp->next != nullptr) {
//			temp->next->prev = temp->prev;
//		}
//		delete temp;
//	}
//};
//int main() {
//	DoublyLinkedList list;
//	list.Push_front(100);
//	list.Push_front(200);
//	list.Push_front(300);
//	list.Push_back(400);
//	//list.Deletetail();
//	//list.DeleteHead();
//	list.DisplayForward();
//	list.DisplayReverse();
//	list.DeleteNode(400);
//	list.DisplayForward();
//
//}

//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//	Node(int val):data(val),prev(nullptr),next(nullptr){}
//};
//class DoublyLinkedList {
//private:
//	Node* head;
//public:
//	DoublyLinkedList() {
//		head = nullptr;
//	}
//	~DoublyLinkedList() {
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void Push_front(int val) {
//		Node* Newnode = new Node(val);
//		Newnode->next = head;
//		head = Newnode;
//		if (head != nullptr) {
//			head->prev = Newnode;
//		}
//	}
//	void display() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//	void FindAndSquare(int target) {
//		Node* temp = head;
//		while (temp != nullptr) {
//			if (temp->data == target) {
//				temp->data = temp->data* temp->data;
//				return;
//			}
//			temp = temp->next;
//		}
//		std::cout << "Value not in list." << std::endl;
//	}
//	void SwapHeadAndTail() {
//		if (head == nullptr || head->next == nullptr) return;
//		Node* temp = head;
//		while (temp->next != nullptr) {
//			temp = temp->next;
//		}
//		int tempValue = head->data;     // Store head's value in a temporary box
//		head->data = temp->data;        // Put tail's value into head
//		temp->data = tempValue;
//	}
//};
//int main() {
//	DoublyLinkedList list;
//	list.Push_front(100);
//	list.Push_front(200);
//	list.Push_front(300);
//	list.FindAndSquare(200);
//	list.SwapHeadAndTail();
//	list.display();
//}



//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//	Node(int val) : data(val), next(nullptr), prev(nullptr){}
//};
//
//class LinkedList {
//private:
//	Node* head;
//public:
//	LinkedList() {
//		head = nullptr;
//	}
//	~LinkedList() {
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void Push_front(int val) {
//		Node* newNode = new Node(val);
//		newNode->next = head;
//		head = newNode;
//		if (head != nullptr) {
//			head->prev = newNode;
//		}
//	}
//	void Display() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//	void Insert_After(int S_val, int N_val) {
//		if (head == nullptr) return;
//		Node* curr = head;
//		while (curr == nullptr && curr->data != S_val) {
//			curr = curr->next;
//		}
//		if (curr == nullptr)return;
//		Node* newNode = new Node(N_val);
//		newNode->next = curr->next;
//		curr->next = newNode;
//	}
//	void InsertBefore(int S_val, int N_val) {
//		Node* curr = head;
//		Node* prev = curr;
//		if (curr->data == S_val) {
//			Push_front(N_val);
//			return;
//		}
//		while (curr != nullptr && curr->data != S_val) {
//			prev = curr;
//			curr = curr->next;
//		}
//		if (curr == nullptr)return;
//		Node* newNode = new Node(N_val);
//		newNode->next = curr;
//		prev->next = newNode;
//
//
//	}
//};
//
//int main() {
//	LinkedList list;
//	list.Push_front(100);
//	list.Push_front(200);
//	list.Push_front(300);
//	list.InsertBefore(200, 250);
//	list.Insert_After(100, 150);
//	list.Display();
//}

//struct Node {
//	int data;
//	Node* next;
//	Node(int val): data(val) , next(nullptr) {}
//};
//class linkedlist {
//private:
//	Node* head;
//public:
//	linkedlist() {
//		head = nullptr;
//	}
//	~linkedlist() {
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void Push_front(int val) {
//		Node* Newnode = new Node(val);
//		Newnode->next = head;
//		head = Newnode;
//	}
//	void display() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//};
//int main() {
//	linkedlist list;
//	list.Push_front(100);
//	list.Push_front(200);
//	list.Push_front(300);
//	list.display();
//}
//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//	Node(int val):data(val),next(nullptr),prev(nullptr){}
//};
//
//class NodeManager {
//private:
//	Node*head;
//public:
//	void AddToEnd(int val) {
//		Node* newnode = new Node(val);
//		if (head == nullptr) {
//			head = newnode;
//			return;
//		}
//		Node* temp = head;
//		while (temp->next != nullptr) {
//			temp = temp->next;
//		}
//		temp->next = newnode;
//		newnode->prev = temp;
//
//	}
//	void PrintAll() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//};


//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//	Node(int val): data(val),next(nullptr),prev(nullptr){}
//};
//class DoublyLinkedList {
//private:
//	Node* head;
//public:
//	DoublyLinkedList() {
//		head = nullptr;
//	}
//	~DoublyLinkedList()
//	{
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void pushFront(int val) {
//		Node* newnode = new Node(val);
//		newnode->next = head;
//		if (head != nullptr) {
//			newnode->prev = newnode;
//		}
//		head = newnode;
//	}
//	void display() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//	void Push_back(int val) {
//		Node* newnode = new Node(val);
//		newnode->next = head; // 1. New node reaches forward to old head
//
//		if (head != nullptr) {
//			head->prev = newnode; // <--- THIS WAS THE FIX: Old head reaches BACK
//		}
//
//		head = newnode;
//	}
//	void DisplayReverse() {
//		Node* temp = head;
//		if (head == nullptr) return;
//		while (temp->next != nullptr) {
//			temp = temp->next;
//		}
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->prev;
//		}
//
//	}
//};
//int main() {
//	DoublyLinkedList list;
//	list.pushFront(100);
//	list.pushFront(200);
//	list.pushFront(300);
//	list.Push_back(90);
//	list.display();
//	list.DisplayReverse();
//	return 0;
//}
//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//	Node(int val ): data(val) , next(nullptr),prev(nullptr){}
//};
//class LinkedList {
//private:
//	Node* head;
//public:
//	LinkedList() {
//		head = nullptr;
//	}
//	~LinkedList() {
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void Puch_front(int val) {
//		Node* Newnode = new Node(val);
//		Newnode->next = head;
//		if (head != nullptr) {
//			head->prev = Newnode;
//		}
//		head = Newnode;
//	}
//	void display() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//	void displayreverse() {
//		Node* temp = head;
//		if (head == nullptr)return;
//		while (temp->next != nullptr) {
//			temp = temp->next;
//		}
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->prev;
//		}
//
//	}
//};
//int main() {
//	LinkedList list;
//	list.Puch_front(100);
//	list.Puch_front(200);
//	list.Puch_front(300);
//	list.Puch_front(400);
//	list.display();
//	//list.displayreverse();
//	return 0;
//}
//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//	Node(int val):data(val),next(nullptr),prev(nullptr){}
//};
//class LinkedList {
//private:
//	Node* head;
//public:
//	LinkedList() {
//		head = nullptr;
//	}
//	~LinkedList() {
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void Push_front(int val) {
//		Node* newnode = new Node(val);
//		newnode->next = head;
//		if (head != nullptr) {
//			head->prev = newnode;
//		}
//		head = newnode;
//	}
//	void display() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//	void displayReverse() {
//		Node* temp = head;
//		if (head == nullptr)return;
//		while (temp->next != nullptr) {
//			temp = temp->next;
//		}
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->prev;
//		}
//	}
//
//	void insertafter(int s_val, int n_val) {
//		
//		Node* curr = head;
//		if (head == nullptr)return;
//
//		while (curr != nullptr && curr->data != s_val) {
//			curr = curr->next;
//		}
//		if (curr == nullptr)return;
//		Node* newnode = new Node(n_val);
//		newnode->next = curr->next;
//		newnode->prev = curr;
//		if (curr->next != nullptr) {
//			curr->next->prev = newnode; 
//		}
//		curr->next = newnode;
//	}
//
//	void inserbefore(int s_val, int n_val) {
//		if (head->data == s_val) {
//			Push_front(n_val);
//			return;
//		}
//		Node* curr = head;
//		Node* prev = nullptr;
//		if (head == nullptr)return;
//		while (curr != nullptr && curr->data != s_val) {
//			prev = curr;
//			curr = curr->next;
//		}
//		if (curr == nullptr)return;
//		Node* newnode = new Node(n_val);
//		newnode->next = curr;
//		newnode->prev = prev;
//		prev->next = newnode;
//		curr->next = newnode;
//		
//	}
//};
//int main() {
//	LinkedList list;
//	list.Push_front(100);
//	list.Push_front(200);
//	list.Push_front(300);
//	list.insertafter(300,250);
//	list.inserbefore(300,350);
//	list.display();
//	std::cout << std::endl;
//	list.displayReverse();
//	return 0;
//}
//struct Post {
//	int postID;
//	int likes = 0;
//	Post* next;
//	Post* prev;
//	Post(int val): postID(val) , next(nullptr),prev(nullptr){}
//};
//class SocialFeed {
//private:
//	Post* head;
//public:
//	SocialFeed() {
//		head = nullptr;
//	}
//	~SocialFeed() {
//		Post* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void AddPost(int id) {
//		Post* newpost = new Post(id);
//		newpost->next = head;
//		if (head != nullptr) {
//			head->prev = newpost;
//		}
//		head = newpost;
//		
//	}
//	void LikePost(int targetID) {
//		Post* temp = head;
//		if (head == nullptr)return;
//		while (temp != nullptr && temp->postID != targetID) {
//			temp = temp->next;
//		}
//		if (temp == nullptr)return;
//		if (temp->postID == targetID) {
//			temp->likes += 1;
//		}
//		else {
//			std::cout << "Post not found." << std::endl;
//		}
//		temp = head;
//	}
//	void DeletePost(int id) {
//		Post* temp = head;
//		if (head == nullptr)return;
//		while (temp!= nullptr && temp->postID != id) {
//			temp = temp->next;
//		}
//		if (temp == nullptr) return;
//		if (temp == head) {
//			head = temp->next;
//		}
//		if (temp->prev != nullptr) {
//			temp->prev->next = temp->next;
//		}
//		if (temp->next != nullptr){
//			temp->next->prev = temp->prev;
//
//		}
//			delete temp;
//	}
//	void ShowFeed() {
//		Post* temp = head;
//		while (temp != nullptr) {
//			std::cout << "Post " << temp->postID << " has " << temp->likes << " likes." << std::endl;
//			temp = temp->next;
//		}
//	}
//};
//int main() {
//	SocialFeed feed;
//	feed.AddPost(1);
//	feed.AddPost(2);
//	feed.AddPost(3);
//	feed.LikePost(2);
//	feed.DeletePost(2);
//	feed.ShowFeed();
//	return 0;
//}


//struct Song {
//	int id;
//	Song* next;
//	Song* prev;
//	Song(int val) : id(val), next(nullptr), prev(nullptr) {}
//};
//class MusicQueue {
//private:
//	Song* head;
//public:
//	MusicQueue() {
//		head = nullptr;
//	}
//	~MusicQueue() {
//		Song* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void BoostToFront(int val) {
//		Song* newsong = new Song(val);
//		newsong->next = head;
//		if (head != nullptr) {
//			head->prev = newsong;
//		}
//		head = newsong;
//	}
//	void AddToEnd(int val) {
//		Song* newsong = new Song(val);
//		if (head == nullptr) {
//			head = newsong;
//			return;
//		}
//		Song* temp = head;
//		while (temp->next != nullptr) {
//			temp = temp->next;
//		}
//		temp->next = newsong;
//		newsong->prev = temp;
//	}
//	void SkipSong(int targetID) {
//		Song* temp = head;
//		while (temp != nullptr && temp->id != targetID) {
//			temp = temp->next;
//		}
//		if (temp == nullptr)return;
//		if (temp == head) {
//			head = temp->next;
//		}
//		if (temp->next != nullptr) {
//			temp->next->prev = temp->prev;
//		}
//		if (temp->prev!= nullptr) {
//			temp->prev->next = temp->next;
//		}
//		delete temp;
//	}
//
//	void shipv2(int tar) {
//		Song* temp = head;
//		while (temp != nullptr && temp->id != tar) {
//			temp = temp->next;
//		}
//		if (temp == nullptr) return;
//		if (temp == head) {
//			head = temp->next;
//		}
//		if (temp->next != nullptr) {
//			temp->next->prev = temp->prev;
//		}
//		if (temp->prev != nullptr) {
//			temp->prev->next = temp->next;
//		}
//		delete temp;
//	}
//
//	void ShowQueue() {
//		Song* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->id << std::endl;
//			temp = temp->next;
//		}
//	}
//	void ShowQueueReverse() {
//		Song* temp = head;
//		while (temp->next != nullptr) {
//			temp = temp->next;
//		}
//		while (temp != nullptr) {
//			std::cout << temp->id << std::endl;
//			temp = temp->prev;
//		}
//	}
//};
//int main() {
//	MusicQueue mu;
//	mu.BoostToFront(1);
//	mu.BoostToFront(2);
//	mu.BoostToFront(3);
//	mu.AddToEnd(4);
//	mu.ShowQueue();
//	mu.shipv2(3);
//	std::cout << "" << std::endl;
//	mu.ShowQueueReverse();
//	return 0;
//
//}

//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//	Node(int val) : data(val),next(nullptr),prev(nullptr){}
//};
//class final_lists {
//private:
//	Node* head;
//public:
//	final_lists() {
//		head = nullptr;
//	}
//	~final_lists() {
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void push_front(int val) {
//		Node* newnode = new Node(val);
//		newnode->next = head;
//		if (head != nullptr) {
//			head->prev = newnode;
//		}
//		head = newnode;
//	}
//	void  pushBack(int val) {
//		if (head == nullptr) {
//			push_front(val);
//			return;
//		}
//		Node* newnode = new Node(val);
//		Node* temp = head;
//		newnode->prev = head;
//		while (temp ->next!= nullptr) {
//			temp = temp->next;
//		}
//		temp->next = newnode;
//		newnode->prev = temp;
//	}
//	void insertafter(int s_val, int n_val) {
//		Node* curr = head;
//		while (curr != nullptr && curr->data != s_val) {
//			curr = curr->next;
//		}
//		if (curr != nullptr) {
//			Node* newnode = new Node(n_val);
//			newnode->next = curr->next;
//			newnode->prev = curr;
//			if (curr->next != nullptr) {
//				curr->next->prev = newnode;
//			}
//			curr->next = newnode;
//		}
//	}
//	void swapData(int val1, int val2) {
//		Node* node1 = head;
//		Node* node2 = head;
//		while (node1 != nullptr && node1->data != val1) {
//			node1 = node1->next;
//		}
//		while (node2 != nullptr && node2->data != val2) {
//			node2 = node2->next;
//		}
//		if (node1 != nullptr && node2 != nullptr) {
//			int temp = node1->data;
//			node1->data = node2->data;
//			node2->data = temp;
//		}
//		else {
//			std::cout << "NOT FOUND!!" << std::endl;
//		}
//	}
//	void display() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//};
//int main() {
//	final_lists list;
//	list.push_front(100);
//	list.push_front(200);
//	list.push_front(300);
//	list.pushBack(90);
//	list.insertafter(90, 85);
//	list.swapData(100, 85);
//	list.display();
//}

//struct task {
//	int id;
//	int priority;
//	task* next;
//	task* prev;
//	task(int val,int v) : id(val) ,priority(v), next(nullptr), prev(nullptr) {}
//};
//class taskmanager {
//private:
//	task* head;
//public:
//	taskmanager() {
//		head = nullptr;
//	}
//	~taskmanager() {
//		task* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void addfirst(int id, int priority) {
//		task* newtask = new task(id, priority);
//		newtask->next = head;
//		if (head != nullptr) {
//			head->prev = newtask;
//		}
//		head = newtask;
//	}
//	void addlast(int id, int priority) {
//		task* newtask = new task(id, priority);
//		if (head == nullptr) {
//			head = newtask;
//			return;
//		}
//		task* temp = head;
//		while (temp->next != nullptr) {
//			temp = temp->next;
//		}
//		temp->next = newtask;
//		newtask->prev = temp;
//	}
//};




//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//	Node(int val):data(val),next (nullptr),prev(nullptr){}
//};
//class DoublyLinkedList {
//private:
//	Node* head;
//public:
//	DoublyLinkedList() {
//		head = nullptr;
//	}
//	~DoublyLinkedList() {
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void Push_front(int val) {
//		Node* newnode = new Node(val);
//		newnode->next = head;
//		if (head != nullptr) {
//			head->prev = newnode;
//		}
//		head = newnode;
//	}
//	void swapNodes(int v1, int v2) {
//		if (v1 == v2)return;
//		Node* A = head;
//		Node* B = head;
//		while (A != nullptr && A->data != v1) A = A->next;
//		while (B != nullptr && B->data != v2) B = B->next;
//		if (A == nullptr || B == nullptr)return;
//
//		if (B->next == A) {
//			Node* temp = A;
//			A = B;
//			B = temp;
//		}
//		 
//		Node* p1 = A->prev;
//		Node* p2 = A->next;
//		Node* n1 = B->prev;
//		Node* n2 = B->next;
//
//		if (p2 != B) {
//			if (p1) p1->next = B; else head = B;
//			if (n2) n2->prev = A;
//			if (p2) p2->prev = B;
//			if (n1) n1->next = A;
//			B->prev = p1;
//			B->next = p2;
//			A->prev = n1;
//			A->next = n2;
//		}
//		else {
//			if (p1) p1->next = B; else head = B;
//			if (n2) n2->prev = A;
//			B->prev = p1;
//			B->next = A;
//			A->prev = B;
//			A->next = n2;
//		}
//	}
//	void display() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//	void reversedisplay() {
//		Node* temp = head;
//		while (temp->next != nullptr) {
//			temp = temp->next;
//		}
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->prev;
//		}
//	}
//	void insertafter(int s_val, int n_val) {
//		Node* curr = head;
//		if (head == nullptr) return;
//		while (curr != nullptr && curr->data != s_val) {
//			curr = curr->next;
//		}
//		if (curr == nullptr) return;
//		Node* newnode = new Node(n_val);
//		newnode->next = curr->next;
//		if (curr->next != nullptr) {
//			curr->next->prev = newnode;
//		}
//		curr->next = newnode;
//		newnode->prev = curr;
//	}
//	void insertbefore(int s_val, int n_val) {
//		Node* curr = head;
//		Node* prev = nullptr;
//		if (curr->data == s_val)Push_front(n_val); return;
//		while (curr != nullptr && curr->data != s_val) {
//			prev = curr;
//			curr = curr->next;
//		}
//		if (curr == nullptr)return;
//		Node* newnode = new Node(n_val);
//		prev->next = newnode;
//		newnode->next = curr;
//	}
//};
//int main() {
//	DoublyLinkedList list;
//	list.Push_front(100);
//	list.Push_front(200);
//	list.Push_front(200);
//	list.Push_front(300);
//	list.Push_front(400);
//	list.Push_front(500);
//	list.reversedisplay();
//	std::cout << std::endl;
//	//list.swapNodes(500, 100);
//	//list.swapNodes(200, 300);
//	list.insertafter(200, 250);
//	//list.insertbefore(500, 450);
//	list.display();


//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//	Node(int val):data(val) , next(nullptr), prev(nullptr){}
//};
//class Lists {
//private:
//	Node* head;
//public:
//	Lists() {
//		head = nullptr;
//	}
//	~Lists() {
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void Push_front(int val) {
//		Node* newnode = new Node(val);
//		newnode->next = head;
//		if (head != nullptr) {
//			head->prev = newnode;
//		}
//		head = newnode;
//	}
//		void swapNodes(int v1, int v2) {
//			if (v1 == v2) return;
//			Node* A = head;
//			Node* B = head;
//			while (A != nullptr && A->data != v1) A = A->next;
//			while (B != nullptr && B->data != v2) B = B->next;
//			if (A == nullptr || B == nullptr) return;
//			if (B->next != A) {
//				Node* temp = A;
//				A = B;
//				B = temp;
//			}
//			Node* A_prev = A->prev;
//			Node* A_next = A->next;
//			Node* B_prev = B->prev;
//			Node* B_next = B->next;
//			if (A_next != B) {
//				if (A_prev) A_prev->next = B; else head = B;
//				if (A_next) A_next->prev = B;
//				if (B_prev) B_prev->next = A;
//				if (B_next) B_next->prev = A;
//				B->prev = A_prev;
//				B->next = A_next;
//				A->prev = B_prev;
//				A->next = B_next;
//			}
//			else {
//				if (A_prev) A_prev->next = B; else head = B;
//				if (B_next) B_next->prev = A;
//				B->prev = A_prev;
//				B->next = A;
//				A->prev = B;
//				A->next = B_next;
//			}
//		}
//		void insertafter(int s_val, int n_val) {
//			if (head == nullptr)return;
//			Node* curr = head;
//			while (curr != nullptr && curr->data != s_val) {
//				curr = curr->next;
//			}
//			if (curr == nullptr) return;
//			Node* newnode = new Node(n_val);
//			newnode->next = curr->next;
//			if (curr->next != nullptr) {
//				curr->next->prev = newnode;
//			}
//			curr->next = newnode;
//			newnode->prev = curr;
//		}
//};







//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//	Node(int val):data(val),next(nullptr),prev(nullptr){}
// };
//class Doublylinkelist {
//private:
//	Node* head;
//public:
//	Doublylinkelist() {
//		head = nullptr;
//	}
//	~Doublylinkelist() {
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void Push_front(int val) {
//		Node* newnode = new Node(val);
//		newnode->next = head;
//		if (head != nullptr) {
//			head->prev = newnode;
//		}
//		head = newnode;
//	}
//
//	void swapNodes(int v1, int v2) {
//		if (v1 == v2)return;
//		Node* A = head;
//		Node* B = head;
//		while (A != nullptr && A->data != v1) A = A->next;
//		while (B != nullptr && B->data != v2) B = B->next;
//		if (A == nullptr || B == nullptr) return;
//		if (B->next != A) {
//			Node* temp = A;
//			A = B;
//			B = temp;
//		}
//		Node* A_prev = A->prev;
//		Node* A_next = A->next;
//		Node* B_prev = B->prev;
//		Node* B_next = B->next;
//		if (A_next != B) {
//			if (A_prev) A_prev->next = B; else head = B;
//			if (A_next) A_next->prev = B;
//			if (B_prev) B_prev->next = A;
//			if (B_next) B_next->prev = A;
//			B->prev = A_prev;
//			B->next = A_next;
//			A->prev = B_prev;
//			A->next = B_next;
//		}
//		else {
//			if (A_prev) A_prev->next = B; else head = B;
//			if (B_next) B_next->prev = A;
//			B->prev = A_prev;
//			B->next = A;
//			A->prev = B;
//			A->next = B_next;
//		}
//	}
//	void InsertAfter(int S_val /*200*/, int N_val/*150*/) {
//		if (head == nullptr)return;
//		Node* curr = head;
//		while (curr != nullptr && curr->data != S_val) curr = curr->next;
//		if (curr == nullptr)return;
//		Node* newnode = new Node(N_val);
//		newnode->next = curr->next;
//		newnode->prev = curr;
//		if (curr->next != nullptr) {
//			curr->next->prev = newnode;
//		}
//		curr->next = newnode;
//	}
//	void Inserbefore(int S_val/*200*/, int N_val/*250*/) {
//		if (head == nullptr)return;
//		Node* curr = head;
//		while (curr != nullptr && curr->data != S_val) curr = curr->next;
//		if (curr == nullptr)return;
//		Node* newnode = new Node(N_val);
//		newnode->prev = curr->prev;
//		newnode->next = curr;
//		if (curr->next != nullptr) {
//			curr->prev->next = newnode;
//		}
//		curr->prev = newnode;
//		
//	}
//	void Display() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//
//	void Displayreverse() {
//		Node* temp = head;
//		while (temp->next != nullptr) {
//			temp = temp->next;
//		}
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->prev;
//		}
//	}
//};
//
//
//
//int main() {
//	Doublylinkelist list;
//	list.Push_front(100);
//	list.Push_front(200);
//	list.Push_front(300);
//	list.Push_front(400);
//	list.Push_front(500);								
//	//list.InsertAfter(200, 150);
//	list.Inserbefore(200,250);
//	list.swapNodes(100, 500);
//	list.Display();
//	std::cout << std::endl;
//	list.Displayreverse();
//}
//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//	Node(int val):data(val),next (nullptr),prev(nullptr){}
//};
//class DDLL {
//private:
//	Node* head;
//public:
//	DDLL() {
//		head = nullptr;
//	}
//	~DDLL() {
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void Push_front(int val) {
//		Node* newnode = new Node(val);
//		newnode->next = head;
//		if (head != nullptr) {
//			head->prev = newnode;
//		}
//		head = newnode;
//	}
//	void swapNodes(int v1, int v2) {
//		if (v1 == v2)return;
//		Node* A = head;
//		Node* B = head;
//		while (A != nullptr && A->data != v1) A = A->next;
//		while (B != nullptr && B->data != v2) B = B->next;
//		if (A == nullptr || B == nullptr) return;
//		if (A->next != B) {
//			Node* temp = A;
//			A = B;
//			B = temp;
//		}
//		Node* A_prev = A->prev;
//		Node* A_next = A->next;
//		Node* B_prev = B->prev;
//		Node* B_next = B->next;
//		if (A_next != B) {
//			if (A_prev) A_prev->next = B; else head = B;
//			if (A_next) A_next->prev = B; 
//			if (B_prev) B_prev->next = A; 
//			if (B_next) B_next->next = A;
//			B->prev = A_prev;
//			B->next = A_next;
//			A->prev = B_prev;
//			A->next = B_next;
//		}
//		else {
//			if (A_prev) A_prev->next = B; else head = B;
//			if (B_next) B_next->next = A;
//			B->prev = A_prev;
//			B->next = A;
//			A->prev = B;
//			A->next = B_next;
//		}
//	}
//	void InsertAfter(int S_val, int N_val) {
//		if (head == nullptr)return;
//		Node* curr = head;
//		while (curr != nullptr && curr->data != S_val) curr = curr->next;
//		if (curr == nullptr)return;
//		Node* newnode = new Node(N_val);
//		newnode->next = curr->next;
//		newnode->prev = curr;
//		if (curr->next != nullptr) {
//			curr->next->prev = newnode;
//		}
//		curr->next = newnode;
//	}
//	void Inserbefore(int S_val,int N_val){
//		if (head == nullptr)return;
//		Node* curr = head;
//		while (curr != nullptr && curr->data != S_val) curr = curr->next;
//		if (curr == nullptr)return;
//		Node* newnode = new Node(N_val);
//		newnode->prev = curr->prev;
//		newnode->next = curr;
//		if (curr->prev != nullptr) {
//			curr->prev->next = newnode;
//		}
//		curr->prev = newnode;
//	}
//	void Display() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//	void Displayreverse() {
//		Node* temp = head;
//		while (temp->next != nullptr) {
//			temp = temp->next;
//		}
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->prev;
//		}
//	}
//};
//
//int main() {
//	DDLL list;
//	list.Push_front(100);
//	list.Push_front(200);
//	list.Push_front(300);
//	list.Push_front(400);
//	list.Push_front(500);								
//	list.InsertAfter(200, 150);
//	list.Inserbefore(200,250);
//	list.swapNodes(100, 500);
//	list.Displayreverse();
//	std::cout << std::endl;
//	list.Display();
//}
//struct Item {
// 
//	int value;
//	Item* next;
//	Item(int val) :value(val), next(nullptr){}
//};
//
//class ListManager {
//private:
//	Item* head;
//public:
//	ListManager() {
//		head = nullptr;
//	}
//
//	~ListManager() {
//		Item* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//
//
//	void insert(int n) {
//		Item* newItem = new Item(n);
//			newItem->next = head;
//			head = newItem;
//	}
//
//	void show() {
//		Item* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->value << std::endl;
//			temp = temp->next;
//		}
//	}
//};
//int main() {
//	ListManager list;
//	list.insert(100);
//	list.insert(200);
//	list.insert(300);
//
//	list.show();
//
//	return 0;
//}
//struct Car {
//	int data;
//	Car* next;
//};
//struct Node{
//	int data;
//	Node* next;
//	Node(int val) :data(val), next(nullptr) {}
//};
//
//class linkedlists {
//private:
//	Node* head;
//public:
//	linkedlists() {
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	
//	void printloop() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//
//		}
//	}
//
//	void push_front(int value) {
//		Node* newNode = new Node(value);
//		newNode->next = head;
//		head = newNode;
//	}
//};

//int main() {
	//Node* a = new Node(10);
	//Node* b = new Node(20);
	//Node* c = new Node(30);
	//Node* temp = a;
	//a->next = b;
	//b->next = c;
	//c->next = nullptr;
	//while (temp != nullptr) {
	//	std::cout << temp->data << std::endl;
	//	temp = temp->next;
	//}
	//delete a;
	//delete b;
	//delete c;
	//return 0;

	//Node* a = new Node(10);
	//Node* b = new Node(20);
	//Node* c = new Node(30);
	//Node* NewNode = new Node(5);
	//Node* EndNode = new Node(40);
	//Node* temp = NewNode;
	//NewNode->next = a;
	//a->next = b;
	//b->next = c;
	//c->next = EndNode;
	//delete NewNode;
	//delete a;
	//delete b;
	//delete c;
	//delete EndNode;
	//linkedlists list;
	//list.push_front(30);
	//list.push_front(20);
	//list.push_front(10);
	//list.printloop();
	//
	//return 0;


	//Node* head = new Node(50);
	//Node* tail = new Node(100);
	//head->next = tail;
	//std::cout << "the value of n2 via n1 is:" <<head->next->data<< std::endl;
	//delete head;
	//delete tail;
	//return 0;

	//Node* NodeA = new Node;
	//NodeA->data = 10;
	//NodeA->next = nullptr;
	//Node* NodeB = new Node;
	//NodeB->data = 20;
	//NodeB->next = nullptr;
	//
	//NodeA->next = NodeB;
	//std::cout << "Node B value via A: " << NodeA->next->data << std::endl;
	//
	//return 0;
	//Node* n1 = new Node;
	//Node* n2 = new Node;
	//Node* n3 = new Node;
	//n1->data = 10;
	//n2->data = 20;
	//n3->data = 30;
	//n1->next = n2;
	//n2->next = n3;
	//n3->next = n1;
	//std::cout << "the first value: " << n1->next->next->next->data << std::endl;
	//delete n1;
	//delete n2;
	//delete n3;
	//return 0;
	 
	
	//Car* head = new Car;
	//Car* middle = new Car;
	//Car* last = new Car;
	//head->data = 100;
	//middle->data = 200;
	//last->data = 300;
	//head->next = middle;
	//middle->next = last;
	//last->next = nullptr;
	//std::cout << "the last value is :" << head->next->next->data << std::endl;
	//delete head;
	//delete middle;
	//delete head;
	//return 0;
	//// question 1
	//int target = 10;
	//int* ptr = &target;
	//*ptr = 7000;
	//std::cout << "the value is now:" << *ptr << std::endl;
	//question 2
	//int ptr;
	//int* ptr2 = new int;
	//*ptr2 = 500;
	//std::cout << "the value is now:" << *ptr2 << std::endl;
	//delete ptr2;
	//question 3
	//int arr[] = { 10,20,30 };
	//int* ptr = arr;
	//for (int i = 0; i < 3; i++) {
	//	std::cout << *ptr << std::endl;
	//	ptr++;
	//}
	//question 4
	//int score;
	//std::cout << "enter the no. of players"<<std::endl;
	//std::cin >> score;
	//int* scoreboard = new int[score];
	//for (int i = 0; i < score; i++) {
	//	std::cout << "enter the player "<<i+1<<" score:" << std::endl;
	//	std::cin >> scoreboard[i];	
	//}
	//std::cout << "Scoreboard!"<< std::endl;
	//for (int i = 0; i < score; i++) {
	//	std::cout << "player " << i + 1 << ":" <<scoreboard[i]<< std::endl;
	//}
	//delete[] scoreboard;


//}

//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//	Node(int val):data(val),next(nullptr),prev(nullptr){}
//};
//class DDLL {
//private:
//	Node* head;
//public:
//	DDLL() {
//		head = nullptr;
//	}
//	~DDLL() {
//		Node* temp = head;
//		while (head != nullptr) {
//			head = head->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void Push_front(int val) {
//		Node* newnode = new Node(val);
//		newnode->next = head;
//		if (head != nullptr) {
//			head->prev = newnode;
//		}
//		head = newnode;
//	}
//	void swap(int v1, int v2) {
//		if (v1 == v2)return;
//		Node* A = head;
//		Node* B = head;
//		while (A != nullptr && A->data != v1) A = A->next;
//		while (B != nullptr && B->data != v2) B = B->next;
//		if (A == nullptr || B == nullptr)return;
//		if (A->next != B) {
//			Node* temp = A;
//			A = B;
//			B = temp;
//		}
//		Node* A_prev = A->prev;
//		Node* A_next = A->next;
//		Node* B_prev = B->prev;
//		Node* B_next = B->next;
//		if (A_next != B) {
//			if (A_prev) A_prev->next = B; else head = B;
//			if (A_next) A_next->prev = B;
//			if (B_prev) B_prev->next = A;
//			if (B_next) B_next->prev = A;
//			B->prev = A_prev;
//			B->next = A_next;
//			A->prev = B_prev;
//			A->next = B_next;
//		}
//		else {
//			if (A_prev) A_prev->next = B; else head = B;
//			if (B_next) B_next->prev = A;
//			B->prev = A_prev;
//			B->next = A;
//			A->prev = B;
//			A->next = B_next;
//		}
//	}
//	void InsertAfter(int S_val, int N_val) {
//		if (head == nullptr)return;
//		Node* curr = head;
//		while (curr != nullptr && curr->data != S_val) curr = curr->next;
//		if (curr == nullptr)return;
//		Node* newnode = new Node(N_val);
//		newnode->next = curr->next;
//		newnode->prev = curr;
//		if (curr->next != nullptr) {
//			curr->next->prev = newnode;
//		}
//		curr->next = newnode;
//	}
//	void Inserbefore(int S_val,int N_val){
//		if (head == nullptr)return;
//		Node* curr = head;
//		while (curr != nullptr && curr->data != S_val) curr = curr->next;
//		if (curr == nullptr)return;
//		Node* newnode = new Node(N_val);
//		newnode->prev = curr->prev;
//		newnode->next = curr;
//		if (curr->prev != nullptr) {
//			curr->prev->next = newnode;
//		}
//		curr->prev = newnode;
//	}
//	void Display() {
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//	void Displayreverse() {
//		if (head == nullptr)return;
//		Node* temp = head;
//		while (temp->next != nullptr) {
//			temp = temp->next;
//		}
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->prev;
//		}
//	}
//	bool checkIntegrity() {
//		if (head == nullptr)return true;
//		Node* curr = head;
//		while (curr->next != nullptr) {
//			Node* newnode = curr->next;
//			if (newnode->prev != curr) {
//				std::cout << "its broken!!" << std::endl;
//				return false;
//			}
//			curr = curr->next;
//		}
//		return true;
//	}
//	void deleteNode(int S_val) {
//		if (head == nullptr)return;
//		Node* curr = head;
//		while (curr!= nullptr && curr->data != S_val) {
//			curr = curr->next;
//		}
//		if (curr == nullptr) return;
//		if (curr->prev != nullptr) {
//			curr->prev->next = curr->next; 
//		}
//		else {
//			head = curr->next;
//		}
//
//		if (curr->next != nullptr) {
//			curr->next->prev = curr->prev; 
//		}
//		delete curr;
//	}
//};
//int main() {
//	DDLL list;
//	int myData[] = { 100, 200, 300, 400, 500 };
//
//	for (int i = 0; i < 5; i++) {
//		list.Push_front(myData[i]); 
//	}
//
//	list.InsertAfter(200, 150);
//	list.Inserbefore(200,250);
//	list.swap(100, 500);
//	list.Displayreverse();
//	std::cout << std::endl;
//	list.Display();
//	list.checkIntegrity();
//	list.deleteNode(300);
//	std::cout << std::endl;
//	list.Display();
//
//}


//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//	Node(int val) : data(val), next(nullptr), prev(nullptr) {}
//};
//
//class DLL {
//private:
//	Node* head;
//public:
//
//	DLL() {
//		head = nullptr;
//	}
//
//	~DLL() {
//		if (head == nullptr)return;
//		Node* temp = head;
//		while (head != nullptr) {
//			temp = temp->next;
//			delete temp;
//			temp = head;
//		}
//	}
//	void Push(int val) {
//		Node* newnode = new Node(val);
//		head = newnode->next;
//		if (head != nullptr) {
//			head->prev = newnode;
//		}
//		newnode = head;
//	}
//
//	void display() {
//		if (head == nullptr)return;
//		Node* temp = head;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//};
//int main() {
//	DLL l;
//	l.Push(100);
//	l.Push(200);
//	l.Push(300);
//	l.Push(400);
//	l.display();
//	return 0;
//}


//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//	Node(int val) :data(val), next(nullptr), prev(nullptr) {}
//};
//class CDLL {
//private:
//	Node* head;
//public:
//	CDLL() {
//		head = nullptr;
//	}
//	~CDLL() {
//		std::cout << "The Execution is over now clearing memory" << std::endl;
//		Node* temp = head;
//		if (head != nullptr) {
//			Node* tail = head->prev;
//			tail->next = nullptr;
//			while (head != nullptr) {
//				Node* temp = head;
//				head = head->next;
//				delete temp;
//			}
//		}
//		std::cout << "Memory cleared from heap!" << std::endl;
//
//	}
//	void Push(int val) {
//		Node* newnode = new Node(val);
//		if (head == nullptr) {
//			head = newnode;
//			head->next = head;
//			head->prev = head;
//			return;
//		}
//		Node* tail = head->prev;
//		newnode->next = head;
//		newnode->prev = tail;
//		tail->next = newnode;
//		head->prev = newnode;
//	}
//
//	void display() {
//		if (head == nullptr)return;
//		Node* temp = head;
//		do {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		} while (temp != nullptr);
//		std::cout << std::endl;
//	}
//
//	void displayRES() {
//		Node* temp = head;
//		while (temp->next != nullptr) {
//			temp = temp->next;
//		}
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->prev;
//
//		}
//	}
//};
//int main() {
//	CDLL list;
//	list.Push(150);
//	list.Push(151);
//	list.Push(152);
//	list.display();
//	std::cout << std::endl;
//	list.displayRES();
//}




//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//	Node(int val) : data(val), next(nullptr), prev(nullptr) {}
//};
//
//class CDLL {
//private:
//	Node* head;
//public:
//	CDLL() {
//		head = nullptr;
//	}
//	~CDLL() {
//		if (head == nullptr) return;
//		Node* curr = head;
//		head->prev->next = nullptr;
//		while (curr != nullptr) {
//			Node* nextNode = curr->next;
//			delete curr;
//			curr = nextNode;
//		}
//		head = nullptr;
//	}
//	void Push_front(int val) {
//		Node* newnode = new Node(val);
//		if (head == nullptr) {
//			head = newnode;
//			newnode->next = head;
//			newnode->prev = head;
//		}
//		else {
//			Node* tail = head->prev;
//			newnode->next = head;
//			newnode->prev = tail;
//			tail->next = newnode;
//			head->prev = newnode;
//			head = newnode;
//		}
//	}
//	void swap(int v1, int v2) {
//		if (v1 == v2 || head == nullptr) return;
//		Node* A = head;
//		Node* B = head;
//		bool foundA = false, foundB = false;
//		Node* temp = head;
//		do {
//			if (temp->data == v1) { A = temp; foundA = true; }
//			if (temp->data == v2) { B = temp; foundB = true; }
//			temp = temp->next;
//		} while (temp != head);
//
//		if (!foundA || !foundB) return;
//
//		if (A->next == B) {
//			Node* A_prev = A->prev;
//			Node* B_next = B->next;
//			A_prev->next = B;
//			B->prev = A_prev;
//			B->next = A;
//			A->prev = B;
//			A->next = B_next;
//			B_next->prev = A;
//		}
//		else if (B->next == A) {
//			Node* B_prev = B->prev;
//			Node* A_next = A->next;
//			B_prev->next = A;
//			A->prev = B_prev;
//			A->next = B;
//			B->prev = A;
//			B->next = A_next;
//			A_next->prev = B;
//		}
//		else {
//			Node* A_prev = A->prev;
//			Node* A_next = A->next;
//			Node* B_prev = B->prev;
//			Node* B_next = B->next;
//			A_prev->next = B;
//			A_next->prev = B;
//			B->prev = A_prev;
//			B->next = A_next;
//			B_prev->next = A;
//			B_next->prev = A;
//			A->prev = B_prev;
//			A->next = B_next;
//		}
//		if (head == A) head = B;
//		else if (head == B) head = A;
//	}
//	void InsertAfter(int S_val, int N_val) {
//		if (head == nullptr) return;
//		Node* curr = head;
//		bool found = false;
//		do {
//			if (curr->data == S_val) { found = true; break; }
//			curr = curr->next;
//		} while (curr != head);
//		if (!found) return;
//		Node* newnode = new Node(N_val);
//		newnode->next = curr->next;
//		newnode->prev = curr;
//		curr->next->prev = newnode;
//		curr->next = newnode;
//	}
//	void Inserbefore(int S_val, int N_val) {
//		if (head == nullptr) return;
//		Node* curr = head;
//		bool found = false;
//		do {
//			if (curr->data == S_val) { found = true; break; }
//			curr = curr->next;
//		} while (curr != head);
//		if (!found) return;
//		Node* newnode = new Node(N_val);
//		newnode->next = curr;
//		newnode->prev = curr->prev;
//		curr->prev->next = newnode;
//		curr->prev = newnode;
//		if (curr == head) head = newnode;
//	}
//	void Display() {
//		if (head == nullptr) return;
//		Node* temp = head;
//		do {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		} while (temp != head);
//	}
//	void Displayreverse() {
//		if (head == nullptr) return;
//		Node* temp = head->prev;
//		Node* tail = head->prev;
//		do {
//			std::cout << temp->data << std::endl;
//			temp = temp->prev;
//		} while (temp != tail);
//	}
//	bool checkIntegrity() {
//		if (head == nullptr) return true;
//		Node* curr = head;
//		do {
//			if (curr->next->prev != curr) {
//				std::cout << "its broken!!" << std::endl;
//				return false;
//			}
//			curr = curr->next;
//		} while (curr != head);
//		return true;
//	}
//	void deleteNode(int S_val) {
//		if (head == nullptr) return;
//		Node* curr = head;
//		bool found = false;
//		do {
//			if (curr->data == S_val) { found = true; break; }
//			curr = curr->next;
//		} while (curr != head);
//		if (!found) return;
//		if (curr->next == curr) {
//			head = nullptr;
//		}
//		else {
//			curr->prev->next = curr->next;
//			curr->next->prev = curr->prev;
//			if (curr == head) head = curr->next;
//		}
//		delete curr;
//	}
//};
//
//int main() {
//	CDLL list;
//	int myData[] = { 100, 200, 300, 400, 500 };
//	for (int i = 0; i < 5; i++) {
//		list.Push_front(myData[i]);
//	}
//	list.InsertAfter(200, 150);
//	list.Inserbefore(200, 250);
//	list.swap(100, 500);
//	list.Displayreverse();
//	std::cout << std::endl;
//	list.Display();
//	list.checkIntegrity();
//	list.deleteNode(300);
//	std::cout << std::endl;
//	list.Display();
//	return 0;
//}


// ============================================================================================================================================================
// ============================================================================================================================================================
// ============================================================================================================================================================
// ============================================================================================================================================================

//struct Node {
//	int data;
//	Node* next;
//	Node(int val) :data(val), next(nullptr) {};
//};
//class stack {
//private:
//	Node* top;
//public:
//	stack() {
//		top = nullptr;
//	}
//	~stack() {
//		if (top == nullptr) return;
//		while (top != nullptr) {
//			pop();
//		}
//	}
//	void Push(int val){
//		Node* newnode = new Node(val);
//		newnode->next = top;
//		top = newnode;
//	}
//	void pop() {
//		if (top == nullptr) {
//			std::cout << "stack underflow!! Nothing to display!" << std::endl;
//			return; 
//		}
//		Node* temp = top;
//		top = top->next;
//		delete temp;
//	}
//	int peek() {
//			if (top == nullptr) {
//			std::cout << "stack underflow! Nothing to display." << std::endl;
//			return -1;
//		}
//		return top->data;
//	}
//	void display() {
//		if (top == nullptr) { 
//			std::cout << "stack underflow!! Nothing to display!" << std::endl;
//			return; 
//		}
//		Node* temp = top;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//};
//int main() {
//	stack s;
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//	s.Push(5);
//	s.display();
//	s.peek();
//	return 0;
//}


//class ArrayStack {
//private:
//	int top;
//	int arr[5];
//public:
//	ArrayStack() { top = -1; }
//	void push(int val) {
//		if (top == 4) {
//			std::cout << "stack overflow! Nothing to display."<< val << std::endl;
//						return;
//		}
//		arr[++top] = val;
//	}
//	void pop() {
//		if (top == -1) {
//			std::cout << "stack underflow!! Nothing to display!" << std::endl;
//			return;
//		}
//		std::cout <<"deleted : "<< arr[top--] << std::endl;
//	}
//};
//int main() {
//	ArrayStack at;
//	at.push(1);
//	at.push(2);
//	at.push(3);
//	at.push(4);
//	at.push(5);
//	at.pop();
//}
//struct Node {
//	std::string data;
//	Node* next;
//	Node(std::string val) :data(val), next(nullptr){}
//};
//
//class Stack {
//private:
//	Node* top;
//public:
//	Stack() {
//		top = nullptr;
//	}
//	~Stack() {
//		if (top == nullptr)return;
//		Node* temp = top;
//		while (top != nullptr) {
//			top = top->next;
//			delete temp;
//			temp = top;
//		}
//
//	}
//	void Push(std::string value) {
//		Node* newnode = new Node(value);
//		newnode->next = top;
//		top = newnode;
//	}
//	void display() {
//		if (top == nullptr) { 
//			std::cout << "stack underflow!! Nothing to display!" << std::endl;
//			return; 
//		}
//		Node* temp = top;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//	std::string peek() {
//		if (top == nullptr) {
//			std::cout << "stack underflow! Nothing to display." << std::endl;
//			return "";
//		}
//		return top->data;
//	}
//	void pop() {
//		if (top == nullptr) {
//			std::cout << "stack is empty! Nothing to display" << std::endl;
//			return;
//		}
//		Node* temp = top;
//		top = top->next;
//		delete temp;
//
//	}
//
//};
//int main() {
//	Stack st;
//	st.Push("hello world");
//	st.Push("hello linkedlists");
//	st.Push("hello Stack");
//	st.pop();
//	st.display();
// st.peek()
//};

// ============================================================================================================================================================
// ============================================================================================================================================================
// ============================================================================================================================================================
// ============================================================================================================================================================


//class LinkedQueues {
//private:
//	struct Node {
//		int data;
//		Node* next;
//		Node(int val) :data(val), next(nullptr) {}
//	};
//	Node* front;
//	Node* rear;
//public:
//	LinkedQueues() {
//		front = nullptr;
//		rear = nullptr;
//	}
//	~LinkedQueues() {
//		while (front != nullptr) {
//			Dequeue();
//		}
//	}
//	void enqueue(int val){
//		Node* newnode = new Node(val);
//		if (rear == nullptr) {
//			front = rear = newnode;
//			return;
//		}
//		rear->next = newnode;
//		rear = newnode;
//	}
//	void Dequeue() {
//		if (front == nullptr) {
//			std::cout << "Queue is empty!" << std::endl;
//			return;
//		}
//		Node* temp = front;
//		front = front->next;
//		if (front == nullptr) {
//			rear = nullptr;
//
//		}
//		delete temp;
//	}
//	int peek() {
//		if (front == nullptr) {
//			std::cout << "Queue is empty!" << std::endl;
//			return 1;
//		}return front->data;
//	}
//	void display() {
//		Node* temp = front;
//		while (temp != nullptr) {
//			std::cout << temp->data << std::endl;
//			temp = temp->next;
//		}
//	}
//};
//int main() {
//	LinkedQueues Q;
//	Q.enqueue(100);
//	Q.enqueue(200);
//	Q.enqueue(300);
//	Q.enqueue(400);
//	Q.enqueue(500);
//	Q.display();
//	Q.peek();
//	std::cout << std::endl;
//	Q.Dequeue();
//	Q.Dequeue();
//	Q.Dequeue();
//	Q.Dequeue();
//	Q.Dequeue();
//	Q.Dequeue();
//	Q.display();
//	Q.peek();
//}

//class Circular_ArrayQueue {
//private:
//	int* arr;
//	int capacity, front, rear;
//public:
//	Circular_ArrayQueue(int value) {
//		capacity = value;
//		arr = new int[capacity];
//		front = -1;
//		rear = -1;
//	}
//	~Circular_ArrayQueue() {
//		delete[] arr;
//	}
//	bool is_empty() {
//		return front == -1;
//	}
//	bool is_full() {
//		return (rear + 1) % capacity == front;
//	}
//	void EnQueue(int value) {
//		if (is_full()) {
//			std::cout << "Queue OverFlow!!" << std::endl;
//			return;
//		}
//		if (is_empty()) {
//			front = 0;
//		}
//		rear = (rear + 1) % capacity;
//		arr[rear] = value;
//	}
//	int DeQueue() {
//		if (is_empty()) {
//			std::cout << "Queue is empty!" << std::endl;
//			return -1;
//		}
//		int deletedElement = arr[front];
//
//		std::cout << "Successfully DeQueued: " << deletedElement << std::endl;
//		if (front == rear) {
//			front= -1;
//			rear= -1;
//		}
//		else {
//			
//			front = (front + 1) % capacity;
//		}
//	}
//	void display() {
//		if (front == -1) {
//			std::cout << "NOTHING TO DISPLAY!" << std::endl;
//			return;
//		}
//		int i = front;
//		do{
//			std::cout << arr[i] << std::endl;
//			i = (i + 1) % capacity;
//		} while (i!=(rear+1)%capacity);
//	}
//	void empty_Q() {
//		front = -1;
//		rear = -1;
//		std::cout << "Queue is emptied" << std::endl;
//	}
//};
//int main() {
//	Circular_ArrayQueue Q(5);
//	Q.EnQueue(100);
//	Q.EnQueue(200);
//	Q.EnQueue(300);
//	Q.EnQueue(400);
//	Q.EnQueue(500);
//	//Q.EnQueue(600);
//	//Q.display();
//	//Q.empty_Q();
//	Q.display();
//	std::cout << std::endl;
//	Q.display();
//	Q.DeQueue();
//	Q.DeQueue();
//	Q.DeQueue();
//	std::cout << std::endl;
//	Q.display();
//
//
//}

class Heap {
private:
	int* arr;
	int capacity;
	int size;
public:
	Heap(int cap) {
		capacity = cap;
		size = 0;
		arr = new int[capacity];
	}
	~Heap() {
		delete[] arr;
	}
	void insert(int value) {
		if (size == capacity) {
			std::cout << "Heap overflow" << std::endl;
			return;
		}
		arr[size] = value;
		int i = size;
		size++;
		while (i > 0 && arr[i] > arr[(i - 1) / 2]) {
			std::swap(arr[i], arr[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}
	void extractMax() {
		if (size == 0) {
			std::cout << "heap empty" << std::endl;
			return;
		}
		arr[0] = arr[size - 1];
		size--;

		int i = 0;
		while (true) {
			int left = 2 * i + 1;
			int right = 2 * i + 2;
			int largest = i;			
			if (left < size && arr[left] > arr[largest]) { // most of the time the size will be greater then left/right! because size increaments as i insert! 
				largest = left;
			}
			if (right < size && arr[right] > arr[largest]) {
				largest = right;
			}
			if (largest == i) {
				break;
			}
			std::swap(arr[i], arr[largest]);
			i = largest;
		}
	}
	void display() {
		for (int i = 0;i < size;i++) {
			std::cout << arr[i]<<" ";
		}
		std::cout << std::endl;
	}
	int getMax() {
		if (size == 0) {
			std::cout << "heap empty" << std::endl;
			return -1;
		}
		std::cout <<arr[0]<<std::endl;
		return 0;
	}
	int getSize() {
		std::cout << size << std::endl;
		return 0;
	}
};
int main() {
	Heap heap(5);
	heap.insert(5);
	heap.insert(10);
	heap.insert(15);
	heap.insert(20);
	heap.insert(25);
	heap.display();
	heap.extractMax();
	heap.display();
	heap.getMax();
	heap.getSize();
}


