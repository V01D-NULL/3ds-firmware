#ifndef MATH_H
#define MATH_H

#include <shared/clang.h>
#include <shared/types.h>

STATIC_INLINE
u32 pow(int base, int exponent) {
  u32 temp;
  if (!exponent)
    return 1;

  temp = pow(base, exponent / 2);
  if ((exponent % 2) == 0) {
    return temp * temp;
  } else {
    if (exponent > 0)
      return base * temp * temp;
    else
      return (temp * temp) / base;
  }
}

#endif // MATH_H