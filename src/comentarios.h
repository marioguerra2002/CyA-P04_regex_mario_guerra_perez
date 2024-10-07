// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: expresiones regulares
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 25/10/2022
// Archivo comentarios.h: cabecera de la clase comentarios

#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <iostream>
#include <vector>

class Comentario {
 public:
  Comentario(std::vector<std::string> comentario_line, 
  unsigned int start_line_number, unsigned int end_line_number);
  unsigned int GetSize();
  unsigned int GetStartLine();
  unsigned int GetEndLine();
  std::string& operator[](unsigned int index);
 private:
  std::vector<std::string> comentario_line_;
  unsigned int start_line_number_;
  unsigned int end_line_number_;
};

#endif // COMENTARIO_H