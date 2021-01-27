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

    char expresion1[] = {'(','A','+','B','*','C','-','D'};
	int size1 = sizeof(expresion1)/sizeof(expresion1[0]);
	char expresion2[] = {'A','^','B','*','C','-','D','+','E','/','F','/','(','G','+','H',')'};
	int size2 = sizeof(expresion2)/sizeof(expresion2[0]);
	char expresion3[] = {'(','(','A','+','B',')','*','C','-','D','-','(','D','-','E',')',')','^','(','F','+','G',')'};
	int size3 = sizeof(expresion3)/sizeof(expresion3[0]);

	printf("Pasando de Infijo a Posfijo. ¿Quieres ver los pasos? (si = s/ no =cualquier otra letra),\n");
	char pasos;
	scanf("%c",&pasos);
    if (pasos == 's')
	{
		printf("\n\nExpresion 1:\n");
		infijoPosfijoPasos(expresion1,size1);
		printf("\n\nExpresion 2:\n");
		infijoPosfijoPasos(expresion2,size2);
		printf("\n\nExpresion 3:\n");
		infijoPosfijoPasos(expresion3,size3);
	}else{
		printf("\n\nExpresion 1:\n");
		infijoPosfijo(expresion1,size1);
		printf("\n\nExpresion 2:\n");
		infijoPosfijo(expresion2,size2);
		printf("\n\nExpresion 3:\n");
		infijoPosfijo(expresion3,size3);
	}
	

	printf("\n\nAutor: Morales Martinez Victor Hugo");
	printf("\nRepositorio Git: github.com/Vicnow/EstructurasDeDatos\n");
	
	//Destruir de la pila
	Destroy(&mi_pila);	
	
	//Salir del main 
	//Salir del main 
	return 0;
}
