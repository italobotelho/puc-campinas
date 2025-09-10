#include <stdio.h>
#define TAM 10

int main()
{
    int vetor[TAM], maiorV = 0, maiorP, menorV = 0, menorP;

    printf("vetor[0] : ");
    scanf(" %d", &vetor[0]);
    maiorV = vetor[0];
    menorV = vetor[0];

    for(int i=1; i<TAM; i++)
    {
        printf("vetor[%d] : ", i);
        scanf(" %d", &vetor[i]);

        if(vetor[i] > maiorV)
        {
            maiorV = vetor[i];
            maiorP = i;
        }
        else if(vetor[i] < menorV)
        {
            menorV = vetor[i];
            menorP = i;
        }
    }

    printf("\nMaior valor lido: vetor[%d] = %d\nMenor valor lido: vetor[%d] = %d\n", maiorP, maiorV, menorP, menorV);

    return 0;
}