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
 * @file DFSum.cc
 * @brief Donde se desarrollan las funciones de la clase DFSum contenida
 * en el archivo de cabecera DFSum.h
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

#include "../include/DFSum.h"

template<class Key>
DFSum<Key>::DFSum(const unsigned& n) : table_size_(n) {}

template<class Key>
unsigned DFSum<Key>::operator()(const Key& k) const {
  int result_sum{0};
  for (const char* i{static_cast<char*>(static_cast<void*>(&k))}; i < (i + sizeof(k)); ++i) {
    result_sum += int(*i);
  }

  return result_sum % table_size_;
}
