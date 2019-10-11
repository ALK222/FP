#pragma once
#include <iostream>
#include <fstream>
using namespace std;

const int MaxProductos = 100;

typedef struct {
	int id;
	double precio;
	int unidades;
} tProducto;

typedef tProducto tArray[MaxProductos];

typedef struct {
	tArray productos;
	int cont;
} tLista;

// Carga los productos del archivo y los muestra en la pantalla
bool carga_muestra(tLista &l);

// Busca el producto con mayor valor en la lista
int buscar_mayor(const tLista &l);

// Elimina un producto de la lista
void eliminar(tLista &l, int id);

// Muestra el contenido de la lista de productos
void mostrar(const tLista &l);