//
// Created by clara on 21/10/22.
//

#include "vector.hh"


Vector::Vector(const Vector &v) {
    for (int i=0; i<size_vector; ++i)  this[i] = v[i];
    size_vector = v.size();
}

Vector& Vector::operator=(const Vector&) {
    return *this;
}

Vector::Vector(size_t N) {
    vect = std::make_unique<value[]>(N);
    for (int i = 0; i < N; i++) {
        vect[i] = 0;
    }
    size_vector = N;
}
Vector::Vector(std::initializer_list<value> l) {
    size_vector = l.size();
    vect = std::make_unique<value[]>(l.size());
    value count = 0;
    for (value element : l) {
        vect[count] = element;
        ++count;
    }
}

size_t Vector::size() const {
    return size_vector;
}

// Public Member functions here
Vector& Vector::operator+=(const Vector& rhs) {
    if (size_vector != rhs.size())
        std::runtime_error("Incompatible size");
    for (int i = 0; i < rhs.size(); i++) {
        vect[i] += rhs[i];
    }

    return *this;
}

Vector& Vector::operator-=(const Vector& rhs){
    if (size_vector != rhs.size())
        std::runtime_error("Incompatible size");
    for (int i = 0; i < rhs.size(); i++) {
        vect[i] -= rhs[i];
    }
    return *this;
}

Vector& Vector::operator+=(value v) {
    for (int i = 0; i < size_vector; i++) {
        vect[i] += v;
    }
    return *this;
}

Vector& Vector::operator*=(value v){
    for (int i = 0; i < size_vector; i++) {
        vect[i] *= v;
    }
    return *this;
}

Vector Vector::operator+(const Vector& rhs) const {
    if (size_vector != rhs.size())
        std::runtime_error("Incompatible size");
    for (int i = 0; i < rhs.size(); i++) {
        vect[i] += rhs[i];
    }
    return *this;
}

Vector Vector::operator+(value v) const {
    for (int i = 0; i < size_vector; i++) {
        vect[i] += v;
    }
    return *this;
}

value Vector::operator*(const Vector& rhs) const {
    if (size_vector != rhs.size())
        std::runtime_error("Incompatible size");
    value sum = 0;
    for (int i = 0; i < rhs.size(); i++) {
        sum += vect[i] * rhs[i];
    }
    return sum;
}

Vector Vector::operator*(value v) const {
    for (int i = 0; i < size_vector; i++) {
        vect[i] *= v;
    }
    return *this;

}

value& Vector::operator[](size_t idx) {
    if (size_vector < idx)
        std::runtime_error("Incompatible size");
    return vect[idx];
}

value Vector::operator[](size_t idx) const {
    if (size_vector < idx)
        std::runtime_error("Incompatible size");
    return vect[idx];
}



// Nonmember function operators go here
Vector operator*(const value& s, const Vector& v) {
    Vector vv = Vector(v.size());
    for (int i = 0; i < v.size(); i++) {
        vv[i] = v[i] * s;
    }
    return vv;
}

Vector operator+(const value& s, const Vector& v) {
    Vector vv = Vector(v.size());
    for (int i = 0; i < v.size(); i++) {
        vv[i] = v[i] + s;
    }
    return vv;
}

std::ostream& operator<<(std::ostream& o, const Vector& v) {
    o<<'{';
    int i = 0;
    for (; i < v.size() - 1; i++) {
        o<<v[i]<<',';
    }
    o<<v[i]<<"}";
    return o;
}