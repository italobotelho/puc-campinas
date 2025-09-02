#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hora, minuto_atual, minutos_totais;
    printf("Vamos calcular quantos minutos se passaram desde o inicio do dia!!\n\tInsira o valor da hora atual: ");
    scanf("%d", &hora);
    printf("\tInsira o valor do minuto atual: ");
    scanf("%d", &minuto_atual);

    minutos_totais = minuto_atual + (hora * 60);

    printf("\tSe passaram %d minutos desde o inicio do dia.", minutos_totais);
    return 0;
}
