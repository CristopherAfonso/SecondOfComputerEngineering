// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Simbolos, alfabetos y cadenas
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 08/10/2021
// Archivo alphabet_class.h: Donde se aloja la declaración de la clase
//         alfabeto y sus metodos
//
// Referencias:
//         Enlaces de interes

#ifndef _ALPHABET_CLASS_
#define _ALPHABET_CLASS_

#include <iostream>
#include <string>
#include <vector>


class Alphabet {
 public:
  //Constructores
  Alphabet();
  Alphabet(std::vector<std::string>& set_in_line);

  std::string VecPlace(size_t ubication); //Getter
  bool AreThereComplexSymbols(); //Testea si hay simbolos de varios caracteres
  size_t SizeAlphabet();

 private:
  std::vector<std::string> alphabet_;
};

#endif
