# Universidad de La Laguna (ULL)
# Escuela Superior de Ingeniería y Tecnología (ESIT)
# Grado en Ingeriería Informática
# Curso: 2º
# Computabilidad y Algoritmia
# Práctica 8: Gramática para expresiones aritméticas
# @author Cristopher Manuel Afonso Mora
# Correo: alu0101402031@ull.edu.es
# @date 16/11/21
# @brief este es el archivo CMake para crear automáticamente un archivo 
# Makefile para compilar este proyecto.

# 1º Paso: Declarar la versión del CMake
cmake_minimum_required(VERSION 3.8)

# 2º Paso: Poner el nombre del proyecto (del archivo donde se halla el main)
project(main_grammar.cc
    VERSION 1.0
    DESCRIPTION "Este proyecto simula el comportamiento de una gramática"
    LANGUAGES CXX)

# 3º Paso: Especificar el Estándar que se usará en C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# 4º Paso: Especificar al CMake en qué carpeta situar el ejecutable
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

# 5º Paso: Colocamos las etiquetas ó banderas(FLAGS) de depuración y lanzamiento
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-03")

# 6º Paso: Decirle al CMake donde buscar los archivos *.h
include_directories(${PROJECT_SOURCE_DIR})

# 7º Paso: Ponemos el nombre del ejecutable y la lista de archivos que habrá que compilar para crearlo
add_executable(main_grammar
    set_symbols.cc
    set_symbols.h
    productions.cc
    productions.h
    grammar.cc
    grammar.h
    main_functions.cc
    main_functions.h
    main_grammar.cc
    )

# 8º Paso: Agregar características esperadas del compilador a un objeto (nuestro ejecutable)
target_compile_features(main_grammar PRIVATE cxx_std_20)

# 9º Paso: Añadir las opciones del compilador a un objeto (nuestro ejecutable)
target_compile_options(main_grammar PRIVATE -Wall -Wextra -Weffc++ -Wpedantic -Werror)

# Fin del archivo