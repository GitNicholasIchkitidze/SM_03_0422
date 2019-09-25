void _setupWEBSERVER()
{

#ifdef ServerDEBUG
	//_SPrintBrLine();
	SERIALPRINT(F("\nSETTING UP WEB SERVER with IP:\t  "));
	_printIp(SERVER_IP);
#endif


	Ethernet.begin(SERVER_MAC, SERVER_IP);//, GATEWAY);
	delay(1000);
	server.begin();


	//unsigned long thisTime = millis();

	//for (int i = 0; i < MAX_SOCK_NUM; i++)
	//{
	//	connectTime[i] = thisTime;
	//}


//#ifdef ServerDEBUG
	//_SPrintBrLine();
	SERIALPRINT(F("\n\tWEB SERVER IS UP and RUNNING at "));
	SERIALPRINT(Ethernet.localIP());
	SERIALPRINT(F(" Port "));
	//SERIALPRINT(Ethernet._server_port());
	SERIALPRINT(SERVER_PORT);
	SERIALPRINT(F(" STATUS: READY "));
	SERIALPRINT(F("\n---------------------------------- Web SERVER -------------------------------------------------- "));
	SERIALPRINTLN(millis());
//#endif


}



void _serverWorks()
{


	for (uint8_t sock = 0; sock < MAX_SOCK_NUM - freeSockets; sock++)
		//for (int sock = 0; sock < 1; sock++)
	{
		//EthernetClient sclient = server.available_(sock);

		EthernetClient sclient = server.available_(sock);

		//connectTime[sock] = thisTime;
		
		runWebServer(sclient);

		//socketRel(sclient, sock);

	}
}


//void runWebServer(EthernetClient *client)
void runWebServer(EthernetClient client)
{

	//SERIALPRINTLN("I'm here too");
	if (client)
	{


		//SERIALPRINTLN("client");

		boolean currentLineIsBlank = false;
		//		boolean currentLineIsGet = true;
//		int tCount = 0;
		//		int tCountOnleLine = 0;
		char tBuf[REQ_BUF_SIZE];// - 1];
		//		char tOneLineBuf[100];
				//int r, t;
		//		char *pch;
		char methodBuffer[4];
		char requestBuffer[109];
		//char pageBuffer[48];
		//char paramBuffer[48];
		char protocolBuffer[9];
		//		char HOSTlBuffer[5];
		char fileName[14];
		//char fileName[32];
		char fileType[4];
		int clientCount = 0;

		//		byte rip[] = { 0,0,0,0 };

		Buffrequest = "";

		// this controls the timeout
		int loopCount = 0;


		String reqLine;

		String reqGet;
		String reqAuth;
		String reqAgent;
		String reqCookie;

		String deviceID;
		uint8_t rremoteIP[4];

		while (client.connected())
		{
			while (client.available())
			{
				char c = client.read();

				if (c == '\n') {
					///SERIALPRINTLN("DBG: " + reqLine);

					if (reqLine.startsWith("GET "))
						reqGet = reqLine;
					else if (reqLine.startsWith("Authorization: "))
						reqAuth = reqLine;
					else if (reqLine.startsWith("Cookie: "))
						reqCookie = reqLine;
					else if (reqLine.startsWith("User-Agent: "))
						reqAgent = reqLine;

					reqLine = "";
				}
				else {
					reqLine += c;
				}







			}		//		while (client.available())

////////			currentLineIsBlank = true;
			
			//#ifdef ServerDEBUG 
					client.getRemoteIP(rremoteIP);
					SERIALPRINTLN(F("\n->"));
					SERIALPRINTLN("CLIENT FROM [ip]:\t" + String(rremoteIP[0]) + "." + String(rremoteIP[1]) + "." + String(rremoteIP[2]) + "." + String(rremoteIP[3]));
			//		SERIALPRINTLN("FULL REQ: " + String(currentLineIsBlank));
					SERIALPRINTLN(reqGet);
			//		SERIALPRINTLN(reqAuth);
					SERIALPRINTLN(reqAgent);
			//		SERIALPRINTLN(reqCookie);
			//#endif


////////			if (currentLineIsBlank)
				//if (c == '\n' && currentLineIsBlank)
////////			{

				//((reqAgent.indexOf(userAgent1) > -1) ||	(reqCookie.indexOf(userCookie) > -1) ||	(reqAgent.indexOf(userAgent2) > -1)) ? userFromAPP = true : userFromAPP = false;
				((reqAgent.indexOf(userAgent1) > -1) || (reqAgent.indexOf(userAgent2) > -1)) ? userFromAPP = true : userFromAPP = false;
				
////				#ifdef ServerDEBUG 
						userFromAPP ? SERIALPRINTLN("\n USER FROM APP") : SERIALPRINTLN("\n NOT FROM APP");
////				#endif

				//uint8_t scanCount = sscanf(reqGet.begin(), "%3s %8s", methodBuffer, protocolBuffer);
				uint8_t scanCount = sscanf(reqGet.begin(), "%3s %108s %8s", methodBuffer, requestBuffer, protocolBuffer);



				if ((authMode == AUTH_OFF) ||
					(userFromAPP) ||
					(authMode == AUTH_ON && check_Auto_HASH(reqAuth) && !userFromAPP) ||
					(useIFTTT && ((reqGet.indexOf("GET /ax_GA") > -1) || (reqGet.indexOf("GET /ax_GC") > -1))))
				{




					
					if (reqGet.indexOf("/ax_df") > -1)
					//if (String(requestBuffer).indexOf("/ax_df") == 0)
					{
						//SERIALPRINTLN(F("\nGENERAL AJAX REQUEST"));
						//SERIALPRINTLN("requestBuffer");
						//SERIALPRINTLN(requestBuffer);

						_sendJSONAnswer(&client);
						_responseGenericJSON_(&client);
					}
					else if (reqGet.indexOf("/ax_SW") > -1)
					//else if (String(requestBuffer).indexOf("/ax_SW") == 0)
					{
						//SERIALPRINTLN(F("\nSWITCH AJAX REQUEST"));
						#ifdef ServerDEBUG 
								SERIALPRINTLN(F("\n"));
								SERIALPRINTLN(reqGet);
						#endif
						_sendJSONAnswer(&client);
						_ax_SW_Action(&client, reqGet);
						//_ax_SW_Action(&client, String(requestBuffer));

					}
					else if (reqGet.indexOf("/ap_PRST") > -1)
					//else if (String(requestBuffer).indexOf("/ap_PRST") == 0)
					{
						#ifdef ServerDEBUG 
								SERIALPRINTLN(F("\n"));
								//SERIALPRINTLN(requestBuffer);
								SERIALPRINTLN(reqGet);
						#endif


						
						//_ap_PRST_Action(&client, String(requestBuffer));
						_sendJSONAnswer(&client);
						_ap_PRST_Action(&client, reqGet);
						
						//_responseGenericJSON_(&client);

					}
					else if (reqGet.indexOf("/ax_GMD") > -1 )
					//else if (String(requestBuffer).indexOf("/ax_GMD") == 0)
					{
						#ifdef ServerDEBUG 
								SERIALPRINTLN(F("\n"));
								//SERIALPRINTLN(requestBuffer);
								SERIALPRINTLN(reqGet);
						#endif

						_sendJSONAnswer(&client);
						//_ax_GMD_Action(&client, String(requestBuffer));
						_ax_GMD_Action(&client, reqGet);
					}
					else if (reqGet.indexOf("/ax_MD") > -1)
					//else if (String(requestBuffer).indexOf("/ax_MD") == 0)
					{
						#ifdef ServerDEBUG 
								SERIALPRINTLN(F("\n"));
								//SERIALPRINTLN(requestBuffer);
								SERIALPRINTLN(reqGet);
						#endif

						_sendJSONAnswer(&client);
						_ax_MD_Action(&client, reqGet);
						//_responseGenericJSON_(&client);
						_response_MD_JSON_(&client);
						//_ax_MD_Action(&client, String(requestBuffer));
					}
					else if (reqGet.indexOf("/ax_DND") > - 1)
					//else if (String(requestBuffer).indexOf("/ax_DND") == 0)
					{
						#ifdef ServerDEBUG 
								//SERIALPRINTLN(F("\n"));
								//SERIALPRINTLN(requestBuffer);
								SERIALPRINTLN("\n" + reqGet);
						#endif

						_sendJSONAnswer(&client);
						_ax_DND_Action(&client, reqGet);
						//_ax_DND_Action(&client, String(requestBuffer));

					}
					//else if (String(requestBuffer).indexOf("/ar_INFR") == 0)
					else if (reqGet.indexOf("/ar_INFR") > -1 )
					{
						#ifdef ServerDEBUG 
								SERIALPRINTLN(F("\n"));
								//SERIALPRINTLN(requestBuffer);
								SERIALPRINTLN(reqGet);
						#endif

						_sendJSONAnswer(&client);
						_ar_INFR_Action(&client, reqGet);
						//_ar_INFR_Action(&client, String(requestBuffer));

					}

					//else if ((String(requestBuffer).indexOf("/ax_GA") == 0) && (useIFTTT))
					else if ((reqGet.indexOf("/ax_GA") > -1) && (useIFTTT))
					{
						//SERIALPRINTLN(F("\nSWITCH AJAX REQUEST"));
						#ifdef ServerDEBUG 								
								SERIALPRINTLN("\nCOMMAND FROM GOOGLE ASSISTANT");
								//SERIALPRINTLN(requestBuffer);
								SERIALPRINTLN(reqGet);
						#endif

						//_sendJSONAnswer(&client);
						//_ax_GA_Action(&client, String(requestBuffer));
						_ax_GA_Action(&client, reqGet);
						

					}
					else if ((reqGet.indexOf("/ax_GC") > -1) && (useIFTTT))
					{
						#ifdef ServerDEBUG 								
								SERIALPRINTLN("\nCOMMAND FROM GOOGLE CALENDAR");
								//SERIALPRINTLN(requestBuffer);
								SERIALPRINTLN(reqGet);
						#endif

					//_sendJSONAnswer(&client);
					//_ax_GA_Action(&client, String(requestBuffer));
					_ax_GA_Action(&client, reqGet);

					}
					//						else if (strcmp(requestBuffer, "/MYTEST.PHP") == 0)
					//						{
					//#ifdef ServerDEBUG 
					//							SERIALPRINTLN(F("dynamic page"));
					//#endif
					//						}
					else
					{


						char* pch = strtok(requestBuffer, "&");
						if (pch != NULL)
						{
							strncpy(fileName, pch, 31);
							strncpy(tBuf, pch, 31);

						}


						//#ifdef ServerDEBUG 
								SERIALPRINT(F("\n\nRequested: "));
								SERIALPRINTLN(requestBuffer);
								//SERIALPRINTLN(F("---------------------------------------"));
						//#endif







						pch = strtok(tBuf, ".");

						if (pch != NULL)
						{
							pch = strtok(NULL, ".");

							if (pch != NULL) strncpy(fileType, pch, 4);
							else fileType[0] = 0;

////#ifdef ServerDEBUG 
							//SERIALPRINT(F("file type = "));
							//SERIALPRINTLN(fileType);
////#endif


						}


						//SERIALPRINT(F("method = "));
						//SERIALPRINTLN(methodBuffer);

						//if (strcmp(methodBuffer, "GET") != 0 && strcmp(methodBuffer, "HEAD") != 0)
						//{
						//	sendBadRequest(client);
						//	return;
						//}

						//SERIALPRINT(F("params = "));
						//SERIALPRINTLN(paramBuffer);

						//SERIALPRINT(F("protocol = "));
						//SERIALPRINTLN(protocolBuffer);





						if ((strcmp(requestBuffer, "/") == 0) || (strcmp(requestBuffer, "/index.htm") == 0))
							//if ((strcmp(fileName, "/") == 0) || (strcmp(fileName, "/index.htm") > -1))
						{
							strcpy(fileName, "index.htm");
							strcpy(fileType, "htm");
							////#ifdef ServerDEBUG 
									SERIALPRINT(F("Home page FILE..."));
									SERIALPRINTLN(fileName);
							////#endif

						}


						SERIALPRINTLN("useCloud\t=\t" + String(useCloud) + ";  \tisSdOk\t" + String(isSdOK));
						if ((useCloud) && (isSdOK))
						//if ((isSdOK))
						{

							////#ifdef ServerDEBUG 
									//SERIALPRINTLN("useCloud\t=\t" + String(useCloud) + ";  \tisSdOk\t" + String(isSdOK));
							////#endif

							if ((strlen(fileName) > 30) || (strlen(fileType) > 3) || (strlen(fileType) < 1))
							{
								////#ifdef ServerDEBUG 
										SERIALPRINTLN(fileName);
										SERIALPRINTLN(F("Filename too long or File Type invalid size"));
										SERIALPRINTLN(F("---------------------------------------"));
								////#endif
								sendBadRequest(client);
								return;
							}
							else
							{

								if ((reIndexFileName != "none") && (String(fileName) == "index.htm"))
									reIndexFileName.toCharArray(fileName, 14);

								if (SD.exists(fileName))
								{

									// SRAM chec
									////#ifdef ServerDEBUG 
											SERIALPRINT(fileName);
											SERIALPRINT(F("\t\tFILE found.."));
									////#endif


									File myFile = SD.open(fileName);

									if (!myFile)
									{
										////#ifdef ServerDEBUG 
												SERIALPRINTLN(F("Open error"));
										////#endif
										sendFileNotFound(client);
										//return;
									}
									else
									{
										//#ifdef ServerDEBUG 										
												//SERIALPRINTLN(F("opened.."));
										//#endif
									

										if (strcmp(fileType, "htm") == 0) _sendHtmlAnswer(&client);
										else if (strcmp(fileType, "txt") == 0) _sendTxtAnswer(&client);
										else if (strcmp(fileType, "ico") == 0) _sendIcoAnswer(&client);
										else if (strcmp(fileType, "png") == 0) _sendPngAnswer(&client);
										else if (strcmp(fileType, "jpg") == 0) _sendJpgAnswer(&client);
										else if (strcmp(fileType, "css") == 0) _sendCssAnswer(&client);
										else if (strcmp(fileType, "js") == 0) _sendJsAnswer(&client);



										if (strcmp(methodBuffer, "GET") == 0)
										{
											#ifdef ServerDEBUG 
													//SERIALPRINT(F("FILE SENDING...\t"));
													startTime = millis();
											#endif

											while (myFile.available())
													{
														clientCount = myFile.read(tBuf, 256);
														//clientCount = myFile.read(tBuf, 128);
														client.write((byte*)tBuf, clientCount);
													}
										}

										myFile.flush();
										myFile.close();

										client.stop();

										#ifdef ServerDEBUG 
												stopTime = millis();
												SERIALPRINT(F("SENT, CLOSED & Client Disconnected in "));
												SERIALPRINT(stopTime - startTime);
												SERIALPRINTLN(F(" ms.\n---------------------------------------"));
										#endif
										//return;
									}
									return;

								}		//		if (SD.exists(fileName))
								else
								{
									////#ifdef ServerDEBUG 
											SERIALPRINT(fileName);
											SERIALPRINTLN(F(" File not found"));
											SERIALPRINTLN(F("-------------------<>------------------"));
									////#endif
									sendFileNotFound(client);
									return;
								}

							}
						}
						else
						{
							////#ifdef ServerDEBUG 
									//SERIALPRINTLN("useCloud\t=\t" + String(useCloud) + ";  \tisSdOk\t" + String(isSdOK));
							////#endif

							if (strcmp(fileType, "htm") == 0) _sendHtmlAnswer(& client);


							if (strcmp(methodBuffer, "GET") == 0)
							{
								#ifdef ServerDEBUG 
										SERIALPRINTLN("Filename = " + String(fileName));
								#endif

								if (strcmp(fileName, "index.htm") == 0)
									//if (fileName == "index.htm")
								{
									MakeIndexAndSendToClient(&client);
								}

								else if (String(fileName).indexOf("ardu_401.js") > -1)


								{
									Make_ArduJSAndSendToClient(&client);
								}

								else if (String(fileName).indexOf("jqrmn.js") > -1)


								{
									Make_jqrmnJSAndSendToClient(&client);
								}

								else if (String(fileName).indexOf("btstrpmn.js") > -1)


								{
									Make_btstrpmnJSAndSendToClient(&client);
								}

							}

							client.stop();

							////#ifdef ServerDEBUG 
									SERIALPRINTLN(F("SENT FROM GENERATOR & Client Disconnected"));
									SERIALPRINTLN(F("---------------------------------------"));
							////#endif
							return;
						}
					}



					client.stop();

				}		//		if (authMode == AUTH_OFF || (authMode == AUTH_ON && check_Auto_HASH()))
				else
				{

					/*
					strcpy_P(tBuf, PSTR("\n401 Unauthorized"));
					client.write(tBuf);
					strcpy_P(tBuf, PSTR("\nWWW - Authenticate: Basic realm = \"M2 SmartHome\""));
					client.write(tBuf);
					*/

					//SPrint(F("\n401 Unauthorized"));
					client.println(F("HTTP/1.1 401 Unauthorized"));
					client.println(F("WWW-Authenticate: Basic realm=\"YOUR SmartHome\""));
					//client.println(F("<body>error</body>"));

					////#ifdef ServerDEBUG 
							SERIALPRINTLN(F("\n401 Unauthorized SENT"));
					////#endif
					client.stop();
				}

////////				currentLineIsBlank = false;
				//break;
////////			}		//		(c == '\n' && currentLineIsBlank)

			loopCount++;


			// if 1000ms has passed since last packet
			if (loopCount > 1000)
			{
				// close connection
				client.stop();
				////#ifdef ServerDEBUG 
						SERIALPRINTLN("\r\nTimeout");
				////#endif

			}

			// delay 1ms for timeout timing
			delay(1);
		}		//		while (client.connected())

		//SERIALPRINTLN("Client Disconnected");
	}		//		if (client)

}




/*

void  strtoupper(char* aBuf) {

	for (int x = 0; x < strlen(aBuf); x++) {
		aBuf[x] = toupper(aBuf[x]);
	}
}
*/



String _makeAnswer200(String content, bool cached = false) {
	//SERIALPRINTLN("_makeAnswer200: " + content);

	String s = "";
	s += F("HTTP/1.1 200 OK\n");
	s += F("Content-Type: ");
	s += content;
	s += F("\n");

	if (cached) {
		s += F("Cache-Control: max-age=604800, public\n");// 290304000
	}
	else {
		s += F("Cache-Control: no-store, no-cache\n");
	}
	s += F("Content - Encoding: gzip\n");
	//s += F("Set-Cookie: DeviceID=COOKK123\n");
	s += F("Set-Cookie: DeviceID=");
	s += userCookie;
	s += F("\n");
	s += F("Connnection: close\n"); // "Connection: keep-alive\n"

	return s;
}

void _sendHtmlAnswer(EthernetClient * cl) { cl->println(_makeAnswer200(F("text/html"), true)); }
void _sendCssAnswer(EthernetClient * cl) { cl->println(_makeAnswer200(F("text/css"), true)); }
void _sendTxtAnswer(EthernetClient * cl) { cl->println(_makeAnswer200(F("text/txt"), true)); }
void _sendJsAnswer(EthernetClient * cl) { cl->println(_makeAnswer200(F("application/javascript"), true)); }
void _sendJSONAnswer(EthernetClient * cl) { cl->println(_makeAnswer200(F("application/json"), true)); }
void _sendPngAnswer(EthernetClient * cl) { cl->println(_makeAnswer200(F("image/png"), true)); }
void _sendJpgAnswer(EthernetClient * cl) { cl->println(_makeAnswer200(F("image/jpeg"), true)); }
void _sendGifAnswer(EthernetClient * cl) { cl->println(_makeAnswer200(F("image/gif"))); }
void _sendXmlAnswer(EthernetClient * cl) { cl->println(_makeAnswer200(F("text/xml"))); }
void _sendIcoAnswer(EthernetClient * cl) { cl->println(_makeAnswer200(F("image/x-icon"))); }


///*
byte socketStat[MAX_SOCK_NUM];

void ShowSockStatus(EthernetClient client, uint8_t n)
{
	//for (int i = 0; i < MAX_SOCK_NUM; i++) {
		SERIALPRINT(F("\nSocket#"));
		SERIALPRINTLN(n);
		uint8_t s = W5100.readSnSR(n);
		socketStat[n] = s;
		SERIALPRINT(F(":0x"));
		SERIALPRINT(s, 16);
		SERIALPRINT(F(" "));
		SERIALPRINT(W5100.readSnPORT(n));
		SERIALPRINT(F(" D:"));
		uint8_t dip[4];
		W5100.readSnDIPR(n, dip);
		for (int j = 0; j < 4; j++) {
			SERIALPRINT(dip[j], 10);
			if (j < 3) SERIALPRINT(".");
		}
		SERIALPRINT(F("("));
		SERIALPRINT(W5100.readSnDPORT(n));
		SERIALPRINTLN(F(")"));
	//}
}

void checkSockStatus(EthernetClient client, uint8_t n)
{
	unsigned long thisTime = millis();

	//for (int i = 0; i < MAX_SOCK_NUM; i++) {
		uint8_t s = W5100.readSnSR(n);

		if ((s == 0x17) || (s == 0x1C)) {
			if (thisTime - connectTime[n] > 30000UL) {
				SERIALPRINT(F("\r\nSocket frozen: "));
				SERIALPRINT(n);
				
				(s == 0x17) ? SERIALPRINT("IN STATUS \"ESTABLISHED\" more then ") : SERIALPRINT("IN STATUS \"CLOSE_WAIT\" more then ");
				SERIALPRINT(String(thisTime - connectTime[n]));
				SERIALPRINTLN(F(" ms."));

				client.stop();
			}
		}
		else
		{
			connectTime[n] = thisTime;
			//SERIALPRINT(F("\nSocket: "));
			//SERIALPRINT(n);
			//SERIALPRINT(F(" "));
			//SERIALPRINTLN(s,HEX);
		}

		socketStat[n] = W5100.readSnSR(n);
	//}
}

void socketRel(EthernetClient client, uint8_t n) {
	//ShowSockStatus(client, n);

	//if (Serial.available()) {
	//	if (Serial.read() == 'r') ShowSockStatus(client);
	//}

	checkSockStatus(client, n);
}

//*/

