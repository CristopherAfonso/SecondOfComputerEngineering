# Universidad de La Laguna
# Escuela Superior de Ingenieria y Tecnologia
# Grado en Ingenieria Informatica
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Practica 2: Simbolos, alfabetos y cadenas
# Autor: Cristopher Manuel Afonso Mora
# Correo: alu0101402031@ull.es
# Fecha: 08/10/2021
# Archivo makefile: Programa compilador.
#         Contiene los comandos de la shell BASH necesarios para poder compilar
#         el programa de forma automatica con solo una orden, ayuda a agilizar
#         el desarrollo del código del programa
#
# Referencias:
#         Enlaces de interes

CC = g++
CFLAGS = -I -Weffc++ -Wall -g
DEPS = alphabet_class.h word_class.h
OBJ = main_strings.o alphabet_class.o word_class.o 

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main_strings: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf *.o
