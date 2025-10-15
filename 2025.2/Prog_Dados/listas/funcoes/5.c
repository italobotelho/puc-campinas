#include <stdio.h>
#include <windows.h>

void pares(int a, int b)
{
    int inicio, fim;

    if(b < a)
    {
        inicio = b;
        fim = a;
    }
    else
    {
        inicio = a;
        fim = b;
    }

    for(int i=inicio; i<=fim; i++)
    {
        if(i % 2 == 0)
        {
            printf(" %d", i);
        }
    }
}

int main()
{
    int n1, n2;

    system("cls");

    printf("Insira o valor de A: ");
    scanf("%d", &n1);
    printf("Insira o valor de B: ");
    scanf("%d", &n2);

    system("cls");
    printf("--- Resultado ---\n\n");
    pares(n1, n2);

    return 0;
}