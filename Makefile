CC=g++
CFLAGS = -Wall -g

expresiones: ClienteExpresiones.cc variables.h variables.cc bucles.h bucles.cc comentarios.h comentarios.cc ocurrencies.h ocurrencies.cc cabeceras.h cabeceras.cc define.cc define.h
	$(CC) $(CFLAGS) -o p04_code_analizer ClienteExpresiones.cc variables.cc bucles.cc comentarios.cc ocurrencies.cc cabeceras.cc define.cc

clean: 
	rm -rf p04_code_analizer
	rm -rf .txt