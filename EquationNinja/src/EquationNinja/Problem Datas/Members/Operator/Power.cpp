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
		return this;
	}
	Member* Power::sub(Member* obj) {
		return nullptr;
	}
	Member* Power::mult(Member* obj) {
		m_Operands[1] = Add(m_Operands[1], ((Power*)obj)->m_Operands[1]).value();
		return this;
	}
	Member* Power::divi(Member* obj) {
		return nullptr;
	}

	bool Power::compatible(Member* obj, MemberType operation) {
		if (obj->getTypeMember() == m_Type) {
			Power* as_pow = (Power*)obj;

			if (operation == OPER_ADDITION) {
				return m_Operands[0]->equal(as_pow->m_Operands[0]) && m_Operands[1]->equal(as_pow->m_Operands[1]);
			}
			else {
				return m_Operands[0]->equal(as_pow->m_Operands[0]) && m_Operands[1]->compatible(as_pow->m_Operands[1], operation);
			}
		}

		return false; 
	}
	bool Power::equal(Member* obj) {
		if (obj->getTypeMember() == m_Type) {
			Power* as_pow = (Power*)obj;

			if (m_Operands[0]->equal(as_pow->m_Operands[0]) && m_Operands[1]->equal(as_pow->m_Operands[1])) {
				return true;
			}
		}

		return false;
	}
}