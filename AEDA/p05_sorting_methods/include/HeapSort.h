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
 * @file HeapSort.h 
 * @brief Donde se aloja la declaración de la clase HeapSort y la declaracion
 * de sus metodos. La clase HeapSort es una clase hija de la clase Strategy y
 * representa una instanciacion del algoritmo de ordenacion de HeapSort
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

#ifndef _HEAPSORT_
#define _HEAPSORT_

#include "Strategy.h"

/**
 * @brief Esta clase representa la implementación del algoritmo de ordenacion
 * HeapSort
 * 
 * @tparam Key Es el tipo de dato de los datos que queremos ordenar
 */
template<class Key>
class HeapSort: public Strategy<Key> {
 public:
  void Sort(std::vector<Key>& vec, unsigned int& n) override;
  
 private:
  void PushDown(int i, std::vector<Key>& vec, int n);
  void Swap(Key& i, Key& j);
};

/// Todos metodos deberian ir en el archivo .cc pero si estan alli el
/// compilador no los reconoce y por eso los puse aqui

/**
 * @brief Implementación del algoritmo HeapSort para ordenar datos
 * 
 * @tparam Key tipo de datos que tienen los datos a ser ordenados
 * @param vec atributo que contiene los datos a ser ordenados
 * @param n es el tamaño del atributo vec
 */
template<typename Key>
void HeapSort<Key>::Sort(std::vector<Key>& vec, unsigned int& n) {
  std::cout << "Fase 1, inserciones\n";
  for (int i{int(n) / 2 - 1}; i >= 0; --i) {
    this->PushDown(i, vec, n);
    for (auto j: vec) std::cout << j << " ";
    std::cout << std::endl;
  }
  std::cout << std::endl;
  
  std::cout << "Fase 2, extracciones\n";
  for (int i{int(n) - 1}; i > 0; --i) {
    this->Swap(vec[0], vec[i]);
    this->PushDown(0, vec, i);
    for (auto j: vec) std::cout << j << " ";
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

/**
 * @brief Metodo que se encarga de bajar (desplazar a la derecha del vector)
 * los valores mas pequeños de un vector
 * 
 * @tparam Key tipo de datos de los datos que van a ser ordenados
 * @param i posicion en el vector del elemento que queremos bajar
 * @param vec contenedor de los datos a ordenar
 * @param n tamaño del vector
 */
template<typename Key>
void HeapSort<Key>::PushDown(int i, std::vector<Key>& vec, int n) {
  int largest{i};
  int left{2 * i + 1};
  int right{2 * i + 2};

  /// Si el hijo izquierdo es mas grande que el padre
  if ((left < n) && (vec[left] > vec[largest])) largest = left;
  
  /// Si el hijo derecho es mas grande que el mas grande hasta ahora
  if ((right < n) && (vec[right] > vec[largest])) largest = right;
  
  /// Si el mas grande no es el padre
  if (largest != i) {
    this->Swap(vec[i], vec[largest]);
  
    /// Llamamos recursivamente al sub-arbol afectado
    this->PushDown(largest, vec, n);
  }
}

/**
 * @brief Metodo que intercambia dos datos de tipo Key
 * 
 * @tparam Key tipo de dato que tienen los datos a ser ordenados
 * @param i dato 1 a intercambiarse con el dato 2
 * @param j dato 2 a intercambiarse con el dato 1
 */
template<typename Key>
void HeapSort<Key>::Swap(Key& i, Key& j) {
  Key aux{i};
  i = j;
  j = aux;
}


#endif