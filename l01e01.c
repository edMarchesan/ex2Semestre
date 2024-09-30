/* 1. Desenvolva um programa em C que contenha uma função que receba uma string
e retorne a quantidade de vogais presentes nela. No programa principal, solicite
ao usuário que insira a string e exiba o resultado da função. */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int retornaVogaisNaString(char *str) {
  int a = strlen(str);
  int count = 0;
  for (int i = 0; i < a; i++) {
    int temp = tolower(str[i]);
    if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' ||
        temp == 'u') {
      count++;
    }
  }
  return count;
}

int main(void) {
  char str[150];
  printf("Digite uma string para calcular seu tamanho.\n");
  fgets(str, sizeof(str), stdin);
  printf("voce digitou uma string com %d vogais\n", retornaVogaisNaString(str));

  return EXIT_SUCCESS;
}
