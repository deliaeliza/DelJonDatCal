#include "calcularPostFija.h"

CalcularPostFija::CalcularPostFija(Lista expr) {
	exprecion = expr;
	numeros =  Pila();
}
double CalcularPostFija::resultado() {
	Nodo* actual = exprecion.obtenerInicio();
	if (!actual)
		return 0;
	while (actual) {
		if (!esOperador(actual->valor)) {
			numeros.push(actual->valor);//Llamar al convertir porque la pila almazenara double

		}
		else {

			try {
				double der = convertir(numeros.pop());//No llamar al convertir
				realizarOperacion(convertir(numeros.pop()), der, actual->valor);//No llamar al convertir
			}
			catch (std::string error) {
				throw(error);
			}
		}
		actual = actual->next;
	}
}


bool CalcularPostFija::esOperador(std::string item) {
	return (item == "+" || item == "-" || item == "*" || item == "/" || item == "^");
}

double realizarOperacion(double izq, double der, std::string operador) {
	if (operador == "+")
		return izq + der;
	if (operador == "-")
		return izq - der;
	if (operador == "*")
		return izq * der;
	if (operador == "^")
		return pow(izq, der);
	if (operador == "/" && der != 0)
		return izq / der;
	throw "Error matematico";
}
double convertir(std::string numero) {
	double d;
	try {
		std::istringstream(numero) >> d;
	}
}