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
 * @file ABB.h 
 * @brief Donde se aloja la declaración de la clase ABB y la declaracion
 * de sus metodos. La clase ABB es una clase hija de la clase AB, la clase ABB
 * es una implementacion de un arbol binario de busqueda
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

#ifndef _ABB_
#define _ABB_

#include <iostream>

#include "AB.h"

/**
 * @brief implementacion de una clase que es un arbol binario de busqueda
 * 
 * @tparam Key tipo de dato de los datos del arbol binario equilibrado 
 */
template<class Key>
class ABB : public AB<Key> {
 public:
  ABB(NodoB<Key>* nodo = nullptr);
  bool Insert(const Key& data) override;
  bool Search(const Key& data) const override;
  bool Delete(const Key& data) override;
  
 private:
  bool InsertBranch(const Key& data, NodoB<Key>* &nodo = nullptr);
  bool SearchDataBinary(const Key& data, const NodoB<Key>* nodo = nullptr) const;
  bool DeleteBranch(const Key& data, NodoB<Key>* &nodo = nullptr);
  void Replace(NodoB<Key>* &deleted, NodoB<Key>* &sust);
};

/**
 * @brief Constructor de la clase ABB
 * 
 * @tparam Key tipo de dato del dato que guardan los nodos del arbol
 * @param nodo nuevo nodo raiz del arbol
 */
template<typename Key>
ABB<Key>::ABB(NodoB<Key>* nodo) : AB<Key>::AB(nodo) {}

/**
 * @brief Metodo que se encarga de insertar un nodo en el arbol en donde el
 * metodo considere que debe ir el nuevo nodo, hay que añadir que esta
 * implementacion del arbol binario no acepta añadir parametros repetidos
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param data nodo nuevo a introducir en el arbol
 * @return true el nodo se inserto correctamente en el arbol
 * @return false el nodo no se pudo insertar en el arbol
 */
template<typename Key>
bool ABB<Key>::Insert(const Key& data) {
  return this->InsertBranch(data, this->root_);
}

/**
 * @brief metodo que se encarga de buscar un dato en el arbol para comprobar si
 * se encuentra en el arbol o si este no esta en el arbol
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param data es el dato a buscar en el arbol
 * @return true el dato si se encuentra dentro del arbol
 * @return false el dato no se encuentra dentro del arbol
 */
template<typename Key>
bool ABB<Key>::Search(const Key& data) const {
  return this->SearchDataBinary(data, this->root_);
}

/**
 * @brief Metodo que se encarga de buscar en el arbol un nodo que se le pasa
 * como argumento, y si lo encuentra en el arbol, lo borra, sino lo encuentra
 * no hace nada
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param data es el nodo a buscar en el arbol para borrar
 * @return true el nodo se encontro en el arbol y se borro correctamente
 * @return false el nodo no se encontro en el arbol
 */
template<typename Key>
bool ABB<Key>::Delete(const Key& data) {
  return this->DeleteBranch(data, this->root_);
}

/**
 * @brief metodo que nos permite insertar un dato en una rama concreta de un
 * arbol binario de busqueda, recordar que si el dato a intentar insertar ya se
 * encuentra en el arbol, este devolvera falso, porque este tipo de arbol solo
 * admite insertar el mismo dato una sola vez
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param data es el dato que queremos insertar en el arbol
 * @param nodo es donde empieza la rama donde queremos insertar el dato
 * @return true el dato si se pudo insertar en la rama
 * @return false el dato no se pudo insertar en la rama
 */
template<typename Key>
bool ABB<Key>::InsertBranch(const Key& data, NodoB<Key>* &nodo) {
  if (nodo == nullptr) {
    nodo = new NodoB<Key>(data);
    return true;
  } else if (data == nodo->GetData()) {
    return false;
  } else if (data < nodo->GetData()) {
    return this->InsertBranch(data, nodo->GetPtrIzdoRef());
  } else return this->InsertBranch(data, nodo->GetPtrDchoRef());
}

/**
 * @brief metodo que busca un dato en un subarbol usando el metodo de
 * busqueda adaptado para los arboles binarios de busqueda
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param data es el dato a buscar
 * @param nodo es donde empieza el subarbol
 * @return true el dato si esta en el arbol
 * @return false el dato no esta en el arbol
 */
template<typename Key>
bool ABB<Key>::SearchDataBinary(const Key& data, 
                                const NodoB<Key>* nodo) const {
  if (nodo == nullptr) return false;
  if (data == nodo->GetData()) return true;
  if (data < nodo->GetData()) return this->SearchDataBinary(data, nodo->GetPtrIzdo());
  return this->SearchDataBinary(data, nodo->GetPtrDcho());
}

/**
 * @brief metodo que busca un dato en un subarbol binario de busqueda para
 * eliminarlo
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param data es el dato a buscar para eliminarlo
 * @param nodo es donde empieza el subarbol
 * @return true el nodo con el valor data en el arbol si fue eliminado
 * @return false no se pudo eliminar el nodo o no existe este en el arbol
 */
template<typename Key>
bool ABB<Key>::DeleteBranch(const Key& data,
                            NodoB<Key>* &nodo) {
  if (nodo == nullptr) return false;
  if (data < nodo->GetData())
    return this->DeleteBranch(data, nodo->GetPtrIzdoRef());
  else if (data > nodo->GetData())
    return this->DeleteBranch(data, nodo->GetPtrDchoRef());
  else { ///< data == nodo->GetData()
    NodoB<Key>* deleted = nodo;
    if (nodo->GetPtrDchoRef() == nullptr) nodo = nodo->GetPtrIzdoRef();
    else if (nodo->GetPtrIzdoRef() == nullptr) nodo = nodo->GetPtrDchoRef();
    else this->Replace(deleted, nodo->GetPtrIzdoRef());
    deleted->~NodoB();
    deleted = nullptr;
    return true;
  }
}

/**
 * @brief Metodo que dado un puntero de un objeto que va a ser eliminado y un
 * puntero de otro objeto que va a ser reemplazado, cambia los valores en el
 * arbol para que tras la eliminacion se mantenga la propiedad del arbol
 * binario de busqueda
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param deleted es el puntero del objeto a borrar
 * @param sust es el puntero al objeto a sustituir
 * @return true los objetos en el arbol se reestructuraron adecuadamente
 * @return false no se modifico nada en el arbol
 */
template<typename Key>
void ABB<Key>::Replace(NodoB<Key>* &deleted, NodoB<Key>* &sust) {
  if (sust->GetPtrDcho() != nullptr)
    this->Replace(deleted, sust->GetPtrDchoRef());
  else {
    deleted->SetData(sust->GetData());
    deleted = sust;
    sust = sust->GetPtrIzdoRef();
  }
}

#endif