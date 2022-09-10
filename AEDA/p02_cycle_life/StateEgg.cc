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
 * @file StateEgg.cc
 * @brief Donde se desarrollan las funciones de la clase StateEgg contenida
 * en el archivo de cabecera StateEgg.h
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

#include "StateEgg.h"
#include "StateDead.h"
#include "StateLarva.h"

/**
 * @brief Método que calcula si una celula en estado Huevo, debe pasar a estado
 * larva o a estado muerta, si este método devuelve un número mayor o igual a
 * cero, debe pasar a estado larva, sino a estado muerta.
 * 
 * @param grid rejilla donde se halla nuestra celula.
 * @param i posición X de la celula
 * @param j posición Y de la celula
 * @return int Número de celulas en estado huevo que hay de más frente a las
 * de estado larva.
 */
int StateEgg::Neighbors(const Grid& grid, const int& i, const int& j) {
  neighbors_egg_ = 0;
  int count_egg{0};
  int count_larva{0};
  for (int offset_x{-1}; offset_x < 2; ++offset_x) {
    for (int offset_y{-1}; offset_y < 2; ++offset_y) {
      if (offset_x == 0 && offset_y == 0) continue;
      if (grid.GetCell(i + offset_x, j + offset_y).GetState() == 'H') ++count_egg;
      if (grid.GetCell(i + offset_x, j + offset_y).GetState() == 'L') ++count_larva;
    }
  }
  neighbors_egg_ = count_egg - count_larva;
  return neighbors_egg_;
}

/**
 * @brief Método que analiza el cambio de estado de en base al valor del
 * atributo interno.
 * 
 * @return State* objeto que representa el cambio de estado de nuestra celula
 */
State* StateEgg::NextState(void) {
  if (neighbors_egg_ >= 0) return new StateLarva;
  else return new StateDead;
}

/**
 * @brief Método virtual que devuelve un caracter que representa el estado de
 * la celula.
 * 
 * @return char es el caracter que representa el estado de la celula.
 */
char StateEgg::GetState(void) const {return 'H';}
