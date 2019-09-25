
void _setupPRE()
{
	Serial.begin(DEBUG_SERIAL_SPEED);       // for debugging
	// Serial.println(Serial.list());
	
//	checkDebug_defines();
	
	
	#ifdef ServerDEBUG
	
			SERIALPRINTLN(F("\n\n\n************************************************************************************************\n "));
			SERIALPRINTLN(F("       LOADING SETUP     *     LOADING SETUP      *      LOADING SETUP     *     LOADING SETUP     "));
			SERIALPRINTLN(F("\n************************************************************************************************\nSTART OF SETUP at (ms) "));
			SERIALPRINTLN(String(millis()));
			
	#else
	
	SERIALPRINTLN(F("\nSerial Debuger DISABLED"));
	Serial.end();
	#endif
} // End of SetupPRE()
