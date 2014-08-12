/*
 * NodeEtherImplTest.cpp
 *
 *  Created on: 07.08.2014
 *      Author: enrico
 */

#include "NodeEtherImplTest.h"
#include <Arduino.h>
#include <Wire.h>


#define RED 6
#define BLUE 3
#define GREEN 5

#define BMP085_ADDRESS 0x77  // I2C address of BMP085

int status = 0;

void NodeEtherImplTest::handleSetSwitch(byte port, byte type, int value) {
	Serial.print("Get Set Switch port:");
	Serial.print(port);
	Serial.print(" type:");
	Serial.print(type);
	Serial.print(" value:");
	Serial.print(value);
	Serial.print("\n");

	if (port == 1) {

		if (type == TYPE_SW_AND) {
			status = status & value;
		}

		if (type == TYPE_SW_OR) {
			status = status | value;
		}




		digitalWrite(7,bitRead(~status,0));
		digitalWrite(8,bitRead(~status,1));
		digitalWrite(9,bitRead(~status,2));
		digitalWrite(4,bitRead(~status,3));

	}

	responseSHORT(0, 0, 0, 0);

}

void NodeEtherImplTest::handleSetRGB(byte port, byte r, byte g, byte b) {
	Serial.print("Get Set Switch port:");
	Serial.print(port);
	Serial.print(" r:");
	Serial.print(r);
	Serial.print(" g:");
	Serial.print(g);
	Serial.print(" b:");
	Serial.print(b);
	Serial.print("\n");

	analogWrite(RED, 255 - r);
	analogWrite(GREEN, 255 - g);
	analogWrite(BLUE, 255 - b);

	responseSHORT(0, 0, 0, 0);
}

NodeEtherImplTest::NodeEtherImplTest(byte mac[], int port) :
		EthernetContrlImpl(mac, port) {

}

void NodeEtherImplTest::handleGetValue(byte port) {
	Serial.print("Get Get Value port:");
	Serial.print(port);

	if (port==1)
	{
		short temp= bmp085GetTemperature(bmp085ReadUT());
		Serial.print("Req Temp:");
		Serial.println (temp);
		responseSHORT(temp, 0, 0, 0);
		return;
	}

	if (port==2)
	{
		// has to be called first otherwise the presure is not correct
		bmp085GetTemperature(bmp085ReadUT());



		long pres=bmp085GetPressure(bmp085ReadUP());
		Serial.print("Req Presure:");
		Serial.println (pres);

		// calc for Meitingen 435 m altitude 15 c



		responseInt(pres, 0);
		return;
	}

	Serial.print("Port Not available:");

	responseSHORT(0, 0, 0, 0);
}

short NodeEtherImplTest::bmp085GetTemperature(unsigned int ut) {
	long x1, x2;
	x1 = (((long)ut - (long)ac6)*(long)ac5) >> 15;
	x2 = ((long)mc << 11)/(x1 + md);
	b5 = x1 + x2;
	return ((b5 + 8)>>4);
}

long NodeEtherImplTest::bmp085GetPressure(unsigned long up) {
	long x1, x2, x3, b3, b6, p;
	unsigned long b4, b7;
	b6 = b5 - 4000;
	// Calculate B3
	x1 = (b2 * (b6 * b6)>>12)>>11;
	x2 = (ac2 * b6)>>11;
	x3 = x1 + x2;
	b3 = (((((long)ac1)*4 + x3)<<OSS) + 2)>>2;
	// Calculate B4
	x1 = (ac3 * b6)>>13;
	x2 = (b1 * ((b6 * b6)>>12))>>16;
	x3 = ((x1 + x2) + 2)>>2;
	b4 = (ac4 * (unsigned long)(x3 + 32768))>>15;
	b7 = ((unsigned long)(up - b3) * (50000>>OSS));
	if (b7 < 0x80000000)
	  p = (b7<<1)/b4;
	else
	  p = (b7/b4)<<1;
	x1 = (p>>8) * (p>>8);
	x1 = (x1 * 3038)>>16;
	x2 = (-7357 * p)>>16;
	p += (x1 + x2 + 3791)>>4;
	return p;
}

void NodeEtherImplTest::calibrationAndSetup() {

	Wire.begin();

	ac1 = bmp085ReadInt(0xAA);
	ac2 = bmp085ReadInt(0xAC);
	ac3 = bmp085ReadInt(0xAE);
	ac4 = bmp085ReadInt(0xB0);
	ac5 = bmp085ReadInt(0xB2);
	ac6 = bmp085ReadInt(0xB4);
	b1 = bmp085ReadInt(0xB6);
	b2 = bmp085ReadInt(0xB8);
	mb = bmp085ReadInt(0xBA);
	mc = bmp085ReadInt(0xBC);
	md = bmp085ReadInt(0xBE);


}

char NodeEtherImplTest::bmp085Read(unsigned char address) {
	unsigned char data;
	Wire.beginTransmission(BMP085_ADDRESS);
	Wire.write(address);
	Wire.endTransmission();
	Wire.requestFrom(BMP085_ADDRESS, 1);
	while(!Wire.available());
	return Wire.read();
}

int NodeEtherImplTest::bmp085ReadInt(unsigned char address) {
	unsigned char msb, lsb;
	Wire.beginTransmission(BMP085_ADDRESS);
	Wire.write(address);
	Wire.endTransmission();
	Wire.requestFrom(BMP085_ADDRESS, 2);
	while(Wire.available()<2);
	msb = Wire.read();
	lsb = Wire.read();
	return (int) msb<<8 | lsb;
}

unsigned int NodeEtherImplTest::bmp085ReadUT() {
	unsigned int ut;
	// Write 0x2E into Register 0xF4
	// This requests a temperature reading
	Wire.beginTransmission(BMP085_ADDRESS);
	Wire.write(0xF4);
	Wire.write(0x2E);
	Wire.endTransmission();
	// Wait at least 4.5ms
	delay(5);
	// Read two bytes from registers 0xF6 and 0xF7
	ut = bmp085ReadInt(0xF6);
	return ut;
}

unsigned long NodeEtherImplTest::bmp085ReadUP() {
	unsigned char msb, lsb, xlsb;
	unsigned long up = 0;
	// Write 0x34+(OSS<<6) into register 0xF4
	// Request a pressure reading w/ oversampling setting
	Wire.beginTransmission(BMP085_ADDRESS);
	Wire.write(0xF4);
	Wire.write(0x34 + (OSS<<6));
	Wire.endTransmission();
	// Wait for conversion, delay time dependent on OSS
	delay(2 + (3<<OSS));
	// Read register 0xF6 (MSB), 0xF7 (LSB), and 0xF8 (XLSB)
	Wire.beginTransmission(BMP085_ADDRESS);
	Wire.write(0xF6);
	Wire.endTransmission();
	Wire.requestFrom(BMP085_ADDRESS, 3);
	// Wait for data to become available
	while(Wire.available() < 3);
	msb = Wire.read();
	lsb = Wire.read();
	xlsb = Wire.read();
	up = (((unsigned long) msb << 16) | ((unsigned long) lsb << 8) | (unsigned long) xlsb) >> (8-OSS);
	return up;
}
