/**
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 3: La Vida en la Frontera
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 21/03/2022
 * 
 * @file main_cycle_life.cc (programa cliente)
 * @brief Programa que simula el famoso "Juego de la Vida" de John Horton
 * Conway, creado en 1970, es un ejemplo de "Autómata Celular". Este programa
 * es una extensión del juego de la vida, representar solo los estados de
 * "viva" y "muerta". A parte de la rejilla o Grid tiene diferentes
 * implementaciones, cosa que antes no tenía.
 * 
 * Si quiere saber mas detalles sobre como usar el programa ejecutable,
 * ejecute: ./main_game_life --help
 * para mas informacion.
 * 
 * @bug No hay bugs conocidos
 * 
 * Referencias:
 * @see
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 21/03/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 * 22/03/22 - Proyecto terminado.
 */

#include "main_functions.h"

  using std::cout;
  using std::cerr;
  using std::cin;

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::string kKindOfGrid{argv[1]};
  std::string kRows{argv[2]};
  std::string kCols{argv[3]};
  std::string kGameTurns{argv[4]};

  Grid* grid{NULL};

  if (kKindOfGrid == "-p") grid = new GridWithPeriodicBorder(std::stoi(kRows), std::stoi(kCols));
  if (kKindOfGrid == "-o") grid = new GridWithOpenBorder(std::stoi(kRows), std::stoi(kCols));
  if (kKindOfGrid == "-r") grid = new GridWithReflectiveBorder(std::stoi(kRows), std::stoi(kCols));
  if (kKindOfGrid == "-n") grid = new GridWithOpenBorder(std::stoi(kRows), std::stoi(kCols));

  cout << "En la rejilla hay " << (grid->GetRows())*(grid->GetCols()) << " celulas,";
  cout << " la rejilla tiene " << (grid->GetRows()) << " filas y " << (grid->GetCols());
  cout << " columnas,\nahora mismo todas están muertas, indique ahora ";
  cout << "cuantas de esas\ncelulas quiere que comiencen en estado viva, ";
  cout << "en el turno 0: ";

  int cell_not_dies{0};
  cin >> cell_not_dies;
  cout << '\n';

  while ((cell_not_dies < 0) || (cell_not_dies > ((grid->GetRows())*(grid->GetCols())))) {
    cerr << "Warning!, el numero de celulas elegido está fuera del rango\n";
    cerr << "aceptable, intentelo de nuevo: ";
    cin >> cell_not_dies;
    cerr << "\n";
  }

  if (cell_not_dies != 0) {
    if (cell_not_dies <= ((grid->GetRows())*(grid->GetCols()))) {
      std::pair<int, int> aux_position{0, 0};
      Cell aux_cell;
      cout << "Debe introducir las coordenadas X e Y para cada celula a la\n";
      cout << "que le quiera definir su estado y en ese orden, primero la\n";
      cout << "coordenada X y luego la Y separadas por uno o varios espacios,\n";
      cout << "tras indicar unas coordenadas correctas, debe introducir uno\n";
      cout << "de los siguientes carácteres para indicar el estado que\n";
      cout << "quiere que se establezca en la posición indicada, y esos\n";
      cout << "carácteres son: X->Viva\n\n";

      for (int i{1}; i <= cell_not_dies; ++i) {
        cout << "¿Posicion de la " << i << "º Celula a definir su estado? ";
        cin >> aux_position.first;
        cin >> aux_position.second;

        while (true) {
          if (aux_position.first > 0 && aux_position.first < (grid->GetRows() + 1) &&
              aux_position.second > 0 && aux_position.second < (grid->GetCols() + 1)) {
            if (grid->GetCell(aux_position.first, aux_position.second).GetState() == ' ') {
              break;
            }
          }
          cerr << "\nLa posición de la celula está fuera de los limites de la\n";
          cerr << "rejilla, o se ha indicado una celula que no esta en estado\n";
          cerr << "muerta, intentelo de nuevo.\n";
          cout << "¿Posicion de la " << i << "º Celula a definir su estado? ";
          cin >> aux_position.first;
          cin >> aux_position.second;
        }

        cout << "\n¿Estado de la célula? (Opciones: 'X'): ";
        char aux_state{' '};
        cin >> aux_state;
        cout << '\n';

        while (aux_state != 'X') {
          cerr << "Warning!, el estado de la célula elegido no corresponde\n";
          cerr << "con los aceptables, intentelo de nuevo: ";
          cin >> aux_state;
          cerr << "\n";
        }

        aux_cell.SetState(aux_state);

        grid->SetCell(aux_position.first, aux_position.second, aux_cell);
      }
    }
  } else {
    cout << "Todas las celulas comenzaran muertas en el turno 0\n\n";
  }

  grid->LifeBorder(std::stoi(kGameTurns));

  return 0;
}
