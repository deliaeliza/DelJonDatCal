#include <iostream>
#include <string>
#include "convertirPostFija.h"
#include "calcularPostFija.h"

int main() {

	Lista *p = new Lista();;
	p->insertarElemento('4');
	p->insertarElemento('5');
	p->insertarElemento('*');
	p->insertarElemento('4');
	p->insertarElemento('/');
	p->insertarElemento('9');
	p->insertarElemento('5');
	p->insertarElemento('-');
	p->insertarElemento('6');
	p->insertarElemento('3');

	convertirPostFija  c;

	c.convertirExpresionPosfija(p);


	system("pause");
	return 0;
}