//============================================================================
// Name        : BrainfuckVM.cpp
// Author      : Kristof
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
#include "BFMachine.h"

int main(int argc, char* argv[]) {
	try {
		std::cout << "Brainfuck VM ready." << std::endl;

		// get program filename
		if (argc != 2) {
			throw std::runtime_error("Usage: bfm sourcecode.bf");
		}
		std::string fileName(argv[1]);


		// Create machine and load program:
		//bfm::BFMachine machine;
		bfm::Program prog(fileName);
		std::cout << prog << std::endl;

		// Run program
		// machine.run(prog);

		std::cout << "Program finished." << std::endl;
	}
	catch (std::exception& e) {

	}
	return 0;
}