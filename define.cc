// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: expresiones regulares
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 25/10/2022
// Archivo define.cc: implementación de la clase define
#include "define.h"

Define::Define(std::string define_name, unsigned int line_number) {
  define_name_ = define_name;
  line_number_ = line_number;
}

std::string Define::GetName() {
  return define_name_;
}

unsigned int Define::GetLine() {
  return line_number_;
}