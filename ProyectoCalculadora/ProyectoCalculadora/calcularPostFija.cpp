#include "calcularPostFija.h"

CalcularPostFija::CalcularPostFija(Lista expr) {
	exprecion = expr;
	//numeros =  Pila();
}
double CalcularPostFija::resultado() {
	Nodo* actual = exprecion.obtenerInicio();
	if (!actual)
		return 0;

}