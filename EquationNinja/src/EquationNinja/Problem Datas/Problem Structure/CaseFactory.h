#pragma once
#include "../../Core.h"
#include "../Members/MemberBase.h"
#include "Case.h"

namespace ENlib {
	class EN_API CaseFactory {
	public: 
		CaseFactory(); 
		~CaseFactory(); 

		Case* create(Member* source);
	};
}