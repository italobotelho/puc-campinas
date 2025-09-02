#include <stdio.h>
#include <stdlib.h>

int main()
{
    float primeiro, segundo, terceiro, premio;
    printf("Vamos dividir o premio entre os ganhadores!\nInsira o valor do premio total (R$): ");
    scanf("%f", &premio);

    primeiro = premio * 0.42;
    segundo = premio * 0.36;
    terceiro = premio - (primeiro + segundo);

    printf("Divisao do premio:\n\tPremio: R$ %.2f\n\tPrimeiro: R$ %.2f\n\tSegundo: R$ %.2f\n\tTerceiro: R$ %.2f", premio, primeiro, segundo, terceiro);
    return 0;
}
