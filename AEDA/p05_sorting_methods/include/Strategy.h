/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 5: Implementación de Métodos de Ordenación
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 21/04/2022
 * 
 * @file Strategy.h 
 * @brief Donde se aloja la declaración de la clase Strategy y la declaracion
 * de sus metodos. La clase Strategy es el objeto que definirá el metodo de
 * ordenacion a seguir en la clase TestOrdenation, tiene varias clases hijas
 * las cuales son cada tipo de ordenacion en particular, al usar al objeto
 * TestOrdenation, estamos usando una de estas clases hijas al ordenar los
 * datos.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 21/04/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado los #include necesarios.
 * 23/04/22 - Archivo terminado.
 */

#ifndef _STRATEGY_
#define _STRATEGY_

#include <iostream>
#include <vector>

/**
 * @brief Es el algoritmo a usar a la hora de ordenar los datos
 * 
 * @tparam Key Es el tipo de dato que tienen los datos que se van a ordenar
 */
template <class Key>
class Strategy {
 public:
  virtual void Sort(std::vector<Key>& vec, unsigned int& n) = 0;
  virtual ~Strategy() = default;
};

#endif