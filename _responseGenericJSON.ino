
/*
void _responseGenericJSON_SHORT(EthernetClient * client)
{
	//String dataJson = "";


	client->print(F("["));

	
	client->println(dataJsonLine);


	client->print(F("]"));
	
	client->flush();
	client->stop();

}
*/

void _response_MD_JSON_(EthernetClient * client)
{


	String dataJson = "";


	client->print(F("["));
	//dataJson = "";
	//dataJson += "{\"FreeMem\":\"" + String(freeRam())  + "\"},";

	//if (authMode == 0)
	//	dataJson += "{\"id\":\"user\", \"val\":\"ANONYMOUS\"},";
	//else
	dataJson += "{\"id\":\"user\", \"val\":\"" + currentUser + "\"},";

	dataJson += "{\"id\":\"sysmsg\", \"msg\":\"" + sysMsg + "\"},";

	dataJson += "{\"id\":\"FreeMem\", \"val\":\"" + String(freeRam()) + "\"},";

	if (currentUser == "ANONYMOUS")
		dataJson += "{\"id\":\"mtab3\", \"display\":\"none\"},";
	else
	{

		if (currentUser == "lasha")
			dataJson += "{\"id\":\"r1c2\", \"readonly\":\"0\"},";
		else
			dataJson += "{\"id\":\"r1c2\", \"readonly\":\"1\"},";

	}
	client->println(dataJson);

	dataJson = "{\"id\":\"jsn\", \"end\":\"1\"}]";
	client->println(dataJson);

	client->flush();
	client->stop();


	sysMsg = "";

}


void _responseGenericJSON_(EthernetClient * client)
{


	String dataJson = "";


	client->print(F("["));
	//dataJson = "";
	//dataJson += "{\"FreeMem\":\"" + String(freeRam())  + "\"},";
	
	//if (authMode == 0)
	//	dataJson += "{\"id\":\"user\", \"val\":\"ANONYMOUS\"},";
	//else
		dataJson += "{\"id\":\"user\", \"val\":\"" + currentUser + "\"},";

	dataJson += "{\"id\":\"sysmsg\", \"msg\":\"" + sysMsg + "\"},";

	dataJson += "{\"id\":\"FreeMem\", \"val\":\"" + String(freeRam()) + "\"},";

	if (currentUser == "ANONYMOUS")
		dataJson += "{\"id\":\"mtab3\", \"display\":\"none\"},";
	else
	{	
		
		if (currentUser == "lasha")
			dataJson += "{\"id\":\"r1c2\", \"readonly\":\"0\"},";
		else
			dataJson += "{\"id\":\"r1c2\", \"readonly\":\"1\"},";

	}
	


	client->println(dataJson);

	for (uint8_t i = 0; i < ActiveGroupsCount; i++)
	{

		dataJson = "{\"id\":\"" + group[i].id + "\", \"en\":\"" + String(group[i].enable) + "\", \"lbl\":\"" + group[i].lbl + "\"},";
		//dataJson += "{\"id\":\"" + group[i].id + "\", \"en\":\"" + String(group[i].enable) + "\", \"lbl\":\"" + group[i].lbl + "\"},";
		client->println(dataJson);
	}


	//SPrintln(dataJson);
	dataJson = "";

	for (uint8_t i = 0; i < ActiveSwitchersCount; i++)
	{
		//		dataJson = "{\"id\":\"sw" + switcher[i].id + "\", \"en\":\"" + String(switcher[i].enable) + "\", \"grp\":\"" + String(switcher[i].group) + "\", \"lbl\":\"" + switcher[i].lbl + "\", \"st\":\"" + String(switcher[i].state) + "\"},";
		dataJson = "{\"id\":\"sw" + switcher[i].id + "\", \"en\":\"" + String(switcher[i].enable) + "\", \"grp\":\"" + String(switcher[i].group) + "\", \"st\":\"" + switcher[i].state + "\", \"lbl\":\"" + String(switcher[i].lbl) + "\"},";
		client->println(dataJson);
	}

	//SPrintln(dataJson);

	dataJson = "";

	dataJson = "{\"id\":\"inf00\", \"en\":\"" + String(true) + "\", \"lbl\":\"ნახშიროჟანგ\", \"val\":\"" + String(analogRead(A0)) + "\"},";
	client->println(dataJson);
	dataJson = "{\"id\":\"inf01\", \"en\":\"" + String(true) + "\", \"lbl\":\"ტენიანობ\", \"val\":\"" + String(analogRead(A1)) + "\"},";
	client->println(dataJson);
	dataJson = "{\"id\":\"inf02\", \"en\":\"" + String(true) + "\", \"lbl\":\"ტემტერატურა\", \"val\":\"" + String(random(24)) + "\"},";
	client->println(dataJson);




	if (presetsAllowed)
	{

		for (uint8_t i = 0; i < 6; i++)
		{

			dataJson = "{\"id\":\"" + preset[i].id + "\", \"en\":\"" + String(preset[i].enable) + "\", \"lbl\":\"" + preset[i].lbl + "\"},";
			client->println(dataJson);
		}
	}






	/*
	dataJson = "{\"id\":\"" + preset[0].id + "\", \"lbl\":\"" + preset[0].lbl + "\", \"en\":\"" + String(preset[0].enable) + "\"},";
	dataJson = dataJson + "{\"id\":\"" + preset[1].id + "\", \"lbl\":\"" + preset[1].lbl + "\", \"en\":\"" + String(preset[1].enable) + "\"},";
	dataJson = dataJson + "{\"id\":\"" + preset[2].id + "\", \"lbl\":\"" + preset[2].lbl + "\", \"en\":\"" + String(preset[2].enable) + "\"},";
	dataJson = dataJson + "{\"id\":\"" + preset[3].id + "\", \"lbl\":\"" + preset[3].lbl + "\", \"en\":\"" + String(preset[3].enable) + "\"},";
	dataJson = dataJson + "{\"id\":\"" + preset[4].id + "\", \"lbl\":\"" + preset[4].lbl + "\", \"en\":\"" + String(preset[4].enable) + "\"},";
	dataJson = dataJson + "{\"id\":\"" + preset[5].id + "\", \"lbl\":\"" + preset[5].lbl + "\", \"en\":\"" + String(preset[5].enable) + "\"},";



	client->println(dataJson);
	*/
	//dataJson = "";

	if (heaterAllowed)
	{
		dataJson = "{\"id\":\"htrlbl0_0\", \"lbl\":\"" + String(heaterAllowed) + "\", \"lbl\":\"CURRENT Temp: " + String(random(40)) + " &deg\", \"st\":\"" + "3" + "\"},";
		//dataJson = "{\"id\":\"htrlbl0_0\", \"lbl\":\"" + String(heaterAllowed) + "\", \"lbl\":\"CURRENT Temp: " + String(random(40)) + " &deg\", \"st\":\"" + "3" + "\"}]";  
		client->println(dataJson);
	}

	dataJson = "{\"id\":\"jsn\", \"end\":\"1\"}]";
	client->println(dataJson);

	client->flush();
	client->stop();


	sysMsg = "";
	//SERIALPRINTLN(dataJson);

}

void _responseOneSwitchJSON(EthernetClient * cl, uint8_t i)
{
	String dataJson = "";


	cl->print(F("["));
	dataJson = "{\"id\":\"sw" + switcher[i].id + "\", \"en\":\"" + String(switcher[i].enable) + "\", \"grp\":\"" + String(switcher[i].group) + "\", \"lbl\":\"" + switcher[i].lbl + "\", \"st\":\"" + String(switcher[i].state) + "\"},";
	cl->println(dataJson);

	dataJson = "{\"id\":\"htrlbl0_0\", \"lbl\":\"" + String(heaterAllowed) + "\", \"lbl\":\"CURRENT Temp: " + String(random(40)) + " &deg\", \"st\":\"" + "3" + "\"}]";

	cl->println(dataJson);

	cl->flush();
	cl->stop();

	//Serial.println(dataJson);
}
