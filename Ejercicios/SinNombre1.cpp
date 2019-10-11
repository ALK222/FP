#include <iostream>
using namespace std;
double cuentas(int litros);

int main() {
	int litros;
	double coste;
	cin >> litros;
	coste = cuentas(litros);
	cout << coste;
	system("pause");
}
double cuentas(int litros) {
	double coste;
	if (litros <= 100) {
		coste = litros * 0.15;
	}
	else {
		if ((litros > 100)&&(litros <= 500)) {
			coste = 100 * 0.15;
			litros = litros - 100;
			coste = coste + (litros * 0.20);
		}
	}
	return coste;
}
