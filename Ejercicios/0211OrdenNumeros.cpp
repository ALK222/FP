#include <iostream>
using namespace std;

int main(){
	//ORDEN DE NUMEROS
	//PROGRAMA CREADO POR ALEJANDRO BARRACHINA
	int numero1 = 0;
	int numero2 = 0;
	int numero3 = 0;
	cout << "Escriba los numeros a ordenar"<<endl;
	cin>>numero1;
	cout<<endl;
	cin>>numero2;
	cout<<endl;
	cin>>numero3;
	if(numero1<numero2){//1<2
		if(numero2<numero3){//2<3
			cout<<numero1<<","<<numero2<<","<<numero3<<endl;//1,2,3
		}
		else{
			cout<<numero1<<","<<numero3<<","<<numero2<<endl;//1,3,2
		}
	}	
	else{
		if(numero2<numero3){//2<3
			if(numero1<numero3){//1<3
				cout<<numero2<<","<<numero1<<","<<numero3<<endl;//2,1,3
			}
			else{
				cout<<numero2<<","<<numero3<<","<<numero1<<endl;//2,3,1
			}
		}
		else{
			if(numero2<numero1){//2<1
				cout<<numero3<<","<<numero2<<","<<numero1<<endl;//3,2,1
			}
			else{
				cout<<numero3<<","<<numero1<<","<<numero2<<endl;//3,1,2
			}
		}
	}
	system("pause");		
}
