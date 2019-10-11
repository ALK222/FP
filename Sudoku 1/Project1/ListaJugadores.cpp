#include "ListaJugadores.h"

//CREAR LISTA VACIA DE JUGADORES

void crearListaVacia(tListaJugadores &l, int capacidad) {
	l.cont = 0;
	l.capacidad = capacidad;
	l.jugadores = new tJugadorPtr[capacidad];
}

//CARGAR JUGADORES

bool cargarJ(tListaJugadores &l) {
	ifstream archivo;
	int centinela = (-1);
	int dato;
	char aux;
	string resto_linea;
	bool ok = false;
	archivo.open("listaJugadores.txt");
	crearListaVacia(l, MAX_JUGADORES);
	if (archivo.is_open()) {
		ok = true;
		archivo >> dato;
		while (dato != centinela) {
			if (l.cont >= l.capacidad) {
				ampliar(l);
			}
			l.jugadores[l.cont] = new tJugador;
			(*l.jugadores[l.cont]).puntos = dato;
			archivo >> noskipws;
			archivo >> aux; //AUXILIAR PARA SALTAR ESPACIOS
			getline(archivo, (*l.jugadores[l.cont]).identificador);
			archivo >> dato;
			l.cont++;
		}
	}
	return ok;
}

//MOSTRAR LISTA DE JUGADORES

void mostrar(const tListaJugadores &l) {
	colorLetra(10);
	cout << "==================================================================" << endl;
	for (int i = 0; i < l.cont; i++) {
		colorLetra(10);
		cout << "Jugador: ";
		colorLetra(14);
		cout << (*l.jugadores[i]).identificador;
		colorLetra(10);
		cout << " Puntuación: ";
		colorLetra(14);
		cout << (*l.jugadores[i]).puntos << endl;
	}
	colorLetra(10);
	cout << "==================================================================" << endl;
}

//GUARDAR LISTA DE JUGADORES

bool guardarJ(tListaJugadores &l) {
	ofstream archivo;
	bool ok = false;
	archivo.open("listaJugadores.txt");
	if (!archivo.is_open()) {
		ok = false;
		colorLetra(12);
		cout << "Error al guardar" << endl;
	}
	else {
		for (int i = 0; i < l.cont; i++) {
			archivo << (*l.jugadores[i]).puntos;
			archivo << " ";
			archivo << (*l.jugadores[i]).identificador;
			archivo << endl;
		}
		archivo << "-1";
		ok = true;
	}
	archivo.close();
	return ok;
} 

//PUNTUACION DE JUGADOR

bool puntuarJugardor(tListaJugadores &l, int puntos, int &desventaja) {
	system("cls");
	colorLetra(10);
	string id;
	bool ok = false;
	int pos = 0;
	char opcion = 0;
	cout << "¿Jugador nuevo?(s/n) ";
	colorLetra(14);
	cin >> opcion;
	colorLetra(10);
	switch (opcion)	{
	case 's': cout << "¿Qué id desea usar?(solo una palabra) ";
		colorLetra(14);
		cin >> id;
		colorLetra(10);
		puntos = puntos - desventaja;
		insertarJ(l, id, puntos, ok = true);
		break;
	case 'n': cout << "¿Qué id desea buscar? ";
		colorLetra(14);
		cin >> id;
		tListaJugadores temp = ordenarPorID(l);
		pos = buscar(temp, id, 0, l.cont - 1); //TODO comprobar qwue no sea -1
		if (pos != (-1)) {
			puntos = puntos - desventaja;
			(*temp.jugadores[pos]).puntos += puntos;
		}
		else {
			colorLetra(12);
			cout << "Jugador no encontrado" << endl;
			system("pause");
		}
		delete[] temp.jugadores;
		break;
	}

	return ok;
}

//INSERTAR JUGADOR EN LA LISTA

void insertarJ(tListaJugadores &lista, const string &id, int puntos, bool& ok) {
	int pos = 0;
	bool encontrado = false;
	if (lista.cont >= MAX_JUGADORES) {
		ampliar(lista);
	}
	lista.jugadores[lista.cont] = new tJugador;
	(*lista.jugadores[lista.cont]).identificador = id;
	(*lista.jugadores[lista.cont]).puntos = puntos;
	lista.cont++;
}

//BUSCAR JUGADOR EN LA LISTA

int buscar(tListaJugadores &lista, const string &id, int ini, int fin) {
	if ((fin - ini) <= 1) {
		if (lista.jugadores[ini]->identificador == id) {
			return ini;
		}
		else if (lista.jugadores[fin]->identificador == id) {
			return fin;
		}
		else {
			return -1;
		}
	}
	else {
		int mitad = ini + (fin - ini) / 2;
		if (id <= lista.jugadores[mitad]->identificador) {
			buscar(lista, id, ini, mitad);
		}
		else {
			buscar(lista, id, mitad, fin);
		}
	}
}

//LISTA ORDENADA POR PUNTOS

tListaJugadores ordenarPorRanking(const tListaJugadores &lista) {
	bool inter = true;
	int i = 0;
	tListaJugadores ordenada = copia(lista);
	while ((i < lista.cont) && inter) {
		inter = false;
		for (int j = ordenada.cont - 1; j > i; j--) {
			if ((*ordenada.jugadores[j]).puntos > (*ordenada.jugadores[j - 1]).puntos) {
				tJugadorPtr aux = ordenada.jugadores[j];
				ordenada.jugadores[j] = ordenada.jugadores[j - 1];
				ordenada.jugadores[j - 1] = aux;
				inter = true;
			}
		}
		if (inter = true) {
			i++;
		}
	}
	return ordenada;
}

//COPIA AUXILIAR DE LA LISTA

tListaJugadores copia(const tListaJugadores &lista) {
	tListaJugadores nueva;
	crearListaVacia(nueva, lista.capacidad);
	for (int i = 0; i < lista.cont; i++) {
		nueva.jugadores[i] = lista.jugadores[i];
		nueva.cont++;
	}
	return nueva;
}

//LISTA ORDENADA POR ID

tListaJugadores ordenarPorID(const tListaJugadores &lista) {
	bool inter = true;
	int i = 0;
	tListaJugadores ordenada = copia(lista);
	while ((i < lista.capacidad) && inter) {
		inter = false;
		for (int j = ordenada.cont - 1; j > i; j--) {
			if (menor((*ordenada.jugadores[j]),(*ordenada.jugadores[j - 1]))) {
				string tempID;
				int tempPuntos = 0;
				tempID = (*ordenada.jugadores[j]).identificador;
				tempPuntos = (*ordenada.jugadores[j]).puntos;
				(*ordenada.jugadores[j]) = (*ordenada.jugadores[j - 1]);
				(*ordenada.jugadores[j - 1]).identificador = tempID;
				(*ordenada.jugadores[j - 1]).puntos = tempPuntos;
				inter = true;
			}
		}
		if (inter = true) {
			i++;
		}
	}
	return ordenada;
}

//AMPLIACION DE LA LISTA

void ampliar(tListaJugadores &lista) {
	int capacidadN = lista.capacidad * 2;
	tJugadorPtr *jugadores = new tJugadorPtr[capacidadN];
	for (int i = 0; i < lista.cont; i++) {
		jugadores[i] = lista.jugadores[i];
	}
	lista.capacidad = capacidadN;
	delete[] lista.jugadores;
	lista.jugadores = jugadores;
}

//BORRAR JUGADORES PARA LIBERAR MEMORIA

void borrarJugadores(tListaJugadores &lista) {
	for (int i = 0; i < lista.cont; i++) {
		delete lista.jugadores[i];
	}
}
