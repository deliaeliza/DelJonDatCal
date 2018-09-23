#include <iostream>
#include <string>
#include "convertirPostFija.h"

int main() {

	std::string convertir = "454*4/965-63";
	convertirPostFija  c = convertirPostFija(convertir);

	c.convertirExpresionPosfija();

	c.getExpresionPostFija().mostrarLista();

	system("pause");
	return 0;
}