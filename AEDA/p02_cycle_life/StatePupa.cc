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
 * @file StatePupa.cc
 * @brief Donde se desarrollan las funciones de la clase StatePupa contenida
 * en el archivo de cabecera StatePupa.h
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

#include "StatePupa.h"
#include "StateDead.h"
#include "StateAdult.h"

/**
 * @brief Método que calcula si una celula en estado Pupa, debe pasar a estado
 * adulta o a estado muerta, si este método devuelve un número mayor o igual a
 * cero, debe pasar a estado adulta, sino a estado muerta.
 * 
 * @param grid rejilla donde se halla nuestra celula.
 * @param i posición X de la celula
 * @param j posición Y de la celula
 * @return int Número de celulas en estado muerta, huevo, pupa y adulta que hay
 * de más frente a las de estado larva.
 */
int StatePupa::Neighbors(const Grid& grid, const int& i, const int& j) {
  neighbors_pupa_ = 0;
  int count_cells_less_larva{0};
  int count_larva{0};
  for (int offset_x{-1}; offset_x < 2; ++offset_x) {
    for (int offset_y{-1}; offset_y < 2; ++offset_y) {
      if (offset_x == 0 && offset_y == 0) continue;
      if (grid.GetCell(i + offset_x, j + offset_y).GetState() == 'H' ||
          grid.GetCell(i + offset_x, j + offset_y).GetState() == 'P' ||
          grid.GetCell(i + offset_x, j + offset_y).GetState() == 'A' ||
          grid.GetCell(i + offset_x, j + offset_y).GetState() == ' ') ++count_cells_less_larva;
      if (grid.GetCell(i + offset_x, j + offset_y).GetState() == 'L') ++count_larva;
    }
  }
  neighbors_pupa_ = count_cells_less_larva - count_larva;
  return neighbors_pupa_;
}

/**
 * @brief Método que analiza el cambio de estado de en base al valor del
 * atributo interno.
 * 
 * @return State* objeto que representa el cambio de estado de nuestra celula
 */
State* StatePupa::NextState(void) {
  if (neighbors_pupa_ >= 0) return new StateAdult;
  else return new StateDead;
}

/**
 * @brief Método virtual que devuelve un caracter que representa el estado de
 * la celula.
 * 
 * @return char es el caracter que representa el estado de la celula.
 */
char StatePupa::GetState(void) const {return 'P';}