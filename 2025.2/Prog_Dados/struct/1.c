#include <stdio.h>
#include <windows.h>
#define tam 10

typedef struct aluno
{
    int ra, cod_disciplina;
    float notas[2];
} al;

int main()
{
    struct aluno a[tam];

    for(int i=0; i<tam; i++)
    {
        printf("RA: ");
        scanf("%d", &a[i].ra);
        printf("Código Disciplina: ");
        scanf("%d", &a[i].cod_disciplina);
        for(int j=1; j<=2; j++)
        {
            printf("Insira a nota da P%d", j);
            scanf("%f", &a[i].notas[j]);
        }
    }
}