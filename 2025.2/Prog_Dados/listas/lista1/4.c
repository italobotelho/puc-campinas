#include <stdio.h>

int main()
{
    int anos, qtd;
    float preco;

    printf("Ha quantos anos voce eh fumante? => ");
    scanf(" %d", &anos);
    printf("\nQuantos cigarros por dia? => ");
    scanf(" %d", &qtd);
    printf("\nQual o preco de uma cartela? => ");
    scanf(" %f", &preco);

    qtd = (365 * anos) * qtd;
    
    preco *= qtd;

    printf("Total gasto no periodo de %d ano(s):\n\tR$ %.2f", anos, preco);

    return 0;
}