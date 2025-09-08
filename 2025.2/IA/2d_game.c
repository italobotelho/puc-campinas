#include <stdio.h>
#define tam 5

int main()
{
    int posicaoV = 0, vetorAtual = 0;
    
    char col0[tam] = {'.','.','.','.','.'};
    char col1[tam] = {'.','#','#','.','#'};
    char col2[tam] = {'.','.','.','.','.'};
    char col3[tam] = {'#','#','.','#','.'};
    char col4[tam] = {'.','.','.','G','.'};
    
    char movimento;
    
    printf("---------------------------------------------------------------------------------\n");
    printf("------------------------- Mova o 'S' para chegar em 'G' -------------------------\n");
    printf("----------------- Use W(cima), A(esquerda), S(baixo), D(direita) ----------------\n");
    printf("---------------------------------------------------------------------------------\n");
    
    while(1)
    {
        for(int i=0; i<tam; i++)
        {
            if((vetorAtual == 0) && (posicaoV == i))
            {
                printf("\tS\t");
            }
            else
            {
                printf("\t%c\t", col0[i]);
            }
            
            if((vetorAtual == 1) && (posicaoV == i))
            {
                printf("\tS\t");
            }
            else
            {
                printf("\t%c\t", col1[i]);
            }
            
            if((vetorAtual == 2) && (posicaoV == i))
            {
                printf("\tS\t");
            }
            else
            {
                printf("\t%c\t", col2[i]);
            }
            
            if((vetorAtual == 3) && (posicaoV == i))
            {
                printf("\tS\t");
            }
            else
            {
                printf("\t%c\t", col3[i]);
            }
            
            if((vetorAtual == 4) && (posicaoV == i))
            {
                printf("\tS\t");
            }
            else
            {
                printf("\t%c\t", col4[i]);
            }
    
            printf("\n");
        }
        
        printf("---------------------------------------------------------------------------------\n");
        
        if (vetorAtual == 4 && posicaoV == 3) {
            printf("\nParabéns! Você alcançou o objetivo!\n");
            break;
        }
        
        
        printf("Movimento: ");
        scanf(" %c", &movimento);
        
        // if(vetorAtual < 0 || vetorAtual > 4)
        // {
        //     printf("Movimento invalido\n");
        //     continue;
        // }
        // else
        // {
            switch(movimento)
            {
                case 'W':
                case 'w':
                    posicaoV--;
                    break;
                case 'A':
                case 'a':
                    vetorAtual--;
                    break;
                case 'S':
                case 's':
                    posicaoV++;
                    break;
                case 'D':
                case 'd':
                    vetorAtual++;
                    break;
                default:
                    printf("\t\t\t- Erro: Faça um movimento possivel! -\n\n");
            }
        // }
    }
    return 0;
}