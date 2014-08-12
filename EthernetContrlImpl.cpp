/*
 * EthernetContrlImpl.cpp
 *
 *  Created on: 07.08.2014
 *      Author: enrico
 */

#include "EthernetContrlImpl.h"


EthernetContrlImpl::EthernetContrlImpl(byte mac[],int port) {

	ready=false;

  server = new EthernetServer(port);

 if (Ethernet.begin(mac) == 0)
 {
	 this->ready=true;
 }

 for (byte thisByte = 0; thisByte < 4; thisByte++) {
     // print the value of each byte of the IP address:
     Serial.print(Ethernet.localIP()[thisByte], DEC);
     Serial.print(".");
   }
   Serial.println();


}

EthernetContrlImpl::~EthernetContrlImpl() {
	// TODO Auto-generated destructor stub
}

void EthernetContrlImpl::processCommunication() {



		  client=server->available();
		  if (client == true) {

			  Serial.println("Incoming data");

		      int size=client.read(buffer,14);

		      Serial.print(size);
		      Serial.print(" Get Package :[");

		      //Debugging

		      for (int i=0;i<14;i++)
		      {
		    	  Serial.print(buffer[i]);
		    	  Serial.print(",");
		      }
		      Serial.print("]\n");

		      processIncommingData(buffer);


		      client.stop();
		      delay(5);

		  }

}

void EthernetContrlImpl::sendBack(byte* buffer) {

	 if (client == true) {

		 Serial.print("Response: ");

		 for (int i=0;i<14;i++)
		 		      {
		 		    	  Serial.print(buffer[i]);
		 		    	  Serial.print(",");
		 		      }
		 		      Serial.print("]\n");

		 client.write(buffer,14);
	 }


}
