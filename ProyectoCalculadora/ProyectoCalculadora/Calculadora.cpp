#include "calculadora.h"

Calculadora::Calculadora() {
}
Calculadora::~Calculadora() {
}

#include "calcularPostFija.h"

CalcularPostFija::CalcularPostFija(Cola exprecion) {
	this->exprecion = exprecion;
	numeros = Pila<double>();
}
CalcularPostFija::~CalcularPostFija() {

}

void CalcularPostFija::setExprecion(Cola exprecion) {
	this->exprecion = exprecion;
}

/*double CalcularPostFija::resultado() {
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
}*/

double CalcularPostFija::resultado(Cola expr) {
	std::string signo = "";
	while (expr.siguiente() != "") {
		std::string actual = expr.dequeue();
		if (esOperador(actual)) {//Si hay dos numeros en pila, es operacion, si hay solo uno, el signo es del siguiente numero
			if (!numeros.estaVacia()) {
				double num = numeros.pop();
				if (!numeros.estaVacia()) {
					try {
						numeros.push(realizarOperacion(num, numeros.pop(), actual));
						//signo = "";
					}
					catch (std::string error) {
						throw error;
					}
				}
				else {
					numeros.push(num); //Devuelve el numero porque no hay sufiecientes para realizar una operacion
					signo = ((signo == "") ? actual : unificarSignos(actual, signo));
				}
			}
			else
				signo = ((signo == "") ? actual : unificarSignos(actual, signo));
		}
		else  if (actual == "(") {
			Cola aux = Cola();
			unsigned int contador = 1;
			actual = expr.dequeue();
			double resultadoParentesis = 0;
			while (actual != ")" && contador != 0) {
				if (actual == "(") {
					contador++;
				}
				if (actual == ")") {
					contador--;
					if (contador == 0) {
						resultadoParentesis = resultado(aux);
					}
				}
				else {
					aux.enqueue(actual);
					actual = expr.dequeue();
				}
			}
			if (signo == "-")
				resultadoParentesis *= -1;
			numeros.push(resultadoParentesis);
			signo = "";
		}
		else { //Es numero. No se verifica ")", se supone que es sintacticamente correcta
			numeros.push(convertir(signo + actual));
			signo = "";
		}
	}
	return numeros.pop();
}

std::string CalcularPostFija::unificarSignos(std::string signoActual, std::string signoAnterior) {
	if (signoAnterior == "+") {
		if (signoActual == "-")
			signoAnterior = "-";
	}
	else if (signoAnterior == "-") {
		if (signoActual == "-")
			signoAnterior = "+";
	}
	return signoAnterior;
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
	//try {
	return std::stod(numero);
	/*} catch (const std::invalid_argument& ia) {
	throw "Error matematico";
	}*/

}