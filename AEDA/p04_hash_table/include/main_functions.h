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
 * 03/04/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado los #include necesarios.
 * 03/04/22 - Archivo terminado.
 */

#include <iostream>
#include <string>
#include "DFModulo.h"
#include "DFRandom.h"
#include "EFCuadratica.h"
#include "HashTable.h"
#include "SBlock.h"
#include "SList.h"

void MainMessage(const std::string& kProgramName, const std::string& kHelp);
void HelpMessage(const std::string& kProgramName);
void WrongNumberOfArguments(const std::string& kProgramName, 
                            const std::string& kHelp);
bool IsItANumber(const std::string& str);
void WrongArguments(const std::string& kProgramName, const std::string& kHelp);
bool IsItAZero(const std::string& str);
void ArgumentsEqualZero(const std::string& kProgramName, 
                        const std::string& kHelp);
void WrongTypeOfDispersionFunction(const std::string& kProgramName, 
                                   const std::string& kHelp);
void WrongTypeOfExplorationFunction(const std::string& kProgramName, 
                                    const std::string& kHelp);
void Usage(const int& argc, char* argv[]);
