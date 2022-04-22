#include "Power.h"

#include "../Container/Number.h"

#include "Add.h"
#include "Multiply.h"

namespace ENlib {
	Power::Power() {
		m_Category = MEM_OPERATOR; 
		m_Type = OPER_POWER;
	}
	Power::Power(Member* base, Member* pow) {
		m_Category = MEM_OPERATOR;
		m_Type = OPER_POWER;

		m_Operands.push_back(base);
		m_Operands.push_back(pow);
	}
	Power::~Power() {

	}

	Member* Power::value() {
		int count = ((Number*)(m_Operands[1]))->m_Value[0];
		Member* result = m_Operands[0];

		for (int i = 1; i < count; i++) {
			result = result->mult(m_Operands[0]);
		}

		return result; 
	}
	std::string Power::getString() {
		std::string as_str = std::string("");
		std::string base = m_Operands[0]->getString();
		std::string pow = m_Operands[1]->getString();

		as_str += "[POW](" + base;
		as_str += "^" + pow + ")";

		return as_str;
	}

	Member* Power::add(Member* obj) {

	}
	Member* Power::sub(Member* obj) {
		return nullptr;
	}
	Member* Power::mult(Member* obj) {

	}
	Member* Power::divi(Member* obj) {
		return nullptr;
	}
	bool Power::compatible(Member* obj, bool abstractIdentity) {
		if (obj->getTypeMember() == m_Type) {
			Operator* as_oper = (Operator*)obj;

			if (m_Operands[0]->compatible(as_oper->m_Operands[0]) && m_Operands[1]->compatible(as_oper->m_Operands[1])) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
}