#include <stdio.h>
#include <windows.h>

int soma_algarismo_fatorial(int numero)
{
    int fatorial = 1, soma = 0;
    for(int i=numero; i>1; i--)
    {
        fatorial *= i;
    }

    while(fatorial > 0)
    {
        soma += fatorial % 10;
        fatorial /= 10;
    }

    return soma;
}

int main()
{
    int num, soma;

    system("cls");

    printf("Insira um numero: ");
    scanf("%d", &num);

    printf("\nA soma dos algarismos de %d! = %d", num, soma_algarismo_fatorial(num));

    return 0;
}