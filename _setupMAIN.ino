
bool _setupMAIN(boolean TraceLog=false)
{
	//hardwareInit();


	  
	if (_sdCardInit() == 1)
	{
		isSdOK = true;
		//Sets SS pin for Ethernet
		pinMode(ETHERNET_SELECT_PIN, OUTPUT);
		digitalWrite(ETHERNET_SELECT_PIN, HIGH);

		char CONFIG_FILE[14];
		String CONFIG_FILE_str;

		CONFIG_FILE_str = "users1.txt";
		//strcpy_P(CONFIG_FILE, PSTR("users.txt"));
		readConfigurationUsers(CONFIG_FILE_str.begin());

//		strcpy_P(CONFIG_FILE, PSTR("users1.txt"));
//		readConfigurationUsers1(CONFIG_FILE);

		strcpy_P(CONFIG_FILE, PSTR("users1.txt"));
		readConfigurationUsers1(CONFIG_FILE);


		strcpy_P(CONFIG_FILE, PSTR("server1.txt"));
		readConfigurationServer(CONFIG_FILE);


		strcpy_P(CONFIG_FILE, PSTR("gcfg.txt"));
		readConfigurationGroups(CONFIG_FILE);

		strcpy_P(CONFIG_FILE, PSTR("sw.txt"));
		readConfigurationSwitches(CONFIG_FILE);



		applyTemporarySettings();

		
		if (presetsAllowed)
		{
			strcpy_P(CONFIG_FILE, PSTR("presets.txt"));
			readConfigurationPresets(CONFIG_FILE);
		}
		

		//	 presetsAllowed = false;
		//	 heaterAllowed = false;

		if (heaterAllowed)
		{

			strcpy_P(CONFIG_FILE, PSTR("heater.txt"));
			readConfigurationHeater(CONFIG_FILE);

		}




		

		//    #ifdef DEBUG_SERIAL
		//        _printSettings();
		//    #endif

		//_PrepareExtendersPins();




		if (useI2C)
		{
			PrepareI2C();
			I2Cscan();
		}


		if (authMode == 0)
			currentUser = "ANONYMOUS";

		if (!SD.exists(F("index.htm")))
		{
#ifdef ServerDEBUG
			SERIALPRINTLN(F("\n\tindex.htm not Found!! Creating a new one!!"));
#endif
			
			MakeIndexFileonSD_B();

			
		}
		else
		{

#ifdef ServerDEBUG
			SERIALPRINT(F("\n\tIndex Found, check REINDEX status: DONE"));
#endif


			if (reIndexFile)
			{
				if (reIndexFileName == "none")
				{
#ifdef ServerDEBUG
					SERIALPRINTLN(F("\n\tDeleting Old index.htm & Creating a new one!!"));
#endif
					SD.remove(F("index.htm"));
					MakeIndexFileonSD_B();
				}
				else
				{
#ifdef ServerDEBUG
					SERIALPRINT(F("\n\tMaking index File from "));
					SERIALPRINTLN(reIndexFileName);
					
#endif

				}
			}
		}



		

//		_makeIndexHtm2();
		
		return true;


	}
	else
	{

		
#ifdef ServerDEBUG
		SERIALPRINTLN(F("\nSD card or Module Initilization Problem!!!\nServer Will WORK with DEFAULT SETTINGS\n"));
#endif		
		//_printSettings();
		
		//_PrepareExtendersPins();
		isSdOK = false;
		applyTemporarySettings();


		return false;
	}


	
	

}
