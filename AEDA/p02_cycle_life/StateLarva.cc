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
 * @file StateLarva.cc
 * @brief Donde se desarrollan las funciones de la clase StateLarva contenida
 * en el archivo de cabecera StateLarva.h
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

#include "StateLarva.h"
#include "StateDead.h"
#include "StatePupa.h"

/**
 * @brief Método que calcula si una celula en estado Larva, debe pasar a estado
 * pupa o a estado muerta, si este método devuelve un número mayor o igual a
 * cero, debe pasar a estado pupa, sino a estado muerta.
 * 
 * @param grid rejilla donde se halla nuestra celula.
 * @param i posición X de la celula
 * @param j posición Y de la celula
 * @return int Número de celulas en estado huevo, pupa y adulta que hay de más
 * frente a las de estado larva.
 */
int StateLarva::Neighbors(const Grid& grid, const int& i, const int& j) {
  neighbors_larva_ = 0;
  int count_egg_pupa_adulta{0};
  int count_larva{0};
  for (int offset_x{-1}; offset_x < 2; ++offset_x) {
    for (int offset_y{-1}; offset_y < 2; ++offset_y) {
      if (offset_x == 0 && offset_y == 0) continue;
      if (grid.GetCell(i + offset_x, j + offset_y).GetState() == 'H' ||
          grid.GetCell(i + offset_x, j + offset_y).GetState() == 'P' ||
          grid.GetCell(i + offset_x, j + offset_y).GetState() == 'A') ++count_egg_pupa_adulta;
      if (grid.GetCell(i + offset_x, j + offset_y).GetState() == 'L') ++count_larva;
    }
  }
  neighbors_larva_ = count_egg_pupa_adulta - count_larva;
  return neighbors_larva_;
}

/**
 * @brief Método que analiza el cambio de estado de en base al valor del
 * atributo interno.
 * 
 * @return State* objeto que representa el cambio de estado de nuestra celula
 */
State* StateLarva::NextState(void) {
  if (neighbors_larva_ >= 0) return new StatePupa;
  else return new StateDead;
}

/**
 * @brief Método virtual que devuelve un caracter que representa el estado de
 * la celula.
 * 
 * @return char es el caracter que representa el estado de la celula.
 */
char StateLarva::GetState(void) const {return 'L';}
