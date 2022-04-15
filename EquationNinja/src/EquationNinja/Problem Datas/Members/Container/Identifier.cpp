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
		return new Mult(new Number(2), new Ident(m_ID));
	}
	Member* Ident::sub(Member* obj) {
		return new Number(0.0);
	}
	Member* Ident::mult(Member* obj) {
		return new Power(this, new Number(2.0));
	}
	Member* Ident::divi(Member* obj) {
		return new Number(1.0);
	}
	bool Ident::equal(Member* obj, bool abstractIdentity) {
		if (obj->getTypeMember() == m_Type) {
			Ident* as_ident = (Ident*)obj;

			if (as_ident->m_ID == m_ID) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
}