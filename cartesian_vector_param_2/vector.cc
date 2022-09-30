//
// Created by clara on 29/09/22.
//
#include "vector.hh"

const int& Vector::operator[](size_t pos) const{
    return vect[pos];
}

int& Vector::operator[](size_t pos){
    return vect[pos];
}

Vector& Vector::operator+=(const Vector& rhs) {
    for (int i = 0; i < NDIM; i++) {
        vect[i] += rhs[i];
    }
    return *this;
}

Vector& Vector::operator+=(int scalar)  {
    for (int i = 0; i < NDIM; i++) {
        vect[i] += scalar;
    }
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs){
    for (int i = 0; i < NDIM; i++) {
        vect[i] -= rhs[i];
    }
    return *this;
}
Vector& Vector::operator*=(const Vector& rhs) {
    for (int i = 0; i < NDIM; i++) {
        vect[i] *= rhs[i];
    }
    return *this;
}


Vector& Vector::operator*=(const int& scalar) {
    for (int i = 0; i < NDIM; i++) {
        vect[i] *= scalar;
    }
    return *this;
}


ostream& operator<<(ostream& os, const Vector& rhs) {
        os<<'{';
        int i = 0;
        for (; i < NDIM - 1; i++) {
            os<<rhs[i]<<',';
        }
        os<<rhs[i]<<"}";
        return os;
}
Vector operator+(const Vector& lhs, const Vector& rhs) {
    Vector v = Vector();
    for (int i = 0; i < NDIM; i++) {
        v[i] = lhs[i] + rhs[i];
    }
    return v;
}
Vector operator-(const Vector& lhs, const Vector& rhs)  {
    Vector v = Vector();
    for (int i = 0; i < NDIM; i++) {
        v[i] = lhs[i] - rhs[i];
    }
    return v;
}
Vector operator*(const Vector& lhs, int scalar) {
    Vector v = Vector();
    for (int i = 0; i < NDIM; i++) {
        v[i] = lhs[i] * scalar;
    }
    return v;
}
Vector operator*(int scalar, const Vector& rhs) {
    Vector v = Vector();
    for (int i = 0; i < NDIM; i++) {
        v[i] = scalar* rhs[i];
    }
    return v;
}
int operator*(const Vector& lhs, const Vector& rhs) {
    int sum = 0;
    for (int i = 0; i < NDIM; i++) {
        sum += lhs[i] * rhs[i];
    }
    return sum;
}