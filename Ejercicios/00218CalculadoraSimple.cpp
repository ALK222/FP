#include <iostream>
using namespace std;

int main(){
	//CONVERSOR DE MEDIDAS
	//PROGRAMA CREADO POR ALEJANDRO BARRACHINA
	double operando1 = 0;
	char operador;
	double operando2 = 0;
	double solucion = 0;
	cout<<"intruduzca la operacion a realizar(+,-,*,/): ";
	cin>>operando1>>operador>>operando2;//INTRODUCIMOS UN NUMERO, UN OPERADOR Y OTRO NUMERO (15+2)
	if(operador == '+'){//SUMA
		solucion = operando1 + operando2;
		cout<<operando1<<"+"<<operando2<<"="<<solucion<<endl;
	}
	else{
		if(operador == '-'){//RESTA
			solucion = operando1 - operando2;
			cout<<operando1<<"-"<<operando2<<"="<<solucion<<endl;
		}
		else{
			if(operador == '*'){//MULTIPLICACION
				solucion = operando1 * operando2;
				cout<<operando1<<"*"<<operando2<<"="<<solucion<<endl;
			}
			else{
				if(operador == '/'){//DIVISION
					solucion = operando1 / operando2; 
					cout<<operando1<<"+"<<operando2<<"="<<solucion<<endl;
				}
				else{
					cout<<"ERROR"<<endl;
				}
			}
		}
	}
	system("pause");
}