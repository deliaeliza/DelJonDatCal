#ifndef CALCULARPOSTFIJA_H
#define CALCULARPOSTFIJA_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cmath>
#include "pila.h"
#include "cola.h"

class CalcularPostFija {
public:
	CalcularPostFija(Cola);
	~CalcularPostFija();
	void setExprecion(Cola);
	double resultado();
private: 
	double resultado(Cola);
	std::string unificarSignos(std::string signoActual, std::string signoAnterior);
	bool esOperador(std::string);
	double realizarOperacion(double, double, std::string);
	double convertir(std::string);

	Pila<double> numeros;
	Cola exprecion;
};

#endif // !CALCULARPOSTFIJA_H
