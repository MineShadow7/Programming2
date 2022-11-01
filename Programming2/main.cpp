// Copyright 2022 Karagodin Andrey Romanovich. All rights reserved.
#include <vector>
#include <list>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <functional>
#include <iterator>
#include <random>
#include <stack>
#include <set>

struct RandomGenerator
{
    int maxv, minv;
    RandomGenerator(int max, int min) :
        maxv(max), minv(min) {

    }
    int operator()() {
        return minv + rand() % maxv - minv + 1;
    }
};

int main() {
    //Block Vector Tasks
    srand(unsigned(time(nullptr)));
    std::vector<int> v(20);
    auto iter = v.begin();
    while (iter != v.end()) {
        std::cout << *iter << " ";
        ++iter;
    }
    std::cout << std::endl << "Created an empty vector 20 elements." << std::endl;
    system("PAUSE");

    int val;
    iter = v.begin();
    std::generate(v.begin(), v.end(), RandomGenerator(100, -100));
    while (iter != v.end()) {
        std::cout << *iter << " ";
        ++iter;
    }
    std::cout << std::endl << "Created random numbers for vector" << std::endl;
    system("PAUSE");

    int minelem = *std::min_element(v.begin(), v.end());
    int maxelem = *std::max_element(v.begin(), v.end());
    std::cout << "Minimal element in vector: " << minelem << std::endl;
    std::cout << "Maximal element in vector: " << maxelem << std::endl;
    std::cout << "Found minmax in vector" << std::endl;
    system("PAUSE");

    std::sort(v.begin(), v.end());
    iter = v.begin();
    while (iter != v.end()) {
        std::cout << *iter << " ";
        ++iter;
    }
    std::cout << std::endl << "Sort vector" << std::endl;
    system("PAUSE");

    iter = v.end();
    for (int i = 0; i < 4; i++) {
        val = -100 + rand() % +201;
        v.push_back(val);
    }
    iter = v.begin();
    while (iter != v.end()) {
        std::cout << *iter << " ";
        ++iter;
    }
    std::cout << std::endl << "Add 4 new elements to end of the vector" << std::endl;
    system("PAUSE");

    iter = v.begin();
    std::replace_if(v.begin(), v.end(), std::bind(std::less<int>(), std::placeholders::_1, 10), 0);
    while (iter != v.end()) {
        std::cout << *iter << " ";
        ++iter;
    }
    std::cout << std::endl << "Replace all number less than 10 with 0" << std::endl;
    system("PAUSE");

    for_each(v.begin(), v.end(), [](int a)
        {
            if (a > 20) { std::cout << a << " "; }
        });

    std::cout << std::endl << "Out all elements greater than 20 in vector" << std::endl;
    system("PAUSE");

    for_each(v.begin(), v.end(), [](int a)
        {
            if (a % 2 != 1) {
                a = a * 3;
                std::cout << a << " ";
            }
        });
    std::cout << std::endl << "All non Odd elements multiplied by 3 in vector" << std::endl;
    system("PAUSE");

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);
    iter = v.begin();
    while (iter != v.end()) {
        std::cout << *iter << " ";
        ++iter;
    }
    std::cout << std::endl << "Shuffle all elements randomly in vector" << std::endl;
    system("PAUSE");

    iter = v.begin();
    while (iter != v.end()) {
        if (*iter > 50) {
            v.erase(iter);
            iter = v.begin();
        }
        iter++;
    }

    iter = v.begin();
    while (iter != v.end()) {
        std::cout << *iter << " ";
        ++iter;
    }
    std::cout << std::endl << "Erase all elements greater than 50 in vector" << std::endl;
    system("PAUSE");

    int vsize;
    vsize = v.size();
    std::cout << vsize << std::endl;

    iter = v.begin();
    if (vsize % 2 == 1) {
        v.pop_back();
        while (iter != v.end()) {
            std::cout << *iter << " ";
            ++iter;
        }
    }
    else
    {
        for (std::vector<int>::reverse_iterator i = v.rbegin();
            i != v.rend(); ++i) {
            std::cout << *i << " ";
        }
    }
    std::cout << std::endl << "Erase last element if vector is Odd and print all vector in reverse if not Odd" << std::endl;
    system("PAUSE");

    v.clear();
    std::cout << std::endl << "Vector cleared." << std::endl;
    system("PAUSE");

    //Block List Tasks

    std::list<int> l;
    int lval;
    for (int i = 0; i < 5; i++) {
        lval = rand() % +20;
        l.push_back(lval);
    }
    auto itera = l.begin();
    while (itera != l.end()) {
        std::advance(itera, 1);
        if (itera == l.end())
            break;
        else
            std::cout << *itera << " ";
    }
    std::cout << std::endl << "Added 5 new elements to end of the list" << std::endl;

    itera = l.begin();
    std::advance(itera, 1);
    std::cout << *itera;
    std::cout << std::endl << "Accessed first element in list" << std::endl;
    system("PAUSE");

    for (int i = 0; i < 2; i++) {
        lval = rand() % +20;
        l.push_front(lval);
    }

    itera = l.begin();
    while (itera != l.end()) {
        std::advance(itera, 1);
        if (itera == l.end())
            break;
        else
            std::cout << *itera << " ";
    }
    std::cout << std::endl << "Added 2 new elements to start of the list" << std::endl;
    system("PAUSE");

    itera = l.begin();
    std::advance(itera, 4);
    l.erase(itera);

    itera = l.begin();
    while (itera != l.end()) {
        std::advance(itera, 1);
        if (itera == l.end())
            break;
        else
            std::cout << *itera << " ";
    }

    std::cout << std::endl << "Erase 4th element of list" << std::endl;
    system("PAUSE");

    itera = l.begin();
    int lpos;
    lval = rand() % +20;
    for (int i = 0; i < 3; i++) {
        itera = l.begin();
        lpos = rand() % +6;
        std::advance(itera, lpos);
        l.insert(itera, lval);
    }

    itera = l.begin();
    while (itera != l.end()) {
        std::advance(itera, 1);
        if (itera == l.end())
            break;
        else
            std::cout << *itera << " ";
    }
    std::cout << std::endl << "Add " << lval << " random value to 3 random spots in list" << std::endl;
    system("PAUSE");

    l.pop_back();
    itera = l.begin();
    while (itera != l.end()) {
        std::advance(itera, 1);
        if (itera == l.end())
            break;
        else
            std::cout << *itera << " ";
    }

    std::cout << std::endl << "Remove last element in list" << std::endl;
    system("PAUSE");

    l.pop_front();
    itera = l.begin();
    while (itera != l.end()) {
        std::advance(itera, 1);
        if (itera == l.end())
            break;
        else
            std::cout << *itera << " ";
    }

    std::cout << std::endl << "Remove first element in list" << std::endl;
    system("PAUSE");

    lval = rand() % +20;
    itera = l.begin();
    std::advance(itera, 4);
    l.insert(itera, 2, lval);

    itera = l.begin();
    while (itera != l.end()) {
        std::advance(itera, 1);
        if (itera == l.end())
            break;
        else
            std::cout << *itera << " ";
    }

    std::cout << std::endl << "Insert in the middle of list 2 elements of " << lval << std::endl;
    system("PAUSE");

    l.sort();
    l.unique();

    itera = l.begin();
    while (itera != l.end()) {
        std::advance(itera, 1);
        if (itera == l.end())
            break;
        else
            std::cout << *itera << " ";
    }

    std::cout << std::endl << "Remove duplicate values in list" << std::endl;
    system("PAUSE");

    l.clear();
    if (l.empty() == true) {
        std::cout << "List is cleared and empty." << std::endl;
    }
    system("PAUSE");

    //Block Stack Tasks

    bool exit = false;
    int action;
    int value;
    std::stack<int> s;
    std::stack<int> s1(s);

    while (exit != true) {
        s1 = s;
        int element = 0;
        while (s1.empty() != true) {
            std::cout << "| " << s1.top() << " |" << std::endl;
            s1.pop();
        }
        if (s1.empty() == true)
            std::cout << "-------" << std::endl;
        std::cout << "Enter number of action:" << std::endl << "1: Add element into stack" << std::endl << "2: Get top element and remove from stack"
            << std::endl << "3: Print elements" << std::endl << "4: Clear stack" << std::endl << "5: Exit" << std::endl;
        std::cin >> action;
        switch (action)
        {
        case 1:
            std::cout << "Enter value: ";
            std::cin >> value;
            s.push(value);
            break;
        case 2:
            element = s.top();
            std::cout << "Your value " << element << " " << std::endl;
            s.pop();
            std::cout << "Element " << element << " Was removed from stack" << std::endl;
            break;
        case 3:
            while (s1.empty() != true) {
                std::cout << "| " << s1.top() << " |" << std::endl;
                s1.pop();
            }
            if (s1.empty() == true)
                std::cout << "-------" << std::endl;
            break;
        case 4:
            while (!s.empty())
                s.pop();
            break;
        case 5:
            exit = true;
            break;
        }
    }


    //Block Set Tasks

    std::set<int> mn1;
    std::set<int> mn2;
    std::vector<int> res;

    bool mnexit = false;
    int mnaction;
    int mnval;
    bool choice;

    while (mnexit != true) {
        std::cout << "Enter number of action:" << std::endl << "1: Add element into set A" << std::endl << "2: Add element into set B"
            << std::endl << "3: Intersection of A and B" << std::endl << "4: Union of A and B" << std::endl << "5: Difference of A and B" <<
            std::endl << "6: Addition of A and B" << std::endl;
        std::cin >> mnaction;
        switch (mnaction)
        {
        case 1:
            std::cout << "Enter a value:";
            std::cin >> mnval;
            mn1.insert(mnval);
            for (const auto& i : mn1) std::cout << i << " ";
            std::cout << std::endl;
            break;
        case 2:
            std::cout << "Enter a value:";
            std::cin >> mnval;
            mn2.insert(mnval);
            for (const auto& i : mn2) std::cout << i << " ";
            std::cout << std::endl;
            break;
        case 3:
            res.clear();
            std::set_intersection(
                mn1.begin(), mn1.end(),
                mn2.begin(), mn2.end(),
                std::back_inserter(res));

            std::cout << "Intersection values of A and B: ";
            for (const auto& i : res) std::cout << i << " ";
            std::cout << std::endl;
            break;
        case 4:
            res.clear();
            std::set_union(
                mn1.begin(), mn1.end(),
                mn2.begin(), mn2.end(),
                std::back_inserter(res));

            std::cout << "Union values of A and B: ";
            for (const auto& i : res) std::cout << i << " ";
            std::cout << std::endl;
            break;
        case 5:
            res.clear();
            std::set_difference(
                mn1.begin(), mn1.end(),
                mn2.begin(), mn2.end(),
                std::back_inserter(res));

            std::cout << "Difference values of A and B: ";
            for (const auto& i : res) std::cout << i << " ";
            std::cout << std::endl;
            break;
        case 6:
            res.clear();
            std::cout << "Addition of A (0) or B(1): ";
            std::cin >> choice;
            if (choice == 0) {
                std::set_difference(
                    mn2.begin(), mn2.end(),
                    mn1.begin(), mn1.end(),
                    std::back_inserter(res));

                std::cout << "Addition of A: ";
                for (const auto& i : res) std::cout << i << " ";
                std::cout << std::endl;
            }
            if (choice == 1) {
                std::set_difference(
                    mn1.begin(), mn1.end(),
                    mn2.begin(), mn2.end(),
                    std::back_inserter(res));

                std::cout << "Addition of B: ";
                for (const auto& i : res) std::cout << i << " ";
                std::cout << std::endl;
            }
            break;
        }
    }
    return 0;
}
