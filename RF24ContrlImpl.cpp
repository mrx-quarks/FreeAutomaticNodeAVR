/*
 * RF24ContrlImpl.cpp
 *
 *  Created on: 06.08.2014
 *      Author: enrico
 */

#include "RF24ContrlImpl.h"





RF24ContrlImpl::RF24ContrlImpl(char localAddr,char channel) {

	this->localAdrr= (0x0000000000LL|localAddr);

	Serial.println("Using RF24 Impl");

	radio=new RF24(9,10);

	radio->begin();

	// optionally, increase the delay between retries & # of retries
	  radio->setRetries(15,15);

	  radio->setChannel(channel);

	  radio->stopListening();

	  radio->setDataRate( RF24_250KBPS );

	  radio->setPALevel( RF24_PA_MAX ) ;
	  radio->setPayloadSize(14);
	  radio->setAutoAck( true ) ;
	  radio->powerUp() ;

	  radio->openReadingPipe(1,localAddr);

	  Serial.println(localAddr);
	  Serial.println(channel);

	  //radio->printDetails();




}



void RF24ContrlImpl::processCommunication() {

	// start listening
	radio->startListening();

	delay(5);

	 // if there is data ready
	    if ( radio->available() )
	    {


	    	bool done = false;
	    	      while (!done)
	    	      {
	    	        // Fetch the payload, and see if this was the last one.
	    	        done = radio->read( buffer,14 );

	    	      /*}
	    	// just for debugging
	    	      Serial.print(  "incomming:");
	    	      for (int i=0;i<14;i++)
	    	           {
	    	           Serial.print(  buffer[i]);
	    	           Serial.print(",");
	    	           }

	    	           Serial.print("\n");
*/

	    	           // First, stop listening so we can talk
	    	                radio->stopListening();

	    	                processIncommingData(buffer);
	    }



}
}


void RF24ContrlImpl::sendBack(byte* buffer) {

	 // calc the src addr

	          uint64_t src_addr = 0x0000000000LL;

		  unsigned char mask=(unsigned char) buffer[1];

		  src_addr=(src_addr|mask)<<8;


	          radio->openWritingPipe(src_addr);

	          radio->write( buffer, 14 );

}
