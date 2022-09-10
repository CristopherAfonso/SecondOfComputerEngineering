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
 * @file DFRandom.h 
 * @brief Donde se aloja la declaración de la clase DFRandom y la declaracion
 * de sus metodos. La clase DFRandom es un tipo de clase hija de una clase
 * abstracta, la clase DispersionFunction la cual es la funcion de dispersion
 * de la clase, esta clase hija se encarga de definir la forma de elegir el
 * bloque de la tabla donde colocaremos el dato que será de forma aleatoria.
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

#ifndef _DFRANDOM_
#define _DFRANDOM_

#include "DispersionFunction.h"
#include <stdlib.h>
#include <ctime>

/**
 * @brief Clase que representa a un caso concreto de funcion de dispersion,
 * la cual se encarga de indicar el primer bloque en el que se deberia meter
 * el dato dado a la tabla hash, en este caso esa funcion es aleatoria, se
 * genera un numero aleatorio, y se obtiene el modulo de ese numero dividido
 * entre el numero de bloques de la tabla, y el modulo se retorna.
 * 
 * @tparam Key es el tipo de dato que guardara la tabla hash.
 */
template<class Key>
class DFRandom: public DispersionFunction<Key> {
 public:
  DFRandom(const unsigned& n);
  unsigned operator()(const Key& k) const override;

 private:
  unsigned table_size_;
};

#endif