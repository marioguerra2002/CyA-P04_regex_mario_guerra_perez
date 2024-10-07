// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: expresiones regulares
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 25/10/2022
// Archivo bucles.h: cabecera de la clase bucles

#ifndef BUCLE_H
#define BUCLE_H

#include <iostream>

class Bucle {
 public:
  Bucle(std::string bucle_line, unsigned int line_number);
  std::string GetType();
  unsigned int GetLine();
 private:
  std::string bucle_type_;
  unsigned int line_number_;
};

#endif