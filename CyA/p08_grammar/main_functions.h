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
 * 16/11/21 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include
 * 16/11/21 - Funciones del main terminadas.
 */

#ifndef _MAIN_FUNCTIONS_
#define _MAIN_FUNCTIONS_

#include <iostream>

void MainMessage(const std::string& kProgramName, const std::string& kHelp);
void HelpMessage(const std::string& kProgramName);
void ErrorParameters(const std::string& kProgramName, 
                     const std::string& kHelp);
void ErrorSizeParameters(const std::string& kProgramName, 
                         const std::string& kHelp);
void ErrorExtensions(const std::string& kProgramName, 
                     const std::string& kHelp);
void ErrorCFGOpen(const std::string& kProgramName, const std::string& kHelp);
void ErrorCFGDrvOpen(const std::string& kProgramName, 
                     const std::string& kHelp);
void ErrorCFGOutFile(const std::string& kProgramName, 
                     const std::string& kHelp);
void ErrorCFGFile(const std::string& kProgramName, const std::string& kHelp);
void ErrorCFGProductions(const std::string& kProgramName, 
                         const std::string& kHelp);
#endif