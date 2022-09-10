# Universidad de La Laguna (ULL)
# Escuela Superior de Ingenieria y Tecnologia (ESIT)
# Grado en Ingeniera Informatica
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Practica 11: Algoritmos Voraces (Greedy)
# @author Cristopher Manuel Afonso Mora
# Correo: alu0101402031@ull.edu.es
# @date 27/12/21
# 
# @file Makefile
# @brief programa que permite automatizar el proceso de compilación para 
#        agilizar el desarrollo del código
# 
# @bug No hay bugs conocidos
# 
# Historial de Revisiones 
# 27/12/21 - Creacion (primera version) del codigo:
#            Cree el archivo, y tras crear todos los archivos que mi ejecutable
#            necesitara (vacios, pero creados), terminé este archivo, solo
#            tiene dos ordenes, y son "make main_backpack" y "make clean"
#            la primera compila el programa, y la segunda limpia de la carpeta
#            actual todos los archivos ".o" que existan
#

CC = g++
CFLAGS = -I -g -std=c++17 -Wall -Weffc++ -Wextra -Wpedantic -Werror
DEPS = main_functions.h 
OBJ = main_backpack.o main_functions.o 

%.o: %.cc $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

backpack: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o
