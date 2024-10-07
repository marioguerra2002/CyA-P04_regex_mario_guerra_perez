// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: expresiones regulares
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 25/10/2022
// Archivo ocurrencies.h: cabecera de la clase ocurrencies

#ifndef OCURRENCIES_H
#define OCURRENCIES_H

#include <iostream>
#include <vector>
#include "variables.h"
#include "bucles.h"
#include "comentarios.h"
#include "cabeceras.h"
#include "define.h"

class Ocurrencies {
 public:
  Ocurrencies(std::string inputfile);
  void WriteOutput(std::string outputfile, std::string inputfile);
 private:
  std::vector<Variable> vector_variables_;
  std::vector<Bucle> vector_bucles_;
  std::vector<Comentario> vector_comentarios_;
  std::vector<Cabecera> vector_cabeceras_;
  std::vector<Define> vector_define_;
  bool has_main_;
};

#endif // OCURRENCIES_H