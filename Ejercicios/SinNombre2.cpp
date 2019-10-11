/* Archivo: suma_digitos.cpp
 * Autor: Nombre y Apellidos
 * Ultima modificacion: 9/9/2003
 * ------------------------------------------------
 Este programa define y usa una funci�n que lee un
 n�mero entero positivo y calcula la suma de sus
 d�gitos.
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
     suma+=n%10;            /* Sumamos la �ltima cifra, que se obtiene
                             calculando el resto m�dulo 10 del n�mero.
                             Por ejemplo, la �ltima cifra de 12345 es
                             12345 % 10 = 5. */
      n=n/10;               /* Repetimos el proceso para el n�mero sin
                             la �ltima cifra, que se obtiene calculando
                             el cociente de dividir el n�mero original
                             por 10. Por ejemplo, 12345/10 =1234. */
   }
   return suma;
}


