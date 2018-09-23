// lista.h
// Declaración de la clase Lista

#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>

class Lista {
public:
	Lista();
	~Lista();
	bool insertarElemento(std::string item);
	bool borrarElemento(std::string item);
	int buscarElemento(std::string item);
	void mostrarLista();
	void mostrarListaInvertida();
	void borrarLista();
	bool listaVacia();
private:
	struct Nodo {
		std::string valor;
		Nodo* next;
		Nodo* prev;
	};
	Nodo * inicio;
};

#endif