/*
 * BFMachine.h
 *
 *  Created on: Nov 18, 2013
 *      Author: kristof
 */

#ifndef BFMACHINE_H_
#define BFMACHINE_H_

#include <array>
#include <memory>
#include "Data.h"
#include "Program.h"


namespace bfm {

class BFMachine {
public:
	BFMachine(Program);
	virtual ~BFMachine();
	int getHead();
	void setHead(int);
	std::vector<Data> tape_;
	//std::array<Data, 30000> tape_;
private:
	void readSymbol();
	int head_;
	Program input_;
};

} /* namespace bfm */

#endif /* BFMACHINE_H_ */

