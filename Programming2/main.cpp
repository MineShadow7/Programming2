// Copyright 2022 Karagodin Andrey Romanovich. All rights reserved.
#include "ClassCoordinates.cpp"


int main() {
    Coordinates<float> A(5.4, 4.2), B(3.1, 5.8), C(A);
    A.print();
    B.print();
    C = A + B;
    std::cout << C << std::endl;
    return 0;
}
