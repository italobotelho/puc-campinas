#include <stdio.h>
#include <stdlib.h>
#define tam 5

void limparTelaANSI() 
{
    printf("\033[2J\033[H");
}

void imprime_lab(char labirinto[tam][tam], int linha_robo, int coluna_robo)
{
    for(int i=0; i<tam; i++) //inicialização
    {
        for(int j=0; j<tam; j++)
        {
            labirinto[i][j] = '.';
        }
    }

    labirinto[1][1] = labirinto[2][1] = labirinto[4][1] = labirinto[0][3] = labirinto[1][3] = labirinto[3][3] = '#'; // posições paredes
    labirinto[3][4] = 'G'; // posição objetivo
    labirinto[linha_robo][coluna_robo] = 'S'; // posição robo

    for(int i=0; i<tam; i++) //impressão
    {
        for(int j=0; j<tam; j++)
        {
            printf("%c\t", labirinto[i][j]);
        }
        printf("\n");
    }
}

void mover_robo(char movimento, int *linha_ptr, int *coluna_ptr)
{
    switch(movimento)
    {
        case 'w':
        case 'W':
            (*linha_ptr)--;
            if(*linha_ptr < 0)
            {
                *linha_ptr = 0;
            }
            break;
        case 'a':
        case 'A':
            (*coluna_ptr)--;
            if(*coluna_ptr < 0)
            {
                *coluna_ptr = 0;
            }
            break;
        case 's':
        case 'S':
            (*linha_ptr)++;
            if(*linha_ptr >= tam)
            {
                *linha_ptr = 4;
            }
            break;
        case 'd':
        case 'D':
            (*coluna_ptr)++;
            if(*coluna_ptr >= tam)
            {
                *coluna_ptr = 4;
            }
            break;
        default:
            break;
    }
}

int main()
{
    char labirinto[tam][tam], movimento;
    int linha = 0, coluna = 0; 

    limparTelaANSI();
    
    printf("Movimente [S] para chegar em [G]\n\tMova usando WASD\n\n");

    while(1)
    {
        imprime_lab(labirinto, linha, coluna);

        if(labirinto[3][4] == 'S')
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

        mover_robo(movimento, &linha, &coluna);

        limparTelaANSI();
    }

    printf("\tExecucao encerrada!\n");
    return 0;
}   