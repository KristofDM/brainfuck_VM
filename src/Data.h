/*
 * Data.h
 *
 *  Created on: Nov 18, 2013
 *      Author: kristof
 */

#ifndef DATA_H_
#define DATA_H_

typedef unsigned char byte;

namespace bfm {

class Data {
public:
	Data();
	Data(char c);
	virtual ~Data();
	Data operator+(const Data&) const;
	Data operator-(const Data&) const;
	byte getInfo();
private:
	byte b;
};

} /* namespace bfm */

#endif /* DATA_H_ */
