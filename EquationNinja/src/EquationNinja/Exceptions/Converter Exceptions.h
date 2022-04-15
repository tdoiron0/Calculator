#pragma once
#include "Exception.h"

namespace ENlib {
	class EN_API ConvIncompat : public Exception {
	public: 
		ConvIncompat() {
			m_Type = CONV_INCOMPAT;
		}
		ConvIncompat(std::string message) {
			m_Type = CONV_INCOMPAT;
			m_Message = message;
		}
		~ConvIncompat() {}
	};
}