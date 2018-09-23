#include "calculadora.h"

Calculadora::Calculadora() {
}
Calculadora::~Calculadora() {
}

bool Calculadora::esValida(std::string expr) {
	return esValida(0, expr);
}

unsigned int Calculadora::esValida(unsigned int pos, std::string expr) {
	bool operCorrecto = false;
	bool parCorrecto = false;
	bool hayNumeros = false;
	while (pos < expr.size()) {
			if (pos == expr.size() - 1 && (esOperador(expr[pos]) || expr[pos] == '('))
				return false;
			if (pos != expr.size() - 1) {
				if ((esOperador(expr[pos])) &&
					(expr[pos + 1] == '^' || expr[pos + 1] == '*' || expr[pos + 1] == '/' || expr[pos + 1] == ')'))
					return false;
			}
		if (expr[pos] == '(') {
			++pos;
			while (expr[pos] != ')') {
				if (expr[pos] == '(')
					pos = esValida(++pos, expr);


				if (hayNumeros && parCorrecto)
					return true;
			}
		}
		
	}
}

bool Calculadora::esOperador(char item) {
	return (item == '+' || item == '-' || item == '*' || item == '/' || item == '^');
}