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
	Calculadora();
	~Calculadora();
	std::string getCadenaPostFija();
	double resultado(Lista&);
private: 
	int precedencia(char);
	std::string convertirString(char);
	void convertirExpresionPosfija(Lista&);
	void convertirInterFijaPostFija(Pila<char>, Nodo*);

	double resultado(Cola*, Pila<double>);
	std::string unificarSignos(std::string signoActual, std::string signoAnterior);
	bool esOperador(std::string);
	double realizarOperacion(double, double, std::string);
	double convertir(std::string);

	Cola* expresionPostFija;
	std::string cadenaPostFija;
};

#endif // !CALCULADORA
