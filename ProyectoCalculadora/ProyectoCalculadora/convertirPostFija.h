#ifndef CONVERTIRPOSTFIJA_H
#define CONVERTIRPOSTFIJA_H

#include "Lista.h"
#include "Pila.h"
#include <iostream>

class convertirPostFija {
public:
	convertirPostFija();
	void convertirExpresionPosfija();
	void convertirInterFijaPostFija(Pila<std::string>,std::string, int, std::string);
	std::string signoMayor(char, std::string);
	void setExpresion(std::string);
	std::string getExpresion();
	~convertirPostFija();
private:
	std::string expresion;
	Lista expresionPostFija;
};

#endif // !CONVERTIRPOSTFIJA