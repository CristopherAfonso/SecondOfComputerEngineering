/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenierıa y Tecnologıa (ESIT)
 * Grado en Ingenierıa Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 7: Simulacion de NFA's (Autómatas Finitos No Deterministas)
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 11/11/2021
 * 
 * @file chain.cc
 * @brief Donde se desarrollan las funciones de la clase Chain contenida
 * en el archivo de cabecera chain.h.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 11/11/21 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include. 
 */

#include "chain.h"

/// Constructor. Por defecto, crea un objeto Chain vacío.
Chain::Chain(void) : chain_() {}

/// Constructor. Crea un objeto Chain copiando el que se le pasa.
Chain::Chain(const std::vector<Symbol>& chain) : chain_(chain) {}

/// Constructor. Crea un objeto Chain copiando el que se le pasa.
Chain::Chain(const Chain& chain) : chain_(chain.GetChain()) {}

/// Setter. Añade un Symbol(char) al final del vector.
void Chain::EmplaceBack(const char& symbol) {
  Symbol aux(symbol);
  chain_.emplace_back(aux);
}

/// Setter. Añade un Symbol(std::string) al final del vector.
void Chain::EmplaceBack(const std::string& symbol) {
  Symbol aux(symbol);
  chain_.emplace_back(aux);
}

/// Setter. Añade un Symbol al final del vector.
void Chain::EmplaceBack(const Symbol& symbol) {
  chain_.emplace_back(symbol);
}

/// Getter. Devuelve todo el vector entero.
std::vector<Symbol> Chain::GetChain(void) const {
  return chain_;
}

/// Getter. Devuelve el simbol indicado en la posición.
Symbol Chain::At(const size_t& position) const {
  if (position < chain_.size()) {
    return chain_[position];
  } else {
    Symbol aux("NULL");
    return aux;
  }
}

/// Función de la clase. Vacía el vector y su tamaño es cero ahora.
void Chain::Clear(void) {
  chain_.clear();
}

/// Función de la clase. Devuelve el tamaño del vector.
size_t Chain::Size(void) const {
  return chain_.size();
}

/// Operador sobrecargado '='. Asigna el valor de una cadena a otra ya creada.
void Chain::operator=(const Chain& chain) {
  chain_.clear();
  for (size_t i{0}; i < chain.Size(); ++i) {
    chain_.emplace_back(chain[i]);
  }
}

/// Operador sobrecargado '=='. Comprueba si las cadenas contienen los mismos
/// objetos Symbol en el mismo orden.
bool Chain::operator==(const Chain& chain) const {
  bool result{true};
  if (chain.Size() == chain_.size()) {
    for (size_t i{0}; i < chain_.size(); ++i) {
      if (!(chain_[i] == chain[i])) {
        result = false;
        break;
      }
    }
  } else {
    result = false;
  }
  return result;
}

/// Operador sobrecargado '[]'. Devuelve el Symbol en la posición indicada.
Symbol Chain::operator[](const size_t& position) const {
  return this->At(position);
}

/// Operador sobrecargado '+'. Todos los elementos de un Chain, se los pone al
/// final de otro objeto Chain, el que está a la izquierda del operador, será
/// el Chain que en su final, tendrá todos los Symbol del objeto Chain de la
/// derecha del operador.
Chain Chain::operator+(const Chain& chain) {
  for (size_t i{0}; i < chain.Size(); ++i) {
    chain_.emplace_back(chain[i]);
  }
  return *this;
}

/// Operador sobrecargado '<<'. Muestra el contenido del vector de ordenada,
/// como si se imprimiera un objeto std::string.
std::ostream& operator<<(std::ostream& out, const Chain& chain) {
  for (size_t i{0}; i < chain.Size(); ++i) {
    out << chain[i];
  }
  return out;
}

/// Operador sobrecargado '>>'. Permite crear dinámicamente un objeto Chain.
std::istream& operator>>(std::istream& input, Chain& chain) {
  size_t aux{0};
  std::cout << "¿Cuántos símbolos va a tener su cadena? ";
  std::cin >> aux;
  chain.chain_.reserve(aux);
  std::string aux_str{""};
  for (size_t i{0}; i < aux; ++i) {
    std::cout << "\nIntroduzca el símbolo " << i + 1 << ": ";
    std::cin >> aux_str;
    chain.EmplaceBack(aux_str);
  }
  
  return input;
}
