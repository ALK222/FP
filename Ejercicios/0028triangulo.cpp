#include <iostream>
#include <cmath>
using namespace std;
double ejercicio_8(double lado1, double lado2, double anguloG);
int main(){
	//AREA DE UN TRIANGULO POR EL SENO
	//PROGRAMA CREADO POR ALEJANDRO BARRACHINA ARGUDO
	double area;
	double lado1 = 0;
	double lado2 = 0;
	double anguloG = 0; //Ángulo en grados
	cout << "Se procede a calcular el area de un triangulo por la ley del seno." << endl;
	//Pedimos medidas
	cout << "Introduce la medida de un lado del triangulo: ";
	cin >> lado1;
	cout << endl << "Introduzca otro lado distinto: ";
	cin >> lado2;
	cout << endl << "Introduzca el angulo entre los lados dados: ";
	cin >> anguloG;
	area= ejercicio_8(lado1, lado2, anguloG);
	cout << "El area del triangulo es: " << area << endl;
	system("pause");
}
double ejercicio_8(double lado1, double lado2, double anguloG){//Cálculo de radianes y area
	double area;
	double angulorads; //Ángulo en radianes
	angulorads = anguloG *(M_PI/180);
	area = (1/2) * lado1 * lado2 * sin(angulorads);
	return area;
}
