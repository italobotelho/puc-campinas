#include <stdio.h>
#include <windows.h>

float calcular_media(float v[], int n)
{
    float media = 0;
    for(int i=1; i<=n; i++)
    {
        media += v[i];
    }

    media /= n;

    return media;
}

int main()
{
    int tam;
    float vetor[tam];

    system("cls");
    printf("Insira a quantidade valores para calcular media: ");
    scanf("%d", &tam);

    printf("-- Insira os valores --\n");

    for(int i=1; i<=tam; i++)
    {
        printf("Valor #%d", i);
        scanf("%f", &vetor[i]);
    }

    system("cls");

    printf("A media dos numeros = %.2f", calcular_media(vetor, tam));

    return 0;
}