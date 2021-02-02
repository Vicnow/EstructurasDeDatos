//Escuela Superior de Computo 
//Mejia Tovar Luis Giovanni / Marco Antonio Molina Garcia / Victor Hugo Morales 
#include <windows.h>				//Funciona unicamente en Windows para usar la funciÃ³n Sleep()
//#include "TADCola/TADColaEst.h" 	//Si se usa la implemtentaciÃ³n dinÃ¡mica (TADColaDin.c)
#include "TADColaDin.h" 	//Si se usa la implemtentaciÃ³n estÃ¡tica (TADColaEst.c|TADColaEstCirc.c)
#include <time.h> 
#include <stdio.h>
#include <string.h>

//DEFINICION DE CONSTANTES
#define TIEMPO_BASE	2000		//Tiempo base en ms
#define TIEMPO_CLIENTE	3		//Tiempo base en ms * 1
#define TIEMPO_ATENCION	15		//Tiempo base en ms * 3
#define TIEMPO_USUARIO 1
#define TIEMPO_PREFERENTE 3
int main(void)
{
	unsigned int tiempo = 0;
	unsigned int cliente = 0;
	int i,fila, tipo;
    int clase, usuario,preferente;
  	int numCajeras;
	int vaciasCajeras = 0;
	char nombre[40];
	char id[45];
	elemento e;
	//Inicializar la funcion rand
	srand(time(NULL));
	

 
	
  do {
	printf("Cuantas cajas hay operando: ");
  	scanf("%d",&numCajeras);
  } while(!(numCajeras>0 && numCajeras<11));
	  
	//Crear numCajeras colas
  
	cola cajera[numCajeras];
	cola usuarios[1];
	cola clientes[1];
	cola preferentes[1];
	//Inicializar ambas colas

for(i=0;i<numCajeras;i++)
  {
  Initialize(&cajera[i]);
	
  }
  Initialize(&usuarios[0]);
  Initialize(&clientes[0]);
  Initialize(&preferentes[0]);
	
	//Ciclo ininito
    int clienteAtendido=0;

	while (1)
	
	{
		Sleep(TIEMPO_BASE);		//Esperar el tiempo base
		tiempo++;				//Incrementar el contador de tiempo

		
		
		//Mostrar los clientes en cada cola
		printf("\n\n%d Personas en cola clientes: [",Size(&clientes[0]));
		for (int j=1;j<=Size(&clientes[0]);j++)
		{
			e=Element(&clientes[0],j);
			printf("c.%d\t", e.n);
		}
		printf("]");

		printf("\n\n%d Personas en cola usuarios: [",Size(&usuarios[0]));
		for (int j=1;j<=Size(&usuarios[0]);j++)
		{
			e=Element(&usuarios[0],j);
			printf("u.%d\t", e.n);
		}
		printf("]");
		
		printf("\n\n%d Personas en cola preferentes: [",Size(&preferentes[0]));
		for (int j=1;j<=Size(&preferentes[0]);j++)
		{
			e=Element(&preferentes[0],j);
			printf("p.%d\t", e.n);
		}
		printf("]");
		
		for(i=0;i<numCajeras;i++){
			printf("\n\n%d clientes en cola %d: [",Size(&cajera[i]),i+1);
			for (int j=1;j<=Size(&cajera[i]);j++)
			{
				e=Element(&cajera[i],j);
				printf("%s\t", e.id);
			}
			printf("]");
		}

		//Si el tiempo es multiplo del tiempo de atencion        
		if (tiempo % TIEMPO_ATENCION == 0)
		{	
			int contador = 0;
			for(i=0;i<numCajeras;i++){
				if(!Empty(&cajera[i]))
				{
					e = Dequeue(&cajera[i]);
					clienteAtendido++;
					printf("\n\n\nAtendi a: %d en caja %d", e.n,i);
				}
				else
				{
					printf("\n\n\nNo hay alguien por atender en caja %d",i);
					contador++;
				}
			}
			printf("\nCajas vacias= %d",contador);
			if(contador == numCajeras){
				vaciasCajeras = 1;
			}else{
				vaciasCajeras = 0;
			}
		}

		//Si el tiempo es multiplo del de llegada de los clientes
		if (clienteAtendido>100){
			continue;
		}
		else{

			if (tiempo % TIEMPO_CLIENTE == 0){
				cliente++;				//Incrementar el numero de clientes
				e.n = cliente;			//Dar el numero que identifica al cliente
				sprintf(id, "c.%d", cliente);			
				strcpy(e.id,id);	
				Queue(&clientes[0], e);//Formarse en la fila seleccionada
				printf("\nLlego el cliente: %d a la cola de clientes", e.n);
			}

			if (tiempo % TIEMPO_USUARIO == 0){
				usuario++;				//Incrementar el numero de clientes
				e.n = usuario;			//Dar el numero que identifica al cliente		
				sprintf(id, "u.%d", usuario);			
				strcpy(e.id,id);		
				Queue(&usuarios[0], e);//Formarse en la fila seleccionada
				printf("\nLlego el usuario: %d a la cola de usuarios", e.n);
			}

			if (tiempo % TIEMPO_PREFERENTE == 0){
				preferente++;				//Incrementar el numero de clientes
				e.n = preferente;			//Dar el numero que identifica al cliente	
				sprintf(id, "p.%d", preferente);			
				strcpy(e.id,id);				
				Queue(&preferentes[0], e);//Formarse en la fila seleccionada
				printf("\nLlego el preferente: %d a la cola de preferentes", e.n);
			}

			if(Empty(&preferentes[0])){
				if(Empty(&clientes[0])){
					if(!(Empty(&usuarios[0]))){
						fila=rand()%numCajeras;			//Escoger la fila para formarse aleatoriamente					
						if(Size(&cajera[fila])<=10){
							e = Dequeue(&usuarios[0]);
							Queue(&cajera[fila], e);//Formarse en la fila seleccionada
							printf("\nLlego el usuario: %d a la cola de la caja %d", e.n,fila);
						}
					}
				}else{
					fila=rand()%numCajeras;			//Escoger la fila para formarse aleatoriamente		
					if(Size(&cajera[fila])<=10){			
						e = Dequeue(&clientes[0]);
						Queue(&cajera[fila], e);//Formarse en la fila seleccionada
						printf("\nLlego el cliente: %d a la cola de la caja %d", e.n,fila);
					}
				}
			}else{
				fila=rand()%numCajeras;			//Escoger la fila para formarse aleatoriamente
				if(Size(&cajera[fila])<=10){				
					e = Dequeue(&preferentes[0]);
					Queue(&cajera[fila], e);//Formarse en la fila seleccionada
					printf("\nLlego el preferente: %d a la cola de la caja %d", e.n,fila);
				}
			}
		}
		printf("Clientes atendidos=%d",clienteAtendido);
	}   
	return 0;
}


// char + int;

//Punto 2 de la practica

