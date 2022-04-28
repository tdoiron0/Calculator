#include "Number.h"

namespace ENlib {
	Number::Number() {
		m_Category = MEM_CONTAINER;
		m_Type = NUM_REAL;

		m_Value.push_back(0.0);
	}
	Number::Number(double value) {
		m_Category = MEM_CONTAINER;
		m_Type = NUM_REAL;

		m_Value.push_back(value);
	}
	Number::~Number() {

	}

	Member* Number::value() { return new Number(m_Value[0]); }
	std::string Number::getString() { return "[NUM](" + std::to_string(m_Value[0]) + ")"; }

	Member* Number::add(Member* obj) {
		return new Number(m_Value[0] + ((Number*)obj)->m_Value[0]);
	}
	Member* Number::sub(Member* obj) {
		return new Number(m_Value[0] - ((Number*)obj)->m_Value[0]);
	}
	Member* Number::mult(Member* obj) {
		return new Number(m_Value[0] * ((Number*)obj)->m_Value[0]);
	}
	Member* Number::divi(Member* obj) {
		return new Number(m_Value[0] / ((Number*)obj)->m_Value[0]);
	}
	bool Number::compatible(Member* obj, MemberType operation) {
		return obj->getTypeMember() == m_Type;
	}
	bool Number::equal(Member* obj) {
		if (obj->getTypeMember() == m_Type) {
			return ((Number*)obj)->m_Value[0] == m_Value[0];
		}
	}
}