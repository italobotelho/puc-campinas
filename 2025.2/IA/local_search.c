#include <stdio.h>

int inicializa()
{
    return 10;
}

int modifica(int estado)
{
    return --estado;
}

void selecionar(int h_vizinho, int h_atual, int *ptr_s, int *ptr_v)
{
    int s = *ptr_s;
    int v = *ptr_v;
    
    if(h_vizinho < h_atual)
    {
        s = v;
    }
}

int avaliacao(int estado)
{
    return (estado ^ 2) + (3 * estado) - 10;
}

int main()
{
    int s, v;
    
    s = inicializa();
    
    while(s != 0)
    {
        v = modifica(s);
        
        selecionar(avaliacao(v), avaliacao(s));
    }

    return 0;
}
