#include <iostream>
#include <windows.h>
#include <conio.h>
#include "plansza.h"

int main() {
  Board plansza(3, 2); //y x

  std::cout << plansza << std::endl;

  std::cout << std::endl;

  plansza.Set(0, 0, 20);
  plansza.Set(1, 1, 10);
  plansza.Set(1, 2, 30);
  std::cout << plansza;
  
  _getch();
  return 0;
}