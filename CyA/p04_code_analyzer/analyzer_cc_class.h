// Universidad de La Laguna (ULL)
// Escuela Superior de Ingenieria y Tecnologia (ESIT)
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 21/10/2021
// Archivo analyzer_files_cc_class.h: 
// 
// Donde se aloja la declaración de la clase
// AnalyzerFilesCC y la declaracion de sus metodos
//
// Referencias:
//         Enlaces de interes
// 

#ifndef _ANALYZER_CC_
#define _ANALYZER_CC_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <fstream>

class AnalyzerCC {
 public:
  AnalyzerCC(); // Constructor por defecto
  AnalyzerCC(const std::string& kFileName, std::ifstream& input_file);

  //Operadores
  friend std::ostream& operator<<(std::ostream& out, const AnalyzerCC& File);

 private:
  std::string file_name_{""}; //Nombre del archivo analizado

  //Descripcion del archivo guardado dividido en lineas
  std::string file_description_{""};

  //Vectores que guardan la posicion de las variables, nombre y declaracion
  std::vector<int> vec_var_line_;
  std::vector<std::string> vec_var_name_;
  size_t vars_int_{0};//Contamos cuantas variables de cada tipo hay
  size_t vars_double_{0};//Es mas comodo declarar variables que hacer un metodo

  //Vectores que guardan el tipo de bucle y su linea
  std::vector<int> vec_loop_line_;
  std::vector<std::string> vec_loop_name_;
  size_t loops_for_{0};//Contamos cuantos bucles de cada tipo se han encontrado
  size_t loops_while_{0};

  bool is_it_main_{false};//Nos dice si tiene una funcion "int main"

  //Vectores que guardan la linea y el contenido del comentario
  std::vector<std::string> vec_comm_line_;
  std::vector<std::string> vec_comm_body_;

  //Modificacion en aula, ahora el programa debe guardar los returns
  std::vector<std::string> vec_ret_line_;
  std::vector<std::string> vec_ret_body_;

};

#endif
