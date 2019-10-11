/*Programa creado por Alejandro Barrachina Argudo
Actividad adicional fundamentos de programación
Ejercicio 05 Tema 07*/

//Bibliotecas

#include "Lista.h"
#include "Algoritmos.h"


//inicialización de la lista

void inicializa(tLista &lista) {
	lista.contador = 0;
}

//Inscripción

void inscripcion(tLista &l) {
	if (l.contador < 20) {
		cout << "Introduzca el nombre del atleta: ";
		relleno(l, 1);//nombre
		cout << "Introduzca la edad del atleta: ";
		relleno(l, 2);//Edad
		cout << "Introduzca la categoría en la que compite:" << endl;
		cout << "1.-Maratón.                   2.-Salto de longitud." << endl;
		cout << "3.-Salto de altura.           4.-Salto con pértiga." << endl;
		cout << "5.-Jabalina.                  6.-Marcha." << endl;
		cout << "7.-Lanzamiento de peso.       8.-Martillo." << endl;
		cout << "9.-100 metros valla.          10.-1500 metros." << endl;
		cout << "Opción: ";
		relleno(l, 3);//prueba
		cout << "¿Ha pasado la prueba de dopaje?(s/n) ";
		relleno(l, 4);//Dopaje
		color(13);
		l.contador++;
		cout << "Datos actualizados" << endl;
	}
	else {
		color(12);
		cout << "Error, la lista está llena." << endl;
	}
	ordenAlfa(l, 1);
	system("pause");
}

//Datos a lista

void relleno(tLista &l, int op) {
	int opcion = (-1);
	char dopaje;
	color(14);
	switch (op){
	case 1:cin.ignore();
		getline(cin, l.lista[l.contador].nombre);
		break;
	case 2: cin >> l.lista[l.contador].edad;
		break;
	case 3:while ((opcion <= 0) || (opcion > 9)) {
		color(14);
		cin >> opcion;
		opcion = opcion - 1;
		l.lista[l.contador].deporte = opcion;
		if ((opcion <= 0) || (opcion >= 10)) {
			color(12);
			cout << "Error, introduzca una respuesta posible." << endl;
		}
	}
		break;
	case 4:	cin >> dopaje;
		if (dopaje == 's') {
			l.lista[l.contador].dopaje = true;
		}
		else {
			if (dopaje == 'n') {
				l.lista[l.contador].dopaje = false;
			}
			else {
				color(12);
				cout << "Error, introduzca una respuesta posible." << endl;
				l.lista[l.contador].dopaje = false;
			}
		}
		diNoalDopaje(l, l.contador);
		break;
	
	}
	color(10);
}

//Actualizacion de podio

void actualizaResultadoP(tLista &l) {
	string aux1; //Nombre
	string aux2; //Apellidos
	string nombre_completo; //buscador
	bool encontrado;
	char cambio;
	cout << "¿A qué atleta quieres actualizarle el resultado? ";
	color(14);
	cin >> aux1;
	cin.sync();
	getline(cin, aux2);
	nombre_completo = aux1 + aux2;
	for (int i = 0; i < l.contador; i++) {
		if (nombre_completo == l.lista[i].nombre) {
			color(10);
			cout << "¿El atleta entra al podio? ";
			color(14);
			cin >> cambio;
			if (cambio == 's') {
				l.lista[i].podio = true;
			}
			else {
				if (cambio == 'n') {
					l.lista[i].podio = false;
				}
				else {
					color(12);
					cout << "Error, introduzca una respuesta posible." << endl;
				}
			}
			i = l.contador;
			encontrado = true;
		}
		else {
			encontrado = false;
		}
	}
	if (encontrado == true) {
		color(13);
		cout << "Datos actualizados" << endl;
	}
	else {
		color(12);
		cout << "Error, atleta no encontrado." << endl;
	}
}

//Actualiza la prueba de dopaje

void actualizaResultadoD(tLista &l) {
	string aux1; //Nombre
	string aux2; //Apellidos
	string nombre_completo; //Buscador
	bool encontrado;
	char cambio;
	cout << "¿A qué atleta quieres actualizarle el resultado? ";
	color(14);
	cin >> aux1;
	cin.sync();
	getline(cin, aux2);
	nombre_completo = aux1 + aux2;
	for (int i = 0; i < l.contador; i++) {
		if (nombre_completo == l.lista[i].nombre) {
			color(10);
			cout << "¿El atleta ha pasado la prueba de dopaje? ";
			color(14);
			cin >> cambio;
			if (cambio == 's') {
				l.lista[i].dopaje = true;
			}
			else {
				if (cambio == 'n') {
					l.lista[i].dopaje = false;
				}
				else {
					color(12);
					cout << "Error, introduzca una respuesta posible." << endl;
				}
			}
			encontrado = true;
			diNoalDopaje(l, i);
			i = l.contador;
		}
		else {
			encontrado = false;
		}
	}

	if (encontrado == true) {
		color(13);
		cout << "Datos actualizados" << endl;
	}
	else {
		color(12);
		cout << "Error, atleta no encontrado." << endl;
	}
}

//Muestra la lista tras ser ordenada

void mostrar(tLista &l) {
	for (int i = 0; i < l.contador; i++) {
		cout << "=============================================================" << endl;
		cout << "Atleta: ";
		mostraraux(l, i, 1);
		cout << "Edad: ";
		mostraraux(l, i, 2);
		cout << "Prueba: ";
		mostraraux(l, i, 3);
		cout << "¿Ha pasado la prueba de dopaje? ";
		mostraraux(l, i, 4);
		cout << "¿Entra al podio? ";
		mostraraux(l, i, 5);
	}
	cout << "=============================================================" << endl;
}

//Cambios de color de la funcion mostrar

void mostraraux(tLista &l, int i, int op) {
	color(14);
	string categoria;
	switch (op) {
	case 1: cout << l.lista[i].nombre << endl;
		break;
	case 2: cout << l.lista[i].edad << endl;
		break;
	case 3:categoria = enum_a_string(l, l.lista[i].deporte);
		cout << categoria << endl;
		break;
	case 4:if (l.lista[i].dopaje == true) {
		cout << "Si" << endl;
	}
		   else {
		cout << "No" << endl;
	}
		break;
	case 5:	if (l.lista[i].podio == true) {
		cout << "Si" << endl;
	}
			else {
		cout << "No" << endl;
	}
		break;
	}
	color(10);
}

//cambio del valor de enum a una lista de caracteres que se muestre por pantalla

string enum_a_string(tLista &l, int opcion) {
	string deporte;
	switch (opcion){
	case maraton: deporte = "maraton";
		break;
	case salto_longitud: deporte = "Salto de longitud";
		break;
	case salto_altura: deporte = "Salto de altura";
		break;
	case pertiga: deporte = "Pertiga";
		break;
	case jabalina: deporte = "Jabalina";
		break;
	case marcha: deporte = "marcha";
		break;
	case peso: deporte = "Lanzamiento de peso";
		break;
	case martillo: deporte = "Lanzamiento de martillo";
		break;
	case valla: deporte = "100 metros valla"; 
		break;
	case metros: deporte = "1500 metros";
		break;
	}
	return deporte;
}

//Funcion destinada a que ningún deportista que no haya pasado la prueba de dopaje pueda entrar al podio

void diNoalDopaje(tLista &l, int i) {
	char podio;
	if (l.lista[i].dopaje == true) {
		color(10);
		cout << "¿Entra al podio?(s/n) ";
		color(14);
		cin >> podio;
		if (podio == 's') {
			l.lista[i].podio = true;
		}
		else {
			if (podio == 'n') {
				l.lista[i].podio = false;
			}
			else {
				color(12);
				cout << "Error, introduzca una respuesta posible." << endl;
			}
		}
		color(10);
	}
	else {
		l.lista[i].podio = false;
		color(12);
		cout << "Si no pasa la prueba de dopaje no puede entrar al podio" << endl;
	}
}
void eliminarAtleta(tLista &l) {
	string aux1; //Nombre
	string aux2; //Apellidos
	string nombre_completo; //Buscador
	bool encontrado = false;
	cout << "¿A qué atleta quieres eliminar? ";
	color(14);
	cin >> aux1;
	cin.sync();
	getline(cin, aux2);
	nombre_completo = aux1 + aux2;
	for (int i = 0; i < l.contador; i++) {
		if (nombre_completo == l.lista[i].nombre) {
			l.lista[i].nombre = " ";
			l.lista[i].edad = 0;
			l.lista[i].deporte = 0;
			l.lista[i].deporte = false;
			l.lista[i].podio = false;
			encontrado = true;
			for (int k = i; k < l.contador-1; k++) {
				l.lista[k] = l.lista[k + 1];
			}
			l.contador--;
		}
	}
	if (encontrado == true) {
		color(13);
		cout << "Datos actualizados" << endl;
	}
	else {
		color(12);
		cout << "Error, atleta no encontrado." << endl;
	}
}