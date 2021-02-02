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

    char expresion[100];

	printf("\nPasando de Infijo a Posfijo.\n");
	printf("\nQuieres ver los pasos? (si = s/ no = cualquier otra letra)\n");
	char pasos;
	scanf("%c",&pasos);
	printf("\nDame la expresion:\t");
	scanf("%s",expresion);
	int size=0;
	while (expresion[size]!='\0'){size++;}
	printf("\n%d\n",size);

    if (pasos == 's')
	{
		printf("\n\nExpresion:\n");
		infijoPosfijoPasos(expresion,size);
	}else{
		printf("\n\nExpresion:\n");
		infijoPosfijo(expresion,size);
	}
	

	printf("\n\nAutor: Morales Martinez Victor Hugo");
	printf("\nRepositorio Git: github.com/Vicnow/EstructurasDeDatos\n");
	
	//Destruir de la pila
	Destroy(&mi_pila);	
	
	//Salir del main 
	//Salir del main 
	return 0;
}
