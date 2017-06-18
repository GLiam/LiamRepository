#include "unittest.h"
#include <iostream>
#include "Interpelation.h"

//using namespace Interp;

int main() {

	if (runUnitTests() == false) {
		std::cout << "Unit test failed!" << std::endl;
		return -1;
	}
	std::cout << "All tests passed successfully." << std::endl;

	//float v = Linear(5, 20, 0.25f);

	system("pause");
	return 0;
}