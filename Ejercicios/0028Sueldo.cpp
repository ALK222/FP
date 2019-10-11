#include <iostream>
using namespace std;

int main(){
	//SUELDO EMPLEADO
	//PROGRAMA CREADO POR ALEJANDRO BARRACHINA
	double sueldobase = 0;
	double complementodestino = 0;
	double complementoacademico = 0;
	int horaextra = 0;
	int hijos = 0;
	int dependientes = 0;
	double sueldobruto = 0;
	double IRPF = 24;
	double retencion = 0;
	double total = 0;
	cout<< "Introduzca su sueldo base: ";
	cin>> sueldobase;
	cout<< "Introduzca su complemento de destino: ";
	cin>> complementodestino;
	cout<< "Introduzca su complemento de cargo academico: ";
	cin>> complementoacademico;
	cout<< "Introduzca la cantidad de horas extra realizadas: ";
	cin>> horaextra;
	cout<< "Introduzca el numero de hijos que tiene: ";
	cin>> hijos;
	cout<< "Introduzca el numero de personas mayores a su cargo: ";
	cin>> dependientes;
	sueldobruto = sueldobase+complementodestino+complementoacademico+(horaextra*23); //Cálculo del sueldo base del empleado
	IRPF= IRPF - (2*hijos) - (dependientes); //Cálculo del IRPF final
	retencion = sueldobruto*(IRPF/100); //Cálculo de la retención por impuestos
	total = sueldobruto - retencion; //Cálculo del sueldo final
	cout<<endl<<endl<<endl<<"Sueldo base: "<<sueldobase<<" euros"<<endl;
	cout<<"Complemento de destino: "<<complementodestino<<" euros"<<endl;
	cout<<"Complemento de cargo academico: "<<complementoacademico<<" euros"<<endl;
	cout<<"Horas extra realizadas: "<<horaextra<<endl;
	cout<<"Hijos: "<<hijos<<endl;
	cout<<"Mayores: "<<dependientes<<endl<<endl;
	cout<<"CALCULO DE LA NOMINA.-"<<endl;
	cout<<"sueldo bruto: "<<sueldobruto<<" euros"<<endl;
	cout<<"Porcentaje IRPF: "<<IRPF<<"%"<<endl;
	cout<<"Retencion IRPF: "<<retencion<<" euros"<<endl;
	cout<<"Sueldo neto: "<<total<<" euros"<<endl;
	system("pause");
	
	
}
