#pragma once
#include "../Core.h"
#include "Members/ObjectFac.h"
#include "EquationNinja/Debug/Log.h"
#include "Members/MemberBase.h"

#include <iostream>
#include <vector>
#include <string>
#include <memory>

namespace ENlib {
	class EN_API Problem {
	public:
		ObjectFac factory;
		std::vector<Member*> m_Data;

		Problem();
		Problem(std::string* filepath);
		~Problem();

		void loadFile(std::string* filepath);
		Member* result();
	private: 

	};
}