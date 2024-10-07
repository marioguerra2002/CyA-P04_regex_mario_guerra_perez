// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: expresiones regulares
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 25/10/2022
// Archivo bucles.cc: implementación de la clase bucles

#include "bucles.h"

Bucle::Bucle(std::string bucle_type, unsigned int line_number) {
  bucle_type_ = bucle_type;
  line_number_ = line_number;
}

std::string Bucle::GetType() {
  return bucle_type_;
}

unsigned int Bucle::GetLine() {
  return line_number_;
}