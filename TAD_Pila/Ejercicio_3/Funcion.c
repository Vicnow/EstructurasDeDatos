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
#include "../TADPila/TADPilaEst.h"

//DEFINICIÓN DE FUNCIONES

void infijoPosfijoPasos(char c[],int size){
    pila aux;
    Initialize(&aux);
    /*
    Jerarquia = ()
                ^
                *   /
                +   -
    */
    pila mi_pila;
    Initialize(&mi_pila);
    elemento e;

    for (int i = 0; i < size; i++)
    {
        //Pruebas
        printf("\nCaracter=\t%c\n",c[i]);
        if (c[i] == '('){
            e.c = '(';
            Push(&mi_pila,e);
        }
        if (c[i] == ')'){
            if(Top(&mi_pila).c!='('){
                do
                {
                    e = Pop(&mi_pila);
                    Push(&aux,e);
                } while (Top(&mi_pila).c !='(');
            }
            Pop(&mi_pila);
        }
        if (c[i] == '^')
        {   
            if (Empty(&mi_pila))
            {
                e.c = c[i];
                Push(&mi_pila,e);
            }
            e.c = c[i];
            if (Top(&mi_pila).c == '^')
            {
                Push(&aux,e);       
            }
            if (Top(&mi_pila).c == '*' || Top(&mi_pila).c == '/' || Top(&mi_pila).c == '+' || Top(&mi_pila).c == '-'){
                Push(&mi_pila,e);
            }
        }
        if (c[i] == '*' || c[i]== '/')
        {   
            if (Empty(&mi_pila))
            {
                e.c = c[i];
                Push(&mi_pila,e);
                continue;
            }
                if(Top(&mi_pila).c == '('){
                e.c = c[i];
                Push(&mi_pila,e);
                continue;
            }
            if (Top(&mi_pila).c == '*' || Top(&mi_pila).c == '/' || Top(&mi_pila).c == '^')
            {
                e = Pop(&mi_pila);
                Push(&aux,e);
                e.c = c[i];
                Push(&mi_pila,e);
            }
            if (Top(&mi_pila).c == '+' || Top(&mi_pila).c == '-'){
                e.c = c[i];
                Push(&mi_pila,e);
            }
        }
        if (c[i] == '+' || c[i]== '-')
        {   
            if (Empty(&mi_pila))
            {
                e.c = c[i];
                Push(&mi_pila,e);
                continue;
            }
            if(Top(&mi_pila).c == '('){
                e.c = c[i];
                Push(&mi_pila,e);
                continue;
            }
            if (Top(&mi_pila).c == '*' || Top(&mi_pila).c == '/' || Top(&mi_pila).c == '^'||Top(&mi_pila).c == '+' || Top(&mi_pila).c == '-')
            {
                int flag = 0;
                while (!Empty(&mi_pila) && flag == 0)
                { 
                    if(Top(&mi_pila).c != '('){
                    printf("Tope de pila: %c\n",Top(&mi_pila).c);
                    e = Pop(&mi_pila);
                    printf("Metiendo en aux %c\n",e.c);
                    Push(&aux,e);
                    }else{
                        flag = 1;
                    }
                }
                e.c = c[i];
                Push(&mi_pila,e);
            }
        }
        if (c[i] != '(' && c[i] != ')' && c[i] != '^' && c[i] != '*' && c[i] != '/' && c[i] != '+' && c[i]!= '-'){
            e.c = c[i];
            Push(&aux,e);
        }
        //Pruebas
        printf("Posfijo\t\t[");
        for (int i = 1; i <= Size(&aux); i++)
        {
            e = Element(&aux,i);
            printf("%c",e.c);
        }
        printf("]\n");
        printf("pila\t\t[");
        for (int i = 1; i <= Size(&mi_pila); i++)
        {
            e = Element(&mi_pila,i);
            printf("%c",e.c);
        }
        printf("]\n");
    }
    //Vaciamos la pila de operandos
    while (!Empty(&mi_pila))
    {
        e = Pop(&mi_pila);
        Push(&aux,e);
    }
    
    printf("\nFin de Caracteres\n");
    printf("Infijo: \t[");
    for (int i = 0; i <= size; i++)
    {
        printf("%c",c[i]);
    }
    printf("]\n");
    printf("Posfijo: \t[");
    for (int i = 0; i <= Size(&aux); i++)
    {
        e = Element(&aux,i);
        printf("%c",e.c);
        c[i] = e.c;
    }
    printf("]");
}

void infijoPosfijo(char c[],int size){
    pila aux;
    Initialize(&aux);
    /*
    Jerarquia = ()
                ^
                *   /
                +   -
    */
    pila mi_pila;
    Initialize(&mi_pila);
    elemento e;

    for (int i = 0; i < size; i++)
    {
        if (c[i] == '('){
            e.c = '(';
            Push(&mi_pila,e);
        }
        if (c[i] == ')'){
            if(Top(&mi_pila).c!='('){
                do
                {
                    e = Pop(&mi_pila);
                    Push(&aux,e);
                } while (Top(&mi_pila).c !='(');
            }
            Pop(&mi_pila);
        }
        if (c[i] == '^')
        {   
            if (Empty(&mi_pila))
            {
                e.c = c[i];
                Push(&mi_pila,e);
            }
            e.c = c[i];
            if (Top(&mi_pila).c == '^')
            {
                Push(&aux,e);       
            }
            if (Top(&mi_pila).c == '*' || Top(&mi_pila).c == '/' || Top(&mi_pila).c == '+' || Top(&mi_pila).c == '-'){
                Push(&mi_pila,e);
            }
        }
        if (c[i] == '*' || c[i]== '/')
        {   
            if (Empty(&mi_pila))
            {
                e.c = c[i];
                Push(&mi_pila,e);
                continue;
            }
                if(Top(&mi_pila).c == '('){
                e.c = c[i];
                Push(&mi_pila,e);
                continue;
            }
            if (Top(&mi_pila).c == '*' || Top(&mi_pila).c == '/' || Top(&mi_pila).c == '^')
            {
                e = Pop(&mi_pila);
                Push(&aux,e);
                e.c = c[i];
                Push(&mi_pila,e);
            }
            if (Top(&mi_pila).c == '+' || Top(&mi_pila).c == '-'){
                e.c = c[i];
                Push(&mi_pila,e);
            }
        }
        if (c[i] == '+' || c[i]== '-')
        {   
            if (Empty(&mi_pila))
            {
                e.c = c[i];
                Push(&mi_pila,e);
                continue;
            }
            if(Top(&mi_pila).c == '('){
                e.c = c[i];
                Push(&mi_pila,e);
                continue;
            }
            if (Top(&mi_pila).c == '*' || Top(&mi_pila).c == '/' || Top(&mi_pila).c == '^'||Top(&mi_pila).c == '+' || Top(&mi_pila).c == '-')
            {
                int flag = 0;
                while (!Empty(&mi_pila) && flag == 0)
                { 
                    if(Top(&mi_pila).c != '('){
                    e = Pop(&mi_pila);
                    Push(&aux,e);
                    }else{
                        flag = 1;
                    }
                }
                e.c = c[i];
                Push(&mi_pila,e);
            }
        }
        if (c[i] != '(' && c[i] != ')' && c[i] != '^' && c[i] != '*' && c[i] != '/' && c[i] != '+' && c[i]!= '-'){
            e.c = c[i];
            Push(&aux,e);
        }
    }
    //Vaciamos la pila de operandos
    while (!Empty(&mi_pila))
    {
        e = Pop(&mi_pila);
        Push(&aux,e);
    }
    printf("Infijo: \t[");
    for (int i = 0; i <= size; i++)
    {
        printf("%c",c[i]);
    }
    printf("]\n");
    printf("Posfijo: \t[");
    for (int i = 0; i <= Size(&aux); i++)
    {
        e = Element(&aux,i);
        printf("%c",e.c);
        c[i] = e.c;
    }
    printf("]");
}