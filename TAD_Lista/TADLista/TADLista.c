#include "TADLista.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Initialize (lista *l)
{
	l->frente=NULL;
	l->final=NULL;
	l->tamanio=0;
	return; 
}
void Destroy (lista *l)
{
	//Apuntador auxiliar a nodo
	nodo *aux;
	
	//Mientras el apuntador del frente de la lista no sea "NULL"
	while(l->frente != NULL)
	{
		//Guardar la referencia el frente
		aux = l->frente;
		
		//El nuevo frente es el siguiente
		l->frente = l->frente->siguiente;
		
		//Liberar el antiguo frente de memoria
		free(aux);
	}

	//Colocar el final inicializado en "NULL"
	l->final = NULL;
	l->tamanio = 0;
	return;		
}

posicion Final (lista *l)
{
	return l->final;
}

posicion First (lista *l)
{
	return l->frente;
}

posicion Following (lista *l,posicion p)
{
	if(ValidatePosition (l,p))
		return p->siguiente;
	else
		exit(1);		
}

posicion Previous (lista *l,posicion p)
{
	posicion aux;
		
		if(p==l->frente) 
			return NULL;
				
		aux=l->frente;
		while(aux!=NULL)
		{
			if(aux->siguiente==p)
				return aux;
		}
		exit(1);
}

posicion Search (lista *l,elemento e)
{
	posicion aux=l->frente;
	
	while(aux!=NULL)
	{
		if(memcmp(&(aux->e),&e,sizeof(elemento))==0)
		{
			return aux;
		}
		aux=aux->siguiente;
	}
	return NULL;
}

elemento Position (lista *l,posicion p)
{
	if(ValidatePosition (l,p))
		return p->e;
	else
		exit(1);
}

boolean ValidatePosition (lista *l,posicion p)
{
	posicion aux=l->frente;
	
	while(aux!=NULL)
	{
		if(aux==p)
			return TRUE;
		aux=aux->siguiente;	
	}
	return FALSE;
}

posicion ElementPosition(lista *l, int n)
{
	posicion r=NULL;
    posicion aux;
	int i;
	
	if(n>0&&n<=Size(l))
	{
		aux=l->frente;
		for(i=2;i<=n;i++)
			aux=aux->siguiente;
		return aux;		
	}
	else
		return NULL;
	
}

elemento Element(lista *l, int n)
{
	elemento r;
    posicion aux;
	int i;
	
	if(n>0&&n<=Size(l))
	{
		aux=l->frente;
		for(i=2;i<=n;i++)
			aux=aux->siguiente;
		return aux->e;		
	}
	else
		exit(1);
}

/*
Ejercicio5
*/

/*
Operacion 01: 	Operación de consulta 
int Size (lista *l);

Descripción: 	Retorna el tamaño de la lista
Recibe: 		lista *l (Referencia a la lista "l" a operar)
Devuelve: 		Tamaño de la lista
Observaciones: 	-
Autor: 			Morales Martínez Víctor Hugo
*/
int Size (lista *l)
{
    return l->tamanio;
}

/*
Operacion 02: 	Operación de consulta 
boolean Empty (lista *l);

Descripción: 	Muestra si la lista esta vacia
Recibe: 		lista *l (Referencia a la lista "l" a operar)
Devuelve: 		booleano TRUE / FALSE dependiendo del caso
Observaciones: 	-
Autor: 			Morales Martínez Víctor Hugo
*/
boolean Empty (lista *l){
	//Utilizando la funcion Size() creada anteriormente
	boolean r;
	int size = Size(l);
	if (size == 0)
	{
		return TRUE; //Esta vacia
	}else{
		return FALSE; //No esta vacia
	}
}

/*
Operacion 03: 	Operación de Insercion
void Insert (lista * l, posicion p, elemento e, boolean b);

Descripción: 	Muestra si la lista esta vacia
Recibe: 		lista *l (Referencia a la lista "l" a operar)
				posicion p (lugar a insertar)
				elemento e (elemento a insertar)
				boolean b (si se insertara atras o enfrente de la posicion dada)
Devuelve: 		-
Observaciones: 	-
Autor: 			Morales Martínez Víctor Hugo
*/
void Insert (lista * l, posicion p, elemento e, boolean b){
	posicion anterior = Previous(l,p);
	posicion siguiente = Following(l,p);
	if (b == TRUE)
	{
		l->tamanio++;
		if (anterior == NULL)
		{
			Final(l)->e = e;
		}else{
			Previous(l,p)->e = e;
		}
	}else{
		l->tamanio++;
		if (siguiente == NULL)
		{
			First(l)->e = e;
		}else{
			Following(l,p)->e = e;
		}
	}
}

/*
Operacion 04: 	Operación de Insercion
void Add (lista *l,elemento e);

Descripción: 	Agrega un elemento al final de la lista
Recibe: 		lista *l (Referencia a la lista "l" a operar)
				elemento e (elemento a insertar)
Devuelve: 		-
Observaciones: 	-
Autor: 			Morales Martínez Víctor Hugo
*/
void Add (lista *l,elemento e)
{
	printf("\nAgregando elemento, numero:\t%i\n",e.n);
	nodo *aux;
	aux=malloc(sizeof(nodo));
	if(aux==NULL)
	{
		printf("\nERROR: Desbordamiento de Lista");
		exit(1);		
	}
	aux->e = e;
	
	if (Empty(l)==1)
	{
		printf("Insertando elemento en fila vacia\n");
		l->final = aux;
		l->frente = aux;
		l->tamanio++;
	}else{
		printf("Insertando elemento\n");
		printf("Elemento final: %i\n",l->final->e.n);
		printf("Elemento : %i\n",aux->e.n);
		aux->siguiente = l->final;
		l->final= aux;
		l->tamanio++;

		//El elemento del final apuntará al nuevo elemento 		
		l->final->siguiente = aux;
		//El final de la lista apuntará al nuevo elemento
		l->final = aux;
	}
}

/*
Operacion 05: 	Operación de Modificadora
void Remove (lista *l,posicion p);

Descripción: 	Elimina la posicion en la lista
Recibe: 		lista *l (Referencia a la lista "l" a operar)
				posicion p (lugar a insertar)
Devuelve: 		-
Observaciones: 	La lista es o vacia y la posicion P es valida
Autor: 			Morales Martínez Víctor Hugo
*/
void Remove (lista *l,posicion p){
	if (Empty(l))
	{
		printf("\nNo se puede eliminar una posicion de una lista vacia\n");
		exit(1);
	}
	
	Previous(l,p)->siguiente = Following(l,p);
	p->siguiente = NULL;
	l->tamanio--;
}

/*
Operacion 06: 	Operación de Modificadora
void Replace (lista *l,posicion p, elemento e);

Descripción: 	Remplaza un elemento en la pocicion dada
Recibe: 		lista *l (Referencia a la lista "l" a operar)
				posicion p (lugar a insertar)
				elemento (elemento a remplazar)
Devuelve: 		-
Observaciones: 	La lista es o vacia y la posicion P es valida
Autor: 			Morales Martínez Víctor Hugo
*/
void Replace (lista *l,posicion p, elemento e){
	if (Empty(l))
	{
		printf("\nNo se puede Remplazar un elemento de una lista vacia\n");
		exit(1);
	}
	p->e = e;
}
