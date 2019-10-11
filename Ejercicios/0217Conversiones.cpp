#include <iostream>
using namespace std;

int main(){
	//CONVERSOR DE MEDIDAS
	//PROGRAMA CREADO POR ALEJANDRO BARRACHINA
	double medida = 0;
	double solucion = 0;
	char magnitud;
	const double pulgada = 2.54;
	const double milla = 1609.344;
	const int fahrenheit = 32;
	const double galon = 4.5460;
	const double onza = 28.3495;
	const double libra = 0.45362;
	cout<<"Introduzca la inicial de la medida a convertir(primero la cantidad y despues la inicial de la magnitud): "<<endl;
	cin>>medida>>magnitud;
	if(magnitud == 'p'){
		solucion=medida*pulgada;
		cout<< medida<<" pulgadas son "<<solucion<<" cm"<<endl;
	}
	else{
		if(magnitud == 'm'){
			solucion=medida*milla;
			cout<< medida<<" millas son "<<solucion<<" metros"<<endl;
		}
		else{
			if(magnitud == 'f'){
				solucion=medida*fahrenheit;
				cout<< medida<<" fahrenheit son "<<solucion<<" celsius"<<endl;
			}
			else{
				if(magnitud == 'g'){
					solucion=medida*galon;
					cout<< medida<<" galones son "<<solucion<<" litros"<<endl;
				}
				else{
					if(magnitud == 'o'){
						solucion=medida*onza;
						cout<< medida<<" onzas son "<<solucion<<" gramos"<<endl;
					}
					else{
						if(magnitud == 'l'){
							solucion=medida*libra;
							cout<< medida<<" libras son "<<solucion<<" kilos"<<endl;
						}
						else{
							cout<<"ERROR"<<endl;
						}
					}
				}
			}	
		}	
	}
	system("pause");
}
