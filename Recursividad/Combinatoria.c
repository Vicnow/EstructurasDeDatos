#include <stdio.h>

int Combinatoria(int n, int k);
int main(int argc, char const *argv[])
{
    int elementos;
    int posibles;
    printf("\nDame el numero de elementos a posibles (En total).\n");
    scanf("%d",&elementos);
    printf("\nDame el numero de elementos a elegir.\n");
    scanf("%d",&posibles);
    printf("\nLas posibilidades distintas son:\n%i",Combinatoria(elementos,posibles)); 
    return 0;
}

int Combinatoria(int n, int k){
    if (k == 0 || k == n){
        return 1; //Caso Base
    }else{
        return Combinatoria(n-1,k-1) + Combinatoria(n-1,k);
    }
}