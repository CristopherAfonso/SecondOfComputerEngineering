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
 * @file symbol.cc
 * @brief Donde se desarrollan las funciones de la clase Symbol contenida
 * en el archivo de cabecera symbol.h.
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

#include "symbol.h"

/// Constructor. Por defecto, crea un Symbol vacío.
Symbol::Symbol() : symbol_() {}

/// Constructor. Crea un objeto Symbol que actua como un char.
Symbol::Symbol(const char& character) {
  symbol_ = character;
}

/// Constructor. Crea un objeto Symbol que actua como un char (pero se compone
/// de varios char).
Symbol::Symbol(const std::string& chain) : symbol_(chain) {}

/// Constructor. De copia, crea un objeto copiando a otro de la clase.
Symbol::Symbol(const Symbol& symbol) : symbol_(symbol.GetSymbol()){}

/// Setter. Para cambiar el valor del std::string de la clase, ahora nuestro
/// Symbol será como un char.
void Symbol::SetSymbol(const char& character) {
  symbol_ = character;
}

/// Setter. Para cambiar el valor de la std::string de Symbol por otra
/// std::string que le pasamos.
void Symbol::SetSymbol(const std::string& chain) {
  symbol_ = chain;
}

/// Setter. Para cambiar el valor de la std::string de Symbol por el
/// std::string de otro objeto Symbol que le pasamos a la función.
void Symbol::SetSymbol(const Symbol& symbol) {
  *this = symbol;
}

/// Setter. Para cambiar el valor de la std::string de nuestro Symbol pero en
/// vez de remplazar el std::string, simplemente le añadimos caracteres al
/// final, es decir, ampliamos su contenido.
void Symbol::EmplaceBack(const char& character) {
  symbol_ += character;
}

/// Setter. Igual que el anterior, pero en vez de un char, le pasamos a la
/// función un std::string.
void Symbol::EmplaceBack(const std::string& chain) {
  symbol_ += chain;
}

/// Setter. Igual que el anterior, pero esta vez de un std::string, le pasamos
/// un Symbol.
void Symbol::EmplaceBack(const Symbol& symbol) {
  symbol_ += symbol.symbol_;
}

/// Getter. Retorna la std::string que contiene el objeto Symbol.
std::string Symbol::GetSymbol(void) const {
  return symbol_;
}

/// Getter. Devuelve el tamaño de la std::string de Symbol.
size_t Symbol::Size(void) const {
  return symbol_.size();
}

/// Operador sobrecargado '=='. Comprueba si las std::strings son iguales.
bool Symbol::operator==(const Symbol& symbol) const {
  return symbol_ == symbol.symbol_;
}

/// Operador sobrecargado '='. Coge el std::string del Symbol que está a la
/// derecha, y lo copia en el std::string del Symbol que está a la izquierda.
void Symbol::operator=(const Symbol& symbol) {
  symbol_ = symbol.symbol_;
}

/// Operador sobrecargado '+'. Coge el valor del std::string del Symbol que
/// está a la derecha del operador, y la incrusta al final (sus caracteres),
/// al final de la std::string del Symbol que está a la izquierda.
Symbol Symbol::operator+(const Symbol& symbol) {
  symbol_ += symbol.symbol_;
}

/// Operador sobrecargado '<'. Compara las std::strings de ambos objetos, y
/// devuelve true si el de la izquierda es menor al de la derecha.
bool Symbol::operator<(const Symbol& symbol) const {
  return (symbol_ < symbol.symbol_);
}

/// Operador sobrecargado '<<'. Muestra el contenido del std::string del objeto
/// Symbol por la salida estándar.
std::ostream& operator<<(std::ostream& out, const Symbol& symbol) {
  return out << symbol.symbol_;
}

/// Operador sobrecargado '>>'. Asigna dinámicamente el contenido del objeto
/// Symbol.
std::istream& operator>>(std::istream& input, Symbol& symbol) {
  return input >> symbol.symbol_;
}
