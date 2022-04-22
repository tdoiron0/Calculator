#include "Divide.h"

namespace ENlib {
	Divide::Divide() {
		m_Category = MEM_OPERATOR;
		m_Type = OPER_DIVIDE;
	}
	Divide::Divide(Member* oper1, Member* oper2) {
		m_Category = MEM_OPERATOR;
		m_Type = OPER_DIVIDE;

		m_Operands.push_back(oper1);
		m_Operands.push_back(oper2);
	}
	Divide::~Divide() {}

	Member* Divide::process(Member* oper1, Member* oper2) {
		if (oper1->getTypeMember() == oper2->getTypeMember()) {
			return oper1->divi(oper2);
		}
		return new Divide(oper1, oper2);
	}
	std::string Divide::getString() {
		std::string as_str = std::string("[DIVIDE](");
		for (int i = 0; i < m_Operands.size(); i++) {
			as_str += m_Operands[i]->getString();
			if (m_Operands.size() - 1 > i)
				as_str += '/';
		}
		as_str += ")";

		return as_str;
	}

	Member* Divide::add(Member* obj) {
		return nullptr;
	}
	Member* Divide::sub(Member* obj) {
		return nullptr;
	}
	Member* Divide::mult(Member* obj) {
		return nullptr;
	}
	Member* Divide::divi(Member* obj) {
		return nullptr;
	}
	bool Divide::compatible(Member* obj, bool abstractIdentity = true) {
		if (obj->getTypeMember() == m_Type) {
			if (abstractIdentity) {
				Operator* as_oper = (Operator*)obj;

				return m_Operands[1]->compatible(as_oper->m_Operands[1], false);
			}
			else {
				Operator* as_oper = (Operator*)obj;

				return m_Operands[0]->compatible(as_oper->m_Operands[0], false) && m_Operands[1]->compatible(as_oper->m_Operands[1], false);;
			}
		}
		else {
			return false; 
		}
	}
}