#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct Produto {
    int id;
    float preco;
    int quantidade;
} Produto;

Produto* le_produto(int tam)
{
    Produto *p;
    p = (Produto *)malloc(tam*sizeof(Produto));

    for(int i=0; i<tam; i++)
    {
        printf("Leitura %d\n", i);
        printf("Id: ");
        scanf("%d", &p[i].id);
        printf("Preço (R$): ");
        scanf("%f", &p[i].preco);
        printf("Quantidade: ");
        scanf("%d", &p[i].quantidade);
        system("cls");
    }
    return p;
}

int main()
{
    Produto *p;
    int tamanho;

    printf("Quantos produtos deseja cadastrar?\n=> ");
    scanf("%d", &tamanho);

    p = le_produto(tamanho);

    for(int i=0; i<tamanho; i++)
    {
        printf("Id: %d\nPreço(R$): %.2f\nQuantidade: %d\n\n", p[i].id, p[i].preco, p[i].quantidade);
    }

    free(p);
    
    return 0;
}
