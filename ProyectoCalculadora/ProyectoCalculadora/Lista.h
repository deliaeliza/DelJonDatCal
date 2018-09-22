// lista.h
// Declaración de la clase Lista

#ifndef LISTA_H
#define LISTA_H

#include <iostream>

// Estructura que contiene los datos de cada nodo de la lista
// En este caso se implementa una lista de enteros
struct Nodo {
	int valor;
	Nodo* next;
	Nodo* prev;
};

// Contiene las operaciones de la Lista Enlazada
// Note que el puntero al primer nodo de la lista
// se mantiene oculto al usuario (privado)
class ListaDoble {
public:
	ListaDoble();
	~ListaDoble();
	int insertarElemento(int item);
	int borrarElemento(int item);
	int buscarElemento(int item);
	void mostrarLista();
	void mostrarListaInvertida();
	void borrarLista();
	bool listaVacia();
private:
	Nodo * inicio;
};

#endif