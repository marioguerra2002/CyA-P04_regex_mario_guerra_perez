// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: expresiones regulares
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 25/10/2022
// Archivo define.h: cabecera de la clase define
#ifndef DEFINE_H
#define DEFINE_H

#include <iostream>

class Define {
 public:
  Define(std::string define_name, unsigned int line_number);
  std::string GetName();
  unsigned int GetLine();
 private:
  std::string define_name_;
  unsigned int line_number_;
};

#endif // DEFINE_H