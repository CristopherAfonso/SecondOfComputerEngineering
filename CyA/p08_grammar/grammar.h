/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 8: Gramática para expresiones aritméticas
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 16/11/2021
 * 
 * @file grammar.h 
 * @brief Donde se aloja la declaración de la clase Grammar y la declaracion
 * de sus metodos. La clase Grammar contiene dos objetos SetSymbols, un Symbol,
 * y un Productions, los dos SetSymbols son el alphabeto y el conjunto de
 * símbolos terminales, el Symbol es el símbolo de arranque, y el objeto
 * Productions, son las producciones en la clase Grammar.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 16/11/21 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 * 19/11/21 - Funciones de la clase terminadas.
 */

#ifndef _GRAMMAR_
#define _GRAMMAR_

#include <fstream>
#include <regex>
#include <vector>

#include "set_symbols.h"
#include "productions.h"

/**
 * @class Grammar.
 * @brief Clase que simula el comportamiento de una gramática, siendo esta
 * capaz de generar un lenguaje. 
 */
class Grammar {
 public:
  /// Constructores. Tenemos 5, el por defecto, los dos que inicializan el
  /// objeto directamente con los valores que se le pasan al constructor,
  /// el constructor de copia, y el quinto es el que más usaremos, es el
  /// constructor que inicializa nuestro objeto gramática a partir de un
  /// archivo.
  Grammar(void);
  Grammar(const std::set<char>& alphabet, const std::set<char>& non_terminals,
          const char& start, 
          const std::multimap<char, std::pair<size_t, std::string>>& prod);
  Grammar(const SetSymbols& alphabet, const SetSymbols& non_terminals,
          const char& start, const Productions& prod);
  Grammar(const Grammar& grammar);
  Grammar(std::ifstream& CFGFile);

  /// Getters.
  SetSymbols GetAlphabet(void) const;
  SetSymbols GetNonTerminals(void) const;
  char GetStart(void) const;
  Productions GetProductions(void) const;
  std::string GetProduction(const char& non_terminal, const size_t& num) const;
  bool Fail(void) const;

  /// Funciones de la clase (Métodos).
  bool IsItInAlphabet(const char& symbol) const;
  bool IsItInNonTerminals(const char& symbol) const;
  bool IsItAProduction(const char& symbol, const size_t& num) const;
  bool IsItAAceptableProduction(const std::string& prod) const;
  bool EvalProdsInFile(std::ifstream& cfg_prods_file, 
                       std::ofstream& cfg_out_file);
  
  /// Operador de flujo de salida.
  friend std::ostream& operator<<(std::ostream& out, const Grammar& grammar);

 private:
  SetSymbols alphabet_; ///< Alfabeto de la gramatica.
  SetSymbols non_terminals_; ///< Conjunto de simbolos no terminales.
  char start_; ///< Simbolo de arranque.
  Productions prod_; ///< Conjunto de reglas de producción.
  bool creation_failed_; ///< nos dice si el objeto se ha creado correctamente.
};
#endif