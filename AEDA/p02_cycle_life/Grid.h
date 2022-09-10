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
 * @file Grid.h 
 * @brief Donde se aloja la declaración de la clase Grid y la declaracion
 * de sus metodos. La clase Grid es una matriz dinámica de objetos Cell, la
 * cual será el escenario de nuestro programa "El Juego de la Vida".
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

#ifndef _GRID_
#define _GRID_

#include <iostream>
#include "Cell.h"

class Cell;

/**
 * @class Grid.
 * @brief El Juego de la Vida consiste en una Rejilla (Grid en ingles), la cual
 * debe ser rellenada con Células (objetos tipo Cell) vivas o muertas, esta
 * clase define el objeto Grid, sus atributos y funciones.
 */
class Grid {
 public:
  /// Constructores.
  Grid(void);
  Grid(const int& kRows, const int& kCols);
  Grid(const Grid& grid);

  /// Destructores.
  ~Grid(void);

  /// Setters.
  void SetCell(const int& posx, const int& posy, const Cell& cell);
  void SetCell(const std::pair<int, int> postion, const Cell& cell);
  void SetCell(const Cell& cell);

  /// Getters.
  Cell GetCell(const int& posx, const int& posy) const;
  const Cell GetCell(const std::pair<int, int> position) const;
  int GetRows(void) const;
  int GetCols(void) const;

  /// Funciones de la Clase (Métodos).
  void CycleLife(const int& kGameTurns);
  void NextGeneration(void);

  /// Operadores Sobrecargados.
  const Grid& operator=(const Grid& grid);

  /// Operador de flujo de salida.
  friend std::ostream& operator<<(std::ostream& out, const Grid& grid);

 private:
  Cell** grid_{NULL};
  int rows_{2};
  int cols_{2};
};
#endif