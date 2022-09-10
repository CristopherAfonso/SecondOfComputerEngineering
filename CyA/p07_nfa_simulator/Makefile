# Universidad de La Laguna (ULL)
# Escuela Superior de Ingenieria y Tecnologia (ESIT)
# Grado en Ingeniera Informatica
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Practica 7: Simulacion de NFA's (Autómatas Finitos No Deterministas)
# @author Cristopher Manuel Afonso Mora
# Correo: alu0101402031@ull.edu.es
# @date 11/11/21
# 
# @file Makefile
# @brief programa que permite automatizar el proceso de compilación para 
#				 agilizar el desarrollo del código
# 
# @bug No hay bugs conocidos
# 
# Historial de Revisiones 
# 11/11/21 - Creacion (primera version) del codigo:
#            Cree el archivo, y tras crear todos los archivos que mi ejecutable
#            necesitara (vacios, pero creados), terminé este archivo, solo
#            tiene dos ordenes, y son "make main_dfa_simulator" y "make clean"
#            la primera compila el programa, y la segunda limpia de la carpeta
#            actual todos los archivos ".o" que existan
#

CC = g++
CFLAGS = -I -std=c++20 -Wall -Weffc++ -Wextra -g
DEPS = alphabet.h chain.h nfa.h state_nfa.h symbol.h
OBJ = main_nfa_simulator.o alphabet.o chain.o nfa.o state_nfa.o symbol.o

%.o: %.cc $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

main_nfa_simulator: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean: 
		rm -rf *.o
