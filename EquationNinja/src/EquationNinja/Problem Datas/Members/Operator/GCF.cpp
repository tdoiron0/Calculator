#include "GCF.h"

namespace ENlib {
	GCF::GCF() {
		m_Category = MEM_OPERATOR;
		m_Type = OPER_GCF;
	}
	GCF::GCF(Member* oper1, Member* oper2) {
		m_Category = MEM_OPERATOR;
		m_Type = OPER_GCF;

		m_Operands.push_back(std::shared_ptr<Member>(oper1));
		m_Operands.push_back(std::shared_ptr<Member>(oper2));
	}
	GCF::~GCF() {}

	Member* GCF::value() {

	}
	std::string GCF::getString() {
		std::string as_str = std::string("[GCF](");
		for (int i = 0; i < m_Operands.size(); i++) {
			as_str += m_Operands[i]->getString();
			if (m_Operands.size() - 1 > i)
				as_str += ", ";
		}
		as_str += ")";

		return as_str;
	}
}