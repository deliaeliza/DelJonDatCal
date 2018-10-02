#include "calculadora.h"

///<summary>Constructor de clase, Inicializa un string, y la cola</summary>
Calculadora::Calculadora() {
	cadenaPostFija = "";
	expresionPostFija = new Cola();
}
///<summary>Destructor de la clase</summary>
Calculadora::~Calculadora() {
	delete expresionPostFija;
}

///<summary>Devuelve el string que contiene la cadena postfija</summary>
std::string Calculadora::getCadenaPostFija() {
	return cadenaPostFija;
}

///<summary>Devuelve el resultado de evaluar la cadena postfija</summary>
///<remarks>Recibe una lista por referencia</remarks>
///<returns>Retorna un double con el resultado</returns>
double Calculadora::resultado(Lista& l) {
	convertirExpresionPostFija(l);
	Pila<double> numeros = Pila<double>();
	//try {
		return resultado(expresionPostFija, numeros);
	//}catch(const char* error) {
	//	throw error;
	//}
}

///<summary>Metodo que llama al metodo que convierte a expresion post-fija</summary>
///<remarks>Recibe una lista por referencia</remarks>
void Calculadora::convertirExpresionPostFija(Lista& l) {
	Pila<char> pila = Pila<char>();
	cadenaPostFija = "";
	convertirInterFijaPostFija(pila, l.obtenerInicio());
}

///<summary>Metodo recursivo que convierte la expresion entrefija a una expresion postfija</summary>
///<remarks>Recibe una pila, y el primer elemento de la lista</remarks>
void Calculadora::convertirInterFijaPostFija(Pila<char> pila, Nodo* actual) {
	char elemento;
	if (!actual) { ///actual == null
		while (!pila.estaVacia()) {
			elemento = pila.pop();
			expresionPostFija->enqueue(convertirString(elemento));
			cadenaPostFija = cadenaPostFija + elemento + " ";
		}
		return;
	}
	///Caso en que el elemento sea un digito
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
	///caso en el que el elemtento sea un (,
	///Y mete el valor a la pila
	else if (actual->valor == '(') {
		pila.push(actual->valor);
		expresionPostFija->enqueue(convertirString(actual->valor));
		cadenaPostFija = cadenaPostFija + actual->valor + " ";
	}
	///caso en el que el elemento sea un ), 
	///cuando eso pasa saca elementos de la pila hasta que encuentre a (
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
		///caso en el que el valor sea un - o un +
		if (actual->valor == '-' || actual->valor == '+') {
			///Casos en el que el valor de - o + sea un operador de raiz
			if (actual->prev && ( isdigit(actual->prev->valor) || actual->prev->valor == ')')) {
				while (!pila.estaVacia() && precedencia(pila.peek()) >= precedencia(actual->valor)) {
					elemento = pila.pop();
					expresionPostFija->enqueue(convertirString(elemento));
					cadenaPostFija = cadenaPostFija + elemento + " ";
				}
				pila.push(actual->valor);
			}
			///Casos en el que los signos de - o + sean parte de un numero o un parentesis
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

///<summary>Consulta el operador de mayor importancia</summary>
///<remarks>Recibe un operador valido, ya sea +,-,^,*,/,(</remarks>
///<returns>Retorna un numero entero</returns>
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

///<summary>Convierte un char a un string</summary>
///<remarks>Recibe un char</remarks>
///<returns>Devuelve un string</returns>
std::string Calculadora::convertirString(char c) {
	std::string expresion;
	expresion = expresion + c;
	return expresion;
}

///<summary>Calcula el resultado de la expresion postfija</summary>
///<remarks>Recibe una cola, en la que esta la expresion postfija, y recibe una pila, en la que guardara 
/// los numeros de la expresion</remarks>
///<returns>Devuelve un double con el resultado</returns>
double Calculadora::resultado(Cola* expr, Pila<double> numeros) {
	std::string signo = "";
	while (expr->siguiente() != "") {
		std::string actual = expr->dequeue();
		if (esOperador(actual)) {
			///Si hay dos numeros en pila, es operacion, si hay solo uno, el signo es del siguiente numero
			if (!numeros.estaVacia()) {
				double num = numeros.pop();
				if (!numeros.estaVacia()) {
					//try {
						numeros.push(realizarOperacion(num, numeros.pop(), actual));
					/*}
					catch (const char* error) {
						throw error;
					}*/
				}
				else {
					/// Devuelve el numero porque no hay suficientes para realizar una operacion
					numeros.push(num);
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
		else { 
			///Es numero. No se verifica ")", se supone que es sintacticamente correcta
			numeros.push(convertir(signo + actual));
			signo = "";
		}
	}

	if (numeros.peek() == -0) {
		return 0;
	}

	return numeros.pop();
}

///<summary>Resuelve signos de + y -</summary>
///<remarks>Recibe el signo actual, y el anterior</remarks>
///<returns>Devuelve un string con el resultado de resolver los signos anteriores</returns>
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

///<summary>Verifica que un valor, es un operador o no</summary>
///<remarks>Recibe un string con un valor actual</remarks>
///<returns>Devuelve un bool con la verficacion</returns>
bool Calculadora::esOperador(std::string item) {
	return (item == "+" || item == "-" || item == "*" || item == "/" || item == "^");
}

///<summary>Realiza una operacion</summary>
///<remarks>Recibe dos numeros y un operador</remarks>
///<returns>Devuelve un double</returns>
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

///<summary>Convierte un string a un numero</summary>
///<remarks>Recibe un string que contiene un numero</remarks>
///<returns>Devuelve un double con el numero convertido</returns>
double Calculadora::convertir(std::string numero) {
	return std::stod(numero);
}