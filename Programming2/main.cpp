// Copyright 2022 Karagodin Andrey Romanovich. All rights reserved.
#include <iostream>
#include <vector>

enum status {
	Private,
	Public,
	Protected
};

int main() {
	std::vector<std::pair<int, float>> classTest;
	for (int i = 0; i < 10; i++) {
		std::pair<int, float> newpair;
		newpair.first = rand() % 3;
		newpair.second = rand() % 10;
		classTest.push_back(newpair);
	}

	for (std::vector<std::pair<int, float>>::iterator it = begin(classTest); it != end(classTest); ++it) {
		std::cout << (*it).first << " " << (*it).second << std::endl;
	}

	return 0;
}
