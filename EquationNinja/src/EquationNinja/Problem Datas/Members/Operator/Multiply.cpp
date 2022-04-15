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

		m_Operands.push_back(std::shared_ptr<Member>(oper1));
		m_Operands.push_back(std::shared_ptr<Member>(oper2));
	}
	Mult::~Mult() {

	}

	Member* Mult::process(Member* oper1, Member* oper2) {
		if (oper1->getTypeMember() == oper2->getTypeMember()) {
			return oper1->mult(oper2);
		}
		return new Mult(oper1, oper2);
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

		if (equal(as_mult)) {
			Mult* result = new Mult();

			int index = 0;
			for (int i = 0; i < m_Operands.size(); i++) {
				index = as_mult->find(m_Operands[i].get());
				if (index != -1 && m_Operands[i]->getTypeMember() == NUM_REAL) {
					result->apply(m_Operands[i]->add(as_mult->m_Operands[index].get()));
				}
				else {
					result->apply(m_Operands[i].get());
				}
			}

			return result;
		}
		else {
			return new Add(this, as_mult);
		}
	}
	Member* Mult::sub(Member* obj) {
		Member* obj_simp = obj->value();

		return nullptr;
	}
	Member* Mult::mult(Member* obj) {
		Member* obj_simp = obj->value();

		return nullptr;
	}
	Member* Mult::divi(Member* obj) {
		return nullptr;
	}
	bool Mult::equal(Member* obj, bool abstractIdentity) {
		if (obj->getTypeMember() == m_Type) {
			if (abstractIdentity) {
				Operator* as_oper = (Operator*)obj;

				for (int i = 0; i < m_Operands.size(); i++) {
					if (m_Operands[i]->getTypeMember() != NUM_REAL) {
						if (as_oper->find(m_Operands[i].get(), abstractIdentity) == -1) {
							return false;
						}
					}
				}

				return true;
			}
			else {
				Operator* as_oper = (Operator*)obj;

				for (int i = 0; i < m_Operands.size(); i++) {
					if (as_oper->find(m_Operands[i].get(), abstractIdentity) == -1) {
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