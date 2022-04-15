#pragma once
#include "../Case.h" 

namespace ENlib {
	//To implement need Number, Identifier, Add, Subtract, Multiply, Power, and Equal first

	class EN_API Quadratic : public Case {
	public: 
		Quadratic();
		~Quadratic();

		Member* get() override;
		Member* find(); 

		Member* factor();
		Member* factorGroup();
	};

	struct Term {
		Member* value; 
	};

	// operationSeries encoding:
	// 0 - addition 
	// 1 - subtraction 
	// 2 - multiplication 
	// 3 - division 
	struct Polynomial {
		std::vector<unsigned int> operatorSeries;
		std::vector<Term> terms;
	};
}