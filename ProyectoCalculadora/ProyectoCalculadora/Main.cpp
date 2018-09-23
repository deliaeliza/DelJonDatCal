#include <iostream>
#include <string>
#include "Pila.h"

int main() {

	Pila<int> pilaNumeros;

	pilaNumeros.push(1);
	pilaNumeros.push(2);
	pilaNumeros.push(3);
	pilaNumeros.push(4);
	pilaNumeros.push(5);

	while (!pilaNumeros.estaVacia()) {
		std::cout <<  pilaNumeros.pop();
	}

	
	std::cout << "\n\n\n";

	Pila<std::string> pilaString;

	pilaString.push("B");
	pilaString.push("E");
	pilaString.push("L");
	pilaString.push("L");
	pilaString.push("O");

	while (!pilaString.estaVacia()) {
		std::cout << pilaString.pop() + " ";
	}


	system("pause");
	return 0;
}