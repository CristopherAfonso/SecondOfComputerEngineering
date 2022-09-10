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
 * @file EFLineal.h 
 * @brief Donde se aloja la declaración de la clase EFLineal y la
 * declaracion de sus metodos. La clase EFLineal es un tipo de clase
 * hija de una clase abstracta, la cual define una forma peculiar de una
 * funcion de exploracion, esta clase hija define la funcion de exploracion en
 * base a una formula de recorrido lineal, es la mas simple de todas, si una
 * posicion esta ocupada, se prueba la siguiente, y si esta ocupada esta,
 * entonces la que viene, hasta hallar una que si este libre.
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

#ifndef _EFLINEAL_
#define _EFLINEAL_

#include "ExplorationFunction.h"

/**
 * @brief Clase que representa a una implementacion concreta de una funcion
 * de exploracion, la cual se encarga de buscar nuevos bloques para introducir
 * un dato a una tabla hash, en el caso de que el primer bloque que nos diga la
 * funcion de dispersion este lleno, esta clase hija implementa la funcion
 * lineal, simplemente retornamos el intento de la llamada a esta funcion.
 * 
 * @tparam Key es el tipo de dato que guardara la tabla hash.
 */
template<class Key>
class EFLineal: public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& k, unsigned i) const override;
};

#endif