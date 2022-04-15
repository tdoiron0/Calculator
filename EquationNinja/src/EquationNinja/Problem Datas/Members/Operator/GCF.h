#pragma once
#include "Operator.h"

namespace ENlib {
	class EN_API GCF : public Operator {
	public: 
		GCF(); 
		GCF(Member* oper1, Member* oper2);
		~GCF(); 

		Member* value() override;
		std::string getString() override;
	};
}