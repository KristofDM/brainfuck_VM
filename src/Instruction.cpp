/*
 * Instruction.cpp
 *
 *  Created on: Nov 18, 2013
 *      Author: kristof
 */

#include "Instruction.h"
#include "BFMachine.h"

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
	std::cout << ">" << std::endl;
	m.setHead(m.getHead() + 1);
}

void InstructionLeft::perform(BFMachine& m) {
	std::cout << "<" << std::endl;
	m.setHead(m.getHead() - 1);
}

void InstructionInc::perform(BFMachine& m) {
	std::cout << "+" << std::endl;
	m.tape_[m.getHead()] = m.tape_[m.getHead()] + 1;
}

void InstructionDec::perform(BFMachine& m) {
	std::cout << "-" << std::endl;
	m.tape_[m.getHead()] = m.tape_[m.getHead()] - 1;
}

void InstructionOut::perform(BFMachine& m) {
	std::cout << "out" << std::endl;
	char c = m.tape_[m.getHead()].getInfo();
	int i = c;
	//std::cout << "This is === " << c << " and that's integer value: " << i << std::endl;
	std::cout << c;
}

void InstructionIn::perform(BFMachine& m) {
	std::cout << "in" << std::endl;
	char c;
	std::cin >> c;
	m.tape_[m.getHead()] = c;
}

void InstructionJumpFw::perform(BFMachine& m) {
	std::cout << "jumpfw" << std::endl;
	stack.push(m.getHead());
	if (m.tape_[m.getHead()].getInfo() == 0) {
		// LastPopped will only work when no nested []
		m.setHead(lastPopped);
	}
}

void InstructionJumpBw::perform(BFMachine& m) {
	std::cout << "jumpbw!" << std::endl;
	int top = stack.top();
	stack.pop();
	lastPopped = m.getHead();
	std::cout << "info: " << int(m.tape_[m.getHead()].getInfo()) << std::endl;
	if (m.tape_[m.getHead()].getInfo() != 0) {
		m.setHeads(top);
	}
}


} /* namespace bfm */
