#include <stdio.h>

int main()
{
    float sal, sal_novo;
    printf("Vamos calcular o reajuste salarial do funcionario!!\nInsira o salário atual (R$): ");
    scanf("%f", &sal);
    
    if(sal < 500){
        sal_novo = sal * 0.15 + sal;
    };
    if(sal >= 500 && sal <= 1000) {
        sal_novo = sal * 0.10 + sal;
    };
    if(sal > 1000) {
        sal_novo = sal * 0.05 + sal;
    }
    
    printf("Indice:\n\tSalario: R$ %6.2f\n\tSalario novo: R$ %6.2f", sal, sal_novo);
    
    return 0;
}

********************************************************************************************

#include <stdio.h>

int main()
{
    float a, b, c;
    printf("Vamos verificar qual o tipo do seu triângulo!!\nInsira o valor do lado A (cm): ");
    scanf("%f", &a);
    printf("Insira o valor do lado B (cm): ");
    scanf("%f", &b);
    printf("Insira o valor do lado C (cm): ");
    scanf("%f", &c);
    
    if(a < b + c && b < a + c && c < a + b){
        if(a == b && b == c) {
            printf("O triângulo é EQULATERO");
        };
        if((a == b && a != c) || (a == c && a != b) || (b == c && b != a)){
            printf("O triangulo é ISOSCELES");
        };
        if(a != b && a != c && b != c){
            printf("O triangulo é ESCALENO");
        }
    } else {
        printf("Os valores inseridos não formam um triângulo!!");
    };
    
    
    return 0;
}

****************************************************************************************

}#include <stdio.h>

int main()
{
    float n1, n2, p1, p2, media;
    printf("Vamos calcular a media das notas do aluno.\nInsira a 1a nota: ");
    scanf("%f", &n1);
    printf("Insira o peso dessa nota: ");
    scanf("%f", &p1);
    printf("Insira a 2a nota: ");
    scanf("%f", &n2);
    printf("Insira o peso dessa nota: ");
    scanf("%f", &p2);
    
    media = (n1 * p1 + n2 * p2) / (p1 + p2);
  
    if(media >= 7 && media < 10){
        printf("Aluno Aprovado!");
    };
    if(media == 10){
        printf("Aluno Aprovado com Distincao!");
    } else {
        printf("Aluno Reprovado!");
    };
    
    return 0;