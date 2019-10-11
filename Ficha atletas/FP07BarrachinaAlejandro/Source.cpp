/*Programa creado por Alejandro Barrachina Argudo
Actividad adicional fundamentos de programaci�n
Ejercicio 05 Tema 07*/

//Bibliotecas
#include "Header.h"
#include "Lista.h"
#include "Archivo.h"
#include "Algoritmos.h"

//Prototipos de funciones
void menu(int op, tLista &l);//Selector de opciones

//Subrutinas

//Main

int main() {
	tLista lista;
	fstream listado;
	char opcion = '-1';
	bool comprobante = false;
	setlocale(LC_ALL, "spanish");
	comprobante = carga(listado, lista);
	if (comprobante == true) {
		while (opcion != 0) {
			system("cls");
			color(10);
			cout << "=========================================================================" << endl;
			cout << "Listado de atletas de la competici�n." << endl;
			cout << "�Qu� desea hacer?" << endl;
			cout << "1.-Inscribir atleta.                   2.-Mostrar listado alfab�ticamente." << endl;
			cout << "3.-Actualizar podio de atleta.         4.-Mostrar listado por edad." << endl;
			cout << "5.-Actualizar prueba de dopaje.        6.-Eliminar atleta de la lista." << endl;
			cout << "7.-Ayuda con el programa.              0.-Salir del programa." << endl;
			cout << "=========================================================================" << endl;
			cout << "Opci�n: ";
			color(14);
			cin >> opcion;
			color(10);
			menu(opcion, lista);
		}
		guardar(lista);
		system("exit");
	}
	else {
		system("exit");
	}

}

//Men�

void menu(char op, tLista &l) {
	int orden = 0;
	switch (op){
	case '1': inscripcion(l);
		guardar(l);
		break;
	case '2':cout << "�Desea ordenarlo de manera ascendente(1) o descendente(2)? ";
		color(14);
		cin >> orden;
		color(10);
		ordenAlfa(l, orden);
		mostrar(l);
		system("pause");
		break;
	case '3': actualizaResultadoP(l);
		system("pause");
		break;
	case '4': cout << "�Desea ordenarlo de manera ascendente(1) o descendente(2)? ";
		color(14);
		cin >> orden;
		color(10);
		ordenNum(l, orden);
		mostrar(l);
		system("pause");
		break;
	case '5': actualizaResultadoD(l);
		system("pause");
		break;
	case '6': eliminarAtleta(l);
		system("pause");
		break;
	case '7': ayuda();
		system("pause");
		break;
	}
}

//Cambio de color de la consola

void color(int c) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Variable para el control del color de la consola
	SetConsoleTextAttribute(hConsole, c);
}

//Funcion de ayuda al usuario

void ayuda() {
	int opcion;
	cout << "========================================================================================================================" << endl;
	cout << "Hola, soy Kord, tu asistente de ayuda en este programa. �Sobre que desea ayuda? " << endl;
	cout << "1.-Orden alfab�tico.                                      2.-El programa se cierra si introduzco un caracter en el men�." << endl;
	cout << "3.-El programa no abre el archivo que quiero.             4.-No se encuentra un atleta." << endl;
	cout << "========================================================================================================================" << endl;
	cout << "Opci�n: ";
	color(14);
	cin >> opcion;
	color(10);
	cout << "========================================================================================================================" << endl;
	switch (opcion)	{
	case 1: cout << "En el orden alfab�tico se ordenar�n las may�sculas antes que las min�sculas, as� que tenga cuidado de introducir todos  los nombres como corresponda" << endl;
		cout << "========================================================================================================================" << endl;
		break;
	case 2: cout << "Por car�cter�sticas del programa no se tolera un caracter en el men�, por lo tanto este se cerrar�" << endl;
		cout << "========================================================================================================================" << endl;
		break;
	case 3: cout <<"Si el programa no abre el archivo deseado mire si lo estuviese escribiendo mal o si no estuviese en la carpeta" << endl;
		cout << "FP07BarrachinaAlejandro" << endl;
		cout << "========================================================================================================================" << endl;
		break;
	case 4: cout << "El programa de b�squeda es muy sensible a espacios, may�sculas y min�sculas, as� que asegurese de que el atleta est� escrito correctamente, o si no est� en la lista" << endl;
		cout << "========================================================================================================================" << endl;
		break;
	}
}