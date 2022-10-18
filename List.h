
#ifndef LIST
#define LIST

#include <iostream>
using namespace std;

template <typename T>
class List {
private:
	//Node Class
	class Node {
	public:
		T data;
		Node* prev;
		Node* next;

		Node(T data, Node* prev, Node* next = nullptr) {
			this->data = data;
			this->prev = prev;
			this->next = next;
		}
	};

	//Helper Attributes
	Node* head;
	Node* tail;
	Node* viewNext;
	Node* viewPrev;
	class error {};
	int len;

public:
	//Constructor and Destructor
	List(){
		head = nullptr;
		tail = head;
		viewNext = head;
		viewPrev = tail;
		len = 0;
	}
	~List(){
		Node* remov;
		Node* temp = head;

		while (temp != nullptr){
			remov = temp;
			temp = temp->next;
			delete remov;
		}
	}

	//Utility methods
	bool isInList(T trgt){
		Node* temp = head;
		while (temp != nullptr && temp->data != trgt){
			temp = temp->next;
		}

		return (temp != nullptr) && (temp->data == trgt);
	}
	bool isEmpty() {
		return len == 0;
	}
	int size() {
		return len;
	}
	T* seeNext(){
		if (isEmpty()) throw error();
		
		T* retVal;
		if (viewNext != nullptr){
			retVal = new T[1]{viewNext->data};
			viewNext = viewNext->next;
		}
		else retVal = nullptr;
		
		return retVal;
	}
	T* seePrev(){
		if (isEmpty()) throw error();
		
		T* retVal;
		if (viewPrev != nullptr){
			retVal = new T[1]{viewPrev->data};
			viewPrev = viewPrev->prev;
		}
		else retVal = nullptr;
		
		return retVal;
	}
	T* seeAt(int idx){
		//NOTE: T* is used to keep things consistent
		if (isEmpty()) throw error();
		if (idx >= len) throw error();

		int n = 0;
		Node* temp = head;
		while (n != idx){
			temp = temp->next;
			n += 1;
		}

		viewNext = temp;
		T* retVal = new T[1]{temp->data};
		return retVal;
	}
	void reset(){
		viewNext = head;
		viewPrev = tail;
	}

	//For debugging
	void display() {
		Node* temp = head;
		cout << "List: ";
		while (temp != nullptr) {
			cout << temp->data << ' ' << endl;
			temp = temp->next;
		}
		cout << endl;
	}

	//Node insertion
	void addItem(T val) {
		//Add to a non-empty List
		if (head != nullptr) {
			//Locate insertion position
			Node* temp = head;
			while (temp != nullptr && temp->data < val){
				temp = temp->next;
			}

			//Insert at head
			if (temp == head){
				if (viewNext == head){
					head->prev = new Node(val, nullptr, head);
					head = head->prev;
					viewNext = head;
				}
				else{
					head->prev = new Node(val, nullptr, head);
					head = head->prev;
				}
			}

			//Insert elsewhere
			else if (temp != nullptr){
				if (viewNext == temp){
					temp->prev->next = new Node(val, temp->prev, temp);
					temp->prev = temp->prev->next;
					viewNext = temp->prev;
				}
				else{
					temp->prev->next = new Node(val, temp->prev, temp);
					temp->prev = temp->prev->next;
				}
			}

			//Insert at tail
			else{
				if (viewPrev == tail){
					tail->next = new Node(val, tail);
					tail = tail->next;
					viewPrev = tail;
				}
				else{
					tail->next = new Node(val, tail);
					tail = tail->next;
				}
			}
		}

		//Add to empty list
		else {
			head = new Node(val, nullptr);
			tail = head;
			viewNext = head;
			viewPrev = tail;
		}

		//Update len
		len += 1;
	}

	//Node removal
	T* getItem(T trgt) {
		//Find trgt
		Node* temp = head;
		while (temp != nullptr && temp->data != trgt){
			temp = temp->next;
		}

		//Not found
		if (temp == nullptr) return nullptr;

		//Remove from head
		if (temp == head){
			if (viewNext == head && viewPrev == head){
				head = head->next;
				viewNext = head;
				viewPrev = nullptr;
			}
			else if (viewNext == head){
				head = head->next;
				viewNext = head;
			}
			else if (viewPrev == head){
				head = head->next;
				viewPrev = nullptr;
			}
			else head->next;
		}

		//Remove from tail
		else if (temp == tail){
			if (viewNext == tail && viewPrev == tail){
				tail = tail->prev;
				viewNext = nullptr;
				viewPrev = tail;
			}
			else if (viewNext == tail){
				tail = tail->prev;
				viewNext = nullptr;
			}
			else if (viewPrev == tail){
				tail = tail->prev;
				viewPrev = tail;
			}
			else tail = tail->prev;
			tail->next = nullptr;
		}

		//Remove from elsewhere
		else{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			if (viewNext == temp && viewPrev == temp){
				viewNext = temp->next;
				viewPrev = temp->prev;
			}
			else if (viewNext == temp) viewNext = temp->next;
			else if (viewPrev == temp) viewPrev = temp->prev;
		}

		//Final operations
		T* retVal = new T[1]{temp->data};
		len -= 1;
		delete temp;
		return retVal;
	}

	//Overloaded operators
	bool operator == (const List& right){
		//Length Handling
		if (this->len != right->len) return false;

		//Comparisons
		else{
			Node* L = this->head;
			Node* R = right->head;
			
			while (L != nullptr){
				if (L->data != R->data) return false;
				L = L->next;
				R = R->next;
			}
		}

		return true;
	}
	bool operator < (const List& right){
		//Length Handling
		if (this->len < right->len) return true;
		else if (this->len > right->len) return false;

		//Comparisons
		else {
			Node* L = this->head;
			Node* R = right->head;

			while (L != nullptr){
				if (L->data > R->data) return false;
				else if (L->data < R->data) return true;
			}
		}

		return false; 
	}
	bool operator > (const List& right){
		//Length Handling
		if (this->len > right->len) return true;
		else if (this->len < right->len) return false;

		//Comparisons
		else {
			Node* L = this->head;
			Node* R = right->head;

			while (L != nullptr){
				if (L->data < R->data) return false;
				else if (L->data > R->data) return true;
			}
		}

		return false; 
	}
};

#endif
