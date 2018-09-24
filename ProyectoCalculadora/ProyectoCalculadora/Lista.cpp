// listadoble.cpp
// Definición de la clase Lista

#include "lista.h"

Lista::Lista() {
	inicio = nullptr;
}

Lista::~Lista() {
	borrarLista();
}

bool Lista::insertarElemento(char item) {
	Nodo* nuevo;

	try {
		nuevo = new Nodo;
	} catch (std::bad_alloc exception) {
		return false;
	}

	nuevo->valor = item;
	nuevo->next = nullptr;
	nuevo->prev = nullptr;

	if (!inicio)
		inicio = nuevo;
	else {
		Nodo* tmp = inicio;
		while (tmp->next != nullptr)
			tmp = tmp->next;
		tmp->next = nuevo; 
		nuevo->prev = tmp;
	}
	return true;
}

bool Lista::borrarElemento(char item) {
	if (listaVacia())
		return -1;
	Nodo* tmp;
	tmp = inicio;
	if (inicio->valor == item) {
		inicio = inicio->next;
		inicio->prev == nullptr;
		delete tmp;
		return true;
	}

	Nodo* tmp2;
	tmp2 = tmp->next;
	while (tmp2) {
		if (tmp2->valor == item) {
			tmp->next = tmp2->next;
			tmp2->next->prev = tmp;
			delete tmp2;
			return true;
		}
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
	return false;
}

void Lista::mostrarLista() {
	if (listaVacia()) {
		std::cout << std::endl << std::endl << "La lista no tiene elementos..." << std::endl;
	}
	else {
		Nodo* tmp;
		tmp = inicio;
		while (tmp) {
			std::cout << tmp->valor << " ";
			tmp = tmp->next;
		}
	}
	std::cout << std::endl;
}

void Lista::mostrarListaInvertida() {
	if (listaVacia()) {
		std::cout << std::endl << std::endl << "La lista no tiene elementos..." << std::endl;
	} else {
		int i = 1;
		Nodo* tmp;
		tmp = inicio ;
		while (tmp->next) {
			tmp = tmp->next;
			++i;
		}
		while (tmp) {
			std::cout << tmp->valor << " ";
			tmp = tmp->prev;
		}
	}
	std::cout << std::endl;
}

int Lista::buscarElemento(char item) {
	std::size_t i = 0;
	Nodo* tmp;
	tmp = inicio;
	while (tmp) {
		if (tmp->valor == item) {
			return i;
		}
		++i;
		tmp = tmp->next;
	}
	return -1;
}

Nodo* Lista::obtenerInicio() {
	return inicio;
}

void Lista::borrarLista() {
	Nodo* tmp;
	while (inicio) {
		tmp = inicio;
		inicio = inicio->next;
		delete tmp;
	}
}

bool Lista::listaVacia() {
	return (inicio == nullptr);
}