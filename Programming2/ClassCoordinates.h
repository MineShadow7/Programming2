#pragma once
#include <iostream>

class Coordinates {
public:
	int first, second;
	Coordinates() {
		first = 0;
		second = 0;
	}

	Coordinates(int _first, int _second) {
		first = _first;
		second = _second;
	}
	void print();

	Coordinates& operator+(const Coordinates& n) {
		Coordinates res;
		res.first = first + n.first;
		res.second = second + n.second;
		return res;
	}

	Coordinates& operator=(const Coordinates& n) {
		if (this == &n) {
			return *this;
		}
		first = n.first;
		second = n.second;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, const Coordinates& r);
};