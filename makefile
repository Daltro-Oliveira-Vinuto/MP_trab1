CC = g++
CFLAGS = -g -Wall  -std=c++11
SOURCES = 	main.cpp romano.cpp romano.hpp testa_romano.cpp
CHECKFLAGS = --enable=warning 

all: romano cppcheck cpplint catch run_test 

romano: romano.cpp main.cpp
	$(CC) $(CFLAGS) romano.cpp main.cpp -o romano.exe

cppcheck: $(SOURCES) 
	cppcheck $(CHECKFLAGS) $(SOURCES)

cpplint: $(SOURCES) 
	cpplint  $(SOURCES) 

catch: romano.cpp testa_romano.cpp testa_romano_main.cpp
	$(CC) $(CFLAGS) romano.cpp testa_romano.cpp testa_romano_main.cpp -o testa_romano_main.exe

run_test: testa_romano_main.exe
	./testa_romano_main.exe

run: romano.exe
	valgrind --leak-check=yes --log-file=valgrind_out.txt ./romano.exe