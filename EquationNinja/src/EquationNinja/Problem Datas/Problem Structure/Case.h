#pragma once
#include "../../Core.h"
#include "../Members/MemberBase.h"

namespace ENlib {
	enum InstructionType {
		INSTRUCTION_FIND
	};

	class EN_API Case {
	public: 
		Case() {}
		~Case() {}

		virtual Member* get() = 0;
	protected: 
		Member* problemSource; 
		InstructionType instruction;
	};
}