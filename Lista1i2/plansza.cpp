#include "plansza.h"

#ifdef PLANSZA_H

Board::Board() {
  board = CreteBoard();
}

Board::Board(const Board &b){
  width = b.width;
  height = b.height;

  board = CreteBoard();
  for (size_t y = 0; y < height; y++) {
    for (size_t x = 0; x < width; x++) {
      board[y][x] = b.board[y][x];
    }
  }
}

Board::Board(int w, int h) {
  width = w;
  height = h;

  board = CreteBoard();
}

Board::~Board() {
  DeleteBoard();
}

const Board& Board::operator=(const Board &b) {
  if (this == &b)
    return *this;

  DeleteBoard();

  width = b.width;
  height = b.height;

  board = CreteBoard();
  for (size_t y = 0; y < height; y++) {
    for (size_t x = 0; x < width; x++) {
      board[y][x] = b.board[y][x];
    }
  }

  return *this;
}

const bool Board::operator==(const Board &b) const {
  if (this->height != b.height || this->width != b.width) {
    return false;
  }

  for (size_t y = 0; y < this->height; y++) {
    for (size_t x = 0; x < this->width; x++) {
      if (this->board[y][x] != b.board[y][x]) {
        return false;
      }
    }
  }
  return true;
}

constexpr int Board::Width() const {
  return width;
}

constexpr int Board::Height() const {
  return height;
}

constexpr int Board::Get(int x, int y) const {
  if (x >= width || y >= height || x < 0 || y < 0)
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

int** Board::CreteBoard() const {
  int** board = new int *[height];
  for (size_t i = 0; i < height; i++) {
    board[i] = new int[width];
  }

  for (size_t y = 0; y < height; y++) {
    for (size_t x = 0; x < width; x++) {
      board[y][x] = 0;
    }
  }

  return board;
}

void Board::DeleteBoard() const {
  for (size_t y = height - 1; y >= 0; y--) {
    delete[] board[y];
  }

  delete[] board;
}
#endif