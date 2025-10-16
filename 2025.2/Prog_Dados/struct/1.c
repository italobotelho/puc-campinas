#include <stdio.h>
#include <windows.h>
#define tam 10

// Falta inserir requisitos de parametros

struct aluno
{
    int ra, cod_disciplina;
    float notas[2];
};

float media_final(float nota1, float nota2)
{
    float media = 0;

    media = ((nota1 * 1) + (nota2 * 2)) / 3;

    return media;
}

int main()
{
    struct aluno a[tam];

    for(int i=1; i<=tam; i++)
    {
        printf("- - Aluno %d - -\n", i);
        printf("RA: ");
        scanf("%d", &a[i].ra);
        printf("Codigo Disciplina: ");
        scanf("%d", &a[i].cod_disciplina);
        
        for(int j=1; j<=2; j++)
        {
            printf("Insira a nota da P%d: ", j);
            scanf("%f", &a[i].notas[j]);
        }
        system("cls");
    }

    for(int k=1; k<=tam; k++)
    {
        printf("RA: %d -> Media: %.1f\n", a[k].ra, media_final(a[k].notas[1], a[k].notas[2]));
    }

    return 0;
}