
//Escuela Superior de Computo 
//Mejia Tovar Luis Giovanni / Marco Antonio Molina Garcia / Victor Hugo Morales 
#include <windows.h>				//Funciona unicamente en Windows para usar la funciÃ³n Sleep()
//#include "TADCola/TADColaEst.h" 	//Si se usa la implemtentaciÃ³n dinÃ¡mica (TADColaDin.c)
#include "../TADCola/TADColaDin.h" 	//Si se usa la implemtentaciÃ³n estÃ¡tica (TADColaEst.c|TADColaEstCirc.c)
#include <time.h> 
#include <stdio.h>
//DEFINICION DE CONSTANTES
#define TIEMPO_BASE	1500		//Tiempo base en ms
#define TIEMPO_CLIENTE	1		//Tiempo base en ms * 1
#define TIEMPO_ATENCION	6		//Tiempo base en ms * 3

int main(void)
{
	unsigned int tiempo = TIEMPO_BASE;
	unsigned int cliente = TIEMPO_CLIENTE;
	int i,fila;
  	int numCajeras;
	int vaciasCajeras = 0;
	char nombre[40];
	elemento e;
	//Inicializar la funcion rand
	srand(time(NULL));
	

  //preguntar al usuario numero de cajeras
	printf("Como se llama el Super Mercado?\n");
	scanf("%s",&nombre);
	printf("Cuantas cajeras hay operando:\t");
  	scanf("%d",&numCajeras);
	  
	//Crear numCajeras colas
  
	cola cajera[numCajeras];
	
	//Inicializar ambas colas

for(i=0;i<numCajeras;i++)
  {
  Initialize(&cajera[i]);
	
  }
	
	
	//Ciclo finito
    int clienteAtendido=0;

	while (vaciasCajeras==0)
	
	{
		Sleep(TIEMPO_BASE);		//Esperar el tiempo base
		tiempo++;				//Incrementar el contador de tiempo
		//Mostrar los clientes en cada cola
		for(i=0;i<numCajeras;i++){
			printf("\n\n[Cola No.%d, No. clientes = %d]\t",i+1,Size(&cajera[i]));
			printf("[");
			for (int j=1;j<=Size(&cajera[i]);j++)
			{
				e=Element(&cajera[i],j);
				printf("%d\t", e.n);
			}
			printf("]");
		}
		Sleep(1000);
		system("cls");
		//Si el tiempo es multiplo del tiempo de atencion        
		if (tiempo % TIEMPO_ATENCION == 0)
		{	
			int contador = 0;
			for(i=0;i<numCajeras;i++){
				if (!Empty(&cajera[i]))
				{
					e = Dequeue(&cajera[i]);
					clienteAtendido++;
					printf("\n\n*********** Atendi a: %d en caja %d", e.n,i);
				}
				else
				{
					printf("\n\n*********** No hay alguien por atender en caja %d",i);
					contador++;
				}
			}
			printf("\n\nCajas vacias= %d",contador);
			if(contador == numCajeras){
				vaciasCajeras = 1;
			}else{
				vaciasCajeras = 0;
			}
		}

		//Si el tiempo es multiplo del de llegada de los clientes
		if (clienteAtendido>10){
			continue;
		}
		else{
			if (tiempo % TIEMPO_CLIENTE == 0){
				cliente++;				//Incrementar el numero de clientes
				e.n = cliente;			//Dar el numero que identifica al cliente
				fila=rand()%numCajeras;			//Escoger la fila para formarse aleatoriamente					
				Queue(&cajera[fila], e);//Formarse en la fila seleccionada
				printf("\n\n*********** Llego el cliente: %d a la cola de la caja %d", e.n,fila);
			}
		}

		printf("\n*********** Clientes Atendidos= %d",clienteAtendido);
	}   
	return 0;
}




//Punto 2 de la practica

