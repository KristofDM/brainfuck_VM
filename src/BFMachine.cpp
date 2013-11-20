/*
 * BFMachine.cpp
 *
 *  Created on: Nov 18, 2013
 *      Author: kristof
 */

#include "BFMachine.h"

namespace bfm {

BFMachine::BFMachine(Program& input)
	: head_(0),	// Point our head to the first cell of our tape.
	  input_(&input)
{}

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



} /* namespace bfm */
