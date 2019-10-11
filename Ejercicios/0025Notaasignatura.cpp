#include <iostream>
using namespace std;

int main(){
	//CALCULO NOTA ASIGNATURA FP
	//PROGRAMA CREADO POR ALEJANDRO BARRACHINA
	double nota1 = 0;
	double nota2= 0;
	double practica1, practica2 = 0;
	double adicional = 0;
	double notafinal = 0;
	cout <<"Escriba la nota del primer examen: "<< endl;
	cin>> nota1;
	cout<<"Escriba la nota del examen final: "<< endl;
	cin>>nota2;
	cout <<"Escriba la nota de la primera práctica: "<< endl;
	cin>> practica1;
	cout <<"Escriba la nota de la segunda práctica: "<< endl;
	cin>> practica2;
	cout <<"Escriba la nota de la actividad adicional: "<< endl;
	cin>> adicional;
	notafinal=(nota1*0.15)+(nota2*0.5)+(practica1*0.06)+(practica2*0.14)+(adicional*0.15);
	cout<<"Su nota final es: "<<notafinal<<endl;
	system("pause");
}
