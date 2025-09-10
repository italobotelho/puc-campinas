#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, triplo, dobro, soma;
    printf("Insira um numero: ");
    scanf("%d", &num);

    triplo = num * 3;
    triplo++;
    dobro = num * 2;
    dobro--;

    soma = triplo + dobro;

    printf("Indice:\n\tNumero: %d\n\tSucessor do triplo: %d\n\tAntecessor do dobro: %d\n\tResultado da soma: %d", num, triplo, dobro, soma);
    return 0;
}
