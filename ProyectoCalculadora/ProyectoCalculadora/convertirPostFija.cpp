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

convertirPostFija::convertirPostFija(std::string expresion) {
	this->expresion = expresion;
	expresionPostFija =  Lista();
}

Lista convertirPostFija::getExpresionPostFija() {
	return expresionPostFija;
}

void convertirPostFija::setExpresion(std::string nExpresion) {
	expresion = nExpresion;
}

std::string convertirPostFija::getExpresion() {
	return expresion;
}


char convertirPostFija::signoMayor(char signoActual, char signoAnterior) {
	if (signoAnterior == '+') {
		if (signoActual == '-')
			signoAnterior = '-';
	}
	else if (signoAnterior == '-') {
		if (signoActual == '-')
			signoAnterior = '+';
	}
	return signoAnterior;
}

void convertirPostFija::convertirExpresionPosfija() {
	char signoA = '+';
	Pila<char> pila = Pila<char>();
	std::string temp;
	Calculadora::removerEspacios(expresion);
	convertirInterFijaPostFija(pila,temp,0,signoA, 0);
}

void convertirPostFija::convertirInterFijaPostFija(Pila<char> pila, std::string temp, int pos, char signoA, int cont) {
	if (pos == expresion.size()) {
		while (!pila.estaVacia()) {
			std::string expresionP;
			expresionP = expresionP + pila.pop();

			expresionPostFija.insertarElemento(expresionP);
		}
		return;
	}
	else if (isdigit(expresion[pos])) {
		temp.append(1, expresion[pos]);
		for (int k = pos + 1; k < expresion.size(); k++) {
			if (isdigit(expresion[k]))
				temp.append(1, expresion[k]);
			else {
				break;
			}
			pos++;
		}
		
		expresionPostFija.insertarElemento(temp);
		temp = "";
	}
	else if (expresion[pos] == '(') {
		if (expresion[pos -1] == '-') {
			bool verdadero = false;
			for (int i = 0; i < expresion.size();i++) {
				if (expresion[i] != ')') {
					if (expresion[i] == '*' || expresion[i] == '/' || expresion[i] == '^') {
						verdadero = true;
					}
					else if (expresion[i] == '-' || expresion[i] == '+') {
						verdadero = false;
						break;
					}
				}
			}
			if (verdadero) {
				
			}


		}

		pila.push(expresion[pos]);
		//convertirInterFijaPostFija(pila, temp, pos++, signoA);
	}
	else if (expresion[pos] == ')') {

		//char elementos;
		/*while (!pila.estaVacia()) {

		}*/
	}
	else {
		char elemento = pila.pop();
		if (!pila.estaVacia() && precedencia(elemento) >= precedencia(expresion[pos])) {





		}
		if (expresion[pos] == '+') {
			signoA = signoMayor(expresion[pos], signoA);
			if (isdigit(expresion[pos + 1]) || expresion[pos + 1] == '(')
				pila.push(signoA);
		}
		else if (expresion[pos] == '-') {
			//Casos en el que seria un numero negativo Por ejemplo: -64
			if ((pos == 0 && isdigit(expresion[pos + 1]) ||
				expresion[pos - 1] == '*' || expresion[pos - 1] == '/')) {
				temp.append(1, expresion[pos]);
				for (int j = pos + 1; j < expresion.size(); j++) {
					if (isdigit(expresion[j]))
						temp.append(1, expresion[j]);
					else {
						break;
					}
					pos++;
				}
				expresionPostFija.insertarElemento(temp);
				temp = "";
			}
			else
				signoA = signoMayor(expresion[pos], signoA);
			if (isdigit(expresion[pos + 1]) || expresion[pos + 1] == '(')
				pila.push(signoA);

		}
		else if (expresion[pos] == '*' || expresion[pos] == '/' || expresion[pos] == '^') {
			pila.push(expresion[pos]);
		}
	}
	convertirInterFijaPostFija(pila, temp, ++pos, signoA);
}

int convertirPostFija::precedencia(char c) {
	if (c == '(')
		return 1;
	if (c == '+' || c == '-')
		return 2;
	if (c == '*' || c == '/' || c == '^')
		return 3;
	return -1;
}

convertirPostFija::~convertirPostFija() {

}