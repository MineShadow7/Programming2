#include "ClassCoordinates.h"

void Coordinates::print() {
	std::cout << first << std::endl;
	std::cout << second << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Coordinates& r)
{
	out << "(" << r.first << ", " << r.second << ")" << std::endl;
	return out;
}
