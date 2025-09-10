#include <stdio.h>
#include <stdlib.h>

int main()
{
    float sal_atual, sal_novo, perc_reajuste;
    printf("Vamos calcular o reajuste salarial de um funcionario!!!\nInsira o salario atual do funcionario (R$): ");
    scanf("%f", &sal_atual);
    printf("Insira o percentual de reajuse (%%): ");
    scanf("%f", &perc_reajuste);

    sal_novo = sal_atual + (sal_atual * perc_reajuste / 100);

    printf("Indice do reajuste:\n\tSalario Atual: R$ %.2f\n\tPercentual de Reajuste: %.2f %%\n\tSalario Reajustado: R$ %.2f", sal_atual, perc_reajuste, sal_novo);
    return 0;
}
