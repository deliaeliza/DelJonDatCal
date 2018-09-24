#include <iostream>
#include <string>
#include "convertirPostFija.h"
#include "calcularPostFija.h"

int main() {
	/*
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

	c.convertirExpresionPosfija(p);*/

	Cola *c = new Cola();
	c->enqueue("-");
	c->enqueue("+");
	c->enqueue("-");
	c->enqueue("+");
	c->enqueue("-");
	c->enqueue("0");
	c->enqueue("(");
	c->enqueue("-");
	c->enqueue("7");
	c->enqueue("-");
	c->enqueue("+");
	c->enqueue("-");
	c->enqueue("+");
	c->enqueue("-");
	c->enqueue("7");
	c->enqueue("-");
	c->enqueue(")");
	c->enqueue("2");
	c->enqueue("^");
	c->enqueue("+");
	c->enqueue("-");
	c->enqueue("+");
	c->enqueue("5");
	c->enqueue("*");
	c->enqueue("-");

	CalcularPostFija result = CalcularPostFija(c);
	std::cout << result.resultado() << "\n";



	system("pause");
	return 0;
}