#include "Identifier.h"

#include "Number.h"
#include "../Operator/Add.h"
#include "../Operator/Subtract.h"
#include "../Operator/Multiply.h"
#include "../Operator/Divide.h"
#include "../Operator/Power.h"

namespace ENlib {
	Ident::Ident() {
		m_Category = MEM_CONTAINER;
		m_Type = ID_VAR;
	}
	Ident::Ident(std::string name) {
		m_Category = MEM_CONTAINER;
		m_Type = ID_VAR;

		m_ID = get_id(name);
	}
	Ident::Ident(unsigned int id) {
		m_Category = MEM_CONTAINER;
		m_Type = ID_VAR;

		m_ID = id;
	}
	Ident::~Ident() {

	}

	Member* Ident::value() { return new Ident(m_ID); }
	std::string Ident::getString() {
		return std::string("[VAR](" + std::to_string(m_ID) + ")");
	}

	Member* Ident::add(Member* obj) {
		return this;
	}
	Member* Ident::sub(Member* obj) {
		return this;
	}
	Member* Ident::mult(Member* obj) {
		return this;
	}
	Member* Ident::divi(Member* obj) {
		return this;
	}

	bool Ident::compatible(Member* obj, MemberType operation) {
		if (obj->getTypeMember() == m_Type) {
			Ident* as_ident = (Ident*)obj;

			return as_ident->m_ID == m_ID;
		}
	}
	bool Ident::equal(Member* obj) {
		if (obj->getTypeMember() == m_Type) {
			if (((Ident*)obj)->linkedValue == nullptr || linkedValue == nullptr) {
				return ((Ident*)obj)->m_ID == m_ID;
			}
			else {
				return linkedValue->equal(((Ident*)obj)->linkedValue);
			}
		}
	}
}