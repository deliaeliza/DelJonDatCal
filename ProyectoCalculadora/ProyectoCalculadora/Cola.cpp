// cola.cpp
// Implementaci�n de la clase Cola

#include "cola.h"

// Constructor
Cola::Cola() {
	head = nullptr;
	tail = nullptr;
}

// Destructor
Cola::~Cola() {
}

// Inserta un nuevo elemento en la cola si no est� llena
void Cola::enqueue(const int item) {
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
	nuevo->next = nullptr;

	if (estaVacia()) {
		head = nuevo;
		tail = nuevo;
	}
	else {
		tail->next = nuevo;
		tail = nuevo;
	}
}

// Recupera el elemento de la cola si no est� vac�a
int Cola::dequeue() {
	if (estaVacia())
		return -1;

	Nodo* tmp;
	int valor;

	tmp = head;
	valor = head->elemento;

	head = head->next;
	if (head == nullptr)
		tail == nullptr;

	free(tmp);
	tmp = nullptr;
	return valor;
}

// Muestra el siguiente elemento en la cola (pr�ximo en salir)
int Cola::siguiente() {
	if (estaVacia())
		return -1;

	return head->elemento;
}

// Retorna "true" si la cola est� vac�a. "false", en caso contrario
bool Cola::estaVacia() {
	return (head == nullptr);
}