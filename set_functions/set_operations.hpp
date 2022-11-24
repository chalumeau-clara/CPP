#include <set>
#include <type_traits>
#include <concepts>

template <class Iterator, class Type>
concept T =
        requires () {
    std::is_integral_v<Type>;
    std::is_array_v<Iterator>;
};

// overload set addition operator
template <typename T>
std::set<T> operator+(std::set<T>& lhs, std::set<T>& rhs) {
    std::set<T> result;
    std::set_union(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), std::inserter(result, result.begin()));
    return result;
}

// overload set subtraction operator
template <typename T>
std::set<T> operator-(std::set<T>& lhs, std::set<T>& rhs) {
    std::set<T> result;
    std::set_difference(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), std::inserter(result, result.begin()));
    return result;
}

// overload set symmetric difference operator
template <typename T>
std::set<T> operator^(std::set<T>& lhs, std::set<T>& rhs) {
    std::set<T> result;
    std::set_symmetric_difference(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), std::inserter(result, result.begin()));
    return result;
}

// overload set multiplication operator {x1+x2 | forall x1 in s1 and x2 in s2}
template <typename T>
std::set<T> operator*(std::set<T>& lhs, std::set<T>& rhs) {
    std::set<T> result;
    for (const auto& x1 : lhs) {
        for (const auto& x2 : rhs) {
            result.insert(x1 + x2);
        }
    }
    return result;
}

// overload set power operator, return a new set containing the original set multiplied with itself n times
template <typename T>
std::set<T> operator^(std::set<T>& lhs, int integer) {
    if (integer < 0)
        throw std::invalid_argument("not an integer");

    else if (integer == 0)
        return std::set<T>{T {}};

    std::set<T> result = lhs;
    for (int i = 1; i < integer; ++i)
        result = result * lhs;

    return result;
}
