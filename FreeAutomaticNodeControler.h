/*
 * FreeAutomaticNodeControler.h
 *
 *  Created on: 06.08.2014
 *      Author: enrico
 */

#ifndef FREEAUTOMATICNODECONTROLER_H_
#define FREEAUTOMATICNODECONTROLER_H_
#include <Arduino.h>

#define CMD_GET 0
#define CMD_SET 1
#define CMD_PRG 2
#define CMD_ACK 10
#define CMD_RES 20
#define CMD_ERR 30

#define TYPE_SHORT 1
#define TYPE_INT 2
#define TYPE_DOUBLE 3
#define TYPE_RGB 4
#define TYPE_BOOL 5
#define TYPE_SW_AND 6
#define TYPE_SW_OR 7


class FreeAutomaticNodeControler {
public:
	FreeAutomaticNodeControler();

	 virtual void processCommunication()=0;



protected:



    bool processIncommingData(byte *buffer );

    bool responseSHORT(int v1,int v2, int v3, int v4);

    bool responseDOUBLE(float value);

    bool responseRGB(int r,int g, int b);

    // integer means Long because so this int is a 4 byte (32 bit Var)

    bool responseInt(long v1,long v2);

    bool responseERR(int err);




    virtual void sendBack(byte *buffer)=0;

    virtual void handleSetSwitch(byte port,byte type,int value)=0;

    virtual void handleSetRGB(byte port, byte r, byte g, byte b)=0;

    virtual void handleGetValue(byte port)=0;




    byte *buffer;


};

#endif /* FREEAUTOMATICNODECONTROLER_H_ */
