/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 8: Árbol binario AVL
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 21/05/2022
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
 * 21/05/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado los #include necesarios.
 * 21/05/22 - Archivo terminado.
 */

#include <iostream>
#include <ctime>

#include "ABE.h"
#include "ABB.h"
#include "AVL.h"
#include "Dummy.h"

void HelpMessage(const std::string& kProgramName,
                 const std::string& kHelp);
void WrongNumberOfArguments(const std::string& kProgramName, 
                            const std::string& kHelp);
void Usage(const int& argc, char* argv[]);