#include <iostream>
using namespace std;

int main(){
	//PASAR DE GRADOS SEGUNDOS A HORAS MINUTOS Y SEGUNDOS
	//PROGRAMA CREADO POR ALEJANDRO BARRACHINA ARGUDO
	int tiempo = 0;
	int segundos = 0;
	int minutos = 0;
	int horas = 0;
	cout << "Introduce los segundos a convertir: ";
	cin >> tiempo;
	horas = tiempo/3600;
	minutos = tiempo%3600;
	segundos = minutos%60;	
	minutos = minutos/60;
	cout << tiempo << " segundos son "<< horas <<":"<<minutos<<":"<<segundos;
	system("pause");
}
	
