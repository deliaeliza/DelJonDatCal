#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "convertirPostFija.h"
#include "calcularPostFija.h"

class Calculadora {
public:
	Calculadora();
	~Calculadora();
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

#endif // !CALCULADORA
