/*
 * Instruction.h
 *
 *  Created on: Nov 18, 2013
 *      Author: kristof
 */

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include "BFMachine.h"
#include <stack>

namespace bfm {

class Instruction {
public:
	Instruction();
	virtual ~Instruction();
	virtual void perform() = 0;
};

class InstructionRight : public Instruction {
public:
	virtual void perform(BFMachine&);
};

class InstructionLeft : public Instruction {
public:
	virtual void perform(BFMachine&);
};

class InstructionInc : public Instruction {
public:
	virtual void perform(BFMachine&);
};

class InstructionDec : public Instruction {
public:
	virtual void perform(BFMachine&);
};

class InstructionOut : public Instruction {
public:
	virtual void perform(BFMachine&);
};

class InstructionIn : public Instruction {
public:
	virtual void perform(BFMachine&);
};

class Jump : public Instruction {
protected:
	static std::stack<int> stack;
	int lastPopped;
};

class InstructionJumpFw : public Jump {
public:
	virtual void perform(BFMachine&);
private:
};

class InstructionJumpBw : public Jump {
public:
	virtual void perform(BFMachine&);
};

} /* namespace bfm */

#endif /* INSTRUCTION_H_ */
