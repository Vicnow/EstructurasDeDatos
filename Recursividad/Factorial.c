#include <stdio.h>

long factorial(long n);
int main(int argc, char const *argv[])
{
    long flag;
    printf("\nEscribe un numero y te dare el factorial.\n");
    scanf("%d",&flag);
    printf("\nEl factorial de %i es:\t: %i",flag,factorial(flag)); 
    return 0;
}

long factorial(long n){
    if (n == 0){
        return 1; //Caso Base
    }else{
        return (n * factorial(n-1));
    }
}

