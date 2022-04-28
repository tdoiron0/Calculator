#pragma once
#include "../../Core.h"
#include "../../ID.h"

#include "pugixml.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <memory>

namespace ENlib {
	enum MemberType {
		MEM_NULL, 
		NUM_CONSTANT, NUM_RATIONAL, NUM_REAL, NUM_INTEGER,
		ID_VAR, 
		CONT_VECTOR, CONT_MATRIX, 
		OPER_ADDITION, OPER_SUBTRACTION, OPER_MULTIPLICATION, OPER_DIVISION, OPER_POWER, OPER_GCF
	};
	enum MemberCategory {
		MEM_CONTAINER,
		MEM_OPERATOR,
		MEM_RELATION
	};

	class EN_API Member {
	public:
		Member() {}
		~Member() {}

		//main interface/simplifing 
		virtual Member* value() = 0;

		//test output tools
		virtual std::string getString() = 0;
		void print() {
			std::cout << getString() << std::endl;
		}

		//interface for combining like terms 
		virtual Member* add(Member* obj) { return nullptr; }
		virtual Member* sub(Member* obj) { return nullptr; }
		virtual Member* mult(Member* obj) { return nullptr; }
		virtual Member* divi(Member* obj) { return nullptr; }
		virtual bool compatible(Member* obj, MemberType operation) { return false; }
		virtual bool equal(Member* obj) { return false; }

		//utility functions 
		MemberType getTypeMember() { return m_Type; }
		MemberCategory getCategoryMember() { return m_Category; }
	protected:
		MemberType m_Type;
		MemberCategory m_Category;
	};
	
	class EN_API MULL : public Member {
	public:
		MULL() {
			m_Category = MEM_CONTAINER; 
			m_Type = MEM_NULL; 
		}
		~MULL() {}

		Member* value() override { return nullptr; }
		std::string getString() override { return "&NULL"; }
		Member* add(Member* obj) override { return nullptr; }
		Member* sub(Member* obj) override { return nullptr; }
		Member* mult(Member* obj) override { return nullptr; }
		Member* divi(Member* obj) override { return nullptr; }
		bool compatible(Member* obj, bool abs = false) override { return false; }
	};
}