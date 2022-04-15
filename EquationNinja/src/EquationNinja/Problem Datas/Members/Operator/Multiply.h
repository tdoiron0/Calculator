#pragma once
#include "Operator.h"

namespace ENlib {
	class EN_API Mult : public Operator {
	public: 
		Mult();
		Mult(Member* oper1, Member* oper2);
		~Mult();

		Member* process(Member* oper1, Member* oper2) override;
		std::string getString() override;

		Member* add(Member* obj) override;
		Member* sub(Member* obj) override;
		Member* mult(Member* obj) override;
		Member* divi(Member* obj) override;
		bool equal(Member* obj, bool abstractIdentity = true) override;
	};
}