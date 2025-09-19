#include <stdio.h>
#include <stdlib.h>
#define tam 5

void limpar_tela() 
{
    printf("\033[2J\033[H");
}

void inicializa_labirinto(char labirinto[tam][tam])
{
    for(int i=0; i<tam; i++)
    {
        for(int j=0; j<tam; j++)
        {
            labirinto[i][j] = '.';
        }
    }

    // Posições das paredes e objetivo (nao mudam durante o jogo)
    labirinto[1][1] = labirinto[2][1] = labirinto[4][1] = labirinto[0][3] = labirinto[1][3] = labirinto[3][3] = '#';
    labirinto[3][4] = 'G';
}

void renderiza_labirinto(char labirinto[tam][tam], int linha_robo, int coluna_robo)
{
    char celula_anterior = labirinto[linha_robo][coluna_robo];
    labirinto[linha_robo][coluna_robo] = 'S';

    int distancia = abs(linha_robo - 3) + abs(coluna_robo - 4);
    printf("Movimente [S] para chegar em [G]\n\tMova usando WASD (Q para sair)\n\n");
    printf("Distancia de Manhattan (ignora paredes): %d\n\n", distancia);

    for(int i=0; i<tam; i++)
    {
        for(int j=0; j<tam; j++)
        {
            printf("%c\t", labirinto[i][j]);
        }
        printf("\n");
    }
    
    labirinto[linha_robo][coluna_robo] = celula_anterior;
}

void mover_robo(char movimento, int *linha_ptr, int *coluna_ptr, char labirinto[tam][tam])
{
    int proxima_linha = *linha_ptr;
    int proxima_coluna = *coluna_ptr;

    switch(movimento)
    {
        case 'w': case 'W': proxima_linha--; break;
        case 'a': case 'A': proxima_coluna--; break;
        case 's': case 'S': proxima_linha++; break;
        case 'd': case 'D': proxima_coluna++; break;
        default: return;
    }

    if (proxima_linha >= 0 && proxima_linha < tam && proxima_coluna >= 0 && proxima_coluna < tam)
    {
        if (labirinto[proxima_linha][proxima_coluna] != '#')
        {
            *linha_ptr = proxima_linha;
            *coluna_ptr = proxima_coluna;
        }
    }
}

int main()
{
    char labirinto[tam][tam], movimento;
    int linha = 0, coluna = 0;

    inicializa_labirinto(labirinto);

    while(1)
    {
        limpar_tela();
        
        renderiza_labirinto(labirinto, linha, coluna);

        if(linha == 3 && coluna == 4)
        {
            printf("\nParabens! Objetivo atingido!\n");
            break;
        }

        printf("\nInsira o movimento: ");
        scanf(" %c", &movimento);

        if(movimento == 'Q' || movimento == 'q')
        {
            break;
        }
        
        mover_robo(movimento, &linha, &coluna, labirinto);
    }

    printf("\n- - Execucao encerrada! - -");
    return 0;
}