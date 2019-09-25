void MakeIndexAndSendToClient(EthernetClient * cl)
{

#ifdef ServerDEBUG
	SERIALPRINTLN(F("\n\tSENDING index to Client"));
#endif

	startTime = millis();


	cl->println(F(

		"<!DOCTYPE HTML>\n"
		"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n"
		"<head>\n"
		"<meta http-equiv=\"Content-Type\" content=\"text/html; text/css; text/javascript; charset=utf-8\" />\n"
		"<meta name=\"viewport\" content=\"width=device-width, , initial-scale=1\">\n"
		"<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge,chrome=1\">\n"
		"<meta name=\"description\" content=\"მარტივი სახლი  | Easy Home | control Everything\">\n"
	));

	



	cl->print(F("<title>ჭკვიანი სახლი | controlling everything "));
	cl->print(serverVersion);
	cl->println(F("</title>\n"));


	cl->println(F("<link rel=\"stylesheet\" href=\"ard/common/css/btstrpmn.css\">\n"));
	cl->println(F("<link rel=\"stylesheet\" href=\"ard/common/css/ccrdn.css\">\n"));
	cl->println(F("<link rel=\"stylesheet\" href=\"ard/common/css/mdnghtbl.css\">\n"));
	cl->println(F("<link rel=\"stylesheet\" href=\"ard/common/css/pre.css\">\n"));



	cl->println(F("</head>\n"
		"\n"
		"<body id=\"body\" onload=\"GetArduinoIO()\">\n\n"));



	cl->println(F("<!------------------------------------------ PRELOADER -----------------------------------------------------  START  ---------------->"));
	cl->println(F("<!--CSS Spinner-->"));
	cl->println(F("<div class=\"spinner-wrapper\">"));
	cl->println(F("<div class=\"spinner\"></div>"));
	cl->println(F("</div>"));
	cl->println(F("<!------------------------------------------ PRELOADER -----------------------------------------------------   END   ---------------->\n"));


	cl->println(F("\t\t\t<div id =\"resp_div\" class=\"col-lg-12 col-md-12 col-sm-12 col-xs-12\">"));
	cl->println(F("\t\t\t\t<div class=\"container container-fluid\">\n"));

	cl->print(F("\t\t<main class=\"container-fluid\" style=\"background-image:url(http://"));
	cl->print(String(SERVER_IP[0]) + "." + String(SERVER_IP[1]) + "." + String(SERVER_IP[2]) + "." + String(SERVER_IP[3]) + ":" + String(SERVER_PORT));
	cl->println(F("/ard/common/img/img_bg_5.jpg); background-position:center center; min-height:100%; min-height: 100vh; align-items: center; background-repeat:  no-repeat; background-attachment:fixed; background-size:cover;\">"));

	_DoInfoBarGENERATED(cl);


	for (uint8_t i = 0; i < ActiveGroupsCount; i++)
	{
		//if (SwitchGroupWebVisible[i])
		_DoGroupSectionGENERATED(cl, i);


	}





	cl->println(F("<div class=\"div-text-and-btn-frame\">"));
	//		indexFile.print(F("<a href=\"#\" id=\"config_0\" class=\"btn btn-block btn-lg btn-warning\" data-toggle=\"modal\" data-target=\"#basicModal\">Click to open config</a>\n"));

	cl->println(F("<button type=\"button\" class=\"btn btn-secondary btn-lg btn-block\" id=\"myBtnModal\">settings</button>"));
	cl->println(F("</div>"));



	cl->println(F("\t\t\t\t</div>\t<!--\tclass=\"container container-fluid\"\t-->\n"));
	cl->println(F("\t\t\t</div>\t<!--\tid =\"resp_div\"\t-->\n"));
	cl->println(F("\t\t</main>\n"));



	_doSendFooterGENERATED(cl);
	cl->println(F("<div class=\"section section-success\">\n""<div class=\"container\">"));



	cl->println(F("</div>\n"));


	cl->println(F("</div>\n"));



	cl->println(F("<script language=\"javascript\" src=\"ard/common/js/ardu_401.js\" type=\"text/javascript\"></script>\n"));
	cl->println(F("<script language=\"javascript\" src=\"ard/common/js/ar_401.js\" type=\"text/javascript\"></script>\n"));
	cl->println(F("<script language=\"javascript\" src=\"ard/common/js/idle.js\" type=\"text/javascript\"></script>\n"));
	//indexFile.println(F("<script language=\"javascript\" src=\"modal.js\" type=\"text/javascript\"></script>\n"));

	cl->println(F("<script language=\"javascript\" src=\"ard/common/js/jqrmn.js\" type=\"text/javascript\"></script>\n"));
	cl->println(F("<script language=\"javascript\" src=\"ard/common/js/btstrpmn.js\" type=\"text/javascript\"></script>\n"));




	cl->println(F("\t\t<script>"));
	cl->println(F("\t\t\t$(document).ready(function()"));
	cl->println(F("\t\t\t{"));
	cl->println(F("\t\t\t\t$(\"#myBtnModal\").click(function(){$(\"#basicModal\").modal(\"show\");});"));
	cl->println(F("\t\t\t\t$(\"#basicModal\").on(\"shown.bs.modal\", function () {modalShown();});"));
	cl->println(F("\t\t\t\t$(\"#basicModal\").on(\"hidden.bs.modal\", function () {modalHidden();});"));


	cl->println(F("\t\t\t\t$(window).on(\"load\", function() {preloaderFadeOutTime = 500;"));
	cl->println(F("\t\t\t\tfunction hidePreloader() {var preloader = $(\".spinner-wrapper\");preloader.fadeOut(preloaderFadeOutTime);}hidePreloader();});"));
	cl->println(F("\t\t\t\t});"));


	cl->println(F("\t\t\t</script>"));












	cl->println(F("</body>\n"));

	cl->println(F("</html>\n"));



	cl->flush();
	cl->stop();


	stopTime = millis();
#ifdef ServerDEBUG
	SERIALPRINT(F("\tSENDING index Client DONE in \t"));
	SERIALPRINT(stopTime - startTime);
	SERIALPRINTLN(F(" milliseconds\n"));
#endif

}



void _DoInfoBarGENERATED(EthernetClient * cl)
{

	cl->println(F("<!------------------------------------------ INFO BAR -----------------------------------------------------  START  ---------------->\n"));
	cl->println(F("\t\t\t\t<div class=\"page-header\">"));
	cl->println(F("\t\t\t\t\t<div class=\"panel panel-warning\" style=\"background:none\">"));
	//	cl->println(F("\t\t\t\t\t\t<div class=\"panel-heading\">"));
	//	cl->println(F("\t\t\t\t\t\t\t<h3 class=\"panel-title\">...</h3>"));
	//	cl->println(F("\t\t\t\t\t\t</div>"));
	cl->println(F("\t\t\t\t\t\t<div class=\"panel-body\" style=\"background:none\">\n"));

	for (uint8_t i = 0; i < 4; i++)
	{
		cl->print(F("\t\t\t\t\t\t\t<div id=\"inf0"));
		cl->print(String(i));
		cl->println(F("\" style=\"display: block\" class=\"col-md-3 col-sm-6\">"));
		cl->println(F("\t\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">"));
		cl->println(F("\t\t\t\t\t\t\t\t<a class=\"btn btn-block btn-lg btn-default\" id=\"inf0"));
		cl->print(String(i));
		cl->print(F("_lbl\">waiting <span id=\"inf0"));
		cl->print(String(i));
		cl->println(F("_val\" class=\"badge\">...</span></a>"));
		cl->println(F("\t\t\t\t\t\t\t\t</div>"));
		cl->println(F("\t\t\t\t\t\t\t</div>\n"));
	}

	cl->println(F("\t\t\t\t\t\t</div>\t<!-- class=\"panel-body\" -->"));
	cl->println(F("\t\t\t\t\t</div>\t<!-- class=\"panel panel-warning\" -->"));
	cl->println(F("\t\t\t\t</div>\t<!-- class=\"page-header\" -->\n\n"));

	cl->println(F("<!------------------------------------------ INFO BAR -----------------------------------------------------   END   ---------------->"));
}




void _DoGroupSectionGENERATED(EthernetClient * cl, uint8_t i)
{

	cl->print(F("<!--start---- switchers GROUP content - "));
	cl->print(i);
	cl->println(F(" -------- START ---------------------------------------------- START ---------------------------------->\n"));

	cl->print(F("\t\t\t\t\t<div class=\"row\" id=\""));
	cl->print(group[i].id);
	cl->print(F("\" style=\"display:"));
	if (group[i].enable) { cl->print(F("block\">\n")); }
	else { cl->print(F("none\">\n")); }


	cl->print(F("\t\t\t\t\t\t<div class=\"tc-accordion-style5\" id=\"accrdn_"));
	cl->print(String(i));
	cl->print(F("\""));
	if (dndEnable)
	{
		cl->print(F(" ondragenter=\"return dragEnter(event)\" ondragover=\"return dragOver(event)\" ondrop=\"return dragDrop("));
		cl->print(String(i));
		cl->print(F(",event)\""));
	}

	cl->print(F(">\n"));

	
	cl->print(F("\t\t\t\t\t\t\t<div class=\"panel\" id=\"grp"));
	cl->print(String(i));
	cl->print(F("_pnl\">\n"));



	cl->print(F("\t\t\t\t\t\t\t\t<h4 class=\"acdn-title team-title\">\n"));


	cl->print(F("\t\t\t\t\t\t\t\t\t<a id=\""));
	cl->print(group[i].id);

	cl->print(F("_lbl\" data-toggle=\"collapse\" data-parent=\"#accrdn_"));
	cl->print(String(i));
	cl->print(F("\" href=\""));
	//cl->print(F("\" href=\"http://"));
	//cl->print(cloudadress);
	cl->print(F("ard/#colsp"));
	cl->print(String(i));
	cl->print(F("\" aria-expanded=\"false\" class=\"collapsed\">"));


	cl->print(group[i].lbl);
	cl->print(F("<span>.</span></a>\n"));
	cl->print(F("\t\t\t\t\t\t\t\t</h4>\n"));



	cl->print(F("\t\t\t\t\t\t\t\t<div class=\"panel-collapse collapse\" aria-expanded=\"false\" style=\"height: 0px;\" id=\"colsp"));
	cl->print(String(i));
	cl->print(F("\">\n"));

	cl->println(F("\t\t\t\t\t\t\t\t<div class=\"acdn-body\">"));
	cl->print(F("\t\t\t\t\t\t\t\t<div class=\"row\" id=\"grp"));
	cl->print(String(i));
	cl->println(F("_row\">\n"));


	//		cl->print(F("_row\" ondragenter=\"return dragEnter(event)\" ondragover=\"return dragOver(event)\" ondrop=\"return dragDrop("));
	//		cl->print(String(i));
	//		cl->print(F(",event)\">\n"));


	for (uint8_t n = 0; n < ActiveSwitchersCount; n++)
	{
		if (switcher[n].group == i)
		{
			//Serial.println(String(n) + " " + String(i) + " " + switcher[n].id+  " " + String(switcher[n].group) );
			_doOneSwitchInGroupGENERATED(*(&cl), n);
		}

	}


	cl->println(F("\t\t\t\t\t\t\t\t</div>"));
	cl->println(F("\t\t\t\t\t\t\t\t</div>"));
	cl->println(F("\t\t\t\t\t\t\t\t</div>"));
	cl->println(F("\t\t\t\t\t\t\t</div>"));
	cl->println(F("\t\t\t\t\t\t</div>"));
	cl->println(F("\t\t\t\t\t</div>"));




	cl->print(F("<!---end----- switchers GROUP content - "));
	cl->print(i);
	cl->println(F(" --------  END  ----------------------------------------------  END  ---------------------------------->\n"));


}



void _doOneSwitchInGroupGENERATED(EthernetClient * cl, uint8_t n)
{


	//

	//cl->print(F("\t\t\t\t\t\t\t\t<div id=\"it_"));
	cl->print(F("\t\t\t\t\t\t\t\t<div id=\"sw"));
	cl->print(switcher[n].id);
	cl->print(F("\""));

	cl->print(F(" style=\"display:"));
	if (switcher[n].enable)
		cl->print(F(" block\""));
	else
		cl->print(F(" none\""));


	cl->print(F(" class= \"col-md-3 col-sm-6 col-xs-6\" draggable=\"true\" ondragstart=\"return dragStart(event)\">\n"));
	//cl->print(F(" class= \"col-md-3 col-sm-6\">\n"));	


	cl->print(F("\t\t\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">\n"));

	//	cl->print(F("\t\t\t\t\t\t\t\t\t\t<p id=\"itlbl"));
	//	cl->print(String(i) + "_" + String(n));
	//	cl->print(F("\" class = \"text-center\">"));
	//cl->print(SwitchWeblabel[i][n]);
	//	cl->print(F(""));
	//	cl->print(F("</p>\n"));



//	cl->print(F("\t\t\t\t\t\t\t\t\t\t<a class=\"btn btn-block btn-lg btn-default\" onclick=\"BB_Onclick(this)\" id=\"sw"));	
//	cl->print(switcher[n].id);
//	cl->print(F("\"></a>\n"));

	cl->print(F("\t\t\t\t\t\t\t\t\t\t<a class=\"btn btn-block btn-lg btn-default\" onClick=\"BB_OnClick(this)\" id=\"sw"));
	cl->print(switcher[n].id);
	cl->print(F("_lbl\"></a>\n"));
	//cl->print(F("\_lbl\"></a>\n"));



	cl->print(F("\t\t\t\t\t\t\t\t\t</div>\t<!-- class=\"div-text-and-btn-frame\" -->\n"));
	cl->print(F("\t\t\t\t\t\t\t\t</div>\n\n\n"));
	//}



}


void _doSendFooterGENERATED(EthernetClient * cl)
{
	cl->println(F("<!------------------------------------------ FOOTER -----------------------------------------------------  START  ---------------->"));

	cl->println(F("<div class=\"container-fluid\">\n"));
	cl->println(F("<div class=\"panel-footer\">\n"));

	//	indexFile->println(F("<div class=\"div-text-and-btn-frame\">"));
		//		indexFile->print(F("<a href=\"#\" id=\"config_0\" class=\"btn btn-block btn-lg btn-warning\" data-toggle=\"modal\" data-target=\"#basicModal\">indexFileick to open config</a>\n"));

	//	indexFile->println(F("<button type=\"button\" class=\"btn btn-info btn-lg btn-block\" id=\"myBtnModal\">settings</button>"));
	cl->println(F("</div>"));
	cl->println(F("</div>"));
	//	indexFile->println(F("</div>"));

	cl->println(F("<!------------------------------------------ FOOTER -----------------------------------------------------   END   ---------------->"));

}
