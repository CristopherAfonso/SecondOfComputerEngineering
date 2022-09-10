/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 2: El Ciclo de la Vida
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 13/03/2022
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
 * 13/03/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include
 * 15/03/22 - Funciones del main terminadas.
 */

#include <iostream>
#include <string>

#include "Grid.h"

void MainMessage(const std::string& kProgramName, const std::string& kHelp);
void HelpMessage(const std::string& kProgramName);
void WrongNumberOfArguments(const std::string& kProgramName, 
                            const std::string& kHelp);
bool IsItANumber(const std::string& str);
void WrongArguments(const std::string& kProgramName, const std::string& kHelp);
bool IsItAZero(const std::string& str);
void ArgumentsEqualZero(const std::string& kProgramName, 
                        const std::string& kHelp);
void Usage(const int& argc, char* argv[]);
