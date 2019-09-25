void MakeIndexFileonSD_B()
{

	//useCloud = false;
#ifdef ServerDEBUG
	SERIALPRINTLN(F("\n\tCREATING index.htm on SD card"));
#endif

	startTime = millis();


	File indexFile;

	//	strcpy_P(CONFIG_FILE, PSTR("server1.txt"));
	//	readConfigurationServer(CONFIG_FILE);

	//if (SD.exists("index.htm"))
	//	SD.remove("index.htm");

	if (indexFile = SD.open(F("index.htm"), O_CREAT | O_WRITE))
	{

	indexFile.println(F(

		"<!DOCTYPE HTML>\n"
		"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n"
		"<head>\n"
		"<meta http-equiv=\"Content-Type\" content=\"text/html; text/css; text/javascript; charset=utf-8\" />\n"
		"<meta name=\"viewport\" content=\"width=device-width, , initial-scale=1\">\n"
		"<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge,chrome=1\">\n"
		"<meta name=\"description\" content=\"მარტივი სახლი  | Easy Home | control Everything\">\n"

		//"<link rel = \"apple-touch-icon\" sizes = \"180x180\" href = \"/favicons/apple-touch-icon.png\">\n"
		//"<link rel = \"icon\" type = \"image/png\" sizes = \"32x32\" href = \"/favicons/favicon-32x32.png\">\n"
		//"<link rel = \"icon\" type = \"image/png\" sizes = \"16x16\" href = \"/favicons/favicon-16x16.png\">\n"
		//"<link rel = \"manifest\" href = \"/favicons/site.webmanifest\">"


		"<link rel = \"apple-touch-icon\" sizes = \"180x180\" href = \"ap-t-icn.png\">\n"
		"<link rel = \"icon\" type = \"image/png\" sizes = \"32x32\" href = \"fcn32x32.png\">\n"
		"<link rel = \"icon\" type = \"image/png\" sizes = \"16x16\" href = \"fcn16x16.png\">\n"
		"<link rel = \"manifest\" href = \"s.mnf\">\n"

	));






	indexFile.print(F("<title>ჭკვიანი სახლი | controlling everything "));
	indexFile.print(serverVersion);
	indexFile.println(F("</title>\n"));



	if (useCloud)
	{


		indexFile.print(F("<link rel=\"stylesheet\" href=\"http://"));
		indexFile.print(cloudAddress);
		indexFile.print(F("/common/css/bootstrap.min.css\">\n"));

///*
		indexFile.print(F("<link rel=\"stylesheet\" href=\"http://"));
		indexFile.print(cloudAddress);
		indexFile.print(F("/common/css/accordion.css\">\n"));

		indexFile.print(F("<link rel=\"stylesheet\" href=\"http://"));
		indexFile.print(cloudAddress);
		indexFile.print(F("/common/css/midnightblue.css\">\n"));

		indexFile.print(F("<link rel=\"stylesheet\" href=\"http://"));
		indexFile.print(cloudAddress);
		indexFile.print(F("/common/css/pre.css\">\n"));

//*/

		//indexFile.print(F("<link href=\"//netdna.bootstrapcdn.com/bootstrap/3.0.0/css/bootstrap-glyphicons.css\" rel=\"stylesheet\">"));

	}
	else
	{


		//indexFile.println(F("<link rel=\"stylesheet\" href=\"ard/common/css/btstrpmn.css\">\n"));
		//indexFile.println(F("<link rel=\"stylesheet\" href=\"ard/common/css/ccrdn.css\">\n"));
		//indexFile.println(F("<link rel=\"stylesheet\" href=\"ard/common/css/mdnghtbl.css\">\n"));
		//indexFile.println(F("<link rel=\"stylesheet\" href=\"ard/common/css/pr.css\">\n"));


		indexFile.println(F("<link rel=\"stylesheet\" href=\"btstrpmn.css\">\n"));
		indexFile.println(F("<link rel=\"stylesheet\" href=\"ccrdn.css\">\n"));
		indexFile.println(F("<link rel=\"stylesheet\" href=\"mdnghtbl.css\">\n"));
		indexFile.println(F("<link rel=\"stylesheet\" href=\"pr.css\">\n"));


	}



	indexFile.println(F("<noscript>Uuups Either Your browser does not support JavaScript! or it is Disabled. OUR SMART HOME Server needs javascript</noscript>"));
	indexFile.println(F("<noscript>ჯავა სკრიპტი გამორთულია ან ძველი ბრაუზერია ეს? </noscript>"));



//	embedCSS("btstrpmn.css", &indexFile);
//	embedCSS("ccrdn.css", &indexFile);
//	embedCSS("mdnghtbl.css", &indexFile);
//	embedCSS("pre.css", &indexFile);



	indexFile.println(F("</head>\n\n"));
	

	

	indexFile.println(F("<body id=\"body\" onload=\"GetArduinoIO()\">\n\n"));



	indexFile.println(F("<!------------------------------------------ PRELOADER -----------------------------------------------------  START  ---------------->"));
	indexFile.println(F("<!--CSS Spinner-->"));
	indexFile.println(F("<div class=\"spinner-wrapper\">"));
	indexFile.println(F("<div class=\"spinner\"></div>"));
	indexFile.println(F("</div>"));
	indexFile.println(F("<!------------------------------------------ PRELOADER -----------------------------------------------------   END   ---------------->\n"));

	if (useCloud)
	{

//		indexFile.print(F("\t\t<main class=\"container-fluid\" style=\"background-image:url(http://"));
//		indexFile.print(cloudAddress);
//		indexFile.println(F("/common/img/img_bg_5.jpg); background-position:center center; min-height:100%; min-height: 100vh; align-items: center; background-repeat:  no-repeat; background-attachment:fixed; background-size:cover;\">"));

		indexFile.print(F("\t\t<main class=\"container-fluid\" style=\"background-image:url(http://"));
		indexFile.print(String(SERVER_IP[0]) + "." + String(SERVER_IP[1]) + "." + String(SERVER_IP[2]) + "." + String(SERVER_IP[3]) + ":" + String(SERVER_PORT));
		indexFile.println(F("/img_bg_5.jpg); background-position:center center; min-height:100%; min-height: 100vh; align-items: center; background-repeat:  no-repeat; background-attachment:fixed; background-size:cover;\">"));

	}
	else
	{
		indexFile.print(F("\t\t<main class=\"container-fluid\" style=\"background-image:url(http://"));
		indexFile.print(String(SERVER_IP[0]) + "." + String(SERVER_IP[1]) + "." + String(SERVER_IP[2]) + "." + String(SERVER_IP[3]) + ":" + String(SERVER_PORT));
		indexFile.println(F("/img_bg_5.jpg); background-position:center center; min-height:100%; min-height: 100vh; align-items: center; background-repeat:  no-repeat; background-attachment:fixed; background-size:cover;\">"));


		
	}


	indexFile.println(F("\t\t\t<div id =\"resp_div\" class=\"col-lg-12 col-md-12 col-sm-12 col-xs-12\">"));
	indexFile.println(F("\t\t\t\t<div class=\"container container-fluid\">\n"));


	

	_DoInfoBarB(& indexFile);

	if (presetsAllowed)
		_doSendPresetsB(&indexFile);
	if ((infraRedAllowed) && (infraRedCmdCount > 0))
		_doSendInfraRed(&indexFile);



	for (uint8_t i = 0; i < ActiveGroupsCount; i++)
	{
		//if (SwitchGroupWebVisible[i])
		_DoGroupSection4B(& indexFile, i);

	}



	if (heaterAllowed)
		_doSendHeaterB(& indexFile);








	indexFile.println(F("<div class=\"div-text-and-btn-frame\">"));
	//		indexFile.print(F("<a href=\"#\" id=\"config_0\" class=\"btn btn-block btn-lg btn-warning\" data-toggle=\"modal\" data-target=\"#basicModal\">Click to open config</a>\n"));

	indexFile.println(F("<button type=\"button\" class=\"btn btn-secondary btn-lg btn-block\" id=\"myBtnModal\">settings</button>"));
	indexFile.println(F("</div>"));



	indexFile.println(F("\t\t\t\t</div>\t<!--\tclass=\"container container-fluid\"\t-->\n"));
	indexFile.println(F("\t\t\t</div>\t<!--\tid =\"resp_div\"\t-->\n"));
	indexFile.println(F("\t\t</main>\n"));



	_doSendFooter4B(& indexFile);
	indexFile.println(F("<div class=\"section section-success\">\n"


		"<div class=\"container\">"));



	indexFile.println(F("</div>\n"));


	indexFile.println(F("</div>\n"));







	_doSendModal4_B(& indexFile);



	indexFile.println(F("\n\n<input type=\"hidden\" id=\"appCheck\" value=\"\" />\n\n"));




	if (useCloud)
	{

		indexFile.print(F("<script language=\"javascript\" src=\"http://"));
		indexFile.print(cloudAddress);
		indexFile.print(F("/common/js/ardu_401.js\""));
		indexFile.print(F(" type=\"text/javascript\"></script>\n"));

		indexFile.print(F("<script language=\"javascript\" src=\"http://"));
		indexFile.print(cloudAddress);
		indexFile.print(F("/common/js/ar_401.js\""));
		indexFile.print(F(" type=\"text/javascript\"></script>\n"));

		indexFile.print(F("<script language=\"javascript\" src=\"http://"));
		indexFile.print(cloudAddress);
		indexFile.print(F("/common/js/idle.js\""));
		indexFile.print(F(" type=\"text/javascript\"></script>\n"));



		//FileIn_SD_filetype.print(F("<script language=\"javascript\" src=\"http://"));
		//FileIn_SD_filetype.print(cloudadress);
		//FileIn_SD_filetype.print(F("/common/modal.js\""));
		//FileIn_SD_filetype.print(F(" type=\"text/javascript\"></script>\n"));

		indexFile.print(F("<script language=\"javascript\" src=\"http://"));
		indexFile.print(cloudAddress);
		indexFile.print(F("/common/js/jquery.min.js\""));
		indexFile.print(F(" type=\"text/javascript\"></script>\n"));

		indexFile.print(F("<script language=\"javascript\" src=\"http://"));
		indexFile.print(cloudAddress);
		indexFile.print(F("/common/js/bootstrap.min.js\""));
		indexFile.print(F(" type=\"text/javascript\"></script>\n"));

		//indexFile.print(F("<script language=\"javascript\" src=\"http://"));
		//indexFile.print(cloudAddress);
		//indexFile.print(F("/common/js/appcnnct.js\""));
		//indexFile.print(F(" type=\"text/javascript\"></script>\n"));




	}
	else
	{



		//indexFile.println(F("<script language=\"javascript\" src=\"ard/common/js/ardu_401.js\" type=\"text/javascript\"></script>\n"));
		//indexFile.println(F("<script language=\"javascript\" src=\"ard/common/js/ar_401.js\" type=\"text/javascript\"></script>\n"));
		//indexFile.println(F("<script language=\"javascript\" src=\"ard/common/js/idle.js\" type=\"text/javascript\"></script>\n"));
		//indexFile.println(F("<script language=\"javascript\" src=\"ard/common/js/jqrmn.js\" type=\"text/javascript\"></script>\n"));
		//indexFile.println(F("<script language=\"javascript\" src=\"ard/common/js/btstrpmn.js\" type=\"text/javascript\"></script>\n"));


		indexFile.println(F("<script language=\"javascript\" src=\"ardu_401.js\" type=\"text/javascript\"></script>\n"));
		indexFile.println(F("<script language=\"javascript\" src=\"ar_401.js\" type=\"text/javascript\"></script>\n"));
		indexFile.println(F("<script language=\"javascript\" src=\"idle.js\" type=\"text/javascript\"></script>\n"));
		indexFile.println(F("<script language=\"javascript\" src=\"jqrmn.js\" type=\"text/javascript\"></script>\n"));
		indexFile.println(F("<script language=\"javascript\" src=\"btstrpmn.js\" type=\"text/javascript\"></script>\n"));

	}




	//		indexFile.println(F("<script language=\"javascript\" src=\"https://parkosadze.com/_asm/ardunew1.js\" type=\"text/javascript\"></script>\n"));
	//		indexFile.println(F("<script language=\"javascript\" src=\"https://parkosadze.com/_asm/modal.js\" type=\"text/javascript\"></script>\n"));


	//if (presetsAllowed)
	//	_presetfunc2Script(&FileIn_SD_filetype);












	indexFile.println(F("\t\t<script>"));


	/*
	indexFile.println(F("\t\t\t$(document).ready(function(){"));

					//indexFile.println(F("idleTimer();"));


		indexFile.println(F("\t\t\t\t$(\"#myBtnModal\").click(function(){"));
			indexFile.println(F("\t\t\t\t\t$(\"#basicModal\").modal(\"show\");"));
		indexFile.println(F("\t\t\t\t});"));
		indexFile.println(F("\t\t\t\t$(\"#basicModal\").on('shown.bs.modal', function () {"));
			indexFile.println(F("\t\t\t\t\tmodalShown();"));

		indexFile.println(F("\t\t\t\t});"));
		indexFile.println(F("\t\t\t\t$(\"#basicModal\").on('hidden.bs.modal', function () {"));
			indexFile.println(F("\t\t\t\t\tmodalHidden();"));

		indexFile.println(F("\t\t\t\t});"));
	indexFile.println(F("\t\t\t\t});"));

	*/


	indexFile.println(F("\t\t\t$(document).ready(function()"));
	indexFile.println(F("\t\t\t{"));
	indexFile.println(F("\t\t\t\t$(\"#myBtnModal\").click(function(){$(\"#basicModal\").modal(\"show\");});"));
	indexFile.println(F("\t\t\t\t$(\"#basicModal\").on(\"shown.bs.modal\", function () {modalShown();});"));
	indexFile.println(F("\t\t\t\t$(\"#basicModal\").on(\"hidden.bs.modal\", function () {modalHidden();});"));


	indexFile.println(F("\t\t\t\t$(window).on(\"load\", function() {preloaderFadeOutTime = 500;"));
	indexFile.println(F("\t\t\t\tfunction hidePreloader() {var preloader = $(\".spinner-wrapper\");preloader.fadeOut(preloaderFadeOutTime);}hidePreloader();});"));
	indexFile.println(F("\t\t\t\t});"));


	indexFile.println(F("\t\t\t</script>"));




	/*

	indexFile.println(F("\n\n\t\t\t<script>"));

	indexFile.println(F("var test = $('#appCheck').val();"));
	indexFile.println(F("alert(test);"));


	indexFile.println(F("\t\t\t</script>"));

	*/



	indexFile.println(F("</body>\n"));

	indexFile.println(F("</html>\n"));





	indexFile.flush();
	indexFile.close();

#ifdef ServerDEBUG
	stopTime = millis();
	SERIALPRINT(F("\tCREATED index.htm on SD in \t"));
	SERIALPRINT(stopTime - startTime);
	SERIALPRINTLN(F(" milliseconds\n"));
#endif

	}
	else
	{
		#ifdef ServerDEBUG
			stopTime = millis();
			SERIALPRINT(F("\tCREATIN PROBLEM index.htm on SD in \t"));
			SERIALPRINT(stopTime - startTime);
			SERIALPRINTLN(F(" milliseconds\n"));
		#endif

	}


	

	
	

}



void _DoGroupSection4B(File * indexFile, uint8_t i)
{

	indexFile->print(F("<!--start---- switchers GROUP content - "));
	indexFile->print(i);
	indexFile->println(F(" -------- START ---------------------------------------------- START ---------------------------------->\n"));

	indexFile->print(F("\t\t\t\t\t<div class=\"row\" id=\""));
	indexFile->print(group[i].id);
	indexFile->print(F("\" style=\"display:"));
	if (group[i].enable) { indexFile->print(F("block\">\n")); }
	else { indexFile->print(F("none\">\n")); }


	indexFile->print(F("\t\t\t\t\t\t<div class=\"tc-accordion-style5\" id=\"accrdn_"));
	indexFile->print(String(i));
	indexFile->print(F("\""));
	if (dndEnable)
	{
		indexFile->print(F(" ondragenter=\"return dragEnter(event)\" ondragover=\"return dragOver(event)\" ondrop=\"return dragDrop("));
		indexFile->print(String(i));
		indexFile->print(F(",event)\""));
	}

	indexFile->print(F(">\n"));


	indexFile->print(F("\t\t\t\t\t\t\t<div class=\"panel\" id=\"grp"));
	indexFile->print(String(i));
	indexFile->print(F("_pnl\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t<h4 class=\"acdn-title team-title\">\n"));


	indexFile->print(F("\t\t\t\t\t\t\t\t\t<a id=\""));
	indexFile->print(group[i].id);

	indexFile->print(F("_lbl\" data-toggle=\"collapse\" data-parent=\"#accrdn_"));
	indexFile->print(String(i));
	indexFile->print(F("\" href=\""));
	//indexFile->print(F("\" href=\"http://"));
	//indexFile->print(cloudadress);
	indexFile->print(F("ard/#colsp"));
	indexFile->print(String(i));
	indexFile->print(F("\" aria-expanded=\"false\" class=\"collapsed\">"));


	indexFile->print(group[i].lbl);
	indexFile->print(F("<span>.</span></a>\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t</h4>\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t<div class=\"panel-collapse collapse\" aria-expanded=\"false\" style=\"height: 0px;\" id=\"colsp"));
	indexFile->print(String(i));
	indexFile->print(F("\">\n"));

	indexFile->println(F("\t\t\t\t\t\t\t\t<div class=\"acdn-body\">"));
	indexFile->print(F("\t\t\t\t\t\t\t\t<div class=\"row\" id=\"grp"));
	indexFile->print(String(i));
	indexFile->println(F("_row\">\n"));


	//		indexFile->print(F("_row\" ondragenter=\"return dragEnter(event)\" ondragover=\"return dragOver(event)\" ondrop=\"return dragDrop("));
	//		indexFile->print(String(i));
	//		indexFile->print(F(",event)\">\n"));


	for (uint8_t n = 0; n < ActiveSwitchersCount; n++)
	{
		if (switcher[n].group == i)
		{
			//Serial.println(String(n) + " " + String(i) + " " + switcher[n].id+  " " + String(switcher[n].group) );
			_doOneSwitchInGroup2B(*(&indexFile), n);
		}

	}


	indexFile->println(F("\t\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t</div>"));




	indexFile->print(F("<!---end----- switchers GROUP content - "));
	indexFile->print(i);
	indexFile->println(F(" --------  END  ----------------------------------------------  END  ---------------------------------->\n"));


}



void _doOneSwitchInGroup2B(File * indexFile, uint8_t n)
{


	//

	//cl->print(F("\t\t\t\t\t\t\t\t<div id=\"it_"));
	indexFile->print(F("\t\t\t\t\t\t\t\t<div id=\"sw"));
	indexFile->print(switcher[n].id);
	indexFile->print(F("\""));

	indexFile->print(F(" style=\"display:"));
	if (switcher[n].enable)
		indexFile->print(F(" block\""));
	else
		indexFile->print(F(" none\""));


	indexFile->print(F(" class= \"col-md-3 col-sm-6 col-xs-6\" draggable=\"true\" ondragstart=\"return dragStart(event)\">\n"));
	//indexFile->print(F(" class= \"col-md-3 col-sm-6\">\n"));	


	indexFile->print(F("\t\t\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">\n"));

	//	indexFile->print(F("\t\t\t\t\t\t\t\t\t\t<p id=\"itlbl"));
	//	indexFile->print(String(i) + "_" + String(n));
	//	indexFile->print(F("\" class = \"text-center\">"));
	//indexFile->print(SwitchWeblabel[i][n]);
	//	indexFile->print(F(""));
	//	indexFile->print(F("</p>\n"));



//	indexFile->print(F("\t\t\t\t\t\t\t\t\t\t<a class=\"btn btn-block btn-lg btn-default\" onindexFileick=\"BB_OnindexFileick(this)\" id=\"sw"));	
//	indexFile->print(switcher[n].id);
//	indexFile->print(F("\"></a>\n"));

	indexFile->print(F("\t\t\t\t\t\t\t\t\t\t<a class=\"btn btn-block btn-lg btn-default\" onClick=\"BB_OnClick(this)\" id=\"sw"));
	indexFile->print(switcher[n].id);
	indexFile->print(F("_lbl\"></a>\n"));
	//indexFile->print(F("\_lbl\"></a>\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t</div>\t<!-- class=\"div-text-and-btn-frame\" -->\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t</div>\n\n\n"));
	//}



}


void _doSendFooter4B(File * indexFile)
{
	indexFile->println(F("<!------------------------------------------ FOOTER -----------------------------------------------------  START  ---------------->"));

	indexFile->println(F("<div class=\"container-fluid\">\n"));
	indexFile->println(F("<div class=\"panel-footer\">\n"));

	//	indexFile->println(F("<div class=\"div-text-and-btn-frame\">"));
		//		indexFile->print(F("<a href=\"#\" id=\"config_0\" class=\"btn btn-block btn-lg btn-warning\" data-toggle=\"modal\" data-target=\"#basicModal\">indexFileick to open config</a>\n"));

	//	indexFile->println(F("<button type=\"button\" class=\"btn btn-info btn-lg btn-block\" id=\"myBtnModal\">settings</button>"));
	indexFile->println(F("</div>"));
	indexFile->println(F("</div>"));
	//	indexFile->println(F("</div>"));

	indexFile->println(F("<!------------------------------------------ FOOTER -----------------------------------------------------   END   ---------------->"));

}


void _DoInfoBarB(File * indexFile)
{

	indexFile->println(F("<!------------------------------------------ INFO BAR -----------------------------------------------------  START  ---------------->\n"));
	indexFile->println(F("\t\t\t\t<div class=\"page-header\">"));
	indexFile->println(F("\t\t\t\t\t<div class=\"panel panel-warning\" style=\"background:none\">"));
	//	indexFile->println(F("\t\t\t\t\t\t<div class=\"panel-heading\">"));
	//	indexFile->println(F("\t\t\t\t\t\t\t<h3 class=\"panel-title\">...</h3>"));
	//	indexFile->println(F("\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t<div class=\"panel-body\" style=\"background:none\">\n"));


	indexFile->println(F("\t\t\t\t\t\t\t<div id=\"inf00\" style=\"display: block\" class=\"col-md-3 col-sm-6\">"));
	indexFile->println(F("\t\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">"));
	indexFile->println(F("\t\t\t\t\t\t\t\t<a class=\"btn btn-block btn-lg btn-default\" id=\"inf00_lbl\">waiting <span id=\"inf00_val\" class=\"badge\">...</span></a>"));
	indexFile->println(F("\t\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t\t</div>\n"));


	indexFile->println(F("\t\t\t\t\t\t\t<div id=\"inf01\" style=\"display: block\" class=\"col-md-3 col-sm-6\">"));
	indexFile->println(F("\t\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">"));
	indexFile->println(F("\t\t\t\t\t\t\t\t<a class=\"btn btn-block btn-lg btn-default\" id=\"inf01_lbl\">waiting <span id=\"inf01_val\" class=\"badge\">...</span></a>"));
	indexFile->println(F("\t\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t\t</div>\n"));

	indexFile->println(F("\t\t\t\t\t\t\t<div id=\"inf02\" style=\"display: block\" class=\"col-md-3 col-sm-6\">"));
	indexFile->println(F("\t\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">"));
	indexFile->println(F("\t\t\t\t\t\t\t\t<a class=\"btn btn-block btn-lg btn-default\" id=\"inf02_lbl\">waiting <span id=\"inf02_val\" class=\"badge\">...</span></a>"));
	indexFile->println(F("\t\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t\t</div>\n"));

	indexFile->println(F("\t\t\t\t\t\t\t<div id=\"inf03\" style=\"display: block\" class=\"col-md-3 col-sm-6\">"));
	indexFile->println(F("\t\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">"));
	indexFile->println(F("\t\t\t\t\t\t\t\t<a class=\"btn btn-block btn-lg btn-default\" id=\"inf03_lbl\">waiting <span id=\"inf03_val\" class=\"badge\">...</span></a>"));
	indexFile->println(F("\t\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t\t</div>\n"));


	indexFile->println(F("\t\t\t\t\t\t</div>\t<!-- class=\"panel-body\" -->"));
	indexFile->println(F("\t\t\t\t\t</div>\t<!-- class=\"panel panel-warning\" -->"));
	indexFile->println(F("\t\t\t\t</div>\t<!-- class=\"page-header\" -->\n\n"));

	indexFile->println(F("<!------------------------------------------ INFO BAR -----------------------------------------------------   END   ---------------->"));

}




void _doSendInfraRed(File * indexFile)
{


	indexFile->println(F(" <!----- INFRARED GROUP content ------------------------------------------------------ START ---------------------------------->\n"));

	indexFile->print(F("\t\t\t\t\t<div class=\"row\" id=\""));
	indexFile->print("grpinfra");
	indexFile->print(F("\" style=\"display:"));
	indexFile->print(F("block\">\n"));

	//	if (presetsAllowed) { indexFile->print(F("block\">\n")); }
	//	else { indexFile->print(F("none\">\n")); }



	indexFile->print(F("\t\t\t\t\t\t<div class=\"tc-accordion-style4\" id=\"accrdn_infra\">\n"));


	indexFile->print(F("\t\t\t\t\t\t\t<div class=\"panel\" id=\"infra_pnl\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t<h4 class=\"acdn-title team-title\">\n"));


	indexFile->print(F("\t\t\t\t\t\t\t\t\t<a id=\"infra_lbl\" data-toggle=\"collapse\" data-parent=\"#accrdn_infra\" href=\"ard/#colspinfra\" aria-expanded=\"false\" class=\"collapsed\">"));



	indexFile->print(F("IR Commands<span>.</span></a>\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t</h4>\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t<div class=\"panel-collapse collapse\" aria-expanded=\"false\" style=\"height: 0px;\" id=\"colspinfra\">\n"));

	indexFile->println(F("\t\t\t\t\t\t\t\t<div class=\"acdn-body\">"));
	indexFile->print(F("\t\t\t\t\t\t\t\t<div class=\"row\" id=\"infra_row\">\n\n"));


	//		indexFile->print(F("_row\" ondragenter=\"return dragEnter(event)\" ondragover=\"return dragOver(event)\" ondrop=\"return dragDrop("));
	//		indexFile->print(String(i));
	//		indexFile->print(F(",event)\">\n"));


	for (uint8_t n = 0; n < infraRedCmdCount; n++)
	{

		
		_doOneInfraInGroup2B(*(&indexFile), n);
	}

	indexFile->println(F("\t\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t</div>"));





	indexFile->println(F(" <!----- INFRARED GROUP content ------------------------------------------------------- END ----------------------------------->\n"));
}



void _doOneInfraInGroup2B(File * indexFile, uint8_t n)
{


	//

	//indexFile->print(F("\t\t\t\t\t\t\t\t<div id=\"it_"));
	indexFile->print(F("\t\t\t\t\t\t\t\t<div id=\"infra"));
	indexFile->print(String(n));
	indexFile->print(F("\""));

	indexFile->print(F(" style=\"display:block\" class= \"col-lg-2 col-md-4 col-sm-6 col-xs-6\">\n"));

	indexFile->print(F("\t\t\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">\n"));

	//	indexFile->print(F("\t\t\t\t\t\t\t\t\t\t<p id=\"itlbl"));
	//	indexFile->print(String(i) + "_" + String(n));
	//	indexFile->print(F("\" class = \"text-center\">"));
	//indexFile->print(SwitchWeblabel[i][n]);
	//	indexFile->print(F(""));
	//	indexFile->print(F("</p>\n"));



	//	indexFile->print(F("\t\t\t\t\t\t\t\t\t\t<a class=\"btn btn-block btn-lg btn-default\" onindexFileick=\"BB_OnindexFileick(this)\" id=\"sw"));
	//	indexFile->print(switcher[n].id);
	//	indexFile->print(F("\"></a>\n"));

	indexFile->print(F("\t\t\t\t\t\t\t\t\t\t<button type=\"button\" contenteditable=\"false\" class=\"btn btn-block btn-lg btn-default\" onClick=\"infra_OnClick(this,"));
	indexFile->print(String(n));
	indexFile->print(F(")\" id=\"infra"));
	indexFile->print(String(n));
	indexFile->print(F("_lbl\">IR command #"));
	//indexFile->print(F("_lbl\" disabled>preset #"));

	indexFile->print(String(n));
	indexFile->print(F("</button>\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t</div>\t<!-- class=\"div-text-and-btn-frame\" -->\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t</div>\n\n\n"));
	//}



}

void _doSendPresetsB(File * indexFile)
{


	indexFile->println(F(" <!----- PRESETS GROUP content ------------------------------------------------------ START ---------------------------------->\n"));

	indexFile->print(F("\t\t\t\t\t<div class=\"row\" id=\""));
	indexFile->print("grpprst");
	indexFile->print(F("\" style=\"display:"));
	indexFile->print(F("block\">\n")); 
	
//	if (presetsAllowed) { indexFile->print(F("block\">\n")); }
//	else { indexFile->print(F("none\">\n")); }



	indexFile->print(F("\t\t\t\t\t\t<div class=\"tc-accordion-style4\" id=\"accrdn_prst\">\n"));


	indexFile->print(F("\t\t\t\t\t\t\t<div class=\"panel\" id=\"prst_pnl\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t<h4 class=\"acdn-title team-title\">\n"));


	indexFile->print(F("\t\t\t\t\t\t\t\t\t<a id=\"prst_lbl\" data-toggle=\"collapse\" data-parent=\"#accrdn_prst\" href=\"ard/#colspprst\" aria-expanded=\"false\" class=\"collapsed\">"));



	indexFile->print(F("პრესეტები<span>.</span></a>\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t</h4>\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t<div class=\"panel-collapse collapse\" aria-expanded=\"false\" style=\"height: 0px;\" id=\"colspprst\">\n"));

	indexFile->println(F("\t\t\t\t\t\t\t\t<div class=\"acdn-body\">"));
	indexFile->print(F("\t\t\t\t\t\t\t\t<div class=\"row\" id=\"prst_row\">\n\n"));


	//		indexFile->print(F("_row\" ondragenter=\"return dragEnter(event)\" ondragover=\"return dragOver(event)\" ondrop=\"return dragDrop("));
	//		indexFile->print(String(i));
	//		indexFile->print(F(",event)\">\n"));


	
	for (uint8_t n = 0; n < 6; n++)
	{

		//Serial.println(String(n) + " " + String(i) + " " + switcher[n].id+  " " + String(switcher[n].group) );
		_doOnePresetInGroup2B(*(&indexFile), n);


	}


	indexFile->println(F("\t\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t</div>"));





	indexFile->println(F(" <!----- PRESETS GROUP content ------------------------------------------------------- END ----------------------------------->\n"));
}


void _doOnePresetInGroup2B(File * indexFile, uint8_t n)
{


	//

	//indexFile->print(F("\t\t\t\t\t\t\t\t<div id=\"it_"));
	indexFile->print(F("\t\t\t\t\t\t\t\t<div id=\"prst"));
	indexFile->print(String(n));
	indexFile->print(F("\""));

	indexFile->print(F(" style=\"display:block\" class= \"col-lg-2 col-md-4 col-sm-6 col-xs-6\">\n"));

	indexFile->print(F("\t\t\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">\n"));

	//	indexFile->print(F("\t\t\t\t\t\t\t\t\t\t<p id=\"itlbl"));
	//	indexFile->print(String(i) + "_" + String(n));
	//	indexFile->print(F("\" class = \"text-center\">"));
	//indexFile->print(SwitchWeblabel[i][n]);
	//	indexFile->print(F(""));
	//	indexFile->print(F("</p>\n"));



	//	indexFile->print(F("\t\t\t\t\t\t\t\t\t\t<a class=\"btn btn-block btn-lg btn-default\" onindexFileick=\"BB_OnindexFileick(this)\" id=\"sw"));
	//	indexFile->print(switcher[n].id);
	//	indexFile->print(F("\"></a>\n"));

	indexFile->print(F("\t\t\t\t\t\t\t\t\t\t<button type=\"button\" contenteditable=\"false\" class=\"btn btn-block btn-lg btn-default\" onClick=\"prst_OnClick(this,"));
	indexFile->print(String(n));
	indexFile->print(F(")\" id=\"prst"));
	indexFile->print(String(n));
	indexFile->print(F("_lbl\">preset #"));
	//indexFile->print(F("_lbl\" disabled>preset #"));
	
	indexFile->print(String(n));
	indexFile->print(F("</button>\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t</div>\t<!-- class=\"div-text-and-btn-frame\" -->\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t</div>\n\n\n"));
	//}



}




void _doSendHeaterB(File * indexFile)
{


	indexFile->println(F(" <!----- HEATER GROUP content ------------------------------------------------------ START ---------------------------------->\n"));

	indexFile->print(F("\t\t\t\t\t<div class=\"row\" id=\""));
	indexFile->print("grphtr");
	indexFile->print(F("\" style=\"display:"));
	if (heaterAllowed) { indexFile->print(F("block\">\n")); }
	else { indexFile->print(F("none\">\n")); }


	indexFile->print(F("\t\t\t\t\t\t<div class=\"tc-accordion-style4\" id=\"accrdn_htr\">\n"));


	indexFile->print(F("\t\t\t\t\t\t\t<div class=\"panel\" id=\"htr_pnl\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t<h4 class=\"acdn-title team-title\">\n"));


	indexFile->print(F("\t\t\t\t\t\t\t\t\t<a id=\"hrt_lbl\" data-toggle=\"collapse\" data-parent=\"#accrdn_htr\" href=\"ard/#colsphtr\" aria-expanded=\"false\" class=\"collapsed\">"));



	indexFile->print(F("გათბობა<span>.</span></a>\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t</h4>\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t<div class=\"panel-collapse collapse\" aria-expanded=\"false\" style=\"height: 0px;\" id=\"colsphtr\">\n"));

	indexFile->println(F("\t\t\t\t\t\t\t\t<div class=\"acdn-body\">"));
	indexFile->print(F("\t\t\t\t\t\t\t\t<div class=\"row\" id=\"htr_row\">\n\n"));


	//		indexFile->print(F("_row\" ondragenter=\"return dragEnter(event)\" ondragover=\"return dragOver(event)\" ondrop=\"return dragDrop("));
	//		indexFile->print(String(i));
	//		indexFile->print(F(",event)\">\n"));


	//for (uint8_t n = 0; n < 2; n++)
	//{

		//Serial.println(String(n) + " " + String(i) + " " + switcher[n].id+  " " + String(switcher[n].group) );
	_doOneHeaterInGroup2B(*(&indexFile), 0);


	//}


	indexFile->println(F("\t\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t</div>"));





	indexFile->println(F(" <!----- HEATER GROUP content ------------------------------------------------------- END ----------------------------------->\n"));
}


void _doOneHeaterInGroup2B(File * indexFile, uint8_t n)
{

	indexFile->print(F("\t\t\t\t\t\t\t\t<div id=\"htr"));
	indexFile->print(String(n));
	indexFile->print(F("\""));
	indexFile->print(F(" style=\"display:block\" class= \"col-lg-4 col-md-4 col-sm-4 col-xs-12\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">\n"));


	indexFile->println(F("\t\t\t\t\t\t\t<div id=\"htrCurrTemp\" style=\"display: block\">"));
	indexFile->println(F("\t\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">"));
	indexFile->println(F("\t\t\t\t\t\t\t\t<a class=\"btn btn-block btn-lg btn-default\" id=\"htrCurrTemp_lbl\">waiting <span id=\"htrCurrTemp_val\" class=\"badge\">...</span></a>"));
	indexFile->println(F("\t\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t\t</div>\n"));


	indexFile->print(F("\t\t\t\t\t\t\t\t\t</div>\t<!-- class=\"div-text-and-btn-frame\" -->\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t</div>\n\n\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t<div id=\"htr"));
	indexFile->print(String(n++));
	indexFile->print(F("\""));
	indexFile->print(F(" style=\"display:block\" class= \"col-lg-4 col-md-4 col-sm-4 col-xs-12\">\n"));

	indexFile->print(F("\t\t\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">\n"));

	indexFile->println(F("\t\t\t\t\t\t\t\t\t\t\t<select class=\"custom-select\" id=\"htrTargetTemp\" style=\"width:100%; height:100%\">"));
	indexFile->println(F("\t\t\t\t\t\t\t\t\t\t\t\t<option selected>Choose target TEMP</option>"));
	indexFile->print(F("\t\t\t\t\t\t\t\t\t\t\t\t<option value=\"-100\">OFF</option>\n"));

	for (uint8_t i = 18; i < 26; i++)
	{
		indexFile->print(F("\t\t\t\t\t\t\t\t\t\t\t\t<option value=\""));
		indexFile->print(String(i));
		indexFile->print(F("\">"));
		indexFile->print(String(i));
		indexFile->print(F("</option>\n"));
	}
	indexFile->println(F("\t\t\t\t\t\t\t\t\t\t</select>"));
	indexFile->print(F("\t\t\t\t\t\t\t\t\t</div>\t<!-- class=\"div-text-and-btn-frame\" -->\n"));


	indexFile->print(F("\t\t\t\t\t\t\t\t</div>\n\n\n"));




	indexFile->print(F("\t\t\t\t\t\t\t\t<div id=\"htr"));
	indexFile->print(String(n++));
	indexFile->print(F("\""));
	indexFile->print(F(" style=\"display:block\" class= \"col-lg-4 col-md-4 col-sm-4 col-xs-12\">\n"));

	indexFile->print(F("\t\t\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">\n"));


	indexFile->println(F("\t\t\t\t\t\t\t\t\t<button type=\"button\" class=\"btn btn-block btn-lg btn-default\" onClick=\"htr_OnClick(this)\" id=\"htr1_lbl\">SET</button>"));

	indexFile->print(F("\t\t\t\t\t\t\t\t\t</div>\t<!-- class=\"div-text-and-btn-frame\" -->\n"));


	indexFile->print(F("\t\t\t\t\t\t\t\t</div>\n\n\n"));


}
