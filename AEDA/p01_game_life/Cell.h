/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 1: El Juego de la Vida
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 05/03/2021
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
 * 05/03/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 * 06/03/22 - Funciones de la clase terminadas.
 */

#ifndef _CELL_
#define _CELL_

#include <iostream>

class Grid; ///< Así solucionamos el problema de la Dependencia Ciclica
typedef int State; ///< Por si hay que cambiar el tipo de dato de Alive de Cell 

/**
 * @class Cell.
 * @brief Esta clase define el objeto celula en El Juego de la Vida, sus
 * propiedades, funciones y atributos. 
 */
class Cell {
 public:
  /// Constructores.
  Cell(void);
  Cell(const State& state);
  Cell(const State& state, const std::pair<int, int>& position);
  Cell(const State& state, const int& posx, const int& posy);
  Cell(const Cell& cell);

  /// Setters.
  void SetState(const State& state);
  void SetPosX(const int& posx);
  void SetPosY(const int& posy);
  void SetPos(const std::pair<int, int> position);
  void SetPos(const int& posx, const int& posy);
  void SetNeighborsAlive();

  /// Getters.
  State GetState(void) const;
  const std::pair<int, int> GetPosition(void) const;
  int GetNeighborsAlive(void) const;

  /// Funciones de la Clase (Métodos).
  void UpdateState(void);
  void NeighborsAlive(const Grid& grid);

  /// Operadores Sobrecargados.
  const Cell& operator=(const Cell& cell);

  /// Operador de flujo de salida.
  friend std::ostream& operator<<(std::ostream& out, const Cell& cell);

 private:
  State state_{0}; ///< Inicialización muerta, 1 es viva
  std::pair<int, int> position_{-1, -1}; ///< Posiciones positivas siempre
  int neighbors_alive_{0}; ///< Nos ayudará a transitar de un instante a otro
};
#endif