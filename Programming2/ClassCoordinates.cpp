// Copyright 2022 Karagodin Andrey Romanovich. All rights reserved.
#include <iostream>

template <class Type> class TPair;
template <class Type> std::ostream& operator <<(std::ostream& out, const TPair<Type>& r);

template <class Type>
class TPair {
    Type first;
    Type second;

public:
    TPair() : first(0), second(0) {}

    TPair(Type _first, Type _second) {
        first = _first;
        second = _second;
    }

    TPair(const TPair& other) {
        first = other.first;
        second = other.second;
    }

    void print() {
        std::cout << "(" << first << ", " << second << ")" << std::endl;
    }

    TPair& operator+(const TPair& n) {
        TPair res;
        res.first = first + n.first;
        res.second = second + n.second;
        return res;
    }

    TPair& operator=(const TPair n) {
        if (this == &n) {
            return *this;
        }
        first = n.first;
        second = n.second;
        return *this;
    }

    friend std::ostream& operator<< <Type>(std::ostream& out, const TPair& r);
};

template <class Type>
std::ostream& operator <<(std::ostream& out, const TPair<Type>& r) {
    out << "(" << r.first << ", " << r.second << ")" << std::endl;
    return out;
}
