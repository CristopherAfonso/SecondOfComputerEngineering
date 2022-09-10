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
 * @file Sequence.h 
 * @brief Donde se aloja la declaración de la clase Sequence y la declaracion
 * de sus metodos. La clase Sequence es un tipo de clase abstracta que define
 * la forma de implementar una tabla hash.
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

#ifndef _SEQUENCE_
#define _SEQUENCE_

#include <iostream>
#include <vector>

#include "DispersionFunction.h"
#include "ExplorationFunction.h"

/**
 * @brief Clase que representa a un almacen donde se contendran los valores de
 * claves sinonimos.
 * 
 * @tparam Key es el tipo de dato que guardara la tabla hash. 
 */
template<class Key>
class Sequence {
 public:
  bool Search(const Key& k, const DispersionFunction<Key>* df, 
              const ExplorationFunction<Key>* ef) const = 0;
  bool Insert(const Key& k, const DispersionFunction<Key>* df, 
              const ExplorationFunction<Key>* ef) = 0;
  bool IsFull(void) const = 0;
  virtual ~Sequence(void) = default;
};

#endif