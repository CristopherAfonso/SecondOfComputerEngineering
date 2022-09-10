/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 6: Árbol binario equilibrado
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 01/05/2022
 * 
 * @file AB.h 
 * @brief Donde se aloja la declaración de la clase AB y la declaracion
 * de sus metodos. La clase AB es una clase abstracta la cual es una
 * implementación del Tipo de Dato Abstracto de Arbol Binario, sus clases hijas
 * cada una es una implementación de un tipo deferente de un arbol binario,
 * esta clase define los métodos y atributos comunes a todas ellas
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 01/05/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado los #include necesarios.
 * 08/05/22 - Archivo terminado.
 */

#ifndef _AB_
#define _AB_

#include <iostream>
#include <queue>

#include "NodoB.h"
#include "dummy.h"

/**
 * @brief Clase que implementa un arbol binario generico, clase abstracta
 * 
 * @tparam Key tipo de dato del dato que se guardará en cada nodo del arbol
 */
template<class Key>
class AB {
 public:
  AB(NodoB<Key>* nodo = nullptr);
  virtual ~AB() = default;
  virtual bool Insert(const Key& data) = 0;
  virtual bool Search(const Key& data) const = 0;
  virtual bool Delete(const Key& data) = 0;
  void Inorden(NodoB<Key>* nodo);
  void InordenRoot(void);
  void Prune(NodoB<Key>* nodo);
  int Size(void) const;
  int Height(void) const;
  bool IsEmpty(const NodoB<Key>* nodo) const;
  bool IsLeaf(const NodoB<Key>* nodo) const;
  Key& operator[](const Key& pos);
  template<typename T>
  friend std::ostream& operator<<(std::ostream& out, const AB<T>* const ab);

 protected:
  NodoB<Key>* root_;
  void SetRoot(const NodoB<Key>* root);
  NodoB<Key>* GetRoot(void);
  int SizeBranch(NodoB<Key>* nodo) const;
  int HeightN(NodoB<Key>* nodo) const;
  bool SearchDataPreorder(NodoB<Key>* nodo, const Key& data) const;
  Key& SearchDataDummy(NodoB<Key>* nodo, const Key& data) const;
};

/**
 * @brief Constructor de la clase AB, constructor que usaran sus clases hijas
 * 
 * @tparam Key tipo de dato del dato que guardan los nodos del arbol
 * @param nodo nuevo nodo raiz del arbol
 */
template<typename Key>
AB<Key>::AB(NodoB<Key>* nodo) : root_(nodo) {}

/**
 * @brief Metodo que recorre todo un subarbol siguiendo el algoritmo Inorden
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es el nodo del cual empezamos a recorrre, la raiz de la busqueda
 */
template<typename Key>
void AB<Key>::Inorden(NodoB<Key>* nodo) {
  if (nodo == nullptr) return;
  this->Inorden(nodo->GetPtrIzdo());
  std::cout << nodo->GetData() << " ";
  this->Inorden(nodo->GetPtrDcho());
}

/**
 * @brief metodo que recorre todo el arbol siguiendo el algritmo Inorden
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es el nodo del cual empezamos a recorrre, la raiz de la busqueda
 */
template<typename Key>
void AB<Key>::InordenRoot(void) {
  this->Inorden(this->root_);
}

/**
 * @brief Metodo que poda una rama, desde el nodo que se le pasa a la rama
 * hasta las hojas, todos los nodos se eliminan
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo nodo que se va a podar
 */
template<typename Key>
void AB<Key>::Prune(NodoB<Key>* nodo) {
  if (nodo == nullptr) return;
  this->Prune(nodo->GetPtrIzdo()); ///< Podar Subarbol Izquierdo
  this->Prune(nodo->GetPtrDcho()); ///< Podar Subarbol Derecho
  delete nodo; ///< Eliminar Nodo
  nodo = nullptr;
}

/**
 * @brief metodo que cuenta todos los nodos del arbol
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @return const int numero de nodos en todo el arbol binario
 */
template<typename Key>
int AB<Key>::Size(void) const { return this->SizeBranch(root_); }

/**
 * @brief metodo que cuenta la profundidad de los nodos y devuelve la
 * profundidad del nodo mas profundo
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @return const int es la profundidad del nodo mas profundo
 */
template<typename Key>
int AB<Key>::Height(void) const { return this->Height(root_); }

/**
 * @brief Metodo que nos dice si el puntero contiene un nodo
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es el nodo que queremos comprobar
 * @return true el nodo pasado al metodo apunta a nullptr
 * @return false el nodo pasado al metodo apunta a un objeto de la clase NodoB
 */
template<typename Key>
bool AB<Key>::IsEmpty(const NodoB<Key>* nodo) const { return nodo == nullptr; }

/**
 * @brief metodo que comprueba si el nodo pasado es un nodo hoja
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es el objeto a comprobar si es un nodo hoja
 * @return true el nodo pasado por parametro si es un nodo hoja
 * @return false el nod pasado por parametro no es un nodo hoja
 */
template<typename Key>
bool AB<Key>::IsLeaf(const NodoB<Key>* nodo) const {
  return !nodo->GetPtrDcho() && !nodo->GetPtrIzdo();
}

template<typename Key>
Key& AB<Key>::operator[](const Key& pos) {
  return this->SearchDataDummy(this->root_, pos);
}

/**
 * @brief metodo de extraccion que muestra el arbol binario por el algoritmo de
 * niveles
 * 
 * @tparam T tipo de dato de los datos del arbol binario
 * @param out flujo de salida estandar
 * @param ab puntero que contiene a una clase hija de la clase AB el cual
 * queremos imprimir su arbol
 * @return std::ostream& el metodo retorna una serie de caracteres a imprimir
 */
template<typename T>
std::ostream& operator<<(std::ostream& out, const AB<T>* const ab) {
  std::queue<std::pair<NodoB<T>*, int>> aux_queue;
  std::pair<NodoB<T>*, int> aux_pair{ab->root_, 0};
  int current_level{0};
  aux_queue.push(aux_pair);
  while (!aux_queue.empty()) {
    aux_pair = aux_queue.front(); ///< Guardamos la parte inicial de la cola, luego la borramos
    aux_queue.pop();
    if (aux_pair.second > current_level) {
      current_level = aux_pair.second;
      out << "\n";
    }
    if (aux_pair.first == nullptr) out << "[.]";
    else {
      out << "[" << aux_pair.first->GetData() << "]";
      aux_queue.push(std::make_pair(aux_pair.first->GetPtrIzdo(), aux_pair.second + 1));
      aux_queue.push(std::make_pair(aux_pair.first->GetPtrDcho(), aux_pair.second + 1));
    }
  }
  return out;
}

/**
 * @brief Cambiamos el valor del atributo root_ por el dado al metodo
 * 
 * @tparam Key tipo de dato del arbol
 * @param root nuevo valor del atributo root_
 */
template<typename Key>
void AB<Key>::SetRoot(const NodoB<Key>* root) { root_ = root; }

/**
 * @brief Retornamos el puntero del atributo root_
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @return NodoB<Key>* puntero que apunta a la raiz del arbol
 */
template<typename Key>
NodoB<Key>* AB<Key>::GetRoot(void) { return root_; }

/**
 * @brief metodo el cual se encarga de contar todos los nodos que hay desde un
 * nodo en particular, contandolo a el, hasta llegar a las hojas del mismo
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo donde empezaremos a contar los nodos
 * @return int numero de nodos que hay a partir del puntero a nodo que se da
 */
template<typename Key>
int AB<Key>::SizeBranch(NodoB<Key>* nodo) const {
  if (nodo == nullptr) return 0;
  return (1 + this->SizeBranch(nodo->GetPtrIzdo()) + 
              this->SizeBranch(nodo->GetPtrDcho()));
}

/**
 * @brief metodo que se encarga de devolver la longitud de la rama mas profunda
 * partiendo del nodo que se le pasa como argumento
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es el nodo del que empezaremos la busqueda
 * @return int es la profundidad de la rama mas profunda partiendo del nodo
 * dado como argumento
 */
template<typename Key>
int AB<Key>::HeightN(NodoB<Key>* nodo) const {
  if (nodo == nullptr) return 0;
  int height_left{this->HeightN(nodo->GetPtrIzdo())};
  int height_right{this->HeightN(nodo->GetPtrDcho())};
  if (height_right > height_left) return height_right;
  else return height_left;
}

/**
 * @brief metodo que busca un dato en un subarbol usando el metodo de Preorder
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es donde empieza el subarbol
 * @param data es el dato a buscar
 * @return true el dato si esta en el arbol
 * @return false el adto no esta en el arbol
 */
template<typename Key>
bool AB<Key>::SearchDataPreorder(NodoB<Key>* nodo, const Key& data) const {
  bool result{false};
  if (nodo != nullptr) {
    if (data == nodo->GetData()) result = true;
    else {
      result = this->SearchDataPreorder(nodo->GetPtrIzdo(), data);
      if (!result) result = this->SearchDataPreorder(nodo->GetPtrDcho(), data);
    }
  }
  return result;
}

/**
 * @brief metodo que busca un dato en un subarbol usando el metodo de Preorder 
 * 
 * @tparam Key tipo de dato de los datos del arbol
 * @param nodo es donde empieza el subarbol
 * @param data es el dato a buscar 
 * @return Key& Es la direccion de memoria del dato en el arbol
 */
template<typename Key>
Key& AB<Key>::SearchDataDummy(NodoB<Key>* nodo, const Key& data) const {
  if (nodo != nullptr) {
    if (data == nodo->GetData()) return nodo->GetData();
    else {
      *result = this->SearchDataDummy(nodo->GetPtrIzdo(), data);
      if (result == nullptr) *result = this->SearchDataDummy(nodo->GetPtrDcho(), data);
    }
  }
  return *result;
}

#endif