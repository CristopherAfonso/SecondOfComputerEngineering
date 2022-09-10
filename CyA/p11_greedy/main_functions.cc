/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 11: Algoritmos Voraces (Greedy)
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 27/12/2021
 * 
 * @file main_functions.cc
 * @brief Donde se aloja el desarrollo y la implementación de las funciones
 * de nuestro archivo cliente.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 27/12/21 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include
 * 27/12/21 - Funciones del main terminadas.
 */

#include "main_functions.h"

/**
 * @fn void Usage(int argc, char* argv[])
 * @brief Funcion que solo comprueba si los argumentos dados al programa son
 * validos para poder ejecutarlo, en caso contrario este se termina con un
 * mensaje.
 * 
 * @param argc numero que contiene la cantidad de argumentos dados al programa,
 * siempre sera 1 o mayor a 1 porque el nombre del propio programa se cuenta.
 * @param argv parametro tipo "char* []" que contiene en cada posicion el
 * primer caracter de cada argumento pasado al programa.
 */
void Usage(int argc, char* argv[], bool& acotado) {
  std::string kHelp{"--help"};
  std::string kProgramName{argv[0]};
  if (argc == 1) {
    MainMessage(kProgramName, kHelp);
    exit(EXIT_SUCCESS);
  }

  std::string kWeightLimit{argv[1]};
  if (argc == 2 && kWeightLimit == kHelp) {
    HelpMessage(kProgramName);
    exit(EXIT_SUCCESS);
  }

  if (argc > 4) {
    ErrorSoMuchParameters(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  std::string kFileName{argv[2]};
  if (argc == 4) {
    if (kWeightLimit == "-u") {
      acotado = false;
      kWeightLimit = kFileName;
      std::string aux{argv[3]};
      kFileName = aux;
    } else {
      ErrorWrongParameters(kProgramName, kHelp);
      exit(EXIT_FAILURE);
    }
  }

  if ((kFileName.size() <= 4) || 
     (kFileName.substr(kFileName.size() - 4) != ".cfg")) {
    ErrorConfigFileExtension(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  /// Solo abrimos el archivo para comprobar que se puede abrir.
  std::ifstream config_file(kFileName, std::fstream::in);
  if (config_file.fail()) {
    ErrorOpenConfigFile(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  std::regex num_objs_exp("^\\s*\\d\\d*\\s*$");
  std::regex weight_value_line_exp("^\\s*\\d\\d*(\\.\\d+)?\\s\\s*\\d\\d*(\\.\\d+)?$");
  std::regex void_line("^\\s*$");
  
  bool begin_config_file{true};
  while (!config_file.eof()) {
    std::string aux{""};
    getline(config_file, aux);
    if (regex_match(aux, void_line)) continue;
    if (begin_config_file) {
      begin_config_file = false;
      if (!regex_match(aux, num_objs_exp)) {
        ErrorConfigFileBody(kProgramName, kHelp);
        exit(EXIT_FAILURE);
      }
    } else {
      if (!regex_match(aux, weight_value_line_exp)) {
        ErrorConfigFileBody(kProgramName, kHelp);
        exit(EXIT_FAILURE);
      }
    }
  }

  config_file.close();

  bool str_begin{true};
  bool str_point{false};
  for (auto i{kWeightLimit.begin()}; i != kWeightLimit.end(); ++i) {
    switch (*i) {
      case '0': case '1': case '2': case '3': case '4': 
      case '5': case '6': case '7': case '8': case '9':
        if (str_begin) str_begin = false;
        break;
      
      case '.':
        if (str_begin) {
          ErrorNoNumber(kProgramName, kHelp);
          exit(EXIT_FAILURE);
        }

        if (str_point) {
          ErrorNoNumber(kProgramName, kHelp);
          exit(EXIT_FAILURE);
        }        

        str_point = true;
        break;
      
      default:
        ErrorNoNumber(kProgramName, kHelp);
        exit(EXIT_FAILURE);
        break;
    }

    if (kWeightLimit.back() == '.') {
      ErrorNoNumber(kProgramName, kHelp);
      exit(EXIT_FAILURE);
    }
  }
}

/**
 * @fn void MainMessage(const std::string& kProgramName, const std::string& kHelp)
 * @brief Mensaje principal mostrado cuando se llama al programa sin parametros
 * 
 * @param kProgramName nombre del programa.
 * @param kHelp palabra para pedir las instruciones del programa.
 */
void MainMessage(const std::string& kProgramName, const std::string& kHelp) {
  using std::cout;
  cout << "Usage: " << kProgramName << " <max_weight> <config_file>\n";
  cout << "Pruebe: \"" << kProgramName << " " << kHelp << "\" ";
  cout << "para mas informacion\n";
}

/**
 * @fn void HelpMessage(const std::string& kProgramName, const std::string& kHelp)
 * @brief Mensaje de ayuda que se muestra solo cuando el unico parametro pasado
 * al programa es la palabra para pedir instruciones.
 * 
 * @param kProgramName nombre del programa.
 * @param kHelp palabra para pedir las instruciones del programa.
 */
void HelpMessage(const std::string& kProgramName) {
  using std::cout;
  cout << kProgramName << " es un programa que se limita a resolver el\n";
  cout << "famoso \"Problema de la mochila\" usando para ello un Algoritmo";
  cout << "Voraz (Greedy).\n\n";
  cout << "A este programa solo se le tienen que pasar dos parametros\n";
  cout << "El primero es el peso maximo que aguantara la mochila (double)\n";
  cout << "(si este lleva decimales, hay que usar un punto, no una coma).\n";
  cout << "El segundo es el archivo de configuracion (tiene que ser un\n";
  cout << "archivo de texto con extension \".cfg\", sino no es asi el\n";
  cout << "programa no se ejecutara) que contiene una lista de los objetos\n";
  cout << "que se disponen para meter en la mochila, su peso y valor.\n\n";
  cout << "Los archivos de configuracion deben seguir esta sintaxis:\n";
  cout << "5      // Linea 1, numero de objetos\n";
  cout << "12 4   // Linea 2, Objeto 1: Peso valor, utilidad: 0,333\n";
  cout << "1 2    // Linea 3, Objeto 2: Peso valor, utilidad: 2\n";
  cout << "4 10   // Linea 4, Objeto 3: Peso valor, utilidad: 2,5\n";
  cout << "1 1    // Linea 5, Objeto 4: Peso valor, utilidad: 1\n";
  cout << "2 2    // Linea 6, Objeto 5: Peso valor, utilidad: 1\n\n";
  cout << "Tambien se le puede pasar un tercer parametro pero es opcional y\n";
  cout << "este es \"-u\", este parametro le dice a nuestro programa que\n";
  cout << "queremos que resuelva el problema de la mochila pero sin acotar\n";
  cout << "(es decir, sin coger partes de un objeto, sin partirlos, o se\n";
  cout << "coge un objeto entero o no se puede coger el objeto).\n\n";
  cout << "Si se quiere usar este parametro, solo se puede poner al lado\n";
  cout << "del nombre del programa cuando lo llamamos, si lo ponemos en\n";
  cout << "otro lado el programa nos devolvera error.\n\n";
  cout << "Dicho esto, solo hay dos formas correctas de llamar al programa:\n";
  cout << "1º ==> " << kProgramName << " <peso_limite> <nombre_archivo>\n";
  cout << "2º ==> " << kProgramName << " -u" << " <peso_limite> ";
  cout << "<nombre_archivo>\n";
}

/**
 * @fn void ErrorSoMuchParameters(const std::string& kProgramName, 
 *                                const std::string& kHelp)
 * @brief Mensaje de error que se muestra cuando al programa se le pasan mas 
 * de dos parametros a la vez.
 * 
 * @param kProgramName nombre del programa.
 * @param kHelp palabra para pedir las instruciones del programa. 
 */
void ErrorSoMuchParameters(const std::string& kProgramName, 
                           const std::string& kHelp) {
  using std::cerr;
  cerr << "Warning! se han pasado mas de tres argumentos al programa\n";
  cerr << "Pruebe: \"" << kProgramName << " " << kHelp << "\" ";
  cerr << "para mas informacion\n";
}

/**
 * @fn void ErrorWrongParameters(const std::string& kProgramName, const std::string& kHelp)
 * @brief Mensaje de error que aparece cuando tenemos un numero correcto de 
 * argumentos en el programa pero no sirven para ejecutarlo.
 * 
 * @param kProgramName nombre del programa.
 * @param kHelp palabra para pedir las instruciones del programa.
 */
void ErrorWrongParameters(const std::string& kProgramName, 
                          const std::string& kHelp) {
  using std::cerr;
  cerr << "Warning! los argumentos dados al programa no son validos para\n";
  cerr << "poder iniciarlo, cambielos y intentelo de nuevo\n";
  cerr << "Pruebe: \"" << kProgramName << " " << kHelp << "\" ";
  cerr << "para mas informacion\n";
}

/**
 * @fn void ErrorConfigFileExtension(const std::string& kProgramName, 
 *                                   const std::string& kHelp)
 * @brief Mensaje de error mostrado cuando se le pasa al programa un archivo
 * de configuracion que no lleva extension ".cfg", y por tanto no se acepta.
 * 
 * @param kProgramName nombre del programa.
 * @param kHelp palabra para pedir las instruciones del programa.
 */
void ErrorConfigFileExtension(const std::string& kProgramName, 
                              const std::string& kHelp) {
  using std::cerr;
  cerr << "Warning! el archivo de texto no tiene la extension \".cfg\"\n";
  cerr << "o el nombre no tiene la longitud requerida\n";
  cerr << "Pruebe: \"" << kProgramName << " " << kHelp << "\" ";
  cerr << "para mas informacion\n";
}

/**
 * @fn void ErrorOpenConfigFile(const std::string& kProgramName, 
 *                              const std::string& kHelp)
 * @brief Mensaje de error que se muestra cuando no se puede abrir el archivo
 * de configuracion.
 * 
 * @param kProgramName nombre del programa.
 * @param kHelp palabra para pedir las instruciones del programa. 
 */
void ErrorOpenConfigFile(const std::string& kProgramName, 
                         const std::string& kHelp) {
  using std::cerr;
  cerr << "Warning! no se pudo abrir el archivo, intentelo de nuevo\n";
  cerr << "Pruebe: \"" << kProgramName << " " << kHelp << "\" ";
  cerr << "para mas informacion\n";
}

/**
 * @fn void ErrorNoNumber(const std::string& kProgramName, const std::string& kHelp)
 * @brief Mensaje de error que se muestra cuando el primer argumento del
 * programa es un std::string que no se puede pasar a double.
 * 
 * @param kProgramName nombre del programa.
 * @param kHelp palabra para pedir las instruciones del programa. 
 */
void ErrorNoNumber(const std::string& kProgramName, const std::string& kHelp) {
  using std::cerr;
  cerr << "Warning! el numero pasado como argumento al programa no se puede\n";
  cerr << "convertir a double, cambielo y intentelo de nuevo.\n";
  cerr << "Pruebe: \"" << kProgramName << " " << kHelp << "\" ";
  cerr << "para mas informacion\n";
}

/**
 * @fn void ErrorConfigFileBody(const std::string& kProgramName, const std::string& kHelp)
 * @brief Mensaje de error que avisa al usuario de que el archivo de
 * configuracion que ha dado al programa no tiene una sintaxis correcta.
 * 
 * @param kProgramName nombre del programa.
 * @param kHelp palabra para pedir las instruciones del programa.
 */
void ErrorConfigFileBody(const std::string& kProgramName, 
                         const std::string& kHelp) {
  using std::cerr;
  cerr << "Warning! el archivo de configuracion dado al programa no tiene la\n";
  cerr << "sintaxis requerida para poder leerlo adecuadamente, cambiela y\n";
  cerr << "intentelo de nuevo.\n";
  cerr << "Pruebe: \"" << kProgramName << " " << kHelp << "\" ";
  cerr << "para mas informacion\n";
}

/**
 * @fn void ErrorLineNotFound(const std::string& kProgramName, const std::string& kHelp)
 * @brief Mensaje de error que aparece cuando hay problemas a la hora de leer
 * las lineas del archivo de configuracion porque el programa las interpreta
 * como lineas en blanco.
 * 
 * @param kProgramName nombre del programa.
 * @param kHelp palabra para pedir las instruciones del programa.
 */
void ErrorLineNotFound(const std::string& kProgramName, 
                       const std::string& kHelp) {
  using std::cerr;
  cerr << "Warning! encontrada linea en blanco donde deberian estar el peso\n";
  cerr << "y valor de un objeto, elimine lineas en blanco del archivo,\n";
  cerr << "añada mas objetos, o cambie el numero de objetos posibles para\n";
  cerr << "meter en la mochila y intentelo de nuevo. Tambien puede ocurrir\n";
  cerr << "que tenga alguna linea que comience por un espacio, quitelos, el\n";
  cerr << "programa las considera como en blanco.\n";
  cerr << "Pruebe: \"" << kProgramName << " " << kHelp << "\" ";
  cerr << "para mas informacion\n";
}

/**
 * @fn void ErrorLackOfObj(const std::string& kProgramName, const std::string& kHelp)
 * @brief Mensaje de error que aparece cuando en el archivo de configuracion
 * se ha indicado un numero mayor de la cantidad de lineas disponibles para
 * leer.
 * 
 * @param kProgramName nombre del programa.
 * @param kHelp palabra para pedir las instruciones del programa. 
 */
void ErrorLackOfObj(const std::string& kProgramName, const std::string& kHelp) {
  using std::cerr;
  cerr << "Warning! se ha marcado en la primera linea del archivo de\n";
  cerr << "configuracion un numero distinto de la cantidad de objetos que\n";
  cerr << "hay en el archivo para procesar, cambie ese numero o añada mas\n";
  cerr << "lineas y intentelo de nuevo\n";
  cerr << "Pruebe: \"" << kProgramName << " " << kHelp << "\" ";
  cerr << "para mas informacion\n";
}

/**
 * @fn void Solve(const double& kWeightLimit, const std::vector<double>& kWeightObjs, 
 *                const std::vector<double>& kValueObjs, const bool& acotado)
 * @brief Funcion que ejecuta el algoritmo voraz (greedy) para resolver el
 * problema de la mochila y imprime por pantalla su resultado.
 * 
 * @param kWeightLimit limite de peso de la mochila.
 * @param kWeightObjs vector que en cada posicion tiene el peso de un objeto.
 * @param kValueObjs vector que en cada posicion tiene el valor de un objeto.
 * @param acotado booleano que nos dice si se quiere resolver acotando o no.
 */
void Solve(const double& kWeightLimit, const std::vector<double>& kWeightObjs, 
           const std::vector<double>& kValueObjs, const bool acotado) {
  using std::cout;
  double benefic{0.00};
  double weight{0.00};
  double count_solution{0.00};
  std::vector<std::pair<int, double>> solution;
  std::vector<double> objs_used(kWeightObjs.size(), 0);
  std::vector<int> utility_obj;

  std::vector<bool> obj_choosen(kWeightObjs.size(), false);
  double aux_double{0.00};
  for (int i{0}; i < int(kWeightObjs.size()); ++i) {
    int aux_position{-1};
    aux_double = 0.00;
    for (int j{0}; j < int(kWeightObjs.size()); ++j) {
      if (obj_choosen[j]) continue;

      if ((kValueObjs[j] / kWeightObjs[j]) > aux_double) {
        aux_double = kValueObjs[j] / kWeightObjs[j];
        aux_position = j;
      }
    }

    obj_choosen[aux_position] = true;
    utility_obj.emplace_back(aux_position);
  }
  
  while (weight < kWeightLimit) {
    int actual_obj{-1};
    if (acotado) {
      for (int i{0}; i < int(kWeightObjs.size()); ++i) {
        if (obj_choosen[i]) {
          obj_choosen[i] = false;
          actual_obj = utility_obj[i];
          break;
        }
      }

      if ((weight + kWeightObjs[actual_obj]) <= kWeightLimit) {
        objs_used[actual_obj] = 1.00;
        weight += kWeightObjs[actual_obj];
        solution.emplace_back(std::make_pair(actual_obj + 1, 1.00));
      } else {
        objs_used[actual_obj] = (kWeightLimit - weight) / kWeightObjs[actual_obj];
        weight = kWeightLimit;
        solution.emplace_back(std::make_pair(actual_obj + 1, objs_used[actual_obj]));
      }

      benefic += objs_used[actual_obj] * kValueObjs[actual_obj];
    } else {
      if (solution.empty()) { ///< Si es verdad, solution esta vacio.
        actual_obj = utility_obj.front();
        solution.emplace_back(std::make_pair(actual_obj + 1, 0.00));
      } else {
        for (int i{0}; i < int(utility_obj.size()); ++i) {
          if (kWeightObjs[utility_obj[i]] + weight <= kWeightLimit) {
            actual_obj = utility_obj[i];
            break;
          }
        }
      }

      objs_used[actual_obj] = 1.00;
      benefic += objs_used[actual_obj] * kValueObjs[actual_obj];
      weight += kWeightObjs[actual_obj];
      for (int i{0}; i < int(solution.size()); ++i) {
        if (actual_obj + 1 == solution[i].first) {
          ++solution[i].second;
          break;
        }

        if (i == (int(solution.size()) - 1)) 
          solution.emplace_back(std::make_pair(actual_obj + 1, 1.00));
      }
      
    }
  }

  if (!acotado) solution.back().second += -1;

  cout << "Beneficio: " << benefic << '\n';
  cout << "Peso: " << weight << '\n';
  aux_double = 0.00;
  for (auto i: solution) {
    aux_double += i.second;
  }

  if ((aux_double - double(int(aux_double))) < 0.5) {
    aux_double = double(int(aux_double));
  } else {
    aux_double = double(int(aux_double)) + 1.00;
  }

  cout << "Solucion " << aux_double << " objetos: ";
  for (auto i: solution) {
    cout << i.first << ":" << i.second << ' ';
  }

  cout << '\n';
}

/**
 * @fn void Backpack(char* argv[])
 * @brief funcion que se encarga de ejecutar el nucleo del programa ofreciendo
 * una solucion al problema de la mochila por pantalla leyendo un archivo de
 * configuracion.
 * 
 * @param argv parametros pasados al programa para poder ejecutarlo, entre
 * ellos estan el nombre del programa, el limite del peso de la mochila y,
 * el nombre del archivo de configuracion, en ese orden.
 */
void Backpack(char* argv[], const bool& acotado) {
  using std::cout;
  const std::string kHelp{"--help"};
  const std::string kProgramName{argv[0]};
  std::string kWeightLimit{argv[1]};
  std::string kFileName{argv[2]};

  if (!acotado) {
    kWeightLimit = kFileName;
    std::string aux{argv[3]};
    kFileName = aux;
  }

  /// No compruebo si la apertura del archivo falla porque eso lo hago en la 
  /// funcion Usage().
  std::ifstream config_file(kFileName, std::fstream::in);
  const double weight_limit{std::stod(kWeightLimit)};
  int num_objs{0};
  std::vector<double> weight_objets;
  std::vector<double> value_objets;

  int count{-1}; ///< cuenta las lineas leidas en el while.
  bool begin_config_file{true};
  while (!config_file.eof()) {
    std::string line{""};
    std::string aux_str{""};
    getline(config_file, line);

    if (count == num_objs) break; ///< Salimos del while al leer las lineas.
    if (line == "" || line.front() == ' ') {
      ErrorLineNotFound(kProgramName, kHelp);
      exit(EXIT_FAILURE);
    }

    if (begin_config_file) {
      begin_config_file = false;
      num_objs = std::stoi(line);
      weight_objets.reserve(num_objs);
      value_objets.reserve(num_objs);
    } else {
      std::istringstream aux_line(line);
      while (getline(aux_line, aux_str, ' ')) {
        /// Para no crear otra variable bool, uso "being_config_file" para
        /// ayudarme a sacar del archivo de configuracion los datos de cada
        /// objeto, al salir del while, "begin_config_file" tiene el mismo
        /// valor que cuando entro (es decir, false).
        if (begin_config_file) {
          begin_config_file = !begin_config_file;
          value_objets.emplace_back(std::stod(aux_str));
        } else {
          begin_config_file = !begin_config_file;
          weight_objets.emplace_back(std::stod(aux_str));
        }
      }
    }
    ++count;
  }

  config_file.close();
  if (count != num_objs) {
    ErrorLackOfObj(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  Solve(weight_limit, weight_objets, value_objets, acotado);
}
