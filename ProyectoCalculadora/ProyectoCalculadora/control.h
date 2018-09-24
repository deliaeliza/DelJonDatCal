#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>
#include "calculadora.h"
#include "lista.h"

class Control {
public:
	double obtenerResultado(std::string);
	std::string obtenerPostFija();
	bool esValida(std::string);
	static bool esOperador(char);
	static void removerEspacios(std::string&);
private:
	bool esValida(unsigned int, std::string);
};
#endif // !CONTROL_H
