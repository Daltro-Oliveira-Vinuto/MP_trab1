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
    algarismo[strlen(algarismo)-1] = '\0';
    if (strcmp(algarismo, "-1") != 0) {
      numero = converte(algarismo);
      if (numero == -1) {
        printf("Algarismo romano invalido!\n\n");
      } else {
        printf("%s = %d\n", algarismo, numero);
      }
    }
  }while(strcmp(algarismo, "-1") != 0);

  printf("Programa finalizado!\n\n");

  return 0;
}
