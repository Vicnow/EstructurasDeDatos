/*
AUTOR: Edgardo Adri�n Franco Mart�nez (C) Septiembre 2016
VERSI�N: 1.0

DESCRIPCI�N: Programa de ejemplo que utiliza el TAD pila

OBSERVACIONES: Se emplea la libreria TADPilaDin.h o TADPilaEst.h implementadas
en clase. Ambas estructuras elemento, ya sea la de la implementaci�n est�tica o din�mica deber�n tener un campo char c;

COMPILACI�N: 	gcc -o Prueba01 Prueba01.c TADPila(Din|Est).o (Si se tiene el objeto de la implementaci�n)
				gcc -o Prueba01 Prueba01.c TADPila(Din|Est).c (Si se tiene el fuente de la implementaci�n)

EJECUCI�N: Prueba01.exe (En Windows) - ./Prueba01 (En Linux)
*/

//LIBRERAS
#include <stdio.h>
#include "TADPilaEst.h" //Inclusi�n de la libreria del TAD Pila Est�tica (Si se desea usar una pila est�tica)
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

	//Push de A, B, C, D, E, F, G, H, I
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
	
	//Ver la letra en el tope	
	e=Top(&mi_pila);
	printf("\n%c",e.c);

	//Probando Element()
	for (int i = 1; i <= 9; i++)
	{
		e=Element(&mi_pila,i);
		printf("\nElemento No.%d = %c\n",i,e.c);
	}
	//int num = 1;
	
	//Mientras la pila no este vacia (Consultar su altura e imprimirla, hacer un Pop e imprimir la letra del elemento)
	/*
	while(!Empty(&mi_pila))
	{	
		printf("\n%d",Top(&mi_pila));
		e=Pop(&mi_pila);
		printf("\t%c",e.c);
	}
	*/

	//Probando Flip();
	printf("Haciendo Flip\n");
	Flip(&mi_pila);
	//Probando Element()
	for (int i = 1; i <= 9; i++)
	{
		e=Element(&mi_pila,i);
		printf("\nElemento No.%d = %c\n",i,e.c);
	}
	//Mostrar el n�mero de elementos que contiene la pila
	printf("\n%d",Size(&mi_pila));
	
	//Destruir de la pila
	Destroy(&mi_pila);	
	
	//Salir del main 
	//Salir del main 
	return 0;
}
