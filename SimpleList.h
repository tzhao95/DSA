//Tony Zhao
//DSA Midterm Project

#ifndef SimpleList_H
#define SimpleList_H
#include <string>
using namespace std;

template <class T>
class SimpleList {
	private:
		string name;
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

		virtual void push(T value) {};
		virtual T pop() {};

		string getName() {
			return name;
		};

		bool empty() {
			if(head->next == tail) {
				return true;
			}
			return false;
		};

	protected:
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
