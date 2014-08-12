/*
 * EthernetContrlImpl.h
 *
 *  Created on: 07.08.2014
 *      Author: enrico
 */

#ifndef ETHERNETCONTRLIMPL_H_
#define ETHERNETCONTRLIMPL_H_


#include <SPI.h>
#include <Ethernet.h>
#include "FreeAutomaticNodeControler.h"

class EthernetContrlImpl: public FreeAutomaticNodeControler {
public:

	EthernetContrlImpl(byte mac[],int port);




	virtual ~EthernetContrlImpl();

	void processCommunication();




protected:
	void sendBack(byte *buffer);


private:

	EthernetClient client;
	EthernetServer *server;
	bool ready;
	unsigned char buffer[14];

};

#endif /* ETHERNETCONTRLIMPL_H_ */
