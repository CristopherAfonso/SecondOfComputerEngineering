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
 * @file TestOrdenation.h 
 * @brief Donde se aloja la declaración de la clase TestOrdenation y la
 * declaracion de sus metodos. La clase TestOrdenation es una clase que
 * encapsula distintos metodos de ordenacion de datos (almacenados en un
 * vector) en un solo objeto, para que dependiendo del metodo elegido, este se
 * ejecute usando el mismo objeto y simplificando el programa.
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

#ifndef _TESTORDENATION_
#define _TESTORDENATION_

#include "../include/Strategy.h"

/**
 * @brief Clase que encapsula un metodo de ordenacion de datos y unos datos, y
 * ordena los datos usando el metodo que guarda
 * 
 * @tparam Key Es el tipo de dato que tienen los datos a ordenar.
 */
template <class Key>
class TestOrdenation {
 public:
  TestOrdenation(void);
  void SetN(const unsigned int& n);
  void SetVec(const std::vector<Key>& vec);
  void SetStrategy(Strategy<Key>* strategy);
  void Execute(void);
  TestOrdenation& operator=(const TestOrdenation& test_ordenation);

 private:
  unsigned int n_;
  std::vector<Key> vec_;
  Strategy<Key>* strategy_;
};

/// Todos metodos deberian ir en el archivo .cc pero si estan alli el
/// compilador no los reconoce y por eso los puse aqui

template<typename Key>
TestOrdenation<Key>::TestOrdenation(void) : n_(0), vec_(), strategy_(NULL) {}

/**
 * @brief Setter del atributo n_, dependiendo del metodo de ordenacion, este
 * atributo tendra una u otra funcion dentro del algoritmo
 * 
 * @tparam Key Tipo de dato que tienen los datos a ser ordenados
 * @param n parametro que ayuda al algoritmo a poder ser aplicado, para saber
 * su funcionalidad exacta, deberia consultar el algoritmo particular a usar
 * para saberlo, cada algoritmo puede usar este parametro para distintos fines
 */
template<typename Key>
void TestOrdenation<Key>::SetN(const unsigned int& n) {n_ = n;}

/**
 * @brief Setter del atributo interno 'vec_', este atributo contiene los datos
 * que van a ser ordenados
 * 
 * @tparam Key tipo de dato que tienen los datos a ser ordenados (que estan
 * contenidos en el atributo interno 'vec_')
 * @param vec es el contenedor de los datos que vamos a ordenar
 */
template<typename Key>
void TestOrdenation<Key>::SetVec(const std::vector<Key>& vec) {vec_ = vec;}

/**
 * @brief Setter del atributo interno 'strategy_', este atributo decide cual
 * sera el algoritmo de ordenacion que se seguira para ordenar los datos
 * 
 * @tparam Key tipo de dato que tienen los datos a ser ordenados
 * @param strategy atributo que decide cual sera el algoritmo de ordenacion
 * que se seguira para ordenar los datos
 */
template<typename Key>
void TestOrdenation<Key>::SetStrategy(Strategy<Key>* strategy) {strategy_ = strategy;}

/**
 * @brief Metodo que se encarga de coger todos los atributos internos del
 * objeto para aplicar el algoritmo de ordenacion que se haya indicado
 * 
 * @tparam Key tipo de dato que tienen los datos a ser ordenados
 */
template<typename Key>
void TestOrdenation<Key>::Execute(void) {
  std::cout << "Vector inicial: ";
  for (auto i: vec_) std::cout << i << " ";
  std::cout << "\n\n";
  strategy_->Sort(vec_, n_);
}

/**
 * @brief Sobrecarga del operador =
 * 
 * @tparam Key es el tipo de dato de los datos que van a ser ordenados
 * @param test_ordenation es un objeto de la misma clase que el objeto que
 * invoca al metodo
 * @return TestOrdenation<Key>& se retorna el mismo objeto que invoca al metodo
 */
template<typename Key>
TestOrdenation<Key>& TestOrdenation<Key>::operator=(const TestOrdenation<Key>& test_ordenation) {
  n_ = test_ordenation.n_;
  vec_ = test_ordenation.vec_;
  strategy_ = test_ordenation.strategy_;
  return *this;
}


#endif