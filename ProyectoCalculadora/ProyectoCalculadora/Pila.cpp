#include "Pila.h"

Pila::Pila() {
	top = nullptr;
}


Pila::~Pila() {
}

void Pila::push(const std::string item) {
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


std::string Pila::pop() {
	if (estaVacia())
		return "";

	std::string valor;
	Nodo* tmp;
	valor = top->elemento;
	tmp = top;
	top = top->next;
	delete tmp;
	tmp = nullptr;
	return valor;
}

std::string Pila::peek() {
	return (!estaVacia() ? top->elemento : "");
}

bool Pila::estaVacia() {
	return (top == nullptr);
}