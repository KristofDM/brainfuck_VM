/*
 * BFMachine.cpp
 *
 *  Created on: Nov 18, 2013
 *      Author: kristof
 */

#include "BFMachine.h"
//#include "Instruction.h"

namespace bfm {

BFMachine::BFMachine(Program input)
	: input_(input),
	  head_(0)	// Point our head to the first cell of our tape.
{
		tape_.resize(30000, 0);
}

BFMachine::~BFMachine() {
	// TODO Auto-generated destructor stub
}

void BFMachine::readSymbol() {

}

int BFMachine::getHead() {
	return head_;
}

void BFMachine::setHead(int newHead) {
	head_ = newHead;
}

void BFMachine::run() {
	while (input_.getInstrInd() != input_.getInstructions().size()) {
//		std::cout << "getInstrInd: " << input_.getInstrInd() << std::endl;
		input_.getInstructions()[input_.getInstrInd()]->perform(*this);
	}
}

} /* namespace bfm */
