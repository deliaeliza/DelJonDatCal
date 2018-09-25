#include "interfaz.h"


Interfaz::Interfaz() {
	control = Control();
}

Interfaz::~Interfaz() {
}

void Interfaz::armarInicio() {
	std::cout << "\t\t\tCALCULADORA\n\n";
	std::cout << "\t------------------------------------------\n";
	std::cout << "\t\t   Caracteres Validos\n";
	std::cout << "\t\t7\t8\t9\t^\n";
	std::cout << "\t\t4\t5\t6\t-\n";
	std::cout << "\t\t1\t2\t3\t/\n";
	std::cout << "\t\t0\t*\t+\t=\n\n";
	std::cout << "\t------------------------------------------\n\n";
}

void Interfaz::calcularExpresion() {
	std::string expresion;
	armarInicio();
	std::cout << "\tDigite la expresion a calcular: \n\n";
	std::cout << "\t  ";
	getline(std::cin,expresion);
	std::cout << "\n";
	std::cout << "\t------------------------------------------\n\n";
	try {
		std::cout << "\t  El resultado es: " << /*control.obtenerResultado(expresion) << */"\n\n";
		std::cout << "\t  Expresion en notacion Post-Fija:\n\n";
		std::cout << "\t  " << /*control.obtenerPostFija()*/ expresion << "\n\n";
		std::cout << "\t------------------------------------------\n\n";
	}
	catch (std::string error) {
		std::cout << "\t  "<< error << "\n";
		std::cout << "\t------------------------------------------\n\n";
	}
}


void Interfaz::mostrarDatos() {
	std::string continuar = "";
	do {
		system("cls");
		calcularExpresion();
		std::cout << "\tRealizar otra operacion: \n\t  1: Cualquier Tecla 2: No" << "\n";
		std::cout << "\t  ";
		getline(std::cin, continuar);
		std::cout << "\t------------------------------------------\n\n";
	} while (continuar != "2" && continuar != "No" && continuar != "NO" && continuar != "no" && continuar != "nO");
}