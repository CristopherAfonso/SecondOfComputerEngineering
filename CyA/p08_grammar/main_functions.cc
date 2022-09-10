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
 * 16/11/21 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include
 * 16/11/21 - Funciones del main terminadas.
 */

#include <iostream>

/**
 * @brief void MainMessage(). Muestra el mensaje predeterminado del programa si
 * se intenta ejecutar sin ningún parámetro.
 * 
 * @param kProgramName Nombre el programa que invoca a la función.
 * @param kHelp Palabra clave para solicitar las instrucciones del programa.
 */
void MainMessage(const std::string& kProgramName, 
                 const std::string& kHelp) {
  std::cout << "Modo de empleo: " << kProgramName << " input.cfg input.drv ";
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
  std::cout << "\n" << kProgramName << " input.cfg input.drv output.txt";
  std::cout << "\n\ninput.cfg es el archivo que contiene la descripición de";
  std::cout << "\nla gramática que usa el programa (este archivo tiene una";
  std::cout << "\nsintaxis muy rigurosa para que el programa lo acepte y";
  std::cout << "\npueda crear debidamente la gramática, esta se explica en";
  std::cout << "\neste mismo mensaje más adelante, y; para input.cfg, solo se";
  std::cout << "\nadmite el formato \".cfg\", cualquier otro formato será";
  std::cout << "\nrechazado).";
  std::cout << "\n\ninput.drv es el archivo que tiene todas las órdenes que";
  std::cout << "\nqueremos que nuestra gramática siga para generar una cadena";
  std::cout << "\ndel lenguaje (solo se acepta una producción por línea, si";
  std::cout << "\nhay más de una cadena en la misma línea, solo se cogerá la";
  std::cout << "\nprimera y el resto serán ignoradas, además solo se acepta";
  std::cout << "\nel formato \".drv\", cualquier otro será rechazado)";
  std::cout << "\n\noutput.txt es el nombre que queremos darle al archivo que";
  std::cout << "\nnuestro programa creará donde guardará el resultado de";
  std::cout << "\nlas sucesivas derivaciones que ha seguido el programa para";
  std::cout << "\nllegar hasta la última derivación ordenada en input.drv, en";
  std::cout << "\noutput.txt, se verá una sucesión de derivaciones progresiva";
  std::cout << "\nhasta llegar a la última de estas y su resultado.";
  std::cout << "\n(para output.txt solo se admite el formato \".txt\",";
  std::cout << "\ncualquier otro formato será rechazado).\n";
  std::cout << "\nLa forma de crear un archivo \"input.cfg\" para que el";
  std::cout << "\nprograma lo acepte y use la gramática que este define a";
  std::cout << "\nla hora de analizar las órdenes que debe serguir es la";
  std::cout << "\nsiguiente:";
  std::cout << "\nLinea 1: Todos los símbolos terminales del alfabeto ";
  std::cout << "separados por SOLO un espacio en blanco. (obligado)";
  std::cout << "\nLinea 2: Conjunto de simbolos no terminales de la gramática";
  std::cout << "separados por SOLO un espacio en blanco. (obligado)";
  std::cout << "\nA continuación viene una línea para cada producción.";
  std::cout << "\n(si un símbolo no terminal tiene más de una producción, en";
  std::cout << "\nvez de usar el símbolo \"|\", y poner todas las producciones";
  std::cout << "\nen una misma línea, debes crear una nueva línea y ahí poner";
  std::cout << "\nel resto de producciones, una producción por línea, hasta que";
  std::cout << "\nno hayan más, si pones varias en la misma línea, habrá un";
  std::cout << "\nerror y el programa no continuará su ejecución). Pasos para";
  std::cout << "\nhacer una producción válida:";
  std::cout << "\n - Solo un símbolo no terminal al inicio de la línea (obligado)";
  std::cout << "\n - Seguido del símbolo no terminal, deben ir estos 4 caracteres";
  std::cout << "\n   exactamente en este orden \" -> \", son un espacio, un guión";
  std::cout << "\n   el símbolo mayor, y otro espacio (esto es para indicar que";
  std::cout << "\n   está efectuando a declarar una producción).";
  std::cout << "\n - Al final de la línea despues del \" -> \", debe ir la";
  std::cout << "\n   cadena de símbolo terminales y/o no terminales que genera el";
  std::cout << "\n   símbolo no terminal";
  std::cout << "\n(hay que repetir todos estos pasos por cada producción que";
  std::cout << "\nqueramos añadir a nuestra gramática)";
  std::cout << "\n\nA la hora de crear su archivo \".cfg\" tenga en cuenta";
  std::cout << "\nla siguiente regla:";
  std::cout << "\n 1. Solo existe un símbolo no terminal de arranque para la";
  std::cout << "\n    gramática, y ese símbolo se presupone que es el primer";
  std::cout << "\n    símbolo de la segunda línea del archivo \".cfg\".";
  std::cout << "\n\nNota Importante: Si tenemos una gramática que contenga la";
  std::cout << "\ncadena vacía, debemos representarla de esta forma: &&";
  std::cout << "\nya que cuando al programa se le pasa un símbolo '&'";
  std::cout << "\ninterpreta que no se ha introducido ningún símbolo";
  std::cout << "\n(porque '&' es usado para representar a la cadena vacía)";
  std::cout << "\nsi queremos representar un símbolo compuesto por dos";
  std::cout << "\ncadenas vacías lo representaríamos así '&&&&' etc...";
  std::cout << "\n\nA modo de ejemplo se muesta un posible archivo \".cfg\"";
  std::cout << "\n - Línea 1: 0 1 2 3 4 5 6 7 8 9 ( ) + -";
  std::cout << "\n - Línea 2: E N D";
  std::cout << "\n - Línea 3: E -> (E)";
  std::cout << "\n - Línea 4: E -> E+E";
  std::cout << "\n - Línea 5: E -> E-E";
  std::cout << "\n - Línea 6: E -> N";
  std::cout << "\n - Línea 7: N -> ND";
  std::cout << "\n - Línea 8: N -> D";
  std::cout << "\n - Línea 9: D -> 0";
  std::cout << "\n - Línea 10: D -> 1";
  std::cout << "\n - Línea 11: D -> 2";
  std::cout << "\n - Línea 12: D -> 3";
  std::cout << "\n - Línea 13: D -> 4";
  std::cout << "\n - Línea 14: D -> 5";
  std::cout << "\n - Línea 15: D -> 6";
  std::cout << "\n - Línea 16: D -> 7";
  std::cout << "\n - Línea 17: D -> 8";
  std::cout << "\n - Línea 18: D -> 9";
  std::cout << "\n\nCon esta gramática y el archivo de entrada siguiente:";
  std::cout << "\n - Línea 1:    E: 1";
  std::cout << "\n - Línea 2:    E: 2";
  std::cout << "\n - Línea 3:    E: 4";
  std::cout << "\n - Línea 4:    N: 2";
  std::cout << "\n - Línea 5:    D: 5";
  std::cout << "\n - Línea 6:    E: 1";
  std::cout << "\n - Línea 7:    E: 3";
  std::cout << "\n - Línea 8:    E: 4";
  std::cout << "\n - Línea 9:    N: 1";
  std::cout << "\n - Línea 10:   N: 2";
  std::cout << "\n - Línea 11:   D: 2";
  std::cout << "\n - Línea 12:   D: 1";
  std::cout << "\n - Línea 13:   E: 4";
  std::cout << "\n - Línea 14:   N: 2";
  std::cout << "\n - Línea 15:   D: 8";
  std::cout << "\n\nLa salida del programa con los dos anteriores";
  std::cout << "\narchivos sería la siguiente:";
  std::cout << "\n - Línea 1: E => (E) => (E + E) => (N + E) =>";
  std::cout << "\n(D + E) => (4 + E) => (4 + (E)) => (4 + (E - E)) =>";
  std::cout << "\n(4 + (N - E)) => (4 + (ND - E)) => (4 + (DD - E)) =>";
  std::cout << "\n(4 + (1D - E)) => (4 + (10 - E)) => (4 + (10 - N)) =>";
  std::cout << "\n(4 + (10 - D)) => (4 + (10 -7))";
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
 * mayor a 4 porque si el archivo pasado al programa fuera ".cfg" o ".txt" o
 * ".drv", tendría una extensión válida, pero sería un archivo inválido.
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
 * introducen archivos con extensiones diferentes de la ".cfg" en el primer
 * parametro del programa, o diferente de la ".drv" en el segundo, o ".txt" en 
 * el tercer parametro, entonces aparece este mensaje de error.
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
 * @brief Mensaje de error si no se puede abrir el archivo ".cfg".
 * 
 * @param kProgramName Nombre del programa.
 * @param kHelp Palabra clave para solicitar las instrucciones del programa.
 */
void ErrorCFGOpen(const std::string& kProgramName, 
                  const std::string& kHelp) {
  std::cerr << "Warning! error al abrir el archivo que contiene la definión";
  std::cerr << "\nde la gramática, reviselo y intentelo de nuevo.";
  std::cerr << "\nPruebe '" << kProgramName << " " << kHelp << "' ";
  std::cerr << "para más información.\n";
}

/**
 * @brief Mensaje de error si no se puede abrir el archivo que contiene las
 * órdenes que va a seguir el objeto Grammar.
 * 
 * @param kProgramName Nombre del programa.
 * @param kHelp Palabra clave para solicitar las instrucciones del programa.
 */
void ErrorCFGDrvOpen(const std::string& kProgramName, 
                     const std::string& kHelp) {
  std::cerr << "Warning! error al abrir el archivo que contiene las órdenes";
  std::cerr << "\nque va a seguir la gramática, reviselo y intentelo de nuevo";
  std::cerr << "\nPruebe '" << kProgramName << " " << kHelp << "' ";
  std::cerr << "para más información.\n";
}

/**
 * @brief Mensaje de error si no se puede abrir correctamente el archivo de
 * salida donde se escribirá el resultado de las órdenes que se le pasen a la
 * gramática, sus sucesivas derivaciones hasta llegar al resultado final.
 * 
 * @param kProgramName Nombre del programa.
 * @param kHelp Palabra clave para solicitar las instrucciones del programa.
 */
void ErrorCFGOutFile(const std::string& kProgramName, 
                            const std::string& kHelp) {
  std::cerr << "Warning! error al crear el archivo que contiene las sucesivas";
  std::cerr << "\nderivaciones de la gramática, intentelo de nuevo.";
  std::cerr << "\nPruebe '" << kProgramName << " " << kHelp << "' ";
  std::cerr << "para más información.\n";
}

/**
 * @brief Mensaje de error si no se puede crear correctamente el objeto Grammar
 * porque el archivo que contiene su definición está mál escrito.
 * 
 * @param kProgramName Nombre del programa.
 * @param kHelp Palabra clave para solicitar las instrucciones del programa. 
 */
void ErrorCFGFile(const std::string& kProgramName, const std::string& kHelp) {
  std::cerr << "Warning! ha habido un error al leer el archivo que contiene";
  std::cerr << "\nla definición del objeto Grammar, modifiquelo para que sea";
  std::cerr << "\nleíble por este programa y intentelo de nuevo.";
  std::cerr << "\nPruebe '" << kProgramName << " " << kHelp << "' ";
  std::cerr << "para más información.\n";
}

/**
 * @fn void ErrorCFGProductions(const std::string& kProgramName, 
 *                              const std::string& kHelp)
 * @brief Mensaje de error que se muestra por pantalla si el archivo que 
 * contiene las órdenes que debe serguir la gramática (input.drv) está mal
 * escrito.
 * 
 * @param kProgramName nombre del programa.
 * @param kHelp palabra clave para pedir las instrucciones del programa.
 */
void ErrorCFGProductions(const std::string& kProgramName, 
                         const std::string& kHelp) {
  std::cerr << "Warning! ha habido un error al leer el archivo que contiene";
  std::cerr << "\nlas órdenes que debe seguir la gramática para generar una";
  std::cerr << "\ncadena del lenguaje que genera, modifiquelo para que sea";
  std::cerr << "\nprocesable por este programa y intentelo de nuevo.";
  std::cerr << "\nPruebe '" << kProgramName << " " << kHelp << "' ";
  std::cerr << "para más información.\n";
}