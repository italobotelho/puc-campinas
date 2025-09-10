#include <stdio.h>

int main()
{
    int TAM;
    
    printf("\tInsira o tamanho do vetor\n\tDeverá ser maior que 0 e menor que 20!!\n\n");
    do
    {
        printf("Tamanho: ");
        scanf(" %d", &TAM);
    }while(TAM < 1 || TAM > 20);

    float x[TAM], y[TAM], mult;
    
    printf("\n\tInsira o valor de cada vetor\n");
    
    for(int i=0; i<TAM; i++)
    {  
        printf("\nx[%d] = ", i);
        scanf(" %f", &x[i]);
        printf("Valor de K: ");
        scanf(" %f", &mult);
        
        y[i] = x[i] * mult;
        
        printf("%.2f * %.2f = %.2f", x[i], mult, y[i]);
        printf("\n");
    }

    return 0;
}