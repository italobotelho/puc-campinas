#include <stdio.h>
#define TAM 15

int main()
{
    int vetor[TAM], qtd_par = 0, qtd_m5 = 0;

    printf("!!!! Este programa aceita somente numeros positivos !!!!\n\n");

    for(int i=0; i<TAM; i++)
    {
        do
        {
            printf("vetor[%d] = ", i);
            scanf(" %d", &vetor[i]);
        }
        while(vetor[i] < 0);

        if(vetor[i] % 2 == 0)
        {
            qtd_par++;
        }

        if(vetor[i] % 5 == 0)
        {
            qtd_m5++;
        }
    }

    printf("\nQtd Pares: %d\nQtd Multiplos de 5: %d\n", qtd_par, qtd_m5);

    return 0;
}