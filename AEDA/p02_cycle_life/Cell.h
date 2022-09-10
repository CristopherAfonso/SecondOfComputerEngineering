/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 2: El Ciclo de la Vida
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 13/03/2021
 * 
 * @file Cell.h 
 * @brief Donde se aloja la declaración de la clase Cell y la declaracion
 * de sus metodos. La clase Cell actúa como objeto celula, su función es tener
 * definido un estado (viva o muerta) y en base al estado de las células más
 * cercanas que tenga a su alrededor en un mismo plano (en 2D), en el siguiente
 * instante de tiempo su estado variará en base al estado de sus compañeras en
 * el instante anterior.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 13/03/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 * 15/03/22 - Funciones de la clase terminadas.
 */

#ifndef _CELL_
#define _CELL_

#include <iostream>
#include "State.h"
#include "Grid.h"

class State;
class Grid; ///< Así solucionamos el problema de la Dependencia Ciclica

/**
 * @class Cell.
 * @brief Esta clase define el objeto celula en El Juego de la Vida, sus
 * propiedades, funciones y atributos. 
 */
class Cell {
 public:
  /// Constructores.
  Cell(void);
  Cell(const char& state);
  Cell(const char& state, const std::pair<int, int>& position);
  Cell(const char& state, const int& posx, const int& posy);
  Cell(const Cell& cell);

  /// Setters.
  void SetState(State* state);
  void SetState(const char& state);
  void SetPosX(const int& posx);
  void SetPosY(const int& posy);
  void SetPos(const std::pair<int, int> position);
  void SetPos(const int& posx, const int& posy);

  /// Getters.
  char GetState(void) const;
  const std::pair<int, int> GetPosition(void) const;

  /// Funciones de la Clase (Métodos).
  void UpdateState(void);
  int Neighbors(const Grid& grid);

  /// Operadores Sobrecargados.
  const Cell& operator=(const Cell& cell);

  /// Operador de flujo de salida.
  friend std::ostream& operator<<(std::ostream& out, const Cell& cell);

 private:
  State* state_{NULL};
  std::pair<int, int> position_{-1, -1}; ///< Posiciones positivas siempre
};
#endif