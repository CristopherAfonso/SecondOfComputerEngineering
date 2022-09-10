/**
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 5: Implementación de Métodos de Ordenación
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 21/04/2022
 * 
 * @file main_sorting_methods.cc (programa cliente)
 * @brief Programa que nos permite aplicar a un vector dado por el usuario o
 * generado aleatoriamente, uno de varios métodos de ordenacion famosos sobre
 * él y mostrarlo por pantalla mientras se ordena para ver su desarrollo.
 * 
 * Si quiere saber mas detalles sobre como usar el programa ejecutable,
 * ejecute: ./main_sorting_methods --help
 * para mas informacion.
 * 
 * @bug No hay bugs conocidos
 * 
 * Referencias:
 * @see
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 21/04/2022 - Creacion (primera version) del codigo:
 *              Solo he creado el archivo, le he puesto el comentario de
 *              cabecera y declarado los #include necesarios.
 * 22/04/2022 - Archivo terminado.
 */

#include "../include/main_functions.h"
#include "../include/TestOrdenation.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);

  const std::string kWayToIntroduceElements{argv[1]};
  const std::string kNumberOfElements{argv[2]};
  const std::string kTypeOfAlgorithm{argv[3]};
  TestOrdenation<int>* test_ordenation = new TestOrdenation<int>;

  test_ordenation->SetN(std::stoi(kNumberOfElements)); ///< Primer elemento

  if (kWayToIntroduceElements == "-R") {
    srand(time(NULL));
    std::vector<int> aux(std::stoi(kNumberOfElements));

    for (int i{0}; i < std::stoi(kNumberOfElements); ++i)
      aux[i] = (rand() % 9000) + 1000;
    
    test_ordenation->SetVec(aux); ///< Segundo elemento

  } else if (kWayToIntroduceElements == "-C") {
    std::string user_number{""};
    std::vector<int> aux(std::stoi(kNumberOfElements));
    for (int i{0}; i < std::stoi(kNumberOfElements); ++i) {
      std::cout << "¿Valor del elemento " << (i + 1) << "º?: ";
      std::cin >> user_number;

      bool repeat{false};
      /// Comprobamos si es un string que puede ser pasado a int
      for (int j{0}; j < int(user_number.size()); ++j) {
        if ((j == 0) && (user_number[j] == '-')) continue;
        if (!(isdigit(user_number[j]) != 0)) {
          repeat = true;
          break;
        }
      }

      while (repeat) {
        std::cout << "Por favor intentelo de nuevo, introducza un numero entero: ";
        std::cin >> user_number;
        for (int j{0}; j < int(user_number.size()); ++j) {
          if ((j == 0) && (user_number[j] == '-')) continue;
          if (!(isdigit(user_number[j]) != 0)) {
            repeat = true;
            break;
          }
          if (j == (int(user_number.size()) - 1)) repeat = false;
        }
      }

      aux[i] = std::stoi(user_number);
    }

    test_ordenation->SetVec(aux); ///< Segundo elemento eligiendo el usuario
  }

  std::cout << "\nAlgoritmo a utilizar: ";
  if (kTypeOfAlgorithm == "-s") {
    test_ordenation->SetStrategy(new Selection<int>); ///< Tercer elemento
    std::cout << "Seleccion\n";
  } else if (kTypeOfAlgorithm == "-q") {
    test_ordenation->SetStrategy(new QuickSort<int>); ///< Tercer elemento
    std::cout << "QuickSort\n";
  } else if (kTypeOfAlgorithm == "-S") {
    test_ordenation->SetStrategy(new ShellSort<int>); ///< Tercer elemento
    std::cout << "ShellSort\n";
  } else if (kTypeOfAlgorithm == "-h") {
    test_ordenation->SetStrategy(new HeapSort<int>); ///< Tercer elemento
    std::cout << "HeapSort\n";
  } else if (kTypeOfAlgorithm == "-r") {
    test_ordenation->SetStrategy(new RadixSort<int>); ///< Tercer elemento
    std::cout << "RadixSort\n";
  }

  test_ordenation->Execute(); ///< Ejecutamos el algoritmo de ordenacion
  std::cout << "\n";

  test_ordenation->~TestOrdenation();
  test_ordenation = NULL;

  return 0;
}