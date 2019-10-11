#include <iostream>
using namespace std;

int main(){
	//FORMULA DE F
	//PROGRAMA CREADO POR ALEJANDRO BARRACHINA
	int x = 12;
	double sigma = 2.1836;
	int y = 3;
	double lambda = 1.11695;
	double alfa = 328.67;
	double f = 0;
	f= (3*((x+(sigma*y))/((x*x)-(y*y))))-(lambda*(alfa-13.7));
	cout<<"La variable x es: "<< x<< endl;
	cout<<"La variable sigma es: "<< sigma<< endl;
	cout<<"La variable y es: "<< y<< endl;
	cout<<"La variable lambda es: "<< lambda<< endl;
	cout<<"La variable alfa es: "<< alfa<< endl;
	cout<<"El calculo final de f es: "<< f<< endl;
	system("pause");
}
