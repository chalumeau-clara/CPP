//
// Created by clara on 29/09/22.
//
#include "vector.hh"

const value& Vector::operator[](size_t pos) const{
    return vect[pos];
}

value& Vector::operator[](size_t pos){
    return vect[pos];
}

Vector& Vector::operator+=(const Vector& rhs) {
    for (int i = 0; i < NDIM; i++) {
        vect[i] += rhs[i];
    }
    return *this;
}

Vector& Vector::operator+=(value scalar)  {
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


Vector& Vector::operator*=(const value& scalar) {
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
Vector operator*(const Vector& lhs, value scalar) {
    Vector v = Vector();
    for (int i = 0; i < NDIM; i++) {
        v[i] = lhs[i] * scalar;
    }
    return v;
}
Vector operator*(value scalar, const Vector& rhs) {
    Vector v = Vector();
    for (int i = 0; i < NDIM; i++) {
        v[i] = scalar* rhs[i];
    }
    return v;
}
value operator*(const Vector& lhs, const Vector& rhs) {
    value sum = 0;
    for (int i = 0; i < NDIM; i++) {
        sum += lhs[i] * rhs[i];
    }
    return sum;
}