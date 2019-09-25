void Make_jqrmnJSAndSendToClient(EthernetClient * cl)
{

#ifdef ServerDEBUG
	SERIALPRINTLN(F("\n\tSENDING jqrmn.js to Client"));
#endif



	cl->println(F(""));

		



	

	cl->flush();
	cl->stop();


	stopTime = millis();
#ifdef ServerDEBUG
	SERIALPRINT(F("\tSENDING jqrmn.js Client DONE in \t"));
	SERIALPRINT(stopTime - startTime);
	SERIALPRINTLN(F(" milliseconds\n"));
#endif
}
