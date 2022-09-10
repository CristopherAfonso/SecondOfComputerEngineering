/**
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 5: Implementación de Métodos de Ordenación
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 21/04/2022
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
 * 21/04/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado los #include necesarios.
 * 23/04/22 - Archivo terminado.
 */

#include "../include/main_functions.h"

using std::cout;
using std::cerr;

/**
 * @brief @brief Función que solo muestra un mensaje por pantalla sobre como
 * usar el programa
 * 
 * @param kProgramName nombre del programa que invoca la funcion
 * @param kHelp palabra clave para pedir mas instrucciones
 */
void MainMessage(const std::string& kProgramName, const std::string& kHelp) {
  cout << "Modo de empleo: " << kProgramName << " [Forma de elegir elementos ";
  cout << "del vector] [Numero de elementos del vector] [Tipo de algoritmo de";
  cout << " ordenacion]";
  cout << "\nPruebe: '" << kProgramName << " " << kHelp << "' ";
  cout << "Para más información\n";
}

/**
 * @brief Función que solo muestra un mensaje de ayuda por pantalla cuando se
 * introduce la palabra clave para pedir instrucciones más detalladas sobre
 * como usar el programa.
 * 
 * @param kProgramName Es el nombre del actual programa, usado por el mensaje
 */
void HelpMessage(const std::string& kProgramName) {
  cout << "\n" << kProgramName << " [-R|-C] (N) [-s|-q|-S|-h|-r]\n\n";
  cout << "-R ==> Los elementos del vector a ordenar se generan aleatoriamente\n";
  cout << "-C ==> Los elementos del vector a ordenar los introduce el usuario";
  cout << " manualmente uno a uno\n\n";
  cout << "N ==> es un numero de tipo entero positivo distinto de cero (si da\n";
  cout << "  un double el programa no lo aceptara) para indicar la cantidad\n";
  cout << "  de elementos del vector a introducir en este\n\n";
  cout << "-s ==> Tipo de algoritmo de ordenacion: \"Seleccion\"\n";
  cout << "-q ==> Tipo de algoritmo de ordenacion: \"QuickSort\"\n";
  cout << "-S ==> Tipo de algoritmo de ordenacion: \"ShellSort\"\n";
  cout << "-h ==> Tipo de algoritmo de ordenacion: \"HeapSort\"\n";
  cout << "-r ==> Tipo de algoritmo de ordenacion: \"RadixSort\"\n\n";
}

/**
 * @brief Función que informa al usuario de que ha introducido un numero
 * incorrecto de argumentos.
 * 
 * @param kProgramName Nombre del programa.
 * @param kHelp Palabra clave para pedir instrucciones específicas al programa.
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
 * funcion 'isdigit(char)' si la cadena dada a la funcion, es un numero o no,
 * el numero cero no se cuenta aqui como un numero positivo
 * 
 * @param str Cadena a ser evaluada.
 * @return true La cadena si es un dato susceptible de ser un numero.
 * @return false La cadena no puede interpretarse como un numero.
 */
bool IsItANumberIntPositive(const std::string& str) {
  bool result{true};
  for (int i{0}; i < int(str.length()); ++i) {
    if (!(isdigit(str[i]) != 0)) {
      result = false;
      break;
    }
  }

  if (result && (std::stoi(str) == 0)) result = false;
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
  cerr << "Warning!, hay algun error en los parametros que ha introducido al\n";
  cerr << "programa, reviselos e intentelo de nuevo";
  cerr << "\nPruebe: '" << kProgramName << " " << kHelp << "' ";
  cerr << "para mas información\n";
}

/**
 * @brief Funcion que evalua una cadena de entrada para averiguar si tiene un
 * valor entre ]0, 1[
 * 
 * @param str cadena a ser evaluada.
 * @return true El valor se puede pasar a un numero decimal con valor: 0 < double(str) < 1
 * @return false El valor no se puede pasar a un numero decimal con valor: 0 < double(str) < 1
 */
bool IsItAPossibleAlpha(const std::string& str) {
  bool result{true};
  if (str.length() >= 3) {
    if (str.substr(0, 2) != "0.") result = false;
    if (result) result = IsItANumberIntPositive(str.substr(2));
  } else result = false;

  return result;
}

void Usage(const int& argc, char* argv[]) {
  const std::string kProgramName{argv[0]};
  const std::string kHelp{"--help"};

  if (argc == 1) {
    MainMessage(kProgramName, kHelp);
    exit(EXIT_SUCCESS);
  }

  const std::string kWayToIntroduceElements{argv[1]};

  if ((argc == 2) && (kHelp == kWayToIntroduceElements)) {
    HelpMessage(kProgramName);
    exit(EXIT_SUCCESS);
  }

  if (argc < 4) {
    WrongNumberOfArguments(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  const std::string kNumberOfElements{argv[2]};
  const std::string kTypeOfAlgorithm{argv[3]};

  if (!(kWayToIntroduceElements == "-R" || kWayToIntroduceElements == "-C")) {
    WrongArguments(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  if (!((kTypeOfAlgorithm == "-s") || (kTypeOfAlgorithm == "-q") || 
      (kTypeOfAlgorithm == "-S") || (kTypeOfAlgorithm == "-h") || 
      (kTypeOfAlgorithm == "-r"))) {
    WrongArguments(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  if (!IsItANumberIntPositive(kNumberOfElements)) {
    WrongArguments(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }
}
