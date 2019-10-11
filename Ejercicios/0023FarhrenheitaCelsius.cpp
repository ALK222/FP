#include <iostream>
using namespace std;

int main(){
	//PASAR DE GRADOS FAHRENHEIT A CELSIUS
	//PROGRAMA CREADO POR ALEJANDRO BARRACHINA ARGUDO
	double c = 0;//CELSIUS
	double f = 0;//FAHRENHEIT
	cout << "Introduzca los grados fahrenheit:  " ;
	cin >> f;
	c = 5/9.0*(f-32);
	cout << f << " grados fahrenheit son "<< c << " grados celsius." << endl;
	system("pause");
}
