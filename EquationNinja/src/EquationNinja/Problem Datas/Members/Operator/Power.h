#pragma once
#include "Operator.h"

namespace ENlib {
	class EN_API Power : public Operator {
	public: 
		Power();
		Power(Member* pow, Member* base);
		~Power(); 

		Member* value() override;
		std::string getString() override; 

		Member* add(Member* obj) override;
		Member* sub(Member* obj) override;
		Member* mult(Member* obj) override;
		Member* divi(Member* obj) override;
		bool compatible(Member* obj, bool abstractIdentity = true) override;
	};
}