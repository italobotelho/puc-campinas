#include <stdio.h>

int inicializa()
{
    return 1;
}

int modifica(int estado)
{
    return --estado;
}

int max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int min(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int avaliacao_a(int estado)
{
    return (estado * estado) + (3 * estado) - 10;
}

int avaliacao_b(int estado)
{
    return max(0, min(estado, 10) + 5 * estado);
}

void selecionar(int *ptr_s, int h_atual, int *ptr_v, int h_vizinho)
{
    int s = *ptr_s;
    int v = *ptr_v;
    
    if (h_vizinho < h_atual)
    {
        s = v;
    }

    *ptr_s = s;
    *ptr_v = v;
}

int main()
{
    int s, v;
    
    s = inicializa();
    
    while(1)
    {
        v = modifica(s);
    
        printf("Estado = %d, Avaliacao = %d | Vizinho = %d, Avaliacao = %d\n", s, avaliacao_b(s), v, avaliacao_b(v));   

        selecionar(&s, avaliacao_b(s), &v, avaliacao_b(v));

        if (s != v)
        {
            break;
        }
    }

    // printf("------------------------------------------------------------------\n");
    // printf("   Estado promissor para 'f(x) = x^2 + 3 * x - 10'  ==>  [ %d ]\n", s);
    // printf("------------------------------------------------------------------");

    printf("----------------------------------------------------------------------------\n");
    printf("     !!!  Busca Local (Hill Climbing) - Otimizacao por Minimizacao  !!!     \n");
    printf("----------------------------------------------------------------------------\n");
    printf("   Estado promissor para 'f(x) = MAX(0, MIN(x, 10) + 5 * x)'  ==>  [ %d ]   \n", s);
    printf("----------------------------------------------------------------------------");

    return 0;
}