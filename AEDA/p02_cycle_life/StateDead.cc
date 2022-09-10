/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenierıa y Tecnologıa (ESIT)
 * Grado en Ingenierıa Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 2: El Ciclo de la Vida
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 13/03/2022
 * 
 * @file StateDead.cc
 * @brief Donde se desarrollan las funciones de la clase StateDead contenida
 * en el archivo de cabecera StateDead.h
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

#include "StateDead.h"
#include "StateEgg.h"

/**
 * @brief Método que calcula el número de celulas vecinas que tiene un estado
 * adulta
 * 
 * @param grid rejilla donde se halla nuestra celula.
 * @param i posición X de la celula
 * @param j posición Y de la celula
 * @return int Número de celulas que tienen un estado adulta.
 */
int StateDead::Neighbors(const Grid& grid, const int& i, const int& j) {
  neighbors_dead_ = 0;
  for (int offset_x{-1}; offset_x < 2; ++offset_x) {
    for (int offset_y{-1}; offset_y < 2; ++offset_y) {
      if (offset_x == 0 && offset_y == 0) continue;
      if (grid.GetCell(i + offset_x, j + offset_y).GetState() == 'A') ++neighbors_dead_;
    }
  }

  return neighbors_dead_;
}

/**
 * @brief Método que analiza el cambio de estado de en base al valor del
 * atributo interno.
 * 
 * @return State* objeto que representa el cambio de estado de nuestra celula
 */
State* StateDead::NextState(void) {
  if (neighbors_dead_ > 1) return new StateEgg;
  else return new StateDead;
}

/**
 * @brief Método virtual que devuelve un caracter que representa el estado de
 * la celula.
 * 
 * @return char es el caracter que representa el estado de la celula.
 */
char StateDead::GetState(void) const {return ' ';}
