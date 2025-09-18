#include <stdio.h>
#define tam 5

void imprime_lab(char labirinto[tam][tam], int linha, int coluna)
{
    for(int i=0; i<tam; i++) //inicialização
    {
        for(int j=0; j<tam; j++)
        {
            labirinto[i][j] = '.';
        }
    }

    labirinto[1][1] = labirinto[2][1] = labirinto[4][1] = labirinto[0][3] = labirinto[1][3] = labirinto[3][3] = '#'; // posições paredes

    labirinto[linha][coluna] = 'S'; // posição S

    for(int i=0; i<tam; i++) //impressão
    {
        for(int j=0; j<tam; j++)
        {
            printf("%c\t", labirinto[i][j]);
        }
        printf("\n");
    }
}

int posicao_robo(linha, coluna)
{
    
}

int main()
{
    char labirinto[tam][tam]; // aloca a matriz
    int linha = 0, coluna = 0;
    
    imprime_lab(labirinto, linha, coluna);

    // scanf(" %c", &movimento);
    
    return 0;
}