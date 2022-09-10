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
 * @file QuickSort.h 
 * @brief Donde se aloja la declaración de la clase QuickSort y la declaracion
 * de sus metodos. La clase QuickSort es una clase hija de la clase Strategy y
 * representa una instanciacion del algoritmo de ordenacion de QuickSort
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

#ifndef _QUICKSORT_
#define _QUICKSORT_

#include "Strategy.h"

/**
 * @brief Esta clase representa la implementación del algoritmo de ordenacion
 * QuickSort
 * 
 * @tparam Key Es el tipo de dato de los datos que queremos ordenar
 */
template<class Key>
class QuickSort: public Strategy<Key> {
 public:
  void Sort(std::vector<Key>& vec, unsigned int& n) override;
  
 private:
  void QSort(std::vector<Key>& vec, int begin, int end);
  int Partition(std::vector<Key>& vec, const int& begin, const int& end);
  void Swap(Key& i, Key& j);
};

/// Todos metodos deberian ir en el archivo .cc pero si estan alli el
/// compilador no los reconoce y por eso los puse aqui

/**
 * @brief Implementación del algoritmo QuickSort para ordenar datos, como este
 * algoritmo es recursivo y la funcion virtual que heredamos de la clase
 * Strategy no se adapta del todo a lo que necesitamos, llamamos a otra funcion
 * que esta si se encarga de implementar e algoritmo como lo necesitamos
 * 
 * @tparam Key tipo de datos que tienen los datos a ser ordenados
 * @param vec atributo que contiene los datos a ser ordenados
 * @param n es el tamaño del parametro vec
 */
template<typename Key>
void QuickSort<Key>::Sort(std::vector<Key>& vec, unsigned int& n) {
  this->QSort(vec, 0, int(n - 1));
}

/**
 * @brief Funcion que implementa el algoritmo QuickSort
 * 
 * @tparam Key tipo de datos que tienen los datos a ser ordenados
 * @param vec contenedor de datos a ordenar
 * @param begin posicion del primer elemento donde empieza el subsecuencia
 * @param end posicion del ultimo elemento donde empieza la subsecuencia
 */
template<typename Key>
void QuickSort<Key>::QSort(std::vector<Key>& vec, int begin, int end) {
  if (begin >= end) return; ///< Caso base
  int pivot{this->Partition(vec, begin, end)}; ///< Particionamos el vector
  this->QSort(vec, begin, pivot - 1); ///< Ordenamos la parte izquierda
  this->QSort(vec, pivot + 1, end); ///< Ordenamos la parte derecha
}

/**
 * @brief Metodo que ordena una particion en concreta de un vector
 * 
 * @tparam Key es el tipo de dato que tienen los datos a ser ordenados
 * @param vec es el contenedor de los datos a ser ordenados
 * @param begin es la posicion inicial de la particion
 * @param end es la posicion final de la particion
 * @return int es el pivote de la particion que invoco a la funcion
 */
template<typename Key>
int QuickSort<Key>::Partition(std::vector<Key>& vec, const int& begin, const int& end) {
  int pivot{vec[begin]};
  int count{0};
  
  for (int i{begin + 1}; i <= end; ++i) if (vec[i] <= pivot) ++count;

  /// Le damos al pivote su posicion correcta
  int pivot_index{begin + count}; 
  this->Swap(vec[pivot_index], vec[begin]);

  for (auto i: vec) std::cout << i << " ";
  std::cout << std::endl;

  /// Ordenamos las partes izquierda y derecha del elemento pivote
  int i{begin};
  int j{end};
  while ((i < pivot_index) && (j > pivot_index)) {
    while (vec[i] <= pivot) ++i;
    while (vec[j] > pivot) --j;
    if ((i < pivot_index) && (j > pivot_index)) this->Swap(vec[i++], vec[j--]);
    for (auto k: vec) std::cout << k << " ";
    std::cout << std::endl;
  }

  return pivot_index;
}

/**
 * @brief Metodo que intercambia dos datos de tipo Key
 * 
 * @tparam Key tipo de dato que tienen los datos a ser ordenados
 * @param i dato 1 a intercambiarse con el dato 2
 * @param j dato 2 a intercambiarse con el dato 1
 */
template<typename Key>
void QuickSort<Key>::Swap(Key& i, Key& j) {
  Key aux{i};
  i = j;
  j = aux;
}


#endif