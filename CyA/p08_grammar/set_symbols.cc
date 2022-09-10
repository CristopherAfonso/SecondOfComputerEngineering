/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenierıa y Tecnologıa (ESIT)
 * Grado en Ingenierıa Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 8: Gramática para expresiones aritméticas
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 16/11/2021
 * 
 * @file set_symbols.cc
 * @brief Donde se desarrollan las funciones de la clase SetSymbols contenida
 * en el archivo de cabecera set_symbols.h.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 16/11/21 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 * 19/11/21 - Funciones de la clase terminadas.
 */

#include "set_symbols.h"

/// Constructor por defecto.
SetSymbols::SetSymbols(void) : name_("sin nombre"), set_symbols_() {}

/// Constructor personalizado, el que  más usamos.
SetSymbols::SetSymbols(const std::string& name) 
    : name_(name), set_symbols_() {}

/// Constructor de copia 1, para hacer el objeto partiendo de sus atributos.
SetSymbols::SetSymbols(const std::string& name, 
                       const std::set<char>& set_symbols)
    : name_(name), set_symbols_(set_symbols) {}

/// Costructor de copia 2, para crear un objeto partiendo de otro.
SetSymbols::SetSymbols(const SetSymbols& set_symbols) 
    : name_(set_symbols.name_), set_symbols_(set_symbols.set_symbols_) {}

/// Setter. Para cambiar el valor de un objeto con un caracter. 
void SetSymbols::Insert(const char& symbol) {
  char aux(symbol);
  set_symbols_.insert(aux);
}

/// Setter. Para cambiar el valor de un objeto con una std::string.
void SetSymbols::Insert(const std::string& symbol) {
  if (symbol.size() == 1) {
    char aux(symbol.front());
    set_symbols_.insert(aux);
  }
}

/// Setter. Para cambiar el valor del objeto partiendo de sus atributos.
void SetSymbols::SetSetSymbols(const std::string& name, 
                               const std::set<char>& set_symbols) {
  name_ = name;
  set_symbols_ = set_symbols;
}

/// Setter. Para cambiar el valor del objeto partiendo de otro.
void SetSymbols::SetSetSymbols(const SetSymbols& set_symbols) {
  name_ = set_symbols.name_;
  set_symbols_ = set_symbols.set_symbols_;
}

/// Setter. Para cambiar el valor del nombre solo.
void SetSymbols::SetName(const std::string& name) {
  name_ = name;
}

/// Getter. Para conseguir el valor del alfabeto en una posición concreta,
/// aunque es un std::set<Symbol>, actua como un std::vector<Symbol>.
char SetSymbols::At(const size_t& position) const {
  char result{};
  if (position < set_symbols_.size()) {
    size_t count{0};
    for (std::set<char>::iterator i{set_symbols_.begin()}; 
         i != set_symbols_.end(); ++i) {
      if (count == position) {
        result = *i;
        break;
      }
      ++count;
    }
  }

  return result;
}

/// Getter. Para obtener todo el alfabeto de golpe.
std::set<char> SetSymbols::GetSetSymbols(void) const {
  return set_symbols_;
}

/// Getter. Para conseguir el nombre dle alfabeto.
std::string SetSymbols::GetName(void) const {
  return name_;
}

/// Función de la clase. Comprueba si el símbolo(caracter) está en el alfabeto.
bool SetSymbols::IsItInSetSymbols(const char& symbol) const {
  bool result{false};
  for (std::set<char>::iterator i{set_symbols_.begin()}; 
       i != set_symbols_.end(); ++i) {
    if (symbol == *i) {
      result = true;
      break;
    }
  }
  return result;
}

/// Función de la clase. Igual que la anterior, pero le pasas una std::string.
bool SetSymbols::IsItInSetSymbols(const std::string& symbol) const {
  bool result{false};
  if (symbol.size() == 1) {
    char aux(symbol.front());
    for (std::set<char>::iterator i{set_symbols_.begin()}; 
      i != set_symbols_.end(); ++i) {
      if (aux == *i) {
        result = true;
        break;
      }
    }
  }
  return result;
}

/// Función de la clase. Devuelve el tamaño del alfabeto.
size_t SetSymbols::Size(void) const {
  return set_symbols_.size();
}

/// Función de la clase. Limpia el alfabeto.
void SetSymbols::Clear(void) {
  set_symbols_.clear();
}

/// Operador sobrecargado '='. Iguala los nombres y los alfabetos.
SetSymbols& SetSymbols::operator=(const SetSymbols& set_symbols) {
  set_symbols_ = set_symbols.set_symbols_;
  name_ = set_symbols.name_;
  return *this;
}

/// Operador sobrecargado '=='. Comprueba si los alfabetos son iguales.
bool SetSymbols::operator==(const SetSymbols& set_symbols) const {
  bool result{true};
  if (set_symbols_.size() == set_symbols.set_symbols_.size()) {
    size_t count{0};
    for (std::set<char>::iterator i{set_symbols_.begin()}; 
         i != set_symbols_.end(); ++i) {
      if (!(set_symbols.At(count) == *i)) {
        result = false;
        break;
      }
      ++count;
    }
  } else {
    result = false;
  }

  return result;
}

/// Operador sobrecargado '[]'. Devuelve el contenido del alfabeto en la
/// posición indicada.
char SetSymbols::operator[](const size_t position) const {
  return this->At(position);
}

/// Operador sobrecargado '<<'. Muestra el contenido del alfabeto de forma
/// clara por la salida estándar.
std::ostream& operator<<(std::ostream& out, const SetSymbols& set_symbols) {
  out << set_symbols.name_ << " = ";
  std::string aux{"{"};
  if (set_symbols.set_symbols_.size() > 0) {
    for (auto i: set_symbols.set_symbols_) {
      aux.push_back(i);
      aux += ", ";
    }
    aux.pop_back(); ///< Quitamos el último espacio.
    aux.pop_back(); ///< Quitamos la última coma.
    out << aux << '}';
  } else {
    out << "{VOID}";
  }
  
  return out;
}

/// Operador sobrecargado '>>'. Permite crear un objeto de la clase
/// dinámicamente.
std::istream& operator>>(std::istream& input, SetSymbols& set_symbols) {
  std::cout << "¿Cuál quiere que sea el nombre del alfabeto? ";
  std::string aux_str{""};
  input >> aux_str;
  set_symbols.SetName(aux_str);
  std::cout << "¿Cuántos Símbolos quiere que tenga el alfabeto? ";
  int aux{0};
  input >> aux;
  set_symbols.Clear();
  for (size_t i{0}; int(i) < aux; ++i) {
    std::cout << "Introduzca el Símbolo " << i + 1 << ": ";
    input >> aux_str;
    while (set_symbols.IsItInSetSymbols(aux_str)) {
      std::cout << "Introduzca un símbolo no repetido por favor: ";
      input >> aux_str; 
    }
    set_symbols.Insert(aux_str);
  }

  return input;
}
