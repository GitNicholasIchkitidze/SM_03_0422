
 void _setup()
 {


	 _setupPRE();

	 _assignDefValuesToSwitches();
	 
	 
	 _setupMAIN();

	/*
	#ifdef NTP_FEATURE
		 ntpInit();
	#endif
	 timeInit();
	 printTimeStamp = true;
	 */
	 
	 _PrepareExtendersPins();
	 
	 _setupWEBSERVER();
	 
	 _setupPOST();


	 //writeFileForSDToI2CEEPROOM("server1.txt");
 }
 
