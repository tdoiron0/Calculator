#pragma once
#include "../Core.h"

#include <string>

namespace ENlib {
	enum ExcType {
		CONV_INCOMPAT
	};
	class EN_API Exception {
	public: 
		Exception() {}
		~Exception() {}

		ExcType gTypeE() { return m_Type; }
		std::string getString() { return m_Message; }
	protected:
		ExcType m_Type;
		std::string m_Message;
	};
}