#ifndef Queue_H
#define Queue_H

#include "SimpleList.h"

template <class T>
class Queue : public SimpleList<T> {
	public:
		Queue(string listName, T type) : SimpleList<T>(listName, type) {};

		void push(T value) {
			this->push_back(value);
		};

		T pop() {
			return this->pop_front();
		};
};
#endif