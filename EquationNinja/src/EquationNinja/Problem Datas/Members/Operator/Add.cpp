#include "Add.h"

#include "Subtract.h"

namespace ENlib {
	Add::Add() {
		m_Category = MEM_OPERATOR;
		m_Type = OPER_ADDITION;
	}
	Add::Add(Member* oper1, Member* oper2) {
		m_Category = MEM_OPERATOR;
		m_Type = OPER_ADDITION;

		m_Operands.push_back(std::shared_ptr<Member>(oper1));
		m_Operands.push_back(std::shared_ptr<Member>(oper2));
	}
	Add::~Add() {

	}

	//Convert and do associated process (in this case add)
	Member* Add::process(Member* oper1, Member* oper2) {
		if (convertable(oper1->getTypeMember(), oper2->getTypeMember())) {
			Member* obj1 = convert(oper1, oper2->getTypeMember());
			Member* obj2 = convert(oper2, obj1->getTypeMember());

			return obj1->add(obj2);
		}
		else {
			return new Add(oper1, oper2);
		}
	}
	std::string Add::getString() {
		std::string as_str = std::string("[ADD](");
		for (int i = 0; i < m_Operands.size(); i++) {
			as_str += m_Operands[i]->getString();
			if (m_Operands.size() - 1 > i)
				as_str += '+';
		}
		as_str += ")";

		return as_str;
	}

	Member* Add::add(Member* obj) {
		Add* as_add = (Add*)obj;
		Add* result = new Add();

		int index = 0; 
		for (int i = 0; i < m_Operands.size(); i++) {
			index = as_add->findCompatible(m_Operands[i].get()); 

			if (index != -1) {
				Member* obj1 = convert(m_Operands[i].get(), as_add->m_Operands[index]->getTypeMember());
				Member* obj2 = convert(as_add->m_Operands[index].get(), obj1->getTypeMember());

				result->apply(obj1->add(obj2));
			}
			else {
				result->apply(m_Operands[i].get());
			}
		}

		for (int i = 0; i < as_add->m_Operands.size(); i++) {
			index = findCompatible(as_add->m_Operands[i].get()); 
			if (index == -1) {
				result->apply(as_add->m_Operands[i].get());
			}
		}

		return result; 
	}
	Member* Add::sub(Member* obj) {
		Add* as_add = (Add*)obj;
		Subtract* result = new Subtract();

		result->apply(m_Operands);
		result->apply(as_add->m_Operands);

		return result->value();
	}
	Member* Add::mult(Member* obj) {
		return nullptr;
	}
	Member* Add::divi(Member* obj) {
		return nullptr;
	}
	bool Add::equal(Member* obj, bool abstractIdentity) {
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