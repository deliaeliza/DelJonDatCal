#include "calculadora.h"

Calculadora::Calculadora() {
	cadenaPostFija = "";
	expresionPostFija = new Cola();
}
Calculadora::~Calculadora() {
	delete expresionPostFija;
}

std::string Calculadora::getCadenaPostFija() {
	return cadenaPostFija;
}

double Calculadora::resultado(Lista l) {
	convertirExpresionPosfija(l);
	Pila<double> numeros = Pila<double>();
	try {
		return resultado(expresionPostFija, numeros);
	}catch(std::string error) {
		throw error;
	}
}

void Calculadora::convertirExpresionPosfija(Lista& l) {
	Pila<char> pila = Pila<char>();
	convertirInterFijaPostFija(pila, l.obtenerInicio());
}


void Calculadora::convertirInterFijaPostFija(Pila<char> pila, Nodo* actual) {
	char elemento;
	if (!actual) { //actual == null
		while (!pila.estaVacia()) {
			elemento = pila.pop();
			expresionPostFija->enqueue(convertirString(elemento));
			cadenaPostFija = cadenaPostFija + elemento + " ";
		}
		return;
	}
	else if (isdigit(actual->valor)) {
		std::string temp;
		temp.append(1, actual->valor);
		actual = actual->next;
		while (actual) { // actual != null
			if (isdigit(actual->valor)) {
				temp.append(1, actual->valor);
				actual = actual->next;
			}
			else {
				actual = actual->prev;
				break;
			}
		}
		expresionPostFija->enqueue(temp);
		cadenaPostFija = cadenaPostFija + temp + " ";
		temp = "";
	}
	else if (actual->valor == '(') {
		pila.push(actual->valor);
		expresionPostFija->enqueue(convertirString(actual->valor));
		cadenaPostFija = cadenaPostFija + actual->valor + " ";
	}
	else if (actual->valor == ')') {
		char signo;
		while ((signo = pila.peek()) != '(') {
			pila.pop();
			expresionPostFija->enqueue(convertirString(signo));
			cadenaPostFija = cadenaPostFija + signo + " ";
		}
		expresionPostFija->enqueue(convertirString(actual->valor));
		cadenaPostFija = cadenaPostFija + actual->valor + " ";
		pila.pop();
	}
	else {
		if (actual->valor == '-' || actual->valor == '+') {
			if (actual->prev && ( isdigit(actual->prev->valor) || actual->prev->valor == ')')) {
				while (!pila.estaVacia() && precedencia(pila.peek()) >= precedencia(actual->valor)) {
					elemento = pila.pop();
					expresionPostFija->enqueue(convertirString(elemento));
					cadenaPostFija = cadenaPostFija + elemento + " ";
				}
				pila.push(actual->valor);
			}
			if (!actual->prev || actual->prev->valor == '/' || actual->prev->valor == '*' ||
				actual->prev->valor == '(' || actual->prev->valor == '^' || actual->prev->valor == '+' || 
				actual->prev->valor == '-') {
				while (actual->next) {
					if (!isdigit(actual->next->valor) && actual->next->valor != '(') {
						expresionPostFija->enqueue(convertirString(actual->valor));
						cadenaPostFija = cadenaPostFija + actual->valor;
						actual = actual->next;
					}
					else {
						expresionPostFija->enqueue(convertirString(actual->valor));
						cadenaPostFija = cadenaPostFija + actual->valor;
						break;
					}
				}
			 }
		}
		else {
			while (!pila.estaVacia() && precedencia(pila.peek()) >= precedencia(actual->valor)) {
				elemento = pila.pop();
				expresionPostFija->enqueue(convertirString(elemento));
				cadenaPostFija = cadenaPostFija + elemento + " ";
			}
			pila.push(actual->valor);
		}
	}
	if (!actual) {
		while (!pila.estaVacia()) {
			elemento = pila.pop();
			expresionPostFija->enqueue(convertirString(elemento));
			cadenaPostFija = cadenaPostFija + elemento + " ";
		}
		return;
	}
	convertirInterFijaPostFija(pila, actual->next);
}


int Calculadora::precedencia(char c) {
	if (c == '(')
		return 1;
	if (c == '+' || c == '-')
		return 2;
	if (c == '*' || c == '/')
		return 3;
	if (c == '^')
		return 4;
	return -1;
}

std::string Calculadora::convertirString(char c) {
	std::string expresion;
	expresion = expresion + c;
	return expresion;
}

double Calculadora::resultado(Cola* expr, Pila<double> numeros) {
	std::string signo = "";
	while (expr->siguiente() != "") {
		std::string actual = expr->dequeue();
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
			Cola *aux = new Cola();
			Pila<double> auxNumeros = Pila<double>();
			unsigned int contador = 1;
			actual = expr->dequeue();
			double resultadoParentesis = 0;
			while (contador != 0) {
				if (actual == "(") {
					contador++;
				}
				if (actual == ")") {
					contador--;
					if (contador == 0) {
						resultadoParentesis = resultado(aux,auxNumeros);
					}
				}
				else {
					aux->enqueue(actual);
					actual = expr->dequeue();
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

	if (numeros.peek() == -0) {
		return 0;
	}

	return numeros.pop();
}

std::string Calculadora::unificarSignos(std::string signoActual, std::string signoAnterior) {
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

bool Calculadora::esOperador(std::string item) {
	return (item == "+" || item == "-" || item == "*" || item == "/" || item == "^");
}

double Calculadora::realizarOperacion(double der, double izq, std::string operador) {
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
double Calculadora::convertir(std::string numero) {
	return std::stod(numero);
}