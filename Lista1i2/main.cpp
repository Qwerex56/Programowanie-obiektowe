#include <iostream>
// #include <windows.h>
// #include <conio.h>
#include "plansza.h"

int main() {
  Board p1(3, 2); //y x
  Board p2(3, 2); //y x

  std::cout << p1 << std::endl;

  if (p1 == p2) {
    std::cout << "p1 == p2" << std::endl;
    std::cout << p1.Get(0, 0) << std::endl;
    std::cout << "Prawda";
  }

  return 0;
}