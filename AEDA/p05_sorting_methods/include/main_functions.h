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
 * 21/04/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado los #include necesarios.
 * 23/04/22 - Archivo terminado.
 */

#include <iostream>
#include <vector>
#include <string>
#include <ctime> ///< Funcion time()
#include <stdlib.h>

#include "../include/Selection.h"
#include "../include/QuickSort.h"
#include "../include/ShellSort.h"
#include "../include/HeapSort.h"
#include "../include/RadixSort.h"
#include "../include/TestOrdenation.h"

void MainMessage(const std::string& kProgramName, const std::string& kHelp);
void HelpMessage(const std::string& kProgramName);
void WrongNumberOfArguments(const std::string& kProgramName, 
                            const std::string& kHelp);
bool IsItANumberIntPositive(const std::string& str);
void WrongArguments(const std::string& kProgramName, const std::string& kHelp);
bool IsItAPossibleAlpha(const std::string& str);
void Usage(const int& argc, char* argv[]);
