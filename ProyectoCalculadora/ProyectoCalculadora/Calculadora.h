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
	void setExpresion(Cola*);
	std::string getCadenaPostFija();
	void imprimirCola();
	double resultado();

private: 
	int precedencia(char);
	std::string convertirString(char);
	void convertirExpresionPosfija();
	void convertirInterFijaPostFija(Pila<char>, Nodo*);

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
