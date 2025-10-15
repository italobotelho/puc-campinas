#include <stdio.h>
#include <windows.h>

float calcular(float x, float y, float z)
{
    return (x*x)+y+z;
}

int main()
{
    float n1, n2, n3, r;

    system("cls");

    printf("Insira o valor de X: ");
    scanf("%f", &n1);
    printf("Insira o valor de Y: ");
    scanf("%f", &n2);
    printf("Insira o valor de Z: ");
    scanf("%f", &n3);

    r = calcular(n1, n2, n3);

    system("cls");
    printf("Resultado: %.2f", r);

    return 0;
}