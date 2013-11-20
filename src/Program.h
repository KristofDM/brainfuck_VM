/*
 * Program.h
 *
 *  Created on: Nov 18, 2013
 *      Author: kristof
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stack>
#include <utility>
#include "Instruction.h"

namespace bfm {

class Program {
public:
	Program(std::string);

	virtual ~Program();

	friend std::ostream& operator<<(std::ostream&, Program&);

	void setHead(int);

	int getHead();

	std::vector<Instruction*> getInstructions();
private:
	std::vector<Instruction*> instructions;

	int head_;
};

} /* namespace bfm */

#endif /* PROGRAM_H_ */
