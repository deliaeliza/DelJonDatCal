#include <iostream>
#include <string>
#include "convertirPostFija.h"

int main() {
	
	Lista *p = new Lista();;
	p->insertarElemento('-');
	p->insertarElemento('+');
	p->insertarElemento('-');
	p->insertarElemento('+');
	p->insertarElemento('-');
	p->insertarElemento('0');
	p->insertarElemento('-');
	p->insertarElemento('(');
	p->insertarElemento('-');
	p->insertarElemento('7');
	p->insertarElemento('-');
	p->insertarElemento('-');
	p->insertarElemento('+');
	p->insertarElemento('-');
	p->insertarElemento('+');
	p->insertarElemento('-');
	p->insertarElemento('7');
	p->insertarElemento(')');
	p->insertarElemento('^');
	p->insertarElemento('2');
	p->insertarElemento('*');
	p->insertarElemento('+');
	p->insertarElemento('-');
	p->insertarElemento('+');
	p->insertarElemento('5');

	convertirPostFija  c;

	c.convertirExpresionPosfija(p);


	system("pause");
	return 0;
}