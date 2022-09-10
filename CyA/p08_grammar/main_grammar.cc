/**
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 8: Gramática para expresiones aritméticas
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 16/11/2021
 * 
 * @file main_grammar.cc (programa cliente)
 * @brief Programa que dados solo 3 parametros de entrada, y usa la clase 
 * Grammar simulando el comportamiento de una gramática, y dandole un
 * archivo de entrada con instrucciones sobre que pasos debe seguir a la hora
 * de derivar una cadena, este devuelve el resultado del proceso de
 * derivaciones que previamente le hemos descrito en el archivo ".drv", y el
 * resultado de sus derivaciones, es mostrado en el archivo "output.txt", por
 * último hay que destacar que la definición de la gramática se hace en el
 * archivo "input.cfg".
 * 
 * Si quiere saber mas detalles sobre como usar el programa ejecutable,
 * ejecute: ./main_grammar --help
 * para mas informacion.
 * 
 * @bug No hay bugs conocidos
 * 
 * Referencias:
 * @see
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 16/11/21 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 * 20/11/21 - Proyecto terminado.
 */

#include "main_functions.h"
#include "grammar.h"

int main(int argc, char* argv[]) {
  const std::string kProgramName{argv[0]};
  const std::string kHelp{"--help"};
  /// Si se ejecuta el programa sin parámetros, se termina con un mensaje.
  if (argc == 1) {
    MainMessage(kProgramName, kHelp);
    exit(EXIT_SUCCESS);
  }

  const std::string kCFGFile{argv[1]};
  /// Si se solicitan las instrucciones de uso del programa, se muestran y ya.
  if ((kCFGFile == kHelp) && (argc == 2)) {
    HelpMessage(kProgramName);
    exit(EXIT_SUCCESS);
  }

  /// Si no hay exactamente 3 parámetros, se cierra el programa con un mensaje.
  if (argc < 4 || argc > 4) {
    ErrorParameters(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  const std::string kCFGProductions{argv[2]};
  const std::string kCFGOutFile{argv[3]};
  /// Si la longitud de alguno de los 3 parámetros no es la correta (mayor a 4)
  /// se termina el programa, porque ningún archivo válido tendrá tamaño menor.
  if (kCFGFile.size() <= 4 || kCFGProductions.size() <= 4 || 
      kCFGOutFile.size() <= 4) {
    ErrorSizeParameters(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  /// Si la extensión del segundo parametro es distinta de ".nfa" o si las
  /// extensiones del segundo y tercer parámetro son distindas de ".txt"
  /// entonces se termina el programa notificando ese error.
  if (kCFGFile.substr(kCFGFile.size() - 4) != ".cfg" || 
      kCFGProductions.substr(kCFGProductions.size() - 4) != ".drv" || 
      kCFGOutFile.substr(kCFGOutFile.size() - 4) != ".txt") {
    ErrorExtensions(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  std::ifstream cfg_file(kCFGFile, std::fstream::in);
  std::ifstream cfg_productions(kCFGProductions, std::fstream::in);
  std::ofstream cfg_out_file(kCFGOutFile, std::fstream::out);

  if (cfg_file.fail()) {
    ErrorCFGOpen(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  if (cfg_productions.fail()) {
    ErrorCFGDrvOpen(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  if (cfg_out_file.fail()) {
    ErrorCFGOutFile(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }
  
  Grammar grammar(cfg_file);
  cfg_file.close();
  if (grammar.Fail()) { ///< si la creación falla, se sale del programa.
    ErrorCFGFile(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  }

  /// si la lectura del archivo input.drv falla, se sale del programa.
  if (grammar.EvalProdsInFile(cfg_productions, cfg_out_file)) {
    ErrorCFGProductions(kProgramName, kHelp);
    exit(EXIT_FAILURE);
  };

  cfg_productions.close();
  cfg_out_file.close();

  return 0;
}
