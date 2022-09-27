#include <iostream>
#include "is_prime.h"

int main()
{
    int num;
    while (std::cin >> num)
    {
        is_prime(num) ? std::cout << num << " is a prime: True\n" : std::cout << num << " is a prime: False\n";
    }
    
    return 0;
}