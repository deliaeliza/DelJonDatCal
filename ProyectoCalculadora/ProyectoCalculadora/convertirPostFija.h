#ifndef CONVERTIRPOSTFIJA_H
#define CONVERTIRPOSTFIJA_H

#include "Cola.h"
#include "Lista.h"
#include "Pila.h"
#include "calculadora.h"
#include <iostream>

class convertirPostFija {
public:
	convertirPostFija();
	void convertirExpresionPosfija(Lista*);
	void convertirInterFijaPostFija(Pila<char>,std::string, Nodo*);
	std::string convertirString(char);
	char signoMayor(char, char);
	void setExpresion(Lista);
	Lista getExpresion();

	Cola getExpresionPostFija();
	
	int precedencia(char);
	~convertirPostFija();
private:
	Lista expresion;
	Cola expresionPostFija;
};

#endif // !CONVERTIRPOSTFIJA