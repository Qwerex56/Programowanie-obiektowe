// #include <windows.h>
// #include <conio.h>
#include <iostream>
#include <chrono>
#include "wielomian.h"

int main(int argc, char** argv)
{
  Programowanie_obiektowe::Wielomian w1(1, {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
  float equation;
  float horner;

  auto e_start = std::chrono::high_resolution_clock::now();
  equation = w1.polynomialEquation(10);
  auto e_end = std::chrono::high_resolution_clock::now();

  std::cout << "Equation Scheme: "
            << std::chrono::duration<double, std::milli>(e_end - e_start).count();

  e_start = std::chrono::high_resolution_clock::now();
  horner = w1.hornerScheme(10);
  e_end = std::chrono::high_resolution_clock::now();

  std::cout <<"\nHorner Scheme: "
            << std::chrono::duration<double, std::milli>(e_end - e_start).count();

  std::cout << std::endl
            << horner << std::endl
            << equation;

  // _getch();
  // _getch();
  return EXIT_SUCCESS;
}