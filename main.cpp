// Copyright 2019 Daltro Oliveira Vinuto

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "romano.hpp"

int main(void) {
  int numero;
  char algarismo[MAX];

  // recebe o algarismo e mostra a conversao
  // o programa termina quando o usuario digitar -1
  do {
    printf("Digite o algarismo romano(-1 para sair): ");
    setbuf(stdin, NULL);
    fgets(algarismo, MAX, stdin);
    if (strcmp(algarismo, "-1\n") != 0) {
      numero = converte(algarismo);
      if (numero == -1) {
        printf("Algarismo romano invalido!\n\n");
      } else {
        printf("%s = %d\n", algarismo, numero);
      }
    }
  }while(strcmp(algarismo, "-1\n") != 0);

  // informa o fim do programa
  printf("Programa finalido!\n\n");

  return 0;
}
