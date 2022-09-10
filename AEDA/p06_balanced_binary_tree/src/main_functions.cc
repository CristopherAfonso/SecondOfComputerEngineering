/**
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 6: Árbol binario equilibrado
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 01/05/2022
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
 * 01/05/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado los #include necesarios.
 * 08/05/22 - Archivo terminado.
 */

#include "../include/main_functions.h"

using std::cout;
using std::cerr;

/**
 * @brief Función que solo muestra un mensaje de ayuda por pantalla cuando se
 * introduce la palabra clave para pedir instrucciones más detalladas sobre
 * como usar el programa.
 * 
 * @param kProgramName Es el nombre del actual programa, usado por el mensaje
 */
void HelpMessage(const std::string& kProgramName,
                 const std::string& kHelp) {
  cout << "\n" << kProgramName << " (" <<  kHelp << ")\n\n";
  cout << "--help ==> Palabra clave para pedir indicaciones sobre como\n";
  cout << "usar el programa\n\n";
  cout << "Este programa es una implementación de un tipo de dato el cual\n";
  cout << "es un arbol binario equilibrado, para usar el objeto basta con\n";
  cout << "llamar al programa y se desplegara un menu interactivo que\n";
  cout << "permite usar el arbol binario.\n\n";
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
 * @brief funcion que comrpueba que los argumentos dados al programa son correctos
 * 
 * @param argc numero de argumentos dados al programa
 * @param argv vector de argumentos del programa
 */
void Usage(const int& argc, char* argv[]) {
  const std::string kProgramName{argv[0]};
  const std::string kHelp{"--help"};
  if (argc != 1) {
    const std::string kHelpUser{argv[1]};
    if ((argc == 2) && (kHelp == kHelpUser)) {
      HelpMessage(kProgramName, kHelp);
      exit(EXIT_SUCCESS);
    } else {
      WrongNumberOfArguments(kProgramName, kHelp);
      exit(EXIT_FAILURE);
    }
  }
}
