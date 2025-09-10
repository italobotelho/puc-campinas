#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

// Chame essa função para preencher um vetor numero de tamanho n com um número
// aleatório entre 00000 e 99999
void gera_numero(int numero[], int n) {
  // srand(time(NULL));

  for (int i = 0; i < n; ++i)
    numero[i] = rand() % 10;

  printf(" %d", numero);
}

// Chame essa função para percorrer o vetor numero e computar o número baseado nos
// elementos dela
int devolve_numero(int numero[], int n) {
  int num = 0;
  for (int i = 0; i < n; ++i)
    num = num * 10 + numero[i];
  return num;
}

// Chame essa função para imprimir o número  de algarismos corretos do número.
// Considere acertados como um vetor com n elementos, onde um elemento de valor
// 0 significa que o algarismo não foi encontrado, e 1 significa que foi
// encontrado
void imprime_acertados(int numero[], int acertados[], int n) {
  printf("Algarismos corretos: ");
  for (int i = 0; i < n; ++i) {
    if (acertados[i] == 1)
      printf("%d", numero[i]);
    else
      printf("_");
  }
  printf("\n");
}

int main() {
  // ======== 1 e 2 - Inicialização e Configuração ========
  int tentativas;


  // printf("Gerei um número aleatório de %d algarismos. Tente adivinhar!\n", TAM);

  // Pergunte ao usuário sobre a quantidade de tentativas a serem realizadas  
  // scanf("Digite o número de tentativas para encontrar o número: %d", &tentativas);

  // ======== 3 - Loop do Jogo ========
  // Para um número de tentativas x, checa se o número lido está correto.
  // Para cada tentativa, caso não tenha acertado:
  //    imprime_acertados(...);

  // for(int i = 0; i < tentativas; i++)
  // {
  //   printf("Digite um número: ");
  //   scanf(" %d", &numero);

  // }

  // ======== 4 - Finalização ========
  // Caso tenha encontrado o número, imprima:
  //  printf("Parabéns, você adivinhou o número %05d!\n", devolve_numero(...));
  // Caso tenha esgotado as tentativas sem encontrar o número, imprima:
  //  printf("Depois de %d tentativas, você não encontrou o número %05d!\n",...);
  return 0;
}
