//Zona de inclusiones
#include <iostream>
#include <string>
using namespace std;

//Zona de prototipos
int operaciones( int numero);
int pedirDato(string);

//Funcion principal
int main(){
	int numero;
	numero = operaciones(pedirDato("Introduzca el numero: "));
}

//Definicion de funciones
int pedirDato(string) {
	cout << string;
	cin >> numero;
	return numero;
}
int operaciones (int numero){
	//Esta funcion realiza la suma de los digitos
	int suma = 0;
	while (numero != 0){
		suma = suma + numero%10;
		numero = numero/10;
	}
	return suma;
}

