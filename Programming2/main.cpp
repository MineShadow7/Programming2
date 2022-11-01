// Copyright 2022 Karagodin Andrey Romanovich. All rights reserved.
#include "ClassCoordinates.h"
#include <iostream>
#include <vector>
#include <string>




int main() {
    //HW1 class TCoordinates.
    TCoordinates<int> cord(1, 2);
    TCoordinates<int> cord2(6, 4);
    TCoordinates<int> cord3(cord2);
    TCoordinates<int> cord4(4, 6);
    cord4 = cord4 + cord2;
    std::cout << cord << cord2 << cord3 << cord4;

    //HW2 Standart template classes.
    std::vector<std::pair<std::string, float>> classTest;
    for (int i = 0; i < 10; i++) {
        std::pair<std::string, float> newpair;
        int r = rand() % 3;
        switch (r)
        {
        case 0:
            newpair.first = "Private";
            break;
        case 1:
            newpair.first = "Public";
            break;
        case 2:
            newpair.first = "Protected";
            break;
        }
        newpair.second = rand() % 10;
        classTest.push_back(newpair);
    }

    for (std::vector<std::pair<std::string, float>>::iterator it = begin(classTest); it != end(classTest); ++it) {
        std::cout << (*it).first << " " << (*it).second << std::endl;
    }

    auto isProtected = [](std::pair<std::string, float> newpair) { return newpair.first == "Protected"; };
    auto isPublic = [](std::pair<std::string, float> newpair) { return newpair.first == "Public"; };


    std::cout << "Finished creating pairs. Now working..." << std::endl;
    for (std::vector<std::pair<std::string, float>>::iterator it = begin(classTest); it != end(classTest); ++it){
        auto pos = std::find_if(std::begin(classTest), std::end(classTest), isProtected);
        if (pos != std::end(classTest)) {
            (*pos).first = "Private";
            std::cout << (*pos).first << " " << (*pos).second << std::endl;
        }
    }
    std::cout << "Finished working with Protected pairs. Now working..." << std::endl;

    for (std::vector<std::pair<std::string, float>>::iterator it = begin(classTest); it != end(classTest); ++it) {
        auto pos = std::find_if(std::begin(classTest), std::end(classTest), isPublic);
        if (pos != std::end(classTest)) {
            (*pos).first = "0";
            std::cout << (*pos).first << " " << (*pos).second << std::endl;
        }
    }
    std::cout << "Finished working with Public pairs. End of programm..." << std::endl;

    return 0;
}
