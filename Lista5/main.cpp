#include <iostream>
#include <conio.h>
#include "./cellularAutomata.h"

int main() {
  CA::CellularAutomata c{40, 20};

  std::cout << c << std::endl;

  for (int i = 0; i < 100; i++) {
    c.iterate();
    std::cout << c << std::endl;
  }

  _getch();
  return EXIT_SUCCESS;
}