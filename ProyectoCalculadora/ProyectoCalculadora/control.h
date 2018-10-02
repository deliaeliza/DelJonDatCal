#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>
#include "calculadora.h"
#include "lista.h"

///<summary>Clase control, que intermedia entre la clase calculadora y la clase interfaz
///Ademas contiene metodos generales.</summary>
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
	void verificarMultiplicacion(std::string& exp);
	static void removerEspacios(std::string&);
	void pasarExpresionLista(std::string, Lista&);
	Calculadora * calculadora; 
};
#endif // !CONTROL_H
