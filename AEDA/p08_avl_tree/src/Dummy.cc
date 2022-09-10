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
 * @file Dummy.cc 
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

#include "../include/Dummy.h"

Dummy::Dummy(void) : clave_(1), dato_(0) {}

Dummy::Dummy(const int& clave, const unsigned& dato) : clave_(clave), dato_(dato) {}

int Dummy::GetClave(void) const { return clave_; }

unsigned Dummy::GetDato(void) const { return dato_; }

unsigned Dummy::GetCounter(void) const { return counter_; }

void Dummy::SetClave(const int& clave) { clave_ = clave; }

void Dummy::SetDato(const unsigned& dato) { dato_ = dato; }

void Dummy::SetCounter(const unsigned& counter) { counter_ = counter; }

Dummy& Dummy::operator=(const Dummy& dummy) {
  this->clave_ = dummy.clave_;
  this->dato_ = dummy.dato_;
  return *this;
}

bool Dummy::operator==(const Dummy& dummy) const {
  ++counter_;
  if (clave_ == dummy.GetClave()) return true;
  else return false;
}

bool Dummy::operator<(const Dummy& dummy) const {
  ++counter_;
  if (clave_ < dummy.GetClave()) return true;
  else return false;
}

bool Dummy::operator>(const Dummy& dummy) const {
  ++counter_;
  if (clave_ > dummy.GetClave()) return true;
  else return false;
}

bool Dummy::operator<=(const Dummy& dummy) const {
  ++counter_;
  if (clave_ <= dummy.GetClave()) return true;
  else return false;
}

bool Dummy::operator>=(const Dummy& dummy) const {
  ++counter_;
  if (clave_ >= dummy.GetClave()) return true;
  else return false;
}

std::istream& operator>>(std::istream& in, Dummy& dummy) {
  int clave;
  unsigned dato;
  in >> clave;
  dummy.SetClave(clave);
  in >> dato;
  dummy.SetDato(dato);
  return in;
}

std::ostream& operator<<(std::ostream& out, const Dummy& dummy) {
  return out << dummy.GetClave();
}
