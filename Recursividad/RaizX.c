#include <stdio.h>

double RaizX(double x);
int main(int argc, char const *argv[])
{
    float n1;
    float n2;
    printf("\nEscribe un numero y te dare su raiz cudrada.\n");
    printf("\nNumero:\n");
    scanf("%f",&n1);
    printf("\nLa raiz es:\t: %f\n",RaizX(n1)); 
    return 0;
}

double RaizX(double x){
    if (x <= 1){
        return 1; //Caso Base
    }else{
        x = 1+((x-1)/(1+RaizX(x)));
        return x;
    }
}

