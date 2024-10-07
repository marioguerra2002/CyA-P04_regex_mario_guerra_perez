// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: expresiones regulares
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 25/10/2022
// Archivo variables.cc: implementación de la clase variables

#include "variables.h"

Variable::Variable(std::string variable_type, std::string variable_name, unsigned int line_number) {
  variable_type_ = variable_type;
  variable_name_ = variable_name;
  line_number_ = line_number;
}

  std::string Variable::GetType() {
    return variable_type_;
  }
  std::string Variable::GetName() {
    return variable_name_;
  }
  unsigned int Variable::GetLine() {
    return line_number_;
  }