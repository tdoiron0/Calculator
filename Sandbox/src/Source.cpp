#include "EquationNinja.h"

#include <iostream>

int main() {
	std::string fileSource("C:/VS/C++/Projects/Calculator++/v0.4/Sandbox/res/Test Equation2.xml");
	ENlib::Problem* obj = ENlib::Alloc(&fileSource);
	obj->result()->print();
	ENlib::Free();

	std::cin.get();
}