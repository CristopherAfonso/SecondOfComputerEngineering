// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Simbolos, alfabetos y cadenas
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 08/10/2021
// Archivo word_class.cc: Donde se desarrollan las funciones de la clase
//         cadena contenida en el archivo de cabecera word_class.h.
//
// Referencias:
//         Enlaces de interes

#include <iostream>
#include "word_class.h"

Word::Word(const std::string& word) {
  word_ = word;
  for(size_t i{0}; i < word.size(); ++i) {
    characters_of_the_word_.emplace_back(word.at(i));
  }
}

int Word::Size() {
  return word_.size();
}

int Word::Size(Alphabet& set) {

  size_t size{0}; //Cantidad de simbolos de la cadena
  size_t position{0};
  size_t lenght{1};
  std::string aux_string{""}; //Guarda el valor que se examina
  bool symbol_found{false}; //Variable declarada para que active el brake 2 
  
  while(position < word_.size()) {
    while((position + lenght) <= word_.size()) {
      aux_string = word_.substr(position, lenght);
      for(size_t i{0}; i < set.SizeAlphabet(); ++i) {
        if(aux_string == set.VecPlace(i)) {
          ++size;
          symbol_found = true;
          break;//Salimos del bucle para ahorrar iteraciones
        }
      }

      if(symbol_found) {
        symbol_found = false;
        break;//Este brake evita iteraciones innecesarias
      }

      //Si no se halla un simbolo, se aumenta la longitud y se vuelve a buscar
      //En todo el alfabeto
      ++lenght;
    }

    //Cuando se halla un simbolo, la position base se actualiza y lenght vuelve
    //a ser 1 y se repite el proceso
    position += lenght;
    lenght = 1;
  }
  
  return size;
}

std::string Word::Inverse() {
  std::string result{""};
  for(int i{int(word_.size() - 1)}; i >= 0; --i) {
    result = result + word_.at(i);
  }

  return result;
}

std::string Word::Inverse(Alphabet& set, int& size_complex_alphabet) {
  std::string result{""};
  int distance_to_the_end{1};
  int position_in_word_stored{int(word_.size())};
  std::string aux_chain{word_};
  
  //Recorremos la cadena caracter a caracter, y cuando encontremos un simbolo
  //complejo, lo añadimos a "result" y de "aux_chain" borramos desde el inicio
  //del simbolo hasta el final de la cadena, para que cuando repitamos el 
  //proceso, sea mas facil entontrar el siguiente simbolo
  for(int i{size_complex_alphabet - 1}; i >= 0; --i) {
    //recorro la cadena por caracteres
    for(int j{position_in_word_stored}; j >= 0; --j) {
      //en cada caracter de la cadena, recorro todo el alfabeto
      for(int k{0}; k < (int(set.SizeAlphabet())); ++k) {
        //si desde la posicion en la que estoy hasta el final de la cadena, 
        //hay un simbolo en el alfabeto que concuerde con esa cadena, la guarda
        if(aux_chain.substr(j, distance_to_the_end) == set.VecPlace(k)) {
          result = result + aux_chain.substr(j, distance_to_the_end);
          aux_chain.erase(j, distance_to_the_end);
          --j;
          //guardamos este numero porque cuando iteremos de nuevo, sera donde
          //partiremos
          position_in_word_stored = j;
          distance_to_the_end = 1;
          break;//ahorra buscar mas en el alfabeto innecesariamente
        }
      }
      
      //si no halla ningun simbolo complejo, aumenta la distancia, y se acerca
      //mas al inicio de la cadena
      ++distance_to_the_end;
    }    
  }
  
  return result;
}

std::string Word::Prefixes() {
  std::string result{"& "};
  std::string aux{""};

  for(size_t i{0}; i < characters_of_the_word_.size(); ++i) {
    aux = aux + characters_of_the_word_.at(i);
    result = result + aux + ' ';
  }

  return result;
}

std::string Word::Prefixes(Alphabet& set, int& size_complex_alphabet) {
  std::string result{"& "};
  std::string aux_chain{""};
  size_t actual_position{0};
  size_t lenght{1};

  //recorremos la cadena caracter a caracter de inicio a fin, si hallamos un
  //simbolo complejo, lo metemos en aux_chain, y aux_chain lo añadimos a result
  for(size_t i{0}; i < size_t(size_complex_alphabet); ++i) {
    for(size_t j{actual_position}; j < characters_of_the_word_.size(); ++j) {
      aux_chain = aux_chain + characters_of_the_word_.at(j);
      ++lenght;
      for(size_t k{0}; k < set.SizeAlphabet(); ++k) {
        if(set.VecPlace(k) == aux_chain.substr(actual_position, lenght)) {
          result = result + aux_chain + ' ';
          lenght = 1;
          actual_position = j + 1;
          break;
        }
      }
    }
  }

  return result;
}

std::string Word::Suffixes() {
  std::string result{"& "};
  std::string aux{""};
  
  for(int i{int(characters_of_the_word_.size() - 1)}; i >= 0; --i) {
    aux = characters_of_the_word_.at(i) + aux;
    result = result + aux + ' ';
  }

  return result;
}

std::string Word::Suffixes(Alphabet& set, int& size_complex_alphabet) {
  std::string result{"& "};
  std::string aux_chain{""};
  const int kZero{0};
  int actual_position{0};
  int position_in_word_stored{int(characters_of_the_word_.size() - 1)};
  size_t lenght{0};

  //hacemos lo mismo que el metodo de prefijos para alfabetos complejos, pero
  //aqui es algo mas complicado el algoritmo, la variable 'i' itera por cada
  //simbolo complejo, 'j' recorre de inicio a fin la cadena word_, 'k' hace
  //lo mismo pero la recorre a la inversa, desde el fin al inicio, y 'l' 
  //recorre todo el alfabeto, en cada iteracion del segundo for, hay que
  //guardar los valores de 'j' y 'k' para la siguiente iteracion, sino
  //empezarian desde el inicio, y esos valores se guardan en "actual_position"
  //y en "position_in_word_stored"
  for(int i{0}; i < size_complex_alphabet; ++i) {
    for(int j{actual_position}, k{position_in_word_stored}; 
    j < int(characters_of_the_word_.size()); ++j, --k) {
      aux_chain = characters_of_the_word_.at(k) + aux_chain;
      ++lenght;
      for(int l{0}; l < int(set.SizeAlphabet()); ++l) {
        if(set.VecPlace(l) == aux_chain.substr(kZero, lenght)) {
          result = result + aux_chain + ' ';
          lenght = 0;
          actual_position = j + 1;
          position_in_word_stored = k - 1;
          break;
        }
      }
    }
  }
  
  return result;
}

std::string Word::Substrings() {
  std::string result{"& "};
  size_t lenght{1}; //Nos ayuda a saber cuantos caracteres debe coger .substr()

  //Empiezo cogiendo las subcadenas de longitud 1, y sigo subiendo de longitud
  //hasta que llego a "lenght = word_.size()"
  while(lenght <= word_.size()) {
    //Cuanto mayor es lenght, menos iteraciones hace, cuando 
    //"lenght = word_.size()", solo hace una
    for(size_t i{0}; i < (word_.size() - lenght + 1); ++i) {
      result = result + word_.substr(i, lenght) + ' ';
    }
    ++lenght;
  }
    
  return result;
}

std::string Word::Substrings(Alphabet& set, int& size_complex_alphabet) {
  std::string result{"& "};
  const size_t kZero{0};
  size_t lenght{1};
  size_t base_position{kZero};
  //Vector que guarda en orden, los simbolos que tiene la cadena a evaluar
  std::vector<std::string> aux_symbols_in_word;

  //Primero, identificamos los simbolos complejos de la palabra, los metemos
  //en "result" y en el vector
  for(size_t i{0}; i < word_.size(); ++i) { //recorremos word_ por caracteres
    for(size_t j{0}; j < set.SizeAlphabet(); ++j) {
      if(set.VecPlace(j) == word_.substr(base_position, lenght)) {
        result = result + set.VecPlace(j) + ' ';
        aux_symbols_in_word.emplace_back(word_.substr(base_position, lenght));
        lenght = kZero;
        base_position = i + 1;
      }
    }
    ++lenght;
  }

  lenght = 2;
  base_position = kZero;

  //Una vez identificados en orden todos los caracteres complejos de la cadena
  //Solo tenemos que ponerlos en orden dentro de "result", esto es más facil
  //que si hubieramos seguido desarrollando el metodo anterior
  while(lenght <= size_t(size_complex_alphabet)) {
    for(size_t i{0}; i < (size_complex_alphabet - lenght + 1); ++i) {

      for(size_t j{base_position + i}; j < (lenght + i); ++j) {
        result = result + aux_symbols_in_word.at(j);
      }

      result = result + ' ';
    }

    ++lenght;
  }

  return result;
}
