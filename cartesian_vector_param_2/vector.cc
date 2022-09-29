//
// Created by clara on 29/09/22.
//
#include "vector.hh"
Vector& Vector::operator+=(const Vector& rhs) {
    for (int i = 0; i < rhs.size(); i++) {
        vect[i] += rhs.vect[i];
    }
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs){
    for (int i = 0; i < rhs.size(); i++) {
        vect[i] -= rhs.vect[i];
    }
    return *this;
}
Vector& Vector::operator*=(const Vector& rhs) {
    for (int i = 0; i < rhs.size(); i++) {
        vect[i] *= rhs.vect[i];
    }
    return *this;
}

ostream& operator<<(ostream& out, const Vector& rhs) {
    if (! rhs.empty()) {
        cout<<'{';
        int i = 0;
        for (; i < rhs.size() - 1; i++) {
            out<<rhs.vect[i]<<',';
        }
        out<<rhs.vect[i]<<"}";
    }
    else {
        cout<<"{}";
    }
}
Vector operator+(const Vector& lhs, const Vector& rhs) {
    Vector v = Vector();
    for (int i = 0; i < rhs.size(); i++) {
        v.vect[i] = lhs.vect[i] + rhs.vect[i];
    }
    return v;
}
Vector operator-(const Vector& lhs, const Vector& rhs)  {
    Vector v = Vector();
    for (int i = 0; i < rhs.size(); i++) {
        v.vect[i] = lhs.vect[i] - rhs.vect[i];
    }
    return v;
}
Vector operator*(const Vector& lhs, int scalar) {
    Vector v = Vector();
    for (int i = 0; i < lhs.size(); i++) {
        v.vect[i] = lhs.vect[i] * scalar;
    }
    return v;
}
Vector operator*(int scalar, const Vector& rhs) {
    Vector v = Vector();
    for (int i = 0; i < rhs.size(); i++) {
        v.vect[i] = scalar* rhs.vect[i];
    }
    return v;
}
int operator*(const Vector& lhs, const Vector& rhs) {
    Vector v = Vector();
    for (int i = 0; i < rhs.size(); i++) {
        v.vect[i] = lhs.vect[i] * rhs.vect[i];
    }
    return v;
}