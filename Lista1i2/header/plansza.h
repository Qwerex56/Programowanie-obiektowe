#ifndef PLANSZA_H
#define PLANSZA_H

#include <iostream>

/**
 * @brief Board is container for easy 2D int array manipulation
 * 
 */
class Board {
public:
  /**
   * @brief Construct a new Board object
   * 
   */
  Board();

  /**
   * @brief Copy constructor
   * @param constructs board from other board
   */
  Board(const Board &);
  
  /**
   * @brief Construct a new Board object
   * @param Constructs board with given dimensions
   */
  Board(int, int);
  
  /**
   * @brief Destroy the Board object
   */
  ~Board();

  /**
   * @brief Move constructor
   * 
   * @return const Board& 
   */
  const Board& operator=(const Board &);

  /**
   * @brief Equality operator
   * 
   * @return true - boards are equal to each other
   * @return false - boards are not equal to each other
   */
  bool operator==(const Board &) const;

  /**
   * @brief Get board width dimension
   * 
   * @return int - board width
   */
  int Width() const;

  /**
   * @brief Get board height dimension
   * 
   * @return int - board height
   */
  int Height() const;

  /**
   * @brief Sets value in given position, or does nothing if is outside of board
   */
  void Set(int, int, int);

  /**
   * @brief Gets value from given position
   * @throws outside of bounds
   * 
   * @return int - value from given position
   */
  int Get(int, int) const;

  /**
   * @brief Get the Board object
   * 
   * @return int** return full board
   */
  int **GetBoard() const { return this->board; }

  /**
   * @brief prints board in std::cin
   * 
   * @param os - ostream
   * @param b - board to print
   * @return std::ostream& 
   */
  friend std::ostream& operator<<(std::ostream& os, Board& b) {
    for (int y = 0; y < b.height; y++) {
      for (int x = 0; x < b.width; x++) {
        os << b.Get(x, y) << " ";
      }
      os << std::endl;
    }
    return os;
  }

private:
  /**
   * @brief board array container, 2D array
   */
  int **board;

  /**
   * @brief Board heigth
   */
  int height = 1; //x

  /**
   * @brief Boards width
   */
  int width  = 1; //y

  /**
   * @brief Helper method, creates and allocates new board
   *
   * @return int** 
   */
  int **CreteBoard() const;

  /**
   * @brief Helper function, deletes and deallocates this board
   */
  void DeleteBoard() const;
};

#endif