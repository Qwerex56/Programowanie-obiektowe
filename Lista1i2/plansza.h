#ifndef PLANSZA_H
#define PLANSZA_H

#include <iostream>

class Board {
public:
  Board();
  Board(const Board &);
  Board(int, int);
  ~Board();

  const Board& operator=(const Board &);
  const bool operator==(const Board &) const;

  constexpr int Width() const;
  constexpr int Height() const;

  void Set(int, int, int);
  constexpr int Get(int, int) const;

  friend std::ostream& operator<<(std::ostream& os, Board& b) {
    for (size_t y = 0; y < b.height; y++) {
      for (size_t x = 0; x < b.width; x++) {
        os << b.Get(x, y) << " ";
      }
      os << std::endl;
    }
    return os;
  }

private:
  int **board;
  int height = 1; //x
  int width  = 1; //y

  int **CreteBoard() const;
  void DeleteBoard() const; // Use with Create Board
};

#endif