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
 * @file Grid.cc
 * @brief Donde se desarrollan las funciones de la clase Grid
 * contenida en el archivo de cabecera Grid.h
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

#include "Grid.h"

/**
 * @brief Metodo que actualiza todas las celulas que hay en la rejilla del
 * estado 't' al estado 't + 1' segun las normas de transicion de estados
 * definida en el metodo "UpdateState" de la clase 'Cell'
 */
void Grid::NextGeneration(void) {
  for (int i{1}; i < (rows_ - 1); ++i) {
    for (int j{1}; j < (cols_ - 1); ++j) {
      this->GetCell(i, j).Neighbors(*this);
    }
  }
 
  for (int i{1}; i < (rows_ - 1); ++i) {
    for (int j{1}; j < (cols_ - 1); ++j) {
      this->GetCell(i, j).UpdateState();
    }
  }
}