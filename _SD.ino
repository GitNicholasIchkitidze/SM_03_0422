void saveAllInSD()
{
	saveGrpConfigInSD();
	saveSwInSD();

	savePrestsSD();
	saveUsersAndPasswInSD();
}


bool savePrestsSD()
{
	File SDFile;

	if (SD.exists(F("presets.txt")))
		SD.remove(F("presets.txt"));

	SDFile = SD.open(F("presets.txt"), O_CREAT | O_WRITE);
	//SDFile = SD.open(F("presets.txt"), FILE_WRITE);
	if (SDFile)
	{
		SDFile.println(F("..."));
		for (uint8_t i = 0; i < 6; i++)
		{
			SDFile.println("prst" + String(i) + "enable=" + String(preset[i].enable) + "\n" +
				"prst" + String(i) + "label=" + preset[i].lbl + "\n" +
				"prst" + String(i) + "states=" + preset[i].states);
		}
		SDFile.print(F("..."));
		SDFile.flush();
		SDFile.close();

		return true;
	}
	else
	{
		return false;
	}


}

bool saveSwInSD()
{
	File SDFile;

	if (SD.exists(F("sw.txt")))
		SD.remove(F("sw.txt"));

	SDFile = SD.open(F("sw.txt"), FILE_WRITE);
	if (SDFile)
	{
		SDFile.println(F("..."));
		for (uint8_t i = 0; i < ActiveSwitchersCount; i++)
		{
			SDFile.println("swlbl" + String(i) + "=" + switcher[i].lbl + "\n" +
				"swenable" + String(i) + "=" + String(switcher[i].enable) + "\n" +
				"swgrp" + String(i) + "=" + String(switcher[i].group));
		}
		SDFile.print(F("..."));
		SDFile.flush();
		SDFile.close();

		return true;
	}
	else
	{
		return false;
	}

}


bool saveGrpConfigInSD()
{
	File SDFile;

	if (SD.exists(F("gcfg.txt")))
		SD.remove(F("gcfg.txt"));

	SDFile = SD.open(F("gcfg.txt"), FILE_WRITE);
	if (SDFile)
	{

		SDFile.println(F("..."));
		for (uint8_t i = 0; i < ActiveGroupsCount; i++)
		{
			SDFile.println("webgrplbl" + String(i) + "=" + group[i].lbl + "\n" + "webgrpvisible" + String(i) + "=" + String(group[i].enable));
			//				Serial.println("webgrplbl" + String(i) + "=" + group[i].lbl + "\n" + "webgrpvisible" + String(i) + "=" + String(group[i].enable));
		}
		SDFile.print(F("..."));
		SDFile.flush();
		SDFile.close();

		return true;
	}
	else
	{
		return false;
	}
}



bool saveUsersAndPasswInSD()
{
	File SDFile;

	if (SD.exists(F("users.txt")))
		SD.remove(F("users.txt"));

	SDFile = SD.open(F("users.txt"), FILE_WRITE);
	if (SDFile)
	{

		SDFile.println(F("..."));
		for (uint8_t i = 0; i < REGISTERED_USER_COUNT; i++)
		{
			SDFile.println("user" + String(i) + "=" + user[i]);
			SDFile.println("passw" + String(i) + "=" + passw[i]);
			
		}
		SDFile.print(F("..."));
		SDFile.flush();
		SDFile.close();

		return true;
	}
	else
	{
		return false;
	}

}


bool saveServerConfig()
{
	File SDFile;

	if (SD.exists(F("server1.txt")))
		SD.remove(F("server1.txt"));

	SDFile = SD.open(F("server1.txt"), FILE_WRITE);
	if (SDFile)
	{

		SDFile.println(F("..."));
		for (uint8_t i = 0; i < 4; i++)
		{
			SDFile.println("ip" + String(i) + "=" + String(SERVER_IP[i]));
			
				
		}
		
		SDFile.println(authMode ? F("authMode=1") : F("authMode=0"));
		SDFile.println("port=" + String(SERVER_PORT));
		SDFile.println("WEB_IMPULSE_DURATION=" + String(WEB_IMPULSE_DURATION));
		SDFile.println(presetsAllowed ? F("presetsAllowed=true") : F("presetsAllowed=false"));
		SDFile.println(heaterAllowed ? F("heaterAllowed=true") : F("heaterAllowed=false"));
		SDFile.println(infraRedAllowed ? F("infraRedAllowed=true") : F("infraRedAllowed=false"));
		SDFile.println("infraRedCmdCount=" + String(infraRedCmdCount));
		SDFile.println(useCloud ? F("useCloud=true") : F("useCloud=false"));
		SDFile.println("cloudAddress=" + cloudAddress);
		SDFile.println(F("dndEnabled=true"));
		SDFile.println(useI2C ? F("useI2C=true") : F("useI2C=false"));
		SDFile.println(useSerialComm ? F("useSerialComm=true") : F("useSerialComm=false"));
		SDFile.println(useIFTTT ? F("useIFTTT=true") : F("useIFTTT=false"));

		SDFile.print(F("..."));
		SDFile.flush();
		SDFile.close();

		return true;
	}
	else
	{
		return false;
	}

}
