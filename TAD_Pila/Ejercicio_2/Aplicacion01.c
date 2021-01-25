/*
AUTOR: Morales Martínez Víctor Hugo

DESCRIPCION: Escribe una función que ordene un arreglo de números enteros utilizando dos pilas, la idea de ordenamiento se basa en el ordenamiento burbuja.

COMPILACION: 	gcc -o Aplicacion01 Aplicacion01.c ../TADPila/TADPila(Din|Est).o (Si se tiene el objeto de la implementacion)
				gcc -o Aplicacion01 Aplicacion01.c ../TADPila/TADPila(Din|Est).c (Si se tiene el fuente de la implementacion)

EJECUCIoN: Aplicacion01.exe (En Windows) - ./Aplicacion01 (En Linux)
*/

//LIBRERAS
#include <stdio.h>
#include <stdlib.h>
#include "../TADPila/TADPilaDiN.h" //Inclusi�n de la libreria del TAD Pila Est�tica (Si se desea usar una pila est�tica)
//#include "TADPila/TADPilaDin.h" //Inclusi�n de la libreria del TAD Pila Din�mica (Si se desea usar una pila din�mica)

//PROGRAMA PRINCIPAL
int main(void)
{
	/*
	Creamos los elementos que iran dentro de nuestro array
	*/
	elemento e1;
	e1.c = 'A';
	e1.i = 15;
	elemento e2;
	e2.c = 'B';
	e2.i = 12;
	elemento e3;
	e3.c = 'C';
	e3.i = 44;
	elemento e4;
	e4.c = 'D';
	e4.i = 2;
	elemento e5;
	e5.c = 'E';
	e5.i = 5;
	//Metemos los elementos en el arreglo
	elemento a[] = {e1,e2,e3,e4,e5};
	//Tamaño del arreglo (5)
  	int n = sizeof(a)/sizeof(a[0]);
	printf("Longitud del arreglo %i\n",n);

    printf("Elementos a ordenar:\n");

    printf("[");
    for(int i = 0; i < n; i++)
    {
        printf("|%c,%i|",a[i].c,a[i].i);
    }
    printf("]\n");

  	bubbleSortStack(a, n);
	
	//Salir del main 
	return 0;
}
