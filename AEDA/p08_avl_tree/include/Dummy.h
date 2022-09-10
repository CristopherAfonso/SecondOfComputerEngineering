/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 7: Árbol binario de busqueda
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 11/05/2022
 * 
 * @file Dummy.h 
 * @brief Clase de objetos pedida como modificacion durante las sesiones de
 * laboratorio de la asignatura AEDA.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 11/05/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado los #include necesarios.
 * 11/05/22 - Archivo terminado.
 */

#ifndef _DUMMY_
#define _DUMMY_

#include <iostream>

/**
 * @brief clase que hace lo que nuestro profesor pide que haga durante la
 * sesion de laboratorio de la asignatura AEDA
 */
class Dummy {
 public:
  Dummy(void);
  Dummy(const int& clave, const unsigned& dato);

  int GetClave(void) const;
  unsigned GetDato(void) const;
  unsigned GetCounter(void) const;
  void SetClave(const int& clave);
  void SetDato(const unsigned& dato);
  void SetCounter(const unsigned& counter);

  Dummy& operator=(const Dummy& dummy);
  bool operator==(const Dummy& dummy) const;
  bool operator<(const Dummy& dummy) const;
  bool operator>(const Dummy& dummy) const;
  bool operator<=(const Dummy& dummy) const;
  bool operator>=(const Dummy& dummy) const;

  friend std::istream& operator>>(std::istream& in, Dummy& dummy);
  friend std::ostream& operator<<(std::ostream& out, const Dummy& dummy);

 private:
  int clave_;
  unsigned dato_;
  static unsigned counter_;
};

#endif