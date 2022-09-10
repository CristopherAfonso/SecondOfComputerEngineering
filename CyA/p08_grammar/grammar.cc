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
 * @file grammar.cc
 * @brief Donde se desarrollan las funciones de la clase Grammar contenida
 * en el archivo de cabecera grammar.h.
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

#include "grammar.h"

/**
 * @fn Grammar::Grammar(void)
 * @brief Construye un nuevo objeto de la clase Grammar todos con su 
 * constructor por defecto.
 */
Grammar::Grammar(void) : alphabet_(), non_terminals_(), start_(), prod_(), 
                         creation_failed_(false) {}

/**
 * @fn Grammar::Grammar(const std::set<char>& alphabet, 
 *              const std::set<char>& non_terminals,
 *              const char& start, 
 *              const std::multimap<char, std::pair<size_t, std::string>>& 
 *              prod)
 * @brief Construye un nuevo objeto Grammar a partir de los parámetros pasados
 * al constructor.
 * 
 * @param alphabet conjunto de datos tipo 'char' que actuarán como nuestro
 * alfabeto.
 * @param non_terminals conjunto de datos tipo 'char' que actuarán como los
 * símbolos no terminales de nuestro alfabeto.
 * @param start símbolo de arranque de nuestra gramática.
 * @param prod conjunto de reglas para que la gramática genera cadenas.
 */
Grammar::Grammar(const std::set<char>& alphabet, 
                 const std::set<char>& non_terminals,
                 const char& start, 
                 const std::multimap<char, std::pair<size_t, std::string>>& 
                 prod) 
    : alphabet_(), non_terminals_(), start_(), prod_(), 
      creation_failed_(false) {
  const std::string alphabet_name{"Alfabeto"};
  const std::string non_terminals_name{"No terminales"};
  alphabet_.SetSetSymbols(alphabet_name, alphabet);
  non_terminals_.SetSetSymbols(non_terminals_name, non_terminals);
  start_ = start;
  prod_.SetProd(prod);
}

/**
 * @fn Grammar::Grammar(
 *              const SetSymbols& alphabet, const SetSymbols& non_terminals,
 *              const char& start, const Productions& prod)
 * @brief Construye un nuevo objeto Grammar a partir de los parámetros pasados
 * al constructor.
 * 
 * @param alphabet conjunto de datos tipo 'char' que actuarán como nuestro
 * alfabeto, esos datos tipo char están dentro del objeto SetSymbols.
 * @param non_terminals conjunto de datos tipo 'char' que actuarán como los
 * símbolos no terminales de nuestro alfabeto, esos datos tipo char están 
 * dentro del objeto SetSymbols.
 * @param start símbolo de arranque de nuestra gramática.
 * @param prod conjunto de reglas para que la gramática genera cadenas, estas
 * reglas están dentro del objeto Productions en un std::multimap.
 */
Grammar::Grammar(const SetSymbols& alphabet, const SetSymbols& non_terminals,
                 const char& start, const Productions& prod) 
    : alphabet_(), non_terminals_(), start_(), prod_(), 
      creation_failed_(false) {
  alphabet_ = alphabet;
  non_terminals_ = non_terminals;
  start_ = start;
  prod_ = prod;
}

/**
 * @fn Grammar::Grammar(const Grammar& grammar)
 * @brief Construye un nuevo objeto Grammar a partir de otro ya existente.
 * 
 * @param grammar objeto de la clase Grammar que se le pasa a la función para
 * que con sus atributos internos inicializen al objeto nuevo.
 */
Grammar::Grammar(const Grammar& grammar) 
    : alphabet_(grammar.alphabet_), non_terminals_(grammar.non_terminals_), 
      start_(grammar.start_), prod_(grammar.prod_), 
      creation_failed_(grammar.creation_failed_) {}

/**
 * @fn Grammar::Grammar(std::ifstream& CFGFile)
 * @brief Construye un nuevo objeto Grammar a partir de un archivo donde se
 * especifican los elementos de este.
 * 
 * @param CFGFile Archivo (de texto) donde se describen los elementos de cada
 * objeto interno de la gramática.
 */
Grammar::Grammar(std::ifstream& CFGFile) 
    : alphabet_("Alfabeto"), non_terminals_("Símbolos No Terminales"), 
      start_(), prod_(), creation_failed_(false) {
  std::string aux_str{""};
  size_t count{0}; ///< cuenta las líneas que se leen.
  std::regex line_only_spaces("^\\s*$");
  std::regex set_symbols_pattern("^\\s*?(([^\\s])\\s)*?\\s*?$");
  std::regex prods_pattern("^\\s*?([^\\s]) -> \\s*(.*?)\\s*?$");
  std::smatch prods_match;

  /// a la vez que leemos una línea, la analizamos y incluimos en la clase.
  while (!CFGFile.eof()) {
    getline(CFGFile, aux_str);

    if (aux_str.empty() || regex_match(aux_str, line_only_spaces)) continue;
    ++count;

    /// analizamos las lineas que contienen descripciones de producciones.
    if (count > 2) {
      /// si la linea está mal escrita, se termina el programa
      if (regex_match(aux_str, prods_match, prods_pattern)) {
        /// si el símbolo no terminal de la línea es incorrecto, se termina el
        /// programa.
        if (non_terminals_.IsItInSetSymbols(prods_match[1].str())) {
          /// si la produccion contiene un solo símbolo que no sea del alfabeto
          /// o del conjunto de símbolos no terminales, se termina el programa
          if (this->IsItAAceptableProduction(prods_match[2].str())) {
            /// si es la primera vez que se añade una producción asociada al
            /// símbolo no terminal de la línea, esta se añade con un número
            /// 1 como referencia, sino, se añade con el valor del número más
            /// grande que tenga asociado el símbolo más 1.
            if (!prod_.IsItAProduction(prods_match[1].str().front(), 1)) {
              prod_.SetProd(prods_match[1].str().front(), 1, 
                            prods_match[2].str());
            } else {
              prod_.SetProd(prods_match[1].str().front(), 
                            prod_.GetUpperNumP1(prods_match[1].str().front()),
                            prods_match[2].str());
            }
          } else {
            creation_failed_ = true;
            break;
          }
        } else {
          creation_failed_ = true;
          break;
        }
      } else {
        creation_failed_ = true;
        break;
      }
    }

    if (count <= 2) { ///< cuando leemos los símbolos del alfabeto.
      /// si la línea está bien escrita, la recorremos para coger los simbolos
      if (regex_match(aux_str, set_symbols_pattern)) {
        for (auto i: aux_str) {
          if (i != ' ') {
            if (count == 1) {alphabet_.Insert(i);}
            if ((count == 2) && (non_terminals_.Size() == 0)) {start_ = i;}
            if (count == 2) {non_terminals_.Insert(i);}
          }
        }
      } else {
        creation_failed_ = true;
        break;
      }
    }
  }
}

/**
 * @fn SetSymbols Grammar::GetAlphabet(void) const
 * @brief Getter, retorna el objeto alphabet_.
 * 
 * @return SetSymbols 
 */
SetSymbols Grammar::GetAlphabet(void) const {
  return alphabet_;
}

/**
 * @fn SetSymbols Grammar::GetNonTerminals(void) const
 * @brief Getter, retorna el objeto non_terminals_.
 * 
 * @return SetSymbols 
 */
SetSymbols Grammar::GetNonTerminals(void) const {
  return non_terminals_;
}

/**
 * @fn char Grammar::GetStart(void) const
 * @brief Getter, retorna el símbolo de arranque de la gramática (start_).
 * 
 * @return char 
 */
char Grammar::GetStart(void) const {
  return start_;
}

/**
 * @fn Productions Grammar::GetProductions(void) const
 * @brief Getter, retorna las producciones de nuestra gramática (prod_).
 * 
 * @return Productions 
 */
Productions Grammar::GetProductions(void) const {
  return prod_;
}

/**
 * @fn std::string Grammar::GetProduction(const char& non_terminal, 
 *                                        const size_t& num) const
 * @brief Getter, usando el símbolo non_terminal y el número de producción num
 * se retorna la cadena que esa produccion genera.
 * 
 * @param non_terminal Símbolo no terminal que produce la cadena que queremos
 * retornar.
 * @param num Etiqueta que nos índica, dentro de las posibles opciones que 
 * posee el símbolo no terminal para sustituir, cual de ellas elegimos.
 * @return std::string 
 */
std::string Grammar::GetProduction(const char& non_terminal, 
                                   const size_t& num) const {
  return prod_.GetProd(non_terminal, num);
}

/**
 * @fn bool Grammar::Fail(void) const
 * @brief retorna el valor del atributo interno 'creation_failed_'.
 * 
 * @return true, la creación del objeto Grammar ha fracasado.
 * @return false, la creación del objeto Grammar ha tenido éxito.
 */
bool Grammar::Fail(void) const {
  return creation_failed_;
}

/**
 * @fn bool Grammar::IsItInAlphabet(const char& symbol) const
 * @brief Devuelve true, si el símbolo (caracter dado a la
 * función) está en el alfabeto.
 * 
 * @param symbol símbolo que se va a comprobar si está incluido en el objeto
 * alphabet_.
 * @return true el símbolo llamado 'symbol' sí está contenido en el alfabeto.
 * @return false el símbolo llamado 'symbol' no está contenido en el alfabeto.
 */
bool Grammar::IsItInAlphabet(const char& symbol) const {
  return alphabet_.IsItInSetSymbols(symbol);
}

/**
 * @fn bool Grammar::IsItInNonTerminals(const char& symbol) const
 * @brief Devuelve true, si el símbolo (caracter dado a la
 * función) está en el conjunto de símbolos no terminales de la gramática.
 * 
 * @param symbol símbolo que se va a comprobar si está incluido en el objeto
 * non_terminals_.
 * @return true el símbolo llamado 'symbol' sí está contenido en el objeto 
 * non_terminals_.
 * @return false el símbolo llamado 'symbol' no está contenido en el objeto 
 * non_terminals_.
 */
bool Grammar::IsItInNonTerminals(const char& symbol) const {
  return non_terminals_.IsItInSetSymbols(symbol);
}

/**
 * @fn bool Grammar::IsItAProduction(const char& symbol, const size_t& num) const
 * @brief Devuelve true, si el símbolo coincide con un símbolo contenido en el
 * objeto prod_, y el número pasado a la función coincide con la etiqueta de 
 * una producción en concreto.
 * 
 * @param symbol símbolo no terminal del que se quiere obtener una producción.
 * @param num número que identifica la producción concreta dentro de las 
 * producciones de un símbolo no terminal.
 * @return true, existe una producción asociada para el símbolo y el número
 * pasados a la función.
 * @return false, no existe una producción asociada para el símbolo y el número
 * pasados a la función.
 */
bool Grammar::IsItAProduction(const char& symbol, const size_t& num) const {
  return prod_.IsItAProduction(symbol, num);
}

/**
 * @fn bool Grammar::IsItAAceptableProduction(const std::string& prod) const
 * @brief analiza el una std::string que le pasan a la función y comprueba, 
 * revisando los objetos alphabet_ y non_terminals_, si la cadena es válida.
 * 
 * @param prod std::string qu va a ser analizada.
 * @return true, la producción es válida.
 * @return false, la producción no es válida.
 */
bool Grammar::IsItAAceptableProduction(const std::string& prod) const {
  bool result{true};
  for (auto i: prod) {
    if (i == ' ') {continue;}
    if (!(alphabet_.IsItInSetSymbols(i) || 
        non_terminals_.IsItInSetSymbols(i))) {
      result = false;
      break;
    }      
  }
  return result;
}

/**
 * @fn bool EvalProdsInFile(std::ifstream& cfg_prods_file, 
 *                          std::ofstream& cfg_out_file)
 * @brief dados un archivo de texto de entrada, y un archivo de texto de salida
 * ya creados, esta función ó método de la clase evalua el contenido del 
 * archivo de entrada y en base a él, va escribiendo en el archivo de salida, 
 * pero si el contenido del archivo de entrada está mal escrito, entonces la
 * función se termina y devuelve true.
 * 
 * @param cfg_prods_file archivo de texto de entrada.
 * @param cfg_out_file archivo de texto de salida
 * @return true la función ha fracasado porque el archivo de entrada ha sido 
 * escrito erroneamente.
 * @return false la función ha sido completada exitosamente.
 */
bool Grammar::EvalProdsInFile(std::ifstream& cfg_prods_file, 
                     std::ofstream& cfg_out_file) {
  bool result{false};
  bool non_terminal_in_line_replaced{false};
  std::string aux_str{""};
  std::string final_chain{start_};
  std::regex line_only_spaces("^\\s*$");
  std::regex prods_pattern("^\\s*?([^\\s]): ([\\d]+)\\s*?$");
  std::smatch prods_match;

  cfg_out_file << final_chain << '\n';

  while (!cfg_prods_file.eof()) {
    getline(cfg_prods_file, aux_str);
    if (aux_str.empty() || regex_match(aux_str, line_only_spaces)) {continue;}

    /// si la línea está mal escrita, se termina el programa.
    if (regex_match(aux_str, prods_match, prods_pattern)) {
      /// si el símbolo no terminal que produce, está mal escrito, se termina
      /// el programa.
      if (non_terminals_.IsItInSetSymbols(prods_match[1].str())) {
        /// si la cadena producida por el símbolo no terminal en la línea,
        /// tiene algún símbolo desconocido para la gramática, es decir,
        /// si sólo un símbolo no está contenido ni en alphabet_ ni en 
        /// non_terminals_, entonces se termina el programa.
        if (prod_.IsItAProduction(prods_match[1].str().front(), 
            size_t(std::stoi(prods_match[2].str())))) {
          /// recorremos final_chain para encontrar el primer símbolo no 
          /// terminal, sustituirlo y iterar de nuevo.
          for (auto i: final_chain) {
            /// si encontramos el primer símbolo no terminal, pero no coincide
            /// con el puesto en la línea del archivo input.drv que estamos
            /// leyendo en este momento, se termina el programa.
            if (non_terminals_.IsItInSetSymbols(i) && 
                i != prods_match[1].str().front()) {
              result = true;
              break;
            }
            /// si encontramos el primer símbolo no terminal y coincide con el
            /// puesto en la línea del archivo, entonces este se sustituye por
            /// su producción y se vuelve a iterar para leer la siguiente
            /// producción o terminar el programa exitosamente.
            if (i == prods_match[1].str().front()) {
              final_chain.replace(final_chain.find_first_of(i), 1, 
                          prod_.GetProd(prods_match[1].str().front(), 
                                size_t(std::stoi(prods_match[2].str()))));
              non_terminal_in_line_replaced = true;
              cfg_out_file << "=> " << final_chain << '\n';
              break; ///< salimos del for tras reemplazar el simbolo.
            }
          }

          if (non_terminal_in_line_replaced) {
            /// para que no afecte a la lectura de la siguiente linea, se pone
            /// a false.
            non_terminal_in_line_replaced = false;
            continue; ///< reiteramos para leer la siguiente línea del archivo.
          } else {
            result = true;
            break; ///< si se sale del for, sin pasar por el if, hubo un error.
          }
        } else {
          result = true;
          break;
        }
      } else {
        result = true;
        break;
      }
    } else {
      result = true;
      break;
    }
  }

  return result;
}

/**
 * @fn std::ostream& operator<<(std::ostream& out, const Grammar& grammar)
 * @brief Sobrecarga del operador "<<" de la clase Grammar.
 * 
 * @param out flujo de salida.
 * @param grammar objeto al cual queremos mostrar sus atributos internos por la
 * salida estándar (excepto el atributo "creation_failed_").
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const Grammar& grammar) {
  out << "\nEsta gramática se compone de 4 elementos fundamentales: ";
  out << "\n1º " << grammar.alphabet_;
  out << "\n2º Conjunto de " << grammar.non_terminals_;
  out << "\n3º Símbolo de arranque de la Gramática: " << grammar.start_;
  out << "\n4º Conjunto de producciones de la gramática: ";
  out << grammar.prod_;
  return out;
}