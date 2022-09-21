// Copyright 2022 Karagodin Andrey Romanovich. All rights reserved.
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <functional>

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
		val = -100 + rand() % + 201;
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
	iter = v.begin();
	if (std::find_if(v.begin(), v.end(), isGreaterThan())
	return 0;
}
