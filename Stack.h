#ifndef Stack_H
#define Stack_H

#include "SimpleList.h"

template <class T>
class Stack : public SimpleList<T> {
	public:
		Stack(string listName, T type) : SimpleList<T>(listName, type) {};

		void push(T value) {
			this->push_front(value);
		};

		T pop() {
			return this->pop_front();
		};
};

#endif