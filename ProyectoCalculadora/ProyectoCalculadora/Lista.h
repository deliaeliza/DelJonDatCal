// lista.h
// Declaración de la clase Lista

#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>

struct Nodo {
	char valor;
	Nodo* next;
	Nodo* prev;
};

class Lista {
public:
	Lista();
	~Lista();
	bool insertarElemento(char);
	bool borrarElemento(char);
	int buscarElemento(char);
	Nodo* obtenerInicio();
	void mostrarLista();
	void mostrarListaInvertida();
	void borrarLista();
	bool listaVacia();
private:
	Nodo * inicio;
};

#endif