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

    float x[TAM], soma = 0;

    printf("\n\tInsira o valor de cada vetor\n");

    for(int i=0; i<TAM; i++)
    {
        printf("\nx[%d] = ", i);
        scanf(" %f", &x[i]);

        soma += x[i];
    }
    printf("\n");
    for(int i=0; i<TAM; i++)
    {
        printf("Vetor[%d] = %.2f\n", i, x[i]);
    }

    printf("Somatoria total = %.2f", soma);

    return 0;
}