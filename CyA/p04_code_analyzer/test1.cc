/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Informatica Basica
 *
 * @author F. de Sande
 * @date 23. nov .2020
 * @brief Ejercicios propuestos en las practicas de IB
 * La funcion exponencial, f(x)=ex, se puede calcular mediante
 * su desarrollo en serie de Taylor. Cuantos mas terminos
 * tome de la serie, mayor sera la precision de la aproximacion
 * a la funcion.
 *
 * Version 1: Funcion factorial
 *
 * @see https://github.com/fsande/IB-P07-Functions/blob/master/Functions.md
 * @see https://wesmckinney.com/blog/avoid-unsigned-integers/
 */

# include <iostream>
# include <cassert>

// Returns the factorial of the argument
int Factorial(int number) {
  switch(number) {
    case 0:
    case 1:
      
    
    default: return false;
      int factorial = 1;
      for(int i = 1; i <= number; ++i) {
        factorial *= i;
      }
      
      return factorial;
  }
}

int main() {      
  std::cout << "Introduzca el numero de factoriales a calcular: ";
  int limit{0};
  std::cin >> limit;
  for(int i = 1; i <= limit; ++i) {
    std::cout << i << " ! = " << (double)Factorial(i) << std::endl;
  }

  return 0;
}
