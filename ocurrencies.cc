// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: expresiones regulares
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 25/10/2022
// Archivo ocurrencies.cc: implementación de la clase ocurrencies


#include "variables.h"
#include "bucles.h"
#include "comentarios.h"
#include "ocurrencies.h"
#include "cabeceras.h"
#include "define.h"
#include <fstream>
#include <regex>
#include <iostream>

Ocurrencies::Ocurrencies(std::string inputfile) {
  std::ifstream input(inputfile);
  // vectores que almacenarán todas las búsquedas
  std::vector<Variable> vector_variables;
  std::vector<Bucle> vector_bucles;
  std::vector<Comentario> vector_comentarios;
  std::vector<Cabecera> vector_cabeceras;
  std::vector<Define> vector_define;
  std::vector<std::string> comentarios;  // almacenar las líneas que formen parte de un comentario de múltiples líneas
  bool comment_start_found = false; // si se está analizando un comentario de múltiples líneas	
  std::string aux; //Variable auxiliar para almacenar las líneas del fichero
  unsigned int line_number{1};
  std::regex expresion_main("\\s*int\\s*main\\s*\\(.*\\).*");
  has_main_ = false;
  std::regex expresion_variables 
  ("[^\\(]\\s*(int|double)\\s+(\\w*\\s*[\\(=\\{]?\\s*\\d*\\.?\\d*\\s*[\\)\\}]?)");
  std::regex expresion_bucles ("\\s*(for|while)\\s*\\(");
  std::regex expresion_comentarios_mono("\\/\\/.*");
  std::regex expresion_comentarios_multistart("\\s*\\/\\*.*\\s*");
  std::regex expresion_comentarios_multiend("\\s*.*\\*\\/\\s*");
  std::regex expresion_cabeceras("#include\\s*[<\"].*[>\"]");
  std::regex expresion_define("#define\\s*\\w*");
  while (getline(input, aux)) {
    std::smatch matches;
    unsigned int iterator{0};
    std::string ocurrencie_type;
    std::string variable_name;
    //Búsqueda de variables
    std::regex_search(aux,matches,expresion_variables);
    for (auto match: matches) {
      //El switch se emplea ya que, al encontra una variable válida, esta se
      //divide en si es un entero o double (caso 1) y en el nombre y declaración
      //de la misma (caso 2). El caso 0 no se emplea, pero en él se guarda tanto
      //el tipo de variable como su nombre y valor (no se suele dar el caso, pero puede existir).
      switch (iterator) {
        case 1:
          ocurrencie_type = match;
          ++iterator;
          break;
        case 2:
          iterator = 0;
          variable_name = match;
          break;
        default:
          ++iterator;
      }
    }
    //Verificamos que el tamaño del vector almacenado sea mayor que 0
    //ya que también se pueden guardar espacios en blanco
    if (ocurrencie_type.size() > 0) {
      Variable new_variable(ocurrencie_type,variable_name,line_number);
      vector_variables.push_back(new_variable);
    }
    //Búsqueda de bucles
    std::regex_search(aux,matches,expresion_bucles);
    for (auto match: matches) {
      ocurrencie_type = match;
    }
    if (ocurrencie_type.size() > 0) {
      Bucle new_bucle(ocurrencie_type,line_number);
      vector_bucles.push_back(new_bucle);
    }
    //Búsqueda de la función main
    if(std::regex_match(aux,matches,expresion_main)) {
      has_main_ = true;
    }
    //Búsqueda de comentarios de una sola línea
    std::regex_search(aux,matches,expresion_comentarios_mono);
    std::vector<std::string> comentario;
    for (auto match: matches) {
      ocurrencie_type = match;
    }
    if (ocurrencie_type.size() > 0) {
      comentario.push_back(ocurrencie_type);
      Comentario new_comentario(comentario,line_number,line_number);
      vector_comentarios.push_back(new_comentario);
    }
    //Búsqueda de comentarios de múltiples líneas
    if (std::regex_match(aux,matches,expresion_comentarios_multistart)) {
      //Si se ha encontrado el inicio de un comentario multi-línea
      //se activa la flag comment_start_found
      comment_start_found = true;
    }
    //Mientras se esté dentro del comentario, las líneas se van
    //almacenando en un vector de cadenas
    if (comment_start_found) {
      comentarios.push_back(aux);
      //Si se ha detectado un fin de comentario multi-línea, se procede a
      //almacenar todo el comentario y a devolver la flag a false
      if (std::regex_match(aux,matches,expresion_comentarios_multiend)) {
        Comentario new_comentario(comentarios,
        line_number-comentarios.size()+1,line_number);
        vector_comentarios.push_back(new_comentario);
        comentarios.clear();
        comment_start_found = false;
      }
    }
    std::regex_search(aux,matches,expresion_cabeceras);
    for (auto match: matches) {
      ocurrencie_type = match;
    }
    if (ocurrencie_type.size() > 0) {
      Cabecera new_cabecera(ocurrencie_type,line_number);
      vector_cabeceras.push_back(new_cabecera);
    }
    std::regex_search(aux,matches,expresion_define);
    for (auto match: matches) {
      ocurrencie_type = match;
    }
    if (ocurrencie_type.size() > 0) {
      Define new_define(ocurrencie_type,line_number);
      vector_define.push_back(new_define);
    }
    ++line_number;
  }
  vector_bucles_ = vector_bucles;
  vector_variables_ = vector_variables;
  vector_comentarios_ = vector_comentarios;
  vector_cabeceras_ = vector_cabeceras;
  vector_define_ = vector_define;
}

void Ocurrencies::WriteOutput(std::string outputfile, std::string inputfile) {
  std::ofstream output(outputfile);
  output << "PROGRAM: " << inputfile << std::endl;
  for (unsigned int i{0}; i < vector_comentarios_.size(); ++i) {
    if (vector_comentarios_[i].GetStartLine() == 1) {
      output << "DESCRIPTION:" << std::endl;
      for (unsigned int j{0}; j < vector_comentarios_[i].GetSize(); ++j) {
        output << vector_comentarios_[i][j] << std::endl;
      }
    }
  }
  output << "VARIABLES:" << std::endl;
  for (unsigned int i{0}; i < vector_variables_.size(); ++i) {
    output << "[LINE " << vector_variables_[i].GetLine() << "] "
    << vector_variables_[i].GetType() << ": " 
    << vector_variables_[i].GetName() << std::endl;
  } 
  output << std::endl << "STATEMENTS: " << std::endl;
  for (unsigned int i{0}; i < vector_bucles_.size(); ++i) {
    output << "[LINE " << vector_bucles_[i].GetLine() << "] loop: "
    << vector_bucles_[i].GetType() << std::endl;
  }
  output << std::endl << "MAIN:" << std::endl;
  if (has_main_) {
    output << "True" << std::endl;
  }
  else {
    output << "False" << std::endl;
  }
  output << std::endl << "COMMENTS:" << std::endl;
  for (unsigned int i{0}; i < vector_comentarios_.size(); ++i) {
    if (vector_comentarios_[i].GetStartLine() == 1) {  // en caso de que el comentario esté en la primera línea
      output << "[LINE " << vector_comentarios_[i].GetStartLine() << "-"
      << vector_comentarios_[i].GetEndLine() << "] DESCRIPTION" << std::endl;
    }
    else if (vector_comentarios_[i].GetSize() == 1) {  // en caso de que el comentario sea de una sola línea
      output << "[LINE " << vector_comentarios_[i].GetStartLine() << "] "
      << vector_comentarios_[i][0] << std::endl;
    }
    else{  // en caso de que el comentario sea de varias líneas
      output << "[LINE " << vector_comentarios_[i].GetStartLine() << "-"
      << vector_comentarios_[i].GetEndLine() << "]" << std::endl;
      for (unsigned int j{0}; j < vector_comentarios_[i].GetSize(); ++j) {
        output << vector_comentarios_[i][j] << std::endl;
      }
    }
  }
  output << std::endl << "HEADERS: " << std::endl;
  for (unsigned int i{0}; i < vector_cabeceras_.size(); ++i) {
    output << "[LINE " << vector_cabeceras_[i].GetLine() << "] "
    << vector_cabeceras_[i].GetType() << std::endl;
  }
  output << std::endl << "DEFINES: " << std::endl;
  for (unsigned int i{0}; i < vector_define_.size(); ++i) {
    output << "[LINE " << vector_define_[i].GetLine() << "] "
    << vector_define_[i].GetName() << std::endl;
  }
}