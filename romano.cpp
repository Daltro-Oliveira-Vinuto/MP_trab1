// Copyright 2019 Daltro Oliveira Vinuto

#include "romano.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int converteSimbolo(char c) {
  int number;
  switch (c) {
    case 'I': number = 1; break;
    case 'V': number = 5; break;
    case 'X': number = 10; break;
    case 'L': number = 50; break;
    case 'C': number = 100; break;
    case 'D': number = 500; break;
    case 'M': number = 1000; break;
    default:  number = -1;
  }
  return number;
}

// verifica se a entrada é valida, se sim retorna TRUE
// se for invalida retorna FALSE
enum boolean validaInput(const char* romano) {
  int size, i, n, Atual;
  enum boolean garanteInput = TRUE;
  size = strlen(romano);
  n = 0;
  for (i=0; i < size && garanteInput == TRUE; i++) {
    // verifica se foi digitado um simbolo nao romano
    if (converteSimbolo(romano[i]) == -1) {
      garanteInput = FALSE;
    } else {
      // verifica se foi digitado mais do que 3 simbolos repetidos
      if (n == 0) {
        Atual = converteSimbolo(romano[i]);
        n = 1;
      } else {
        if (Atual == converteSimbolo(romano[i])) {
          n++;
          if (n > 3)  garanteInput = FALSE;
        } else {
          n = 1;
          Atual = converteSimbolo(romano[i]);
        }
      }
    }
  }
  return garanteInput;
}

// recebe dois pares de simbolos e soma ou subtrai
// dependendo se o simbolo da direta e maior ou menor do que o da esquerda
void verificaDupla(int* sum, int* A, int* B, int* nA, int* nB) {
  if (*A > *B) {
    *sum+= (*nA)*(*A) + (*nB)*(*B);
  } else if (*A < *B) {
    *sum+= (*nB)*(*B) - (*nA)*(*A);
  }
  *nA = *nB = 0;
}

// recebe tres pares de simbolos soma o primeiro a soma total
// e trata os outros dois como uma dupla simples
void verificaTrio(int* sum, int* A, int* B, int* C, int* nA, int* nB, int* nC) {
  *sum+= (*A)*(*nA);
  *A = *B;
  *nA = *nB;
  *B = *C;
  *nB = *nC;
  verificaDupla(sum, A, B, nA, nB);
}

// retorna a quantidade de simbolos romanos diferentes
int contaDigitos(const char* romano) {
  int size, i, valor;
  int totalSimbolo = 0;
  size = strlen(romano);
  for (i = 0; i < size; i++) {
    if (totalSimbolo == 0) {
      totalSimbolo = 1;
      valor = converteSimbolo(romano[i]);
    } else if (valor != converteSimbolo(romano[i])) {
      totalSimbolo++;
      valor = converteSimbolo(romano[i]);
    }
  }
  return totalSimbolo;
}

// recebe um simbolo romano e retorna o algarismo
// indo-arabico correspondente
int converte(const char* romano) {
  int Final;

  if (validaInput(romano) == FALSE) {
    Final = -1;
  } else {
    int size = strlen(romano);
    int par, totalSimbolos;
    int i, sum = 0, A = 0, B = 0, C = 0;
    int nA = 0, nB = 0, nC = 0;
    totalSimbolos = contaDigitos(romano);
    if (totalSimbolos % 2 == 0) {
      par = 1;
    } else {
      par = 0;
    }
    for (i = 0; i <  size; i++) {
      // verifica se a ja ocorreu um simbolo da esquerda(isso é A)
      if (nA == 0) {
        nA = 1;
        A = converteSimbolo(romano[i]);
      // se leu somente o simbolo A entao conta o numero de ocorrencias
      } else if (nB == 0 && A == converteSimbolo(romano[i])) { nA++;
      // se ocorreu outro simbolo alem do A entao chame de B
      } else if (nB == 0) {
        nB = 1;
        B = converteSimbolo(romano[i]);
      // somente leu simbolos A e B
      } else if (nC == 0 && B == converteSimbolo(romano[i])) { nB++;
      // varreu outro simbolo que nao A e B, chame de C
      } else if (nC == 0) {
        C = converteSimbolo(romano[i]);
        nC = 1;
      // se ha 3 simbolos e ha um numero impar deles, entao incremente C
      } else if (par == 0 && C == converteSimbolo(romano[i])) { nC++;
      // se ha mais de de 3 simbolos e ha um numero impar deles
      } else if (par == 0 && C != converteSimbolo(romano[i])) {
        verificaTrio(&sum, &A, &B, &C, &nA, &nB, &nC);
        A = converteSimbolo(romano[i]);
        nA = 1;
        nC = 0;
      // se ha mais de 3 simbolos e ha um numero par deles
      } else if (par == 1 && C != converteSimbolo(romano[i])) {
        verificaDupla(&sum, &A, &B, &nA, &nB);
        A = C;
        nA = nC;
        B = converteSimbolo(romano[i]);
        nB = 1;
        nC = 0;
      }
    }

    // dois pares de simbolos restantes
    // ou havia apenas dois pares de simbolos
    if (nC == 0) {
      verificaDupla(&sum, &A, &B, &nA, &nB);
    // tres pares de simbolos restantes
    // ou havia apenas 3 pares de de simbolos
    } else  {
      verificaTrio(&sum, &A, &B, &C, &nA, &nB, &nC);
    }

    Final = sum;
  }
  return Final;
}


