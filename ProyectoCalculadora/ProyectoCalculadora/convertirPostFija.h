#ifndef CONVERTIRPOSTFIJA_H
#define CONVERTIRPOSTFIJA_H

#include "Cola.h"
#include "Pila.h"
#include <iostream>

class convertirPostFija {
public:
	void convertirInterFijaPostFija();
	void setExpresion(std::string);
	std::string getExpresion();

private:
	std::string expresion;
};

#endif // !CONVERTIRPOSTFIJA