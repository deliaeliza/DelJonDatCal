// lista.h
// Declaración de la clase Lista

#ifndef LISTA_H
#define LISTA_H

#include <iostream>

// Contiene las operaciones de la Lista Enlazada
// Note que el puntero al primer nodo de la lista
// se mantiene oculto al usuario (privado)
class Lista {
public:
	Lista();
	~Lista();
	int insertarElemento(int item);
	int borrarElemento(int item);
	int buscarElemento(int item);
	void mostrarLista();
	void mostrarListaInvertida();
	void borrarLista();
	bool listaVacia();
private:
	struct Nodo {
		int valor;
		Nodo* next;
		Nodo* prev;
	};
	Nodo * inicio;
};

#endif