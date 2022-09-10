/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 7: Simulacion de NFA's (Autómatas Finitos No Deterministas)
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 11/11/2021
 * 
 * @file state_nfa.h 
 * @brief Donde se aloja la declaración de la clase StateNfa y la declaracion
 * de sus metodos. La clase StateNfa tiene un std::map que contiene un Symbol,
 * a modo de clave, y cada Symbol tiene asociado un vector<size_t> que son los
 * estados a los que se puede ir con ese Symbol, un size_t que representa el
 * estado actual y, un bool que representa si el estado es de aceptación,
 * si es true, es que sí es de aceptación.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 11/11/21 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 */

#ifndef _STATE_NFA_
#define _STATE_NFA_

#include <iostream>
#include <vector>
#include <map>

#include "symbol.h"

/**
 * @class StateNfa.
 * @brief Cada objeto de esta clase actua como un estado de nuestro NFA, porque
 * cada estado tiene asociado un número, que representa qué estado es, un
 * conjunto de transiciones que representa las posibilidades que tiene el
 * estado para llevarte a otro, y un bool que nos dice si el estado es de
 * aceptación. 
 */
class StateNfa {
 public:
  /// Constructores. Hay 3, el por defecto, el predeterminado y el de copia.
  StateNfa(void);
  StateNfa(const size_t& state, const bool& aceptation);
  StateNfa(const StateNfa& state_nfa);

  /// Setters.
  void SetState(const size_t& state);
  void SetAceptationState(const bool& aceptation_state);
  void SetTransition(const Symbol& symbol, const size_t& state);
  void SetTransition(const Symbol& symbol, 
                     const std::vector<size_t>& set_status);

  /// Getters.
  size_t GetState(void) const;
  std::vector<size_t> GetTransitions(const Symbol& symbol) const;
  bool GetAceptationStatus(void) const;

  /// Funciones de la clase (Métodos).
  size_t NumTransitions(void) const;

  /// Operadores sobrecargados.
  void operator=(const StateNfa& state);
  bool operator==(const StateNfa& state) const;
  bool operator<(const StateNfa& state) const;

  /// Operador de flujo de salida.
  friend std::ostream& operator<<(std::ostream& out, const StateNfa& state_nfa);

 private:
  std::size_t state_; ///< Número que representa el estado actual.
  std::map<Symbol, std::vector<size_t>> transitions_; ///< Transiciones. 
  bool aceptation_; ///< Señala si es un estado de aceptación.
};
#endif
