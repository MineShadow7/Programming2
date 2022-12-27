// Copyright 2022 Karagodin Andrey Romanovich.

#include <sstream>
#include <iostream>
#include <iomanip>
#include "bitfield.h"
#include "set.h"

int main() {
    int max;

    setlocale(LC_ALL, "Russian");
    std::cout << "Решето Эратосфена" << std::endl;
    std::cout << "верхняя граница значений - ";
    std::cin >> max;

    TSet s(max + 1);                            //Создание и заполнение
    for (int i = 2; i <= max; i++)
        s.InsElem(i);
    for (int i = 2; i * i <= max; i++)          // проверка до sqrt(n) и удаление кратных
        // если м в s, удаление кратных
        if (s.IsMember(i))
            for (int j = 2 * i; j <= max; j += i)
                if (s.IsMember(j))
                    s.DelElem(j);
    // оставшиеся в s элементы - простые числа
    std::cout << std::endl << "Множество некратных чисел: " << std::endl << s << std::endl;
    std::cout << std::endl << "Простые числа: " << std::endl;
    int count = 0;
    int k = 1;
    for (int i = 2; i <= max; i++)
        if (s.IsMember(i))
        {
            count++;
            std::cout << std::setw(3) << i << " ";
            if (k++ % 10 == 0)
                std::cout << " ";
        }
    std::cout << std::endl;
    std::cout << "В первых " << max << " числах " << count << " простых" << std::endl;
}