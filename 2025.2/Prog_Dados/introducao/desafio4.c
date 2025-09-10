#include <stdio.h>
#include <stdlib.h>

int main()
{
    float sal_min, sal, qtd_sal_min;

    printf("Vamos calcular quantos salarios minimos uma pessoa ganha!!\n\tInsira o salario minimo atual (R$): ");
    scanf("%f", &sal_min);
    printf("\tInsira o salario dessa pessoa (R$): ");
    scanf("%f", &sal);

    qtd_sal_min = sal / sal_min;

    printf("Indice:\n\tSalario minimo: R$ %.f\n\tSalario avaliado: R$ %.f\n\tTotal de %.1f salario(s) minimo(s)", sal_min, sal, qtd_sal_min);
    return 0;
}
