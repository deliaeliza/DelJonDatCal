#include "cola.h"

Cola::Cola() {
	head = nullptr;
	tail = nullptr;
}

Cola::~Cola() {
}

void Cola::enqueue(const std::string item) {
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

std::string Cola::dequeue() {
	if (estaVacia())
		return "";
	Nodo* tmp;
	std::string valor;
	tmp = head;
	valor = head->elemento;
	head = head->next;
	if (head == nullptr)
		tail = nullptr;
	delete tmp;
	tmp = nullptr;
	return valor;
}

std::string Cola::siguiente() {
	if (estaVacia())
		return "";
	return head->elemento;
}

bool Cola::estaVacia() {
	return (head == nullptr);
}