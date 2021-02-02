
//Escuela Superior de Computo 
//Mejia Tovar Luis Giovanni / Marco Antonio Molina Garcia / Victor Hugo Morales 
//LIBRERAS
#include <string.h>
#include <stdio.h>
#include <windows.h>				//Funciona unicamente en Windows para usar la funciÃ³n Sleep()
//#include "TADCola/TADColaEst.h" 	//Si se usa la implemtentaciÃ³n dinÃ¡mica (TADColaDin.c)
#include "../TADCola/TADColaDin.h" 	//Si se usa la implemtentaciÃ³n estÃ¡tica (TADColaEst.c|TADColaEstCirc.c)
#include <time.h> 

//DEFINICION DE CONSTANTES
#define TIEMPO_BASE   1000		//Tiempo base en ms


int main(void)
{
	unsigned int tiempo = 0;
	unsigned int cliente = 0;
	int i,fila;
  	int numCajeras;
	int vaciasCajeras = 0;
    int numProcesos;
    char nom[45];
    char des[200];
    char id[45];
    char temp;
    int t,tiempoEspera;
	elemento e;
	//Inicializar la funcion rand
	srand(time(NULL));
	
    

  //preguntar al usuario numero de cajeras
  
    printf("Cuantos procesos habra en la cola?\t");
    scanf("%d",&numProcesos);
    cola ejecucion[1];
    cola finalizados[1];
    cola listo[1];
    
    Initialize(&listo[0]);
    Initialize(&ejecucion[0]);
    Initialize(&finalizados[0]);

    tiempoEspera = 0;
    for(i=0;i<numProcesos;i++){
        e.n = i;
        printf("\nCual es el nombre de su proceso numero: %d?\n",i+1);
        scanf("%c",&temp); // temp statement to clear buffer
	    scanf("%[^\n]",e.nomProceso);
        printf("\nCual es descripcion de su proceso numero: %d?\n",i+1);
        scanf("%c",&temp); // temp statement to clear buffer
        scanf("%[^\n]",e.actividad);
        printf("\nCual es el ID de su proceso numero: %d?\n",i+1);
        scanf("%c",&temp); // temp statement to clear buffer
        scanf("%[^\n]",e.id);
        printf("id: %s\n",e.id);
        printf("\nCuantos quantiums toma su proceso numero: %d?\n",i+1);
        scanf("%d",&t);
        t = t * 1000;
        e.tiempo = t; //pasamos tiempo de milisegundos a segundos
        e.tiempoTotal = tiempoEspera + t;
        Queue(&listo[0],e);
        system("cls");
        printf("Proceso Guardado: %s - %s - %s\tTiempo actual: %d\n",e.nomProceso,e.actividad,e.id,e.tiempoTotal+tiempoEspera);
    }

    
    //printf("Tama%ao del la cola listo: %d", 164, Size(&listo[0]));

    e = Front(&listo[0]);
    printf("Proceso Siguiente: %s - %s - %s\tTiempo para finalizar: %d\n",e.nomProceso,e.actividad,e.id,e.tiempo+tiempoEspera);


    for(i=0;i<Size(&listo[0]);i++){
        //Sleep(TIEMPO_BASE);
        e = Dequeue(&listo[0]);
        printf("Proceso Actual: %s - %s - %s\tTiempo actual: %d\n",e.nomProceso,e.actividad,e.id,e.tiempoTotal+tiempoEspera);
        for(int j = e.tiempo; j == 0; j-1000){
            tiempoEspera = tiempoEspera + 1000;
            e.tiempo = e.tiempo - 1000;
        }

        printf("Proceso Actual: %s - %s - %s\tTiempo actual: %d\n",e.nomProceso,e.actividad,e.id,e.tiempoTotal+tiempoEspera);
        if (e.tiempo == 0)
        {
            e.tiempoTotal = tiempoEspera;
            printf("Mandando a finalizados\n");
            Queue(&finalizados[0],e);
        }

        e=Final(&finalizados[0]);
        printf("Proceso Anterior: %s - %s - %s\tTiempo para finalizar: %d\n",e.nomProceso,e.actividad,e.id,e.tiempo+tiempoEspera);
        e=Front(&listo[0]);
        printf("Proceso Siguiente: %s - %s - %s\tTiempo para finalizar: %d\n",e.nomProceso,e.actividad,e.id,e.tiempo+tiempoEspera);
    }

/*
    for(i=0;i<Size(&ejecucion[0]);i++){
        e = Dequeue(&ejecucion[0]);
        Queue(&ejecucion[0],e);
    }
*/
    if (Empty(&listo[0]))
    {
        for(i=0;i<Size(&finalizados[0]);i++){
            e=Dequeue(&finalizados[0]); 
           printf("Proceso: %s - %s - %s\tTiempo Total: %d\n",e.nomProceso,e.actividad,e.id,e.tiempoTotal);
        }
    }
    return 0;
}
    
