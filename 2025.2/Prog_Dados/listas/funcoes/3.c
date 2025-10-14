#include <stdio.h>
#include <windows.h>

int eh_divisivel(int x, int y)
{
    if (x % y == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int x, y;

    system("cls");

    printf("Valor de X: ");
    scanf("%d", &x);
    printf("Valor de Y: ");
    scanf("%d", &y);

    printf("Retorno: %d", eh_divisivel(x, y));

    return 0;
}