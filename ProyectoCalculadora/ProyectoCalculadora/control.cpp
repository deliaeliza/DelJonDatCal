#include "control.h"

bool Control::esValida(std::string expr) {//quitar
	return esValida(0, expr);
}

bool Control::esValida(unsigned int pos, std::string expr) {
	bool hayNumero = false;
	Pila<char> parentesis = Pila<char>();
	while (pos < expr.size()) {
		if (expr[pos] >= '0' && expr[pos] <= '9')
			hayNumero = true;
		if (!esOperador(expr[pos]) && !isdigit(expr[pos]) && expr[pos] != ')' && expr[pos] != '(')
			return false;
		if (pos == expr.size() - 1 && (esOperador(expr[pos]) || expr[pos] == '('))
			return false;
		if ((pos != expr.size() - 1 && esOperador(expr[pos])) &&
			(expr[pos + 1] == '^' || expr[pos + 1] == '*' || expr[pos + 1] == '/' || expr[pos + 1] == ')'))
			return false;
		if (expr[pos] == '(') {
			parentesis.push(expr[pos]);
		}
		if (expr[pos] == ')') {
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

bool Control::esOperador(char item) {
	return (item == '+' || item == '-' || item == '*' || item == '/' || item == '^');
}

void Control::removerEspacios(std::string& exp) {
	for (std::string::size_type i = 0; i < exp.size(); ++i)
		if (isspace(exp[i])) {
			exp.erase(i, 1);
			--i;
		}
}