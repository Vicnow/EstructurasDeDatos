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
#include "../TADPila/TADPilaDin.h" //Inclusi�n de la libreria del TAD Pila Est�tica (Si se desea usar una pila est�tica)
//#include "TADPila/TADPilaDin.h" //Inclusi�n de la libreria del TAD Pila Din�mica (Si se desea usar una pila din�mica)

//PROGRAMA PRINCIPAL
int main(void)
{
	/*
	Creamos los elementos que iran dentro de nuestro array
	*/

    pila mi_pila;
    Initialize(&mi_pila);
    pila ordenada;
    Initialize(&ordenada);
	elemento e1;
	e1.c = 'A';
	e1.i = 15;
    Push(&mi_pila,e1);
	e1.c = 'B';
	e1.i = 12;
    Push(&mi_pila,e1);
	e1.c = 'C';
	e1.i = 44;
    Push(&mi_pila,e1);
	e1.c = 'D';
	e1.i = 2;
    Push(&mi_pila,e1);
	e1.c = 'E';
	e1.i = 5;
    Push(&mi_pila,e1);

    ordenada = sortStack(&mi_pila);
	
    while (!Empty(&ordenada))
    {
        elemento e = Pop(&ordenada);
        printf("|%c,%i|",e.c,e.i);
    }

    printf("\n\nAutor: Morales Martinez Victor Hugo");
	printf("\nRepositorio Git: github.com/Vicnow/EstructurasDeDatos");
	printf("\nSitioWeb de ayuda: geeksforgeeks.org/sort-stack-using-temporary-stack/\n");
	
    
	//Salir del main 
	return 0;
}
