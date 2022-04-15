#pragma once
#include "../MemberBase.h"
#include "../Conversions.h"

#include <vector>

namespace ENlib {
	class EN_API Operator : public Member {
	public: 
		std::vector<std::shared_ptr<Member>> m_Operands;

		Operator() {}
		~Operator() {}

		int find(Member* obj, bool abstractIdentity = true) {
			for (int i = 0; i < m_Operands.size(); i++) {
				if (m_Operands[i]->equal(obj, abstractIdentity)) {
					return i;
				}
			}

			return -1;
		}
		int find(MemberType target) {
			for (int i = 0; i < m_Operands.size(); i++) {
				if (m_Operands[i]->getTypeMember() == target) {
					return i;
				}
			}

			return -1;
		}
		int findCompatible(Member* obj) {
			for (int i = 0; i < m_Operands.size(); i++) {
				if (convertable(m_Operands[i]->getTypeMember(), obj->getTypeMember())) {
					Member* temp = convert(m_Operands[i].get(), obj->getTypeMember()); 
					if (obj->equal(temp)) {
						return i;
					}
				}
				else if (convertable(obj->getTypeMember(), m_Operands[i]->getTypeMember())) {
					Member* temp = convert(obj, m_Operands[i]->getTypeMember());
					if (m_Operands[i]->equal(temp)) {
						return i;
					}
				}
			}

			return -1; 
		}

		Member* value() override {
			Member* result; 

			for (int i = 0; i < m_Operands.size(); i++) {
				result = process(result, m_Operands[i].get());
			}

			return result;
		}

		virtual Member* process(Member* oper1, Member* oper2) { return nullptr; }
		virtual void apply(Member* oper) {
			m_Operands.push_back(std::shared_ptr<Member>(oper));
		}
		virtual void apply(std::vector<std::shared_ptr<Member>>& oper) {
			for (int i = 0; i < oper.size(); i++) {
				m_Operands.push_back(oper[i]);
			}
		}
	protected:

	};
}