#ifndef _RANGE_H_
#define _RANGE_H_

namespace PO {
  template <typename T>
  class Range {
  public:
    Range() {

    }

    Range(T _a, T _b) {
      a = _a;
      b = _b;
    }

    T a;
    T b;

    bool isInRange(T min, T max, T val) {
      return (val >= min) && (val <= max);
    }
  };
}

#endif