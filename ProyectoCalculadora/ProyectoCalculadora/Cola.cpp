#include "cola.h"

Cola::Cola() {
	head = nullptr;
	tail = nullptr;
}

Cola::~Cola() {
}

void Cola::enqueue(const int item) {
	Nodo* nuevo;
	try {
		nuevo = new Nodo;
	} catch (std::bad_alloc exception) {
		return;
	}
	nuevo->elemento = item;
	nuevo->next = nullptr;
	if (estaVacia()) {
		head = nuevo;
		tail = nuevo;
	} else {
		tail->next = nuevo;
		tail = nuevo;
	}
}

int Cola::dequeue() {
	if (estaVacia())
		return -1;
	Nodo* tmp;
	int valor;
	tmp = head;
	valor = head->elemento;
	head = head->next;
	if (head == nullptr)
		tail = nullptr;
	delete tmp;
	return valor;
}

int Cola::siguiente() {
	if (estaVacia())
		return -1;
	return head->elemento;
}

bool Cola::estaVacia() {
	return (head == nullptr);
}