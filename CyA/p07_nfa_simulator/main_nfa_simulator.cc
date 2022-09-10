/**
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 7: Simulacion de NFA's (Autómatas Finitos No Deterministas)
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 11/11/2021
 * 
 * @file main_nfa_simulator.cc (programa cliente)
 * @brief Programa que dados solo 3 parametros de entrada, y usa la clase Nfa
 * simulando el comportamiento del Autómata Finito No Determinista (AFN ó NFA),
 * y dandole un archivo de entrada con cadenas sobre un determinado lenguage
 * este devuelve el resultado del proceso del NFA sobre cada cadena del archivo
 * diciendo en el archivo de salida generado, si las cadenas fueron aceptadas o
 * rechazadas.
 * 
 * Si quiere saber mas detalles sobre como usar el programa ejecutable,
 * ejecute: ./main_nfa_simulator --help
 * para mas informacion.
 * 
 * @bug No hay bugs conocidos
 * 
 * Referencias:
 * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
 * Gracias a este enlace y los ofrecidos por el profesorado, he podido hacer
 * esta práctica con documentación doxygen
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 11/11/21 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 */

#include "nfa.h"

/**
 * @brief void MainMessage(). Muestra el mensaje predeterminado del programa si
 * se intenta ejecutar sin ningún parámetro.
 * 
 * @param kProgramName Nombre el programa que invoca a la función.
 * @param kHelp Palabra clave para solicitar las instrucciones del programa.
 */
void MainMessage(const std::string& kProgramName, 
                        const std::string& kHelp) {
  std::cout << "Modo de empleo: " << kProgramName << " input.nfa input.txt ";
  std::cout << "output.txt";
  std::cout << "\nPruebe: '" << kProgramName << " " << kHelp << "' ";
  std::cout << "Para más información\n";
}

/**
 * @brief void HelpMessage(). Muestra el mensaje de ayuda del programa que le
 * dice al usuario como usarlo correctamente.
 * 
 * @param kProgramName Nombre el programa que invoca a la función.
 */
void HelpMessage(const std::string& kProgramName) {
  std::cout << kProgramName.substr(2) << " es un programa que solo recibe 3";
  std::cout << "\nparámetros, primero 2 archivos existentes y luego el nombre";
  std::cout << "\nde un tercer archivo que se creará si todo se ejecuta";
  std::cout << "\ncorrectamente (si el tercer archivo ya existe al ejecutar";
  std::cout << "\nel programa, este se sobreescribirá sin avisar).";
  std::cout << "\nEl modo de empleo es el siguiente:";
  std::cout << "\n" << kProgramName << " input.nfa input.txt output.txt";
  std::cout << "\n\ninput.nfa es el archivo que contiene la descripición del";
  std::cout << "\nNfa que usará nuestro programa (este archivo debe tener una";
  std::cout << "\nsintaxis muy rigurosa, para que el programa lo acepte y";
  std::cout << "\npueda crear debidamente el Nfa y usarlo, esta se explica en";
  std::cout << "\neste mismo mensaje más adelante, y; para input.nfa, solo se";
  std::cout << "\nadmite el formato \".nfa\", cualquier otro formato será";
  std::cout << "\nrechazado).";
  std::cout << "\n\ninput.txt es el archivo que tiene todas las cadenas que";
  std::cout << "\nqueremos que nuestro Nfa analice y nos diga si las acepta";
  std::cout << "\no las rechaza (solo se acepta una cadena por línea, si hay";
  std::cout << "\nmás de una cadena en la misma línea, solo se cogerá la";
  std::cout << "\nprimera y el resto serán ignoradas, además solo se acepta";
  std::cout << "\nel formato \".txt\", cualquier otro será rechazado)";
  std::cout << "\n\noutput.txt es el nombre que queremos darle al archivo que";
  std::cout << "\nnuestro programa creará donde guardará los resultados de";
  std::cout << "\nsu análisis sobre cada cadena del archivo input.txt, en";
  std::cout << "\ncada línea de output.txt, se verá una cadena analizada por";
  std::cout << "\nel Nfa y a continuación, si la ha rechazado o aceptado";
  std::cout << "\n(para output.txt solo se admite el formato \".txt\",";
  std::cout << "\ncualquier otro formato será rechazado).";
  std::cout << "\n";
  std::cout << "\nLa forma de crear un archivo \"input.nfa\" para que este";
  std::cout << "\nlo acepte y lo use a la hora de analizar las cadenas de un";
  std::cout << "\nes la siguiente:";
  std::cout << "\nLinea 1: Número total de estados del NFA (obligado)";
  std::cout << "\nLinea 2: Estado de arranque del Nfa (obligado)";
  std::cout << "\nA continuación viene una línea para cada estado.";
  std::cout << "\n(si en la primera línea hay un 4, ponemos 4 líneas más de";
  std::cout << "\nla siguiente forma).";
  std::cout << "\n - Número identificador del estado (obligado), los estados";
  std::cout << "\n   del autómata se representarán mediante números enteros";
  std::cout << "\n   sin signo, la numeración de los estados correspoderá a";
  std::cout << "\n   a los primeros números naturales comenzando por 0.";
  std::cout << "\n   (es decir, si una linea empieza por 1, pero su línea";
  std::cout << "\n   predecesora no empieza por 0, siendo esta una línea";
  std::cout << "\n   distinta a la del estado de arranque del Nfa, el archivo";
  std::cout << "\n   será rechazado).";
  std::cout << "\n - Un número que identifica si el estado es de aceptación";
  std::cout << "\n   (1 para los de aceptación y 0 para no aceptación).";
  std::cout << "\n - Número de transiciones que posee el estado (este número";
  std::cout << "\n   mientras sea no negativo no pasa nada).";
  std::cout << "\n - A continiación para cada una de las transiciones, y";
  std::cout << "\n   separadas por espacios en blanco, se detallará la";
  std::cout << "\n   información siguiente:";
  std::cout << "\n     - Simbolo de entrada necesario realizar la transición.";
  std::cout << "\n     - Estado destino de la transición. (número no negativo";
  std::cout << "\n       menor al número que hay en la primera línea).";
  std::cout << "\n\nA la hora de crear su archivo \".nfa\" tenga en cuenta";
  std::cout << "\nla siguiente regla:";
  std::cout << "\n 1. Solo existe un estado inicial para el autómata";
  std::cout << "\n\nNota Importante: Si tenemos un lenguaje que contenga la";
  std::cout << "\ncadena vacía, debemos representarla de esta forma: &&";
  std::cout << "\nya que cuando al programa se le pasa un símbolo '&'";
  std::cout << "\ninterpreta que no se ha introducido ningún símbolo";
  std::cout << "\n(porque '&' es usado para representar a la cadena vacía)";
  std::cout << "\nsi queremos representar un símbolo compuesto por dos";
  std::cout << "\ncadenas vacías lo representaríamos así '&&&&' etc...";
  std::cout << "\n\nA modo de ejemplo se muesta un posible archivo \".nfa\"";
  std::cout << "\n - Línea 1: 4";
  std::cout << "\n - Línea 2: 0";
  std::cout << "\n - Línea 3: 0 0 3 a 0 b 0 b 1";
  std::cout << "\n - Línea 4: 1 0 2 a 2 b 2";
  std::cout << "\n - Línea 5: 2 0 2 a 3 b 3";
  std::cout << "\n - Línea 6: 3 1 0";
  std::cout << "\n\nCon el Nfa anterior y el archivo de entrada siguiente:";
  std::cout << "\n - Línea 1: & (como si al autómata no le pasaramos nada)";
  std::cout << "\n - Línea 2: && (le pasamos al Dfa el símbolo cadena vacía)";
  std::cout << "\n - Línea 3: a";
  std::cout << "\n - Línea 4: bb";
  std::cout << "\n - Línea 5: abb";
  std::cout << "\n - Línea 6: bab";
  std::cout << "\n - Línea 7: bbbb";
  std::cout << "\n - Línea 8: ababaa";
  std::cout << "\n\nLa salida del anterior archivo sería la siguiente:";
  std::cout << "\n - Línea 1: & -- Rejected";
  std::cout << "\n - Línea 2: && -- Rejected (no está en el alfabeto)";
  std::cout << "\n - Línea 3: a -- Rejected";
  std::cout << "\n - Línea 4: bb -- Rejected";
  std::cout << "\n - Línea 5: abb -- Rejected";
  std::cout << "\n - Línea 6: bab -- Accepted";
  std::cout << "\n - Línea 7: bbbb -- Accepted";
  std::cout << "\n - Línea 8: ababaa -- Acepted";
  std::cout << "\nFin del Mensaje.\n";
}

/**
 * @brief Mensaje de error que se muestra si no se han pasado correctamente los
 * parametros a la función.
 * 
 * @param kProgramName nombre del programa que llama a la función.
 * @param kHelp palabra clave para solicitar las instrucciones del programa.
 */
void ErrorParameters(const std::string& kProgramName, 
                            const std::string& kHelp) {
  std::cerr << "Warning!, Faltan/Sobran argumentos para ejecutar este ";
  std::cerr << "programa.";
  std::cerr << "\nPruebe '" << kProgramName << " " << kHelp << "' ";
  std::cerr << "para más información.\n";
}

/**
 * @brief Mensaje de error en la forma en la que pasamos parametros a la
 * función. Si le pasamos 3 parametros a la función, pero si tamaño no es el
 * correto, o sea, mayor a 4, entonces sale este mensaje, el tamaño válido es
 * mayor a 4 porque si el archivo pasado al programa fuera ".nfa" o ".txt",
 * tendría una extensión válida, pero sería un archivo inválido.
 * 
 * @param kProgramName Nombre del programa.
 * @param kHelp Palabra clave para solicitar las instrucciones del programa.
 */
void ErrorSizeParameters(const std::string& kProgramName, 
                                const std::string& kHelp) {
  std::cerr << "Warning! debe introducir parametros válidos al programa,";
  std::cerr << "\ncompruebelos y intentelo de nuevo.";
  std::cerr << "\nPruebe '" << kProgramName << " " << kHelp << "' ";
  std::cerr << "para más información.\n";
}

/**
 * @brief Mensaje de error en las extensiones de los parámetros. Si se
 * introducen archivos con extensiones diferentes de la ".nfa" en el primer
 * parametro del programa, o diferente de la ".txt" en el segundo y tercer
 * parametro, entonces aparece este mensaje de error.
 * 
 * @param kProgramName Nombre del programa.
 * @param kHelp Palabra clave para solicitar las instrucciones del programa.
 */
void ErrorExtensions(const std::string& kProgramName, 
                            const std::string& kHelp) {
  std::cerr << "Warning! hay archivos con extensiones no aceptadas por";
  std::cerr << "\nel programa en los argumentos, pruebe con otros archivos";
  std::cerr << "\no cambieles el formato para poder ejecutar este programa";
  std::cerr << "\nPruebe '" << kProgramName << " " << kHelp << "' ";
  std::cerr << "para más información.\n";
}

/**
 * @brief Mensaje de error si no se puede abrir el archivo ".nfa".
 * 
 * @param kProgramName Nombre del programa.
 * @param kHelp Palabra clave para solicitar las instrucciones del programa.
 */
void ErrorNfaOpen(const std::string& kProgramName, 
                         const std::string& kHelp) {
  std::cerr << "Warning! error al abrir el archivo que contiene la definión";
  std::cerr << "\ndel NFA, reviselo y intentelo de nuevo.";
  std::cerr << "\nPruebe '" << kProgramName << " " << kHelp << "' ";
  std::cerr << "para más información.\n";
}

/**
 * @brief Mensaje de error si no se puede abrir el archivo que contiene las
 * palabras que va a analizar el NFA.
 * 
 * @param kProgramName Nombre del programa.
 * @param kHelp Palabra clave para solicitar las instrucciones del programa.
 */
void ErrorNfaWordsOpen(const std::string& kProgramName, 
                              const std::string& kHelp) {
  std::cerr << "Warning! error al abrir el archivo que contiene la palabras";
  std::cerr << "\nque va a analizar el NFA, reviselo y intentelo de nuevo.";
  std::cerr << "\nPruebe '" << kProgramName << " " << kHelp << "' ";
  std::cerr << "para más información.\n";
}

/**
 * @brief Mensaje de error si no se puede abrir correctamente el archivo de
 * salida donde se escribirá el resultado de las palabras que se le pasen al
 * NFA.
 * 
 * @param kProgramName Nombre del programa.
 * @param kHelp Palabra clave para solicitar las instrucciones del programa.
 */
void ErrorNfaOutFile(const std::string& kProgramName, 
                            const std::string& kHelp) {
  std::cerr << "Warning! error al crear el archivo que contiene la palabras";
  std::cerr << "\nya analizas del NFA, intentelo de nuevo.";
  std::cerr << "\nPruebe '" << kProgramName << " " << kHelp << "' ";
  std::cerr << "para más información.\n";
}

/**
 * @brief Mensaje de error si no se puede crear correctamente el NFA porque el
 * archivo que contiene su definición está mál escrito.
 * 
 * @param kProgramName Nombre del programa.
 * @param kHelp Palabra clave para solicitar las instrucciones del programa. 
 */
void ErrorNfaFile(const std::string& kProgramName, const std::string& kHelp) {
  std::cerr << "Warning! ha habido un error al leer el archivo que contiene";
  std::cerr << "\nla definición del NFA, modifiquelo para que sea leíble por";
  std::cerr << "\neste programa y intentelo de nuevo.";
  std::cerr << "\nPruebe '" << kProgramName << " " << kHelp << "' ";
  std::cerr << "para más información.\n";
}

int main(int argc, char* argv[]) {
  const std::string kProgramName{argv[0]};
  const std::string kHelp{"--help"};
  /// Si se ejecuta el programa sin parámetros, se termina con un mensaje.
  if (argc == 1) {
    MainMessage(kProgramName, kHelp);
    exit(EXIT_SUCCESS);
  }

  const std::string kNfaFile{argv[1]};
  /// Si se solicitan las instrucciones de uso del programa, se muestran y ya.
  if ((kNfaFile == kHelp) && (argc == 2)) {
    HelpMessage(kProgramName);
    exit(EXIT_SUCCESS);
  }

  /// Si no hay exactamente 3 parámetros, se cierra el programa con un mensaje.
  if (argc < 4 || argc > 4) {
    ErrorParameters(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  const std::string kNfaWords{argv[2]};
  const std::string kNfaOutFile{argv[3]};
  /// Si la longitud de alguno de los 3 parámetros no es la correta (mayor a 4)
  /// se termina el programa, porque ningún archivo válido tendrá tamaño menor.
  if (kNfaFile.size() <= 4 || kNfaWords.size() <= 4 || 
      kNfaOutFile.size() <= 4) {
    ErrorSizeParameters(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  /// Si la extensión del segundo parametro es distinta de ".nfa" o si las
  /// extensiones del segundo y tercer parámetro son distindas de ".txt"
  /// entonces se termina el programa notificando ese error.
  if (kNfaFile.substr(kNfaFile.size() - 4) != ".nfa" || 
      kNfaWords.substr(kNfaWords.size() - 4) != ".txt" || 
      kNfaOutFile.substr(kNfaOutFile.size() - 4) != ".txt") {
    ErrorExtensions(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  std::ifstream nfa_file(kNfaFile, std::fstream::in);
  std::ifstream nfa_words(kNfaWords, std::fstream::in);
  std::ofstream nfa_out_file(kNfaOutFile, std::fstream::out);

  if (nfa_file.fail()) {
    ErrorNfaOpen(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  if (nfa_words.fail()) {
    ErrorNfaWordsOpen(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  if (nfa_out_file.fail()) {
    ErrorNfaOutFile(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }
  
  // Nfa nfa(nfa_file);
  // nfa_file.close();
  // if (nfa.Fail()) {
  //   ErrorNfaFile(kProgramName, kHelp);
  //   exit(EXIT_FAILURE);
  // }

  // nfa.EvalStrInFile(nfa_words, nfa_out_file);
  nfa_words.close();
  nfa_out_file.close();

  return 0;
}
