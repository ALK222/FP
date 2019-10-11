/*Ejercicio 6.2
Alejandro y Airam*/


//Librerias
#include <iostream>
using namespace std;
#include <locale>
#include <fstream>



//Variables globales
const int MaxProductos = 100;
typedef struct {
	int id = 0;//Identificador de cada producto
	float precio = 0;
	int cantidad = 0;
}tProducto;
typedef tProducto tArray[MaxProductos];

typedef struct{
	int contador = 0;
	tArray productos;
}tLista;

//Prototipos
void menu(int opcion); // menu
bool cargar(tLista &l);//Carga de archivo
int mayor(const tLista &l);//Busqueda del mayor valor
//void eliminar(tLista &l, int id);//Eliminar una posición del array
void mostrar(const tLista &l);//Mostrar lista completa
	

//Main

int main() {
	setlocale(LC_ALL, "spanish");
	system("color 0A");
	int opcion = -1;
	while (opcion != 0) {
		cout << "¿Qué desea hacer?" << endl;
		cout << "1.- Mostrar lista" << endl << "2.- Ver producto de mayor valor" << endl << "0.- Salir" << endl;
		cin >> opcion;
		menu(opcion);
	}
}


//Menu

void menu(int opcion) {
	tLista l;
	switch (opcion) {
	case 1:system("cls"); cargar(l);
			break;
		case 2:system("cls"); mayor(l);
			break;
		case 3:system("cls"); //eliminar(l, opcion);
			break;
		case 0: system("Exit");
			break;
	}
}

//Cargar

bool cargar(tLista &l) {
	bool ok;
	l.contador = 0;
	ifstream archivo;
	archivo.open("lista.txt");
	if (archivo.is_open()) {
		ok = true;
		archivo >> l.productos[l.contador].id;
		while (l.productos[l.contador].id != (-1)) {
			archivo >> l.productos[l.contador].precio;
			archivo >> l.productos[l.contador].cantidad;
			l.contador++;
			archivo >> l.productos[l.contador].id;
		}
		mostrar(l);
	}
	else {
		ok = false;
	}
	return ok;
}


void mostrar(const tLista &l) {
	cout << "===================================================" << endl;
	for (int i = 0; i < l.contador; i++) {
		cout << "id: " << l.productos[i].id << endl;
		cout << "Precio: " << l.productos[i].precio << endl;
		cout << "Unidad: " << l.productos[i].cantidad << endl;
		cout << "===================================================" << endl;
	}
}

int mayor(const tLista &l) {
	float total = 0;
	for (int i = 0; i < 1-l.contador; i++) {
		total = l.productos[i].cantidad*l.productos[i].precio;
		if (total > l.productos[i + 1].cantidad*l.productos[i + 1].precio) {
			total = l.productos[i + 1].cantidad*l.productos[i + 1].precio;
			i++;
		}
		else {
			i++;
		}
	}
		cout << "el mayor es: " << total;
		return total;
}