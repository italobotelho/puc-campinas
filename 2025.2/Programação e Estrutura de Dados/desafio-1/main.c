#include <stdio.h>
#include <stdlib.h>

int main()
{
    float larg, comp, area;
    printf("Vamos calcular a area do terreno!!!\nInsira o valor da largura: ");
    scanf("%f", &larg);
    printf("Insira o valor do comprimeto: ");
    scanf("%f", &comp);

    area = comp * larg;

    printf("Propriedades do terreno:\n\tLargura: %.2f metros\n\tComprimento: %.2f metros\n\tArea: %.2f metros quadrados", larg, comp, area);
    return 0;
}
