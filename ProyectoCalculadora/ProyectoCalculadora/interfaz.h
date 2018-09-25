#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <string>
#include "control.h"
#include <iostream>

class Interfaz {
public:
	Interfaz();
	~Interfaz();
	void armarCalculadora();
	//std::string pedirExpresionInterfija();
private:
	Control* control;
};

#endif // !INTERFAZ_H
