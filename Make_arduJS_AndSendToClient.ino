

void Make_ArduJSAndSendToClient(EthernetClient * cl)
{
#ifdef ServerDEBUG
	SERIALPRINTLN(F("\n\tSENDING adru403.js to Client"));
#endif

	startTime = millis();



	cl->println(F(

		"var strLED1 = "", strLED2 = "", requestType = \"ax_df\", sendAJAX = !0, TimeDur = 1500, firstPass = true, modalVisible = false;\n"

		"function getXmlHttpRequest() { if (window.XMLHttpRequest)return new XMLHttpRequest; try { return new ActiveXObject(\"MSXML2.XMLHTTP.3.0\") } catch (t) { return null } }"

		"function GetArduinoIO() {sendAJAX&&GetArduinoIO1()}\n"
		"function GetArduinoIO1() { nocache = \"&nc=\" + Math.random(); var e = new getXmlHttpRequest; e.onreadystatechange = function() { if (4 == this.readyState && 200 == this.status)switch (this.getResponseHeader(\"content-type\").split(\"/\")[1]) { case \"xml\":null != this.responseXML&&CheckResponse(this); break; case \"json\":CheckResponseJSON(this) } }, e.open(\"GET\", requestType + strLED1 + strLED2 + nocache, true), e.send(null), setTimeout(\"GetArduinoIO()\", TimeDur), strLED1 = \"\", strLED2 = \"\", firstPass ? requestType = \"ax_df\" : requestType = \"ax_ds\" }\n"
		"function modalShown() { modalVisible = true }function modalHidden() { modalVisible = false }\n"


		"function CheckResponseJSON(e) { var l = JSON.parse(e.responseText); for (i = 0; i < l.length - 1; i++)if (x = l[i].id, -1 < x.indexOf(\"sysmsg\"))0 < l[i].msg.length&&alert(l[i].msg); else if (-1 < x.indexOf(\"user\"))document.title = \"ჭკვიანი სახლი | controlling everything  : \" + l[i].val; else if (-1 < x.indexOf(\"grp\"))modalVisible || (document.getElementById(\"mGrpLbl\" + x.charAt(3)).innerHTML = l[i].lbl), 0 == l[i].en ? document.getElementById(x).style.display = \"none\" : (document.getElementById(\"grp\" + x.charAt(3) + \"_lbl\").innerHTML = l[i].lbl, document.getElementById(x).style.display = \"block\"); else if (-1 < x.indexOf(\"sw\"))if (document.getElementById(x + \"_lbl\").innerHTML = l[i].lbl, modalVisible || (document.getElementById(\"m\" + x).value = l[i].lbl), 0 == l[i].en)document.getElementById(x).style.display = \"none\", modalVisible || (document.getElementById(\"mChBx\" + x.charAt(2) + x.charAt(3)).checked = !1); else switch (document.getElementById(x).style.display = \"block\", modalVisible || (document.getElementById(\"mChBx\" + x.charAt(2) + x.charAt(3)).checked = !0), xElement = document.getElementById(x + \"_lbl\"), l[i].st) { case\"0\":xElement.className = \"btn btn-block btn-lg btn-danger\"; break; case\"1\":xElement.className = \"btn btn-block btn-lg btn-success\"; break; default:xElement.className = \"btn btn-block btn-lg btn-warning\" } else - 1 < x.indexOf(\"htr\") ? document.getElementById(\"htrCurrTemp_lbl\").innerHTML = l[i].lbl + '\t<span id=\"htrCurrTemp_val\" class=\"badge\">' + l[i].val + \"</span>\" : -1 < x.indexOf(\"inf\") ? document.getElementById(x + \"_lbl\").innerHTML = l[i].lbl + '\t<span id=\"inf01_val\" class=\"badge\">' + l[i].val + \"</span>\" : -1 < x.indexOf(\"Free\") ? document.getElementById(\"inf03_lbl\").innerHTML = 'freeMem\t<span id=\"inf01_val\" class=\"badge\">' + l[i].val + \"</span>\" : -1 < x.indexOf(\"prst\") && (document.getElementById(x + \"_lbl\").innerHTML = l[i].lbl, modalVisible || (document.getElementById(\"m\" + x + \"_txt\").value = l[i].lbl), \"1\" == l[i].en ? (document.getElementById(x + \"_lbl\").style.display = \"block\", document.getElementById(x + \"_lbl\").disabled = !1, document.getElementById(x + \"_lbl\").className = \"btn btn-block btn-lg btn-dark\", document.getElementById(\"m\" + x + \"_lbl\").innerHTML = \"unset\") : (document.getElementById(x + \"_lbl\").style.display = \"none\", document.getElementById(x + \"_lbl\").disabled = !0, document.getElementById(x + \"_lbl\").className = \"btn btn-block btn-lg btn-default\", document.getElementById(\"m\" + x + \"_lbl\").innerHTML = \"set\")) }"

	));




	cl->flush();
	cl->stop();


	stopTime = millis();
#ifdef ServerDEBUG
	SERIALPRINT(F("\tSENDING Ardu401.js Client DONE in \t"));
	SERIALPRINT(stopTime - startTime);
	SERIALPRINTLN(F(" milliseconds\n"));
#endif
}
