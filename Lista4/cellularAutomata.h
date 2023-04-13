#ifndef CELLULAR_AUTOMATA_HPP
#define CELLULAR_AUTOMATA_HPP

#include "../Lista1i2/plansza.h"
#include <iostream>
#include <vector>

namespace Lista4 {
  struct CellularGrid {
    CellularGrid();
    CellularGrid(int x, int y, int q = 1, int seed = time(NULL));
    void randomizeGrid(int seed);
    
    Board cellGrid;
    int q;

    friend std::ostream& operator<<(std::ostream &os, CellularGrid &c) {
      const std::vector<char> COLORS = {' ', '.', ':', ';', '-', '+', '=', 'z', 'Z', 'X'};

      for (int i = 0; i < c.cellGrid.Height(); i++) {
        for (int j = 0; j < c.cellGrid.Width(); j++) {
            os << COLORS[c.cellGrid.Get(j, i)] << " ";
          }
        os << std::endl;
      }
      return os;
    }
  };

  struct Range {
    Range(int a, int b);

    int a;
    int b;

    bool isInRange(int val) const;
  };

  class CellularAutomata {
  public:
    CellularAutomata(int x, int y);
    CellularAutomata(int x, int y, int q, int k1, int k2, int g);

    void iterate(int times = 1);
  private:
    CellularGrid grid;
    int k1 = 1;
    int k2 = 2;
    int q = 2;
    int g = 1;

    int countNeighboursState(int x, int y, Range = Range(1, 1)) const;
    int getStateSum(int x, int y) const;

    void setState(int x, int y, int state);
  };
} // namespace Lista4


#endif