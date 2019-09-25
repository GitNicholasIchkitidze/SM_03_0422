String getTokenFromString(String theString, char separator, uint8_t tokenIndex, uint8_t stopPosIndex, boolean DDebug = false)
{
	uint8_t found = 0;
	int strIndex[] = { 0, -1 };
	//int maxIndex = data.length()-1;

	--stopPosIndex;

	for (int i = 0; i <= stopPosIndex && found <= tokenIndex; i++) 
	{
		if (theString.charAt(i) == separator || i == stopPosIndex) 
		{
			found++;
			strIndex[0] = strIndex[1] + 1;
			strIndex[1] = (i == stopPosIndex) ? i + 1 : i;
		}
	}

//*#ifdef ServerDEBUG 
	(DDebug && found >= tokenIndex) ? SERIALPRINTLN("Token N:" + String (tokenIndex) + ", \t" + theString.substring(strIndex[0], strIndex[1]) + "\tStopPos:" + String(stopPosIndex)) : SERIALPRINT(F(""));
//*#endif

	return found >= tokenIndex ? theString.substring(strIndex[0], strIndex[1]) : "";
}


//variableAndValue getVarAndValue(String theString, boolean DDebug = false, char delimChar = '=')
variableAndValue getVarAndValue(String theString, boolean DDebug, char delimChar )
{
	variableAndValue forReturn;


	forReturn.vvarName = getTokenFromString(theString, delimChar, 0, theString.length() - 1, false);
	forReturn.vvarValue = getTokenFromString(theString, delimChar, 1, theString.length(), false);


//*#ifdef ServerDEBUG 
	(DDebug) ? SERIALPRINTLN("Split Token \"" + theString +"\" \tAS\tVariable Name:\t" + forReturn.vvarName + " \tVariable Value:\t" + forReturn.vvarValue) : SERIALPRINT(F(""));
//*#endif

	return forReturn;
}



String GetRidOfurlCharacters(String urlChars)
{



	urlChars.replace(F("%E1%83%90"), F("ა"));
	urlChars.replace(F("%E1%83%91"), F("ბ"));
	urlChars.replace(F("%E1%83%92"), F("გ"));
	urlChars.replace(F("%E1%83%93"), F("დ"));
	urlChars.replace(F("%E1%83%94"), F("ე"));
	urlChars.replace(F("%E1%83%95"), F("ვ"));
	urlChars.replace(F("%E1%83%96"), F("ზ"));
	urlChars.replace(F("%E1%83%97"), F("თ"));
	urlChars.replace(F("%E1%83%98"), F("ი"));
	urlChars.replace(F("%E1%83%99"), F("კ"));
	urlChars.replace(F("%E1%83%9A"), F("ლ"));
	urlChars.replace(F("%E1%83%9B"), F("მ"));
	urlChars.replace(F("%E1%83%9C"), F("ნ"));
	urlChars.replace(F("%E1%83%9D"), F("ო"));
	urlChars.replace(F("%E1%83%9E"), F("პ"));
	urlChars.replace(F("%E1%83%9F"), F("ჟ"));
	urlChars.replace(F("%E1%83%A0"), F("რ"));
	urlChars.replace(F("%E1%83%A1"), F("ს"));
	urlChars.replace(F("%E1%83%A2"), F("ტ"));
	urlChars.replace(F("%E1%83%A3"), F("უ"));
	urlChars.replace(F("%E1%83%A4"), F("ფ"));
	urlChars.replace(F("%E1%83%A5"), F("ქ"));
	urlChars.replace(F("%E1%83%A6"), F("ღ"));
	urlChars.replace(F("%E1%83%A7"), F("ყ"));
	urlChars.replace(F("%E1%83%A8"), F("შ"));
	urlChars.replace(F("%E1%83%A9"), F("ჩ"));
	urlChars.replace(F("%E1%83%AA"), F("ც"));
	urlChars.replace(F("%E1%83%AB"), F("ძ"));
	urlChars.replace(F("%E1%83%AC"), F("წ"));
	urlChars.replace(F("%E1%83%AD"), F("ჭ"));
	urlChars.replace(F("%E1%83%AE"), F("ხ"));
	urlChars.replace(F("%E1%83%AF"), F("ჯ"));
	urlChars.replace(F("%E1%83%B0"), F("ჰ"));
	urlChars.replace(F("%20"), F(" "));



	return urlChars;
}


uint8_t getCorrespondArrIndex(String theString)
{
	//	String tmpStr;
	uint8_t tmpuint;

	//	Serial.println("theString= " + theString);
	TMP_STRING_LOCAL = theString.substring(2, 4);
	//	Serial.println("tmpStr= " + tmpStr);

	switch (theString.charAt(2))
	{
	case '0':
	{
		tmpuint = TMP_STRING_LOCAL.toInt();
		break;
	}
	case '1':
	{
		tmpuint = TMP_STRING_LOCAL.toInt() - 2;
		break;
	}
	case '2':
	{
		tmpuint = TMP_STRING_LOCAL.toInt() - 4;
		break;
	}
	case '3':
	{
		tmpuint = TMP_STRING_LOCAL.toInt() - 6;
		break;
	}


	}

	return tmpuint;

}


uint8_t count_charInString(String s, char cchar) {
	int count = 0;

	for (uint16_t i = 0; i < s.length()-1; i++)
	{
		if (s[i] == cchar) 	count++;
	}
	return count;
}
