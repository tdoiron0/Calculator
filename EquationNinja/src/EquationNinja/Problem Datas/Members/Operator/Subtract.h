#pragma once
#include "Operator.h"

namespace ENlib {
	class EN_API Subtract : public Operator {
	public: 
		Subtract(); 
		Subtract(Member* oper1, Member* oper2);
		~Subtract(); 

		Member* process(Member* oper1, Member* oper2) override;
		std::string getString() override;

		Member* add(Member* obj) override;
		Member* sub(Member* obj) override;
		Member* mult(Member* obj) override;
		Member* divi(Member* obj) override;
		bool equal(Member* obj, bool abstractIdentity = true) override;
	};
}