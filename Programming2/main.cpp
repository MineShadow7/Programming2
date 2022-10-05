// Copyright 2022 Karagodin Andrey Romanovich. All rights reserved.
#include <vector>;
#include <iostream>;

void print(std::vector<std::vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> set(int size, std::vector<std::vector<int>> matrix) {
    std::vector<std::vector<int>> matrix2(size, std::vector<int>(size, 0));
    std::cout << "Enter new matrix" << std::endl;
    for (int i = 0; i < matrix.size(); i++) {
        std::cout << std::endl << "New row:" << std::endl;
        for (int j = 0; j < matrix2[i].size(); j++) {
            std::cin >> matrix2[i][j];
            std::cout << " ";
        }
    }
    std::cout << "Printing your new matrix: " << std::endl;
    print(matrix2);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix2[i].size(); j++) {
            matrix[i][j] = matrix2[i][j];
        }
    }
    return matrix;
}

std::vector<std::vector<int>> operator-(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b)
{
    if (a.size() != b.size())
        throw("a.size() != b.size()");
    std::vector<std::vector<int>> c(a.size(), std::vector<int>(a.size(), 0));
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[i].size(); j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    return c;
}

std::vector<std::vector<int>> operator+(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b)
{
    if (a.size() != b.size())
        throw("a.size() != b.size()");
    std::vector<std::vector<int>> c(a.size(), std::vector<int>(a.size(), 0));
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[i].size(); j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}

std::vector<std::vector<int>> operator*(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b)
{
    if (a.size() != b.size())
        throw("a.size() != b.size()");
    std::vector<std::vector<int>> c(a.size(), std::vector<int>(a.size(), 0));
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[i].size(); j++) {
            c[i][j] = a[i][j] * b[j][i];
        }
    }
    return c;
}

std::vector<std::vector<int>> operator*(const std::vector<std::vector<int>>& a, const int b)
{
    std::vector<std::vector<int>> c(a.size(), std::vector<int>(a.size(), 0));
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[i].size(); j++) {
            c[i][j] = a[i][j] * b;
        }
    }
    return c;
}

std::vector<std::vector<int>> operator*(const std::vector<std::vector<int>>& a, const std::vector<int>& b)
{
    if (a.size() != b.size())
        throw("a.size() != b.size()");
    std::vector<std::vector<int>> c(a.size(), std::vector<int>(a.size(), 0));
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[i].size(); j++) {
            c[i][j] = a[i][j] * b[j];
        }
    }
    return c;
}

std::vector<std::vector<int>> transp(std::vector<std::vector<int>>& a) {
    std::vector<std::vector<int>> c(a.size(), std::vector<int>(a.size(), 0));
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[i].size(); j++) {
            c[i][j] = a[j][i];
        }
    }
    return c;
}

int main() {
    int size = 5;
    std::vector<std::vector<int>> matrix(size, std::vector<int>(size, 0));
    print(matrix);
    matrix = set(size, matrix);

    std::cout << "Matrix = Matrix 2" << std::endl;
    std::vector<std::vector<int>> matrix2(size, std::vector<int>(size, 0));
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            matrix2[i][j] = matrix[i][j];
        }
    }

    std::cout << "Operator +" << std::endl;
    matrix = matrix + matrix2;
    print(matrix);
    std::cout << "Operator -" << std::endl;
    matrix = matrix - matrix2;
    print(matrix);
    std::cout << "Operator * on matrix" << std::endl;
    matrix = matrix * matrix2;
    print(matrix);
    std::cout << "Operator * on a number" << std::endl;
    matrix = matrix * 6;
    print(matrix);

    std::vector<int> vec{ 6, 7, 8, 9, 10 };
    std::cout << "Operator * on a vector" << std::endl;
    matrix = matrix * vec;
    print(matrix);

    std::cout << "Transponirovanie matrix" << std::endl;
    matrix = transp(matrix);
    print(matrix);


}