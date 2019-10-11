#include <iostream>
using namespace std;

int main(){
	//CALCULO DEL VOLUMEN DE UNA ESFERA PREDEFINIDA CON VARIABLES
	//PROGRAMA CREADO POR ALEJANDRO BARRACHINA ARGUDO
	double PI = 3.141592;
	double VOLUMEN = 0;
	double RADIO = 14.5;
	double ALTURA = 26.79;
	VOLUMEN = (PI*(RADIO*RADIO)*ALTURA)/3;
	cout <<"El volumen de la esfera es "<< VOLUMEN << endl;
	system("pause");
}
