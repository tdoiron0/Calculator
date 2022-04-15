#include "Problem.h"

namespace ENlib {
	Problem::Problem() {
		//_setmode(_fileno(stdout), _O_U16TEXT);
		Log::Init();
	}
	Problem::Problem(std::string* filepath) {
		Log::Init();
		loadFile(filepath);
	}
	Problem::~Problem() {
		for (int i = 0; i < m_Data.size(); i++) {
			delete m_Data[i];
		}
	}

	void Problem::loadFile(std::string* filepath) {
		pugi::xml_document m_Doc;
		if (m_Doc.load_file(filepath->c_str())) {
			pugi::xml_node root = m_Doc.first_child();

			for (pugi::xml_node& it : root.children()) {
				m_Data.push_back(factory.b_Mem(it));
			}
		}

		instr->set(&m_Data);
	}
	Member* Problem::result() {
		return instr->result();
	}
}