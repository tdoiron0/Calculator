#include "QuadraticCase.h"

namespace ENlib {
	Quadratic::Quadratic() {

	}

	Quadratic::~Quadratic() {

	}

	Member* Quadratic::get() {
		if (instruction == INSTRUCTION_FIND) {
			return findCompatible();
		}
	}

	Member* Quadratic::findCompatible() {

	}

	Member* Quadratic::factor() {

	}

	Member* Quadratic::factorGroup() {

	}
}