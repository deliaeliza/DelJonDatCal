#include "control.h"


///<summary>Constructor de la clase </summary>
Control::Control() {
	calculadora = new Calculadora();
}

///<summary>Destructor de la clase</summary>
Control::~Control() {
	delete calculadora;
}

///<summary>Valida que la expresion entrefija digitada por el usuario es valida,
///Este metodo llama a otro metodo que valida la expresion, pero le pasa una posicion por parametro</summary>
///<remarks>Recibe por paramtro un string con la expresion</remarks>
///<returns>Retorna un bool</returns>
bool Control::esValida(std::string expr) {
	return esValida(0, expr);
}

///<summary>Valida que la expresion entrefija digitada por el usuario es valida</summary>
///<remarks>Recbie una posicion, y la expresion entrefija a validar</remarks>
///<returns>Retorna un bool, true si la expresion en valida, false si no</returns>
bool Control::esValida(unsigned int pos, std::string expr) {
	if (expr == "" || expr == " ") {
		throw "La expresion esta vacia";
	}

	bool hayNumero = false;
	int contadorNumeros = 0;
	Pila<char> parentesis = Pila<char>();
	while (pos < expr.size()) {
		if (expr[pos] >= '0' && expr[pos] <= '9') {
			hayNumero = true;
			contadorNumeros++;
		}
		else {
			if (contadorNumeros <= 5)
				contadorNumeros = 0;
			else
				throw "Solo acepta numeros con maximo 5 cifras\n\t  Disposiciones del profesor";
		}
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
	if (contadorNumeros > 5)
		throw "Solo acepta numeros con maximo 5 cifras\n\t  Disposiciones del profesor";
	return true;
}

///<summary>Metodo que valida si un char es un operador</summary>
///<remarks>Recibe por parametro un char, con la expresion</remarks>
///<returns>Retorna true si es operador, false si no</returns>
bool Control::esOperador(char item) {
	return (item == '+' || item == '-' || item == '*' || item == '/' || item == '^');
}

///<summary>Remueve espacios de un string</summary>
///<remarks>Recibe la direccion de memoria de la expresion entre fija</remarks>
void Control::removerEspacios(std::string& exp) {
	for (std::string::size_type i = 0; i < exp.size(); ++i) {
		if (exp[i] < 0)
			throw "Error de sintaxis";
		if (isspace(exp[i]))
			exp.erase(i--, 1);
	}
}

///<summary>Si encuentra un patron de un numero seguido por un parentesis de apertura, supone que en media hay una multiplicacion</summary>
///<remarks>Recibe por referencia un string con la expresion entre fija</remarks>
void Control::verificarMultiplicacion(std::string& exp) {
	for (std::string::size_type i = 0; i < exp.size(); ++i)
		if (isdigit(exp[i]) && i != exp.size() - 1 && exp[i + 1] == '(')
			exp.insert(i + 1, 1, '*');
}

///<summary>Pasa la cadena que contiene la expresion entrefija a una lista</summary>
///<remarks>Llena una lista de caracteres</remarks>
void Control::pasarExpresionLista(std::string expresion, Lista& expresionEntrefija) {
	for (std::string::size_type i = 0; i < expresion.size(); ++i)
		expresionEntrefija.insertarElemento(expresion[i]);
}

///<summary>Metodo que es llamado de la interfaz, en donde obtiene el resultado
/// en donde encapsula varios metodos</summary>
///<remarks>Recibe por parametro la expresion entre-fija</remarks>
///<returns>Devuelve el resultado final</returns>
double Control::obtenerResultado(std::string expr) {
		removerEspacios(expr);
		if (!esValida(expr))
			throw "Error de sintaxis";
		verificarMultiplicacion(expr);
		Lista aux = Lista();
		pasarExpresionLista(expr, aux);
		return calculadora->resultado(aux);
}

///<summary>Metodo que devuelve la cadena que contiene la expresion post-fija</summary>
///<returns>Devuelve un string con la expresion post-fija</returns>
std::string Control::obtenerPostFija() {
	std::string postfija = calculadora->getCadenaPostFija();
	if (postfija == "")
		throw "Error, no hay expresion";
	return postfija;
}