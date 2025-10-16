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

int func_maior_dependentes(Funcionario f[])
{
    int maior_dep = f[1].dependentes;
    for(int i=2; i<=tam; i++)
    {
        if(maior_dep < f[i].dependentes)
        {
            maior_dep = f[i].dependentes;
            // continuar daqui
        }
    }
}

float media_salarial_func_cargo(Funcionario f[])
{

}

int main()
{
    Funcionario func[tam];
    float media_salarial_total = 0;

    le_info_func(func);

    imprime_info_func(func);

    media_salarial_total = media_salarial_func(func);



    return 0;
}
