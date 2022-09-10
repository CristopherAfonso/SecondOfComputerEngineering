/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenierıa y Tecnologıa (ESIT)
 * Grado en Ingenierıa Informatica
 * Asignatura: Algorítmos y Estructuras de Datos Avanzados
 * Curso: 2º
 * Practica 1: El Juego de la Vida
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 05/03/2022
 * 
 * @file Cell.cc
 * @brief Donde se desarrollan las funciones de la clase Cell contenida
 * en el archivo de cabecera Cell.h
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 05/03/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 * 06/03/22 - Funciones de la clase terminadas.
 */

#include "Cell.h"
#include "Grid.h"

/**
 * @brief Constructor por defecto definido. 
 */
Cell::Cell(void) : state_(0), position_({-1, -1}), neighbors_alive_(0) {}

/**
 * @brief Constructor basico, que define el estado, pero no la posicion.
 * 
 * @param state estado de la celula.
 */
Cell::Cell(const State& state) 
    : state_(state), position_({-1, -1}), neighbors_alive_(0) {}

/**
 * @brief Constructor basico que define el estado y la posicion de la celula
 * en la Rejilla, este lo hace usando directamente un dato de tipo
 * std::pair<int, int>.
 * 
 * @param state Estado de la celula.
 * @param position Posicion en 2D de la celula en la Rejilla.
 */
Cell::Cell(const State& state, const std::pair<int, int>& position) 
    : state_(state), position_(position), neighbors_alive_(0) {}

/**
 * @brief Constructor basico que define el estado y la posicion de la celula
 * en la Rejilla, este lo hace cogiendo dos numeros que serán sus posiciones
 * en los ejes 'X' e 'Y'.
 * 
 * @param state Estado de la celula.
 * @param posx Posición en el eje 'X'
 * @param posy Posición en el eje 'Y'
 */
Cell::Cell(const State& state, const int& posx, const int& posy)
    : state_(state), position_({posx, posy}), neighbors_alive_(0) {}

/**
 * @brief Constructor de copia de la celula, el constructor llama al operador =
 * de la clase para crear el nuevo objeto Cell.
 * 
 * @param cell Objeto tipo Cell el cual, el neuvo objeto que va a ser creado
 * copiará.
 */
Cell::Cell(const Cell& cell) {
  *this = cell;
}

/**
 * @brief Funcion que cambia el atributo interno de la celula llamado 'state_'
 * por el dado al método (State es un int).
 * 
 * @param state Dato de tipo int que sustituirá al state_ de la celula.
 */
void Cell::SetState(const State& state) {state_ = state;}

/**
 * @brief Función que solo modifica la posición en el eje 'X' de la celula.
 * 
 * @param posx Posición nueva en el eje 'X' solo donde nuestra celula estara.
 */
void Cell::SetPosX(const int& posx) {position_.first = posx;}

/**
 * @brief Función que solo modifica la posición en el eje 'Y' de la celula.
 * 
 * @param posy Posición nueva en el eje 'Y' solo donde nuestra celula estara.
 */
void Cell::SetPosY(const int& posy) {position_.second = posy;}

/**
 * @brief Función que modifica la posición en el eje 'X' y 'Y' de nuestra
 * celula. La posición está contenida en un dato de tipo std::pair<int, int>,
 * donde el primer elemento es la posición en el eje 'X' y el segundo en el eje
 * 'Y' de nuestra celula.
 * 
 * @param position Nueva posición de nuestra celula.
 */
void Cell::SetPos(const std::pair<int, int> position) {position_ = position;}

/**
 * @brief Función que modifica la posición en el eje 'X' y 'Y' de nuestra
 * celula. La posición está contenida en un dato de tipo std::pair<int, int>,
 * donde el primer elemento es la posición en el eje 'X' y el segundo en el eje
 * 'Y' de nuestra celula.
 * 
 * @param posx Nueva posicion en el eje 'X' de nuestra celula.
 * @param posy Nueva posicion en el eje 'Y' de nuestra celula.
 */
void Cell::SetPos(const int& posx, const int& posy) {
  position_.first = posx;
  position_.second = posy;
}

/**
 * @brief Funcion que devuelve el atributo interno state_
 * 
 * @return State es el atributo interno de la celula devuelto.
 */
State Cell::GetState(void) const {return state_;}

/**
 * @brief Función que devuelve el atributo position_ que es un
 * std::pair<int, int> el cual, contiene la información de la posicion de la
 * celula.
 * 
 * @return const std::pair<int, int> posicion de la celula, el primero es la
 * posicion en el eje X y la segunda es la posicion en el eje Y.
 */
const std::pair<int, int> Cell::GetPosition(void) const {return position_;}

/**
 * @brief Funcion que devuelve el atributo interno neighbors_alive_ que es un
 * int que contiene la cantidad de celulas vecinas en el turno actual que estan
 * en estado 'viva'
 * 
 * @return int es el numero de celulas vivas en el turno actual, este numero
 * esta comprendido entre el 0 y el 8
 */
int Cell::GetNeighborsAlive(void) const {return neighbors_alive_;}

/**
 * @brief Funcion que se encarga de hacer que la propia celula actualice su
 * estado en el turno actual en base a las reglas de transicion
 */
void Cell::UpdateState(void) {
  if (state_ == 0) {
    if (neighbors_alive_ == 3) state_ = 1;
  }

  if (state_ == 1) {
    if (!(neighbors_alive_ == 2 || neighbors_alive_ == 3)) state_ = 0;
  }
}

/**
 * @brief Puesto que las reglas de transicion se definen en funcion del numero
 * de celulas vecinas vivas a su lado, cada celula debe interactuar con sus 8
 * celulas vecinas para consultarles sus estados, para ello sirve este metodo.
 * 
 * @param grid Rejilla o matriz de celulas en la cual está este objeto celula
 * que invoca al metodo que se halla presente en la rejilla(sino el metodo no
 * tiene sentido usarlo)
 * @return int Numero de celulas vivas vecinas a la que invoca el metodo.
 */
void Cell::NeighborsAlive(const Grid& grid) {
  neighbors_alive_ = 0;
  for (int i{-1}; i < 2; ++i) {
    for (int j{-1}; j < 2; ++j) {
      if ((position_.first == position_.first + i) && 
          (position_.second == position_.second + j)) continue;
        if (grid.GetCell(position_.first + i, position_.second + j).GetState() == 1)
          ++neighbors_alive_;
    }
  }
  
}

/**
 * @brief Funcion que sobrecarga el operador = para la clase Cell.
 * 
 * @param cell Es el objeto celula el cual quiere ser copiado en el otro objeto
 * celula que invoca al método.
 * @return Cell& Es el valor del propio objeto Cell que invoca a la función.
 */
const Cell& Cell::operator=(const Cell& cell) {
  state_ = cell.state_;
  position_ = cell.position_;
  neighbors_alive_ = cell.neighbors_alive_;
  return *this;
}

/**
 * @brief Función que sobrecarga el operador << y os permite mostrar por
 * pantalla el estado de la celula.
 * 
 * @param out variable que nos permite mostrar las cadenas que le enviemos
 * por pantalla
 * @param cell objeto el cual queremos mostrar por pantalla
 * @return std::ostream& objeto out el cual ya tiene los datos necesarios
 * para mostrar las caracteristicas de la celula por pantalla
 */
std::ostream& operator<<(std::ostream& out, const Cell& cell) {
  return out << ((cell.state_) ? 'X' : ' ');
}

