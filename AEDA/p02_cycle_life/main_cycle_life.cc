/**
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 2: El Ciclo de la Vida
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 13/03/2022
 * 
 * @file main_cycle_life.cc (programa cliente)
 * @brief Programa que simula el famoso "Juego de la Vida" de John Horton
 * Conway, creado en 1970, es un ejemplo de "Autómata Celular". Este programa
 * es una extensión del juego de la vida, ya que en vez de representar solo los
 * estados de "viva" y "muerta", se representan los estados de "muerta", 
 * "huevo", "larva", "pupa" y "adulta".
 * 
 * Si quiere saber mas detalles sobre como usar el programa ejecutable,
 * ejecute: ./main_game_life --help
 * para mas informacion.
 * 
 * @bug No hay bugs conocidos
 * 
 * Referencias:
 * @see
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 13/03/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 * 15/03/22 - Proyecto terminado.
 */

#include "main_functions.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::string kRows{argv[1]};
  std::string kCols{argv[2]};
  std::string kGameTurns{argv[3]};

  Grid grid(std::stoi(kRows), std::stoi(kCols));
  grid.CycleLife(std::stoi(kGameTurns));

  return 0;
}
