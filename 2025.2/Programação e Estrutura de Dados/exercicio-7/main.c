#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float lado, volume;
    printf("Vamos calcular o volume do cubo!!\nInsira o valor do lado (cm): ");
    scanf("%f", &lado);

    volume = pow(lado, 3);

    printf("Caracteristicas do cubo:\n\tLado: %.1f cm\n\tVolume: %.1f cm cubicos", lado, volume);
    return 0;
}
