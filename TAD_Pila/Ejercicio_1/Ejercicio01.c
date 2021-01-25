/*
AUTOR: Morales Martínez Víctor Hugo

DESCRIPCION: Programa que emplea las Operaciones Element() y FLip() del ejercicio1 

COMPILACION: 	gcc -o Ejercicio01 Ejercicio01.c ../TADPila/TADPila(Din|Est).o (Si se tiene el objeto de la implementaci�n)
				gcc -o Ejercicio01 Ejercicio01.c ../TADPila/TADPila(Din|Est).c (Si se tiene el fuente de la implementaci�n)

EJECUCI�N: Ejercicio01.exe (En Windows) - ./Ejercicio01 (En Linux)
*/

//LIBRERAS
#include <stdio.h>
#include "../TADPila/TADPilaEst.h" //Inclusi�n de la libreria del TAD Pila Est�tica (Si se desea usar una pila est�tica)
//#include "TADPila/TADPilaDin.h" //Inclusi�n de la libreria del TAD Pila Din�mica (Si se desea usar una pila din�mica)

//PROGRAMA PRINCIPAL
int main(void)
{
	//Se declara una pila "mi_pila"
	pila mi_pila;
	//Declaro un elemento "e"
	elemento e;	
	//Inicializaci�n de "mi_pila"
	Initialize(&mi_pila);

	//Push de letras en orden alfabetico
	e.c='A';
	Push(&mi_pila,e);
	e.c='B';
	Push(&mi_pila,e);
	e.c='C';
	Push(&mi_pila,e);
	e.c='D';
	Push(&mi_pila,e);
	e.c='E';
	Push(&mi_pila,e);
	e.c='F';
	Push(&mi_pila,e);
	e.c='G';
	Push(&mi_pila,e);
	e.c='H';
	Push(&mi_pila,e);
	e.c='I';
	Push(&mi_pila,e);
	e.c='J';
	Push(&mi_pila,e);
	
	//Mostramos los ementos sin Modificarlos
	for (size_t i = 1; i <= Size(&mi_pila); i++)
	{
		e = Element(&mi_pila,i);
		printf("El elemento en la pocicion %i es:\t'%c'\n",i,e.c);
	}

	printf("\nAhora hacemos un Flip de la pila para voltear sus elementos!\n\n");
	Flip(&mi_pila);

	//Mostramos los ementos sin Modificarlos
	for (size_t i = 1; i <= Size(&mi_pila); i++)
	{
		e = Element(&mi_pila,i);
		printf("El elemento en la pocicion %i es:\t'%c'\n",i,e.c);
	}
	
	printf("\nComo vemos los Elementos de la pila se cambiaron de lugar!\n");
	printf("\nEl elemento que antes estaba en el tope ahora esta en el fondo y viceversa!\n");
	printf("\n\nAutor: Morales Martinez Victor Hugo");
	printf("\nRepositorio Git: github.com/Vicnow/EstructurasDeDatos\n");
	
	//Destruir de la pila
	Destroy(&mi_pila);	
	
	//Salir del main 
	//Salir del main 
	return 0;
}
