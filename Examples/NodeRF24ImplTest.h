/*
 * NodeRF24ImplTest.h
 *
 *  Created on: 09.08.2014
 *      Author: enrico
 */

#ifndef NODERF24IMPLTEST_H_
#define NODERF24IMPLTEST_H_

#include "../RF24ContrlImpl.h"

class NodeRF24ImplTest: public RF24ContrlImpl {
public:
	NodeRF24ImplTest(char localAddr,char channel);
	void calibrationAndSetup();

protected:
	 void handleSetSwitch(byte port,byte type,int value);

		   void handleSetRGB(byte port, byte r, byte g, byte b);

		 void handleGetValue(byte port);

private:
		 // Calculate temperature given ut.
			 // Value returned will be in units of 0.1 deg C
			 short bmp085GetTemperature(unsigned int ut);

			 // Calculate pressure given up
			 // calibration values must be known
			 // b5 is also required so bmp085GetTemperature(...) must be called first.
			 // Value returned will be pressure in units of Pa.
			 long bmp085GetPressure(unsigned long up);



			 char bmp085Read(unsigned char address);

			 int bmp085ReadInt(unsigned char address);

			 unsigned int bmp085ReadUT();

			 unsigned long bmp085ReadUP();


			 const static  unsigned char OSS = 0;  // Oversampling Setting
			 // Calibration values
			 int ac1;
			 int ac2;
			 int ac3;
			 unsigned int ac4;
			 unsigned int ac5;
			 unsigned int ac6;
			 int b1;
			 int b2;
			 int mb;
			 int mc;
			 int md;

			 long b5;
			 short temperature;
			 long pressure;
};

#endif /* NODERF24IMPLTEST_H_ */
