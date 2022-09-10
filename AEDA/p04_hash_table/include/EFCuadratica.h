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
 * @file EFCuadratica.h 
 * @brief Donde se aloja la declaración de la clase EFCuadratica y la
 * declaracion de sus metodos. La clase EFCuadratica es un tipo de clase hija
 * de una clase abstracta, la cual define una forma peculiar de una funcion de
 * exploracion, esta clase hija define la funcion de exploracion en base a una
 * formula cuadratica, le damos a la clase un número entero positivo y esta nos
 * devolvera el cuadrado de ese numero, el cual sera la posicion del nuevo
 * bloque donde deberemos situar el dato.
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

#ifndef _EFCUADRATICA_
#define _EFCUADRATICA_

#include "ExplorationFunction.h"

/**
 * @brief Clase que representa a una implementacion concreta de una funcion
 * de exploracion, la cual se encarga de buscar nuevos bloques para introducir
 * un dato a una tabla hash, en el caso de que el primer bloque que nos diga la
 * funcion de dispersion este lleno, esta clase hija implementa la funcion
 * cuadratica, simplemente retornamos el cuadrado del intento de la llamada a
 * esta funcion.
 * 
 * @tparam Key es el tipo de dato que guardara la tabla hash.
 */
template<class Key>
class EFCuadratica: public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& k, unsigned i) const override;
};

#endif