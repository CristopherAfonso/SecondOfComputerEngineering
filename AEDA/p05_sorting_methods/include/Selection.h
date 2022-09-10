/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 5: Implementación de Métodos de Ordenación
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 21/04/2022
 * 
 * @file Selection.h 
 * @brief Donde se aloja la declaración de la clase Selection y la declaracion
 * de sus metodos. La clase Selection es una clase hija de la clase Strategy y
 * representa una instanciacion del algoritmo de ordenacion de Seleccion
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 21/04/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado los #include necesarios.
 * 23/04/22 - Archivo terminado.
 */

#ifndef _SELECTION_
#define _SELECTION_

#include "Strategy.h"

/**
 * @brief Esta clase representa la implementación del algoritmo de ordenacion
 * de seleccion
 * 
 * @tparam Key Es el tipo de dato de los datos que queremos ordenar
 */
template<class Key>
class Selection: public Strategy<Key> {
 public:
  Selection(void) = default;
  void Sort(std::vector<Key>& vec, unsigned int& n) override;
};

/// Todos metodos deberian ir en el archivo .cc pero si estan alli el
/// compilador no los reconoce y por eso los puse aqui

/**
 * @brief Implementación del algoritmo de Seleccion para ordenar datos
 * 
 * @tparam Key tipo de datos que tienen los datos a ser ordenados
 * @param vec atributo que contiene los datos a ser ordenados
 * @param n es el tamaño del parametro vec
 */
template<typename Key>
void Selection<Key>::Sort(std::vector<Key>& vec, unsigned int& n) {
  Key aux; ///< Valor a poner en la parte ordenada en cada iteracion
  for (int i{0}; i < (int(n) - 1); ++i) {
    int min_pos{i};
    for (int j{i + 1}; j < int(n); ++j) {
      if (vec[j] < vec[min_pos]) {
        min_pos = j;
        aux = vec[min_pos];
      }
    }

    vec[min_pos] = vec[i];
    vec[i] = aux;

    /// mostramos el vector por pantalla tras hacer la iteracion del algoritmo
    for (auto j: vec) std::cout << j << " ";
    std::cout << std::endl;
  }
}

#endif 