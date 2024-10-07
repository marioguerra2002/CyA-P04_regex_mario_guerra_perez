// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: expresiones regulares
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 25/10/2022
// Archivo ClienteExpresiones.cc: programa principal

#include <iostream>
#include "ocurrencies.h"
#include <fstream>

int main(int argc, char* argv[]) {
  if (argc == 1) {
    std::cerr << "No se han introducido parámetros, el programa se " <<
    "debe ejecutar de la siguiente forma:" << std::endl << std::endl <<
    "./p04_code_analizer code.cc codescheme.txt" << std::endl << std::endl <<
    "El archivo .cc es el código a analizar y el .txt es la salida donde" <<
    "se imprimirán las ocurrencias" << std::endl;
    return 0;
  }
  std::string inputfile(argv[1]);
  std::string outputfile(argv[2]);
  Ocurrencies current_file(inputfile);
  current_file.WriteOutput(outputfile,inputfile);
  return 0;
}