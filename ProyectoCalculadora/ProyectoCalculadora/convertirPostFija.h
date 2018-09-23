#ifndef CONVERTIRPOSTFIJA_H
#define CONVERTIRPOSTFIJA_H

#include "Lista.h"
#include "Pila.h"
#include "calculadora.h"
#include <iostream>

class convertirPostFija {
public:
	convertirPostFija(std::string);
	void convertirExpresionPosfija();
	void convertirInterFijaPostFija(Pila<char>,std::string, int, char, int);
	char signoMayor(char, char);
	void setExpresion(std::string);
	std::string getExpresion();

	Lista getExpresionPostFija();
	
	int precedencia(char);
	~convertirPostFija();
private:
	std::string expresion;
	Lista expresionPostFija;
};

#endif // !CONVERTIRPOSTFIJA