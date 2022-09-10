/**
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 11: Algoritmos Voraces (Greedy)
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 27/12/2021
 * 
 * @file main_backpack.cc (programa cliente)
 * @brief Programa que dados solo 2 parametros de entrada, ofrece por pantalla
 * una solucion al famoso "problema de la mochila".
 * 
 * Si quiere saber mas detalles sobre como usar el programa ejecutable,
 * ejecute: ./main_grammar --help
 * para mas informacion.
 * 
 * @bug No hay bugs conocidos
 * 
 * Referencias:
 * @see
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 27/12/21 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 * 27/12/21 - Proyecto terminado.
 */

#include "main_functions.h"

int main(int argc, char* argv[]) {
  bool acotado{true};
  Usage(argc, argv, acotado);
  Backpack(argv, acotado);
  return 0;
}