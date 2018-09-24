#include <iostream>
#include <string>
#include "calculadora.h"
#include "lista.h"


int main() {
	
	Lista *p = new Lista();
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

	Calculadora c = Calculadora(p);

	c.convertirExpresionPosfija();

	c.imprimirCola();

	system("pause");
	return 0;
}