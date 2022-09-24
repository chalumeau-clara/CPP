#include <iostream>
#include "is_prime.h"
//#include "sources_2.h"

int main()
{
    int number;
    while (std::cin >> number) {
        std::cout << number << " is a prime: ";
        is_prime(number) ? std::cout << "True\n" : std::cout << "False\n";
    }
    return 0;
}