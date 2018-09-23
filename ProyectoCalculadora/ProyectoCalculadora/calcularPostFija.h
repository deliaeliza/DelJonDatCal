#ifndef CALCULARPOSTFIJA_H
#define CALCULARPOSTFIJA_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "pila.h"
#include "lista.h"

class CalcularPostFija {
public:
	CalcularPostFija(Lista);
	double resultado();

private: 
	bool esOperador(std::string);
	double realizarOperacion(double, double, std::string);
	double convertir(std::string);
	Pila numeros;
	Lista exprecion;
};

#endif // !CALCULARPOSTFIJA_H
