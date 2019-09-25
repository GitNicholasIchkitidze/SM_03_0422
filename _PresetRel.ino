void saveCurrentStatesinPreset(uint8_t prstNum, String lblStr)
{

	//TMP_STRING_LOCAL = getTokenFromString(lblStr, '=', 1, lblStr.length() - 1);
	preset[prstNum].enable = true;
	preset[prstNum].lbl = GetRidOfurlCharacters(lblStr);
	preset[prstNum].states = "";
	for (uint8_t i = 0; i < ActiveSwitchersCount; i++)
	{
		preset[prstNum].states += String(switcher[i].state);
	}

	//	Serial.println(preset[prstNum].states);

}

void saveStatesOnlyInPreset(uint8_t prstNum, String StateStr)
{

	//SERIALPRINT("::" + String(prstNum));
	//SERIALPRINT("::" + StateStr);

	//TMP_STRING_LOCAL = getTokenFromString(lblStr, '=', 1, lblStr.length() - 1);
	preset[prstNum].enable = true;
	//preset[prstNum].lbl = GetRidOfurlCharacters(lblStr);
	preset[prstNum].states = StateStr;

	//	Serial.println(preset[prstNum].states);

}
//
//
//void _saveStatesinPreset(uint8_t prstNum, String prstlbl, String prstSwitchersStates )
//{
//
//	//TMP_STRING_LOCAL = getTokenFromString(prstlbl, '=', 1, prstlbl.length() - 1);
//	preset[prstNum].enable = true;
//
//	(prstlbl != "") ? preset[prstNum].lbl = GetRidOfurlCharacters(prstlbl) : preset[prstNum].lbl = preset[prstNum].lbl;
//	
//	//preset[prstNum].lbl = GetRidOfurlCharacters(prstlbl);
//	//preset[prstNum].states = "";
//	preset[prstNum].states = prstSwitchersStates;
//
//
//	//for (uint8_t i = 0; i < ActiveSwitchersCount; i++)
//	//{
//	//	preset[prstNum].states += prstSwitchersStates[i];
//	//}
//
//	//	Serial.println(preset[prstNum].states);
//
//}

void deleteStatesinPreset(uint8_t prstNum)
{

	preset[prstNum].enable = false;
	preset[prstNum].lbl = "preset" + String(prstNum);
	//for (uint8_t i = 0; i < ActiveSwitchersCount; i++)
	//{
		//preset[prstNum].states[i] = 'x';
		preset[prstNum].states = F("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
	//}

	//	Serial.println(preset[prstNum].states);
}

void doPresetJob(uint8_t prstNum)
{



	for (uint8_t i = 0; i < ActiveSwitchersCount; i++)
	{
		if ((preset[prstNum].states[i] == '1') || (preset[prstNum].states[i] == '0'))
		{
			if (String(switcher[i].state) != String(preset[prstNum].states[i]))
				_doSwAction(i);
		}

	}

	//Serial.println(preset[prstNum].states);
}
