// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: expresiones regulares
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 25/10/2022
// Archivo comentarios.cc: implementación de la clase comentarios

#include "comentarios.h"
#include "vector"

Comentario::Comentario(std::vector<std::string> comentario_line, 
unsigned int start_line_number, unsigned int end_line_number) {
  comentario_line_ = comentario_line;
  start_line_number_ = start_line_number;
  end_line_number_ = end_line_number;
}

unsigned int Comentario::GetSize() {
  return comentario_line_.size();
}

unsigned int Comentario::GetStartLine() {
  return start_line_number_;
}

unsigned int Comentario::GetEndLine() {
  return end_line_number_;
}

std::string& Comentario::operator[](unsigned int index) {
  return comentario_line_[index];
}