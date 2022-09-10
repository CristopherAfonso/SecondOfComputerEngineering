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
 * @file EFDoubleDispersion.cc
 * @brief Donde se desarrollan las funciones de la clase EFDoubleDispersion contenida
 * en el archivo de cabecera EFDoubleDispersion.h
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

#include "../include/EFDoubleDispersion.h"

template<class Key>
EFDoubleDispersion<Key>::EFDoubleDispersion(const unsigned& n,
                                            const DispersionFunction<Key>* df)
    : table_size_(n), df_(df) {}

template<class Key>
unsigned EFDoubleDispersion<Key>::operator()(const Key& k, unsigned i) const {
  return ((k % table_size_) + i * df_(k)) % table_size_;
}
