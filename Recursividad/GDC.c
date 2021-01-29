#include <stdio.h>

int GCD(int a, int b);
int main(int argc, char const *argv[])
{
    int n1;
    int n2;
    printf("\nEscribe dos numeros y te dare el Maximo comun divisor.\n");
    printf("\nNumero 1:\n");
    scanf("%d",&n1);
    printf("\nNunero 2:\n");
    scanf("%d",&n2);
    printf("\nEl Maximo comun divisor es:\t: %i\n",GCD(n1,n2)); 
    return 0;
}

int GCD(int a, int b){
    if (b == 0){
        return a; //Caso Base
    }else{
        return (GCD(b,a%b));
    }
}

