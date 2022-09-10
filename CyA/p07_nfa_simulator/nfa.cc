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
 * @file nfa.cc
 * @brief Donde se desarrollan las funciones de la clase Nfa contenida
 * en el archivo de cabecera nfa.h.
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

#include "nfa.h"

Nfa::Nfa(void) 
    : alphabet_(), all_status_(), initial_state_(), creation_failed_() {}

Nfa::Nfa(std::ifstream& nfa_def) 
    : alphabet_(), all_status_(), initial_state_(), creation_failed_(false) {
  std::vector<std::string> file;
  std::string aux_chain{""};
  int num_transitions{-1}; 
  size_t count_lines{0};
  Symbol symbol;

  /// Leemos todo el archivo de entrada para almacenarlo.
  while (!nfa_def.eof()) {
    getline(nfa_def, aux_chain);
    file.emplace_back(aux_chain);
  }
  
  /// Iteramos por cada línea del archivo.
  for (size_t i{0}; i < file.size(); ++i) {
    if (file[i] == "" || file[i].front() == ' ') continue;
    std::istringstream act_line(file[i]);
    aux_chain = "";
    ++count_lines;

    /// Caso para cuando leemos la línea 1.
    if (count_lines == 1) {
      
    }
}

Nfa::Nfa(const Nfa& nfa)
    : alphabet_(nfa.alphabet_), all_status_(nfa.all_status_), 
      initial_state_(nfa.initial_state_) {}

Alphabet Nfa::GetAlphabet(void) const {
  return alphabet_;
}

std::set<StateNfa> Nfa::GetAllStatus(void) const {
  return all_status_;
}

StateNfa Nfa::GetInitialState(void) const {
  return initial_state_;
}

bool Nfa::Fail(void) const {
  return creation_failed_;
}

bool Nfa::IsItInAlphabet(const Chain& chain) const {
  bool result{true};
  for (size_t i{0}; i < chain.Size(); ++i) {
    if (!alphabet_.IsItInAlphabet(chain[i])) {
      result = false;
      break;
    }
  }
  return result;
}

bool Nfa::EvalStr(const Chain& chain, const StateNfa& act_state) const {
  if (chain.Size() == 0) {
    return act_state.GetAceptationStatus();
  } else {
    bool result{false};
    for (size_t i{0}; i < chain.Size(); ++i) {

    }
  if (act_state.GetAceptationStatus()) result = true;
  return result;
  } 
}

void Nfa::EvalStrInFile(std::ifstream& input, std::ofstream& out) const {
  std::vector<std::string> vec_words;
  std::string aux_chain{""};
  while (!input.eof()) {
    getline(input, aux_chain);
    vec_words.emplace_back(aux_chain);
  }

  for (size_t i{0}; i < vec_words.size(); ++i) {
    Chain chain;
    std::istringstream aux_stringstream(vec_words[i]);
    for (size_t j{0}; j < vec_words[i].size(); ++j) {
      Symbol temp(vec_words[i][j]);
      chain.EmplaceBack(temp);
    }

    if (chain[0].GetSymbol() == "&" && chain.Size() == 1) {
      out << "& -- Accepted\n";
      continue;
    } else {
      if (!this->IsItInAlphabet(chain)) {
        out << chain << " -- Rejected (no está en el alfabeto)\n";
        continue;
      }
    }
    

    if (this->EvalStr(chain)) {
      out << chain << " -- Accepted";
    } else {
      out << chain << " -- Rejected";
    }

    if (i != (vec_words.size() - 1)) out << std::endl;
  }
}

/**
 * @fn std::string Nfa::ShowAllStatus(void) const
 * @brief devuelve un std::string que contiene los estados actuales que posee
 * el conjunto.
 * 
 * @return std::string.
 */
std::string Nfa::ShowAllStatus(void) const {
  std::string result{"Conjunto de estados totales del NFA = {"};
  if (all_status_.size() == 0) {
    result += "VOID}";
  } else {
    for (auto i: all_status_) {
    result += std::to_string(i.GetState()) + ", ";
    }
    result.pop_back();
    result.pop_back();
  }
  return result;
}

/**
 * @fn std::ostream& operator<<(std::ostream& out, const Nfa& nfa)
 * @brief Sobrecarga del operador "<<", muestra por la salida estándar, todos
 * los datos relacionados con el NFA.
 * 
 * @param out variable de flujo de salida, similar a "std::cout"
 * @param nfa objeto de la clase NFA al cual sus atributos internos se
 * mostraran por la salida estándar.
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const Nfa& nfa) {
  out << "Este Autómata Finito Determinista (AFN o DFA) está compuesto por";
  out << "\nuna colección de 5 elementos:";
  out << "\n\n1. Un alfabeto de entrada (Sigma):";
  out << "\n   " << nfa.alphabet_; 
  out << "\n\n2. Una colección finita de estados Q:";
  out << "\n   " << nfa.ShowAllStatus();
  out << "\n\n3. Un estado inicial 's': " << nfa.initial_state_;
  out << "\n\n4. Una colección F de estados finales o de aceptación:";
  out << "\n   " << nfa.ShowAcepStatus();
  out << "\n\n5. Una función de transición de estados: Q x (Símb. Alf.) ==> Q";
  out << "\n   que determina el único estado siguiente para el";
  out << "\n   par (Qi, simb.) correspondiente al estado actual y la entrada:";
  out << nfa.ShowTransFunc();
  return out;
}
