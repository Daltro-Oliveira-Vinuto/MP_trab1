// Copyright 2019 Daltro Oliveira Vinuto

#include "romano.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int converteSimbolo(char c) {
  int valor;
  switch (c) {
    case 'I': valor = 1; break;
    case 'V': valor = 5; break;
    case 'X': valor = 10; break;
    case 'L': valor = 50; break;
    case 'C': valor = 100; break;
    case 'D': valor = 500; break;
    case 'M': valor = 1000; break;
    default: valor = -1;
  }
  return valor;
}

int converte(const char* romano) {
  return converteSimbolo(romano[0]);
}


