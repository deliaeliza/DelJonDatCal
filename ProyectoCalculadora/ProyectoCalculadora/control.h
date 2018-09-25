#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>
#include "calculadora.h"
#include "lista.h"

class Control {
public:
	Control();
	~Control();
	double obtenerResultado(std::string);
	std::string obtenerPostFija();
	bool esValida(std::string);
private:
	static bool esOperador(char);
	bool esValida(unsigned int, std::string);
	static void removerEspacios(std::string&);
	Lista pasarExpresionLista(std::string);
	Calculadora * calculadora; 
};
#endif // !CONTROL_H
