#pragma once
#include "Container.h"
#include "EquationNinja/Debug/Log.h"

#include <vector>
#include <memory>

namespace ENlib {
	class EN_API Number : public Container {
	public: 
		double base = 10;
		std::vector<double> m_Value;

		Number(); 
		Number(double value); 
		~Number(); 

		Member* value() override;
		std::string getString() override; 

		Member* add(Member* obj) override;
		Member* sub(Member* obj) override;
		Member* mult(Member* obj) override;
		Member* divi(Member* obj) override;
		bool equal(Member* obj, bool abstractIdentity = true) override;
	};
}