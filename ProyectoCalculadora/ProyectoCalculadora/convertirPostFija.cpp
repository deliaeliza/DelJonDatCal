#include "convertirPostFija.h"

void convertirPostFija::convertirInterFijaPostFija() {
	
	char c;
	int posicion = 0;
	std::string temp;
	Pila pila;
	std::string signoA = "+";
	
	for (std::string::size_type i = 0; i < expresion.size(); i++) {
		if (expresion[i] == '+') {
			signoA = signoMayor(expresion[i],signoA);
			if (isdigit(expresion[i + 1]) && expresion[i + 1] == '(')
				pila.push(signoA);
		}
		else if (expresion[i] == '-') {
			//Casos en el que seria un numero negativo Por ejemplo: -64
			if ((i == 0 && isdigit(expresion[i + 1]) || 
				expresion[i - 1] == '*' || expresion[i -1] == '/')) {
				temp.append(1, expresion[i]);
				for (int j = i + 1; j < expresion.size();j++) {
					if (isdigit(expresion[j]))
						temp.append(1, expresion[j]);
					else
						break;
				}
				pila.push(temp);
			}
			else if (expresion[i + 1] == '(') {

			}

		}
		else if (expresion[i] == '*') {

		}
		else if (expresion[i] == '/') {

		}
		else if (expresion[i] == ')') {

		}
		else if (expresion[i] == '(') {

		}
		else if (expresion[i] == '^') {

		}
		else if (isdigit(expresion[i])) {
			temp.append(1, expresion[i]);
		}


	}
}

void convertirPostFija::setExpresion(std::string nExpresion) {
	expresion = nExpresion;
}

std::string convertirPostFija::getExpresion() {
	return expresion;
}


std::string convertirPostFija::signoMayor(char signoActual, std::string signoAnterior) {
	if (signoAnterior == "+") {
		if (signoActual == '-')
			signoAnterior = "-";
	}
	else if (signoAnterior == "-") {
		if (signoActual == '-')
			signoAnterior = "+";
	}
	return signoAnterior;
}