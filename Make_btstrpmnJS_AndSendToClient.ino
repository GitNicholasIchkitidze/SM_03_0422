void Make_btstrpmnJSAndSendToClient(EthernetClient * cl)
{

#ifdef ServerDEBUG
	SERIALPRINTLN(F("\n\tSENDING btstrpmn.js to Client"));
#endif
	cl->flush();
	cl->stop();


	stopTime = millis();
#ifdef ServerDEBUG
	SERIALPRINT(F("\tSENDING btstrpmn.js Client DONE in \t"));
	SERIALPRINT(stopTime - startTime);
	SERIALPRINTLN(F(" milliseconds\n"));
#endif
}
