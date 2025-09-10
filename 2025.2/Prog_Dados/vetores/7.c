#include <stdio.h>
#define TAM 10

int main()
{
    int A[TAM], qtd_menor_media = 0, media = 0;

    for(int i=0; i<TAM; i++)
    {
        printf("Idade %d => ", i+1);
        scanf(" %d", &A[i]);

        media += A[i];
    }

    media /= TAM;

    for(int i=0; i<TAM; i++)
    {
        if(A[i] < media)
        {
            qtd_menor_media++;
        }
    }

    printf("\nIdade Media: %d anos\nQtd menores que a media: %d\n", media, qtd_menor_media);

    return 0;
}