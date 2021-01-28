#include <stdio.h>
#include "../TADLista/TADLista.h"

int main(){
    lista mi_lista;
    Initialize(&mi_lista);

    elemento e;
    
    for(int i=0;i<3;i++)
	{
		printf("\nDame el %d numero entero: ",i+1);
		scanf("%d",&e.n);
		Add(&mi_lista,e);
	}


    printf("\nTamanano de la lista:\t%i\n\n",Size(&mi_lista));
    printf("Lista:\n");
    printf("[");
    for (int i = 1; i <= Size(&mi_lista); i++)
    {
        printf("\t%i\t",Element(&mi_lista,i));
    }
    printf("]\n");
    
    printf("\nInsertando n = '20' alado del ultimo elemento\t\n");
    e.n = 20;
    Insert(&mi_lista,Final(&mi_lista),e,FALSE);
    
    printf("[");
    for (int i = 1; i <= Size(&mi_lista); i++)
    {
        printf("\t%i\t",Element(&mi_lista,i));
    }
    printf("]\n");

    printf("\nRemover el Primer elemento\t\n");
    e.n = 20;
    Remove(&mi_lista,First(&mi_lista));
    
    printf("[");
    for (int i = 1; i <= Size(&mi_lista); i++)
    {
        printf("\t%i\t",Element(&mi_lista,i));
    }
    printf("]\n");

	printf("\nIngresa 3 elementos nuevos");
    for(int i=0;i<3;i++)
	{
		printf("\nDame el %d numero entero: ",i+1);
		scanf("%d",&e.n);
		Add(&mi_lista,e);
	}

    printf("Lista:\n");
    printf("[");
    for (int i = 1; i <= Size(&mi_lista); i++)
    {
        printf("\t%i\t",Element(&mi_lista,i));
    }
    printf("]\n");
    int opc;
    printf("\nQuieres Eliminar o Agregar? (1/0)\n");
    scanf("%i",&opc);
    if (opc == 1)
    {
        printf("\nDame el elemento a eliminar?\n");
        scanf("%i",&e.n);
        Remove(&mi_lista,Search(&mi_lista,e));
    }else{
        elemento eaux;
        printf("\nDame el elemento a agregar?\n");
        scanf("%i",&e.n);
        printf("\nAlado de Que elemento lo agregamos??\n");
        scanf("%i",&eaux.n);
        Insert(&mi_lista,Search(&mi_lista,eaux),e,FALSE);
    }

    printf("Lista:\n");
    printf("[");
    for (int i = 1; i <= Size(&mi_lista); i++)
    {
        printf("\t%i\t",Element(&mi_lista,i));
    }
    printf("]\n");
    
    return 0;
}