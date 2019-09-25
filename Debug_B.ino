#include "MemoryFree.h"




void _printIp(byte ip[]) {

	for (byte i = 0; i < 4; i++) {
		SERIALPRINT(ip[i]);
		if (i == 3) { break; }
		SERIALPRINT(F("."));
	}

}



void _printMac(byte mac[]) {

	for (byte i = 0; i < 6; i++) {
		SERIALPRINT(mac[i], HEX);
		if (i == 5) { break; }
		SERIALPRINT(F(" "));
	}


}


void _printSettings()
{

	uint8_t i = 0;
	//  if (presetsAllowed)
	//  {
	//  _checkPresets();
	//  }

	SERIALPRINT(F("\n\n\tLoaded Settings:"));

	SERIALPRINT(F("\n\tMAC:\t\t\t\t"));
	_printMac(SERVER_MAC);

	SERIALPRINT(F("\n\tIP:\t\t\t\t"));
	_printIp(SERVER_IP);
	

	SERIALPRINT(F("\n\tPORT:\t\t\t\t"));
	SERIALPRINT(SERVER_PORT);

	SERIALPRINT(F("\n\tSERVER VERSION:\t\t"));
	SERIALPRINT(serverVersion);

	SERIALPRINT(F("\n\t\tUSER-AGENT1:\t\t"));
	SERIALPRINT(userAgent1);
	SERIALPRINT(F("\n\t\tUSER-AGENT2:\t\t"));
	SERIALPRINT(userAgent2);

	

	SERIALPRINT(F("\n\tUSE Cloud:\t\t\t"));
	SERIALPRINT(useCloud);

	SERIALPRINT(F("\n\tUSE I2C bus:\t\t\t"));
	SERIALPRINT(useI2C);

	SERIALPRINT(F("\n\tUSE Extedned Serial Communication:\t"));
	SERIALPRINT(useSerialComm);
	SERIALPRINT(F("\n\tUSE Google ASSISTANT (IFTTT):\t"));
	SERIALPRINT(useIFTTT);

	SERIALPRINT(F("\n\tSD CARD:\t\t\t"));
	SERIALPRINT(isSdOK);


	SERIALPRINT(F("\n\tMAX SOCKETS NUM:\t\t"));
	SERIALPRINT(MAX_SOCK_NUM);

	SERIALPRINT(F("\n\tHeater Enabled:\t\t\t"));
	SERIALPRINTLN(heaterAllowed);

	SERIALPRINT(F("\n\tIR Enabled:\t\t\t"));
	SERIALPRINT(infraRedAllowed);
	SERIALPRINT(F("\tIR Commands:\t\t\t"));
	SERIALPRINTLN(infraRedCmdCount);

	SERIALPRINT(F("\n\tReindex from Custom file:\t\t"));
	SERIALPRINT(reIndexFile);
	SERIALPRINT(F("\tfilename:\t\t\t\t"));
	SERIALPRINT(reIndexFileName);
	
	SERIALPRINT(F("\nEEPROM SIZE:\t\t\t"));
	SERIALPRINT(EEPROM.length());


	SERIALPRINT(F("\n\tPresets Enabled:\t\t\t"));
	SERIALPRINTLN(presetsAllowed);
	SERIALPRINTLN(F(""));

	if (presetsAllowed)
	{
		for (i = 0; i < 6; i++)
		{
			SERIALPRINT(F("\tId: "));
			SERIALPRINT(preset[i].id);
			SERIALPRINT(F(";\tEnabled:"));
			SERIALPRINT(preset[i].enable);
			SERIALPRINT(F(";\tStates: "));
			SERIALPRINT(preset[i].states);
			SERIALPRINT(F(";\tlabel: "));
			SERIALPRINTLN(preset[i].lbl);
		}

	}


	/*
	 *
	 *
	 *
	  SERIALPRINT(F("\n\tPRESETS ALLOWED:\t\t"));
	  SERIALPRINT(presetsAllowed);


	  SERIALPRINT(F("\n\tPRESETS COUNT:\t\t\t"));
	  SERIALPRINT(PresetsCount);

	  SERIALPRINT(F("\n\tHeater Allowed:\t\t\t"));
	  SERIALPRINT(heaterAllowed);
	   if (heaterAllowed)
	   {
		 SERIALPRINT(F("\n\tHeater Switch On at:\t\t\t"));
		 SERIALPRINT(heaterTempMin);
		 SERIALPRINT(F("\n\tHeater Switch Off at:\t\t\t"));
		 SERIALPRINT(String(heaterTempMax));

	   }


	*/
	SERIALPRINT(F("\n\tImpulse Duration:\t\t"));
	SERIALPRINT(WEB_IMPULSE_DURATION);




	SERIALPRINT(F("\n\tAuthentification MODE:\t\t"));
	SERIALPRINTLN(authMode);

	SERIALPRINT(F("\n\n\tREGISTERED USERS:\t\tPASSWORD\t\t\tROLE"));

	for (i = 0; i < REGISTERED_USER_COUNT; i++)
	{
		SERIALPRINT(F("\n\t"));
		SERIALPRINT(user[i]);
		SERIALPRINT(F("\t\t\t\t"));
		SERIALPRINT(passw[i]);
		SERIALPRINT(F("\t\t\t\tNot Defined"));

	}

	SERIALPRINT(F("\n\n"));

	SERIALPRINT(F("\n\tRegistered Groups Count:\t\t"));
	SERIALPRINT(ActiveGroupsCount);

	SERIALPRINT(F("\tRegistered Switchers Count:\t\t"));
	SERIALPRINTLN(ActiveSwitchersCount);



	for (i = 0; i < ActiveGroupsCount; i++)
	{
		SERIALPRINTLN("\tId: " + group[i].id + ";\tEnable: " + String(group[i].enable) + ";\tlabel: " + group[i].lbl);
	}




	SERIALPRINT(F("\n"));
	for (i = 0; i < ActiveSwitchersCount; i++)
	{
		SERIALPRINTLN("\t#: " + String(i) + "\tId: " + switcher[i].id + ";\tgroup: " + String(switcher[i].group) + ";\t" +
			String(switcher[i].extenderChipNum) + ":" + String(switcher[i].extenderChipPinNum) + "::" + String(switcher[i].ControllerPinNum) + ";\tState: " +
			String(switcher[i].state) + ";\tEnable: " + String(switcher[i].enable) + ";\tlabel: \"" + switcher[i].lbl + "\"");
	}




}


String _printVarAndVal(variableAndValue vv)
{
	return "Variable: \"" + vv.vvarName + "\" <=> Value: " + vv.vvarValue;
}


void _printFuncAndMemTrace(char InOut, String funcName = "", boolean TraceLog = false)
{

#ifdef DEBUG_SERIAL_trace_FUNCandFREEMEM

	if (TraceLog)
	{
		SERIALPRINT(F("\n**********\t"));
		SERIALPRINT(funcName);
		if (InOut == 'I')
			SERIALPRINT(F("\tIN;\t"));
		else if (InOut == 'O')
			SERIALPRINT(F("\tOUT;\t"));

		SERIALPRINT(F("\tfree MEM:\t"));
		//SERIALPRINT(availableMemory());
		//SERIALPRINT(F("::"));
		SERIALPRINT(freeMemory());
		SERIALPRINT(F("::"));
		SERIALPRINT(freeRam());
		SERIALPRINT(F("\t"));
		SERIALPRINT(F("\t**********\t"));
		SERIALPRINTLN(millis());
	}

#endif

}
