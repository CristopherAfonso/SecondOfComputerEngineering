/**
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 6: Árbol binario equilibrado
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 01/05/2022
 * 
 * @file main_balanced_binary_tree.cc (programa cliente)
 * @brief Programa que nos permite usar una implementacion de un árbol binario
 * equilibrado y usus algoritmos, en este programa el término de árbol binario
 * equilibrado (ABE) es referido a un AB perfectamente equilibrado.
 * 
 * Si quiere saber mas detalles sobre como usar el programa ejecutable,
 * ejecute: ./balanced_binary_tree --help
 * para mas informacion.
 * 
 * @bug No hay bugs conocidos
 * 
 * Referencias:
 * @see
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 01/05/2022 - Creacion (primera version) del codigo:
 *              Solo he creado el archivo, le he puesto el comentario de
 *              cabecera y declarado los #include necesarios.
 * 08/05/2022 - Archivo terminado.
 */

#include "../include/main_functions.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  bool Dummy{true};
  if (!Dummy) {
  ///< paso 1 usar Key = int
  AB<int>* ab{nullptr}; ///< paso 2 crear un AB<Key> vacio
  ab = new ABE<int>;
  std::cout << "\nEste programa es una implementacion de un 'Arbol binario equilibrado'\n\n";
  /// paso 3 presentar un menu con las opciones:
  /// 0-salir, 1-insertar, 2-buscar, 3-eliminar, 4-mostrar arbol inorden
  std::string user_choice{""};
  while (true) {
    user_choice = "";
    std::cout << "Elija la operacion a usar sobre el arbol binario equilibrado:\n";
    std::cout << "[0] Salir\n";
    std::cout << "[1] Insertar Clave\n";
    std::cout << "[2] Buscar Clave\n";
    std::cout << "[3] Eliminar Clave\n";
    std::cout << "[4] Mostrar Arbol Inorden\n\n";
    std::cout << "¿Operacion a realizar? ";
    std::cin >> user_choice;
    std::cout << "\n";
    if ((user_choice != "0") && (user_choice != "1") && (user_choice != "2") && (user_choice  != "3") && (user_choice != "4")) {
      std::cout << "Error: no se reconoce la operacion que quiere usar, intentelo de nuevo\n\n";
    } else {
      if (user_choice == "0") break;
      if (user_choice == "4") {
        std::cout << "Recorrido Inorden: ";
        if (ab != nullptr) ab->InordenRoot();
        std::cout << "\n\n";
      }
      /// paso 4 para cada operacion 1, 2 o 3 se pide el valor clave y se realiza la operacion en el AB<Key>
      if ((user_choice == "1") || (user_choice == "2") || (user_choice == "3")) {
        std::string aux;
        std::cout << "¿Clave para la operacion? ";
        std::cin >> aux;
        /// paso 5 despues de cada operacion 1, se muestra el AB<Key> resultante mediante el recorrido por niveles con sobrecarga del operador
        if (user_choice == "1") {
          if ((ab != nullptr) && ab->Insert(std::stoi(aux))) {
            std::cout << ab;
          } else {
            std::cout << "No se pudo insertar el dato";
          }
          std::cout << "\n\n";
        }
        if (user_choice == "2") {
          if ((ab != nullptr) && ab->Search(std::stoi(aux))) {
            std::cout << "El dato si se encuentra en el arbol binario";
          } else {
            std::cout << "El dato no se encuentra en el arbol binario";
          }
          std::cout << "\n\n";
        }
        if (user_choice == "3") {
          if ((ab != nullptr) && ab->Delete(std::stoi(aux))) {
            std::cout << ab;
          } else {
            std::cout << "No se elimino ningun dato";
          }
          std::cout << "\n\n";
        }
      }
    }
  }
  if (ab != nullptr) {
    ab->~AB();
    ab = nullptr;
  }
  } else { ///< if (!Dummy)
    ABE<dummy> A;
    dummy d{3, ""};
    A->Insert(d);
    
    if (A->Search(d)) {
      std::cout << A << "\n\n";
      A[d].name = "X";
      std::cout << A << "\n";
    }

    if (A != nullptr) {
      A->~AB();
      A = nullptr;
    }
  }
    
  std::cout << "Fin del programa\n\n";
  
  return 0;
}
