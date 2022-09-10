// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Simbolos, alfabetos y cadenas
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 08/10/2021
// Archivo alphabet_class.cc: Donde se desarrollan las funciones de la clase
//         alfabeto contenida en el archivo de cabecera alphabet_class.h.
//
// Referencias:
//         Enlaces de interes

#include "alphabet_class.h"

Alphabet::Alphabet(std::vector<std::string>& set_in_line) {
  alphabet_ = set_in_line;
}

std::string Alphabet::VecPlace(size_t ubication) {
  return alphabet_.at(ubication);
}

bool Alphabet::AreThereComplexSymbols() {
  bool result{false};
  for(auto actual_place: alphabet_) {
    if(actual_place.size() > 1) {
      result = true;
      break;
    }
  }
  return result;
}

size_t Alphabet::SizeAlphabet() {
  return alphabet_.size();
}
