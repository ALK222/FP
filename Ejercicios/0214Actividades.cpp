#include <iostream>
using namespace std;

int main(){
	//ACIVIDAD SEGUN TEMPERATURA
	//PROGRAMA CREADO POR ALEJANDRO BARRACHINA
	int temperatura = 0;
	cout<<"Escriba la temperatura en grados Celsius: ";
	cin>>temperatura;
	if(temperatura>30){
		cout<<"Lo idoneo para esta temperatura es hacer natacion."<<endl;
	}
	else{
		if((temperatura<=30)&&(20<temperatura)){
			cout<<"Lo idoneo es jugar al tenis."<<endl;
		}
		else{
			if((temperatura<=20)&&(10<temperatura)){
				cout<<"Lo idoneo es jugar al golf."<<endl;
			}
			else{
				if((temperatura<=10)&&(5<temperatura)){
					cout<<"Lo idoneo es hacer esqui."<<endl;
				}
				else{
					cout<<"Mejor quedate en casa jugando al parchis."<<endl;
				}
			}
		}
	}
	system("pause");
}	
