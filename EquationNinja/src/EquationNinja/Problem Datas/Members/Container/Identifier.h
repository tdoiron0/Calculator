#pragma once
#include "Container.h"

namespace ENlib {
	class EN_API Ident : public Container {
	public: 
		unsigned int m_ID = NULL;
		Member* linkedValue = nullptr;

		Ident();
		Ident(std::string name);
		Ident(unsigned int id);
		~Ident();

		Member* value() override;
		std::string getString() override;

		Member* add(Member* obj) override;
		Member* sub(Member* obj) override;
		Member* mult(Member* obj) override;
		Member* divi(Member* obj) override;
		bool compatible(Member* obj, MemberType operation) override;
		bool equal(Member* obj) override;
	};
}