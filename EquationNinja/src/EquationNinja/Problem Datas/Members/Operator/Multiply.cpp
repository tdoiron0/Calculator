#include "Multiply.h"

#include "Add.h"

namespace ENlib {
	Mult::Mult() {
		m_Category = MEM_OPERATOR; 
		m_Type = OPER_MULTIPLY;
	}
	Mult::Mult(Member* oper1, Member* oper2) {
		m_Category = MEM_OPERATOR;
		m_Type = OPER_MULTIPLY;

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

		int index = find(NUM_REAL);
		result->apply(m_Operands[index]->add(as_mult->m_Operands[as_mult->find(NUM_REAL)]));

		for (int i = 0; i < m_Operands.size(); i++) {
			if (!m_Operands[i]->compatible(m_Operands[index], true)) {
				result->apply(m_Operands[i]);
			}
		}

		return result;
	}
	Member* Mult::sub(Member* obj) {
		return nullptr;
	}
	Member* Mult::mult(Member* obj) {
		Mult* as_mult = (Mult*)obj;
		Mult* result = new Mult();

		int index = 0;
		for each (Member* oper in m_Operands) {
			if (oper->getTypeMember() != ID_VAR) {
				index = as_mult->findCompatible(oper);
				result->apply(Mult(oper, as_mult->m_Operands[index]).value());
			}
			else {
				result->apply(oper);
			}
		}

		return result; 
	}
	Member* Mult::divi(Member* obj) {
		return nullptr;
	}
	bool Mult::compatible(Member* obj, bool abstractIdentity) {
		if (obj->getTypeMember() == m_Type) {
			if (abstractIdentity) {
				Operator* as_oper = (Operator*)obj;

				for (int i = 0; i < m_Operands.size(); i++) {
					if (m_Operands[i]->getTypeMember() != NUM_REAL) {
						if (as_oper->find(m_Operands[i], abstractIdentity) == -1) {
							return false;
						}
					}
				}

				return true;
			}
			else {
				Operator* as_oper = (Operator*)obj;

				for (int i = 0; i < m_Operands.size(); i++) {
					if (as_oper->find(m_Operands[i], abstractIdentity) == -1) {
						return false;
					}
				}

				return true;
			}
		}
		else {
			return false;
		}
	}
}