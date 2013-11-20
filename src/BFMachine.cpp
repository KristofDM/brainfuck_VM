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
	: head_(0),	// Point our head to the first cell of our tape.
	  input_(input)
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
	std::cout << "NEWHEAD = " << head_ << std::endl;
}

void BFMachine::setHeads(int newHead) {
	head_ = newHead;
	input_.setHead(newHead);
	std::cout << "NEWHEAD = " << head_ << std::endl;
}

void BFMachine::run() {

	/*
	 * Need to write this.
	 */

}

} /* namespace bfm */
