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
  bool operator==(const Board &) const;

  int Width() const;
  int Height() const;

  void Set(int, int, int);
  int Get(int, int) const;
  int **GetBoard() const { return this->board; }

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
  int **board;
  int height = 1; //x
  int width  = 1; //y

  int **CreteBoard() const;
  void DeleteBoard() const; // Use with Create Board
};

#endif