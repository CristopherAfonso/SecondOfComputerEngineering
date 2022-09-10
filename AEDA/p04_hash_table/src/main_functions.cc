/**
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 4: Implementación de Tabla Hash
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 03/04/2022
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
 * 03/04/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado los #include necesarios.
 * 03/04/22 - Archivo terminado.
 */

#include "../include/main_functions.h"

using std::cout;
using std::cerr;

/**
 * @brief Función que solo muestra un mensaje por pantalla sobre como usar el
 * programa.
 * 
 * @param argv Array de puntero a caracteres donde cada posición contiene el
 * primer caracter de cada argumento del programa.
 */
void MainMessage(const std::string& kProgramName, const std::string& kHelp) {
  cout << "Modo de empleo: " << kProgramName << " [Numero de filas] ";
  cout << "[Numero de columnas] [Tipo de Funcion de dispersion] ";
  cout << "[Tipo de Funcion de exploracion]";
  cout << "\nPruebe: '" << kProgramName << " " << kHelp << "' ";
  cout << "Para más información\n";
}

/**
 * @brief Función que solo muestra un mensaje de ayuda por pantalla cuando se
 * introduce la palabra clave para pedir instrucciones más detalladas sobre
 * como usar el programa.
 * 
 * @param kProgramName Es el nombre del actual programa, usando por el mensaje.
 */
void HelpMessage(const std::string& kProgramName) {
  cout << kProgramName.substr(2) << " es un programa que simula a una";
  cout << "\ntabla hash, es una tabla que contiene datos, pero la forma de";
  cout << "\nbuscar los datos esta muy optimizada para lograr hallarlos y";
  cout << "\ndevolverlos en un tiempo constante. Para que funcione, a este";
  cout << "\nprograma se le deben pasar 4 argumentos.";
  cout << "\n\nLos dos primeros argumentos deben ser numeros no negativos,";
  cout << "\ny tambien distintos de cero.";
  cout << "\nEl tercer argumento es el tipo de funcion de dispersion y solo";
  cout << "\nse admite como entradas a estos argumentos '-M', '-R' o '-S', el";
  cout << "\nargumento '-M' es de Modulo, la funcion de dispersion será una";
  cout << "\nfuncion de modulo, la '-R' es de random, sera una funcion que";
  cout << "\ndevuelva un valor aleatorio dentro de un intervalo y la '-S' es";
  cout << "\nde suma, la funcion suma los valores ASCII de la entrada, y ese";
  cout << "\nvalor se divide por el tamaño de la tabla y se obtiene el resto";
  cout << "\nque sera la posicion.";
  cout << "\nEl cuarto argumento es el tipo de funcion de exploracion y solo";
  cout << "\nse admiten como entradas '-c' que significa que la funcion es";
  cout << "\ncuadratica, devuelve el numero cuadrado del intento de acceder a";
  cout << "\nun bloque de la tabla hash, luego '-d' significa doble";
  cout << "\ndispersion, se aplica usa serie de formulas para obtener una";
  cout << "\nposicion nueva, despues '-l' es de lineal, la funcion de";
  cout << "\nexploracion es simple, solo consulta el siguiente bloque, y si";
  cout << "\nesta lleno, el siguiente, hasta hallar uno, y por ultimo '-r' es";
  cout << "\nde Redispersion, la cual elige una formula de dispersion";
  cout << "\nentre las que disponga y la usa para hallar el nuevo bloque.";
  cout << "\n\nEjemplo: ";
  cout << "\n" << kProgramName << " 3 4 [-M|-R|-S] [-c|-d|-l|-r]\n\n";
}

/**
 * @brief Función que informa al usuario de que ha introducido un numero
 * incorrecto de argumentos.
 * 
 * @param kProgramName Nombre del programa.
 * @param kHelp Palabra clave para pedir instrucciones específicas al programa
 * tras invocarlo.
 */
void WrongNumberOfArguments(const std::string& kProgramName, 
                            const std::string& kHelp) {
  cerr << "Warning!, se ha pasado al programa un número incorrecto de ";
  cerr << "argumentos";
  cerr << "\nPruebe: '" << kProgramName << " " << kHelp << "' ";
  cerr << "para mas información\n";
}

/**
 * @brief Funcion que dada una cadena de entrada, determina con ayuda de la
 * funcion 'isdigit(char)' si la cadena dada a la funcion, es un numero o no.
 * 
 * @param str Cadena a ser evaluada.
 * @return true La cadena si es un dato susceptible de ser un numero.
 * @return false La cadena no puede interpretarse como un numero.
 */
bool IsItANumber(const std::string& str) {
  bool result{true};
  for (int i{0}; i < int(str.length()); ++i) {
    if (!(isdigit(str[i]) != 0)) {
      result = false;
      break;
    }
  }
  return result;
}

/**
 * @brief Funcion que avisa al usuario mediante un mensaje de texto, que los
 * argumentos dados al programa son erroneos.
 * 
 * @param kProgramName Nombre del actual programa.
 * @param kHelp Palabra clave para pedir instrucciones específicas sobre como
 * usar el programa.
 */
void WrongArguments(const std::string& kProgramName, const std::string& kHelp) {
  cerr << "Warning!, se ha introducido cuatro argumentos al programa, pero";
  cerr << "\nlos 2 primeros no son numeros enteros, o son numeros enteros ";
  cerr << "negativos";
  cerr << "\nPruebe: '" << kProgramName << " " << kHelp << "' ";
  cerr << "para mas información\n";
}

/**
 * @brief Funcion que determina si un dato de tipo string que ya sabemos que
 * puede ser susceptible de ser pasado a un numero entero sin problema, es el
 * numero cero exactamente.
 * 
 * @param str Cadena a ser evaluada
 * @return true La cadena pasada a tipo int, tiene valor 0.
 * @return false La cadena pasada a tipo int, tiene valor distinto de 0.
 */
bool IsItAZero(const std::string& str) {
  if (std::stoi(str) == 0) return true;
  return false;
}

/**
 * @brief Funcion que muestra un mensaje de error cuando los dos primeros
 * argumentos del programa son numeros no negativos, pero minimo uno de ellos
 * es un cero.
 * 
 * @param kProgramName Nombre del actual programa.
 * @param kHelp Palabra clave para pedir instrucciones específicas sobre el
 * funcionamiento del programa.
 */
void ArgumentsEqualZero(const std::string& kProgramName, 
                        const std::string& kHelp) {
  cerr << "Warning!, uno o mas de los argumentos dados al programa es un cero";
  cerr << "\nPruebe: '" << kProgramName << " " << kHelp << "' ";
  cerr << "para mas información\n";
}

/**
 * @brief Función que informa al usuario de que el tercer argumento que le pasó
 * al programa no es un tipo válido de funcion de dispersion, y esta función
 * actua como mensaje de error.
 * 
 * @param kProgramName Nombre del programa.
 * @param kHelp Palabra clave para pedir instrucciones específicas al programa
 * tras invocarlo.
 */
void WrongTypeOfDispersionFunction(const std::string& kProgramName, 
                                   const std::string& kHelp) {
  cerr << "Warning!, se ha introducido al programa como tercer argumento un";
  cerr << "\nflag distinto de '-M', '-R' o '-S'";
  cerr << "\nPruebe: '" << kProgramName << " " << kHelp << "' ";
  cerr << "para mas información\n";
}

/**
 * @brief Función que informa al usuario de que el cuarto argumento que le pasó
 * al programa no es un tipo válido de funcion de exploracion, y esta función
 * actua como mensaje de error.
 * 
 * @param kProgramName Nombre del programa.
 * @param kHelp Palabra clave para pedir instrucciones específicas al programa
 * tras invocarlo.
 */
void WrongTypeOfExplorationFunction(const std::string& kProgramName, 
                                    const std::string& kHelp) {
  cerr << "Warning!, se ha introducido al programa como cuarto argumento un";
  cerr << "\nflag distinto de '-c', '-d', '-l' o '-r'";
  cerr << "\nPruebe: '" << kProgramName << " " << kHelp << "' ";
  cerr << "para mas información\n";
}

/**
 * @brief Funcion que nos ayuda a procesar las entradas del programa por línea
 * de comandos para comprobar si se han pasado valores correctos al programa.
 * 
 * @param argc Número de argumentos pasados al programa (incluido el nombre).
 * @param argv Array de puntero a caracteres donde cada posición contiene el
 * primer caracter de cada argumento del programa.
 */
void Usage(const int& argc, char* argv[]) {
  const std::string kProgramName{argv[0]};
  const std::string kHelp{"--help"};

  if (argc == 1) {
    MainMessage(kProgramName, kHelp);
    exit(EXIT_SUCCESS);
  }

  const std::string kTableRows{argv[1]};

  if ((argc == 2) && (kHelp == kTableRows)) {
    HelpMessage(kProgramName);
    exit(EXIT_SUCCESS);
  }

  if (argc != 5) {
    WrongNumberOfArguments(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  const std::string kTableCols{argv[2]};
  const std::string kKindOfDispersionFunction{argv[3]};
  const std::string kKindOfExplorationFunction{argv[4]};

  if (!(IsItANumber(kTableRows)) || !(IsItANumber(kTableCols))) {
    WrongArguments(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  if (IsItAZero(kTableRows) || IsItAZero(kTableCols)) {
    ArgumentsEqualZero(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  if ((kKindOfDispersionFunction != "-M") && 
      (kKindOfDispersionFunction != "-R") && 
      (kKindOfDispersionFunction != "-S")) {
    WrongTypeOfDispersionFunction(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  if ((kKindOfExplorationFunction != "-c") &&
      (kKindOfExplorationFunction != "-d") &&
      (kKindOfExplorationFunction != "-l") &&
      (kKindOfExplorationFunction != "-r")) {
    WrongTypeOfExplorationFunction(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }
}
