#ifndef CALCULARPOSTFIJA_H
#define CALCULARPOSTFIJA_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cmath>
#include "pila.h"
#include "lista.h"

class CalcularPostFija {
public:
	CalcularPostFija(Lista);
	~CalcularPostFija();
	double resultado();
private: 
	bool esOperador(std::string);
	double realizarOperacion(double, double, std::string);
	double convertir(std::string);
	Pila<double> numeros;
	Lista exprecion;
};

#endif // !CALCULARPOSTFIJA_H
