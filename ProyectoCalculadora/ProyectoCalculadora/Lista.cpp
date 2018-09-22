// listadoble.cpp
// Definición de la clase Lista

#include "Lista.h"

// Inicializa la lista enlazada, con el nodo inicial apuntando a nullptr, el tamaño de la lista
// con cero elementos
ListaDoble::ListaDoble() {
	inicio = nullptr;
}

// Llama a la función borrarLista() para eliminar todos los elementos
ListaDoble::~ListaDoble() {
	borrarLista();
}


// Primero se verifica que se pueda crear memoria. Una vez creada la memoria, se realiza una 
// inserción simple, asignando el valor al nuevo nodo. Cada nodo recién creado se
// inserta al final de la lista
// La función devuelve como resultado el valor del item en caso de que se insertara correctamente, -1 en caso contrario 
int ListaDoble::insertarElemento(int item) {
	Nodo* nuevo;

	// Manejo de excepciones. Si no hay memoria para crear un nodo nuevo
	// se lanza una excepción
	try
	{
		nuevo = new Nodo;
	}
	catch (std::bad_alloc exception)
	{
		return -1;
	}

	nuevo->valor = item;     // Guardamos el valor en el nodo
	nuevo->next = nullptr;   // El puntero siguiente apuntaría a NULL
	nuevo->prev = nullptr;

	// Si la lista está vacía, el nodo creado se convierte en el primer elemento
	if (inicio == nullptr)
		inicio = nuevo;
	else {                      // Si ya existen elementos en la lista, entonces necesitamos
		Nodo* tmp = inicio;     // un auxiliar para recorrer la lista y colocarnos al final
		while (tmp->next != nullptr)
			tmp = tmp->next;
		tmp->next = nuevo;   // El último nodo apunta al nodo nuevo
		nuevo->prev = tmp;   // Apuntamos al nodo anterios
	}
}

//Primero se verifica si la lista está vacía, en ese caso no se hace nada. En caso contrario, se verifica si el elemento
//se encuentra en el primer nodo de la lista. Si el elemento no está en el primer nodo, entonces se recorre la lista
//utilizando dos punteros: tmp que apunta al nodo anterior mientras que tmp2 apunta al nodo actual. Si el elementro se
//encuentra en tmp2, entonces el nodo anterior debe apuntar al nodo que sigue al actual, y luego se libera la memoria
//La función devuelve como resultado el valor del item en caso de que se borrara correctamente, -1 en caso contrario 
int ListaDoble::borrarElemento(int item) {
	// Caso #1: Si la lista está vacía no hay nada qué borrar
	if (listaVacia())
		return -1;

	// Caso #2: Si el elemento a borrar es el primer nodo de la lista
	Nodo* tmp;
	tmp = inicio;
	if (inicio->valor == item) {
		inicio = inicio->next;
		inicio->prev == nullptr;
		delete tmp;
		return item;
	}

	// Caso #3: Si el elemento a borrar es cualquier otro nodo distinto del primero
	Nodo* tmp2;
	tmp2 = tmp->next;
	while (tmp2 != nullptr) {
		if (tmp2->valor == item) {
			tmp->next = tmp2->next;
			tmp2->next->prev = tmp;
			delete tmp2;
			return item;
		}
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
	return -1;
}

//Recorre la lista enlazada mostrando el contenido de cada uno de los elementos
void ListaDoble::mostrarLista() {
	if (listaVacia()) {
		std::cout << std::endl << std::endl << "La lista no tiene elementos..." << std::endl;
	}
	else
	{
		int i = 1;
		Nodo* tmp;
		tmp = inicio;
		while (tmp != nullptr) {
			std::cout << tmp->valor << " ";
			tmp = tmp->next;
		}
	}
	std::cout << std::endl;
}

//Recorre la lista enlazada de manera invertida mostrando el contenido de cada uno de los elementos
void ListaDoble::mostrarListaInvertida() {
	if (listaVacia()) {
		std::cout << std::endl << std::endl << "La lista no tiene elementos..." << std::endl;
	}
	else
	{
		int i = 1;
		Nodo* tmp;
		tmp = inicio;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
			++i;
		}
		while (tmp != nullptr) {
			std::cout << tmp->valor << " ";
			tmp = tmp->prev;
		}
	}
	std::cout << std::endl;
}

//Se recorre la lista enlazada de princio a fin, buscando el elemento en cada nodo. Además se cuenta con un contador que lleva la posición 
//del nodo donde se está llevando a cabo la búsqueda
//La función devuelve como resultado la posición del nodo donde se encontró el elemento, -1 si el elemento no se encontró 
int ListaDoble::buscarElemento(int item) {
	int i = 1;
	Nodo* tmp;
	tmp = inicio;
	while (tmp != nullptr) {
		if (tmp->valor == item) {
			return i;
		}
		++i;
		tmp = tmp->next;
	}
	return -1;
}

//Con ayuda de un puntero auxiliar, se recorre la lista de inicio a fin, eliminando de la memoria cada uno de los nodos
//Esta función no retorna ningún valor
void ListaDoble::borrarLista() {
	Nodo* tmp;
	while (inicio != nullptr) {
		tmp = inicio;
		inicio = inicio->next;
		delete tmp;
	}
}

//Función que devuelve "false" si la lista no está vacía, "true" en caso contrario
bool ListaDoble::listaVacia() {
	if (inicio == nullptr)
		return true;
	return false;
}