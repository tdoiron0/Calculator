#include "Add.h"

#include "../Container/Number.h"

#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"

namespace ENlib {
	Add::Add() {
		m_Category = MEM_OPERATOR;
		m_Type = OPER_ADDITION;
	}
	Add::Add(Member* oper1, Member* oper2) {
		m_Category = MEM_OPERATOR;
		m_Type = OPER_ADDITION;

		m_Operands.push_back(oper1);
		m_Operands.push_back(oper2);
	}
	Add::~Add() {

	}

	//Convert and do associated process (in this case add)
	Member* Add::process(Member* oper1, Member* oper2) {
		return oper1->add(oper2);
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

		result->apply(m_Operands);
		result->apply(as_add->m_Operands);

		return result->value();
	}
	Member* Add::sub(Member* obj) {
		return nullptr;
	}
	Member* Add::mult(Member* obj) {
		Add* as_add = (Add*)obj;
		Add* result = new Add();

		for each (Member* oper1 in m_Operands) {
			for each (Member* oper2 in as_add->m_Operands) {
				result->apply(Mult(oper1, oper2).value());
			}
		}

		return result->value();
	}
	Member* Add::divi(Member* obj) {
		return nullptr;
	}
	bool Add::compatible(Member* obj, MemberType operation) {
		return obj->getTypeMember() == m_Type;
	}
	bool Add::equal(Member* obj) {
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