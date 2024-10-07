// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: expresiones regulares
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 25/10/2022
// Archivo variables.h: cabecera de la clase variables

#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>

class Variable {
 public:
  Variable(std::string vaiable_type, std::string variable_name, unsigned int line_number);
  std::string GetType();
  std::string GetName();
  unsigned int GetLine();
 private:
  std::string variable_type_;
  std::string variable_name_;
  unsigned int line_number_;
};

#endif // VARIABLE_H