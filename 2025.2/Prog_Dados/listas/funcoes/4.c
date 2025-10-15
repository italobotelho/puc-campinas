#include <stdio.h>
#include <windows.h>

float media_maior_menor(float a, float b, float c, float *media, float *pt_maior, float *pt_menor)
{
    *media = (a + b + c) / 3;

    float maior = a, menor = a;
    
    if(b > maior)
    {
        maior = b;
    }
    else if(c > maior)
    {
        maior = c;
    }

    if(b < menor)
    {
        menor = b;

    }
    else if(c < menor)
    {
        menor = c;
    }

    *pt_maior = maior;
    *pt_menor = menor;
}

int main()
{
    float n1, n2, n3, media, maior, menor;

    system("cls");

    printf("Insira um valor: ");
    scanf("%f", &n1);
    printf("Insira um valor: ");
    scanf("%f", &n2);
    printf("Insira um valor: ");
    scanf("%f", &n3);

    system("cls");

    media_maior_menor(n1, n2, n3, &media, &maior, &menor);
    printf("--- Resultados ---\n\nMedia: %.2f\nMaior: %.2f\nMenor: %.2f", media, maior, menor);

    return 0;
}