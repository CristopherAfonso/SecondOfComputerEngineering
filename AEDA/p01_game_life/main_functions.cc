/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 1: El Juego de la Vida
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 05/03/2022
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
 * 05/03/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include
 * 06/03/22 - Funciones del main terminadas.
 */

#include "main_functions.h"

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
  cout << "[Numero de columnas] [Numero de turnos del juego]";
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
  cout << kProgramName.substr(2) << " es un programa que simula a un automata";
  cout << "\ncelular, concretamente a 'El Juego de la Vida' de John Horton";
  cout << "\nConway. El programa se basa en una rejilla (matriz) en 2D, donde";
  cout << "\nse almacenaran celulas con dos posibles estados, viva o muerta,";
  cout << "\nlas celulas en estado vivas se representan con el símbolo 'X', y";
  cout << "\nlas muertas con el símbolo ' '. Toda celula tiene a su alrededor";
  cout << "\nexactamente 8 celulas (menos las de los bordes), y el juego se";
  cout << "\ndesarrolla de la siguiente manera.\n";
  cout << "\nInvocas al programa con los tres parametros que necesita, el";
  cout << "\nprimero es el número de filas (un número entero mayor a cero) el";
  cout << "\nsegundo es el número de columnas (un número entero mayor a cero)";
  cout << "\ny el tercer argumento es el número de turnos en los que se";
  cout << "\ndesarrollará el juego (un número entero mayor a cero).\n";
  cout << "\nDespués, el programa te pedirá que introduzcas el número de";
  cout << "\ncélulas que quieres tú que estén vivas en el turno cero";
  cout << "\n(debe ser un número entero mayor a cero), y después de dar";
  cout << "\nese número, se te pedirá que introduzcas las coordenadas en 2D";
  cout << "\nde todas esas células que quieres que empiecen vivas en el turno";
  cout << "\ncero, después se aplicarán lasi siguientes normas a todas las";
  cout << "\ncélulas del juego:";
  cout << "\n - Si una celula 'muerta' tiene exactamente 3 celulas en estado\n";
  cout << "   viva a su alrededor, pasa a ser una viva en el turno siguiente.";
  cout << "\n   En cualquier otro caso permanece muerta.";
  cout << "\n - Si una celula viva tiene 2 o 3 celulas vecinas en estado\n";
  cout << "   'viva' continua viva en el siguiente turno.";
  cout << "\n   En cualquier otro caso pasa al estado de 'muerta'.\n";
  cout << "\nEstas normas se aplicarán en todos los turnos, viendose por";
  cout << "\npantalla todo el desarrollo del juego.\n";
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
  cerr << "Warning!, se ha introducido tres argumentos al programa, pero";
  cerr << "\nestos no son numeros enteros, o son numeros enteros negativos";
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
  bool result{false};
  int aux{std::stoi(str)};
  if (aux == 0) result = true;
  return result;
}

/**
 * @brief Funcion que muestra un mensaje de error cuando los tres argumentos
 * del programa son numeros no negativos, pero minimo uno de ellos es un cero.
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

  const std::string kRows{argv[1]};

  if ((argc == 2) && (kHelp == kRows)) {
    HelpMessage(kProgramName);
    exit(EXIT_SUCCESS);
  }

  if (argc != 4) {
    WrongNumberOfArguments(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  const std::string kCols{argv[2]};
  const std::string kTurns{argv[3]};

  if (!(IsItANumber(kRows)) || !(IsItANumber(kCols)) || !(IsItANumber(kTurns))) {
    WrongArguments(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  if (IsItAZero(kRows) || IsItAZero(kCols) || IsItAZero(kTurns)) {
    ArgumentsEqualZero(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }
}

