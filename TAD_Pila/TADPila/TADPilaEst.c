/*
IMPLEMENTACIONES DE LA LIBRERIA DEL TAD PILA ESTÁTICA (TADPilaEst.h)
AUTOR: Edgardo Adrián Franco Martínez (C) Septiembre 2016
VERSIÓN: 1.0

DESCRIPCIÓN: TAD pila o stack.
Estructura de datos en la que se cumple:
Los elementos se añaden y se remueven por un solo extremo.
Este extremo es llamado “tope” de la pila.

OBSERVACIONES: Hablamos de una Estructura de datos estática cuando se le 
asigna una cantidad fija de memoria para esa estructura 
antes de la ejecución del programa. 

COMPILACIÓN PARA GENERAR EL CÓDIGO OBJETO: gcc TADPilaEst.c -c 
*/

//LIBRERAS
#include<stdio.h>
#include<stdlib.h>
#include "TADPilaEst.h"

//DEFINICIÓN DE FUNCIONES

/*
void Initialize(pila *s);
Descripción: Inicializar pila (Iniciar una pila para su uso)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve:
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/
void Initialize(pila *s)
{
	(*s).tope=-1; //s->tope=-1; 
	return;
}

/*
void Push(pila *s, elemento e);
Descripción: Empilar (Introducir un elemento a la pila)
Recibe: pila *s (Referencia a la pila "s" a operar), elemento e (Elemento a introducir en la pila)
Devuelve:
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida el indice del arreglo (tope) esta fuera del arreglo es decir hay desbordamiento
y se causará en error.
*/
void Push(pila *s, elemento e)
{
	s->tope++;
	
	//Si el tope alcanzo a MAX_ELEMENT, ya no hay más espacio para elementos en el arreglo
	if(s->tope==MAX_ELEMENT)
	{
		printf("\nERROR-Push(&s,e): Desbordamiento de la pila, no hay mas espacio en la pila");
		exit(1);
	}
	
	//Insertar el elemento si no hubo error
	s->arreglo[s->tope]=e;
	return;
}

/*
elemento Pop(pila *s);
Descripción: Desempilar (Extraer un elemento de la pila)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: elemento (Elemento e extraido de la pila)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida si la pila esta vacia (tope == -1) antes de desempilar (causa error desempilar si esta esta vacía)
*/
elemento Pop (pila *s)
{
	elemento r;
	
	//Si el tope es -1, se intenta Pop de pila vacia 
	if(s->tope==-1)
	{
		printf("\nERROR-e=Pop(&s): Subdesbordamiento de la pila, no hay elementos en la pila");
		exit(1);
	}
	
	//Si no hubo error retornar el elemento indexado por tope
	r=s->arreglo[s->tope];
	s->tope--;
	return r; 	
}

/*
boolean Empy(pila *s);
Descripción: //Vacia (Preguntar si la pila esta vacia)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: boolean (TRUE o FALSE según sea el caso)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
*/
boolean Empty(pila *s)
{
	boolean r;	
	if(s->tope==-1)
	{
		r= TRUE;	
	}	
	else
	{
		r= FALSE;
	}	
	return r;	
}

/*
elemento Top(pila *s);
Descripción: Tope (Obtener el "elemento" del tope de la pila si extraerlo de la pila)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: elemento (Elemento del tope de la pila)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida si la pila esta vacia antes de consultar al elemento del tope (causa error si esta esta vacía).
*/
elemento Top(pila *s)
{
	//Si el tope es -1, se intenta Pop de pila vacia 
	if(s->tope==-1)
	{
		printf("\nERROR-e=Top(&s): Subdesbordamiento de la pila, no hay elementos en la pila");
		exit(1);
	}
	
	//Si no hubo error retornar el elemento indexado por tope
	return s->arreglo[s->tope];	
}

/*
int Size(pila *s);
Descripción: Tamaño de la pila (Obtener el número de elementos en la pila)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: int (Tamaño de la pila -1->Vacia, 1->1 elemento, 2->2 elementos, ...)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
*/
int Size(pila *s)
{
	return s->tope+1;
}

/*
void Destroy(pila *s);
Descripción: Elimina pila (Borra a todos los elementos en a la pila de memoria* Memoria estática (No se puede eleminar realmente)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: 
Observaciones: El usuario a creado una pila y s tiene la referencia a ella.
*/
void Destroy(pila *s)
{
	//s->tope=-1;
	Initialize(s);
	return;
}

/*
Ejercicio1
*/

/*
Operacion 01: 	Operación de consulta 
elemento Element (pila *s, n);

Descripción: 	Retorna el elemento en de la pocicion "n" de la pila como desde 1 el más profundo hasta el
				tope de la pila
Recibe: 		pila *s (Referencia a la pila "s" a operar), int n (Pocicion del elemento)
Devuelve: 		Elemento en la pocicion "n"
Observaciones: 	Si el usuario ingresa un numero "n" fuera del rango, retornara error
Autor: 			Morales Martínez Víctor Hugo
*/
elemento Element (pila *s, int n){
	elemento e;
	int size = Size(s)-1;
	s->tope = -1;

	for (int i = 1; i <= n; i++)
	{
		s->tope++; 
	}
	e = s->arreglo[s->tope];
	s->tope = size;
	return e;	
}

/*
Operacion 02: 	Operación Modificadora 
void Flip(pila *s) 

Descripción: 	Voltea los elemntos de una pila
Recibe: 		pila *s (Referencia a la pila "s" a operar), int n (Pocicion del elemento)
Devuelve: 		-
Observaciones: 	Esta operación no causa errores, siempre es posible hacer un flip
Autor: 			Morales Martínez Víctor Hugo
*/
void Flip(pila *s){
	int size = Size(s)-1; 
	elemento arregloAux[size];
	elemento e;
	for (int i = 0; i <= size; i++)
	{
		e = Pop(s);
		arregloAux[i] = e;
	}
	
	for (int i = 0; i <= size; i++)
	{
		e = arregloAux[i];
		Push(s,e);
	}
	return;	
}