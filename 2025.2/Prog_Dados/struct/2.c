#include <stdio.h>
#include <windows.h>
#define tam 2

typedef struct Funcionario
{
    int matricula, cargo, dependentes;
    float salario;
} Funcionario;

void le_info_func(Funcionario f[])
{
    for(int i=1; i<=tam; i++)
    {
        printf("- - Funcionario %d - -\n", i);
        printf("Matricula: ");
        scanf("%d", &f[i].matricula);
        printf("Codigo do Cargo: ");
        scanf("%d", &f[i].cargo);
        printf("Quantidade de dependentes: ");
        scanf("%d", &f[i].dependentes);
        printf("Salario (R$): ");
        scanf("%f", &f[i].salario);
        system("cls");
    }
}

void imprime_info_func(Funcionario f[])
{
    for(int i=1; i<=tam; i++)
    {
        printf("- - Funcionario %d - -\n", i);
        printf("Matricula: %d\n", f[i].matricula);
        printf("Codigo do Cargo: %d\n", f[i].cargo);
        printf("Quantidade de dependentes: %d\n", f[i].dependentes);
        printf("Salario (R$): %.2f\n", f[i].salario);
        printf("\n");
    }
}

float media_salarial_func(Funcionario f[])
{
    float media = 0;
    for(int i=1; i<=tam; i++)
    {
        media += f[i].salario;
    }

    media /= tam;

    return media;
}

int matric_func_maior_dependentes(Funcionario f[])
{
    int maior_dep = f[1].dependentes;
    int matricula_func = f[1].matricula;
    for(int i=2; i<=tam; i++)
    {
        if(maior_dep < f[i].dependentes)
        {
            maior_dep = f[i].dependentes;
            matricula_func = f[i].matricula;
        }
    }

    return matricula_func;
}

void matric_cod_func_maior_dep(Funcionario f[], int *matricula, int *cargo)
{
    int pos = 1;

    for(int i=2; i<=tam; i++)
    {
        if(f[pos].dependentes < f[i].dependentes)
        {
            pos = i;
        }
    }

    *matricula = f[pos].matricula;
    *cargo = f[pos].cargo;
}

float media_salarial_func_cargo(Funcionario f[])
{
    //
}

int main()
{
    Funcionario func[tam];
    float media_salarial_total = 0;
    int matric_func, cargo_func;

    le_info_func(func);

    imprime_info_func(func);

    media_salarial_total = media_salarial_func(func);

    matric_func = matric_func_maior_dependentes(func);

    matric_cod_func_maior_dep(func, &matric_func, &cargo_func);

    printf("Funcionario com mais dependentes:\n");
    printf("Matricula: %d\n", matric_func);
    printf("Codigo do cargo: %d\n", cargo_func);

    return 0;
}
