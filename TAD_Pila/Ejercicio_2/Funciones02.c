/*
IMPLEMENTACIONES DE LA LIBRERIA DEL TAD PILA DINÁMICA (TADPilaDin.h)
AUTOR: Edgardo Adrián Franco Martínez (C) Septiembre 2012
VERSIÓN: 1.3

DESCRIPCIÓN: TAD pila o stack.
Estructura de datos en la que se cumple:
Los elementos se añaden y se remueven por un solo extremo.
Este extremo es llamado “tope” de la pila.

OBSERVACIONES: Hablamos de una Estructura de datos dinámica 
cuando se le asigna memoria a medida que es necesitada, 
durante la ejecución del programa. En este caso la memoria 
no queda fija durante la compilación.

COMPILACIÓN PARA GENERAR EL CÓDIGO OBJETO: gcc TADPilaDin.c -c
*/

//LIBRERAS
#include <stdio.h>
#include <stdlib.h>
#include "../TADPila/TADPilaDin.h"

//DEFINICIÓN DE FUNCIONES

void bubbleSortStack(elemento a[], int n)
{
    pila pila1;
     
    // Push all elements of array in 1st stack
    for(int i = 0; i < n; i++) 
    {
        Push(&pila1,a[i]);
    }
 
    pila pila2;
 
    for(int i = 0; i < n; i++)
    {
        if (i % 2 == 0) 
        {
            while (!Empty(&pila1))
            {
                elemento t = Pop(&pila1);
 
                if (Empty(&pila2)) 
                {
                    Push(&pila2,t);
                }
 
                else
                {
                    // Swapping
                    if (Top(&pila2).i > t.i)
                    {
                        elemento temp = Pop(&pila2);
                        Push(&pila2,t);
                        Push(&pila2,temp);
                    }
                    else
                    {
                        Push(&pila2,t);
                    }
                }
            }
             
            // Tricky step
            a[n - 1 - i] = Pop(&pila2);
        }
 
        else
        {
            while (!Empty(&pila2)) 
            {
                elemento t = Pop(&pila2);
 
                if (Empty(&pila1)) 
                {
                   Push(&pila1,t);
                }
 
                else
                {
                    if (Top(&pila1).i > t.i) 
                    {
                        elemento temp = Pop(&pila1);
                        Push(&pila1,t);
                        Push(&pila1,temp);
                    }
 
                    else
                    {
                        Push(&pila1,t);
                    }
                }
            }
             
            // Tricky step
            a[n - 1 - i] = Pop(&pila1);
        }
    }
     
    printf("[");
    for(int i = 0; i < n; i++)
    {
        printf("|%c,%i|",a[i].c,a[i].i);
    }
    printf("]");
} 