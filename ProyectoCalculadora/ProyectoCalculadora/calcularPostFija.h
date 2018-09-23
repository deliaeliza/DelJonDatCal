#ifndef CALCULARPOSTFIJA_H
#define CALCULARPOSTFIJA_H

#include <iostream>
#include <string>
#include "pila.h"
#include "lista.h"

class CalcularPostFija {
public:
	CalcularPostFija(Lista);
	double resultado();

private: 
	Pila numeros;
	Lista exprecion;
};

#endif // !CALCULARPOSTFIJA_H
