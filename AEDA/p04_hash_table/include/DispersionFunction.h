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
 * @file DispersionFunction.h 
 * @brief Donde se aloja la declaración de la clase DispersionFunction y la
 * declaracion de sus metodos. La clase DispersionFunction es un tipo de clase
 * abstracta la cual sus clases hijas definiran una forma especifica de elegir
 * el bloque en cuestion en el cual se introducira el dato dado por el usuario.
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

#ifndef _DISPERSIONFUNCTION_
#define _DISPERSIONFUNCTION_

/**
 * @brief Clase que representa a una funcion de dispersion, la cual se encarga
 * de indicar el primer bloque en el que se deberia meter el dato dado a la
 * tabla hash.
 * 
 * @tparam Key es el tipo de dato que guardara la tabla hash.
 */
template<class Key>
class DispersionFunction {
 public:
  unsigned operator()(const Key& k) const = 0;
  virtual ~DispersionFunction(void) = default;
};

#endif