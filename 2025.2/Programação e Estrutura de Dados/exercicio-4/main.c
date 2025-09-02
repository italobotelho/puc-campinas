#include <stdio.h>
#include <stdlib.h>

int main()
{
    float base, altura, area;
    printf("Vamos calcular a area do triangulo!!!\nInsira o valor da base (cm): ");
    scanf("%f", &base);
    printf("Insira o valor da altura (cm): ");
    scanf("%f", &altura);

    area = (base * altura) / 2;

    printf("Propriedades do calculo do triangulo:\n\tBase: %.2f cm\n\tAltura: %.2f cm\n\tArea: %.2f cm quadrado", base, altura, area);
    return 0;
}
