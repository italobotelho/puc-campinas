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

    float x[TAM], y[TAM], z[TAM];

    printf("\n\tInsira o valor de cada vetor\n");

    for(int i=0; i<TAM; i++)
    {
        printf("\nx[%d] = ", i);
        scanf(" %f", &x[i]);
        printf("\ny[%d] = ", i);
        scanf(" %f", &y[i]);

        z[i] = x[i] * y[i];
    }

    for(int i=0; i<TAM; i++)
    {
        printf("\n%.2f * %.2f = %.2f", x[i], y[i], z[i]);
    }

    return 0;
}