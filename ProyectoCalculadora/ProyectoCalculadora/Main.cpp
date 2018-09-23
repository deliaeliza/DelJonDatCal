#include <iostream>
#include <string>
#include "convertirPostFija.h"

int main() {

	Lista p;
	p.insertarElemento('4');
	p.insertarElemento('5');
	p.insertarElemento('*');
	p.insertarElemento('4');
	p.insertarElemento('/');
	p.insertarElemento('9');
	p.insertarElemento('5');
	p.insertarElemento('-');
	p.insertarElemento('6');
	p.insertarElemento('3');
	/*p.insertarElemento();
	p.insertarElemento();
	p.insertarElemento();
	p.insertarElemento();
	p.insertarElemento();
	p.insertarElemento();
	p.insertarElemento();*/

	convertirPostFija  c = convertirPostFija(p);

	c.convertirExpresionPosfija();

	while (c.getExpresionPostFija().siguiente() != "") {
		std::cout << c.getExpresionPostFija().dequeue() << " ";
	}

	system("pause");
	return 0;
}