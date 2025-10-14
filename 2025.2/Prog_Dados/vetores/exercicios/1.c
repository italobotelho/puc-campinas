#include <stdlib.h>
#include <stdio.h>

#define tam 50

int main()
{
    float vetor[tam], s = 0;

    for(int i = 1, j = 1; i <= tam; i++, j=j+2)
    {
        vetor[i] = (float)j / i;
        s += vetor[i];
    }

    printf("S = %.4f", s);

    return 0;
}