p01_chainCC=g++ -std=c++20
CFLAGS=-O0 -g -Wall
DEPS = ocurrencies.h
OBJ = main.o

SRC = './src/'

compilar:
	g++ $(CFLAGS) $(SRC)*.cc -o p04_regex


%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
all: chain

busqueda: main.o
	g++ -o p04_regex ClienteExpresiones.cc bucles.cc cabeceras.cc comentarios.cc define.cc ocurrencies.cc variables.cc
clean:
	rm -f *.o