#include <stdio.h>
#include <stdlib.h>

int main()
{
    int seg, min, hora, resto_hora, novo_seg;
    printf("Insira um valor em segundos: ");
    scanf("%d", &seg);

    hora = seg / 3600;
    resto_hora = seg - (hora * 3600);
    min = resto_hora / 60;
    novo_seg = resto_hora - (min * 60);

    printf("%d segundos resulta em %d horas, %d minutos e %d segundos", seg, hora, min, novo_seg);
    return 0;
}
