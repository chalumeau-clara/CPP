#include <iostream>
#include "is_prime.h"

int main()
{
    long double num;
    std::cout.precision(30);

    while (std::cin >> num)
    {
        is_prime(num) ? std::cout << num << " is a prime: True\n" : std::cout << num << " is a prime: False\n";
    }

    return 0;
}