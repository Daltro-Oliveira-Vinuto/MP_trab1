// Copyright 2019 Daltro Oliveira Vinuto

#include <catch2/catch.hpp>
#include "romano.hpp"

// test 1
TEST_CASE("testaSimbolosBasicos", "testaConversao") {
  REQUIRE(converte("I") == 1);
  REQUIRE(converte("V") == 5);
  REQUIRE(converte("X") == 10);
  REQUIRE(converte("L") == 50);
  REQUIRE(converte("C") == 100);
  REQUIRE(converte("D") == 500);
  REQUIRE(converte("M") == 1000);
}

// teste 2
TEST_CASE("testaSimbolosInvalidos", "testaConversaoInvalida") {
  REQUIRE(converte("z") == -1);
  REQUIRE(converte("a") == -1);
  REQUIRE(converte("3") == -1);
}

// teste 3
TEST_CASE("entradaComMaisDe3SimbolosRepetidos", "testaConversaoInvalida") {
  REQUIRE(converte("IIII") == -1);
  REQUIRE(converte("XXXXX") == -1);
  REQUIRE(converte("CCCCCC") == -1);
}

// teste 4
TEST_CASE("algunsNumerosRomanosAte100", "testaConversao") {
  REQUIRE(converte("III") == 3);
  REQUIRE(converte("IV") == 4);
  REQUIRE(converte("VIII") == 8);
  REQUIRE(converte("IX") == 9);
  REQUIRE(converte("XV") == 15);
  REQUIRE(converte("XIV") == 14);
  REQUIRE(converte("XVIII") == 18);
  REQUIRE(converte("XIX") == 19);
  REQUIRE(converte("XXXIV") == 34);
  REQUIRE(converte("XXXVIII") == 38);
  REQUIRE(converte("XLIV") == 44);
  REQUIRE(converte("XLVIII") == 48);
  REQUIRE(converte("XCIV") == 94);
  REQUIRE(converte("XCVII") == 97);
  REQUIRE(converte("XCIX") == 99);
}

