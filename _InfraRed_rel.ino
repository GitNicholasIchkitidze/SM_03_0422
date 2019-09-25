void _sendircommand1(uint8_t irCmdNum)
{
  //IRSend irsend;

  //unsigned int irBuffer[] = { 4400,4250, 600,1550, 550,500, 550,1550, 550,1550, 600,500, 550,500, 550,1550, 550,550, 500,550, 550,1550, 550,500, 550,500, 550,1550, 600,1550, 550,500, 550,1550, 550,550, 500,1600, 550,1550, 550,1550, 550,1550, 600,500, 550,1550, 550,1550, 600,1550, 550,500, 550,500, 550,550, 500,550, 500,1550, 600,500, 550,500, 550,1550, 550,1550, 600,1550, 550,500, 550,550, 500,550, 500,550, 550,500, 550,500, 550,500, 550,500, 550,1600, 500,1600, 550,1550, 550,1600, 500,1600, 550 }; //AnalysIR Batch Export (IRremote) - RAW
  unsigned int irBuffer[] = { 8900, 4400, 550, 550, 600, 1600, 600, 500, 600, 500, 600, 1650, 600, 1600, 600, 500, 600, 1650, 550, 1650, 600, 500, 600, 1600, 600, 1650, 600, 500, 600, 500, 600, 1600, 600, 550, 550, 550, 550, 550, 600, 1600, 600, 1600, 600, 1650, 600, 500, 600, 1600, 600, 1650, 600, 1600, 600, 1600, 600, 500, 600, 550, 550, 550, 550, 1650, 600, 500, 600, 500, 650};




  //currentIrBufferLength = sizeof(irBuffer);

  //mySender.send(irBuffer, sizeof(irBuffer), 38);//Pass the buffer,length, optionally frequency

  IRsendRaw mySender;

  mySender.send(irBuffer, sizeof(irBuffer), 36);//Pass the buffer,length, optionally frequency
  SERIALPRINTLN(F("Sent signal."));

  Serial.println(F("Code sent!"));
  Serial.println();



  delay(500);

}

void _sendircommand2(uint8_t irCmdNum)
{
  //writeFileForSDToI2CEEPROOM("SERVER1.txt");
}

void _sendircommand22(uint8_t irCmdNum)
{

  //IRSend irsend;

  //unsigned int irBuffer[] = { 4400,4250, 600,1550, 550,500, 550,1550, 550,1550, 600,500, 550,500, 550,1550, 550,550, 500,550, 550,1550, 550,500, 550,500, 550,1550, 600,1550, 550,500, 550,1550, 550,550, 500,1600, 550,1550, 550,1550, 550,1550, 600,500, 550,1550, 550,1550, 600,1550, 550,500, 550,500, 550,550, 500,550, 500,1550, 600,500, 550,500, 550,1550, 550,1550, 600,1550, 550,500, 550,550, 500,550, 500,550, 550,500, 550,500, 550,500, 550,500, 550,1600, 500,1600, 550,1550, 550,1600, 500,1600, 550 }; //AnalysIR Batch Export (IRremote) - RAW
  unsigned int irBuffer[] = { 8850, 4400, 600, 500, 600, 1650, 550, 550, 600, 500, 600, 1600, 600, 1650, 550, 550, 550, 1650, 600, 1600, 600, 550, 550, 1650, 600, 1600, 600, 500, 600, 500, 600, 1650, 600, 500, 600, 500, 600, 500, 600, 1650, 550, 1650, 600, 1600, 600, 500, 600, 1650, 600, 1600, 600, 1650, 550, 1650, 600, 500, 600, 500, 650, 450, 650, 1600, 600, 500, 600, 500, 600 };





  //currentIrBufferLength = sizeof(irBuffer);

  //mySender.send(irBuffer, sizeof(irBuffer), 38);//Pass the buffer,length, optionally frequency

  IRsendRaw mySender;

  mySender.send(irBuffer, sizeof(irBuffer), 36);//Pass the buffer,length, optionally frequency
  Serial.println(F("Sent signal."));

  Serial.println(F("Code sent!"));
  Serial.println();



  delay(500);

}



void doInfraJob(uint8_t irCmdNum)
{

  //*#ifdef ServerDEBUG
  SERIALPRINTLN("Infra cmd DONE " + String(irCmdNum));
  //*#endif

  if (irCmdNum == 0)
    _sendircommand1(irCmdNum);
  else if (irCmdNum == 1)
    _sendircommand2(irCmdNum);
  else
    sendircommand(irCmdNum);


  //Serial.println(preset[prstNum].states);
}

/*
  void sendircommand(uint8_t irCmdNum)
  {
	//IRsend irsend;
	//unsigned int rawCodes[RAWBUF];
	String tmpStr = getIrCommand(irCmdNum);
	uint8_t r = 0, t = 0;

	for (int i = 0; i < tmpStr.length() - 1; i++)
	{
		if (tmpStr.charAt(i) == ',')
		{
			rawCodes[t] = tmpStr.substring(r, i).toInt();
			Serial.println(rawCodes[t]);
			r = (i + 1);

			t++;
		}
	}

	//irsend.sendRaw(rawCodes, sizeof(rawCodes), 38);
  }

*/



void sendircommand(uint8_t irCmdNum)
{

  IRsendRaw mySender;
  String tmpStr = getIrCommand(irCmdNum);


  uint8_t r = 0, t = 0;

  //const size_t bufferSize = count_charInString(tmpStr, ',') + 1;
  uint16_t irBuffer[100];

  for (uint16_t i = 0; i < tmpStr.length() - 1; i++)
  {
    if (tmpStr.charAt(i) == ',')
    {
      irBuffer[t] = tmpStr.substring(r, i).toInt();
      Serial.println(irBuffer[t]);
      r = (i + 1);

      t++;
    }
  }










  mySender.send(irBuffer, sizeof(irBuffer), 38);//Pass the buffer,length, optionally frequency
  Serial.println(F("Sent signal."));

  Serial.println(F("Code sent!"));
  Serial.println();



  delay(50);

}


String getIrCommand(uint8_t irCmdNum)
{
  char CONFIG_FILE[14];
  String tmpStr = "ircmd" + (irCmdNum < 10 ? "0" + String(irCmdNum) : String(irCmdNum)) + ".txt";
  tmpStr.toCharArray(CONFIG_FILE, 14);

  //return "4400, 4250, 600, 1550, 550, 500, 550, 1550, 550, 1550, 600, 500, 550, 500, 550, 1550, 550, 550, 500, 550, 550, 1550, 550, 500, 550, 500, 550, 1550, 600, 1550, 550, 500, 550, 1550, 550, 550, 500, 1600, 550, 1550, 550, 500, 550, 500, 550, 500, 550, 1600, 500, 1600, 550, 1550, 550, 1600, 500, 1600, 550";
  return readIRcmdfromSD(CONFIG_FILE);


}

String readIRcmdfromSD(char CONFIG_FILE[]) {
  /*
     Length of the longest line expected in the config file.
     The larger this number, the more memory is used
     to read the file.
     You probably won't need to change this number.
  */
  //const uint8_t CONFIG_LINE_LENGTH = 650;
  String tmpstr = "ERROR";

  // The open configuration file.
  SDConfigFile cfg;

  // Open the configuration file.
  if (!cfg.begin(CONFIG_FILE, 100))
  {
#ifdef ServerDEBUG
    SERIALPRINT(F("Failed to open configuration file: "));
    SERIALPRINTLN(CONFIG_FILE);
#endif
    return tmpstr;
  }



  // Read each setting from the file.
  tmpstr = "";
  while (cfg.readNextSetting()) {

    // Put a nameIs() block here for each setting you have.

    TMP_STRING1 = cfg.getName();

    if (TMP_STRING1.charAt(0) != '*')
    {

      if (TMP_STRING1 == "rawcmd") {
        tmpstr += cfg.getValue();
        // SPrint(i);     SPrint("\t->\t");  SPrint(cfg->getName());     SPrint("\t=\t");    SPrintln(cfg->getValue());

      }



    }
  }

  // clean up
  cfg.end();


  //SERIALPRINTLN(F("ჰავე ბეენ ჰერე"));
  return tmpstr;
}
