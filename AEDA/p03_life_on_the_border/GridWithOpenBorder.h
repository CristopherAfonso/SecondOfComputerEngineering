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
 * @file GridWithOpenBorder.h 
 * @brief Donde se aloja la declaración de la clase GridWithOpenBorder y la
 * declaración de sus metodos. La clase GridWithOpenBorder es una matriz
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

#ifndef _GRIDWITHOPENBORDER_
#define _GRIDWITHOPENBORDER_

#include "Grid.h"
#include "Cell.h"

class Cell; ///< requiere ser declarado para que el make no nos dé error

/**
 * @class GridWithOpenBorder.
 * @brief El Juego de la Vida consiste en una Rejilla (Grid en ingles), la cual
 * debe ser rellenada con Células (objetos tipo Cell) vivas o muertas, esta
 * clase define el objeto Grid, sus atributos y funciones, pero solo define un
 * tipo de Grid, la Grid con borde abierto.
 */
class GridWithOpenBorder : public Grid {
 public:
  /// Constructores.
  GridWithOpenBorder(void);
  GridWithOpenBorder(const int& kRows, const int& kCols);
  GridWithOpenBorder(const GridWithOpenBorder& grid_with_open_border);

  /// Destructores.
  ~GridWithOpenBorder(void);

  /// Setters.
  void SetCell(const int& posx, const int& posy, const Cell& cell);
  void SetCell(const Cell& cell);

  /// Getters.
  Cell& GetCell(const int& posx, const int& posy);
  const Cell& GetCell(const int& posx, const int& posy) const;
  int GetRows(void) const;
  int GetCols(void) const;

  /// Funciones de la Clase (Métodos).
  void LifeBorder(const int& kGameTurns) override;
  void NextGeneration(void);

  /// Operadores Sobrecargados.
  const GridWithOpenBorder& operator=(const GridWithOpenBorder& grid_with_open_border);

  /// Operador de flujo de salida.
  friend std::ostream& operator<<(std::ostream& out, const GridWithOpenBorder& grid_with_open_border);

 private:
  Cell** grid_with_open_border_{NULL};
};
#endif