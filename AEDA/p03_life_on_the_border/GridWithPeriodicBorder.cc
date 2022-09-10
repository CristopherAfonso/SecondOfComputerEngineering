/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenierıa y Tecnologıa (ESIT)
 * Grado en Ingenierıa Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 3: La Vida en la Frontera
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 21/03/2022
 * 
 * @file GridWithPeriodicBorder.cc
 * @brief Donde se desarrollan las funciones de la clase GridWithPeriodicBorder
 * contenida en el archivo de cabecera GridWithPeriodicBorder.h
 *
 * @bug En el metodo LifeBorder, cuando te piden las posiciones de las celulas
 * si introduces caracteres en vez de numeros, entra en bucle infinito, pasa lo
 * mismo si introduces numeros con decimales.
 * 
 * Referencias: Enlaces de Interes
 * @see
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 21/03/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 * 22/03/22 - Funciones de la clase terminadas.
 */

#include "GridWithPeriodicBorder.h"

/**
 * @brief Constructor por defecto, crear un objeto GridWithPeriodicBorder de
 * tamaño 10x10 visible al usuario.
 */
GridWithPeriodicBorder::GridWithPeriodicBorder(void)
    : grid_with_periodic_border_(NULL), rows_(2), cols_(2) {
  grid_with_periodic_border_ = new Cell*[rows_];
  Cell aux;
  for (int i{0}; i < rows_; ++i) {
    grid_with_periodic_border_[i] = new Cell[cols_];
    for (int j{0}; j < cols_; ++j) {
      aux.SetPos(i, j);
      grid_with_periodic_border_[i][j] = aux;
    }
  }
}

/**
 * @brief Constructor predeterminado, crea un objeto GridWithPeriodicBorder
 * donde kRows es el numero de filas y kCols es el numero de columnas,
 * tanto kRows como kCols deben ser 1, o mayores a 1, sino el objeto estará
 * vacio.
 * 
 * @param kRows Numero de filas de la rejilla
 * @param kCols Numero de columnas de la rejilla
 */
GridWithPeriodicBorder::GridWithPeriodicBorder(const int& kRows, const int& kCols)
  : grid_with_periodic_border_(NULL), rows_(2), cols_(2) {
  if (kRows > 0) rows_ = kRows + 2;
  if (kCols > 0) cols_ = kCols + 2;
  grid_with_periodic_border_ = new Cell*[rows_];
  Cell aux;
  for (int i{0}; i < rows_; ++i) {
    grid_with_periodic_border_[i] = new Cell[cols_];
    for (int j{0}; j < cols_; ++j) {
      aux.SetPos(i, j);
      grid_with_periodic_border_[i][j] = aux;
    }
  }
}

/**
 * @brief Constructor de copia, crea un nuevo objeto copiando el que se le pasa
 * 
 * @param grid Objeto tipo GridWithPeriodicBorder que nuestro nuevo objeto
 * GridWithPeriodicBorder copiara.
 */
GridWithPeriodicBorder::GridWithPeriodicBorder(const GridWithPeriodicBorder& grid_with_periodic_border)
  : grid_with_periodic_border_(NULL), rows_(2), cols_(2) {
  grid_with_periodic_border_ = new Cell*[rows_];
  Cell aux;
  for (int i{0}; i < rows_; ++i) {
    grid_with_periodic_border_[i] = new Cell[cols_];
    for (int j{0}; j < cols_; ++j) {
      aux.SetPos(i, j);
      grid_with_periodic_border_[i][j] = aux;
    }
  }
  *this = grid_with_periodic_border;
}

/**
 * @brief Destructor de la clase GridWithPeriodicBorder, cada objeto
 * GridWithPeriodicBorder debe eliminar su memoria dinamica antes de
 * terminar el programa, eso hace este metodo.
 */
GridWithPeriodicBorder::~GridWithPeriodicBorder(void) {
  for (int i{0}; i < rows_; ++i) delete[] grid_with_periodic_border_[i];
  delete[] grid_with_periodic_border_;
  grid_with_periodic_border_ = NULL;
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
void GridWithPeriodicBorder::SetCell(const int& posx, const int& posy, const Cell& cell) {
  if ((posx > 0) && (posy > 0) && (posx < (rows_ - 1)) && 
      (posy < (cols_ - 1))) {
    grid_with_periodic_border_[posx][posy] = cell;
    grid_with_periodic_border_[posx][posy].SetPos(posx, posy);
  } else {
    int aux_rows{0};
    int aux_cols{0};
    if (posx >= rows_) aux_rows = posx % rows_;
    if (posy >= cols_) aux_cols = posy % cols_;
    if (posx < 0) aux_rows = (posx % rows_) + rows_;
    if (posy < 0) aux_cols = (posy % cols_) + cols_;
    grid_with_periodic_border_[aux_rows][aux_cols] = cell;
    grid_with_periodic_border_[aux_rows][aux_cols].SetPos(aux_rows, aux_cols);
  }
}

/**
 * @brief Añade un nuevo objeto Cell a la posicion indicada en el atributo
 * privado position_ del objeto cell que va a ser añadido al objeto rejilla, si la
 * posicion cae fuera de las dimensiones de la rejilla, directamente no la añade
 * y no avisa de si ha sido o no ha sido añadida correctamente.
 * 
 * @param cell objeto tipo Cell que sera añadido al objeto Grid en la posicion
 * que indique la propia celula ya.
 */
void GridWithPeriodicBorder::SetCell(const Cell& cell) {
  if ((cell.GetPosition().first > 0) && (cell.GetPosition().second > 0) &&
      (cell.GetPosition().first < (rows_ - 1)) && 
      (cell.GetPosition().second < (cols_ - 1))) {
    grid_with_periodic_border_[cell.GetPosition().first][cell.GetPosition().second] = cell;
  } else {
    int aux_rows{0};
    int aux_cols{0};
    if (cell.GetPosition().first >= rows_) aux_rows = cell.GetPosition().first % rows_;
    if (cell.GetPosition().second >= cols_) aux_cols = cell.GetPosition().second % cols_;
    if (cell.GetPosition().first < 0) aux_rows = (cell.GetPosition().first % rows_) + rows_;
    if (cell.GetPosition().second < 0) aux_cols = (cell.GetPosition().second % cols_) + cols_;
    grid_with_periodic_border_[aux_rows][aux_cols] = cell;
    grid_with_periodic_border_[aux_rows][aux_cols].SetPos(aux_rows, aux_cols);
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
Cell& GridWithPeriodicBorder::GetCell(const int& posx, const int& posy) {
  if ((posx > 0) && (posy > 0) && (posx < (rows_ - 1)) && 
      (posy < (cols_ - 1))) {
    return grid_with_periodic_border_[posx][posy];
  } else {
    int aux_rows{0};
    int aux_cols{0};
    if (posx >= rows_) aux_rows = posx % rows_;
    if (posy >= cols_) aux_cols = posy % cols_;
    if (posx < 0) aux_rows = (posx % rows_) + rows_;
    if (posy < 0) aux_cols = (posy % cols_) + cols_;
    return grid_with_periodic_border_[aux_rows][aux_cols];
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
const Cell& GridWithPeriodicBorder::GetCell(const int& posx, const int& posy) const {
  if ((posx > 0) && (posy > 0) &&
      (posx < (rows_ - 1)) && 
      (posy < (cols_ - 1))) {
    return grid_with_periodic_border_[posx][posy];
  } else {
    int aux_rows{0};
    int aux_cols{0};
    if (posx >= rows_) aux_rows = posx % rows_;
    if (posy >= cols_) aux_cols = posy % cols_;
    if (posx < 0) aux_rows = (posx % rows_) + rows_;
    if (posy < 0) aux_cols = (posy % cols_) + cols_;
    return grid_with_periodic_border_[aux_rows][aux_cols];
  }
}

/**
 * @brief Metodo que devuelve el numero de filas que tiene la rejilla.
 * 
 * @return int Numero de filas que tiene la rejilla (rejillas usables).
 */
int GridWithPeriodicBorder::GetRows(void) const {return rows_ - 2;}

/**
 * @brief Metodo que devuelve el numero de columnas que tiene la rejilla.
 * 
 * @return int Numero de columnas que tiene la rejilla (rejillas usables).
 */
int GridWithPeriodicBorder::GetCols(void) const {return cols_ - 2;}

/**
 * @brief Metodo que implementa El Juego de la Vida, aquí está desarrollado
 * todo lo que debe ocurrir en el juego.
 * 
 * @param kGameTurns Parametro que indica cuantas veces se va a actulizar toda
 * la rejilla (cuantos turnos van a pasar y como se va a desarrollar el juego)
 * segun los estados de las celulas.
 */
void GridWithPeriodicBorder::LifeBorder(const int& kGameTurns) {
  std::cout << "\nTurno 0\n";
  std::cout << *this;
  for (int i{1}; i < kGameTurns; ++i) {
    std::cout << "Turno " << i << "\n";
    this->NextGeneration();
    std::cout << *this;
  }

  std::cout << "Fin del Juego\n\n";
}

/**
 * @brief Sobrecarga del operador = en la clase GridWithPeriodicBorder.
 * 
 * @param grid Objeto a copiar dentro del objeto que invoca el metodo.
 * @return Grid& Objeto que invoca el metodo pero ya siendo modificado.
 */
const GridWithPeriodicBorder& GridWithPeriodicBorder::operator=(const GridWithPeriodicBorder& grid_with_periodic_border) {
  for (int i{0}; i < rows_; ++i) {
    delete[] this->grid_with_periodic_border_[i];
  }
  delete[] this->grid_with_periodic_border_;
  grid_with_periodic_border_ = NULL;

  grid_with_periodic_border_ = new Cell*[grid_with_periodic_border.GetRows() + 2];
  for (int i{0}; i < (grid_with_periodic_border.GetRows() + 2); ++i) {
    grid_with_periodic_border_[i] = new Cell[grid_with_periodic_border.GetCols() + 2];
  }
  this->rows_ = grid_with_periodic_border.GetRows() + 2;
  this->cols_ = grid_with_periodic_border.GetCols() + 2;

  Cell aux_var;
  for (int i{0}; i < rows_; ++i) {
    Cell aux_var_cell;
    for (int j{0}; j < cols_; ++j) {
      if ((i == (rows_ - 1)) || (j == (cols_ - 1))) {
        aux_var = aux_var_cell;
      } else {
        aux_var = grid_with_periodic_border.grid_with_periodic_border_[i][j];
      }
      aux_var.SetPos(i, j);
      grid_with_periodic_border_[i][j] = aux_var;
    }
  }

  return *this;
}

/**
 * @brief Sobrecarga del operador << de la clase GridWithPeriodicBorder. Nos 
 * permite mostrar la matriz por pantalla.
 * 
 * @param out variable a la que hay que redireccionar los datos para que salgan
 * en la pantalla, generalmente es std::cout, pero dentro de la funcion lleva
 * el nombre que quieras.
 * @param grid_with_periodic_border Objeto tipo rejilla que va a ser mostrado.
 * @return std::ostream& retorno de los todos caracteres que se quieren mostrar
 * por pantalla.
 */
std::ostream& operator<<(std::ostream& out, const GridWithPeriodicBorder& grid_with_periodic_border) {
  for (int i{0}; i < grid_with_periodic_border.rows_; ++i) {
    for (int j{0}; j < grid_with_periodic_border.cols_; ++j) {
      if (i == 0 || i == (grid_with_periodic_border.rows_ - 1)) {
        out << "·";
        for (int k{1}; k < (grid_with_periodic_border.rows_ - 1); ++k) out << '-';
        out << "·\n";
        break;
      }

      if (j == 0) {
        out << '|';
        continue;
      }

      if (j == (grid_with_periodic_border.cols_ - 1)) {
        out << "|\n";
        continue;
      }

      out << grid_with_periodic_border.GetCell(i, j);
    }
  }
  out << '\n';
  return out;
}
