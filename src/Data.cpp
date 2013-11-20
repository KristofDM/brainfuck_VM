/*
 * Data.cpp
 *
 *  Created on: Nov 18, 2013
 *      Author: kristof
 */

#include "Data.h"

namespace bfm {

Data::Data(char c)
 : b(c)
{
}

Data::~Data() {
	// TODO Auto-generated destructor stub
}

Data Data::operator+(const Data& that) const {
	byte test = this->b + that.b;
	return Data(test);
}

Data Data::operator-(const Data& that) const {
	byte test = this->b - that.b;
	return Data(test);
}

unsigned char Data::getInfo() {
	return b;
}


} /* namespace bfm */
