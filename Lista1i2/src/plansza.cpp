#include "../header/plansza.h"

#ifdef PLANSZA_H

Board::Board() {
  board = CreteBoard();
}

Board::Board(const Board &b){
  width = b.width;
  height = b.height;

  board = CreteBoard();
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
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
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      board[y][x] = b.board[y][x];
    }
  }

  return *this;
}

bool Board::operator==(const Board &b) const {
  if (this->height != b.height || this->width != b.width) {
    return false;
  }

  for (int y = 0; y < this->height; y++) {
    for (int x = 0; x < this->width; x++) {
      if (this->board[y][x] != b.board[y][x]) {
        return false;
      }
    }
  }
  return true;
}

int Board::Width() const {
  return width;
}

int Board::Height() const {
  return height;
}

int Board::Get(int x, int y) const {
  if (x >= width || y >= height || x < 0 || y < 0)
    throw std::runtime_error("X or Y out of array bounds");

  return board[y][x];
}

void Board::Set(int x, int y, int val) {
  try {
    Get(x, y);
  }
  catch(const std::exception& e) {
    // std::cerr << e.what() << '\n';
    return;
  }

  board[y][x] = val;
}

int** Board::CreteBoard() const {
  int** newBoard = new int *[height];
  for (int i = 0; i < height; i++) {
    newBoard[i] = new int[width];
  }

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      newBoard[y][x] = 0;
    }
  }

  return newBoard;
}

void Board::DeleteBoard() const {
  for (int y = height - 1; y >= 0; y--) {
    delete[] board[y];
  }

  delete[] board;
}
#endif