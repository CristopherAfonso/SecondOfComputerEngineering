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
 * @file State.h 
 * @brief Donde se aloja la declaración de la clase State y la declaracion
 * de sus metodos. La clase State es un tipo de clase abstracta el cual solo
 * nos sirve para heredarla y que sus métodos virtuales sean reimplementados
 * en sus clases hijas, estas clases derivadas son las que usaremos en nuestro
 * programa.
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

#ifndef _STATE_
#define _STATE_

#include <iostream>
#include "Cell.h"
#include "Grid.h"
#include "GridWithOpenBorder.h"

class Grid;
class GridWithOpenBorder;

/**
 * @brief Clase abstracta que define en nuestro programa que requerimientos
 * necesita tener un "estado".
 */
class State {
 public:
  virtual int Neighbors(const Grid& grid, const int& i, const int& j) = 0;
  virtual State* NextState(void) = 0;
  virtual char GetState(void) const = 0;
  virtual ~State(void) = default;
};

#endif