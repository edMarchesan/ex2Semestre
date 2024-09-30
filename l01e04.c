/* 4. A prefeitura de uma pequena cidade do interior contratou você para
desenvolver um software para armazenar e processar alguns dados de amostra de
uma consulta municipal. O programa deve registrar os seguintes dados para 200
famílias: • Renda familiar • Número de filhos • Número de animais de estimação
Escreva um programa em C que contenha uma matriz de tamanho 200 x 3 para
armazenar os dados descritos acima, onde a primeira coluna representa a renda
familiar, a segunda coluna representa o número de filhos e a terceira coluna
representa o número de animais de estimação. Para fins de teste, estes dados
devem ser gerados de forma aleatória, onde:
• O salário deve variar entre R$ 500 e R$ 20.000;
• O número de filhos deve variar entre 0 e 12;
• O número de animais de estimação deve variar entre 0 a 5.
O programa deve conter um menu de opções para apresentar os seguintes dados:
a. A média de salário da população;
b. A maior e a menor renda familiar e a quais famílias respectivamente
pertencem; c. O percentual de famílias com salário menor de R$ 2.000,00; d. A
média de número de filhos; e. A média de número de animais de estimação.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int familias[200][3];

void gerarSalario() {
  for (int i = 0; i < 200; i++) {
    familias[i][0] = (rand() % (20000 - 500 + 1)) + 500;
  }
}

void gerarFilhos() {
  for (int i = 0; i < 200; i++) {
    familias[i][1] = rand() % 12;
  }
}

void gerarAnimais() {
  for (int i = 0; i < 200; i++) {
    familias[i][2] = rand() % 5;
  }
}

void mediaSalario() {
  int soma = 0;
  for (int i = 0; i < 200; i++) {
    soma += familias[i][0];
  }
  printf("A media salarial e de R$ %.2f.\n", ((float)soma / 200));
}

void maioreMenorSalario() {
  int menor = 20000, maior = 0, familiaMenor, familiaMaior;
  for (int i = 0; i < 200; i++) {
    if (familias[i][0] > maior) {
      maior = familias[i][0];
      familiaMaior = i;
    } else if (familias[i][0] < menor) {
      menor = familias[i][0];
      familiaMenor = i;
    }
  }
  printf("A maior renda e de R$ %d da familia %d\n", maior, familiaMaior);
  printf("A menor renda e de R$ %d da familia %d\n", menor, familiaMenor);
}

void menordeDoisMil() {
  int soma = 0;
  for (int i = 0; i < 200; i++) {
    if (familias[i][0] < 2000) {
      soma++;
    }
  }
  printf("%.2f%% das familias recebem menos de 2 mil\n",
         (float)soma * 100 / 200);
}

void mediaFilhos() {
  int somaFilhos = 0;
  for (int i = 0; i < 200; i++) {
    somaFilhos += familias[i][1];
  }
  printf("A media de filhos e de %.2f\n", (float)somaFilhos / 200);
}

void mediaAnimais() {
  int somaAnimais = 0;
  for (int i = 0; i < 200; i++) {
    somaAnimais += familias[i][2];
  }
  printf("A media de animais e de %.2f\n", (float)somaAnimais / 200);
}

int main(void) {
  srand(time(NULL));
  gerarSalario();
  gerarFilhos();
  gerarAnimais();
  int decisao = 7;
  do {
    printf("Escolha uma opcao.\n");
    printf("1-Media dos salarios.\n");
    printf("2-Maior e Menor salario.\n");
    printf("3-Quantor %% menor de 2 mil\n");
    printf("4-Media de filhos\n");
    printf("5-Media de animais\n");
    printf("0-Sair\n");
    scanf("%d", &decisao);
    switch (decisao) {
    case 0:
      printf("Saindo.\n");
      return 1;
      break;
    case 1:
      mediaSalario();
      break;
    case 2:
      maioreMenorSalario();
      break;
    case 3:
      menordeDoisMil();
      break;
    case 4:
      mediaFilhos();
      break;
    case 5:
      mediaAnimais();
      break;
    default:
      printf("Opcao invalida.\n");
      break;
    }
  } while (decisao != 0);
  return EXIT_SUCCESS;
}
