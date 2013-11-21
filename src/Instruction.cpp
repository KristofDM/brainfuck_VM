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
std::stack<int> Jump::lpStack = std::stack<int>();

Instruction::Instruction()
{
	// TODO Auto-generated constructor stub
}

Instruction::~Instruction() {
	// TODO Auto-generated destructor stub
}

void InstructionRight::perform(BFMachine& m) {
//	std::cout << ">" << std::endl;
	m.setHead(m.getHead() + 1);
	m.input_.setInstrInd(m.input_.getInstrInd() + 1);
}

void InstructionLeft::perform(BFMachine& m) {
//	std::cout << "<" << std::endl;
	m.setHead(m.getHead() - 1);
	m.input_.setInstrInd(m.input_.getInstrInd() + 1);
}

void InstructionInc::perform(BFMachine& m) {
//	std::cout << "+" << std::endl;
	m.tape_[m.getHead()] = m.tape_[m.getHead()] + 1;
	m.input_.setInstrInd(m.input_.getInstrInd() + 1);
}

void InstructionDec::perform(BFMachine& m) {
//	std::cout << "-" << std::endl;
	m.tape_[m.getHead()] = m.tape_[m.getHead()] - 1;
	m.input_.setInstrInd(m.input_.getInstrInd() + 1);
//	std::cout << "THIS VALUE IS  ------- = " << m.getHead() << std::endl;
}

void InstructionOut::perform(BFMachine& m) {
//	std::cout << "out" << std::endl;
	char c = m.tape_[m.getHead()].getInfo();
	int i = c;
	//std::cout << "This is === " << c << " and that's integer value: " << i << std::endl;
	std::cout << c;
	m.input_.setInstrInd(m.input_.getInstrInd() + 1);
}

void InstructionIn::perform(BFMachine& m) {
//	std::cout << "in" << std::endl;
	char c;
	std::cin >> c;
	m.tape_[m.getHead()] = c;
	m.input_.setInstrInd(m.input_.getInstrInd() + 1);
}

void InstructionJumpFw::perform(BFMachine& m) {
//	std::cout << "jumpfw" << std::endl;

	stack.push(m.input_.getInstrInd());
	if (int(m.tape_[m.getHead()].getInfo()) == 0) {
//		std::cout << "JMPING!" << std::endl;
		std::cout << lpStack.size() << std::endl;
		m.input_.setInstrInd(lpStack.top());
	}
	else {
		m.input_.setInstrInd(m.input_.getInstrInd() + 1);
	}
	if (!lpStack.empty()) {
		lpStack.pop();
	}
}

void InstructionJumpBw::perform(BFMachine& m) {
//	std::cout << "jumpbw" << std::endl;

	int top = stack.top();
	stack.pop();
	if (m.tape_[m.getHead()].getInfo() > 0) {
		lpStack.push(m.input_.getInstrInd());
		m.input_.setInstrInd(top);
	}
	else {
		m.input_.setInstrInd(m.input_.getInstrInd() + 1);
	}
}


} /* namespace bfm */
