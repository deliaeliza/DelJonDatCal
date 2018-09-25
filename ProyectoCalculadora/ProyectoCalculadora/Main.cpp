#include <iostream>
#include <string>
#include "interfaz.h"
#include "control.h"


int main() {
	/*
	Lista *p = new Lista();
	*/
	/*
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
	*/
	/*
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
	*/
	/*
	p->insertarElemento('3');
	p->insertarElemento('4');
	p->insertarElemento('-');
	p->insertarElemento('2');
	p->insertarElemento('3');
	p->insertarElemento('4');
	*/
	/*
	p->insertarElemento('2');
	p->insertarElemento('8');
	p->insertarElemento('/');
	p->insertarElemento('7');
	*/
	/*
	p->insertarElemento('3');
	p->insertarElemento('1');
	p->insertarElemento('*');
	p->insertarElemento('2');
	p->insertarElemento('3');
	*/
	/*
	p->insertarElemento('-');
	p->insertarElemento('3');
	p->insertarElemento('+');
	p->insertarElemento('-');
	p->insertarElemento('5');
	*/
	/*
	p->insertarElemento('7');
	p->insertarElemento('*');
	p->insertarElemento('-');
	p->insertarElemento('3');
	*/
	/*
	p->insertarElemento('-');
	p->insertarElemento('8');
	p->insertarElemento('/');
	p->insertarElemento('-');
	p->insertarElemento('4');
	*/
	/*
	p->insertarElemento('(');
	p->insertarElemento('3');
	p->insertarElemento('4');
	p->insertarElemento('-');
	p->insertarElemento('2');
	p->insertarElemento(')');
	p->insertarElemento('+');
	p->insertarElemento('(');
	p->insertarElemento('2');
	p->insertarElemento('1');
	p->insertarElemento('/');
	p->insertarElemento('-');
	p->insertarElemento('7');
	p->insertarElemento(')');
	*/
	/*
	p->insertarElemento('-');
	p->insertarElemento('(');
	p->insertarElemento('4');
	p->insertarElemento('2');
	p->insertarElemento('/');
	p->insertarElemento('6');
	p->insertarElemento(')');
	p->insertarElemento('-');
	p->insertarElemento('+');
	p->insertarElemento('-');
	p->insertarElemento('3');
	p->insertarElemento('*');
	p->insertarElemento('4');
	*/
	/*
	p->insertarElemento('-');
	p->insertarElemento('1');
	p->insertarElemento('5');
	p->insertarElemento('+');
	p->insertarElemento('3');
	p->insertarElemento('*');
	p->insertarElemento('-');
	p->insertarElemento('+');
	p->insertarElemento('(');
	p->insertarElemento('9');
	p->insertarElemento('*');
	p->insertarElemento('4');
	p->insertarElemento(')');
	*/
	/*
	p->insertarElemento('(');
	p->insertarElemento('-');
	p->insertarElemento('-');
	p->insertarElemento('-');
	p->insertarElemento('8');
	p->insertarElemento(')');
	p->insertarElemento('^');
	p->insertarElemento('2');
	p->insertarElemento('+');
	p->insertarElemento('(');
	p->insertarElemento('-');
	p->insertarElemento('3');
	p->insertarElemento(')');
	p->insertarElemento('^');
	p->insertarElemento('(');
	p->insertarElemento('-');
	p->insertarElemento('3');
	p->insertarElemento('-');
	p->insertarElemento('8');
	p->insertarElemento(')');
	*/

	//Calculadora c = Calculadora(p);

	//c.convertirExpresionPosfija();

	//c.imprimirCola();
	//std::cout << "Expresion PostFija: \n" << c.getCadenaPostFija() << "\n\n";

	//Interfaz inter = Interfaz();
	//inter.armarCalculadora();

	Control c = Control();
	std::string expresion = "(--8*(67+9))^(2) + (-3)^3";

	if (c.esValida(expresion)) {
		std::cout << "La expresion es valida\n";
	}
	else {
		std::cout << "La expresion no es valida\n";
	}

	system("pause");
	return 0;
}