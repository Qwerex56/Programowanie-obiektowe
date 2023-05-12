#include <iostream>
#include <conio.h>
#include "./src/cellularAutomata.cpp"

int main() {
#ifdef _CELLULAR_AUTOMATA_H_
  
  CA::CellularAutomata c{40, 20};

  std::cout << c << std::endl;

  for (int i = 0; i < 100; i++) {
    c.iterate();
    std::cout << c << std::endl;
  }

  _getch();

#endif
  return EXIT_SUCCESS;
}