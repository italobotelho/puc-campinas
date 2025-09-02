#include <stdio.h>
#include <stdlib.h>

int main()
{
    float lado, altura, perimetro;
    printf("Vamos calcular o perimetro do retangulo!!\nInsira o valor da altura do retangulo: ");
    scanf("%f", &altura);
    printf("Insira o valor do lado do retangulo: ");
    scanf("%f", &lado);

    perimetro = (lado * 2) + (altura * 2);

    printf("Propriedades do calculo do retangulo:\n\tLado: %.2f\n\tAltura: %.2f\n\tPerimetro: %.2f", lado, altura, perimetro);
    return 0;
}
