#include "is_prime.h"
#include <cmath>

bool is_prime(long double number)
{
    if (number <= 1)
        return false;
    if (number <= 3)
        return true;
    if (fmodl(number,2) == 0 || fmodl(number,3) == 0)
        return false;

    for (int i = 5; i * i <= number; i = i + 6)
        if (fmodl(number,i) == 0 || fmodl(number, (i + 2)) == 0)
            return false;
    return true;
}


