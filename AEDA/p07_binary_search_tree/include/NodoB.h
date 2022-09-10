/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 7: Árbol binario de busqueda
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 15/05/2022
 * 
 * @file NodoB.h 
 * @brief Donde se aloja la declaración de la clase NodoB y la declaracion
 * de sus metodos. La clase NodoB es una clase que implementa un nodo binario
 * de un arbol binario, contiene dos punteros y un dato.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 15/05/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado los #include necesarios.
 * 17/05/22 - Archivo terminado.
 */

#ifndef _NODOB_
#define _NODOB_

#include <iostream>

/**
 * @brief Clase que implementa un nodo binario de un arbol binario
 * 
 * @tparam Key Es el tipo de dato del dato que se guardará en el nodo
 */
template<class Key>
class NodoB {
 public:
  NodoB(void);
  NodoB(const Key& data, NodoB<Key>* izdo = NULL, NodoB<Key>* dcho = NULL);

  Key GetData(void) const;
  NodoB<Key>* GetPtrIzdo(void) const;
  NodoB<Key>* GetPtrDcho(void) const;
  NodoB<Key>*& GetPtrIzdoRef(void);
  NodoB<Key>*& GetPtrDchoRef(void);
  void SetData(const Key& data);
  void SetPtrIzdo(NodoB<Key>* izdo = NULL);
  void SetPtrDcho(NodoB<Key>* dcho = NULL);

  NodoB<Key>& operator=(const NodoB<Key>& nodo);
  template<typename T>
  friend std::ostream& operator<<(std::ostream& out, const NodoB<T>& nodo);

 private:
  Key data_;
  NodoB<Key>* izdo_;
  NodoB<Key>* dcho_;
};

/**
 * @brief Constructor por defecto de la clase NodoB
 * 
 * @tparam Key es el tipo de dato del dato que se va a guardar
 */
template<typename Key>
NodoB<Key>::NodoB(void) : data_(), izdo_(NULL), dcho_(NULL) {}

/**
 * @brief Constructor que permite inicializar la clase NodoB dandole el dato,
 * permite inicializar los punteros izdo_ y dcho_ si se quiere
 * 
 * @tparam Key tipo de dato del dato que se va a guardar
 * @param data dato que se va a guardar
 * @param izdo puntero izquierdo a otro objeto NodoB
 * @param dcho puntero derecho a otro objeto NodoB
 */
template<typename Key>
NodoB<Key>::NodoB(const Key& data, NodoB<Key>* izdo, 
                  NodoB<Key>* dcho) : data_(data), izdo_(izdo), dcho_(dcho) {}

/**
 * @brief Devuelve el dato del nodo
 * 
 * @tparam Key tipo de dato del dato del nodo
 * @return Key retorna el dato del nodo
 */
template<typename Key>
Key NodoB<Key>::GetData(void) const { return data_; }

/**
 * @brief devuelve un puntero que señala al nodo izquierdo
 * 
 * @tparam Key es el tipo de dato del dato guardado en el nodo
 * @return NodoB<Key>* Puntero que apunta al nodo izquierdo del nodo
 */
template<typename Key>
NodoB<Key>* NodoB<Key>::GetPtrIzdo(void) const { return izdo_; }

/**
 * @brief devuelve un puntero que señala al nodo derecho
 * 
 * @tparam Key es el tipo de dato del dato guardado en el nodo
 * @return NodoB<Key>* Puntero que apunta al nodo derecho del nodo
 */
template<typename Key>
NodoB<Key>* NodoB<Key>::GetPtrDcho(void) const { return dcho_; }

/**
 * @brief devuelve una referencia al puntero que señala al nodo izquierdo
 * 
 * @tparam Key es el tipo de dato del dato guardado en el nodo
 * @return NodoB<Key>*& Puntero que apunta al nodo izquierdo del nodo
 */
template<typename Key>
NodoB<Key>*& NodoB<Key>::GetPtrIzdoRef(void) { return izdo_; }

/**
 * @brief devuelve una referencia al puntero que señala al nodo derecho
 * 
 * @tparam Key es el tipo de dato del dato guardado en el nodo
 * @return NodoB<Key>*& Puntero que apunta al nodo derecho del nodo
 */
template<typename Key>
NodoB<Key>*& NodoB<Key>::GetPtrDchoRef(void) { return dcho_; }

/**
 * @brief Cambia el dato del nodo por el parametro que se le pasa al metodo
 * 
 * @tparam Key es el tipo de dato guardado en el nodo
 * @param data es el nuevo valor del dato que guarda el nodo
 */
template<typename Key>
void NodoB<Key>::SetData(const Key& data) { data_ = data; }

/**
 * @brief Cambia el valor del puntero izquierdo, por el puntero que se pase
 * como parametro, sino se pasa ningun parametro al metodo el puntero izquierdo
 * pasara a no apuntar a ningun nodo (ser nulo)
 * 
 * @tparam Key es el tipo de dato guardado en el nodo
 * @param izdo es el nuevo valor del puntero izdo_
 */
template<typename Key>
void NodoB<Key>::SetPtrIzdo(NodoB<Key>* izdo) { izdo_ = izdo; }

/**
 * @brief Cambia el valor del puntero derecho, por el puntero que se pase
 * como parametro, sino se pasa ningun parametro al metodo el puntero derecho
 * pasara a no apuntar a ningun nodo (ser nulo)
 * 
 * @tparam Key es el tipo de dato guardado en el nodo
 * @param izdo es el nuevo valor del puntero dcho_
 */
template<typename Key>
void NodoB<Key>::SetPtrDcho(NodoB<Key>* dcho) { dcho_ = dcho; }

/**
 * @brief sobrecarga del operador =
 * 
 * @tparam Key es el tipo de dato guardado en el nodo
 * @param nodo es el nodo que queremos copiar en el objeto que llama al metodo
 * @return NodoB<Key>& es el objeto que llamo al metodo retornado pero con sus
 * atributos internos ya cambiados
 */
template<typename Key>
NodoB<Key>& NodoB<Key>::operator=(const NodoB<Key>& nodo) {
  data_ = nodo.data_;
  izdo_ = nodo.izdo;
  dcho_ = nodo.dcho;
  return this;
}

/**
 * @brief sobrecarga del operador <<
 * 
 * @tparam T es el tipo de dato guardado en el nodo
 * @param out es la salida estandar de la clase ostream
 * @param nodo es el dato que queremos mostrar por pantalla
 * @return std::ostream& es lo que vamos a mostrar por pantalla
 */
template<typename T>
std::ostream& operator<<(std::ostream& out, const NodoB<T>& nodo) {
  return out << nodo.data_;
}

#endif