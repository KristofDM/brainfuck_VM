/*
 * Program.cpp
 *
 *  Created on: Nov 18, 2013
 *      Author: kristof
 */

#include "Program.h"

namespace bfm {

Program::Program(std::string fileName) {
	// open file
	std::ifstream file;
	file.open(fileName);

	while (file.good()) {
		char c = file.get();
		if (file.good()) {
			switch (c) {
			case '>':
				Instruction* test = new InstructionRight;
				//instructions.push_back(new InstructionRight);
				break;
			}
			if (c == '>' || c == '<' || c == '+' || c == '-' || c == '.' || c == ',') {
				//instructions.push_back(c);
			}
			else if (c == '[') {
				//stack.push(std::pair<char, int>(c, file.tellg()));
			}
			else if (c == ']') {
				//std::pair<char, int> td = stack.top();
				//s/tack.pop();
				//file.seekg(td.second);
			}
		}
	}
}

std::ostream& operator<<(std::ostream& o, Program& p) {
	for (auto e : p.instructions) {
		o << e << " ";
	}

	return o;
}


Program::~Program() {
	// TODO Auto-generated destructor stub
}

} /* namespace bfm */
