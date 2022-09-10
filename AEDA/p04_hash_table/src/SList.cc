/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenierıa y Tecnologıa (ESIT)
 * Grado en Ingenierıa Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 4: Implementación de Tabla Hash
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 03/04/2022
 * 
 * @file SList.cc
 * @brief Donde se desarrollan las funciones de la clase SList contenida
 * en el archivo de cabecera SList.h
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

#include "../include/SList.h"

template<class Key>
SList<Key>::SList(const unsigned& table_size) : table_() {
  table_.resize(table_size);
}

template<class Key>
bool SList<Key>::Search(const Key& k, const DispersionFunction<Key>* df, 
                        const ExplorationFunction<Key>* ef) const {
  bool result{false};
  unsigned aux{df(k)};
  for (auto i: table_[aux]) {
    if (k == i) {
      result = true;
      break;
    }
  }

  return result;
}

template<class Key>
bool SList<Key>::Insert(const Key& k, const DispersionFunction<Key>* df, 
                        const ExplorationFunction<Key>* ef) {
  unsigned aux{df(k)};
  for (auto i: table_[aux]) {
    if (k == i) return false;
  }

  table_[aux].emplace_back(k);
  return true;
}

template<class Key>
bool SList<Key>::IsFull(void) const {return false;}
