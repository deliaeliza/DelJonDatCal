#ifndef CALCULARPOSTFIJA_H
#define CALCULARPOSTFIJA_H

#include <iostream>
#include <string>
#include "pila.h"

class CalcularPostFija {
public:
	CalcularPostFija();


private: 
	Pila numeros;
	Lista exprecion;
};

#endif // !CALCULARPOSTFIJA_H
