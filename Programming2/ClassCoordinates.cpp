// Copyright 2022 Karagodin Andrey Romanovich. All rights reserved.
#include <iostream>

template <class Type> class Coordinates;
template <class Type> std::ostream& operator <<(std::ostream& out, const Coordinates<Type>& r);

template <class Type>
class Coordinates {
    Type first;
    Type second;

public:
    Coordinates() : first(0), second(0) {}

    Coordinates(Type _first, Type _second) {
        first = _first;
        second = _second;
    }

    Coordinates(const Coordinates& other) {
        first = other.first;
        second = other.second;
    }

    void print() {
        std::cout << "(" << first << ", " << second << ")" << std::endl;
    }

    Coordinates& operator+(const Coordinates& n) {
        Coordinates res;
        res.first = first + n.first;
        res.second = second + n.second;
        return res;
    }

    Coordinates& operator=(const Coordinates n) {
        if (this == &n) {
            return *this;
        }
        first = n.first;
        second = n.second;
        return *this;
    }

    friend std::ostream& operator<< <Type>(std::ostream& out, const Coordinates& r);
};

template <class Type>
std::ostream& operator <<(std::ostream& out, const Coordinates<Type>& r) {
    out << "(" << n.first << ", " << n.second << ")" << std::endl;
    return out;
}
