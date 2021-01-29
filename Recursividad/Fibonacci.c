#include <stdio.h>

int Fibonacci(long n);
int main(int argc, char const *argv[])
{
    long flag;
    printf("\nEscribe un numero y te dare el fin de la secuencia Fibonacci.\n");
    scanf("%d",&flag);
    printf("\nEl valor de la seccuencia Fibonacci de la posicion %i es:\t: %i\n",flag,Fibonacci(flag)); 
    return 0;
}

int Fibonacci(long n){
    if (n <= 2){
        return 1; //Caso Base
    }else{
        return (Fibonacci(n-1)+Fibonacci(n-2));
    }
}

