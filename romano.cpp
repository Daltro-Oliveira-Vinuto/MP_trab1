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

enum boolean validaInput(const char* romano) {
  int size, i, n, Atual;
  enum boolean garanteInput = TRUE;

  size = strlen(romano);
  n = 0;
  for (i=0; i < size && garanteInput == TRUE; i++) {
    if (converteSimbolo(romano[i]) == -1) {
      garanteInput = FALSE;
    } else {
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

void verificaDupla(int* sum, int* A, int* B, int* nA, int* nB) {
  if (*A > *B) {
    *sum+= (*nA)*(*A) + (*nB)*(*B);
  } else if (*A < *B) {
    *sum+= (*nB)*(*B) - (*nA)*(*A);
  }
  *nA = *nB = 0;
}

void verificaTrio(int* sum, int* A, int* B, int* C, int* nA, int* nB, int* nC) {
  *sum+= (*A)*(*nA);
  *A = *B;
  *nA = *nB;
  *B = *C;
  *nB = *nC;
  verificaDupla(sum, A, B, nA, nB);
}

int converte(const char* romano) {
  int Final;

  if (validaInput(romano) == FALSE) {
    Final = -1;
  } else {
    int size = strlen(romano);
    int i, sum = 0, A = 0, B = 0, C = 0, D = 0;
    int nA = 0, nB = 0, nC = 0, nD = 0;
    for (i = 0; i <  size; i++) {
      if (nA == 0) {
        nA = 1;
        A = converteSimbolo(romano[i]);
      } else if (nB == 0 && A == converteSimbolo(romano[i])) { nA++;
      } else if (nB == 0) {
        nB = 1;
        B = converteSimbolo(romano[i]);
      } else if (nC == 0 && B == converteSimbolo(romano[i])) { nB++;
      } else if (nC == 0) {
        C = converteSimbolo(romano[i]);
        nC = 1;
      } else if (nD == 0 && C == converteSimbolo(romano[i])) { nC++;
      } else if (nD == 0) {
        nD = 1;
        D = converteSimbolo(romano[i]);
      } else if (D == converteSimbolo(romano[i])) { nD++;
      } else {
        verificaDupla(&sum, &A, &B, &nA, &nB);
        verificaDupla(&sum, &C, &D, &nC, &nD);
      }
    }

    if (nC == 0) {
      verificaDupla(&sum, &A, &B, &nA, &nB);
    } else if (nD == 0) {
      verificaTrio(&sum, &A, &B, &C, &nA, &nB, &nC);
    } else {
      verificaDupla(&sum, &A, &B, &nA, &nB);
      verificaDupla(&sum, &C, &D, &nC, &nD);
    }

    Final = sum;
  }
  return Final;
}


