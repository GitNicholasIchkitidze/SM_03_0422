

void clearEEPROM()
{

	for (uint16_t i = 0; i < EEPROM.length(); i++) {
		if (EEPROM.read(i) != 0)                     //skip already "empty" addresses
		{
			EEPROM.write(i, 0);                       //write 0 to address i
		}
	}
	Serial.println("EEPROM erased");
//	address = 0;                                  //reset address counter
}


/*

void writeFileForSDToI2CEEPROOM(String InFileName)
{


	
	SERIALPRINTLN(F("\n\nwriteFileForSDToI2CEEPROOM\n\n"));



	char ffileName[14];
	int clientCount = 0;
	char tBuf[64];
	byte tBufbyte[1];

	long currentSpot = 0;
	//	long timerReset = 0;
	//	byte counter = 0;

	InFileName.toCharArray(ffileName, 14);

	Wire.begin();
	Wire.setClock(400000); //Let's go fast!


	if (SD.exists(ffileName))
	{

		// SRAM chec

		SERIALPRINT(F("SRAM = "));
		SERIALPRINTLN(freeRam());

		SERIALPRINT(ffileName);
		SERIALPRINT(F("\t\tFILE found.."));



		File mmyFile = SD.open(ffileName);

		if (!mmyFile)
		{

			SERIALPRINTLN(F("open error"));

			//sendFileNotFound(client);
			return;
			SERIALPRINTLN(F("open error"));

			//sendFileNotFound(client);
			return;
		}
		else

			SERIALPRINTLN(F("opened.."));




		SERIALPRINTLN("Starting POS: " + String(currentSpot));
		SERIALPRINTLN("[buff] ->");
		SERIALPRINTLN(tBuf);
		SERIALPRINT("<-[buff]\t");
		SERIALPRINT("[Length of buff =\t");
		SERIALPRINT(String(sizeof(tBuf)));
		SERIALPRINTLN(" ]\t");





		while (mmyFile.available())
		{
			//clientCount = mmyFile.read(tBuf, 64);
			clientCount = mmyFile.read(tBufbyte, 1);


//			SERIALPRINTLN("Current POS: " + String(currentSpot));
//			SERIALPRINTLN("[buff] ->");
//			SERIALPRINTLN(tBuf);
//			SERIALPRINT("<-[buff]\t");
//			SERIALPRINT("\t\t[Length of buff =\t");
//			SERIALPRINT(String(sizeof(tBuf)));
//			SERIALPRINTLN(" ]\t\n");



//			writeEEPROMPage(currentSpot, (byte*)tBuf);
//			currentSpot += 64;

			writeEEPROMbyte(currentSpot, (byte*)tBufbyte);
			currentSpot ++;


			//client.write((byte*)tBuf, clientCount);
		}



		SERIALPRINTLN("Pointer END POS: " + String(currentSpot));

		mmyFile.flush();
		mmyFile.close();

	}
	else
	{

		SERIALPRINT(ffileName);
		SERIALPRINTLN(F(" File not found"));

	}

	Wire.flush();
	Wire.end();

}


void writeEEPROMbyte(long eeAddress, byte data)
{
	if (eeAddress < 65536)
	{
		Wire.beginTransmission(0x50);
		eeAddress &= 0xFFFF; //Erase the first 16 bits of the long variable



		Wire.write((int)(eeAddress >> 8)); // MSB
		Wire.write((int)(eeAddress & 0xFF)); // LSB
		Wire.write(data);
		Wire.endTransmission();
	}

}
void writeEEPROMPage(long eeAddress, byte tempStore[64])
{
	if (eeAddress < 65536)
	{
		Wire.beginTransmission(0x50);
		eeAddress &= 0xFFFF; //Erase the first 16 bits of the long variable


		Wire.write((int)(eeAddress >> 8)); // MSB
		Wire.write((int)(eeAddress & 0xFF)); // LSB


		//Write bytes to EEPROM
		for (byte x = 0; x < 64; x++)
			Wire.write(tempStore[x]); //Write the data





		Wire.endTransmission(); //Send stop condition
	}
}


*/
