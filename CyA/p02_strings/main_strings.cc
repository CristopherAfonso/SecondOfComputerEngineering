// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Simbolos, alfabetos y cadenas
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 08/10/2021
// Archivo main_strings.cc: programa cliente.
//         Contiene la funcion main del proyecto que usa las clases X e Y que
//         realizan el trabajo de leer el fichero de entrada identificando 
//         patrones en el texto que dan lugar al fichero de salida.
//
// Referencias:
//         Enlaces de interes
//
// Historial de revisiones
//         08/10/2021 - Creacion (primera version) del codigo
//         09/10/2021 - Desarrollo de las clases Alphabet, Word y creación de
//                      los mensajes de uso del programa y de reportes de error
//                      (segunda versión)
//         10/10/2021 - Archivo Cliente (main_strings.cc) casi terminado, y 
//                      inicio del desarrollo de los métodos que realizan las
//                      operaciones solicitadas por los usuario (OpCodes)
//                      (tercera versión)
//         11/10/2021 - Archivo Cliente terminado, métodos orientados a 
//                      alfabetos simples terminados (cuarta version)
//         12/10/2021 - Métodos orientados a alfabetos complejos terminados,
//                      finalización de redactación de comentarios en las 
//                      partes del projecto que más cuesta entender
//                      (Version final)

#include <fstream>
#include <sstream>

#include "alphabet_class.h"
#include "word_class.h"

//Mensaje de error si no se cumple con el numero de argumentos, que es 4
void ErrorMessage(const std::string& function_name) { 
  std::cout << "\nWarning!, Faltan/Sobran argumentos para este programa";
  std::cout << "\nPara más información sobre como funciona pruebe:";
  std::cout << "\n'" << function_name << " --help'\n\n";
}

void ErrorOpcode() { 
  std::cout << "\nOpCode invalido, intentelo de nuevo\n\n";
}

//Explica al usuario como usar el programa
void InfoMessage(const std::string& function_name) { 
  std::cout << "\nDescripcion:";
  std::cout << "\n" << function_name << " es un programa el cual recibe un";
  std::cout << "\nfichero de texto y devuelve como salida otro. La forma de";
  std::cout << "\nusar el programa es esta:\n\n";
  std::cout << "'" << function_name << " [input_file] [output_file] [opcode]'";
  std::cout << "\n\ninput_file: archivo de texto que le pasamos al programa";
  std::cout << "\noutput_file: nombre del archivo que se creara";
  std::cout << "\nopcode: número que identifica a la operacion a hacer\n";

  std::cout << "\nEspecificaciones del archivo input_file:";
  std::cout << "\nEl archivo input_file puede ser tan extenso como se desee,";
  std::cout << "\nlas lineas pueden ser tan largas como se desee, y cada";
  std::cout << "\nlinea debe contener minimo dos cadenas, la ultima cadena";
  std::cout << "\nde la fila se procesaria como parte de la clase 'aux_word' y";
  std::cout << "\nla primera como parte de la clase 'alphabet', si en una";
  std::cout << "\nlinea hay mas de dos cadenas, la ultima seria parte de";
  std::cout << "\nla clase 'word' y el resto serian simbolos de la clase";
  std::cout << "\n'alphabet'\n";

  std::cout << "\nDetalles de las operaciones:";
  std::cout << "\nOpCode '1' Longitud: Se escribe en output_file la longitud";
  std::cout << "\nde cada cadena de entrada (se cuentan sus simbolos)";
  std::cout << "\nOpCode '2' Inversa: Se escribe en el output_file la inversa";
  std::cout << "\nde cada cadena de entrada (se invierten sus simbolos)";
  std::cout << "\nOpCode '3' Prefijos: Se escribe en output_file el conjunto";
  std::cout << "\nde cadenas que son prefijos de la cadena de entrada";
  std::cout << "\nOpCode '4' Sufijos: Se escribe en output_file el conjunto";
  std::cout << "\nde cadenas que son sufijos de cada cadena de entrada\n";
  std::cout << "OpCode '5' Subcadenas: Se escribe en output_file el conjunto";
  std::cout << "\nde subcadenas para cada cadena de entrada\n\n";
}

int main(int argc, char* argv[]) {

  // Paso los argumenos a tipo string porque es más facil que trabajar con los
  // char* argv[]
  const std::string kNameProgram{argv[0]};
  const std::string kNameInput{argv[1]};
  const std::string kNameOutput{argv[2]};
  const std::string kOpCode{argv[3]};
  
  //Se solicita conocer el modo de uso del programa
  if(("--help" == kNameInput)) {
    InfoMessage(kNameProgram);
    exit(EXIT_SUCCESS);
  }
  
  //Error al pasar parametros
  if(argc < 3 || argc > 5) { 
    ErrorMessage(kNameProgram);
    exit(EXIT_FAILURE);
  }

  //OpCode mal puesto
  if(std::stoi(kOpCode) < 1 || std::stoi(kOpCode) > 5) { 
    ErrorOpcode();
    exit(EXIT_FAILURE);
    
  }

  std::string line = ""; //Variable donde guardamos las lineas del archivo
  std::ifstream input_file;
  std::ofstream output_file;

  input_file.open(kNameInput, std::fstream::in);
  output_file.open(kNameOutput, std::fstream::out);

  if(input_file.fail()) {
    std::cout << "\nError al leer el archivo " << kNameInput << ",";
    std::cout << "\nIntentelo de nuevo\n\n";
    exit(EXIT_FAILURE);
  }

  if(output_file.fail()) {
    std::cout << "\nError al abrir el archivo " << kNameOutput << ",";
    std::cout << "\nIntentelo de nuevo\n\n";
    exit(EXIT_FAILURE);
  }

  //Aquí guardamos todo el archivo, dividido en lineas para trabajar mejor
  std::vector<std::string> set_of_lines;

  //Mientras no sea el final del archivo, itera
  while(!input_file.eof()) {
    std::string chain{""};
    
    //Leo toda la linea actual del archico y la guardo 
    getline(input_file, chain);
    set_of_lines.emplace_back(chain);
  }

  input_file.close(); //Cerramos el archivo para liberar memoria

  //En este for, por cada linea guardada, se crean un objeto Alphabet y Word, 
  //Se les aplica su opcode, se guarda el resultado en el archivo de salida
  //Y se repite el proceso hasta que no hay mas lineas
  for(size_t i{0}; i < set_of_lines.size(); ++i) {
    //Flujo de entrada de datos que me ayuda a dividirlos para clasificarlos
    std::istringstream actual_line(set_of_lines[i]);
    std::string chain{""}; //String entera que guarda una linea
    //String que se le pasara al constructor de la clase Word
    std::string aux_word = {""};
    int alphabet_size{-1};
    //Vector que se le pasara al constructor de la clase Alphabet
    std::vector<std::string> aux_vec;

    //Leemos la linea, si solo tiene una cadena, el alfabeto esta vacio y hay
    //que generarlo a partir de la cadena que hay, si hay mas de una cadena
    //en la linea, se van metiendo menos la ultima leida
    while(getline(actual_line, chain, ' ')) {
      ++alphabet_size;
      if(alphabet_size > 0) {
        aux_vec.emplace_back(aux_word);
      }
      aux_word = chain;
    }

    //Caso particular para cuando creamos el alfabeto a partir de la cadena
    if(alphabet_size <= 0) {
      aux_vec.clear(); //Vaciamos el vector por si acaso
      for(size_t i{0}; i < aux_word.size(); ++i) {
        if(aux_word.at(i) != ' ') {
          std::string character{aux_word[i]};
          aux_vec.emplace_back(character);
        }
      }
    }

    Alphabet alphabet(aux_vec);
    Word word(aux_word);

    switch(std::stoi(kOpCode)) {
      case 1:
        if(!alphabet.AreThereComplexSymbols()) {
          output_file << word.Size() << '\n';
        }
        else {
          output_file << word.Size(alphabet) << '\n';
        }
        break;

      case 2:
        if(!alphabet.AreThereComplexSymbols()) {
          output_file << word.Inverse() << '\n';
        }
        else {
          int size_complex_alphabet{word.Size(alphabet)};
          output_file << word.Inverse(alphabet, size_complex_alphabet) << '\n';
        }
        break;

      case 3:
        if(!alphabet.AreThereComplexSymbols()) {
          output_file << word.Prefixes() << '\n';
        }
        else {
          int size_alphabet{word.Size(alphabet)};
          output_file << word.Prefixes(alphabet, size_alphabet) << '\n';
        }
        break;

      case 4:
        if(!alphabet.AreThereComplexSymbols()) {
          output_file << word.Suffixes() << '\n';
        }
        else {
          int size_alphabet{word.Size(alphabet)};
          output_file << word.Suffixes(alphabet, size_alphabet) << '\n';
        }
        break;

      case 5:
        if(!alphabet.AreThereComplexSymbols()) {
          output_file << word.Substrings() << '\n';
        }
        else {
          int size_alphabet{word.Size(alphabet)};
          output_file << word.Substrings(alphabet, size_alphabet) << '\n';
        }
        break;
      
      //Definido un default por si en el futuro se le hiciera un cambio al
      //programa, estar prevenido
      default: 
        exit(EXIT_FAILURE);
    }
    
  }

  output_file.close(); //Cerramos el archivo que creamos o sobreescribimos, 
  // y así todos los cambios que le aplicamos se ejecutan y guardan
 
  return 0;
}