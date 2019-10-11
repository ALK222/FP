/*Programa creado por Alejandro Barrachina Argudo
Actividad adicional fundamentos de programación
Ejercicio 05 Tema 07*/
//Bibliotecas
#include "Header.h"
#include "Archivo.h"

//Carga del archivo

bool carga(fstream &archivo, tLista &l) {
	int edad = 0;
	bool ok = false;
	string file;
	inicializa(l);
	color(10);
	cout << "¿Qué archivo desea abrir?(La lista por defecto es lista_atletas.txt) ";
	color(14);
	cin >> file;
	color(10);
	archivo.open(file);
	if (archivo.is_open()) {
		archivo >> edad;
		while ((edad != (-1)) && (l.contador < MAX_PARTICIPANTES)) {
				l.lista[l.contador].edad = edad;
				archivo >> l.lista[l.contador].deporte;
				archivo >> l.lista[l.contador].dopaje;
				archivo >> l.lista[l.contador].podio;
				archivo.ignore();
				getline(archivo, l.lista[l.contador].nombre);
				archivo >> edad;
				l.contador++;
		}	
		archivo.close();

		ok = true;
	}
	else {
		color(12);
		cout << "Error, no se ha encontrado el archivo." << endl;
		system("pause");
		ok = false;
	}
	return ok;
}

//Guardado del archivo

void guardar(tLista &l) {
	ofstream archivo;
	int pruebas;
	archivo.open("lista_atletas.txt");
	for (int i = 0; i < l.contador; i++) {
		
		archivo << l.lista[i].edad << " ";
		archivo << l.lista[i].deporte << " ";
		archivo << l.lista[i].dopaje << " ";
		archivo << l.lista[i].podio << " ";
		archivo << l.lista[i].nombre;
		archivo << endl;
	}
	archivo << "-1";
	archivo.close();

}