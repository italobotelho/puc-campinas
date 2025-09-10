#include <stdio.h>

int main()
{
    int num1, num2, num3;
    printf("Insira o valor do primeiro numero: ");
    scanf("%d", &num1);
    printf("Insira o valor do segundo: ");
    scanf("%d", &num2);
    printf("Insira o valor do terceiro: ");
    scanf("%d", &num3);
    
    if(num1<num2 && num1<num3){
        printf("O primeiro numero (%d) é o menor valor");
    };
    if(num2<num1 && num2<num3){
        printf("O segundo numero (%d) é o menor valor");
    };
    if(num3<num1 && num3<num2){
        printf("O terceiro numero (%d) é o menor valor");
    };
    return 0;
}