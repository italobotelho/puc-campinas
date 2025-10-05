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
            printf("\nParabens! Voce alcancou o objetivo!\n");
            break;
        }
        
        printf("Movimento: ");
        scanf(" %c", &movimento);
        
        switch(movimento)
        {
            case 'W':
            case 'w':
                posicaoV--;
                if(posicaoV < 0)
                {
                    posicaoV++;
                    printf("Movimento invalido\n\n");
                }
                break;

            case 'A':
            case 'a':
                vetorAtual--;
                if(vetorAtual < 0)
                {
                    vetorAtual++;
                    printf("Movimento invalido\n\n");
                }
                break;

            case 'S':
            case 's':
                posicaoV++;
                if(posicaoV > 4)
                {
                    posicaoV--;
                    printf("Movimento invalido\n\n");
                }
                break;

            case 'D':
            case 'd':
                vetorAtual++;
                if(vetorAtual > 4)
                    {
                        vetorAtual--;
                        printf("Movimento invalido\n\n");
                    }
                break;
                
            default:
                printf("\t\t\t- Erro: Faca um movimento possivel! -\n\n");
        }

        if(((vetorAtual == 1) && (posicaoV == 4 || posicaoV == 2 || posicaoV == 1)) || ((vetorAtual == 3) && (posicaoV == 3 || posicaoV == 1 || posicaoV == 0)))
        {
            if(movimento == 'W' || movimento == 'w')
            {
                printf("Movimento invalido\n\n");
                posicaoV++;
            }
            else if(movimento == 'S' || movimento == 's')
            {
                printf("Movimento invalido\n\n");
                posicaoV--;
            }
            else if(movimento == 'A' || movimento == 'a')
            {
                printf("Movimento invalido\n\n");
                vetorAtual++;
            }
            else if(movimento == 'D' || movimento == 'd')
            {
                printf("Movimento invalido\n\n");
                vetorAtual--;
            }
        }
    }
    return 0;
}