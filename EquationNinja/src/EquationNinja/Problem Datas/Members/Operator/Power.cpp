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

		m_Operands.push_back(std::shared_ptr<Member>(base));
		m_Operands.push_back(std::shared_ptr<Member>(pow));
	}
	Power::~Power() {

	}

	Member* Power::value() {
		int count = ((Number*)(m_Operands[1].get()))->m_Value[0];
		Member* result = m_Operands[0].get();

		for (int i = 1; i < count; i++) {
			result = result->mult(m_Operands[0].get());
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
		Member* obj_simp = obj->value(); 

		if (equal(obj_simp)) {
			return new Mult(new Number(2), this);
		}
		else {
			return new Add(this, obj_simp);
		}
	}
	Member* Power::sub(Member* obj) {
		Member* obj_simp = obj->value();

		if (equal(obj_simp)) {
			return new Number(0);
		}
		else {

		}
	}
	Member* Power::mult(Member* obj) {

	}
	Member* Power::divi(Member* obj) {

	}
	bool Power::equal(Member* obj, bool abstractIdentity) {
		if (obj->getTypeMember() == m_Type) {
			Operator* as_oper = (Operator*)obj;

			if (m_Operands[0]->equal(as_oper->m_Operands[0].get()) && m_Operands[1]->equal(as_oper->m_Operands[1].get())) {
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