boolean readConfigurationServer(char CONFIG_FILE[]) {
	/*
	 * Length of the longest line expected in the config file.
	 * The larger this number, the more memory is used
	 * to read the file.
	 * You probably won't need to change this number.
	 */
	const uint8_t CONFIG_LINE_LENGTH = 65;

	// The open configuration file.
	SDConfigFile cfg;

	// Open the configuration file.
	if (!cfg.begin(CONFIG_FILE, CONFIG_LINE_LENGTH)) {
#ifdef ServerDEBUG
		SERIALPRINT(F("Failed to open configuration file: "));
		SERIALPRINTLN(CONFIG_FILE);
#endif
		return false;
	}

	// Read each setting from the file.
	while (cfg.readNextSetting()) 
	{

		// Put a nameIs() block here for each setting you have.

		if (cfg.nameIs((char*) "port"))
			SERVER_PORT = cfg.getIntValue();
		else if (cfg.nameIs((char*) "ip0")) SERVER_IP[0] = cfg.getIntValue();
		else if (cfg.nameIs((char*) "ip1")) SERVER_IP[1] = cfg.getIntValue();
		else if (cfg.nameIs((char*) "ip2")) SERVER_IP[2] = cfg.getIntValue();
		else if (cfg.nameIs((char*) "ip3")) SERVER_IP[3] = cfg.getIntValue();
		else if (cfg.nameIs((char*) "WEB_IMPULSE_DURATION")) WEB_IMPULSE_DURATION = cfg.getIntValue();
		else if (cfg.nameIs((char*) "authMode")) authMode = cfg.getIntValue();
		else if (cfg.nameIs((char*) "useCloud")) useCloud = cfg.getBooleanValue();
		else if (cfg.nameIs((char*) "useI2C")) useI2C = cfg.getBooleanValue();
		else if (cfg.nameIs((char*) "useSerialComm")) useSerialComm = cfg.getBooleanValue();
		else if (cfg.nameIs((char*) "useIFTTT")) useIFTTT = cfg.getBooleanValue();
		else if (cfg.nameIs((char*) "reIndexFile")) reIndexFile = cfg.getBooleanValue();
		else if (cfg.nameIs((char*) "reIndexFileName")) reIndexFileName = cfg.getValue();
		//else if (cfg.nameIs("serverVersion")) serverVersion = cfg.getValue();
		//else if (cfg.nameIs((char*) "userAgent1"))
		//{
		//	userAgent1 = cfg.getValue();
		//	userAgent1 = "User-Agent: " + userAgent1;
		//}
		else if (cfg.nameIs((char*) "userAgent1")) userAgent1 = cfg.getValue();
		else if (cfg.nameIs((char*) "userAgent2")) userAgent2 = cfg.getValue();
		else if (cfg.nameIs((char*) "userCookie")) userCookie = cfg.getValue();
		else if (cfg.nameIs((char*) "cloudAddress")) cloudAddress = cfg.getValue();
		else if (cfg.nameIs((char*) "presetsAllowed")) presetsAllowed = cfg.getBooleanValue();
		else if (cfg.nameIs((char*) "heaterAllowed")) heaterAllowed = cfg.getBooleanValue();
		else if (cfg.nameIs((char*) "infraRedAllowed")) infraRedAllowed = cfg.getBooleanValue();
		else if (cfg.nameIs((char*) "infraRedCmdCount")) infraRedCmdCount = cfg.getIntValue();
		
	}

	// clean up
	cfg.end();

	return true;
}



boolean readConfigurationUsers(char CONFIG_FILE[]) {
	/*
	 * Length of the longest line expected in the config file.
	 * The larger this number, the more memory is used
	 * to read the file.
	 * You probably won't need to change this number.
	 */
	const uint8_t CONFIG_LINE_LENGTH = 65;

	// The open configuration file.
	SDConfigFile cfg;

	// Open the configuration file.
	if (!cfg.begin(CONFIG_FILE, CONFIG_LINE_LENGTH)) 
	{
#ifdef ServerDEBUG
		SERIALPRINT(F("Failed to open configuration file: "));
		SERIALPRINTLN(CONFIG_FILE);
#endif
		return false;
	}


	
	// Read each setting from the file.
	while (cfg.readNextSetting()) {

		// Put a nameIs() block here for each setting you have.

		TMP_STRING1 = cfg.getName();

		if (TMP_STRING1.charAt(0) != '*')
		{
			for (uint8_t i = 0; i < REGISTERED_USER_COUNT; i++)
			{
				if (TMP_STRING1 == "user" + String(i)) {
					user[i] = cfg.getValue();
					// SPrint(i);     SPrint("\t->\t");  SPrint(cfg->getName());     SPrint("\t=\t");    SPrintln(cfg->getValue());
					break;
				}
				else if (TMP_STRING1 == "passw" + String(i)) {
					passw[i] = cfg.getValue();
					//SPrint(i);     SPrint("\t->\t");  SPrint(cfg->getName());     SPrint("\t=\t");    SPrintln(cfg->getValue());
					break;
				}
			}
		}
	}

	// clean up
	cfg.end();

	return true;
}


boolean readConfigurationUsers1(char CONFIG_FILE[]) {
	/*
	 * Length of the longest line expected in the config file.
	 * The larger this number, the more memory is used
	 * to read the file.
	 * You probably won't need to change this number.
	 */
	const uint8_t CONFIG_LINE_LENGTH = 65;

	variableAndValue currSW;


	


	// The open configuration file.
	SDConfigFile cfg;

	// Open the configuration file.
	if (!cfg.begin(CONFIG_FILE, CONFIG_LINE_LENGTH))
	{
#ifdef ServerDEBUG
		SERIALPRINT(F("Failed to open configuration file: "));
		SERIALPRINTLN(CONFIG_FILE);
#endif
		return false;
	}



	// Read each setting from the file.
	while (cfg.readNextSetting()) {

		// Put a nameIs() block here for each setting you have.

		TMP_STRING1 = cfg.getName();

		if (TMP_STRING1.charAt(0) != '*')
		{
			for (uint8_t i = 0; i < REGISTERED_USER_COUNT; i++)
			{
				if (TMP_STRING1 == "user" + String(i)) 
				{
					currSW = getVarAndValue(cfg.getValue(), true,',');
					user[i] = currSW.vvarName;
					passw[i] = currSW.vvarValue;
					// SPrint(i);     SPrint("\t->\t");  SPrint(cfg->getName());     SPrint("\t=\t");    SPrintln(cfg->getValue());
				
				}
				
			}
		}
	}

	// clean up
	cfg.end();

	return true;
}


boolean readConfigurationGroups(char CONFIG_FILE[]) {
	/*
	 * Length of the longest line expected in the config file.
	 * The larger this number, the more memory is used
	 * to read the file.
	 * You probably won't need to change this number.
	 */
	const uint8_t CONFIG_LINE_LENGTH = 65;

	// The open configuration file.
	SDConfigFile cfg;

	// Open the configuration file.
	if (!cfg.begin(CONFIG_FILE, CONFIG_LINE_LENGTH)) {
#ifdef ServerDEBUG
		SERIALPRINT(F("Failed to open configuration file: "));
		SERIALPRINTLN(CONFIG_FILE);
#endif
		return false;
	}

	// Read each setting from the file.
	while (cfg.readNextSetting()) {

		// Put a nameIs() block here for each setting you have.

		TMP_STRING1 = cfg.getName();

		for (uint8_t i = 0; i < ActiveGroupsCount; i++)
		{
			if (TMP_STRING1 == "webgrplbl" + String(i))
			{
				group[i].lbl = cfg.getValue();

				break;
			}
			else if (TMP_STRING1 == "webgrpvisible" + String(i))
			{
				group[i].enable = (cfg.getIntValue() == 1) ? true : false;

				break;
			}
		}
	}

	// clean up
	cfg.end();

	return true;
}


boolean readConfigurationSwitches(char CONFIG_FILE[]) {
	/*
	 * Length of the longest line expected in the config file.
	 * The larger this number, the more memory is used
	 * to read the file.
	 * You probably won't need to change this number.
	 */
	const uint8_t CONFIG_LINE_LENGTH = 65;

	// The open configuration file.
	SDConfigFile cfg;

	// Open the configuration file.
	if (!cfg.begin(CONFIG_FILE, CONFIG_LINE_LENGTH)) {
#ifdef ServerDEBUG
		SERIALPRINT(F("Failed to open configuration file: "));
		SERIALPRINTLN(CONFIG_FILE);
#endif
		return false;
	}

	// Read each setting from the file.
	while (cfg.readNextSetting()) {

		// Put a nameIs() block here for each setting you have.

		TMP_STRING1 = cfg.getName();

		for (uint8_t n = 0; n < ActiveSwitchersCount; n++)
		{
			if (TMP_STRING1 == "swlbl" + String(n))
			{
				switcher[n].lbl = cfg.getValue();

				//SPrint("\n\t("+String(i)+ String(n)+ ")");     SPrint("\t->\t");  SPrint(cfg->getName());     SPrint("\t=\t");    SPrint(cfg->getValue()); SPrint("\t=\t");    SPrintln(SwitchWeblabel[i][n]);

				break;
			}
			else if (TMP_STRING1 == "swenable" + String(n))
			{
				switcher[n].enable = (cfg.getIntValue() == 1) ? true : false;
				//SPrint("\n\t("+String(i) + String(n)+ ")");     SPrint("\t->\t");  SPrint(cfg->getName());     SPrint("\t=\t");    SPrint(cfg->getValue()); SPrint("\t=\t");    SPrintln(SwitchWebVisible[i][n]);
				break;
			}
			else if (TMP_STRING1 == "swgrp" + String(n))
			{
				switcher[n].group = cfg.getIntValue();
				//SPrint("\n\t("+String(i) + String(n)+ ")");     SPrint("\t->\t");  SPrint(cfg->getName());     SPrint("\t=\t");    SPrint(cfg->getValue()); SPrint("\t=\t");    SPrintln(SwitchWebVisible[i][n]);
				break;
			}

		}
	}

	// clean up
	cfg.end();

	return true;
}

boolean readConfigurationPresets(char CONFIG_FILE[]) {
	/*
	 * Length of the longest line expected in the config file.
	 * The larger this number, the more memory is used
	 * to read the file.
	 * You probably won't need to change this number.
	 */
	const uint8_t CONFIG_LINE_LENGTH = 65;

	// The open configuration file.
	SDConfigFile cfg;

	// Open the configuration file.
	if (!cfg.begin(CONFIG_FILE, CONFIG_LINE_LENGTH)) {
#ifdef ServerDEBUG
		SERIALPRINT(F("Failed to open configuration file: "));
		SERIALPRINTLN(CONFIG_FILE);
#endif
		return false;
	}

	// Read each setting from the file.
	while (cfg.readNextSetting()) {

		// Put a nameIs() block here for each setting you have.

		TMP_STRING1 = cfg.getName();

		for (uint8_t n = 0; n < 6; n++)
		{
			if (TMP_STRING1 == "prst" + String(n) + "enable")
			{
				preset[n].enable = (cfg.getIntValue() == 1) ? true : true;
				

				//SPrint("\n\t("+String(i)+ String(n)+ ")");     SPrint("\t->\t");  SPrint(cfg->getName());     SPrint("\t=\t");    SPrint(cfg->getValue()); SPrint("\t=\t");    SPrintln(SwitchWeblabel[i][n]);

				break;
			}
			else if (TMP_STRING1 == "prst" + String(n) + "label")
			{
				
				preset[n].lbl = cfg.getValue();
				//SPrint("\n\t("+String(i) + String(n)+ ")");     SPrint("\t->\t");  SPrint(cfg->getName());     SPrint("\t=\t");    SPrint(cfg->getValue()); SPrint("\t=\t");    SPrintln(SwitchWebVisible[i][n]);
				break;
			}
			else if (TMP_STRING1 == "prst" + String(n) + "states")
			{
				
				preset[n].states = cfg.getValue();
				//SPrint("\n\t("+String(i) + String(n)+ ")");     SPrint("\t->\t");  SPrint(cfg->getName());     SPrint("\t=\t");    SPrint(cfg->getValue()); SPrint("\t=\t");    SPrintln(SwitchWebVisible[i][n]);
				break;
			}

		}
	}

	// clean up
	cfg.end();

	return true;
}


boolean readConfigurationHeater(char CONFIG_FILE[]) {
	/*
	 * Length of the longest line expected in the config file.
	 * The larger this number, the more memory is used
	 * to read the file.
	 * You probably won't need to change this number.
	 */
	const uint8_t CONFIG_LINE_LENGTH = 65;

	// The open configuration file.
	SDConfigFile cfg;

	// Open the configuration file.
	if (!cfg.begin(CONFIG_FILE, CONFIG_LINE_LENGTH)) {
#ifdef ServerDEBUG
		SERIALPRINT(F("Failed to open configuration file: "));
		SERIALPRINTLN(CONFIG_FILE);
#endif
		return false;
	}
	/*

	// Read each setting from the file.
	while (cfg.readNextSetting()) {

		// Put a nameIs() block here for each setting you have.

		TMP_STRING1 = cfg.getName();

		for (uint8_t n = 0; n < 6; n++)
		{
			if (TMP_STRING1 == "prst" + String(n) + "enable")
			{
				preset[n].enable = (cfg.getIntValue() == 1) ? true : true;


				//SPrint("\n\t("+String(i)+ String(n)+ ")");     SPrint("\t->\t");  SPrint(cfg->getName());     SPrint("\t=\t");    SPrint(cfg->getValue()); SPrint("\t=\t");    SPrintln(SwitchWeblabel[i][n]);

				break;
			}
	
			else if (TMP_STRING1 == "prst" + String(n) + "states")
			{

				preset[n].states = cfg.getValue();
				//SPrint("\n\t("+String(i) + String(n)+ ")");     SPrint("\t->\t");  SPrint(cfg->getName());     SPrint("\t=\t");    SPrint(cfg->getValue()); SPrint("\t=\t");    SPrintln(SwitchWebVisible[i][n]);
				break;
			}

		}
	}


	*/
	// clean up
	cfg.end();

	return true;
}
