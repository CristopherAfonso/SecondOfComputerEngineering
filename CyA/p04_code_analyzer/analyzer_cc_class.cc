// Universidad de La Laguna (ULL)
// Escuela Superior de Ingenierıa y Tecnologıa (ESIT)
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.edu.es
// Fecha: 21/10/2021
//
// Archivo analyzer_files_cc_class.cc:
// 
// Donde se desarrollan las funciones de la clase AnalyzerFilesCC contenida
// en el archivo de cabecera analyzer_files_cc_class.h
//
// Referencias:
// Enlaces de interes
//
// Historial de revisiones
// 21/10/2021 - Creacion (primera version) del codigo
// 

#include "analyzer_cc_class.h"

AnalyzerCC::AnalyzerCC(const std::string& kFileName, std::ifstream& in_file) {
  file_name_ = kFileName;

  //vector que nos almacenará el archivo dividido en lineas
  std::vector<std::string> whole_file;

  //mientras queden lineas por leer, se añaden al vector whole_file
  while(!in_file.eof()) {
    std::string aux_line;
    getline(in_file, aux_line);//cogemos la linea
    whole_file.emplace_back(aux_line);
  }
  
  //expresion regular de la descripcion del programa, pequeñas expresiones
  //regulares, que juntas me ayudan a coger la descripcion del programa
  std::regex gen_descrip_begin("^\\s*/[/\\*]\\*?.*$");
  std::regex gen_descrip_end("^\\s*#.*\\s*$");
  bool more_gen_descrip{true};//bool que dice si quedan lineas por leer
  int comm_init{0}; //enteros que marcan el inicio y final de la descripcion
  int comm_end{0}; //tambien los uso a la hora de buscar comments multilinea
  bool in_comment_multiline{false};//si estoy dentro de un coment. multilinea
  

  //booleanos que nos ayudan con los bucles y con los
  int num_of_open_brackets{0};

  std::smatch vars;
  std::smatch loops;
  std::smatch comments_one_line;
  std::smatch comments_multiline;
  //Modificacion
  std::smatch vec_returns;

  for(int i{0}; i < int(whole_file.size()); ++i) {

    //Codigo para almacenar la descripcion
    if (more_gen_descrip) { //si todavia queda comentario por leer, se entra
      if (regex_match(whole_file[i], gen_descrip_end)) {
        //si ha aparecido un '#', entonces ya no hay descripcion general
        more_gen_descrip = false;
      } else {
        //si la linea esta en blanco, se omite, no es relevante
        if(!regex_match(whole_file[i], std::regex("^\\s*$"))) {
          //si es la primera vez que se entra, se establece la linea inicial
          //de la descripcion, solo se entra aquí una vez
          if(vec_comm_line_.size() == 0 && vec_comm_body_.size() == 0) {
            comm_init = i;
            vec_comm_body_.emplace_back("DESCRIPTION");
          }
          //se mete la linea y se actualiza el final del comentario
          file_description_ += whole_file[i] + '\n';
          comm_end = i;
        }else {
          continue; //como es una linea en blanco, no tiene sentido mirarla
        }
      }
    }
    //convertimos los numeros a strings y los metemos en el vector
    if(!more_gen_descrip && vec_comm_line_.size() == 0 && 
       vec_comm_body_.size() == 1) {
      std::string aux1 = std::to_string(comm_init + 1);
      std::string aux2 = std::to_string(comm_end + 1);
      vec_comm_line_.emplace_back(aux1 + '-' + aux2);
    }

    //si no hay mas decripcion por leer, entonces busco el resto de cosas
    if(!more_gen_descrip) {
      //Estos if me dicen si estoy en una funcion o dentro de un if, bucle,etc...
      if(regex_search(whole_file[i], std::regex("^.*?\\{.*?$"))) {
        ++num_of_open_brackets;
      }
      if(regex_search(whole_file[i], std::regex("^.*?\\}.*?$"))) {
        --num_of_open_brackets;
      }

      //Codigo para almecenar las variables
      //si solo hay una llave abierta, detecta las variables int y double
      if(num_of_open_brackets == 1) {
        if(regex_search(whole_file[i], vars, 
           std::regex("^\\s*(int|double)\\s*&?\\s*([^,;]*?)[,;].*$"))) {
          vec_var_name_.emplace_back(vars[1].str() + ' ' + vars[2].str());
          vec_var_line_.emplace_back(i + 1);
          if(vars[1].str() == "int") {
            ++vars_int_;
          }else {
            ++vars_double_;
          }
        }
      }

      //Codigo para almecenar los bucles
      if(num_of_open_brackets >= 1) {
        if(regex_search(whole_file[i], loops, std::regex("^.*?(for|while)\\s*\\(.*?\\)\\s*\\{?.*?\\}?\\s*$"))) {
          vec_loop_name_.emplace_back(loops[1].str());
          vec_loop_line_.emplace_back(i + 1);
          if(loops[1].str() == "for") {
            ++loops_for_;
          }else {
            ++loops_while_;
          }
        }

        //Modificacion
        if(regex_search(whole_file[i], vec_returns, 
           std::regex("^\\s*?\\w*?.?\\s*?(return)\\s*(.*?)\\s*;\\s*$"))) {
          vec_ret_line_.emplace_back(std::to_string(i + 1));
          vec_ret_body_.emplace_back(vec_returns[2].str());
        }

      }

      //si hay un int main() se torna true el valor de la clase
      if(regex_search(whole_file[i], 
         std::regex("^\\s*int\\s*main\\s*\\(.*?\\)\\s*\\{?\\s*$"))) {
        is_it_main_ = true;
      }

      //Codigo para almacenar comentarios en una sola linea
      //si la linea es de tipo //
      if(regex_search(whole_file[i], comments_one_line, 
         std::regex("^.*?(//.*)$")) && !in_comment_multiline) {
        vec_comm_body_.emplace_back(comments_one_line[1].str());
        vec_comm_line_.emplace_back(std::to_string(i + 1));
      }
      //si la linea es de tipo /*...*/
      if(regex_search(whole_file[i], comments_one_line, 
         std::regex("^[^/]*?(/\\*.*\\*/).*$")) && !in_comment_multiline) {
        vec_comm_body_.emplace_back(comments_one_line[1].str());
        vec_comm_line_.emplace_back(std::to_string(i + 1));
      }

      //Codigo para almacenar comentarios multilinea del tipo /*...\n...*/
      //Si ya estoy dentro de un comentario multilinea, y es el final, capto hasta el final
      if(regex_search(whole_file[i], comments_multiline,
         std::regex("^(.*?\\*/).*$")) && in_comment_multiline) {
        ++comm_end;
        vec_comm_body_.back() += comments_multiline[1].str() + '\n';
        vec_comm_line_.emplace_back(std::to_string(comm_init) + '-' + 
                                    std::to_string(comm_end));
        in_comment_multiline = false;
      }
      //Si estoy dentro de un comentario multilinea, lo capto
      if(in_comment_multiline) {
        ++comm_end;
        vec_comm_body_.back() += whole_file[i] + '\n';
      }

      //si no estoy dentro de un comentario multilina y capto el inicio
      //pillo el inicio solo
      if(regex_search(whole_file[i], comments_multiline, 
         std::regex("^.*?(/\\*.*)$")) && (!in_comment_multiline)) {
        comm_init = i + 1;
        comm_end = i + 1;
        vec_comm_body_.emplace_back(comments_multiline[1].str() + '\n');
        in_comment_multiline = true;
      }

    }
  }
}

std::ostream& operator<<(std::ostream& out, const AnalyzerCC& File) {
  out << "PROGRAM: " << File.file_name_;
  out << "\nDESCRIPTION: ";
  out << "(Lineas en blanco del archivo original omitidas)";
  out << '\n' << File.file_description_;
  
  out << "\n\nVARIABLES: NumInt: " << File.vars_int_;
  out << ", NumDouble: " << File.vars_double_;
  //por defecto en el constructor me aseguro que siempre el vector de lineas y
  //el vector que guarda las declaraciones de las variables tengan la misma
  //longitud, pero por si me despisto, tengo este if
  if(File.vec_var_name_.size() == File.vec_var_line_.size()) {
    for(size_t i{0}; i < File.vec_var_line_.size(); ++i) {
      const size_t kPosInt{4};
      const size_t kPosDouble{7};
     //decimos la linea donde esta la variable declarada
      out << "\n[Line " << File.vec_var_line_.at(i) << "] ";
     //estos dos if detectan si es int o double, dependiendo de cual sea, se
     //coge el valor y se muestra su nombre
      if(File.vec_var_name_.at(i).find("int") != std::string::npos) {
        out << "INT: " << File.vec_var_name_.at(i).substr(kPosInt);
        continue;
      }

      if(File.vec_var_name_.at(i).find("double") != std::string::npos) {
        out << "DOUBLE: " << File.vec_var_name_.at(i).substr(kPosDouble);
        continue;
      }
      
      //si no se muestra ninguno de los dos, hay un error, por eso se para de
      //buscar, se sale del bucle y se sigue con el resto del codigo
      out << "ERROR: algo ha ido mal al detectar el tipo de variables";
      break;
    }
    out << '\n';

  }else {
    out << "\nAlgo ha ido mal al guardar las variables\n";
  }

  out << "\nSTATEMENTS: NumFor: " << File.loops_for_;
  out << ", NumWhile: " << File.loops_while_;
  //este if y lo que contiene hace lo mismo que hace el if de arriba, pero
  //con los bucles
  if(File.vec_loop_line_.size() == File.vec_loop_name_.size()) {
    for(size_t i{0}; i < File.vec_loop_line_.size(); ++i) {
      out << "\n[Line " << File.vec_loop_line_.at(i) << "] LOOP: ";
      if(File.vec_loop_name_.at(i).find("for") != std::string::npos) {
        out << "for";
        continue;
      }
      if(File.vec_loop_name_.at(i).find("while") != std::string::npos) {
        out << "while";
        continue;
      }
      out << "ERROR: algo ha ido mal al detectar el tipo de bucle";
      break;
    }

  }else {
    out << "\nAlgo ha ido mal al guardar las lineas de los bucles\n";
  }
  //Modificacion en clase
  if (File.vec_ret_line_.size() == File.vec_ret_body_.size()) {
    for (int i{0}; i < int(File.vec_ret_line_.size()); ++i) {
      out << "\n[Line " << File.vec_ret_line_.at(i) << "] ";
      out << "RETURN: " << File.vec_ret_body_.at(i);
    }
  }else {
    out << "\nAlgo ha ido mal al guardar las lineas de los returns\n";
  }
  out << '\n';

  out << "\nMAIN: ";
  if(File.is_it_main_) {
    out << "True";

  } else {
    out << "False";
  }
  out << '\n';

  out << "\nCOMMENTS: ";
  if(File.vec_comm_line_.size() == File.vec_comm_body_.size()) {
    for(int i{0}; i < int(File.vec_comm_line_.size()); ++i) {
      out << "\n[Line " << File.vec_comm_line_.at(i) << "] ";
      if(i > 0 && File.vec_comm_line_.at(i).find("-") != std::string::npos) {
        out << '\n';
      }
      out << File.vec_comm_body_.at(i);
    }

  }else {
    out << "\nAlgo ha ido mal al guardar las lineas de los comentarios\n";
  }
  out << '\n';

  return out;
}
