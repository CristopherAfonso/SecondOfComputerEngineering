/**
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 7: Árbol binario de busqueda
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 15/05/2022
 * 
 * @file main_binary_search_tree.cc (programa cliente)
 * @brief Programa que nos permite usar una implementacion de un árbol binario
 * equilibrado, de busqueda y usus algoritmos, en este programa el término de
 * árbol binario equilibrado (ABE) es referido a un AB perfectamente
 * equilibrado.
 * 
 * Si quiere saber mas detalles sobre como usar el programa ejecutable,
 * ejecute: ./binary_search_tree --help
 * para mas informacion.
 * 
 * @bug No hay bugs conocidos
 * 
 * Referencias:
 * @see
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 15/05/2022 - Creacion (primera version) del codigo:
 *              Solo he creado el archivo, le he puesto el comentario de
 *              cabecera y declarado los #include necesarios.
 * 17/05/2022 - Archivo terminado.
 */

#include "../include/main_functions.h"
#include "../include/Dummy.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  using std::cout; ///< nos permite usar std::cout de una buena forma
  using std::cin; ///< nos permite usar std::cin de una buena forma
  std::string user_choice{""};
  typedef int data; ///< paso 1 usar Key = int
  cout << "\nEste programa es una implementacion de un 'Arbol binario'";
  cout << "\nElija la implementacion concreta del arbol:";
  cout << "\n[1] Arbol binario equilibrado";
  cout << "\n[2] Arbol binario de busqueda\n";
  cout << "\n¿Su eleccion? ";
  cin >> user_choice;
  if (user_choice != "1" && user_choice != "2") {
    while (true) {
      user_choice = "";
      cout << "\nError, clave incorrecta, intentelo de nuevo";
      cout << "\n¿Su elección? ";
      cin >> user_choice;
      if (user_choice == "1" || user_choice == "2") break;
    }
  }
  cout << "\n";
  AB<data>* ab{nullptr}; ///< paso 2 crear un AB<Key> vacio
  if (user_choice == "1") ab = new ABE<data>;
  if (user_choice == "2") ab = new ABB<data>;
  /// paso 4 presentar un menu con las opciones:
  /// 0-salir, 1-insertar, 2-buscar, 3-eliminar, 4-mostrar arbol inorden
  while (true) {
    user_choice = "";
    cout << "Elija la operacion a usar sobre el arbol binario seleccionado:\n";
    cout << "[0] Salir\n";
    cout << "[1] Insertar Clave\n";
    cout << "[2] Buscar Clave\n";
    cout << "[3] Eliminar Clave\n";
    cout << "[4] Mostrar Arbol Inorden\n\n";
    cout << "¿Operacion a realizar? ";
    cin >> user_choice;
    cout << "\n";
    if ((user_choice != "0") && (user_choice != "1") && (user_choice != "2") && (user_choice  != "3") && (user_choice != "4")) {
      cout << "Error: no se reconoce la operacion que quiere usar, intentelo de nuevo\n\n";
    } else {
      if (user_choice == "0") break;
      if (user_choice == "4") {
        cout << "Recorrido Inorden: ";
        if (ab != nullptr) ab->InordenRoot();
        cout << "\n\n";
      }
      /// paso 5 para cada operacion 1, 2 o 3 se pide el valor clave y se realiza la operacion en el AB<Key>
      if ((user_choice == "1") || (user_choice == "2") || (user_choice == "3")) {
        std::string aux;
        cout << "¿Clave para la operacion? ";
        cin >> aux;
        /// paso 6 despues de cada operacion 1, se muestra el AB<Key> resultante mediante el recorrido por niveles con sobrecarga del operador
        if (user_choice == "1") {
          if ((ab != nullptr) && ab->Insert(std::stoi(aux))) {
            cout << ab;
          } else {
            cout << "No se pudo insertar el dato";
          }
          cout << "\n\n";
        }
        if (user_choice == "2") {
          if ((ab != nullptr) && ab->Search(std::stoi(aux))) {
            cout << "El dato si se encuentra en el arbol binario";
          } else {
            cout << "El dato no se encuentra en el arbol binario";
          }
          cout << "\n\n";
        }
        if (user_choice == "3") {
          if ((ab != nullptr) && ab->Delete(std::stoi(aux))) {
            cout << ab;
          } else {
            cout << "No se elimino ningun dato";
          }
          cout << "\n\n";
        }
      }
    }
  }
  if (ab != nullptr) {
    ab->~AB();
    ab = nullptr;
  }
  cout << "Fin del programa\n\n";
  return 0;
}
