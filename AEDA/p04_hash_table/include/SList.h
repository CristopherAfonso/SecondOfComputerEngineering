/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 4: Implementación de Tabla Hash
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 03/04/2022
 * 
 * @file SList.h 
 * @brief Donde se aloja la declaración de la clase SList y la declaracion
 * de sus metodos. La clase SList es un tipo de clase hija de una clase
 * abstracta, la clase Sequence, que define la forma de implementar la propia
 * tabla y los bloques de la tabla, esta clase hija implementa la tabla hash
 * con un numero de bloques dinamico, y un tamaño de bloques dinamico.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 03/04/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado los #include necesarios.
 * 03/04/22 - Archivo terminado.
 */

#ifndef _SLIST_
#define _SLIST_

#include "Sequence.h"

/**
 * Clase que representa a una implementacion concreta de una clase Sequence que
 * es un contenedor de datos optimizado o una version concreta de la tabla hash
 * la cual tiene bloques de longitud dinamina.
 * 
 * @tparam Key es el tipo de dato que guardara la tabla hash.
 */
template<class Key>
class SList : public Sequence<Key> {
 public:
  SList(const unsigned& table_size);
  bool Search(const Key& k, const DispersionFunction<Key>* df, 
              const ExplorationFunction<Key>* ef) const override;
  bool Insert(const Key& k, const DispersionFunction<Key>* df, 
              const ExplorationFunction<Key>* ef) override;
  bool IsFull(void) const override;

 private:
  std::vector<std::vector<Key>> table_;
};

#endif