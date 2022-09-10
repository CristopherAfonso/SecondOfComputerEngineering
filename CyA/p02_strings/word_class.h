// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Simbolos, alfabetos y cadenas
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 08/10/2021
// Archivo word_class.h: Donde se aloja la declaración de la clase
//         cadena y sus metodos
//
// Referencias:
//         Enlaces de interes

#ifndef _WORD_CLASS_
#define _WORD_CLASS_

#include <iostream>
#include <string>
#include <vector>

#include "alphabet_class.h"

class Word {
 public:
  //Constructores
  Word();
  Word(const std::string& word);

  // Para cada OpCode hay un métodoo con alfabetos simples y complejos
  // Así en algunos casos hacemos que el tiempo de respuesta del Programa
  // Sea más rápido y haga lo que se le pide en menos tiempo.
  // En este programa hice que la clase Word realizara las operaciones
  // Solicitadas y la clase Alphabet complementa y apoya esas operaciones
  // OpCode 1
  int Size();
  int Size(Alphabet& set);

  // OpCode 2
  std::string Inverse();
  std::string Inverse(Alphabet& set, int& size_complex_alphabet);

  // OpCode 3
  std::string Prefixes();
  std::string Prefixes(Alphabet& set, int& size_complex_alphabet);

  // OpCode 4
  std::string Suffixes();
  std::string Suffixes(Alphabet& set, int& size_complex_alphabet);

  // OpCode 5
  std::string Substrings();
  std::string Substrings(Alphabet& set, int& size_complex_alphabet);

 private:
 // Donde guardamos la cadena a evaluar
  std::string word_ = ""; 
  // Este vector es útil al usarlo en algunos métodos de la clase
  // porque ahorra mucho trabajo
  std::vector<char> characters_of_the_word_;
};

#endif
