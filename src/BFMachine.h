/*
 * BFMachine.h
 *
 *  Created on: Nov 18, 2013
 *      Author: kristof
 */

#ifndef BFMACHINE_H_
#define BFMACHINE_H_

#include <memory>
#include <vector>
#include "Data.h"

namespace bfm {

class Program;

class BFMachine {
public:
	BFMachine(Program&);
	virtual ~BFMachine();
	int getHead();
	void setHead(int);
	std::vector<Data> tape_;
private:
	void readSymbol();
	int head_;
	Program* input_;
};

} /* namespace bfm */

#endif /* BFMACHINE_H_ */

