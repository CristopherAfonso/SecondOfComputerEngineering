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
 * @file ExplorationFunction.h 
 * @brief Donde se aloja la declaración de la clase ExplorationFunction y la
 * declaracion de sus metodos. La clase ExplorationFunction es un tipo de clase
 * abstracta la cual define la forma en la que se tiene que buscar un bloque de
 * la tabla hash libre en el caso, de que al intentar insertar un dato en el
 * primer bloque que nos dice la funcion de dispersion, este bloque este lleno,
 * esta funcion nos dice cual es el siguiente bloque al que hay que intentar
 * acceder, y si esta lleno, el siguiente al que hay que intentar acceder, y
 * asi hasta que o hallemos uno libre o se sobrepase el numero de intentos.
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

#ifndef _EXPLORATIONFUNCTION_
#define _EXPLORATIONFUNCTION_

/**
 * @brief Clase que representa a una funcion de exploracion, la cual se encarga
 * de buscar nuevos bloques para introducir un dato a una tabla hash, en el
 * caso de que el primer bloque que nos diga la funcion de dispersion este
 * lleno.
 * 
 * @tparam Key es el tipo de dato que guardara la tabla hash.
 */
template<class Key>
class ExplorationFunction {
 public:
  unsigned operator()(const Key& k, unsigned i) const = 0;
  virtual ~ExplorationFunction(void) = default;
};

#endif