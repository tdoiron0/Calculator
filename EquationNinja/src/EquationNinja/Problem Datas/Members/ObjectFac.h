#pragma once
#include "../../Core.h"

//-----------------------Members---------------------------
#include "MemberBase.h"
//Tokens
#include "Container/Number.h"
#include "Container/Identifier.h"

//Containers

//Operators
#include "Operator/Add.h"
#include "Operator/Multiply.h"

//Relations 
//---------------------------------------------------------

#include "pugixml.hpp"

#include <string>
#include <vector>

namespace ENlib {
	class EN_API ObjectFac {
	public: 
		ObjectFac();
		~ObjectFac();

		Member* b_Mem(pugi::xml_node& root);
	private: 
		Member* b_Apply(pugi::xml_node& root);
		void b_Oper(Operator* target, std::vector<pugi::xml_node>& source);
		
		Member* b_Num(pugi::xml_node& root);
		Member* b_Id(pugi::xml_node& root);
		Member* b_Add(std::vector<pugi::xml_node>& oper);
	};
}