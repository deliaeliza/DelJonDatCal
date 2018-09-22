#ifndef CALCULARPOSTFIJA_H;
#define CALCULARPOSTFIJA_H;

#include <iostream>
#include <string>
#include <cstdlib>
#include "pila.h"

class CalcularPostFija {
public:
	CalcularPostFija(std::string);
	double resultado();
private:
	std::string exprecion;
	Pila numeros;
};
#endif // !CALCULARPOSTFIJA