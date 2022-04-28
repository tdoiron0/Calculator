#pragma once
#include "../MemberBase.h"
#include "../Conversions.h"

#include <vector>

namespace ENlib {
	class EN_API Operator : public Member {
	public: 
		std::vector<Member*> m_Operands;

		Operator() {}
		~Operator() {}

		int findConvertable(Member* obj, MemberType operation) {
			for (int i = 0; i < m_Operands.size(); i++) {
				if (m_Operands[i]->compatible(obj, operation)) {
					return i;
				}
				else if (convertable(m_Operands[i]->getTypeMember(), obj->getTypeMember())) {
					Member* temp = convert(m_Operands[i], obj->getTypeMember()); 
					if (obj->compatible(temp, operation)) {
						return i;
					}
				}
				else if (convertable(obj->getTypeMember(), m_Operands[i]->getTypeMember())) {
					Member* temp = convert(obj, m_Operands[i]->getTypeMember());
					if (m_Operands[i]->compatible(temp, operation)) {
						return i;
					}
				}
			}

			return -1; 
		}
		int findEqual(Member* obj) {
			for (int i = 0; i < m_Operands.size(); i++) {
				if (obj->equal(m_Operands[i])) {
					return i;
				}
			}

			return -1; 
		}

		Member* value() override {
			int index = 0;

			for (int i = 0; i < m_Operands.size(); i++) {
				index = findConvertable(m_Operands[i], this->m_Type);

				if (index != -1) {
					Member* obj1 = convert(m_Operands[i], m_Operands[index]->getTypeMember());
					Member* obj2 = convert(m_Operands[index], m_Operands[i]->getTypeMember());

					m_Operands[i] = process(obj1, obj2);
					m_Operands.erase(m_Operands.begin() + index);
				}
			}

			if (m_Operands.size() == 1) {
				return m_Operands[0];
			}
			else {
				return this;
			}
		}

		virtual Member* process(Member* oper1, Member* oper2) { return nullptr; }
		virtual void apply(Member* oper) {
			m_Operands.push_back(oper);
		}
		virtual void apply(std::vector<Member*>& oper) {
			for (int i = 0; i < oper.size(); i++) {
				m_Operands.push_back(oper[i]);
			}
		}
	protected:

	};
}