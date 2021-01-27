/*
AUTOR: Moraes Martinez Victor Hugo

DESCRIPCIÓN: Programa del Ejercicio 4

OBSERVACIONES: 

COMPILACIÓN: 	gcc -o Ejercicio04 Ejercicio04.c ../TADCola/TADCola(Din|Est|EstCirc).o (Si se tiene el objeto de la implementación)
				gcc -o Ejercicio04 Ejercicio04.c ../TADCola/TADCola(Din|Est|EstCirc).c (Si se tiene el fuente de la implementación)

EJECUCIÓN: Ejercicio04.exe (En Windows) - ./Ejercicio04 (En Linux)
*/

//LIBRERAS
#include <stdio.h>
#include "../TADCola/TADColaEst.h" 	//Si se usa la implemtentación dinámica (TADColaDin.c)
//#include "../TADCola/TADColaDin.h" 	//Si se usa la implemtentación estática (TADColaEst.c|TADColaEstCirc.c)

//PROGRAMA PRINCIPAL
int main(void)
{
	int i; //Variable para ciclos
	//Declaración de una cola c
	cola c;
	//Declaración de un elemento e
	elemento e;
	
	
	//Inicialización de la cola
	Initialize(&c);
	
	//Introducir los 10 numeros a la cola
	for(i=0;i<10;i++)
	{
		printf("\nDame el %d numero entero: ",i+1);
		scanf("%d",&e.n);
		Queue(&c,e);
	}
	
	//Mostrar los numeros a la cola
    printf("\nTu cola:\n");
	printf("\n");
	for(i=1;i<=Size(&c);i++)
	{
		e=Element(&c,i);
		printf("%d\t",e.n);
	}
	printf("\n");

	//Volteando la cola Flip()
	printf("\nCola Volteada\n");
	Flip(&c);

	//Mostrar los numeros a la cola
	printf("\n");
	for(i=1;i<=Size(&c);i++)
	{
		e=Element(&c,i);
		printf("%d\t",e.n);
	}
	printf("\n");

	//Buscando el elemento
	printf("\nBusca un elemento en la cola\n");
	printf("\nDijita el elemento:\n");
	scanf("%d",&e.n);
	int pos = Search(&c,e);
	printf("\nPosicion del elemento:\t%i\n",pos);

	//Destruir la cola
	Destroy(&c);
	
	return 0;
}

