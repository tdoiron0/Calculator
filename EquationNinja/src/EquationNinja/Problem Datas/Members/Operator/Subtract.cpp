#include "Subtract.h"

namespace ENlib {
	Subtract::Subtract() {
		m_Category = MEM_OPERATOR;
		m_Type = OPER_SUBTRACTION;
	}
	Subtract::Subtract(Member* oper1, Member* oper2) {
		m_Category = MEM_OPERATOR;
		m_Type = OPER_SUBTRACTION;

		m_Operands.push_back(oper1);
		m_Operands.push_back(oper2);
	}
	Subtract::~Subtract() {}

	Member* Subtract::process(Member* oper1, Member* oper2) {
		return oper1->sub(oper2);
	}
	std::string Subtract::getString() {
		std::string as_str = std::string("[SUBTRACT](");
		for (int i = 0; i < m_Operands.size(); i++) {
			as_str += m_Operands[i]->getString();
			if (m_Operands.size() - 1 > i)
				as_str += '-';
		}
		as_str += ")";

		return as_str;
	}

	Member* Subtract::add(Member* obj) {

	}
	Member* Subtract::sub(Member* obj) {

	}
	Member* Subtract::mult(Member* obj) {

	}
	Member* Subtract::divi(Member* obj) {

	}
	bool Subtract::equal(Member* obj, bool abstractIdentity) {
		if (obj->getTypeMember() == m_Type) {
			if (abstractIdentity) {
				Operator* as_oper = (Operator*)obj;

				if (as_oper->m_Operands.size() == m_Operands.size()) {
					int index = 0;
					for (int i = 0; i < m_Operands.size(); i++) {
						if (m_Operands[i]->getTypeMember() != NUM_REAL) {
							index = as_oper->find(m_Operands[i], abstractIdentity);
							if (index != i) {
								return false;
							}
						}
						else {
							index = as_oper->find(NUM_REAL);
							if (index != i) {
								return false;
							}
						}
					}

					return true;
				}
				else {
					return false;
				}
			}
			else {
				Operator* as_oper = (Operator*)obj;

				if (as_oper->m_Operands.size() == m_Operands.size()) {
					int index = 0;
					for (int i = 0; i < m_Operands.size(); i++) {
						index = as_oper->find(m_Operands[i], abstractIdentity);
						if (index != i) {
							return false;
						}
					}

					return true;
				}
				else {
					return false;
				}
			}
		}
		else {
			return false; 
		}
	}
}