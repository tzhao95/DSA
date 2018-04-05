//Tony Zhao
//DSA Programming Project 1

#ifndef Stack_H
#define Stack_H

#include "SimpleList.h"

//Stack class using SimpleList----LIFO
template <class T>
class Stack : public SimpleList<T> {
	public:
		Stack(string listName, T type) : SimpleList<T>(listName, type) {};

		//Add node to top of stack
		void push(T value) {
			this->push_front(value);
		};

		//Remove node from top of stack
		T pop() {
			return this->pop_front();
		};
};

#endif