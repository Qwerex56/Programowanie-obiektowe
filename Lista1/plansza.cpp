#include "plansza.h"

#ifdef PLANSZA_H

Board::Board() {
  board = new int *[width];
  for (size_t i = 0; i < width; i++)
  {
    board[i] = new int[height];
  }

  for (size_t y = 0; y < width; y++) {
    for (size_t x = 0; x < height; x++) {
      board[y][x] = 0;
    }
  }
}

Board::Board(int w, int h) {
  width = w;
  height = h;

  board = new int *[width];
  for (size_t i = 0; i < width; i++) {
    board[i] = new int[height];
  }

  for (size_t y = 0; y < width; y++) {
    for (size_t x = 0; x < height; x++) {
      board[y][x] = 0;
    }
  }
}

Board::~Board() {
  for (size_t y = width - 1; y > 0; y--) {
    delete[] board[y];
  }

  delete[] board;
}

constexpr int Board::Width() const {
  return width;
}

constexpr int Board::Height() const {
  return height;
}

constexpr int Board::Get(int x, int y) const {
  if (x >= height || y >= width || x < 0 || y < 0)
    throw std::runtime_error("X or Y out of array bounds");

  return board[y][x];
}

void Board::Set(int x, int y, int val) {
  try {
    Get(x, y);
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
    return;
  }

  board[y][x] = val;
}

#endif