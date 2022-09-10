/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 8: Árbol binario AVL
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 21/05/2022
 * 
 * @file NodoAVL.h 
 * @brief Donde se aloja la declaración de la clase NodoAVL y la declaracion
 * de sus metodos. La clase NodoAVL es una clase que implementa un nodo binario
 * de un arbol binario AVL, contiene dos punteros y un dato.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 21/05/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado los #include necesarios.
 * 21/05/22 - Archivo terminado.
 */

#ifndef _NODOAVL_
#define _NODOAVL_

#include <iostream>

#include "NodoB.h"

/**
 * @brief clase nodo explícitamente creada para la clase NodoAVL
 * 
 * @tparam tipo de dato del dato que contiene el nodo
 */
template<class Key>
class NodoAVL : public NodoB<Key> {
 public:
  NodoAVL(void);
  NodoAVL(const Key& data, NodoAVL<Key>* izdo = NULL, NodoAVL<Key>* dcho = NULL);
  ~NodoAVL() = default;

  int GetBal(void);
  NodoAVL<Key>* GetPtrIzdo(void) const;
  NodoAVL<Key>* GetPtrDcho(void) const;
  NodoAVL<Key>*& GetPtrIzdo(void);
  NodoAVL<Key>*& GetPtrDcho(void);
  void SetBal(const int& bal);
  void SetPtrIzdo(NodoAVL<Key>* &izdo = NULL);
  void SetPtrDcho(NodoAVL<Key>* &dcho = NULL);

  NodoAVL<Key>& operator=(const NodoAVL<Key>& nodo);
  template<typename T>
  friend std::ostream& operator<<(std::ostream& out, const NodoAVL<T>& nodo);

 private:
  int bal_; ///< contiene el factor de balanceo del nodo
};

/**
 * @brief Constructor por defecto de la clase
 * 
 * @tparam Key tipo de dato del dato del nodo
 */
template<typename Key>
NodoAVL<Key>::NodoAVL(void) : NodoB<Key>::NodoB(), bal_(0) {}

/**
 * @brief Construct a new Nodo A V L< Key>:: Nodo A V L object
 * 
 * @tparam Key 
 * @param data 
 * @param izdo 
 * @param dcho 
 */
template<typename Key>
NodoAVL<Key>::NodoAVL(const Key& data, NodoAVL<Key>* izdo, NodoAVL<Key>* dcho)
    : NodoB<Key>::NodoB(data, izdo, dcho), bal_(0) {}

/**
 * @brief Getter del atributo bal_
 * 
 * @tparam Key tipo de dato del dato del nodo
 * @return int es el valor de bal_
 */
template<typename Key>
int NodoAVL<Key>::GetBal(void) { return bal_; }

/**
 * @brief Metodo que devuelve el puntero izquierdo del objeto, pero una copia
 * 
 * @tparam Key tipo de dato del dato del nodo
 * @return NodoAVL<Key>* es el puntero que apunta al subarbol izquierdo
 */
template<typename Key>
NodoAVL<Key>* NodoAVL<Key>::GetPtrIzdo(void) const {
  return reinterpret_cast<NodoAVL<Key>*>(this->NodoB<Key>::GetPtrIzdo());
}

/**
 * @brief Metodo que devuelve el puntero derecho del objeto, pero una copia
 * 
 * @tparam Key tipo de dato del dato del nodo
 * @return NodoAVL<Key>* es el puntero que apunta al subarbol derecho
 */
template<typename Key>
NodoAVL<Key>* NodoAVL<Key>::GetPtrDcho(void) const {
  return reinterpret_cast<NodoAVL<Key>*>(this->NodoB<Key>::GetPtrDcho());
}

/**
 * @brief Metodo que devuelve el puntero izquierdo del objeto
 * 
 * @tparam Key tipo de dato del dato del nodo
 * @return NodoAVL<Key>*& es el puntero que apunta al subarbol izquierdo
 */
template<typename Key>
NodoAVL<Key>*& NodoAVL<Key>::GetPtrIzdo(void) {
  return reinterpret_cast<NodoAVL<Key>*&>(this->NodoB<Key>::GetPtrIzdo());
}

/**
 * @brief Metodo que devuelve el puntero derecho del objeto
 * 
 * @tparam Key tipo de dato del dato del nodo
 * @return NodoAVL<Key>*& es el puntero que apunta al subarbol derecho
 */
template<typename Key>
NodoAVL<Key>*& NodoAVL<Key>::GetPtrDcho(void) {
  return reinterpret_cast<NodoAVL<Key>*&>(this->NodoB<Key>::GetPtrDcho());
}

/**
 * @brief Setter del atributo bal_, que nos dice la diferencia de alturas entre
 * las dos ramas del nodo
 * 
 * @tparam Key tipo de dato del dato del nodo
 * @param bal nuevo valor del atributo bal_
 */
template<typename Key>
void NodoAVL<Key>::SetBal(const int& bal) { bal_ = bal; }

/**
 * @brief Setter del nodo que apunta al subarbol izquierdo
 * 
 * @tparam Key tipo de dato del dato del nodo
 * @param izdo puntero que contiene al subarbol izquierdo del nodo
 */
template<typename Key>
void NodoAVL<Key>::SetPtrIzdo(NodoAVL<Key>* &izdo) { this->NodoB<Key>::SetPtrIzdo(izdo); }

/**
 * @brief Setter del nodo que apunta al subarbol derecho
 * 
 * @tparam Key tipo de dato del dato del nodo
 * @param dcho puntero que contiene al subarbol derecho del nodo
 */
template<typename Key>
void NodoAVL<Key>::SetPtrDcho(NodoAVL<Key>* &dcho) { this->NodoB<Key>::SetPtrDcho(dcho); }

/**
 * @brief sobrecarga del operador = de la clase NodoAVL
 * 
 * @tparam Key tipo de dato del dato del nodo
 * @param nodo es el objeto del cual queremos copiar su contenido, en el objeto
 * que llama a la funcion
 * @return NodoAVL<Key>& es el objeto que llamo a la funcion despues de hacer
 * la operacion
 */
template<typename Key>
NodoAVL<Key>& NodoAVL<Key>::operator=(const NodoAVL<Key>& nodo) {
  SetBal(nodo.GetBal());
  SetData(nodo.GetData());
  SetPtrIzdo(nodo.GetPtrIzdo());
  SetPtrDcho(nodo.GetPtrDcho());
}

/**
 * @brief sobrecarga del operador <<
 * 
 * @tparam T es el tipo de dato guardado en el nodo
 * @param out es la salida estandar de la clase ostream
 * @param nodo es el nodo que contiene el dato que queremos mostrar por pantalla
 * @return std::ostream& es lo que vamos a mostrar por pantalla
 */
template<typename T>
std::ostream& operator<<(std::ostream& out, const NodoAVL<T>& nodo) {
  return out << nodo.data_;
}

#endif