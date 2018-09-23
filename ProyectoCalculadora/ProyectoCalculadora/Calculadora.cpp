#include "calculadora.h"

Calculadora::Calculadora() {
}
Calculadora::~Calculadora() {
}

bool Calculadora::esValida(std::string expr) {
	return esValida(0, expr);
}

unsigned int Calculadora::esValida(unsigned int pos, std::string expr) {
	bool hayNumero = false;
	char actual;
	Pila<char> parentesis = Pila<char>();
	while (pos < expr.size()) {
		actual = expr[pos];
		if (actual >= '0' && actual <= '9')
			hayNumero = true;
		if (!esOperador(actual) && !isdigit(actual) && actual != ')' && actual != '(')
			return false;
		if (pos == expr.size() - 1 && (esOperador(actual) || actual == '('))
			return false;
		if ((pos != expr.size()-1 && esOperador(actual)) &&
			(expr[pos + 1] == '^' || expr[pos + 1] == '*' || expr[pos + 1] == '/' || expr[pos + 1] == ')'))
			return false;
		if (actual == '(') {//Si la pila esta vacia, hayNumero para a false;
			parentesis.push(actual);
		}
		if (actual == ')') {
			if (parentesis.estaVacia() || !hayNumero)
				return false;
			parentesis.pop();
			if (parentesis.estaVacia())
				hayNumero = false;
		}
		
	}
	if (!parentesis.estaVacia())
		return false;
	return true;
}

bool Calculadora::esOperador(char item) {
	return (item == '+' || item == '-' || item == '*' || item == '/' || item == '^');
}