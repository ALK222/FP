
#include "Lista.h"





int main() {
	tLista lista;
	bool ok = false;
	int pos;
	int ident;

	ok = carga_muestra(lista);
	if (ok) {
		pos = buscar_mayor(lista);
		cout << "El producto de mayor valor es: " << lista.productos[pos].id << endl;
		cout << "Identificador del producto a eliminar: ";
		cin >> ident;
		eliminar(lista, ident);
		mostrar(lista);
	}
	else {
		cout << "Error al abrir el archivo" << endl;
	}
	cout << endl;
	system("pause");
	return 0;
} // main


bool carga_muestra(tLista &l) {
	ifstream archivo;
	int ident;
	bool ok = false;

	l.cont = 0;
	archivo.open("productos.txt");
	cout << "Cargado archivo de productos..." << endl << endl;
	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		ok = true;
		archivo >> ident;
		while ((ident != -1) && (l.cont < MaxProductos)) {
			l.productos[l.cont].id = ident;
			archivo >> l.productos[l.cont].precio;
			archivo >> l.productos[l.cont].unidades;
			l.cont++;
			archivo >> ident;
		}
		archivo.close();
		mostrar(l);
	}
	return ok;
} // carga_muestra


int buscar_mayor(const tLista &l) {
	int pos;
	double mayor = 1.0;

	for (int i = 0; i < l.cont; i++) {
		if ((l.productos[i].precio * l.productos[i].unidades) > mayor) {
			mayor = l.productos[i].precio * l.productos[i].unidades;
			pos = i;
		}
	}
	return pos;
} // buscar_mayor


void eliminar(tLista &l, int id) {
	int pos = 0;
	bool encontrado = false;

	while ((pos < l.cont) && (!encontrado)) {
		if (l.productos[pos].id == id) {
			encontrado = true;
		}
		else {
			pos++;
		}
	}
	if (encontrado) {
		for (int i = pos; i < l.cont; i++) {
			l.productos[i] = l.productos[i + 1];
		}
		l.cont--;
	}
	else {
		cout << "Producto no encontrado" << endl;
	}
} // eliminar


void mostrar(const tLista &l) {
	cout << endl;
	cout << "Listado de productos" << endl;
	cout << "--------------------" << endl;
	for (int i = 0; i < l.cont; i++) {
		cout << l.productos[i].id << " ";
		cout << l.productos[i].precio << " ";
		cout << l.productos[i].unidades;
		cout << endl;
	}
} // mostrar
