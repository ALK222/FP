/*Programa creado por Alejandro Barrachina Argudo
Actividad adicional fundamentos de programación
Ejercicio 05 Tema 07*/

//Bibliotecas 
#include "Algoritmos.h"

//ordenacion numerica

void ordenNum(tLista &l, int op) {
	tLista aux;
	int pos = 0;
	aux.contador = 1;
	if (op == 1) { //Orden ascendente
		//Desde el segundo valor hasta el último
		for (int i = 1; i < l.contador; i++) {
			aux.lista[1] = l.lista[i];
			pos = 0;
			while ((pos < i) && !(l.lista[pos].edad > aux.lista[1].edad)) {
				pos++;
			}
			// pos: índice del primer mayor; i si no lo hay
			for (int j = i; j > pos; j--) {
				l.lista[j] = l.lista[j - 1];
			}
			l.lista[pos] = aux.lista[1];
		}
	}
	else {
		if (op == 2) {//Orden descendente
			//Desde el segundo valor hasta el último
			for (int i = 1; i < l.contador; i++) {
				aux.lista[1] = l.lista[i];
				pos = 0;
				while ((pos < i) && !(l.lista[pos].edad < aux.lista[1].edad)) {
					pos++;
				}
				// pos: índice del primer mayor; i si no lo hay
				for (int j = i; j > pos; j--) {
					l.lista[j] = l.lista[j - 1];
				}
				l.lista[pos] = aux.lista[1];
			}
		}
		else {
			color(13);
			cout << "Error, valor no valido" << endl;
		}
	}

}

//Ordenacion alfabetica

void ordenAlfa(tLista &l, int op) {
	tLista aux;
	int pos = 0;
	
	if (op == 1) { //Orden ascendente
		//Desde el segundo valor hasta el último
		for (int i = 1; i < l.contador; i++) {
			aux.lista[1] = l.lista[i];
			pos = 0;
			while ((pos < i) && !(l.lista[pos].nombre > aux.lista[1].nombre)) {
				pos++;
			}
			// pos: índice del primer mayor; i si no lo hay
			for (int j = i; j > pos; j--) {
				l.lista[j] = l.lista[j - 1];
			}
			l.lista[pos] = aux.lista[1];
		}
	}
	else {
		if (op == 2) {//Orden descendente
			//Desde el segundo valor hasta el último
			for (int i = 1; i < l.contador; i++) {
				aux.lista[1] = l.lista[i];
				pos = 0;
				while ((pos < i) && !(l.lista[pos].nombre < aux.lista[1].nombre)) {
					pos++;
				}
				// pos: índice del primer mayor; i si no lo hay
				for (int j = i; j > pos; j--) {
					l.lista[j] = l.lista[j - 1];
				}
				l.lista[pos] = aux.lista[1];
			}
		}
		else {
			color(13);
			cout << "Error, valor no valido" << endl;
		}
	}
}