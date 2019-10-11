/*Programa creado por Alejandro Barrachina Argudo
Actividad adicional fundamentos de programación
Ejercicio 05 Tema 07*/
#pragma once
//Bibliotecas
#include "Header.h"


//Variables globales
const int MAX_PARTICIPANTES = 20; //Número máximo de participantes. Se puede variar según las necesidades del torneo
typedef enum { maraton, salto_longitud, salto_altura, pertiga, jabalina, marcha, peso, martillo, valla, metros}tPrueba;
typedef struct {
	string nombre;
	int edad;
	int deporte;
	bool dopaje;
	bool podio;
}tAtleta;
typedef tAtleta tArray[MAX_PARTICIPANTES];

typedef struct {
	tArray lista;
	int contador;
}tLista;


//Prototipos de funciones
void menu(char op, tLista & l);
void inicializa(tLista &lista);
void inscripcion(tLista &l);//Rutina para inscirbir nuevos participantes
void actualizaResultadoP(tLista &l);//Actualiza el podio de un atleta
void actualizaResultadoD(tLista &l);//Actualiza la prueba de dopaje de un atleta
void relleno(tLista &l, int op); //Pasa la inscripcion a la lista
void mostrar(tLista &l);//Muestra la lista tras ordenarla
void mostraraux(tLista &l, int i, int op);//cambia el color de los datos y del enunciado
string enum_a_string(tLista &l, int opcion);//Devuelve como string el valor del enum
void diNoalDopaje(tLista &l, int i);//Si el atleta no ha pasado la prueba de dopaje, no entra al podio
void eliminarAtleta(tLista &l);//Se elimina a un atleta seleccionado de la lista