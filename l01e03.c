/* 3. Faça um programa em C para ler ou gerar (aleatoriamente) 10 números e
armazená-los em um vetor. O programa deve conter um procedimento para ordenar os
números no vetor em ordem crescente. Ao final da execução, o programa deve
apresentar o vetor ordenado. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int array[10];

void gerarValores() {
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    array[i] = rand() % 50;
  }
}

void escreverValores() {
  for (int i = 0; i < 10; i++) {
    printf("Digite o valor da posicao %d\n", i);
    scanf("%d", &array[i]);
  }
}

void ordenarValores() {
  int tmp;
  for (int i = 0; i < 10; i++) {
    if (array[i] > array[i + 1]) {
      tmp = array[i];
      array[i] = array[i + 1];
      array[i + 1] = tmp;
      ordenarValores();
    }
  }
}

void printValores() {
  for (int i = 0; i < 10; i++) {
    printf("[%2d] ", array[i]);
  }
  printf("\n");
}

int main(void) {
  int decisao;
  printf("Deseja gerar ou escrever os 10 numeros?\n");
  printf("1-gerar\n2-escrever\n");
  scanf("%d", &decisao);
  switch (decisao) {
  case 1:
    gerarValores();
    break;
  case 2:
    escreverValores();
    break;
  default:
    printf("Decisao invalida, encerrando programa\n");
    return 1;
  }
  ordenarValores();
  printValores();
  return EXIT_SUCCESS;
}
