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
 * @file RadixSort.h 
 * @brief Donde se aloja la declaración de la clase RadixSort y la declaracion
 * de sus metodos. La clase RadixSort es una clase hija de la clase Strategy y
 * representa una instanciacion del algoritmo de ordenacion de RadixSort
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

#ifndef _RADIXSORT_
#define _RADIXSORT_

#include "Strategy.h"

/**
 * @brief Esta clase representa la implementación del algoritmo de ordenacion
 * RadixSort
 * 
 * @tparam Key Es el tipo de dato de los datos que queremos ordenar
 */
template<class Key>
class RadixSort: public Strategy<Key> {
 public:
  void Sort(std::vector<Key>& vec, unsigned int& n) override;

 private:
  int GetMaxItem(const std::vector<Key>& vec, const unsigned int& n) const;
  void CountSort(std::vector<Key>& vec, unsigned int& n, unsigned int& exp);
};

/// Todos metodos deberian ir en el archivo .cc pero si estan alli el
/// compilador no los reconoce y por eso los puse aqui

/**
 * @brief Implementación del algoritmo RadixSort para ordenar datos
 * 
 * @tparam Key tipo de datos que tienen los datos a ser ordenados
 * @param vec atributo que contiene los datos a ser ordenados
 * @param n es el tamaño del parametro vec
 */
template<typename Key>
void RadixSort<Key>::Sort(std::vector<Key>& vec, unsigned int& n) {
  int max_item{this->GetMaxItem(vec, n)};

  /// Haga una clasificación de conteo para cada dígito
  /// Tenga en cuenta que en lugar de pasar el número de dígito, se pasa exp
  /// exp es 10^i donde i es el número de dígito actual
  for (unsigned int exp{1}; (max_item / int(exp)) > 0; exp *= 10) {
    this->CountSort(vec, n, exp);
    std::cout << "\n";
  }
}

/**
 * @brief Metodo que halla el elemento de mayor valor dentro del parametro vec
 * y lo retorna
 * 
 * @tparam key es el tipo de datos de los datos a ser ordenados
 * @param vec contenedor de datos a ser ordenados
 * @param n tamaño del contenedor de datos
 * @return int elemento de mayor valor dentro del parametro vec
 */
template <typename Key>
int RadixSort<Key>::GetMaxItem(const std::vector<Key>& vec, const unsigned int& n) const {
  int max_item{vec[0]};
  for (int i{1}; i < int(n); ++i) if (vec[i] > max_item) max_item = vec[i];
  return max_item;
}

/**
 * @brief Metodo que se encarga de implementar el algoritmo RadixSort
 * 
 * @tparam Key tipo de dato de los datos que van a ser ordenados
 * @param vec contenedor de datos
 * @param n tamaño del parametro vec
 * @param exp es un numero multiplo de 10 donde su exponente es el numero del
 * digito actual como base para la ordenacion
 */
template<typename Key>
void RadixSort<Key>::CountSort(std::vector<Key>& vec, unsigned int& n, unsigned int& exp) {
  std::vector<Key> output(n);
  std::vector<int> count(10, 0);

  /// Almacena las cuenta de concurrencias en count
  for (int i{0}; i < int(n); ++i) count[(vec[i] / exp) % 10]++;

  /// Cambia count[i] asi que count[i] ahora contiene la posicion actual de
  /// este digito en output[]
  for (int i{1}; i < 10; ++i) count[i] += count[i - 1];

  /// Construye el array output
  for (int i{int(n) - 1}; i >= 0; --i) {
    output[count[(vec[i] / exp) % 10] - 1] = vec[i];
    count[(vec[i] / exp) % 10]--;

    for (auto j: output) if (j != 0) std::cout << j << " ";
    std::cout << std::endl;
  }

  /// Copia el array output a vec, asi ahora vec ahora contiene los elementos
  /// ordenados acorde a los digitos actuales
  for (int i{0}; i < int(n); ++i) vec[i] = output[i];
}


#endif