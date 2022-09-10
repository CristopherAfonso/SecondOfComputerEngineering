/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenierıa y Tecnologıa (ESIT)
 * Grado en Ingenierıa Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 3: La Vida en la Frontera
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 21/03/2022
 * 
 * @file StateAlive2.cc
 * @brief Donde se desarrollan las funciones de la clase StateAlive contenida
 * en el archivo de cabecera StateAlive.h
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 21/03/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 * 22/03/22 - Funciones de la clase terminadas.
 */

#include "StateAlive.h"
#include "StateDead.h"

/**
 * @brief Método que calcula si una celula en estado Viva, debe pasar a estado
 * Muerta, si este método devuelve un número que es el número de celulas vivas
 * vecinas en un momento X.
 * 
 * @param grid rejilla donde se halla nuestra celula.
 * @param i posición X de la celula
 * @param j posición Y de la celula
 * @return int Número de celulas en estado viva que hay a nuestro alrededor
 * en un momento X.
 */
int StateAlive::Neighbors(const Grid& grid, const int& i, const int& j) {
  neighbors_alive_ = 0;
  for (int offset_x{-1}; offset_x < 2; ++offset_x) {
    for (int offset_y{-1}; offset_y < 2; ++offset_y) {
      if (offset_x == 0 && offset_y == 0) continue;
      if (grid.GetCell(i + offset_x, j + offset_y).GetState() == 'X') 
        ++neighbors_alive_;
    }
  }

  return neighbors_alive_;
}

/**
 * @brief Método que devuelve el siguiente estado del objeto.
 * 
 * @return State* es el siguiente estado del objeto.
 */
State* StateAlive::NextState(void) {
  if (neighbors_alive_ == 2 || neighbors_alive_ == 3) return new StateAlive;
  else return new StateDead;
}

/**
 * @brief Método que devuelve el estado del objeto.
 * 
 * @return char caracter que nos dice el estado de la celula
 */
char StateAlive::GetState(void) const {return state_;}