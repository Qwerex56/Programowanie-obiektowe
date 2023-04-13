#include "./cellularAutomata.h"

#ifdef CELLULAR_AUTOMATA_HPP

namespace Lista4 {
  CellularAutomata::CellularAutomata(int x, int y) {
    grid = CellularGrid(x, y, q);
    grid.randomizeGrid(time(NULL));
  }

  CellularAutomata::CellularAutomata(int x, int y, int q, int k1, int k2, int g) {
    this->k1 = k1;
    this->k2 = k2;
    this->q = q;
    this->g = g;

    grid = CellularGrid(x, y, q);
    grid.randomizeGrid(time(NULL));
  }

  int CellularAutomata::countNeighboursState(int const x, int const y, Range range) const {
    int count = 0;
    for (int v = y - 1; v <= y + 1; v++) {
      for (int u = x - 1; u <= x + 1; u++) {
        if ( y == v && x == u ) continue;

        int state = grid.cellGrid.Get(u, v);
        if ( range.isInRange(state) ) count++;
      }
    }
    return count;
  }

  void CellularAutomata::iterate(int times) {
    Board copy = grid.cellGrid;
    
    for (int y = 1; y < copy.Height() - 1; y++) {
      for (int x = 1; x < copy.Width() - 1; x++) {
        int state = copy.Get(x, y);
        if (state == q) {
          copy.Set(x, y, 1);
        } else if (state == 1) {
          int a = countNeighboursState(x, y, Range(2, q - 1));
          int b = countNeighboursState(x, y, Range(q, q));
          int newState = (a / k1) + (b / k2) + 1;
          copy.Set(x, y, newState);
        } else if (Range(2, q - 1).isInRange(state)) {
          int neighbourSum = getStateSum(x, y);
          int c = countNeighboursState(x, y, Range(1, 1));
          int newState = (neighbourSum / (9 - c)) + g;
          copy.Set(x, y, newState);
        } else if (state > q) {
          copy.Set(x, y, q);
        }
      }
    }
    grid.cellGrid = copy;
    std::cout << grid << std::endl;
  }

  int CellularAutomata::getStateSum(int x, int y) const {
    int sum = 0;
    for (int v = y - 1; v <= y + 1; v++) {
      for (int u = x - 1; u <= x + 1; u++) {
        int state = grid.cellGrid.Get(u, v);
        sum += state;
      }
    }
    return sum;
  }

  void CellularAutomata::setState(int x, int y, int state) {
    grid.cellGrid.Set(x, y, state);
  }

  CellularGrid::CellularGrid() {
    cellGrid = Board();
  }

  CellularGrid::CellularGrid(int x, int y, int q, int seed) {
    cellGrid = Board(x, y);
    this->q = q;
    randomizeGrid(seed);
  }

  void CellularGrid::randomizeGrid(int seed) {
    srand(seed);
    for (int y = 0; y < cellGrid.Height(); y++) {
      for (int x = 0; x < cellGrid.Width(); x++) {
        cellGrid.Set(x, y, (rand() % q) + 1);
      }
    }
  }

  Range::Range(int a, int b) {
    this->a = a;
    this->b = b;
  }

  bool Range::isInRange(int val) const {
    return (val >= a && val <= b);
  }
}

#endif