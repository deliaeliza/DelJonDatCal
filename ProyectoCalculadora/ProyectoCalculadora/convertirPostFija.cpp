#include "convertirPostFija.h"
/*
void convertirPostFija::convertirInterFijaPostFija() {
	
	char c;
	int posicion = 0;
	std::string temp;
	Pila pila;
	std::string signoA = "+";
	
	for (std::string::size_type i = 0; i < expresion.size(); i++) {
		if (expresion[i] == '(') {

		}
		else if (expresion[i] == ')') {

		}
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
						i = j - 1;
						break;
				}
				pila.push(temp);
			}
			else if (expresion[i + 1] == '(') {

			}

		}
		else if (expresion[i] == '*' || expresion[i] == '/' || expresion[i] == '^') {
			pila.push(expresion[i] + "");
		}
		else if (isdigit(expresion[i])) {
			expresionPostFija.insertarElemento(expresion[i] + "");
		}
	}
}*/

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

void convertirPostFija::convertirExpresionPosfija() {
	std::string signoA = "+";
	Pila<std::string> pila;
	std::string temp;
	convertirInterFijaPostFija(pila,temp,0,signoA);
}

void convertirPostFija::convertirInterFijaPostFija(Pila<std::string> pila, std::string temp, int pos, std::string signoA) {
	if (isdigit(expresion[pos])) {
		for (int k = pos + 1; k < expresion.size(); k++) {
			if (isdigit(expresion[k]))
				temp.append(1, expresion[k]);
			else
				pos = k - 1;
			break;
		}
		expresionPostFija.insertarElemento(temp);
		temp = "";
	}else if (expresion[pos] == '+') {
		signoA = signoMayor(expresion[pos], signoA);
		if (isdigit(expresion[pos + 1]) && expresion[pos + 1] == '(')
			pila.push(signoA);
	}
	else if (expresion[pos] == '-') {
		signoA = signoMayor(expresion[pos], signoA);
		//Casos en el que seria un numero negativo Por ejemplo: -64
		if ((pos == 0 && isdigit(expresion[pos + 1]) ||
			expresion[pos - 1] == '*' || expresion[pos - 1] == '/')) {
			temp.append(1, expresion[pos]);
			for (int j = pos + 1; j < expresion.size(); j++) {
				if (isdigit(expresion[j]))
					temp.append(1, expresion[j]);
				else
					pos = j - 1;
				break;
			}
			expresionPostFija.insertarElemento(temp);
			temp = "";
		}
		else  {	
		}
		if (isdigit(expresion[pos + 1]) && expresion[pos + 1] == '(')
			pila.push(signoA);

	}
	else if (expresion[pos] == '*' || expresion[pos] == '/' || expresion[pos] == '^') {
		pila.push(expresion[pos] + "");
	}
	else if (expresion[pos] == '(') {
		pila.push(expresion[pos] + "");
		convertirInterFijaPostFija(pila, temp, 0, signoA);
	}
	else if (expresion[pos] == ')') {
		std::string elementos;

	}
}