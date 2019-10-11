/*Programa de Alejandro Barrachina y Airam Martín
Practica 2: Sudokus*/
#include "listaSudokus.h"

//CREAR LISTA VACIA DE SUDOKUS

void crearListaVacia(tListaSudokus &lista) {
	lista.cont = 0;
}

//CARGAR LISTA DE SUDOKUS

bool cargarS(tListaSudokus &lista) {
	ifstream archivo;
	int centinela = (-1);
	int dato;
	char aux;
	string resto_linea;
	bool ok = false;
	archivo.open("listaSudokus.txt");
	crearListaVacia(lista);
	if (archivo.is_open()) {
		ok = true;
		archivo >> dato;
		while ((dato != centinela) && (lista.cont < MAX_SUDOKUS)) {
			lista.array[lista.cont].nivel = dato;
			archivo >> noskipws;
			archivo >> aux;
			getline(archivo, lista.array[lista.cont].fichero);
			archivo >> dato;
			lista.cont++;
		}
	}
	return ok;
}

//MOSTRAR LISTA DE SUDOKUS

void mostrar(const tListaSudokus &lista) {
	for (int i = 0; i < lista.cont; i++) {
		colorLetra(10);
		if (i % 2 == 0) {
			cout << i + 1 << ".- Sudoku: ";
			colorLetra(14);
			cout << lista.array[i].fichero;
		}
		else {
			cout << "                   " << i + 1 << ".- Sudoku: ";
			colorLetra(14);
			cout << lista.array[i].fichero << endl;
		}
	}
}

//REGISTRAR SUDOKU

bool registrarSudoku(tListaSudokus &lista) {
	tSudoku sudokun; //Sudoku a insertar
	bool lleno = false;
	bool repetido = false;
	mostrar(lista);
	colorLetra(10);
	cout << endl << "¿Cómo se llama el sudoku que quiere añadir? ";
	colorLetra(14);
	cin >> sudokun.fichero;
	colorLetra(10);
	cout << "¿Cuántos puntos se pueden conseguir? ";
	colorLetra(14);
	cin >> sudokun.nivel;
	insertarS(lista, sudokun, lleno, repetido);
	colorLetra(12);
	if (lleno) {
		cout << "La lista de sudokus ya está llena" << endl;
		system("pause");
	}
	if (repetido) {
		cout << "Ya hay un archivo con el mismo nombre en la lista" << endl;
		system("pause");
	}
	guardar(lista);
	return (!lleno) && (!repetido);
}

//GUARDADO DE LISTA

bool guardar(const tListaSudokus &lista) {
	ofstream archivo;
	bool ok = false;
	archivo.open("listaSudokus.txt");
	if (!archivo.is_open()){
		ok = false;
		colorLetra(12);
		cout << "Error al guardar" << endl;
	}
	else {
		for (int i = 0; i < lista.cont; i++) {
			archivo << lista.array[i].nivel;
			archivo << " ";
			archivo << lista.array[i].fichero;
			archivo << endl;
		}
		archivo << "-1";
		ok = true;
	}
	archivo.close();
	return ok;
}

//INSERCION DEL SUDOKU EN LISTA

void insertarS(tListaSudokus &lista, const tSudoku &sudoku, bool &lleno, bool &encontrado){
	int pos = 0;
	if (lista.cont == MAX_SUDOKUS) {
		lleno = true;
	}
		encontrado = buscarFichero(lista, sudoku.fichero);
	if ((!encontrado) && (!lleno)){
		pos = buscarPos(lista, sudoku);
		lista.cont++;
		for(int i = lista.cont; i > pos; i--){
			lista.array[i] = lista.array[i - 1];
		}
		lista.array[pos] = sudoku;
	}
}

//BUSCAR FICHERO

bool buscarFichero(const tListaSudokus &lista, string nombreFich) {
	bool encontrado = false;
	for (int i = 0; i < lista.cont; i++) {
		if (nombreFich == lista.array[i].fichero) {
			encontrado = true;
			i = lista.cont;
		}
	}
	return encontrado;
}

//BUSCAR POSICION

int buscarPos(const tListaSudokus &lista, const tSudoku &sudoku) {
	int ini = 0, fin = lista.cont - 1, mitad;
	while (ini <= fin){
		mitad = (ini + fin) / 2; //Division entera
		if (operator<(sudoku.fichero, lista.array[mitad].fichero)) {
			fin = mitad - 1;
		}
		else {
			ini = mitad + 1;
		}
	}
	return ini;
}