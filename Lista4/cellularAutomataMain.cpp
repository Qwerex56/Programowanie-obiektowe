#include "./cellularAutomata.h"

#include <iostream>


int main(int argc, char *argv[]) {
  Lista4::CellularAutomata ca = Lista4::CellularAutomata(40, 20, 9, 4, 7, 3);

  for (int i = 0; i < 400; i++) {
    std::cout << "Iteration: " << i << std::endl;
    ca.iterate();
  }

  return 0;
}