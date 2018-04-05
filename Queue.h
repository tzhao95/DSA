//Tony Zhao
//DSA Programming Project 1

#ifndef Queue_H
#define Queue_H

#include "SimpleList.h"

//Queue class using SimpleList----FIFO
template <class T>
class Queue : public SimpleList<T> {
	public:
		Queue(string listName, T type) : SimpleList<T>(listName, type) {};

		//Add node to the end of queue
		void push(T value) {
			this->push_back(value);
		};

		//Remove top node
		T pop() {
			return this->pop_front();
		};
};
#endif