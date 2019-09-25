
uint8_t _sdCardInit()
{

	if (!SD.begin(SDCARD_SELECT_PIN))
	{
#ifdef ServerDEBUG

		SERIALPRINTLN(F("\n\tSD Initialization\t FAILED"));
		//_SPrintBrLine();
#endif
		return 0;
	}
	else
	{
#ifdef ServerDEBUG
		SERIALPRINTLN(F("\n\tSD Initialization\t OK"));
		//_SPrintBrLine();
#endif

		return 1;
	}

} // sdCardInit()
