#include <stdio.h>

int fibonacci(long n);
int main(int argc, char const *argv[])
{
    long flag;
    printf("\nEscribe un numero y te dare el fin de la secuencia fibonacci.\n");
    scanf("%d",&flag);
    printf("\nEl valor de la seccuencia Fibonacci de la posicion %i es:\t: %i\n",flag,fibonacci(flag)); 
    return 0;
}

int fibonacci(long n){
    if (n <= 2){
        return 1; //Caso Base
    }else{
        return (fibonacci(n-1)+fibonacci(n-2));
    }
}

