#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cmath>
#include "pila.h"
#include "cola.h"
#include "convertirPostFija.h"


class Calculadora {
public:
	Calculadora();
	~Calculadora();
	void setExprecion(Cola*);
	double resultado();

private: 
	double resultado(Cola*);
	std::string unificarSignos(std::string signoActual, std::string signoAnterior);
	bool esOperador(std::string);
	double realizarOperacion(double, double, std::string);
	double convertir(std::string);

	Pila<double> numeros;
	Cola *exprecion;
};

#endif // !CALCULADORA
