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
 * @file state_nfa.cc
 * @brief Donde se desarrollan las funciones de la clase StateNfa contenida
 * en el archivo de cabecera state_nfa.h.
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

#include "state_nfa.h"

/**
 * @fn StateNfa::StateNfa(void)
 * @brief Construye un nuevo objeto de la clase StateNfa, este es el
 * constructor por defecto, por defecto el estado actual es el máximo valor
 * posible para una variable size_t, y no se considera de aceptación.
 */
StateNfa::StateNfa(void) : state_(SIZE_MAX), transitions_(), 
                           aceptation_(false) {}

/**
 * @brief Construye un nuevo objeto de la clase StateNfa, este es el
 * constructor predeterminado, el que usaremos más, la función solo copia los
 * valores pasados a la función a sus respectivos atributos internos.
 * 
 * @param state es el estado al que representa el objeto.
 * @param aceptation indica si es un estado de aceptación.
 */
StateNfa::StateNfa(const size_t& state, const bool& aceptation)
    : state_(state), transitions_(), aceptation_(aceptation) {}

/**
 * @fn StateNfa::StateNfa(const StateNfa& state_nfa)
 * @brief Construye un nuevo objeto de la clase StateNfa, este es el
 * constructor de copia, y permite crear un objeto copiando a otro ya existente
 * 
 * @param state_nfa objeto de la clase StateNfa ya existente que sus atributos
 * internos serán copiados para inicializar cada atributo interno del objeto.
 */
StateNfa::StateNfa(const StateNfa& state_nfa) 
    : state_(state_nfa.state_), transitions_(state_nfa.transitions_), 
      aceptation_(state_nfa.aceptation_) {}

/**
 * @fn void StateNfa::SetState(const size_t& state)
 * @brief Setter de la clase StateNfa. Permite cambiar el valor del atributo
 * interno "state_" por el valor que se le pase a la función.
 * 
 * @param state valor que reemplazará al contenido de "state_".
 */
void StateNfa::SetState(const size_t& state) {
  state_ = state;
}

/**
 * @fn void StateNfa::SetAceptationState(const bool& aceptation_state)
 * @brief cambia el valor de aceptation_ por el que le pasemos al método.
 * 
 * @param aceptation_state valor que reemplazará al contenido de aceptation_
 */
void StateNfa::SetAceptationState(const bool& aceptation_state) {
  aceptation_ = aceptation_state;
}

/**
 * @fn void StateNfa::SetTransition(const Symbol& symbol, const size_t& state)
 * @brief Añade al vector asociado al símbolo, un size_t, es como añadir una
 * transición más al Nfa, el método está implementado para que no se puedan
 * introducir transiciones repetidas.
 * 
 * @param symbol es la clave asociada al vector que queremos modificar
 * @param state es el valor que vamos a añadir al vector.
 */
void StateNfa::SetTransition(const Symbol& symbol, const size_t& state) {
  if (transitions_.size() == 0) {
    std::vector<size_t> aux{state};
    transitions_.insert(std::make_pair(symbol, aux));
  } else {
    for (auto i: transitions_) {
      std::cout << i.first << '\n';
      if (i.first == symbol) return;
    }
    transitions_[symbol].emplace_back(state);
  }
}

/**
 * @fn void StateNfa::SetTransition(const std::string& symbol, 
                             const std::vector<size_t>& set_status)
 * @brief Si Symbol está dentro del std::map, cambiamos todo el vector por el
 * vector que se le pasa a la función, y si no lo está, insertamos una nueva
 * clave y el vector que la acompañará será set_status.
 * 
 * @param symbol Valor que será la clave para poder cambiar el vector que
 * tenemos en el std::map, si la clave ya existe, cambiamos su vector por el
 * que recibe la función, sino existe, añadimos un nuevo std::pair.
 * @param state Vector que será el que incluiremos en el std::map, si la clave
 * existe, cambiamos su vector por este, sino, creamos una clave con este
 * vector.
 */
void StateNfa::SetTransition(const Symbol& symbol, 
                             const std::vector<size_t>& set_status) {
  if (transitions_.find(symbol) != transitions_.end()) {
    transitions_[symbol] = set_status;
  } else {
    transitions_.insert(std::make_pair(symbol, set_status));
  }
}

/**
 * @fn size_t StateNfa::GetState(void) const
 * @brief devuelve state_ que es el identificado del estado en el que estamos.
 * 
 * @return size_t state_, es el estado que representa la clase.
 */
size_t StateNfa::GetState(void) const {
  return state_;
}

/**
 * @fn std::vector<size_t> StateNfa::GetTransitions(const Symbol& symbol) const
 * @brief esta función devuelve el conjunto de estados a los cuales desde el
 * estado actual, con el símbolo symbol, podemos llegar.
 * 
 * @param symbol es el símbolo asociado al vector que queremos obtener.
 * @return std::vector<size_t> es el vector que retornará que contiene los
 * estados a los cuales, con el símbolo symbol, partiendo del estado actual
 * podemos llegar.
 */
std::vector<size_t> StateNfa::GetTransitions(const Symbol& symbol) const {
  std::vector<size_t> aux;
  std::cout << '\n' << symbol << " Symbol" << '\n';
  for (auto i: transitions_) {
    std::cout << i.first << '\n';
    if (symbol == i.first) {
      aux = transitions_.find(symbol)->second;
      break;
    }
  }    
  return aux;
}

/**
 * @fn bool StateNfa::GetAceptationStatus(void) const
 * @brief retorna el valor de la variable aceptation_, que nos dice si el
 * estado es de aceptación, si es true, es de aceptación.
 * 
 * @return aceptation_ es el atributo interno que nos dice si es de aceptación.
 */
bool StateNfa::GetAceptationStatus(void) const {
  return aceptation_;
}

/**
 * @fn size_t StateNfa::NumTransitions(void) const
 * @brief devuelve un size_t que es la cantidad de transiciones que tiene el
 * estado en total.
 * 
 * @return size_t
 */
size_t StateNfa::NumTransitions(void) const {
  size_t result{0};
  for (auto i: transitions_) {
    result += i.second.size();
  }
  return result;
}

/**
 * @fn void StateNfa::operator=(const StateNfa& state)
 * @brief Sobrecarga del operador "=".
 * 
 * @param state es el objeto de la clase StateNfa que usaremos para coger sus
 * atributos internos y asignarlos al objeto que esté a la izquierda del
 * operador.
 */
void StateNfa::operator=(const StateNfa& state) {
  state_ = state.state_;
  transitions_ = state.transitions_;
  aceptation_ = state.aceptation_;
}

/**
 * @fn bool StateNfa::operator==(const StateNfa& state) const
 * @brief Sobrecarga del operador "==".
 * 
 * @param state es el objeto de la clase StateNfa que estará a la izquierda del
 * operador.
 * @return true, los 3 atributos internos de los objetos son iguales entre sí.
 * @return false, los 3 atributos internos de los objetos no son iguales.
 */
bool StateNfa::operator==(const StateNfa& state) const {
  return (state_ == state.state_) && (aceptation_ == state.aceptation_) && 
         (transitions_ == state.transitions_);
}

/**
 * @fn bool StateNfa::operator<(const StateNfa& state) const
 * @brief Sobrecarga del operador "<", como la clase representa estados, lo que
 * se compara son los atributos internos "state_" de cada objeto.
 * 
 * @param state es el objeto que va a la derecha del operando cuando se llama.
 * @return true, el valor del atributo "state_" del objeto que está a la
 * izquierda, es menor que el de la derecha.
 * @return false el valor del atributo "state_" del objeto que está a la
 * izquierda, es igual o mayor que el del objeto que está a la derecha.
 */
bool StateNfa::operator<(const StateNfa& state) const {
  return state_ < state.state_;
}

/**
 * @fn std::ostream& operator<<(std::ostream& out, const StateNfa& state_nfa)
 * @brief Sobrecarga del operador "<<".
 * 
 * @param out es la variable que actua como flujo de salida, equivalente a 
 * std::cout
 * @param state_nfa es el objeto que queremos que se muestre por la salida
 * estándar.
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const StateNfa& state_nfa) {
  out << "Identificador del estado: " << state_nfa.state_ << " <== ";
  out << (state_nfa.aceptation_ ? "" : "no ") << "es un estado de aceptación";
  out << "\nTransiciones:";
  for (auto i: state_nfa.transitions_) {
    out << '\n' << i.first << ":";
    for (auto j: i.second) {
      out << ' ' << j;
    }
  }
  out << '\n';
  return out;
}
