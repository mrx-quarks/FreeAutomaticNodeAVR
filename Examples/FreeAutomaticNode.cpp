// Do not remove the include below



/*
 Copyright (C) 2011 J. Coliz <maniacbug@ymail.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
 */

/**
 * Example RF Radio Ping Pair
 *
 * This is an example of how to use the RF24 class.  Write this sketch to two different nodes,
 * connect the role_pin to ground on one.  The ping node sends the current time to the pong node,
 * which responds by sending the value back.  The ping node can then see how long the whole cycle
 * took.
 */

/*
  DHCP-based IP printer

 This sketch uses the DHCP extensions to the Ethernet library
 to get an IP address via DHCP and print the address obtained.
 using an Arduino Wiznet Ethernet shield.

 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13

 created 12 April 2011
 modified 9 Apr 2012
 by Tom Igoe

 */

#include <SPI.h>
#include <Ethernet.h>
//#include "NodeEtherImplTest.h"
#include "NodeRF24ImplTest.h"



// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
//byte mac[] = {
 // 0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02
//};



int count=0;
//NodeEtherImplTest *etherTest;
NodeRF24ImplTest *rf24Test;

void setup() {

	pinMode(6,OUTPUT);
	Serial.begin(9600);
	Serial.println("Start new Framwork");
	rf24Test=new NodeRF24ImplTest(42,0x64);
	Serial.println("init done");

	rf24Test->calibrationAndSetup();
	/**
	etherTest=new NodeEtherImplTest(mac,7666);

    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(4,OUTPUT);

    etherTest->calibrationAndSetup();





*/




}

void loop() {


//	etherTest->processCommunication();

	rf24Test->processCommunication();



}
