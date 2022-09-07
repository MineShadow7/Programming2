#include <iostream>
#include "ClassCoordinates.h"

  // Add a comment to commit changes.
  // No need to pay attention to these comments.
int main() {
	std::cout << "Hello World" << std::endl;
	Coordinates A(5, 4), B(1, 6), C;
	C = B + A;
	std::cout << C;
	return 0;
}