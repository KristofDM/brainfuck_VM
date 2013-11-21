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
#include "Program.h"

namespace bfm {

class BFMachine {
public:
	BFMachine(Program);

	virtual ~BFMachine();

	int getHead();

	void setHead(int);

	void run();

	std::vector<Data> tape_;

	Program input_;

private:
	void readSymbol();
	int head_;
};

} /* namespace bfm */

#endif /* BFMACHINE_H_ */

