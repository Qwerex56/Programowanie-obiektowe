#include <iostream>
#include <windows.h>
#include <conio.h>
#include "plansza.h"

int main() {
  Board p1(3, 2); //y x

  std::cout << p1 << std::endl;

  p1.Set(0, 1, 10);
  p1.Set(1, 0, 20);
  p1.Set(2, 1, 30);

  std::cout << p1;

  Board p2(p1);
  std::cout << std::endl << p2;

  Board p3;
  p3 = (p2 = p1);
  std::cout << p3.Get(0, 0);
  std::cout << p3 << std::endl;
  std::cout << p3.Get(0, 0);

  _getch();
  return 0;
}