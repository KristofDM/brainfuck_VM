/*
 * Program.cpp
 *
 *  Created on: Nov 18, 2013
 *      Author: kristof
 */

#include "Program.h"

namespace bfm {

Program::Program(std::string fileName) : head_(0) {
	// open file
	std::ifstream file;
	file.open(fileName);

	while (file.good()) {
		char c = file.get();
		if (file.good()) {
			switch (c) {
			case '>':
				instructions.push_back(new InstructionRight);
				break;
			case '<':
				instructions.push_back(new InstructionLeft);
				break;
			case '+':
				instructions.push_back(new InstructionInc);
				break;
			case '-':
				instructions.push_back(new InstructionDec);
				break;
			case '.':
				instructions.push_back(new InstructionOut);
				break;
			case ',':
				instructions.push_back(new InstructionIn);
				break;
			case '[':
				instructions.push_back(new InstructionJumpFw);
				break;
			case ']':
				instructions.push_back(new InstructionJumpBw);
				break;
			default:
				// do nothing (token not part of brainfuck)
				break;
			}
		}
	}
}

std::ostream& operator<<(std::ostream& o, Program& p) {
	for (auto e : p.instructions) {
		// This will print addresses.
		o << e << " ";
	}

	return o;
}

std::vector<Instruction*> Program::getInstructions() {
	return instructions;
}

void Program::setHead(int newHead) {
	head_ = newHead;
}

int Program::getHead() {
	return head_;
}

Program::~Program() {
	// TODO Auto-generated destructor stub
}

} /* namespace bfm */
