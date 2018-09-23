#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

class Pila {
public:
	Pila();
	~Pila();

	void push(const std::string);
	std::string pop();
	std::string peek();

private:
	struct Nodo {
		std::string elemento;
		struct Nodo* next;
	};
	struct Nodo* top;
	bool estaVacia();
};

#endif
