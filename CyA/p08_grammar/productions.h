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
 * @file productions.h 
 * @brief Donde se aloja la declaración de la clase Productions y la declaracion
 * de sus metodos. La clase Productions contiene un 
 * std::vector<std::pair<Symbol, std::vector<Chain>>> que será la variable que
 * usaremos a modo de alphabeto y conjunto de símbolos terminales en la clase
 * Grammar.
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

#ifndef _PRODUCTIONS_
#define _PRODUCTIONS_

#include <iostream>
#include <map>

/**
 * @class Productions.
 * @brief Una gramática debe tener producciones, que un conjunto de símbolos
 * no terminales que pueden generar otros símbolos no terminales y terminales,
 * esta clase se encarga de definir esas producciones y usarlas según convenga. 
 */
class Productions {
 public:
  /// Constructores. Tenemos el por defecto, y los dos predeterminados, y el
  /// de copia.
  Productions(void);
  Productions(const char& non_terminal, 
              std::pair<size_t, std::string> prod);
  Productions(const char& non_terminal, const size_t& num, 
              const std::string& prod);
  Productions(const Productions& prod);

  /// Setters.
  void SetProd(const std::multimap<char, std::pair<size_t, std::string>>& 
               prod);
  void SetProd(const char& non_terminal, const size_t& num, 
               const std::string& prod);
  void SetProd(const char& non_terminal, 
               std::pair<size_t, std::string>& prod);
  
  /// Getters.
  std::pair<std::multimap<char, std::pair<size_t, std::string>>::iterator,
  std::multimap<char, std::pair<size_t, std::string>>::iterator> 
  GetEqRang(const char& non_terminal);
  std::string GetProd(const char& non_terminal, const size_t& num) const;
  size_t GetUpperNumP1(const char& symbol) const;

  /// Funciones de la clase (Métodos).
  size_t Size(void) const;
  bool IsItAProduction(const char& symbol, const size_t& num) const;

  /// Operadores sobrecargados.
  Productions& operator=(const Productions& prod);

  /// Operadores de flujo de entrada y salida.
  friend std::ostream& operator<<(std::ostream& out, const Productions& prod);
  
 private:
  /// multimap que contiene todas las producciones de la gramática.
  std::multimap<char, std::pair<size_t, std::string>> prod_;
};
#endif