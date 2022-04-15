#pragma once
#include "EquationNinja/Core.h"
#include "EquationNinja/Problem Datas/Members/MemberBase.h"
#include "EquationNinja/Exceptions/Converter Exceptions.h"
#include "../../ID.h"

#include "pugixml.hpp"

#include <string>
#include <map>

namespace ENlib {
	typedef Member* (*conv_function)(Member*);
	typedef std::map<MemberType, conv_function> MapRow;
	typedef std::map<MemberType, MapRow> ConvertMap;

	class EN_API Converter {
	public:
		ConvertMap cMap;

		Converter();
		~Converter(); 

	}converter;

	bool convertable(MemberType source, MemberType target) {
		if (converter.cMap.count(source) && converter.cMap[source].count(target)) {
			return true;
		}
		else {
			return false;
		}
	}

	Member* convert(Member* obj, MemberType target) {
		bool mode = convertable(obj->getTypeMember(), target);

		if (mode) {
			return converter.cMap[obj->getTypeMember()][target](obj);
		}
		else if (!mode) {
			return obj;
		}
	}
}