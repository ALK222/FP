/* Archivo: suma_digitos.cpp
 * Autor: Nombre y Apellidos
 * Ultima modificacion: 9/9/2003
 * ------------------------------------------------
 Este programa define y usa una función que lee un
 número entero positivo y calcula la suma de sus
 dígitos.
*/


/* Zona de inclusiones */
#include <iostream>
using namespace std;


/* Zona de prototipos */
int suma_dig(int n);


/* Zona de definicion de la funcion principal (main) */
int main(void) {
   int numero;
   cout << "Este programa lee un numero y calcula la suma de sus digitos." <<
   endl << endl;

   cout << "Por favor, introduzca un numero entero positivo: ";
   cin >> numero;
   cout << endl;

   cout << "La suma de los digitos del numero " << numero << " es " <<
   suma_dig(numero) << "." << endl;

   system("pause");
}



/* Zona de definicion de funciones auxiliares */
int suma_dig(int n) {
   int suma=0;
   if (n < 0) n=-n;
   while (n!=0) {
     suma+=n%10;            /* Sumamos la última cifra, que se obtiene
                             calculando el resto módulo 10 del número.
                             Por ejemplo, la última cifra de 12345 es
                             12345 % 10 = 5. */
      n=n/10;               /* Repetimos el proceso para el número sin
                             la última cifra, que se obtiene calculando
                             el cociente de dividir el número original
                             por 10. Por ejemplo, 12345/10 =1234. */
   }
   return suma;
}


