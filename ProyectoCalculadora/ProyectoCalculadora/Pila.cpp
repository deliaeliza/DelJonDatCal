#include "Pila.h"

Stack::Stack() {
	top = nullptr;
}


Stack::~Stack() {
}

void Stack::push(const char item) {
	Nodo* nuevo;

	try
	{
		nuevo = new Nodo;
	}
	catch (std::bad_alloc exception)
	{
		return;
	}

	nuevo->elemento = item;
	nuevo->next = top;
	top = nuevo;
}

char Stack::pop() {
	if (estaVacia())
		return -1;

	char valor;
	Nodo* tmp;

	valor = top->elemento;
	tmp = top;
	top = top->next;
	delete tmp;
	tmp = nullptr;
	return valor;
}

int Stack::peek() {
	return (!estaVacia() ? top->elemento : -1);
}

bool Stack::estaVacia() {
	return top == nullptr;
}