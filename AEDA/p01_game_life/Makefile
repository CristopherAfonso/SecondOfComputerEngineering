# Universidad de La Laguna (ULL)
# Escuela Superior de Ingenieria y Tecnologia (ESIT)
# Grado en Ingeniera Informatica
# Asignatura: Algorítmos y Estructuras de Datos Avanzados
# Curso: 2º
# Practica 1: El Juego de la Vida
# @author Cristopher Manuel Afonso Mora
# Correo: alu0101402031@ull.edu.es
# @date 05/03/22
# 
# @file Makefile
# @brief programa que permite automatizar el proceso de compilación para 
#        agilizar el desarrollo del código
# 
# @bug No hay bugs conocidos
# 
# Historial de Revisiones 
# 05/03/22 - Creacion (primera version) del codigo:
#            Cree el archivo, y tras crear todos los archivos que mi ejecutable
#            necesitara (vacios, pero creados), terminé este archivo, solo
#            tiene dos ordenes, y son "make game_life" y "make clean"
#            la primera compila el programa, y la segunda limpia de la carpeta
#            actual todos los archivos ".o" que existan
#

CC = g++
CFLAGS = -I -g -std=c++17 -Wall -Weffc++ -Wextra -Wpedantic -Werror
DEPS = main_functions.h Cell.h Grid.h
OBJ = main_functions.o Cell.o Grid.o main_game_life.o

%.o: %.cc $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

game_life: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o
