boolean  _setupPOST()
{


	//#ifdef ServerDEBUG
	//  _SPrintBrLine();


	
	_printSettings();
	

	SERIALPRINT(F("\n\nGLOBAL Initializations DONE\n"));
	//  timeStamp();
	SERIALPRINT(F("\nSETUP FINISHED. AMS RUNNING"));

	SERIALPRINT(F("\n\tController:\t\tArduino Mega"));
	SERIALPRINT(F("\n\tFirmware:\t\t"));   SERIALPRINT(serverVersion);
	//  SPrint(F("\n\tTotal memory:\t\t")); SPrint(MAX_MEMORY);
	//  SPrint(F("\n\tFree memory:\t\t"));  SPrint(_freeMem()); SPrint(F(" (")); SPrint(_freeMemInPerCent()); SPrint(F("%)"));

	//  SPrint(F("\n\tUnusedRAM:\t\t")); SPrint(_UnusedRAM());
	//  SPrint(F("\n\n------------------------------------------------------------------------------------------------ "));
	
	

	SERIALPRINT(F("\n\n************************************************************************************************\n "));
	SERIALPRINT(F("       END OF SETUP     *     END OF SETUP      *      END OF SETUP     *     END OF SETUP     "));
	SERIALPRINT(F("************************************************************************************************ \nEND OF SETUP in (ms)\t"));
	
	SERIALPRINTLN(millis());
	SERIALPRINT(F("\n\n\n"));
	
	SERIALPRINT(F("freeMem "));
	SERIALPRINTLN(String(freeRam ()));
	
	
	_printFuncAndMemTrace('W', "END OF SETUP", true);
	
	//#endif
	return true;

}
