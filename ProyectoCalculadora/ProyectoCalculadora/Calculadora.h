#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cmath>
#include "pila.h"
#include "cola.h"
#include "lista.h"

class Calculadora {
public:
	Calculadora(Lista*);
	~Calculadora();
	void setExprecion(Cola*);
	void imprimirCola();
	double resultado();
	void convertirExpresionPosfija();

private: 

	int precedencia(char);
	std::string convertirString(char);
	void convertirInterFijaPostFija(Pila<char>, std::string, Nodo*);

	double resultado(Cola*, Pila<double>);
	std::string unificarSignos(std::string signoActual, std::string signoAnterior);
	bool esOperador(std::string);
	double realizarOperacion(double, double, std::string);
	double convertir(std::string);

	Cola* expresionPostFija;
	Lista *expresionEntreFija;
	std::string cadenaPostFija;
};

#endif // !CALCULADORA
