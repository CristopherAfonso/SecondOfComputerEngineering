/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenierıa y Tecnologıa (ESIT)
 * Grado en Ingenierıa Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 2: El Ciclo de la Vida
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 13/03/2022
 * 
 * @file Grid.cc
 * @brief Donde se desarrollan las funciones de la clase Grid contenida
 * en el archivo de cabecera Grid.h
 *
 * @bug En el metodo GameLife, cuando te piden las posiciones de las celulas
 * si introduces caracteres en vez de numeros, entra en bucle infinito, pasa lo
 * mismo si introduces numeros con decimales.
 * 
 * Referencias: Enlaces de Interes
 * @see
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 13/03/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 * 15/03/22 - Funciones de la clase terminadas.
 */

#include "Grid.h"

/**
 * @brief Constructor por defecto, crear un objeto Grid de tamaño 10x10 visible
 * al usuario.
 */
Grid::Grid(void) : grid_(NULL), rows_(2), cols_(2) {
  grid_ = new Cell*[rows_];
  Cell aux;
  for (int i{0}; i < rows_; ++i) {
    grid_[i] = new Cell[cols_];
    for (int j{0}; j < cols_; ++j) {
      aux.SetPos(i, j);
      grid_[i][j] = aux;
    }
  }
}

/**
 * @brief Constructor predeterminado, crea un objeto Grid donde kRows es el
 * numero de filas y kCols es el numero de columnas, tanto kRows como kCols
 * deben ser 1, o mayores a 1, sino el objeto estará vacio
 * 
 * @param kRows Numero de filas de la rejilla
 * @param kCols Numero de columnas de la rejilla
 */
Grid::Grid(const int& kRows, const int& kCols) 
    : grid_(NULL), rows_(2), cols_(2) {
  if (kRows > 0) rows_ = kRows + 2;
  if (kCols > 0) cols_ = kCols + 2;
  grid_ = new Cell*[rows_];
  Cell aux;
  for (int i{0}; i < rows_; ++i) {
    grid_[i] = new Cell[cols_];
    for (int j{0}; j < cols_; ++j) {
      aux.SetPos(i, j);
      grid_[i][j] = aux;
    }
  }
}

/**
 * @brief Constructor de copia, crea un nuevo objeto copiando el que se le pasa
 * 
 * @param grid Objeto tipo Grid que nuestro nuevo objeto Grid copiara.
 */
Grid::Grid(const Grid& grid) : grid_(NULL), rows_(2), cols_(2) {
  grid_ = new Cell*[rows_];
  Cell aux;
  for (int i{0}; i < rows_; ++i) {
    grid_[i] = new Cell[cols_];
    for (int j{0}; j < cols_; ++j) {
      aux.SetPos(i, j);
      grid_[i][j] = aux;
    }
  }
  *this = grid;
}

/**
 * @brief Destructor de la clase Grid, cada objeto Grid debe eliminar su
 * memoria dinamica antes de terminar el programa, eso hace este metodo
 */
Grid::~Grid(void) {
  for (int i{0}; i < rows_; ++i) delete[] grid_[i];
  delete[] grid_;
  grid_ = NULL;
}

/**
 * @brief Añade un nuevo objeto Cell a la posición en la rejilla indicada por
 * posx, y; posy, si la posicion cae fuera de las dimensiones de la rejilla,
 * directamente no la añade y no avisa de si ha sido o no ha sido añadida
 * correctamente.
 * 
 * @param posx Posición en el eje 'X' donde será añadida la celula
 * @param posy Posición en el eje 'Y' donde será añadida la celula
 * @param cell Celula que se añadirá a la rejilla
 */
void Grid::SetCell(const int& posx, const int& posy, const Cell& cell) {
  if ((posx > 0) && (posy > 0) && (posx < (rows_ - 1)) && 
      (posy < (cols_ - 1))) {
    grid_[posx][posy] = cell;
    grid_[posx][posy].SetPos(posx, posy);
  }
}

/**
 * @brief Añade un nuevo objeto Cell a la posición en la rejilla indicada por
 * position, position.first es la posicion de la celula en el eje 'X', y
 * position.second en el eje 'Y', si la posicion cae fuera de las dimensiones
 * de la rejilla, directamente no la añade y no avisa de si ha sido o no ha 
 * sido añadida correctamente.
 * 
 * @param position objeto std::pair<int, int> el cual en su primer elemento,
 * contiene la position en el eje 'X' de la celula y en el segundo la
 * posicion en el eje 'Y'. 
 * @param cell Es el objeto que va a ser añadido
 */
void Grid::SetCell(const std::pair<int, int> position, const Cell& cell) {
  if ((position.first > 0) && (position.second > 0) && 
      (position.first < (rows_ - 1)) && (position.second < (cols_ - 1))) {
    grid_[position.first][position.second] = cell;
    grid_[position.first][position.second].SetPos(position.first, position.second);
  }
}

/**
 * @brief Añade un nuevo objeto Cell a la posicion indicada en el atributo
 * privado position_ del objeto cell que va a ser añadido al objeto Grid, si la
 * posicion cae fuera de las dimensiones de la rejilla, directamente no la añade
 * y no avisa de si ha sido o no ha sido añadida correctamente.
 * 
 * @param cell objeto tipo Cell que sera añadido al objeto Grid en la posicion
 * que indique la propia celula ya.
 */
void Grid::SetCell(const Cell& cell) {
  if ((cell.GetPosition().first > 0) && (cell.GetPosition().second > 0) &&
      (cell.GetPosition().first < (rows_ - 1)) && 
      (cell.GetPosition().second < (cols_ - 1))) {
    grid_[cell.GetPosition().first][cell.GetPosition().second] = cell;
  }
}

/**
 * @brief Metodo que recibe una coordenada en el eje 'X' y otra en el eje 'Y'
 * y si estas coordenadas señalan una posicion valida dentro de la rejilla (una
 * posicion positiva y menor al limite en cada eje de coordenadas), devuelve la
 * celula que en esa posicion se halla, sino, devuelve una celula en estado
 * muerta y con posición en el eje 'X' = -1, y en el eje 'Y' = -1.
 * 
 * @param posx Posición en eje 'X' donde está la celula que queremos retornar.
 * @param posy Posición en eje 'Y' donde está la celula que queremos retornar.
 * @return Cell objeto celula que tiene como coordenadas 'posx' en el eje 'X' y
 * 'posy' en el eje 'Y'.
 */
Cell Grid::GetCell(const int& posx, const int& posy) const {
  if ((posx > 0) && (posy > 0) && (posx < (rows_ - 1)) && 
      (posy < (cols_ - 1))) {
    return grid_[posx][posy];
  } else {
    Cell aux;
    return aux;
  }
}

/**
 * @brief Metodo que recibe una coordenada en el eje 'X' y otra en el eje 'Y'
 * codificadas en un argumento std::pair<int, int> (coordenada 'X' es la
 * primera y la segunda es la 'Y'). Si estas coordenadas señalan una posicion
 * valida dentro de la rejilla (una posicion positiva y menor al limite en cada
 * eje de coordenadas), devuelve la celula que en esa posicion se halla, sino,
 * devuelve una celula en estado muerta y con posición en el eje 'X' = -1, y en
 * el eje 'Y' = -1.
 * 
 * @param position Variable que contiene la coordenada 'X' en el atributo
 * .first y la 'Y' en el atributo .second
 * @return Cell Objeto celula que tiene como coordenadas los valores de
 * position.
 */
const Cell Grid::GetCell(const std::pair<int, int> position) const {
  if ((position.first > 0) && (position.second > 0) &&
      (position.first < (rows_ - 1)) && 
      (position.second < (cols_ - 1))) {
    return grid_[position.first][position.second];
  } else {
    Cell aux;
    return aux;
  }
}

/**
 * @brief Metodo que devuelve el numero de filas que tiene la rejilla.
 * 
 * @return int Numero de filas que tiene la rejilla (rejillas usables).
 */
int Grid::GetRows(void) const {return rows_ - 2;}

/**
 * @brief Metodo que devuelve el numero de columnas que tiene la rejilla.
 * 
 * @return int Numero de columnas que tiene la rejilla (rejillas usables).
 */
int Grid::GetCols(void) const {return cols_ - 2;}

/**
 * @brief Metodo que implementa El Juego de la Vida, aquí está desarrollado
 * todo lo que debe ocurrir en el juego.
 * 
 * @param kGameTurns Parametro que indica cuantas veces se va a actulizar toda
 * la rejilla (cuantos turnos van a pasar y como se va a desarrollar el juego)
 * segun los estados de las celulas.
 */
void Grid::CycleLife(const int& kGameTurns) {
  using std::cout;
  using std::cerr;
  using std::cin;
  cout << "En la rejilla hay " << (rows_ - 2)*(cols_ - 2) << " celulas,";
  cout << " la rejilla tiene " << (rows_ - 2) << " filas y " << (cols_ - 2);
  cout << " columnas,\nahora mismo todas están muertas, indique ahora ";
  cout << "cuantas de esas\ncelulas quiere que comiencen en estado huevo, ";
  cout << "larva, pupa o adulta\nen el turno 0: ";

  int cell_not_dies{0};
  cin >> cell_not_dies;
  cout << '\n';

  while ((cell_not_dies < 0) || (cell_not_dies > ((rows_ - 2)*(cols_ - 2)))) {
    cerr << "Warning!, el numero de celulas elegido está fuera del rango\n";
    cerr << "aceptable, intentelo de nuevo: ";
    cin >> cell_not_dies;
    cerr << "\n";
  }

  if (cell_not_dies != 0) {
    if (cell_not_dies <= ((rows_ - 2)*(cols_ - 2))) {
      std::pair<int, int> aux_position{0, 0};
      Cell aux_cell;
      cout << "Debe introducir las coordenadas X e Y para cada celula a la\n";
      cout << "que le quiera definir su estado y en ese orden, primero la\n";
      cout << "coordenada X y luego la Y separadas por uno o varios espacios,\n";
      cout << "tras indicar unas coordenadas correctas, debe introducir uno\n";
      cout << "de los siguientes carácteres para indicar el estado que\n";
      cout << "quiere que se establezca en la posición indicada, y esos\n";
      cout << "carácteres son: A->Adulta, P->Pupa, L->Larva, H->Huevo\n\n";

      for (int i{1}; i <= cell_not_dies; ++i) {
        cout << "¿Posicion de la " << i << "º Celula a definir su estado? ";
        cin >> aux_position.first;
        cin >> aux_position.second;

        while (true) {
          if (aux_position.first > 0 && aux_position.first < (rows_ - 1) &&
              aux_position.second > 0 && aux_position.second < (cols_ - 1)) {
            if (this->GetCell(aux_position.first, aux_position.second).GetState() == ' ') {
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

        cout << "\n¿Estado de la célula? (Opciones: 'A', 'P', 'L', 'H'): ";
        char aux_state{' '};
        cin >> aux_state;
        cout << '\n';

        while (aux_state != 'A' && aux_state != 'P' && aux_state != 'L' && aux_state != 'H') {
          cerr << "Warning!, el estado de la célula elegido no corresponde\n";
          cerr << "con los aceptables, intentelo de nuevo: ";
          cin >> aux_state;
          cerr << "\n";
        }

        aux_cell.SetState(aux_state);

        this->SetCell(aux_position, aux_cell);
      }
    }
  } else {
    cout << "Todas las celulas comenzaran muertas en el turno 0\n\n";
  }

  cout << "\nTurno 0\n";
  cout << *this;
  for (int i{1}; i < kGameTurns; ++i) {
    cout << "Turno " << i << "\n";
    this->NextGeneration();
    cout << *this;
  }

  cout << "Fin del Juego\n\n";
}

/**
 * @brief Metodo que actualiza todas las celulas que hay en la rejilla del
 * estado 't' al estado 't + 1' segun las normas de transicion de estados
 * definida en el metodo "UpdateState" de la clase 'Cell'
 */
void Grid::NextGeneration(void) {
  for (int i{1}; i < (rows_ - 1); ++i) {
    for (int j{1}; j < (cols_ - 1); ++j) {
      grid_[i][j].Neighbors(*this);
    }
  }
 
  for (int i{1}; i < (rows_ - 1); ++i) {
    for (int j{1}; j < (cols_ - 1); ++j) {
      grid_[i][j].UpdateState();
    }
  }
}

/**
 * @brief Sobrecarga del operador = en la clase Grid.
 * 
 * @param grid Objeto a copiar dentro del objeto que invoca el metodo.
 * @return Grid& Objeto que invoca el metodo pero ya siendo modificado.
 */
const Grid& Grid::operator=(const Grid& grid) {
  for (int i{0}; i < rows_; ++i) {
    delete[] this->grid_[i];
  }
  delete[] this->grid_;
  grid_ = NULL;

  grid_ = new Cell*[grid.GetRows() + 2];
  for (int i{0}; i < (grid.GetRows() + 2); ++i) {
    grid_[i] = new Cell[grid.GetCols() + 2];
  }
  this->rows_ = grid.GetRows() + 2;
  this->cols_ = grid.GetCols() + 2;

  Cell aux_var;
  for (int i{0}; i < rows_; ++i) {
    Cell aux_var_cell;
    for (int j{0}; j < cols_; ++j) {
      if ((i == (rows_ - 1)) || (j == (cols_ - 1))) {
        aux_var = aux_var_cell;
      } else {
        aux_var = grid.grid_[i][j];
      }
      aux_var.SetPos(i, j);
      grid_[i][j] = aux_var;
    }
  }

  return *this;
}

/**
 * @brief Sobrecarga del operador << de la clase Grid. Nos permite mostrar la
 * matriz por pantalla.
 * 
 * @param out variable a la que hay que redireccionar los datos para que salgan
 * en la pantalla, generalmente es std::cout, pero dentro de la funcion lleva
 * el nombre que quieras.
 * @param grid Objeto tipo rejilla que va a ser mostrado.
 * @return std::ostream& retorno de los todos caracteres que se quieren mostrar
 * por pantalla.
 */
std::ostream& operator<<(std::ostream& out, const Grid& grid) {
  for (int i{0}; i < grid.rows_; ++i) {
    for (int j{0}; j < grid.cols_; ++j) {
      if (i == 0 || i == (grid.rows_ - 1)) {
        out << "·";
        for (int k{1}; k < (grid.rows_ - 1); ++k) out << '-';
        out << "·\n";
        break;
      }

      if (j == 0) {
        out << '|';
        continue;
      }

      if (j == (grid.cols_ - 1)) {
        out << "|\n";
        continue;
      }

      out << grid.GetCell(i, j);
    }
  }
  out << '\n';
  return out;
}

