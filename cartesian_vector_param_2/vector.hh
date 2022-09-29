#pragma once

#include <ostream>
#include <initializer_list>

#include "config.h"
using namespace std;
class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector();
    Vector(initializer_list<int> li) : vect{li};
    // possibly more

// Public Member functions here
    Vector& operator+=(const Vector& rhs);
    Vector& operator-=(const Vector& rhs);
    Vector& operator*=(const Vector& rhs);
    // More to go

private:
// Private Member functions here
    value *vect[NDIM];
// Member variables are ALWAYS private, and they go here
};

// Nonmember function operators go here
ostream& operator<<(ostream& os, const Vector& rhs);
Vector operator+(const Vector& lhs, const Vector& rhs);
Vector operator-(const Vector& lhs, const Vector& rhs);
Vector operator*(const Vector& lhs, int scalar);
Vector operator*(int scalar, const Vector& rhs);
int operator*(const Vector& lhs, const Vector& rhs);