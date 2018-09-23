#include "Pila.h"

Pila::Pila() {
	top = nullptr;
}


Pila::~Pila() {
}

void Pila::push(const int item) {
	Nodo* nuevo;

	try {
		nuevo = new Nodo;
	} catch (std::bad_alloc exception) {
		return;
	}

	nuevo->elemento = item;
	nuevo->next = top;
	top = nuevo;
}

int Pila::pop() {
	if (estaVacia())
		return -1;

	int valor;
	Nodo* tmp;

	valor = top->elemento;
	tmp = top;
	top = top->next;
	delete tmp;
	tmp = nullptr;
	return valor;
}

int Pila::peek() {
	return (!estaVacia() ? top->elemento : -1);
}

bool Pila::estaVacia() {
	return (top == nullptr);
}