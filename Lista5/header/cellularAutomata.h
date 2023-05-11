#ifndef _CELLULAR_AUTOMATA_H_
#define _CELLULAR_AUTOMATA_H_
#include <iostream>

#include "../../POLib/range.cpp"
#include "../../Lista1i2/header/plansza.h"

namespace CA {
  class CellularAutomata : protected Board {
  public: 
    CellularAutomata(int x, int y);
    CellularAutomata(int x, int y, int q, int k1, int k2, int g);

    void iterate();
    friend std::ostream& operator<<(std::ostream& os, const CellularAutomata& ca) {
      const char color[] = {' ',
                            '.',
                            ':',
                            ';',
                            '-',
                            '+',
                            '=',
                            'z',
                            'Z',
                            'X'};
      for (int y = 0; y < ca.Height(); y++) {
        for (int x = 0; x < ca.Width(); x++) {
          // os << ca.Get(x, y) << ' ';
          os << color[ca.Get(x, y)] << ' ';
        }
        os << '\n';
      }
      return os;
    }

  private:
    int q = 9;
    int k1 = 4;
    int k2 = 3;
    int g = 1;

    int countNeighboursState(int x, int y, Board& b, PO::Range<int> = PO::Range<int>(1, 1)) const;
    int getStateSum(int x, int y, Board& b) const;

    void randGrid();
  };
}


#endif // _CELLULAR_AUTOMATA_H_