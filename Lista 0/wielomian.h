#include <iostream>
#include <vector>
#include <math.h>

#ifndef WIELOMIAN_HPP
#define WIELOMIAN_HPP

namespace Programowanie_obiektowe
{

  class Wielomian
  {
  private:
    int polynomialDegree = 0;
    std::vector<float> factors;

  public:
    Wielomian(int polynomialDegree = 0, std::vector<float> factors = {0});
    ~Wielomian();

    float GetFactor(int atDegree) const;
    float hornerScheme(float value) const;
    float polynomialEquation(float value) const;
  };

}

#endif