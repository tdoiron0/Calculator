#include "Conversions.h"
//-----------------------Members---------------------------
#include "MemberBase.h"
//Tokens
#include "Container/Number.h"
#include "Container/Identifier.h"

//Containers

//Operators
#include "Operator/Add.h"
#include "Operator/Multiply.h"
#include "Operator/Power.h"

//Relations 
//---------------------------------------------------------

namespace ENlib {
	Member* num_to_add(Member* src) {
		Add* result = new Add;
		result->apply(src);
		return result;
	}
	Member* ident_to_mult(Member* src) {
		Mult* result = new Mult(new Number(1), src);
		return result;
	}
	Member* ident_to_pow(Member* src) {
		Power* result = new Power(src, new Number(1));
		return result;
	}
	Member* ident_to_ident(Member* src) {
		return ident_to_mult(ident_to_pow(src));
	}

	Converter::Converter() {
		MapRow newRow;

		//All real number conversions 
		newRow.emplace(OPER_ADDITION, &num_to_add);
		cMap.emplace(NUM_REAL, newRow);
		newRow.clear();

		//All identifier conversions 
		newRow.emplace(OPER_MULTIPLY, &ident_to_mult);
		newRow.emplace(OPER_POWER, &ident_to_pow);
		newRow.emplace(ID_VAR, &ident_to_ident);
		cMap.emplace(ID_VAR, newRow);
		newRow.clear();

		//All power conversions 
		newRow.emplace(OPER_MULTIPLY, &ident_to_mult);
		cMap.emplace(OPER_POWER, newRow);
		newRow.clear(); 
	}
	Converter::~Converter() {}
}