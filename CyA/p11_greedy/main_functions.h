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
 * @file main_functions.h 
 * @brief Donde se aloja la declaración de las funciones del archivo cliente
 * de nuestro programa.
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

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>

void Usage(int argc, char* argv[], bool& acotado);
void MainMessage(const std::string& kProgramName, const std::string& kHelp);
void HelpMessage(const std::string& kProgramName);
void ErrorSoMuchParameters(const std::string& kProgramName, 
                           const std::string& kHelp);
void ErrorWrongParameters(const std::string& kProgramName, 
                          const std::string& kHelp);
void ErrorConfigFileExtension(const std::string& kProgramName, 
                              const std::string& kHelp);
void ErrorOpenConfigFile(const std::string& kProgramName, 
                         const std::string& kHelp);
void ErrorNoNumber(const std::string& kProgramName, const std::string& kHelp);
void ErrorConfigFileBody(const std::string& kProgramName, 
                         const std::string& kHelp);
void ErrorLineNotFound(const std::string& kProgramName, 
                       const std::string& kHelp);
void ErrorLackOfObj(const std::string& kProgramName, const std::string& kHelp);
void Solve(const double& kWeightLimit, const std::vector<double>& kWeightObjs, 
           const std::vector<double>& kValueObjs, const bool acotado);
void Backpack(char* argv[], const bool& acotado);