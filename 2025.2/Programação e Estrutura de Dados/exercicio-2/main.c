#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, ant, suc;
    printf("Insira um numero: ");
    scanf("%d", &num);

    suc = num + 1;
    ant = num - 1;

    printf("\tNumero: %d\n\tSucessor: %d\n\tAntecessor: %d", num, suc, ant);
    return 0;
}
