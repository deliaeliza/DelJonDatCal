#include "control.h"

Control::Control() {
	calculadora = new Calculadora();
}

Control::~Control() {
	delete calculadora;
}

bool Control::esValida(std::string expr) {
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
		pos++;
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

Lista Control::pasarExpresionLista(std::string expresion) {
	Lista expresionEntrefija = Lista();
	for (std::string::size_type i = 0; i < expresion.size(); ++i)
		expresionEntrefija.insertarElemento(expresion[i]);
	return expresionEntrefija;
}

double Control::obtenerResultado(std::string expr) {
	removerEspacios(expr);
	try {
		Lista aux = pasarExpresionLista(expr);
		if (!esValida(expr))
			throw "Error de sintaxis";
		return calculadora->resultado(aux);
	} catch (std::string error) {
		throw error;
	}
}

std::string Control::obtenerPostFija() {
	std::string postfija = calculadora->getCadenaPostFija();
	if (postfija == "")
		throw "Error, no hay expresion";
	return postfija;
}