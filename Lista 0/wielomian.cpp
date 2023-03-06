#include "wielomian.h"

#if defined(WIELOMIAN_HPP)

Programowanie_obiektowe::Wielomian::Wielomian(int polynomialDegree, std::vector<float> factors)
{
  this->polynomialDegree = polynomialDegree;
  this->factors = factors;

  this->factors.resize(polynomialDegree + 1);
}

Programowanie_obiektowe::Wielomian::~Wielomian()
{
}

float Programowanie_obiektowe::Wielomian::GetFactor(int at) const
{
  try
  {
    return this->factors.at(at);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    return -1;
  }
}

float Programowanie_obiektowe::Wielomian::hornerScheme(float value) const
{
  float res = GetFactor(0);

  for (size_t i = 1; i < this->polynomialDegree + 1; i++)
  {
    float a_n = GetFactor(i);

    res = res * value + a_n;
  }
  return res;
}

float Programowanie_obiektowe::Wielomian::polynomialEquation(float value) const
{
  float res = 0;
  for (size_t i = 0; i < factors.size(); i++)
  {
    res += GetFactor(i) * powf(value, this->polynomialDegree - i);
  }

  return res;
}

#endif
