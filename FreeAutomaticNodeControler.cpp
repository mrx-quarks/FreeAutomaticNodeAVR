/*
 * FreeAutomaticNodeControler.cpp
 *
 *  Created on: 06.08.2014
 *      Author: enrico
 */

#include "FreeAutomaticNodeControler.h"


FreeAutomaticNodeControler::FreeAutomaticNodeControler() {



}

bool FreeAutomaticNodeControler::processIncommingData(byte *buffer) {

	this->buffer=buffer;

 // determ which command we get

	 if ((buffer[3]>=CMD_SET)&&(buffer[3]<=CMD_SET+10))
	 {
		 // process a set Command
		  byte type=buffer[3]-CMD_SET;

		  if ((type==TYPE_SW_OR)||(type==TYPE_SW_AND))
		  {
		  int value=word(buffer[6],buffer[7]);

		  this->handleSetSwitch(buffer[2],type,value);
		  }

		  if (type==TYPE_RGB)
		  {
			  this->handleSetRGB(buffer[2],buffer[6],buffer[7],buffer[8]);
		  }

	 }
	 if (buffer[3]==CMD_GET)
	 {
		    this->handleGetValue(buffer[2]);
	 }







	return true;

}

bool FreeAutomaticNodeControler::responseSHORT(int v1, int v2, int v3, int v4) {

	buffer[3]=CMD_RES+TYPE_SHORT;

	buffer[6]=highByte(v1);
	buffer[7]=lowByte(v1);

	buffer[8]=highByte(v2);
	buffer[9]=lowByte(v2);

	buffer[10]=highByte(v3);
	buffer[11]=lowByte(v3);

	buffer[12]=highByte(v4);
	buffer[13]=lowByte(v4);

    sendBack(buffer);

    return true;



}

bool FreeAutomaticNodeControler::responseDOUBLE(float value) {

	buffer[3]=CMD_RES+TYPE_DOUBLE;

	byte x[8] = {
	    0,0,0,0, 0,0,0,0      };

	 // float2DoublePacked(value, x);

	  for (int i=0;i<8;i++)
	  {
		  buffer[6+i]=x[i];
	  }



}

bool FreeAutomaticNodeControler::responseRGB(int r, int g, int b) {

	this->buffer[3]=CMD_RES+TYPE_RGB;

	buffer[6] = (byte) r;
	buffer[7] = (byte)  g;
	buffer[8] = (byte) b;
	return true;
}

bool FreeAutomaticNodeControler::responseInt(long v1,long v2) {

	buffer[3]=CMD_RES+TYPE_INT;

		buffer[6]=(int)((v1 >> 24) & 0xFF) ;
		buffer[7]=(int)((v1 >> 16) & 0xFF) ;

		buffer[8]=(int)((v1 >> 8) & 0xFF) ;
		buffer[9]=(int)(v1  & 0xFF) ;

		buffer[10]=(int)((v2 >> 24) & 0xFF) ;
		buffer[11]=(int)((v2 >> 16) & 0xFF) ;

		buffer[12]=(int)((v2 >> 8) & 0xFF) ;
		buffer[13]=(int)(v2  & 0xFF) ;


	    sendBack(buffer);

	    return true;

}

bool FreeAutomaticNodeControler::responseERR(int err)
{

	this->buffer[3]=CMD_ERR;

	this->buffer[6]=highByte(err);
	this->buffer[7]=lowByte(err);

	sendBack(this->buffer);

		return true;

}



