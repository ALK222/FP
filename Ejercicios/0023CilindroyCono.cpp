#include <iostream>
using namespace std;

int main(){
	double radio = 0;
	double pi = 3.14159;
	double altura = 0;
	double volumen = 0;
	cout<< "Introduzca el radio del cilindro y del cono: "<< endl;
	cin>> radio;
	cout<< "Introduzca la altura del cilindro y del cono: "<< endl;
	cin>> altura;
	volumen = altura*pi+(radio+radio);
	cout<< "El volumen del cilindro es "<< volumen <<"."<< endl;
	volumen = (altura*pi*(radio*radio))/3;
	cout<< "El volumen del cono es "<< volumen <<"."<< endl;
	system("pause");
}
