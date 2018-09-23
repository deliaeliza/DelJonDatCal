// cola.h
// Declaración de la clase Cola

#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <string>

class Cola {
public:
	Cola();
	~Cola();
	void enqueue(const std::string);
	std::string dequeue();
	std::string siguiente();
private:
	struct Nodo {
		std::string elemento;
		struct Nodo* next;
	};
	Nodo * head; //salida
	Nodo* tail;  //entrada
	bool estaVacia();
};

#endif