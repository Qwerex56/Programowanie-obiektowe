#include "../header/cellularAutomata.h"

CA::CellularAutomata::CellularAutomata(int x, int y) : Board(x, y) {
  randGrid();
}

CA::CellularAutomata::CellularAutomata(int x, int y, int Q, int K1, int K2, int G) : Board(x, y) {
  this->q = Q;
  this->k1 = K1;
  this->k2 = K2;
  this->g = G;
  randGrid();
}

void CA::CellularAutomata::iterate() {
  Board* copy = this;
  PO::Range<int> range{};

  for (int y = 0; y < Height(); y++) {
    for (int x = 0; x < Width(); x++) {
      int state = copy->Get(x, y);
      if (state == q) {
        state = 1;
      } else if (state == 1) {
        int a = countNeighboursState(x, y, *copy, PO::Range<int>{2, q - 1});
        int b = countNeighboursState(x, y, *copy, PO::Range<int>{q, q});
        state = (a / k1) + (b / k2) + 1;
      } else if (range.isInRange(2, q - 1, state)) {
        int sum = getStateSum(x, y, *copy);
        int c = countNeighboursState(x, y, *copy, PO::Range<int>{1, 1});
        state = (sum / (9 - c)) + g;
      }

      if (state > q) {
        state = q;
      }

      Set(x, y, state);
    }
  }
}

int CA::CellularAutomata::countNeighboursState(int x, int y, Board& b, PO::Range<int> r) const {
  int neighbours = 0;
  for (int v = y - 1; v < y + 1; v++) {
    for (int u = x - 1; u < x + 1; u++) {
      int _u = (u + Width()) % Width();
      int _v = (v + Height()) % Height();

      if (_u == x && _v == y) {
        continue;
      }

      if (r.isInRange(r.a, r.b, b.Get(_u, _v))) {
        neighbours++;
      }
    }
  }
  return neighbours;
}

int CA::CellularAutomata::getStateSum(int x, int y, Board& b) const {
  int sum = 0;
  for (int v = y - 1; v <= y + 1; v++) {
    for (int u = x - 1; u <= x + 1; u++) {
      int _u = (u + Width()) % Width();
      int _v = (v + Height()) % Height();

      sum += b.Get(_u, _v);
    }
  }
  return sum;
}

void CA::CellularAutomata::randGrid() {
  srand(120);
  for (int y = 0; y < Height(); y++) {
    for (int x = 0; x < Width(); x++) {
      int rng = rand() % q;
      Set(x, y, rng);
    }
  }
}