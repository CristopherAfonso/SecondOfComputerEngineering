/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 3: La Vida en la Frontera
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 21/03/2021
 * 
 * @file StateDead.h 
 * @brief Donde se aloja la declaración de la clase StateDead y la declaracion
 * de sus metodos. La clase StateDead es una clase de 2 clases de las cuales
 * cada una representa un estado de una celula.
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

#ifndef _STATEDEAD_
#define _STATEDEAD_

#include <iostream>
#include "State.h"
#include "Cell.h"

/**
 * @brief Clase que define lo que es estar "muerta". 
 */
class StateDead : public State {
 public:
  int Neighbors(const Grid& grid, const int& i, const int& j) override;
  State* NextState(void) override;
  char GetState(void) const override;

 private:
  int neighbors_alive_{0};
  const char state_{' '};
};

#endif