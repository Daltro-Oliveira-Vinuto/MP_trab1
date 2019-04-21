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

