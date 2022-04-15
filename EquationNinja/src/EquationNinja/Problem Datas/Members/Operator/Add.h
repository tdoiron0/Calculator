#pragma once
#include "Operator.h"
#include "EquationNinja/Debug/Log.h"

#include <string>
#include <vector>

namespace ENlib {
	class EN_API Add : public Operator {
	public: 
		Add(); 
		Add(Member* oper1, Member* oper2);
		~Add(); 

		Member* process(Member* oper1, Member* oper2) override; 
		std::string getString() override; 

		Member* add(Member* obj) override;
		Member* sub(Member* obj) override; 
		Member* mult(Member* obj) override;
		Member* divi(Member* obj) override; 
		bool equal(Member* obj, bool abstractIdentity = true) override;
	private: 

	};
}