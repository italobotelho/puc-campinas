#include <stdio.h>

int main()
{
    int TAM;

    printf("\tInsira o tamanho do vetor\n\tDeverá ser maior que 0 e menor que 20!!\n\n");
    do
    {
        printf("Tamanho: ");
        scanf(" %d", &TAM);
    }while(TAM < 1 || TAM > 20);

    int x[TAM];

    for(int i=0; i<TAM; i++)
    {
        printf("x[%d] = ", i);
        scanf(" %d", &x[i]);
    }

    printf("\nVetor lido:      ");
    for(int i=0; i<TAM; i++)
    {
        printf(" %d", x[i]);
    }

    printf("\nVetor invertido: ");
    for(int i=TAM-1; i>=0; i--)
    {
        printf(" %d", x[i]);
    }
}
