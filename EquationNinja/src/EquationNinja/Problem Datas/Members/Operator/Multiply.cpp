#include "Multiply.h"

#include "Add.h"

namespace ENlib {
	Mult::Mult() {
		m_Category = MEM_OPERATOR; 
		m_Type = OPER_MULTIPLICATION;
	}
	Mult::Mult(Member* oper1, Member* oper2) {
		m_Category = MEM_OPERATOR;
		m_Type = OPER_MULTIPLICATION;

		m_Operands.push_back(oper1);
		m_Operands.push_back(oper2);
	}
	Mult::~Mult() {

	}

	Member* Mult::process(Member* oper1, Member* oper2) {
		return oper1->mult(oper2);
	}
	std::string Mult::getString() {
		std::string as_str = std::string("[MULTIPLY](");
		for (int i = 0; i < m_Operands.size(); i++) {
			as_str += m_Operands[i]->getString();
			if (m_Operands.size() - 1 > i)
				as_str += '*';
		}
		as_str += ")";

		return as_str;
	}

	Member* Mult::add(Member* obj) {
		Mult* as_mult = (Mult*)obj;
		Mult* result = new Mult();

		int index = 0; 
		for each (Member * oper1 in m_Operands) {
			index = as_mult->findConvertable(oper1, OPER_ADDITION);

			result->apply(oper1->add(as_mult->m_Operands[index]));
		}

		return result;
	}
	Member* Mult::sub(Member* obj) {
		return nullptr;
	}
	Member* Mult::mult(Member* obj) {
		Mult* as_mult = (Mult*)obj;
		Mult* result = new Mult();

		result->apply(m_Operands);
		result->apply(as_mult->m_Operands);

		return result->value();
	}
	Member* Mult::divi(Member* obj) {
		return nullptr;
	}
	bool Mult::compatible(Member* obj, MemberType operation) {
		if (obj->getTypeMember() == m_Type) {
			Operator* as_oper = (Operator*)obj;

			for (int i = 0; i < m_Operands.size(); i++) {
				if (m_Operands[i]->getTypeMember() != NUM_REAL) {
					if (as_oper->findCompatible(m_Operands[i], operation) == -1) {
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
	bool Mult::equal(Member* obj) {
		if (obj->getTypeMember() == m_Type) {
			Add* as_add = (Add*)obj;

			for (int i = 0; i < m_Operands.size(); i++) {
				if (as_add->findEqual(m_Operands[i]) == -1) {
					return false;
				}
			}

			return true;
		}

		return false;
	}
}