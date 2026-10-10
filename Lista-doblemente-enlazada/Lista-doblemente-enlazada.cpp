// Lista-doblemente-enlazada.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

struct Nodo {
	int dato;
	Nodo* siguiente;
	Nodo* anterior;
};

//Recorrer la lista desde la cabeza hacia la cola
//esto tambien muestra la direccion de memoria de cada nodo y sus enlaces.
void imprimirLista(Nodo* cabeza) {
	Nodo* actual = cabeza;
	while (actual != nullptr) {
		cout << "Dato: " << actual->dato
			<< "| Direccion: " << actual
			<< "| Anterior: " << actual->anterior
			<< "| Siguiente " << actual->siguiente << endl;
		actual = actual->siguiente;
	}
	cout << endl;
}

//Recorre la lista desde la cola hacia la cabeza (usando el apuntador anterior)
void imprimirListaReversa(Nodo* cola) {
	Nodo* actual = cola;
	while (actual != nullptr) {
		cout << "Dato: " << actual->dato
			<< "| Direccion: " << actual
			<< "| Anterior: " << actual->anterior
			<< "| Siguiente: " << actual->siguiente << endl;
		actual = actual-> anterior;
	}
	cout << endl;
}

void BorrarLista(Nodo*& cabeza, Nodo*& cola) {
	int contador = 0;
	while (cabeza != nullptr) {
		Nodo* siguiente = cabeza->siguiente;
		contador++;
		// se imprime antes de delete: despues el nodo ya no existe
		cout << "Elemento borrado " << contador
			<< "| Dato: " << cabeza->dato
			<< "| Direccion: " << cabeza << endl;		
		delete cabeza;
		cabeza = siguiente;
	}
	cout << "Total de elementos borrados " << contador << endl;
	cola = nullptr;
}

//Agrega un nodo al final; mantener la cola evita recorrer toda la lista
void agregarNodo(Nodo*& cabeza, Nodo*& cola, int valor) {
	Nodo* nuevoNodo = new Nodo; // se crea el elemento con sus apuntadores
	nuevoNodo->dato = valor;
	nuevoNodo->siguiente = nullptr;
	nuevoNodo->anterior = nullptr;

	if (cabeza == nullptr) {
		// Lista vacia: el nuevo nodo es cabeza y cola a la vez
		cabeza = nuevoNodo;
		cola = nuevoNodo;
	}
	else {
		cola->siguiente = nuevoNodo; //El ultimo nodo apunta al nuevo
		nuevoNodo->anterior = cola; //El nuevo apunta de regreso al ultimo
		cola = nuevoNodo;
	}
}

int main()
{
	cout << "Actividad 10 - Lista Doblemente Enlazada\n";
	Nodo* cabeza = nullptr; // Apuntador al primer nodo
	Nodo* cola = nullptr; // Apuntador ak ultimo nodo
	int tamanoLista;

	cout << "Ingrese la cantidad de elementos de la lista enlazada: ";
	cin >> tamanoLista;
	if (tamanoLista <= 0) {
		cout << "Cantidad de elementos no valida" << endl;
		return 1;
	}

	for (int i = 0; i < tamanoLista; i++) {
		int valor;
		cout << "Ingrese el dato " << i + 1 << ": ";
		cin >> valor;
		// invocamos la funcion para agregar el Nodo
		agregarNodo(cabeza, cola, valor);
	}

	cout << "\nImprimiendo lista (de inicio a fin):" << endl;
	imprimirLista(cabeza);

	cout << "Imprimiendo lista (de fin a inicio):" << endl;
	imprimirListaReversa(cola);

	cout << "\nBorrando lista de numeros" << endl;
	BorrarLista(cabeza, cola);

	return 0;
}
