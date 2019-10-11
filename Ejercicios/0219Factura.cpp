#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	//PRECIO DE UN PRODUCTO Y DATOS DEL CLIENTE
	//PROGRAMA CREADO POR ALEJANDRO BARRACHINA
	double precio = 0;
	int unidades = 0;
	char descuento;//letra de respuesta a la pregunta
	string DNI;
	string direccion;
	string nombre;
	string producto;
	double total = 0;//precio pre descuento
	double total2 = 0;//precio tras descuento
	double final = 0;
	double IVA = 0;
	double rebaja = 0;//rebaja final sobre el producto
	cout<<"Precio del producto: ";
	cin>>precio;
	cout<<"Unidades: ";
	cin>>unidades;
	cout<<"Descuento(s/n)? ";
	cin>>descuento;
	cout<<"Nombre del cliente: ";
	cin.ignore();
	getline (cin, nombre);
	cout<<"NIF del cliente: ";
	getline (cin, DNI);
	cout<<"Direccion del cliente: ";
	getline (cin, direccion);
	cout<<"Nombre del producto: ";
	getline (cin, producto); 
	cout << endl;
	total= precio * unidades;
	if(descuento == 's'){
		rebaja = total * 0.15;
		total2 = total - rebaja;
		IVA = total2 * (0.18);
		final = total2 + IVA;
	}
	else{
		if(descuento == 'n'){
			rebaja = 0;
			total = total2;
			IVA = total2 * (0.18);
			final = total2 + IVA;			
		}
		else{
			cout<<"ERROR";
			system("pause");			
		}
	}
	cout<<"Factura: "<<endl;
	cout << right << setw(50) <<nombre << endl;
	cout << right << setw(50) << direccion<< endl;
	cout << right << setw(50) << DNI << endl;
	cout << left << "Producto: "<< producto<< endl;
	cout << left << "Precio unitario: "<< right << setw(33)<<fixed<<setprecision(2)<< precio << endl;
	cout << left << "Unidades: "<< right << setw(40)<< unidades << endl;
	cout << left << "Total: "<< right << setw(43)<< fixed<<setprecision(2)<< total << endl;
	cout << left << "Descuento: "<< right << setw(34)<<"-"<< fixed<<setprecision(2)<< rebaja<< endl;
	cout << left << "Total tras descuento: "<< right << setw(28)<< fixed<<setprecision(2)<< total2 << endl;
	cout << left << "I.V.A. (18%): "<< right << setw(36)<< fixed<<setprecision(2)<< IVA << endl;
	cout << left << "Precio final: "<< right << setw(36)<< fixed<<setprecision(2)<< final << endl;
	system("pause");

}
