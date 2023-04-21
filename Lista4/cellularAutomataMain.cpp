#include "./cellularAutomata.h"

#include <iostream>
#include <conio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
  Lista4::CellularAutomata ca = Lista4::CellularAutomata(60, 30, 9, 3, 2, 1);

  while (!_kbhit()) {
    system("cls");
    // std::cout << "Iteration: " << i << std::endl;
    std::cout << std::endl;
    ca.iterate();

    _sleep(16);
  }

  _getch();
  _getch();

  return 0;
}