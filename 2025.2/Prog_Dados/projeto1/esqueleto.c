#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

// Chame essa função para preencher um vetor numero de tamanho n com um número
// aleatório entre 00000 e 99999
void gera_numero(int numero[], int n) {
  srand(time(NULL));

  for (int i = 0; i < n; ++i)
    numero[i] = rand() % 10;
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
    int vetor[TAM], vetor_numero[TAM], vetor_bool[TAM];
    int tentativas, numero, digito, aux;

    gera_numero(vetor, TAM);

    printf("Gerei um numero aleatorio de %d algarismos. Tente adivinhar!\n", TAM);

    do
    {
      printf("Digite o numero de tentativas para encontrar o numero: ");
      scanf(" %d", &tentativas);
    } while (tentativas <= 0);

    // ======== 3 - Loop do Jogo ========

    for(int i = 0; i < tentativas; i++)
    {
      do
      {
        printf("Digite um numero: ");
        scanf(" %d", &numero);
      } while (numero < 0);

      if(numero == devolve_numero(vetor, TAM))
      {
        break;
      }
      else
      {
        for (int a = 0; a < TAM; a++)
        {
          vetor_bool[a] = 0;
          vetor_numero[a] = 0;
        }

        aux = numero;
        for (int j = TAM - 1; j >= 0; j--)
        {
          vetor_numero[j] = aux % 10;
          aux /= 10;
        }

        for (int k = 0; k < TAM; k++)
        {
          if (vetor[k] == vetor_numero[k])
          {
            vetor_bool[k] = 1;
          }
        }

        imprime_acertados(vetor, vetor_bool, TAM);
      }
    }

    // 4 - Finalização
    if(numero == devolve_numero(vetor, TAM))
    {
        printf("Parabens, voce adivinhou o numero %05d!\n", devolve_numero(vetor, TAM));
    }
    else
    {
        printf("Depois de %d tentativas, voce nao encontrou o numero %05d!\n", tentativas, devolve_numero(vetor, TAM));
    }

  return 0;
}