#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define tam 5

// Função que controla o tempo de impressão dos estados
void temporizador(int segundos) {
    while (segundos > 0) {
        fflush(stdout);
        Sleep(1000); // Pausa por 1000 milissegundos (1 segundo)
        segundos--;
    }
}

void layout()
{
    printf("-------------------------------------------------------\n");
}

// Função que 'seta' o estado padrão e inicial do labirinto
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

// Função que vai imprimir o estado do labirinto após o movimento do robô 'S'
void renderiza_labirinto(char labirinto[tam][tam], int linha_robo, int coluna_robo)
{
    char celula_anterior = labirinto[linha_robo][coluna_robo];
    labirinto[linha_robo][coluna_robo] = 'S';

    for(int i=0; i<tam; i++)
    {
        printf("\t");

        for(int j=0; j<tam; j++)
        {
            printf("  ");
            printf("%c\t", labirinto[i][j]);
        }
        printf("\n");
    }

    labirinto[linha_robo][coluna_robo] = celula_anterior;
}

void heuristica(int linha_robo, int coluna_robo)
{
    int distancia = abs(linha_robo - 3) + abs(coluna_robo - 4);
    
    printf("       Distancia de Manhattan (ignora paredes): %d\n", distancia);
}

// Função que calcula a heuristica e altera a posicao atual do robô 'S'
void mover_robo_guloso(int *linha_ptr, int *coluna_ptr, char labirinto[tam][tam])
{
    int proxima_linha = *linha_ptr;
    int proxima_coluna = *coluna_ptr;

    int h_cima, h_baixo, h_esquerda, h_direita;

    h_cima = (abs((proxima_linha - 1) - 3) + abs(proxima_coluna - 4)) + 1;
    h_baixo = (abs((proxima_linha + 1) - 3) + abs(proxima_coluna - 4)) + 1;
    h_direita = (abs(proxima_linha - 3) + abs((proxima_coluna + 1) - 4)) + 1;
    h_esquerda = (abs(proxima_linha - 3) + abs((proxima_coluna - 1) - 4)) + 1;

    if(h_cima < h_baixo && h_cima < h_esquerda && h_cima < h_direita)
    {
        proxima_linha--;
    }
    else if(h_esquerda < h_cima && h_esquerda < h_baixo && h_esquerda < h_direita)
    {
        proxima_coluna--;
    }
    else if(h_baixo < h_cima && h_baixo < h_direita && h_baixo < h_esquerda)
    {
        proxima_linha++;
    }
    else if(h_direita < h_cima && h_direita < h_baixo && h_direita < h_esquerda)
    {
        proxima_coluna++;
    }
    else if(h_direita == h_baixo)
    {
        proxima_linha++;
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

void mover_robo_manual(char movimento, int *linha_ptr, int *coluna_ptr, char labirinto[tam][tam])
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
    int linha = 0, coluna = 0, modo_jogo, opcao;

    inicializa_labirinto(labirinto);

    do
    {
        system("cls");

        printf("--------------- Movimento em Labirinto! ---------------\n");
        layout();
        printf("              Selecione um modo de jogo:\n\n");
        printf("    1. Controlar os movimentos do robo\n");
        printf("    2. Robo se movimenta sozinho (Busca Gulosa)\n\n");
        
        do
        {
            printf("Digite uma das opcoes => ");
            scanf("%d", &modo_jogo);
        } while (modo_jogo != 1 && modo_jogo != 2);

        while(1)
        {       
            system("cls");

            layout();
            heuristica(linha, coluna);
            layout();
            renderiza_labirinto(labirinto, linha, coluna);

            if(linha == 3 && coluna == 4)
            {
                layout();
                printf("              Parabens! Objetivo atingido!\n");
                layout();
                break;
            }

            if(modo_jogo == 1)
            {
                layout();
                printf("           Movimente [S] para chegar em [G]\n");
                printf("            Mova usando WASD (Q para sair)\n");
                layout();

                printf("===> ");
                scanf(" %c", &movimento);

                if(movimento == 'Q' || movimento == 'q')
                {
                    layout();
                    break;
                }
            
                mover_robo_manual(movimento, &linha, &coluna, labirinto);
            }
            else
            {
                layout();
                printf("               Busca Gulosa de robo [S]\n");
                layout();

                mover_robo_guloso(&linha, &coluna, labirinto);

                temporizador(2);
            }
        }

        printf("                    Jogar de novo?\n");
        printf("                  1. Sim  |  2. Nao\n");
        layout();

        do
        {
            printf("===> ");
            scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2);
        
        if(opcao == 2)
        {
            break;
        }
        else
        {
            linha = 0;
            coluna = 0;
        }

    }while(1);

    layout();
    printf("             - - Execucao encerrada! - -\n");
    layout();

    return 0;
}
