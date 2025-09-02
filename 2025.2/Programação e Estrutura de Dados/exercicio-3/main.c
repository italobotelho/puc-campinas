#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hora, min;
    printf("Insira um valor de horas: ");
    scanf("%d", &hora);

    min = hora * 60;

    printf("%d hora(s) sao exatamente %d minutos", hora, min);
    return 0;
}
