#include <stdio.h>
#include "../TADLista/TADLista.h"

int main(){
    lista mi_lista;
    Initialize(&mi_lista);

    elemento e;
    
    printf("\nTamanano de la lista:\t%i\n",Size(&mi_lista));
    printf("\nPila Vacia:\t%i\n",Empty(&mi_lista));

    for(int i=0;i<3;i++)
	{
		printf("\nDame el %d numero entero: ",i+1);
		scanf("%d",&e.n);
		Add(&mi_lista,e);
	}


    printf("\nTamanano de la lista:\t%i\n",Size(&mi_lista));
    printf("Lista:\n");
    printf("Primer Elemento:\t%i\n",Element(&mi_lista,1).n);
    printf("Ultimo Elemento:\t%i\n",Element(&mi_lista,Size(&mi_lista)).n);

    

    return 0;
}