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
 * @file DFModulo.h 
 * @brief Donde se aloja la declaración de la clase DFModulo y la declaracion
 * de sus metodos. La clase DFModulo es un tipo de clase hija de una clase
 * abstracta, la clase DispersionFunction la cual es la funcion de dispersion
 * de la clase, esta clase hija se encarga de definir la forma de elegir el
 * bloque de la tabla donde colocaremos el dato que será con la operacion
 * modulo o resto de una division entera.
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

#ifndef _DFMODULO_
#define _DFMODULO_

#include "DispersionFunction.h"

/**
 * @brief Clase que representa a un caso concreto de funcion de dispersion,
 * la cual se encarga de indicar el primer bloque en el que se deberia meter
 * el dato dado a la tabla hash, en este caso esa funcion es el modulo, el dato
 * pasado al objeto se le aplica el modulo de una division entera y lo retorna.
 * 
 * @tparam Key es el tipo de dato que guardara la tabla hash.
 */
template<class Key>
class DFModule: public DispersionFunction<Key> {
 public:
  DFModule(const unsigned& n);
  unsigned operator()(const Key& k) const override;

 private:
  unsigned table_size_;
};

#endif