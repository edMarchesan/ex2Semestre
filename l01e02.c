/* 2. Escreva um programa em C que gere números aleatórios para uma matriz
quadrada de ordem 9. O programa deve conter um menu com as seguintes opções: a.
Gerar elementos para a matriz b. Apresentar os elementos da matriz c. Apresentar
a média dos valores de uma linha (informada pelo usuário) d. Apresentar a média
dos valores de uma coluna (informada pelo usuário) e. Apresentar a média dos
valores da diagonal principal f. Apresentar a média dos valores abaixo da
diagonal principal g. Apresentar a média dos valores acima da diagonal principal
Procure empregar o uso de funções na solução deste problema.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int matriz[9][9];

void gerarElementosAleatorios();
void apresentarMatriz();
void apresentarMediaColuna();
void apresentarMediaLinha();
void apresentarDiagonalPrincipal();
void apresentarMediaAbaixoDaPrincipal();
void apresentarMediaAcimaDaPrincipal();

int main(void) {
  srand(time(NULL));
  int decisao = 1;
  while (decisao != 0) {
    printf("O que deseja fazer?\n");
    printf("1-Gerar elementos para a matriz.\n");
    printf("2-Apresentar os elementos da matriz.\n");
    printf("3-Apresentar a media de uma linha.\n");
    printf("4-Apresentar a media de uma coluna.\n");
    printf("5-Apresentar a diagonal principal.\n");
    printf("6-Apresentar a media abaixo da diagonal.\n");
    printf("7-Apresentar a media acima da diagonal.\n");
    printf("0-Sair.\n");
    scanf("%d", &decisao);
    switch (decisao) {
    case 1:
      gerarElementosAleatorios();
      break;
    case 2:
      apresentarMatriz();
      break;
    case 3:
      apresentarMediaLinha();
      break;
    case 4:
      apresentarMediaColuna();
      break;
    case 5:
      apresentarDiagonalPrincipal();
      break;
    case 6:
      apresentarMediaAbaixoDaPrincipal();
      break;
    case 7:
      apresentarMediaAcimaDaPrincipal();
      break;
    default:
      printf("Opcao invalida, tente novamente.\n");
      return 1;
      break;
    }
  }
  return EXIT_SUCCESS;
}

void gerarElementosAleatorios() {
  for (int i = 0; i < 9; i++) {
    for (int y = 0; y < 9; y++) {
      matriz[i][y] = rand() % 100;
    }
  }
}

void apresentarMatriz() {
  for (int i = 0; i < 9; i++) {
    for (int y = 0; y < 9; y++) {
      printf("[%3d] ", matriz[i][y]);
    }
    printf("\n");
  }
}

void apresentarMediaLinha() {
  int linha;
  float soma = 0;
  printf("Escolha uma linha de 0 a 8 para apresentar sua media.\n");
  scanf("%d", &linha);
  if (linha >= 0 && linha <= 8) {
    for (int i = 0; i < 9; i++) {
      soma += matriz[linha][i];
    }
    printf("A media da linha selecionada e: %.2f \n", soma / 9);
    printf("\n");
  }
}

void apresentarMediaColuna() {
  int coluna;
  float soma = 0;
  printf("Escolha uma coluna de 0 a 8 para apresentar sua media.\n");
  scanf("%d", &coluna);
  if (coluna >= 0 && coluna <= 8) {
    for (int i = 0; i < 9; i++) {
      soma += matriz[i][coluna];
    }
    printf("A media da coluna selecionada e: %.2f \n", soma / 9);
    printf("\n");
  }
}

void apresentarDiagonalPrincipal() {
  for (int i = 0; i < 9; i++) {
    for (int y = 0; y < 9; y++) {
      if (i == y) {
        printf("[%3d] ", matriz[i][y]);
      } else {
        printf("[   ] ");
      }
    }
    printf("\n");
  }
}

void apresentarMediaAbaixoDaPrincipal() {
  float soma = 0;
  for (int i = 0; i < 9; i++) {
    for (int y = 0; y < 9; y++) {
      if (i < y) {
        soma += matriz[i][y];
      }
    }
  }
  printf("A media abaixo da principal e: %.2f \n", soma / 36);
}

void apresentarMediaAcimaDaPrincipal() {
  float soma = 0;
  for (int i = 0; i < 9; i++) {
    for (int y = 0; y < 9; y++) {
      if (i > y) {
        soma += matriz[i][y];
      }
    }
  }
  printf("A media abaixo da principal e: %.2f \n", soma / 36);
}
