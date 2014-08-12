/*
 * RF24ContrlImpl.h
 *
 *  Created on: 06.08.2014
 *      Author: enrico
 */

#ifndef RF24CONTRLIMPL_H_
#define RF24CONTRLIMPL_H_
#include <RF24.h>
#include "FreeAutomaticNodeControler.h"

class RF24ContrlImpl: public FreeAutomaticNodeControler {
	public:
	RF24ContrlImpl(char localAddr,char channel);
	void processCommunication();
protected:


	 void sendBack(byte* buffer);

private:

	 RF24 *radio;

	 uint64_t localAdrr;

	 unsigned char buffer[14];

};

#endif /* RF24CONTRLIMPL_H_ */
