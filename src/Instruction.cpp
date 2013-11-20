/*
 * Instruction.cpp
 *
 *  Created on: Nov 18, 2013
 *      Author: kristof
 */

#include "Instruction.h"

namespace bfm {

std::stack<int> Jump::stack = std::stack<int>();

Instruction::Instruction()
{
	// TODO Auto-generated constructor stub
}

Instruction::~Instruction() {
	// TODO Auto-generated destructor stub
}

void InstructionRight::perform(BFMachine& m) {
	m.setHead(m.getHead() + 1);
}

void InstructionLeft::perform(BFMachine& m) {
	m.setHead(m.getHead() - 1);
}

void InstructionInc::perform(BFMachine& m) {
	m.tape_[m.getHead()] = m.tape_[m.getHead()] + 1;
}

void InstructionDec::perform(BFMachine& m) {
	m.tape_[m.getHead()] = m.tape_[m.getHead()] - 1;
}

void InstructionOut::perform(BFMachine& m) {
	char c = m.tape_[m.getHead()].getInfo();
	std::cout << c;
}

void InstructionIn::perform(BFMachine& m) {
	char c;
	std::cin >> c;
	m.tape_[m.getHead()] = c;
}

void InstructionJumpFw::perform(BFMachine& m) {
	stack.push(m.getHead());
	if (m.tape_[m.getHead()].getInfo() == 0) {
		// LastPopped will only work when no nested []
		m.setHead(lastPopped);
	}
}

void InstructionJumpBw::perform(BFMachine& m) {
	int top = stack.top();
	stack.pop();
	lastPopped = m.getHead();
	if (m.tape_[m.getHead()].getInfo() != 0) {
		m.setHead(top);
	}
}


} /* namespace bfm */
