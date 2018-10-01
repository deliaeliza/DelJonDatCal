#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <string>
#include "control.h"
#include <iostream>

///<summary>Declaracion de la clase interfaz, que tendra las salidas 
///que necesita el usuario</summary>
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
