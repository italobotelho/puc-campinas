#include <stdio.h>
#include <windows.h>
#include <math.h>

int QP(int a)
{
    float raiz;

    raiz = sqrt((float)a);

    if((int)raiz * (int)raiz == a)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int numero, bool;

    system("cls");

    printf("Insira um numero: ");
    scanf("%d", &numero);

    bool = QP(numero);

    system("cls");

    if(bool == 1)
    {
        printf("%d eh um quadrado perfeito", numero);
    }
    else
    {
        printf("%d NAO eh um quadrado perfeito", numero);
    }

    return 0;
}