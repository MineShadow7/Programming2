#pragma once
// Copyright 2022 Karagodin Andrey Romanovich. All rights reserved.
#include <iostream>

template <class Type> class TCoordinates;
template <class Type> std::ostream& operator <<(std::ostream& out, const TCoordinates<Type>& r);

template <class Type>
class TCoordinates {
    Type first;
    Type second;

public:
    TCoordinates() : first(0), second(0) {}

    TCoordinates(Type _first, Type _second) {
        first = _first;
        second = _second;
    }

    TCoordinates(const TCoordinates& other) {
        first = other.first;
        second = other.second;
    }

    void print() {
        std::cout << "(" << first << ", " << second << ")" << std::endl;
    }

    TCoordinates operator+(const TCoordinates& n) {
        TCoordinates res;
        res.first = first + n.first;
        res.second = second + n.second;
        return res;
    }

    TCoordinates& operator=(const TCoordinates& n) {
        if (this == &n) {
            return *this;
        }
        first = n.first;
        second = n.second;
        return *this;
    }

    friend std::ostream& operator<< <Type>(std::ostream& out, const TCoordinates& r);
};

template <class Type>
std::ostream& operator <<(std::ostream& out, const TCoordinates<Type>& r) {
    out << "(" << r.first << ", " << r.second << ")" << std::endl;
    return out;
}
