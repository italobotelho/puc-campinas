#include <stdio.h>
#include <windows.h>

float media_maior_menor(float a, float b, float c, float *media, float *pt_maior, float *pt_menor)
{
    *media = (a + b + c) / 3;
}

int main()
{
    float n1, n2, n3, media, maior, menor;

    printf("Insira um valor:");
    scanf("%f", &n1);
    printf("Insira um valor:");
    scanf("%f", &n2);
    printf("Insira um valor:");
    scanf("%f", &n3);

    media_maior_menor(n1, n2, n3, &media, &maior, &menor);
    printf("Média: %.2f\nMaior: %.2f\nMenor: %.2f", media, maior, menor);

    return 0;
}