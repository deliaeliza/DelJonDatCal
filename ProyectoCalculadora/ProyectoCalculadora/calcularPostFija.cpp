#include "calcularPostFija.h"

CalcularPostFija::CalcularPostFija(Lista expr) {
	exprecion = expr;
	numeros =  Pila<double>();
}
double CalcularPostFija::resultado() {
	Nodo* actual = exprecion.obtenerInicio();
	if (!actual)
		return 0;
	while (actual) {
		if (!esOperador(actual->valor)) {
			numeros.push(convertir(actual->valor));
		} else {
			try {
				double der;
				if (!numeros.estaVacia())
					der = numeros.pop();
				else throw "Error matematico";
				if (!numeros.estaVacia())
					numeros.push(realizarOperacion(der, numeros.pop(), actual->valor));
				else throw "Error matematico";
				
			} catch (std::string error) {
				throw(error);
			}
		}
		actual = actual->next;
	}
}


bool CalcularPostFija::esOperador(std::string item) {
	return (item == "+" || item == "-" || item == "*" || item == "/" || item == "^");
}

double CalcularPostFija::realizarOperacion(double der, double izq, std::string operador) {
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
double CalcularPostFija::convertir(std::string numero) {
	try {
		return std::stod(numero);
	} catch (const std::invalid_argument& ia) {
		throw "Error matematico";
	}
		
}