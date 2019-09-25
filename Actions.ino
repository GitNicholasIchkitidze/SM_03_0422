void _ax_SW_Action(EthernetClient * client, String request, bool DDEBUG = false)

{
	variableAndValue currSW;


	currSW = getVarAndValue(getTokenFromString(request, '&', 1, request.indexOf("&nc"), true), true);




	_doSwAction(currSW.vvarValue.toInt());
	_responseOneSwitchJSON(*(&client), currSW.vvarValue.toInt());


}


void _ax_GA_Action(EthernetClient * client, String request, bool DDEBUG = false)

{
	variableAndValue currSW;


	currSW = getVarAndValue(getTokenFromString(request, '&', 1, request.indexOf("&nc"), true), true);

	//if (switcher[currSW.vvarValue.toInt()].state != ;

	//SERIALPRINTLN("****");
	//SERIALPRINTLN(currSW.vvarName);
	//SERIALPRINTLN(currSW.vvarValue);
	//SERIALPRINTLN("****");

	//_doSwAction(currSW.vvarValue.substring(2, 4).toInt());
	//_responseOneSwitchJSON(*(&client), currSW.vvarValue.substring(2,4).toInt());

	_doSwAction(currSW.vvarValue.toInt());
	_responseOneSwitchJSON(*(&client), currSW.vvarValue.toInt());


}

/*
void _ax_SW_Action_(EthernetClient * client, String request, bool DDEBUG = false)

{
	variableAndValue currSW;
	uint8_t ArrIndex;

	//printFreeMem(F("IN _ax_SW_Action"));
	TMP_STRING1 = getTokenFromString(request, '&', 1, request.indexOf("&nc"), true);


	TMP_STRING1 = TMP_STRING1.substring(2, 4);

	////#ifdef ServerDEBUG 
	SERIALPRINTLN(TMP_STRING1);
	////#endif

	currSW = getVarAndValue(TMP_STRING1);

	ArrIndex = TMP_STRING1.toInt();

	////#ifdef ServerDEBUG 
	SERIALPRINTLN(ArrIndex);
	////#endif
	//ArrIndex = getCorrespondArrIndex(currSW.vvar);



	_doSwAction(ArrIndex);
	_responseOneSwitchJSON(*(&client), ArrIndex);


	//Serial.println(currSW.vvar);
	//Serial.println(String(ArrIndex));

	//printFreeMem(F("OUT _ax_SW_Action"));	

	//TMP_STRING2 = getTokenFromString(String(HTTP_req),'&',2,String(HTTP_req).indexOf("&nc"));
}

*/

bool _doSwAction(uint8_t i)
{



#if defined (DEBUG_SERIAL)


	//SPrint("\ncorrespond chip " + String(switcher[i].extenderChipNum) + " Pin " + String(switcher[i].extenderChipPinNum) + ", Arduino PIN OUT " + String(OutPPins[i][n]) + ", Command SET Switch From " + String(OutPPinsstate[i][n]) + " To - " + String(!OutPPinsstate[i][n]) + ";\n");
	//SPrint("\nBefore:\t\t\t\tOutPPinsstate[" + String(i) + "][" + String(n) + "] = " + String(OutPPinsstate[i][n]) + ";\t\tdigitalREAD pin N " + String(OutPPins[i][n]) + " = " + String(digitalRead(OutPPins[i][n])) + ";\n");

#endif


	//I2C
//	if (i == 0) 
//	{


//		_doPinI2C_MCP23017(i, 3, HIGH);
//		delay(WEB_IMPULSE_DURATION);
//		_doPinI2C_MCP23017(i, 3, LOW);
//		delay(WEB_IMPULSE_DURATION);

		/*
		Adafruit_MCP23017 mcp;


		//SERIALPRINTLN(String(i));
		mcp.begin(0);
		mcp.pinMode(0, OUTPUT);
		mcp.pinMode(1, OUTPUT);
		mcp.pinMode(2, OUTPUT);
		mcp.pinMode(3, OUTPUT);
		mcp.pinMode(4, OUTPUT);
		mcp.pinMode(5, OUTPUT);
		mcp.pinMode(6, OUTPUT);
		mcp.pinMode(7, OUTPUT);

		mcp.pinMode(8, OUTPUT);
		mcp.pinMode(9, OUTPUT);
		mcp.pinMode(10, OUTPUT);
		mcp.pinMode(11, OUTPUT);
		mcp.pinMode(12, OUTPUT);
		mcp.pinMode(13, OUTPUT);
		mcp.pinMode(14, OUTPUT);
		mcp.pinMode(15, OUTPUT);


		//mcp.pullUp(0);
		mcp.digitalWrite(0, LOW);
		mcp.digitalWrite(1, LOW);
		mcp.digitalWrite(2, LOW);
		mcp.digitalWrite(3, HIGH);
		mcp.digitalWrite(4, LOW);
		mcp.digitalWrite(5, LOW);
		mcp.digitalWrite(6, LOW);
		mcp.digitalWrite(7, LOW);
		mcp.digitalWrite(8, LOW);
		mcp.digitalWrite(9, LOW);
		mcp.digitalWrite(10, LOW);
		mcp.digitalWrite(11, LOW);
		mcp.digitalWrite(12, HIGH);
		mcp.digitalWrite(13, LOW);
		mcp.digitalWrite(14, LOW);
		mcp.digitalWrite(15, LOW);

		delay(100);
		//mcp.digitalWrite(9, LOW);

		//Serial.println(mcp.readGPIO(0));
		//Serial.println(mcp.readGPIO(0), BIN);
		//Serial.println(mcp.readGPIOAB(), BIN);


		*/



		//Wire.beginTransmission(0x20);
		//Wire.write(0x00); // IODIRA register
		//Wire.write(0x00); // set entire PORT A to output
		//Wire.endTransmission();

		//WriteMCP(0x20, GPIOB, HIGH);
//	}

//	else
//	{

	digitalWrite(switcher[i].ControllerPinNum, HIGH);




	delay(WEB_IMPULSE_DURATION);
	digitalWrite(switcher[i].ControllerPinNum, LOW);
	//	}


		//OutPPinsstate[i][n] = !OutPPinsstate[i][n];
	switcher[i].state = !switcher[i].state;




	return switcher[i].state;

}




void _ap_PRST_Action(EthernetClient * cl, String request, bool DDEBUG = false)
{


	variableAndValue token1 = getVarAndValue(getTokenFromString(request, '&', 1, request.indexOf("&nc"), true));
	

	if (token1.vvarName.indexOf("cmd") > -1)
	{
		variableAndValue token2 = getVarAndValue(getTokenFromString(request, '&', 2, request.indexOf("&nc"), true));

		if (token1.vvarValue == "do")
		{
			doPresetJob(token2.vvarValue.toInt());
			_responseGenericJSON_(*(&cl));
		}

		else
		{

			sysMsg = "Preset Edit Failed after restarting controller editings will be lost";
		

			if (token1.vvarValue == "0")
			{
				deleteStatesinPreset(token2.vvarValue.toInt());
			}
			else if (token1.vvarValue == "1")
			{
				
				variableAndValue token3 = getVarAndValue(getTokenFromString(request, '&', 3, request.indexOf("&nc"), true));

				saveCurrentStatesinPreset(token2.vvarValue.toInt(), token3.vvarValue);
				//_saveStatesinPreset(token1.vvarValue.toInt(), "", token2.vvarValue);
			}


			if (savePrestsSD())
				sysMsg = "user Edited preset OK";

			_response_MD_JSON_(*(&cl));
		}

	}

	
	

	
}


void _ax_GMD_Action(EthernetClient * cl, String request, bool DDEBUG = false)

{
	//boolean tmpBool;
	variableAndValue token1;
	variableAndValue token2;
	//uint8_t ArrIndex;



	//TMP_STRING1 = getTokenFromString(request, '&', 1, request.indexOf("&nc"));
	//TMP_STRING2 = getTokenFromString(request, '&', 2, request.indexOf("&nc"));
	//Serial.println(TMP_STRING1);
	//Serial.println(TMP_STRING2);

	
	token1 = getVarAndValue(getTokenFromString(request, '&', 1, request.indexOf("&nc"), true));

	token2 = getVarAndValue(getTokenFromString(request, '&', 2, request.indexOf("&nc"), true));

	if (token1.vvarName.indexOf("mGrpLbl") > -1)

		group[token1.vvarValue.toInt()].lbl = GetRidOfurlCharacters(token2.vvarValue);
	else if (token1.vvarName.indexOf("msw") > -1)
		switcher[token1.vvarValue.toInt()].lbl = GetRidOfurlCharacters(token2.vvarValue);
	else if (token1.vvarName.indexOf("mGrpChBx") > -1)
	{

		(token2.vvarValue == "1") ? group[token1.vvarValue.toInt()].enable = true : group[token1.vvarValue.toInt()].enable = false;

		/*
		if (token2.vvarValue == "1")
		{
			group[token1.vvarValue.toInt()].enable = true;
			//Serial.println("::::::: \t setting " + String(currGrp.vvalue.toInt())  + " to " + true);
		}
		else
		{
			group[token1.vvarValue.toInt()].enable = false;
		//Serial.println("::::::: \t setting " + String(currGrp.vvalue.toInt()) + " to " + false);
		}
		*/
	}
	else if (token1.vvarName.indexOf("mChBx") > -1)
	{
		(token2.vvarValue == "1") ? switcher[token1.vvarValue.toInt()].enable = true : switcher[token1.vvarValue.toInt()].enable = false;
		/*
		//Serial.println(":::::::"+ currGrpLbl.vvalue);
		if (token2.vvarValue == "1")
		{
			switcher[token1.vvarValue.toInt()].enable = true;
			//Serial.println("::::::: \t setting " + String(currGrp.vvalue.toInt())  + " to " + true);
		}
		else
		{
			switcher[token1.vvarValue.toInt()].enable = false;
			//Serial.println("::::::: \t setting " + String(currGrp.vvalue.toInt()) + " to " + false);
		}
		*/
	}









	_responseGenericJSON_(*(&cl));

}


void _ax_MD_Action(EthernetClient * cl, String request, bool DDEBUG = false)
{
//boolean tmpBool;
	//variableAndValue currSW;
//	uint8_t ArrIndex;
	TMP_STRING1 = getTokenFromString(request, '&', 1, request.indexOf("&nc"), true);
	//TMP_STRING2 = getTokenFromString(request, '&', 2, request.indexOf("&nc"), true);
	//variableAndValue token1 = getVarAndValue(getTokenFromString(request, '&', 1, request.indexOf("&nc"), true), true);

	if (TMP_STRING1 == "save=1")
	{
		SERIALPRINTLN("1111");
	}
	else if (TMP_STRING1 == "save=1p")
	{

		
		variableAndValue token2 = getVarAndValue(getTokenFromString(request, '&', 2, request.indexOf("&nc"), true),true);
		variableAndValue token3 = getVarAndValue(getTokenFromString(request, '&', 3, request.indexOf("&nc"), true),true);

		sysMsg = "Preset Edit Failed after restarting controller editings will be lost";


		//SERIALPRINTLN(String(token2.vvarValue.toInt()));


		saveStatesOnlyInPreset(token2.vvarValue.toInt(), token3.vvarValue);
		

		if (savePrestsSD())
			sysMsg = "user Edited preset OK";

			   		 	  	


	}
	else if (TMP_STRING1 == "save=2")
	{

	}
	//else if (TMP_STRING1 == "save=3")			//// MOMXMAREBLEBI TAB
	//{

	//		SERIALPRINTLN(TMP_STRING1);

	//	/// ax_MD & save = 3 & edituser = user22 & newuser = admin & curpass = 22user&newpass = admin

	//	sysMsg = "user Edit Failed to save. After restarting controller editings will be lost";

	//	for (uint8_t i = 0; i < REGISTERED_USER_COUNT; i++)
	//	{
	//		if ((currentUser == "admin") && (user[i] == getVarAndValue(TMP_STRING2, true).vvarValue))
	//		{
	//			user[i] = getVarAndValue(getTokenFromString(request, '&', 3, request.indexOf("&nc")), true).vvarValue;
	//			passw[i] = getVarAndValue(getTokenFromString(request, '&', 5, request.indexOf("&nc")), true).vvarValue;
	//			break;
	//		}
	//		else if (((currentUser != "admin") && (user[i] == getVarAndValue(TMP_STRING2, true).vvarValue))
	//			&& (passw[i] == getVarAndValue(getTokenFromString(request, '&', 4, request.indexOf("&nc"))).vvarValue, true) )

	//		{
	//			user[i] = getVarAndValue(getTokenFromString(request, '&', 3, request.indexOf("&nc")), true).vvarValue;
	//			passw[i] = getVarAndValue(getTokenFromString(request, '&', 5, request.indexOf("&nc")), true).vvarValue;

	//			break;
	//		}
	//	}

	//	if (saveUsersAndPasswInSD())
	//		sysMsg = "user Edited OK";

	//	_responseGenericJSON_(*(&cl));
	//}



}
//
//void _ax_MD_Action_(EthernetClient * cl, String request, bool DDEBUG = false)
//
//{
//	boolean tmpBool;
//	variableAndValue currSW;
//	uint8_t ArrIndex;
//
//
//
//	TMP_STRING1 = getTokenFromString(request, '&', 1, request.indexOf("&nc"),true);
//	TMP_STRING2 = getTokenFromString(request, '&', 2, request.indexOf("&nc"),true);
////#ifdef ServerDEBUG 
////	SERIALPRINTLN(TMP_STRING1);
////	SERIALPRINTLN(TMP_STRING2);
////#endif
//
//	if (TMP_STRING1.indexOf("sw") > -1)
//	{
//		if (TMP_STRING1.charAt(5) == '1')
//			tmpBool = true;
//		else
//			tmpBool = false;
//
//		currSW = getVarAndValue(TMP_STRING1);
//		ArrIndex = getCorrespondArrIndex(currSW.vvarName);
//
//		switcher[ArrIndex].enable = tmpBool;
//		//CurrValue = GetRidOfurlCharacters(TMP_STRING2.substring(4, TMP_STRING2.length()));
//		//						Serial.println(CurrValue);
//		switcher[ArrIndex].lbl = GetRidOfurlCharacters(TMP_STRING2.substring(4, TMP_STRING2.length()));
//	}
//	else if (TMP_STRING1.indexOf("grp") > -1)
//	{
//		if (TMP_STRING1.charAt(5) == '1')
//			group[String(TMP_STRING1.charAt(3)).toInt()].enable = true;
//		else
//			group[String(TMP_STRING1.charAt(3)).toInt()].enable = false;
//
//		group[String(TMP_STRING1.charAt(3)).toInt()].lbl = GetRidOfurlCharacters(TMP_STRING2.substring(4, TMP_STRING2.length()));
//	}
//	else if (TMP_STRING1.indexOf("save=0") > -1)
//	{
//
//
//		saveAllInSD();
//	}
//	else if (TMP_STRING1.indexOf("save=1") > -1)
//	{
//
//		variableAndValue token1;
//		variableAndValue token2;
//
//		token1 = getVarAndValue(getTokenFromString(request, '&', 2, request.indexOf("&nc")));
//		
//
//		token2 = getVarAndValue(getTokenFromString(request, '&', 3, request.indexOf("&nc")));
//#ifdef ServerDEBUG 
//		SERIALPRINTLN(_printVarAndVal(token1));
//		SERIALPRINTLN(_printVarAndVal(token2));
//#endif
//
//		_saveStatesinPreset(token1.vvarValue.toInt(), "", token2.vvarValue);
//		saveAllInSD();
//
//	}
//
//	else if (TMP_STRING1.indexOf("save=3") > -1)
//	{
//		SERIALPRINTLN("SAVE = 3");
//		//SERIALPRINTLN(getTokenFromString(request, '&', 1, request.indexOf("&nc")));
//		//SERIALPRINTLN(getTokenFromString(request, '&', 2, request.indexOf("&nc")));
//		//SERIALPRINTLN(getTokenFromString(request, '&', 3, request.indexOf("&nc")));
//		//SERIALPRINTLN(getTokenFromString(request, '&', 4, request.indexOf("&nc")));
//		//SERIALPRINTLN(getTokenFromString(request, '&', 5, request.indexOf("&nc")));
//
//
//		sysMsg = "user Edit Failed after restarting controller editing will be lost";
//
//		for (uint8_t i = 0; i < REGISTERED_USER_COUNT; i++)
//		{
//			if ((user[i] == getVarAndValue(getTokenFromString(request, '&', 2, request.indexOf("&nc"))).vvarValue, true)
//				&& (passw[i] == getVarAndValue(getTokenFromString(request, '&', 4, request.indexOf("&nc"))).vvarValue, true))
//
//			{
//				user[i] = getVarAndValue(getTokenFromString(request, '&', 3, request.indexOf("&nc")),true).vvarValue;
//				passw[i] = getVarAndValue(getTokenFromString(request, '&', 5, request.indexOf("&nc")),true).vvarValue;
//				if (saveUsersAndPasswInSD())
//					sysMsg = "user Edited OK";
//
//#ifdef ServerDEBUG 
//				SERIALPRINTLN(user[i] + "\t" + passw[i]);
//#endif
//				break;
//			}
//		}
//
//
//
//
//		//saveAllInSD();
//	}
//
//
//	_responseGenericJSON_(*(&cl));
//}
//
//

void _ax_DND_Action(EthernetClient * cl, String request, bool DDEBUG = false)

{
	//printFreeMem(F("IN ax_DND_Action"));	

	TMP_STRING1 = getTokenFromString(request, '&', 1, request.indexOf("&nc"));
	TMP_STRING2 = getTokenFromString(TMP_STRING1, '=', 1, TMP_STRING1.length());
	TMP_STRING1 = getTokenFromString(TMP_STRING1, '=', 0, TMP_STRING1.length());

	//		Serial.println(TMP_STRING1);
	//		Serial.println(TMP_STRING2);	

	for (uint8_t i = 0; i < ActiveSwitchersCount; i++)
	{
		if (switcher[i].id == TMP_STRING1)
		{
			switcher[i].group = TMP_STRING2.toInt();
			//_doSwAction(i);
			_responseOneSwitchJSON(*(&cl), i);
			// 			Serial.print("***\t");

			// 			Serial.println(i);
			break;

		}
	}


	//printFreeMem(F("OUT ax_DND_Action"));
}



void _ar_INFR_Action(EthernetClient * cl, String request, bool DDEBUG = false)
{


	variableAndValue token1;
	variableAndValue token2;
	//uint8_t ArrIndex;


	token2 = getVarAndValue(getTokenFromString(request, '&', 2, request.indexOf("&nc")),true);
	//SERIALPRINTLN(_printVarAndVal(token2));

	doInfraJob(token2.vvarValue.toInt());

	/*


		//TMP_STRING1 = getTokenFromString(request, '&', 1, request.indexOf("&nc"));
		//TMP_STRING2 = getTokenFromString(request, '&', 2, request.indexOf("&nc"));
		//Serial.println(TMP_STRING1);
		//Serial.println(TMP_STRING2);

		token1 = getVarAndValue(getTokenFromString(request, '&', 1, request.indexOf("&nc")));
		SERIALPRINTLN(_printVarAndVal(token1));
		if (token1.vvarName.indexOf("cmd") > -1)
		{
			if (token1.vvarValue == "do")
			{
				token2 = getVarAndValue(getTokenFromString(request, '&', 2, request.indexOf("&nc")));
				SERIALPRINTLN(_printVarAndVal(token2));

				doInfraJob(token2.vvarValue.toInt());
			}

			else
			{

					sysMsg = "user Edited preset OK";
			}

		}

	*/
	_responseGenericJSON_(*(&cl));


}
