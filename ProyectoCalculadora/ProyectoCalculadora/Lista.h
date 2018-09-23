// lista.h
// Declaración de la clase Lista

#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>

struct Nodo {
	std::string valor;
	Nodo* next;
	Nodo* prev;
};

class Lista {
public:
	Lista();
	~Lista();
	bool insertarElemento(std::string item);
	bool borrarElemento(std::string item);
	int buscarElemento(std::string item);
	Nodo* obtenerInicio();
	void mostrarLista();
	void mostrarListaInvertida();
	void borrarLista();
	bool listaVacia();
private:
	Nodo * inicio;
};

#endif