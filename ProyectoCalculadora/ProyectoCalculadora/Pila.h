#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack {
public:
	Stack();
	~Stack();

	void push(const char);
	char pop();
	int peek();

private:
	struct Nodo {
		char elemento;
		struct Nodo* next;
	};
	struct Nodo* top;
	bool estaVacia();
};

#endif
