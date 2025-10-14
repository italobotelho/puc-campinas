#include <stdio.h>
#include <windows.h>

int horas_to_segundos(int h, int m, int s)
{
    return (h * 60 * 60) + (m * 60) + s;
}

int main()
{
    int hora, minuto, segundo, conversao_seg;

    system("cls");

    printf("Insira as horas: ");
    scanf("%d", &hora);
    printf("Insira os minutos: ");
    scanf("%d", &minuto);
    printf("Insira os segundos: ");
    scanf("%d", &segundo);

    printf("%d hora(s), %d minuto(s) e %d segundo(s) equivalem a %d segundo(s).", hora, minuto, segundo, conversao_seg = horas_to_segundos(hora, minuto, segundo));

    return 0;
}