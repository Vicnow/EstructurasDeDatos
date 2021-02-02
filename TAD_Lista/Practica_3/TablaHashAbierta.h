//Autor: Morales Martinez Victor Hugo
//Observaciones: Exactaente igual que TADLista solo que con modificaciones en la estructura elemento.
#define TRUE 1
#define FALSE 0

typedef unsigned char boolean;

typedef struct elemento
{
	//Lo que gustes	
	char palabra[101];
	char definicion[251];
    char definicion2[251];
}elemento;

//Estructura de un NODO SIMPLEMENTE LIGADO
typedef struct nodo
{
	elemento e;

	struct nodo *siguiente;		
} nodo;

//Se define una posicion como un apuntador a nodo
typedef nodo* posicion;

//Estructura de una lista
typedef struct lista
{
	int tamanio;
	posicion frente; //nodo * frente;
	posicion final;
}lista;

void Initialize (lista *l);
void Destroy (lista *l);
posicion Final (lista *l);
posicion First (lista *l);
posicion Following (lista *l,posicion p);
posicion Previous (lista *l,posicion p);
posicion Search (lista *l,elemento e);
elemento Position (lista *l,posicion p);
boolean ValidatePosition (lista *l,posicion p);
posicion ElementPosition(lista *l, int n);
elemento Element(lista *l, int n);
int Size (lista *l);
boolean Empty (lista *l);
void Insert (lista * l, posicion p, elemento e, boolean b);
void Add (lista *l,elemento e);
void Remove (lista *l,posicion p);
void Replace (lista *l,posicion p, elemento e);
//void VerLigasLista(lista *l);
