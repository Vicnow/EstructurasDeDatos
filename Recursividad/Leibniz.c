#include <stdio.h>

int Leibniz(int a);
int main(int argc, char const *argv[])
{
    int n1;
    int n2;
    printf("\nEscribe dos numeros y te dare el Maximo comun divisor.\n");
    printf("\nNumero 1:\n");
    scanf("%d",&n1);
    printf("\nNunero 2:\n");
    scanf("%d",&n2);
    printf("\nEl Maximo comun divisor es:\t: %i\n",Leibniz(n1,n2)); 
    return 0;
}

int Leibniz(int a){
    if (a == 0){
        return 1; //Caso Base
    }else{
        
        return;
    }
}

