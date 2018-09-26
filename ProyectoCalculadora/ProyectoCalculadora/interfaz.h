#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <string>
#include "control.h"
#include <iostream>

class Interfaz {
public:
	Interfaz();
	~Interfaz();
	void mostrarDatos();
private:
	void armarInicio();
	void calcularExpresion();
	Control *control;
};

#endif // !INTERFAZ_H
