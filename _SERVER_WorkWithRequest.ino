//void workRequestი(EthernetClient client, char requestBuffer[109])
//{
//
//
//	int tCount = 0;
//	int tCountOnleLine = 0;
//	char tBuf[REQ_BUF_SIZE - 1];
//	char tOneLineBuf[100];
//	//int r, t;
////		char *pch;
//	char methodBuffer[4];
//	//char requestBuffer[109];
//	//char pageBuffer[48];
//	//char paramBuffer[48];
//	char protocolBuffer[9];
//	//		char HOSTlBuffer[5];
//	char fileName[14];
//	//char fileName[32];
//	char fileType[4];
//	int clientCount = 0;
//
//
//	/*
//	SERIALPRINTLN("\n--------------");
//	SERIALPRINTLN(tBuf);
//	SERIALPRINTLN(scanCount);
//
//
//
//	if (scanCount != 3)
//	{
//		SERIALPRINTLN(F("bad request"));
//		sendBadRequest(client);
//		return;
//	}
//
//
//	*/
//
//	//if (String(requestBuffer).indexOf("POST") == 0)
//	//{
//	//	SERIALPRINTLN(F("\nGENERAL POST"));
//	//	//_sendJSONAnswer(&client);
//	//	//_responseGenericJSON_(&client);
//	//}
//
//
//
//
//
//	if (String(requestBuffer).indexOf("/ax_df") == 0)
//	{
//		//SERIALPRINTLN(F("\nGENERAL AJAX REQUEST"));
//		//SERIALPRINTLN("requestBuffer");
//		//SERIALPRINTLN(requestBuffer);
//
//		_sendJSONAnswer(&client);
//		_responseGenericJSON_(&client);
//	}
//	else if (String(requestBuffer).indexOf("/ax_SW") == 0)
//	{
//		//SERIALPRINTLN(F("\nSWITCH AJAX REQUEST"));
//#ifdef ServerDEBUG 
//		SERIALPRINTLN(F("\n"));
//		SERIALPRINTLN(requestBuffer);
//#endif
//		_sendJSONAnswer(&client);
//		_ax_SW_Action(&client, String(requestBuffer));
//
//	}
//	else if (String(requestBuffer).indexOf("/ap_PRST") == 0)
//	{
//#ifdef ServerDEBUG 
//		SERIALPRINTLN(F("\n"));
//		SERIALPRINTLN(requestBuffer);
//#endif
//
//
//		_sendJSONAnswer(&client);
//		_ap_PRST_Action(&client, String(requestBuffer));
//		//_responseGenericJSON_(&client);
//
//	}
//	else if (String(requestBuffer).indexOf("/ax_GMD") == 0)
//	{
//#ifdef ServerDEBUG 
//		SERIALPRINTLN(F("\n"));
//		SERIALPRINTLN(requestBuffer);
//#endif
//
//		_sendJSONAnswer(&client);
//		_ax_GMD_Action(&client, String(requestBuffer));
//	}
//	else if (String(requestBuffer).indexOf("/ax_MD") == 0)
//	{
//#ifdef ServerDEBUG 
//		SERIALPRINTLN(F("\n"));
//		SERIALPRINTLN(requestBuffer);
//#endif
//
//		_sendJSONAnswer(&client);
//		_ax_MD_Action(&client, String(requestBuffer));
//	}
//	else if (String(requestBuffer).indexOf("/ax_DND") == 0)
//	{
//#ifdef ServerDEBUG 
//		SERIALPRINTLN(F("\n"));
//		SERIALPRINTLN(requestBuffer);
//#endif
//
//		_sendJSONAnswer(&client);
//		_ax_DND_Action(&client, String(requestBuffer));
//
//	}
//	else if (String(requestBuffer).indexOf("/ar_INFR") == 0)
//	{
//#ifdef ServerDEBUG 
//		SERIALPRINTLN(F("\n"));
//		SERIALPRINTLN(requestBuffer);
//#endif
//
//		_sendJSONAnswer(&client);
//		_ar_INFR_Action(&client, String(requestBuffer));
//
//	}
//
//	else if ((String(requestBuffer).indexOf("/ax_GA") == 0) && (useIFTTT))
//
//	{
//		//SERIALPRINTLN(F("\nSWITCH AJAX REQUEST"));
//#ifdef ServerDEBUG 
//		SERIALPRINTLN(F("\n"));
//		SERIALPRINTLN("COMMAND FROM GOOGLE ASSISTANT");
//		SERIALPRINTLN(requestBuffer);
//
//#endif
//
//		//_sendJSONAnswer(&client);
//		_ax_SW_Action(&client, String(requestBuffer));
//
//	}
//	else if (strcmp(requestBuffer, "/MYTEST.PHP") == 0)
//	{
//#ifdef ServerDEBUG 
//		SERIALPRINTLN(F("dynamic page"));
//#endif
//	}
//	else
//	{
//		//SERIALPRINTLN(F("\n1---------------------------------------"));
//		//SERIALPRINT(F("Buffer:\t"));
//		//SERIALPRINTLN(tBuf);
//		//SERIALPRINT(F("FileName:\t"));
//		//SERIALPRINTLN(fileName);
//		//SERIALPRINT(F("requestBuffer:\t"));
//		//SERIALPRINTLN(requestBuffer);
//		//SERIALPRINTLN(F("---------------------------------------"));
//
//
//		char* pch = strtok(requestBuffer, "&");
//		if (pch != NULL)
//		{
//			strncpy(fileName, pch, 31);
//			strncpy(tBuf, pch, 31);
//
//			//pch = strtok(NULL, "?");
//			//if (pch != NULL)
//			//{
//			//	strcpy(paramBuffer, pch);
//			//}
//			//else paramBuffer[0] = 0;
//		}
//
//
//		//SERIALPRINTLN(F("\n---------------------------------------"));
//		//SERIALPRINT(F("pch:\t"));
//		//SERIALPRINTLN(pch);
//		//SERIALPRINT(F("Buffer:\t"));
//		//SERIALPRINTLN(tBuf);
//		//SERIALPRINT(F("FileName:\t"));
//		//SERIALPRINTLN(fileName);
//		//SERIALPRINT(F("requestBuffer:\t"));
//#ifdef ServerDEBUG 
//		SERIALPRINT(F("\n\nRequested: "));
//		SERIALPRINTLN(requestBuffer);
//		//SERIALPRINTLN(F("---------------------------------------"));
//#endif
//
//
//
//
//
//
//
//		pch = strtok(tBuf, ".");
//
//		if (pch != NULL)
//		{
//			pch = strtok(NULL, ".");
//
//			if (pch != NULL) strncpy(fileType, pch, 4);
//			else fileType[0] = 0;
//
//#ifdef ServerDEBUG 
//			//SERIALPRINT(F("file type = "));
//			//SERIALPRINTLN(fileType);
//#endif
//
//
//		}
//
//
//		//SERIALPRINT(F("method = "));
//		//SERIALPRINTLN(methodBuffer);
//
//		//if (strcmp(methodBuffer, "GET") != 0 && strcmp(methodBuffer, "HEAD") != 0)
//		//{
//		//	sendBadRequest(client);
//		//	return;
//		//}
//
//		//SERIALPRINT(F("params = "));
//		//SERIALPRINTLN(paramBuffer);
//
//		//SERIALPRINT(F("protocol = "));
//		//SERIALPRINTLN(protocolBuffer);
//
//
//
//
//
//		if ((strcmp(requestBuffer, "/") == 0) || (strcmp(requestBuffer, "/index.htm") == 0))
//			//if ((strcmp(fileName, "/") == 0) || (strcmp(fileName, "/index.htm") > -1))
//		{
//			strcpy(fileName, "index.htm");
//			strcpy(fileType, "htm");
//#ifdef ServerDEBUG 
//			SERIALPRINT(F("Home page FILE..."));
//			SERIALPRINTLN(fileName);
//#endif
//
//		}
//
//#ifdef ServerDEBUG 
//		//SERIALPRINTLN(F("SD FILE ... "));
//#endif
//		if ((useCloud) && (isSdOK))
//		{
//
//#ifdef ServerDEBUG 
//			SERIALPRINTLN("useCloud\t=\t" + String(useCloud) + ";  \tisSdOk\t" + String(isSdOK));
//#endif
//			if ((strlen(fileName) > 30) || (strlen(fileType) > 3) || (strlen(fileType) < 1))
//			{
//#ifdef ServerDEBUG 
//				SERIALPRINTLN(fileName);
//				SERIALPRINTLN(F("filename too long or file type invalid size"));
//				SERIALPRINTLN(F("---------------------------------------"));
//#endif
//				sendBadRequest(client);
//				return;
//			}
//			else
//			{
//
//				if ((reIndexFileName != "none") && (String(fileName) == "index.htm"))
//					reIndexFileName.toCharArray(fileName, 14);
//
//				if (SD.exists(fileName))
//				{
//
//					// SRAM chec
//#ifdef ServerDEBUG 
//									//SERIALPRINT(F("SRAM = "));
//									//SERIALPRINTLN(freeRam());
//
//					SERIALPRINT(fileName);
//					SERIALPRINT(F("\t\tFILE found.."));
//#endif
//
//
//					File myFile = SD.open(fileName);
//
//					if (!myFile)
//					{
//#ifdef ServerDEBUG 
//						SERIALPRINTLN(F("open error"));
//#endif
//						sendFileNotFound(client);
//						return;
//					}
//					else
//					{
//#ifdef ServerDEBUG 										
//						//SERIALPRINTLN(F("opened.."));
//#endif
//					}
//
//
//					strcpy_P(tBuf, PSTR("HTTP/1.0 200 OK\r\nContent-Type: "));
//
//#ifdef ServerDEBUG 
//					//SERIALPRINT(F("FILE TYPE is "));
//					//SERIALPRINTLN(fileType);
//#endif
//
//
//									//if (strcmp(methodBuffer, "Android") > -1)
//									//{
//									//	SERIALPRINT(F("Android user\n"));
//									//}
//
//									// send Content-Type
//					if (strcmp(fileType, "htm") == 0) strcat_P(tBuf, PSTR("text/html"));
//					//else if (strcmp(fileType, "PHP") == 0) strcat_P(tBuf, PSTR("text/html"));
//					//else if (strcmp(fileType, "txt") == 0) strcat_P(tBuf, PSTR("text/plain"));
//					else if (strcmp(fileType, "css") == 0) strcat_P(tBuf, PSTR("text/css"));
//					//else if (strcmp(fileType, "GIF") == 0) strcat_P(tBuf, PSTR("image/gif"));
//					else if (strcmp(fileType, "jpg") == 0) strcat_P(tBuf, PSTR("image/jpeg"));
//					else if (strcmp(fileType, "js") == 0) strcat_P(tBuf, PSTR("application/javascript"));
//					else if (strcmp(fileType, "ico") == 0) strcat_P(tBuf, PSTR("image/x-icon"));
//					//else if (strcmp(fileType, "PNG") == 0) strcat_P(tBuf, PSTR("image/png"));
//					//else if (strcmp(fileType, "PDF") == 0) strcat_P(tBuf, PSTR("application/pdf"));
//					//else if (strcmp(fileType, "ZIP") == 0) strcat_P(tBuf, PSTR("application/zip"));
//					else strcat_P(tBuf, PSTR("text/plain"));
//
//					strcat_P(tBuf, PSTR("\r\nConnection: close\r\n\r\n"));
//					client.write(tBuf);
//
//
//					if (strcmp(methodBuffer, "GET") == 0)
//					{
//#ifdef ServerDEBUG 
//						//SERIALPRINT(F("FILE SENDING...\t"));
//#endif
//
//						while (myFile.available())
//						{
//							clientCount = myFile.read(tBuf, 64);
//							//clientCount = myFile.read(tBuf, 128);
//							client.write((byte*)tBuf, clientCount);
//						}
//					}
//					myFile.flush();
//					myFile.close();
//
//					client.stop();
//
//#ifdef ServerDEBUG 
//					SERIALPRINTLN(F("SENT, CLOSED & Client Disconnected"));
//					SERIALPRINTLN(F("---------------------------------------"));
//#endif
//					return;
//
//				}		//		if (SD.exists(fileName))
//				else
//				{
//#ifdef ServerDEBUG 
//					SERIALPRINT(fileName);
//					SERIALPRINTLN(F(" File not found"));
//					SERIALPRINTLN(F("---------------------------------------"));
//#endif
//					sendFileNotFound(client);
//					return;
//				}
//
//			}
//		}
//		else
//		{
//			SERIALPRINTLN("useCloud\t=\t" + String(useCloud) + ";  \tisSdOk\t" + String(isSdOK));
//
//			strcpy_P(tBuf, PSTR("HTTP/1.0 200 OK\r\nContent-Type: "));
//
//#ifdef ServerDEBUG 
//			//SERIALPRINT(F("FILE TYPE is "));
//			//SERIALPRINTLN(fileType);
//#endif
//
//
//									//if (strcmp(methodBuffer, "Android") > -1)
//									//{
//									//	SERIALPRINT(F("Android user\n"));
//									//}
//
//									// send Content-Type
//			if (strcmp(fileType, "htm") == 0) strcat_P(tBuf, PSTR("text/html"));
//			//else if (strcmp(fileType, "PHP") == 0) strcat_P(tBuf, PSTR("text/html"));
//			//else if (strcmp(fileType, "txt") == 0) strcat_P(tBuf, PSTR("text/plain"));
//			else if (strcmp(fileType, "css") == 0) strcat_P(tBuf, PSTR("text/css"));
//			//else if (strcmp(fileType, "GIF") == 0) strcat_P(tBuf, PSTR("image/gif"));
//			else if (strcmp(fileType, "jpg") == 0) strcat_P(tBuf, PSTR("image/jpeg"));
//			else if (strcmp(fileType, "js") == 0) strcat_P(tBuf, PSTR("application/javascript"));
//			else if (strcmp(fileType, "ico") == 0) strcat_P(tBuf, PSTR("image/x-icon"));
//			//else if (strcmp(fileType, "PNG") == 0) strcat_P(tBuf, PSTR("image/png"));
//			//else if (strcmp(fileType, "PDF") == 0) strcat_P(tBuf, PSTR("application/pdf"));
//			//else if (strcmp(fileType, "ZIP") == 0) strcat_P(tBuf, PSTR("application/zip"));
//			else strcat_P(tBuf, PSTR("text/plain"));
//
//			strcat_P(tBuf, PSTR("\r\nConnection: close\r\n\r\n"));
//			client.write(tBuf);
//
//
//			if (strcmp(methodBuffer, "GET") == 0)
//			{
//#ifdef ServerDEBUG 
//				SERIALPRINTLN("filename = " + String(fileName));
//#endif
//				if (strcmp(fileName, "index.htm") == 0)
//					//if (fileName == "index.htm")
//				{
//					MakeIndexAndSendToClient(&client);
//				}
//				else if (fileName == "ardu_401.js")
//				{
//
//				}
//
//
//			}
//
//			client.stop();
//
//#ifdef ServerDEBUG 
//			SERIALPRINTLN(F("SENT FROM GENERATOR & Client Disconnected"));
//			SERIALPRINTLN(F("---------------------------------------"));
//#endif
//			return;
//		}
//	}
//
//
//
//	client.stop();
//}
