# Universidad de La Laguna (ULL)
# Escuela Superior de Ingenieria y Tecnología (ESIT)
# Grado de Ingenieria Informatica
# Asignatura: Computabilidad y Algoritmia 
# Curso: 2º
# Practica 4: Expresiones Regulares
# Autor: Cristopher Manuel Afonso Mora
# Correo: alu0101402031@ull.edu.es
# Fecha: 21/10/21 
# Archivo Makefile: Programa compilador.
#                   Contiene los comandos de la shell BASH necesarios para
#                   poder compilar el programa de forma automatica con solo
#                   una orden, ayuda a agilizar el desarrollo del codigo
#

CC = g++
CFLAGS = -I -Weffc++ -Wall -g   
DEPS = analyzer_cc_class.h
OBJ = main_code_analyzer.o analyzer_cc_class.o 

%.o: %.cc $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

main_code_analyzer: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)

clean:
		rm -rf *.o
