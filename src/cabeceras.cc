// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: expresiones regulares
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 25/10/2022
// Archivo cabeceras.cc: implementación de la clase cabeceras

#include "cabeceras.h"

Cabecera::Cabecera(std::string cabecera_type, unsigned int line_number) {
  cabecera_type_ = cabecera_type;
  line_number_ = line_number;
}

std::string Cabecera::GetType() {
  return cabecera_type_;
}

unsigned int Cabecera::GetLine() {
  return line_number_;
}