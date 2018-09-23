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
		if (expr[pos] == '(') {//Si la pila esta vacia, hayNumero para a false;
 			
				
		}
		
	}
}

bool Calculadora::esOperador(char item) {
	return (item == '+' || item == '-' || item == '*' || item == '/' || item == '^');
}