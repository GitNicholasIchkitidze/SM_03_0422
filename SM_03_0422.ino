


#include "I2CMaster.h"
//#include "EEPROM24.h"
#include <SD.h>
#include <SDConfigFile.h>
#include <Ethernet.h>
#include <utility/w5100.h>

#include "vars.h"
#include "ethernetRELVARS.h"
#include "extenderRELVARS.h"
#include <EEPROM.h>
//#include <IRremote.h>

#include "IRLibSendBase.h"    //We need the base code
#include "IRLib_HashRaw.h"    //Only use raw sender

#include <Wire.h>


#include <TimeLib.h>
#include <DS1307RTC.h>

#include <SoftwareSerial.h>
SoftwareSerial mySerialCom(18, 19); // RX, TX

#define DEBUG_SERIAL_SPEED 115200
#define ServerDEBUG 
//#define DEBUG_SERIAL_base64

//#define DEBUG_SERIAL_trace_FUNCandFREEMEM

//#define DEBUG_SERIAL_Extender_inputs

//#define SERIALPRINT Serial.print
//#define SERIALPRINTLN Serial.println

#define NTP_FEATURE


#ifdef ServerDEBUG     //Macros are usually in all capital letters.
#define SERIALPRINT(...)    Serial.print(__VA_ARGS__)     //DPRINT is a macro, debug print
#define SERIALPRINTLN(...)  Serial.println(__VA_ARGS__)   //DPRINTLN is a macro, debug print with new line
#else
#define SERIALPRINT(...)     //now defines a blank line
#define SERIALPRINTLN(...)   //now defines a blank line
#endif

void applyTemporarySettings();
String getTokenFromString(String theString, char separator, uint8_t tokenIndex, uint8_t stopPosIndex, boolean DDebug = false);

variableAndValue getVarAndValue(String theString, boolean DDebug = false, char delimChar = '=');
//variableAndValue getVarAndValue(String theString, boolean DDebug = false, char delimChar = '=')


void applyTemporarySettings()
{
	presetsAllowed = true;
	heaterAllowed = true;
	useIFTTT = true;
	authMode = AUTH_ON;
	infraRedAllowed = true;
	useCloud = true;
	useI2C = true;
	//isSdOK = false;


}


void setup() {
	// put your setup code here, to run once:
	_setup();
}

void loop() {
	// put your main code here, to run repeatedly:

	digitalWrite(SH_LD, LOW);
	digitalWrite(CLK, LOW);


	/*******************  INHIBIT SECTION START HERE  *****************/
	digitalWrite(SH_LD, HIGH);
	/************** INHIBIT SECTION ENDS HERE ************/
	/************** SERIAL SHIFT SECTION START HERE **********/
	digitalWrite(CLK_INH, LOW);


	_serverWorks();

	



	_listenButtonsAndDebounce1();

	//sendircommand(1);
}




void _PrepareExtendersPins(void)
{


	pinMode(SH_LD, OUTPUT);
	pinMode(CLK, OUTPUT);
	pinMode(CLK_INH, OUTPUT);


	for (uint8_t i = 0; i < NUMBER_INPUT_EXTENDER; i++)
	{

#ifdef ServerDEBUG
		//if (i < 8)
	//	{
		SERIALPRINT(F("\tSetting Pin for INPUT MODE: "));
		SERIALPRINT(ExtendersPin[i]);
		SERIALPRINT(F(", for Extender Chip 74165 N: "));
		SERIALPRINTLN(i);
		//}
#endif

		//                if (inputPullUp)
		//                    pinMode(ExtendersPin[i], INPUT_PULLUP);
		//                else
		pinMode(ExtendersPin[i], INPUT);
	}

	/*
	typedef struct  {
		char id;
		uint8_t group;
		uint8_t extenderChipNum;
		uint8_t extenderChipPinNum;
		uint8_t ControllerPinNum;
		bool state;
		bool enable;
		String lbl;

	} switcherItemStruct;
	*/
	for (uint8_t i = 0; i < ActiveSwitchersCount; i++)
	{

		//			
		//            #ifdef DEBUG_SERIAL
		//                       SPrintln("\t" + switcher[i].id + "\t" + String(switcher[i].group) + "\t" + 
		//								String(switcher[i].extenderChipNum) + ":" + String(switcher[i].extenderChipPinNum)  + "::" + String(switcher[i].ControllerPinNum) + "\t\t" + 
		//								String(switcher[i].state) + "\t" + String(switcher[i].enable) + "\t\"" + switcher[i].lbl + "\"");
		//             #endif
		//

		pinMode(switcher[i].ControllerPinNum, OUTPUT);
		digitalWrite(switcher[i].ControllerPinNum, LOW);
		switcher[i].state = false;
	}

}




void _listenButtonsAndDebounce1()
{
	// LOOP TO GENERATE 8 CLOCK PULSES

	uint8_t x = 0;
	for (uint8_t i = 0; i < 8; i++)
	{

		x = i;
		digitalWrite(CLK, LOW);
		for (uint8_t n = 0; n < NUMBER_INPUT_EXTENDER; n++)
		{
			uint8_t state = digitalRead(ExtendersPin[n]);

			////////////////////////////////////////------------------------------------------------------------------------------------------------////////////////////////////////////
			switch (state)
			{
			case 0:
				//   if ( i==7 )
			{
				switcher[x].state = true;
				break;
			}
			case 1:
			{
				switcher[x].state = false;
				break;
			}
			case 2:
			{
				switcher[x].state = !switcher[x].state;
				break;
			}
			default:
				break;
			}

			////////////////////////////////////////------------------------------------------------------------------------------------------------////////////////////////////////////
#if defined (DEBUG_SERIAL_Extender_inputs)
			SERIALPRINT(F("CHIP/ArduPin/ChipPin N:\t"));				SERIALPRINT(String(n) + "::" + String(ExtendersPin[n]) + "::" + String(i));				SERIALPRINT(F("\tpin State:\t"));				SERIALPRINT(switcher[x].state);
			SERIALPRINT(F("\tsw. Num in Arr:\t"));		SERIALPRINT(x);				SERIALPRINT(F("\tsw. id:\t"));				SERIALPRINT(switcher[x].id);				SERIALPRINT(F("\tsw. lbl:\t"));				SERIALPRINTLN(switcher[x].lbl);
#endif

			x = x + 8;

		}

		digitalWrite(CLK, HIGH);

	}
}
