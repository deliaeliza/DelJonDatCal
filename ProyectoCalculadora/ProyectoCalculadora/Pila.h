#ifndef PILA_H
#define PILA_H

#include <iostream>

class Pila {
public:
	Pila();
	~Pila();

	void push(const int);
	int pop();
	int peek();

private:
	struct Nodo {
		int elemento;
		struct Nodo* next;
	};
	struct Nodo* top;
	bool estaVacia();
};

#endif
