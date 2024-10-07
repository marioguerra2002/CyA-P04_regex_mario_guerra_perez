// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: expresiones regulares
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 25/10/2022
// Archivo cabeceras.h: cabecera de la clase cabeceras

#ifndef CABECERA_H
#define CABECERA_H

#include <iostream>

class Cabecera {
 public:
  Cabecera(std::string cabecera_line, unsigned int line_number);
  std::string GetType();
  unsigned int GetLine();
 private:
  std::string cabecera_type_;
  unsigned int line_number_;
};

#endif // CABECERA_H