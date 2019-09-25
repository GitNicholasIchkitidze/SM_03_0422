
void sendBadRequest(EthernetClient thisClient) {
	char tBuf[64];
	strcpy_P(tBuf, PSTR("HTTP/1.0 400 Bad Request\r\n"));
	thisClient.write(tBuf);
	strcpy_P(tBuf, PSTR("Content-Type: text/html\r\nConnection: close\r\n\r\n"));
	thisClient.write(tBuf);
	strcpy_P(tBuf, PSTR("<html><body><H1>BAD REQUEST</H1></body></html>"));
	thisClient.write(tBuf);
	thisClient.stop();

	SERIALPRINTLN(F("BAD Requested 400 Sent & disconnected"));

}



void sendFileNotFound(EthernetClient thisClient) {
	char tBBuf[64];
	strcpy_P(tBBuf, PSTR("HTTP/1.0 404 File Not Found\r\n"));
	thisClient.write(tBBuf);
	strcpy_P(tBBuf, PSTR("Content-Type: text/html\r\nConnection: close\r\n\r\n"));
	thisClient.write(tBBuf);
	strcpy_P(tBBuf, PSTR("<html><body><H1>FILE NOT FOUND, Check SD CARD in Controller Please</H1></body></html>"));
	thisClient.write(tBBuf);
	thisClient.stop();

	SERIALPRINTLN(F("File Not Found 404 Sent & disconnected"));

}
