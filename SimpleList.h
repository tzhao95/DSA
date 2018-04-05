//Tony Zhao
//DSA Programming Project 1

#ifndef SimpleList_H
#define SimpleList_H
#include <string>
using namespace std;

//Abstract template class for Stack and Queue
template <class T>
class SimpleList {
	private:
		string name;
		//Private class Node: stores the Node value("data") and a pointer to the next node in list
		class Node {
		public:
			T data; 
			Node *next; 
			Node(Node *nextNode, T value) : data(value), next(nextNode) {};
		};

	public:
		Node *head;
		Node *tail;
		SimpleList(string listName, T type) : name(listName) {
			tail = new Node(NULL, type); 
			head = new Node(tail, type);
		};

		Node *start = NULL;
		Node *end = NULL;

		//Adds a node with the value to list
		virtual void push(T value) {};
		//Removed the first node from list and returns value of node
		virtual T pop() {};

		//Returns the name of the SimpleList
		string getName() {
			return name;
		};

		//Returns true if the List is empty
		bool empty() {
			if(head->next == tail) {
				return true;
			}
			return false;
		};

	protected:
		//adds a node to top of list
		void push_front(T value) {
			if(empty()) {
				Node *item = new Node(tail, value);
				head->next = item;
				start = item;
				end = item;
			}
			else {
				Node *item = new Node(start, value);
				head->next = item;
				start = item;
			}
		};

		//adds a node to back of list
		void push_back(T value) {
			Node *item = new Node(tail, value);
			if(empty()) {
				head->next = item;
				start = item;
				end = item;
			}
			else {
				end->next = item;
			}
		};

		//removed the first node from list
		T pop_front() {
			Node *first = start;
			T first_value = start->data;
			head->next = start->next;
			start = head->next;
			delete first;
			return first_value;
		};
};
#endif
