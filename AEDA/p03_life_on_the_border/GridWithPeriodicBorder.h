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
 * @file GridWithPeriodicBorder.h 
 * @brief Donde se aloja la declaración de la clase GridWithPeriodicBorder y la
 * declaración de sus metodos. La clase GridWithPeriodicBorder es una matriz
 * dinámica de objetos Cell, la cual será el escenario de nuestro programa
 * "El Juego de la Vida" para un caso concreto de rejillas o grid.
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

#ifndef _GRIDWITHPERIODICBORDER_
#define _GRIDWITHPERIODICBORDER_

#include <iostream>
#include "Grid.h"
#include "Cell.h"

/**
 * @class GridWithPeriodicBorder.
 * @brief El Juego de la Vida consiste en una Rejilla (Grid en ingles), la cual
 * debe ser rellenada con Células (objetos tipo Cell) vivas o muertas, esta
 * clase define el objeto Grid, sus atributos y funciones, pero solo define un
 * tipo de Grid, la Grid con borde periódico.
 */
class GridWithPeriodicBorder : public Grid {
 public:
  /// Constructores.
  GridWithPeriodicBorder(void);
  GridWithPeriodicBorder(const int& kRows, const int& kCols);
  GridWithPeriodicBorder(const GridWithPeriodicBorder& grid_with_periodic_border);

  /// Destructores.
  ~GridWithPeriodicBorder(void);

  /// Setters.
  void SetCell(const int& posx, const int& posy, const Cell& cell) override;
  void SetCell(const Cell& cell) override;
  
  /// Getters.
  Cell& GetCell(const int& posx, const int& posy) override;
  const Cell& GetCell(const int& posx, const int& posy) const override;
  int GetRows(void) const override;
  int GetCols(void) const override;
  
  /// Funciones de la clase abstracta (Métodos).
  void LifeBorder(const int& kGameTurns) override;
  void NextGeneration(void) override;

  /// Operadores Sobrecargados.
  const GridWithPeriodicBorder& operator=(const GridWithPeriodicBorder& grid_with_periodic_border);

  /// Operador de flujo de salida.
  friend std::ostream& operator<<(std::ostream& out, const GridWithPeriodicBorder& grid_with_periodic_border);

 private:
  Cell** grid_with_periodic_border_{NULL};
  int rows_{2};
  int cols_{2};
};
#endif