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
 * 21/03/22 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include.
 * 22/03/22 - Funciones de la clase terminadas.
 */

#include "Cell.h"
#include "GridWithOpenBorder.h"
#include "StateDead.h"
#include "StateAlive.h"

/**
 * @brief Constructor por defecto definido. 
 */
Cell::Cell(void) : state_(new StateDead), position_({-1, -1}) {}

/**
 * @brief Constructor basico, que define el estado, pero no la posicion.
 * 
 * @param state estado de la celula.
 */
Cell::Cell(const char& state) : state_(NULL), position_({-1, -1}) {
  if (state == 'X') state_ = new StateAlive;
  if (state == ' ') state_ = new StateDead;
}

/**
 * @brief Constructor basico que define el estado y la posicion de la celula
 * en la Rejilla, este lo hace usando directamente un dato de tipo
 * std::pair<int, int>.
 * 
 * @param state Estado de la celula.
 * @param position Posicion en 2D de la celula en la Rejilla.
 */
Cell::Cell(const char& state, const std::pair<int, int>& position) 
    : state_(NULL), position_(position) {
  if (state == 'X') state_ = new StateAlive;
  if (state == ' ') state_ = new StateDead;
}

/**
 * @brief Constructor basico que define el estado y la posicion de la celula
 * en la Rejilla, este lo hace cogiendo dos numeros que serán sus posiciones
 * en los ejes 'X' e 'Y'.
 * 
 * @param state Estado de la celula.
 * @param posx Posición en el eje 'X'
 * @param posy Posición en el eje 'Y'
 */
Cell::Cell(const char& state, const int& posx, const int& posy)
    : state_(NULL), position_({posx, posy}) {
  if (state == 'X') state_ = new StateAlive;
  if (state == ' ') state_ = new StateDead;
}

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
 * @brief Método que sustituye el valor del atributo interno state_ por el
 * valor que se le pasa al método.
 * 
 * @param state es el nuevo valor del altributo interno state_
 */
void Cell::SetState(State* state) {state_ = state;}

/**
 * @brief Método que asigna un nuevo estado a la celula.
 * 
 * @param state es el carácter que dice que tipo de estado tendrá la celula.
 */
void Cell::SetState(const char& state) {
  if (state == 'X') state_ = new StateAlive;
  if (state == ' ') state_ = new StateDead;
}

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
 * @brief Método que muestra por pantalla el estado de la célula, este puede
 * variar entre 2 posibles estados y son Muerta ( ) y Viva (X)
 * 
 * @return char es uno de los 2 carácteres que representa a cada uno de los
 * 2 posibles estados en los que puede estar una celula.
 */
char Cell::GetState(void) const {return state_->GetState();}

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
 * @brief Método que ayuda a la celula a pasar al siguiente estado.
 */
void Cell::UpdateState(void) {
  state_ = state_->NextState();
}

/**
 * @brief Puesto que las reglas de transicion se definen en funcion del numero
 * de celulas vecinas vivas a su lado, cada celula debe interactuar con sus 8
 * celulas vecinas para consultarles sus estados, para ello sirve este metodo.
 * 
 * @param grid Rejilla o matriz de celulas en la cual está este objeto celula
 * que invoca al metodo que se halla presente en la rejilla(sino el metodo no
 * tiene sentido usarlo)
 * @return int Numero de celulas que cumplen un requisito, dependiendo del
 * estado actual de la célula, ese número significará una cosa u otra y ayudará
 * a interpretar el próximo estado que la célula adoptará.
 */
int Cell::Neighbors(const Grid& grid) {
  return state_->Neighbors(grid, position_.first, position_.second);  
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
  return out << cell.state_->GetState();
}

