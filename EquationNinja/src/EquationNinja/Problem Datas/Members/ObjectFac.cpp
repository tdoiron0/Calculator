#include "ObjectFac.h"

namespace ENlib {
	int ntoi(pugi::xml_node& root) {
		return std::stoi(root.child_value());
	}
	double ntod(pugi::xml_node& root) {
		return std::stod(root.child_value());
	}

	ObjectFac::ObjectFac() {}
	ObjectFac::~ObjectFac() {}

	//XML build functions 
	Member* ObjectFac::b_Mem(pugi::xml_node& root) {
		std::string name(root.name());
		unsigned int id = get_id(name);

		switch (id) {
		case 847:
			return b_Num(root);
		case 822:
			return b_Id(root);
		case 4396:
			return b_Apply(root);
		}

		return nullptr;
	}
	Member* ObjectFac::b_Apply(pugi::xml_node& root) {
		std::string name(root.first_child().name());
		unsigned int id = get_id(name);

		std::vector<pugi::xml_node> operands;
		for (pugi::xml_node& it : root.children()) {
			operands.push_back(it);
		}
		operands.erase(operands.begin());

		switch (id) {
		case 2960:
			return b_Add(operands);
		}

		return nullptr;
	}
	void ObjectFac::b_Oper(Operator* target, std::vector<pugi::xml_node>& source) {
		for (int i = 0; i < source.size(); i++) {
			target->apply(b_Mem(source[i]));
		}
	}
	
	Member* ObjectFac::b_Num(pugi::xml_node& root) {
		return new Number(std::stod(root.child_value()));
	}
	Member* ObjectFac::b_Id(pugi::xml_node& root) {
		return new Ident(std::string(root.child_value()));
	}
	Member* ObjectFac::b_Add(std::vector<pugi::xml_node>& source) {
		Add* result = new Add;
		b_Oper(result, source);
		return result;
	}
}