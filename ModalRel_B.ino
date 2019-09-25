



void _doSendModal4_B(File * indexFile)

{

	indexFile->print(F("<!------------------------------------------ MODAL FORM ----------------------------------------------------- START ---------------->\n"));

	/*
		IndexFile->println(F("<script>"));
		IndexFile->print(F("$('#basicModal').on('shown.bs.modal', function (e) {modalVisible= true;})"));
		IndexFile->println(F("</script>"));

		IndexFile->println(F("<script>"));
		IndexFile->print(F("$('#basicModal').on('hidden.bs.modal', function (e) {modalVisible= false;})"));
		IndexFile->println(F("</script>"));
	*/

	indexFile->print(F("\t\t<div class=\"modal fade\" id=\"basicModal\" tabindex=\"-1\" role=\"dialog\" aria-labelledby=\"basicModal\" aria-hidden=\"true\">\n"
		"\t\t\t<div class=\"modal-dialog modal-dialog-centered\" role=\"document\">\n"
		"\t\t\t<div class=\"modal-content\">\n"
		"\t\t\t<div class=\"modal-header\">\n"
		"\t\t\t\t\t<h4 class=\"modal-title\" id=\"myModalLabel\">სისტემა და კონფიგურაცია </h4>\n"

		"\t\t\t</div>\t<!-- class=\"modal-header\"-->\n"

		"\t\t\t<div role=\"tabpanel\">\n"));



	indexFile->print(F("\t\t\t\t<ul class=\"nav nav-tabs\" role=\"tablist\">\n"));

	for (uint8_t i = 0; i < 3; i++)
	{




		if (i == 0)
			indexFile->print(F("\t\t\t\t\t<li id=\"modalTab0\" role=\"presentation\" class=\"active\" style=\"display:block\">\n"));
		else
		{
			indexFile->print(F("\t\t\t\t\t<li id=\"modalTab"));
			indexFile->print(String(i));
			indexFile->print(F("\" role = \"presentation\" style=\"display:block\">\n"));
		}
		indexFile->print(F("\t\t\t\t\t\t<a href=\"#group"));
		indexFile->print(String(i));
		indexFile->print(F("Tab\" id=\"groupTab"));
		indexFile->print(String(i));
		indexFile->print(F("\" aria-controls=\"group"));
		indexFile->print(String(i));
		indexFile->print(F("Tab\" role=\"tab\" data-toggle=\"tab\">"));
		switch (i)
		{
		case 0: { indexFile->print("ჯგუფები"); break; }
		case 1: { indexFile->print("ჩამრთველი"); break; }
		case 2: { indexFile->print("პრესეტები"); break; }
		//case 3: { indexFile->print("მომხმარებელი"); break; }
		//case 4: { indexFile->print("ADD NEW User"); break; }
		}

		indexFile->print(F("</a>\n"));


		indexFile->print(F("\t\t\t\t\t</li>\n"));

	}
	indexFile->print(F("\t\t\t\t</ul>\n\n"));


	indexFile->print(F("\t\t\t\t<div class=\"tab-content\">\n\n\n\n"));

	for (uint8_t i = 0; i < 3; i++)
	{


		if (i == 0)
			indexFile->print(F("\t\t\t\t\t<div role=\"tabpanel\" class=\"tab-pane active\" id=\"group"));
		else
			indexFile->print(F("\t\t\t\t\t<div role=\"tabpanel\" class=\"tab-pane\" id=\"group"));

		indexFile->print(String(i));
		indexFile->print(F("Tab\">\n"));

		indexFile->print(F("\t\t\t\t\t<div class=\"row\" style=\"padding:5px\">\n\n"));

		switch (i)
		{
		case 0:
		{
			//for (uint8_t n=0; n < 2; n++)
			for (uint8_t n = 0; n < ActiveGroupsCount; n++)
				sendGroupRowItemModalB(*(&indexFile), n, group[n].lbl, group[n].enable);

			sendHtrGrpModalRowItemB(*(& indexFile), 0, "გათბობა", heaterAllowed);
			sendPrstGrpModalRowItem_B(*(&indexFile), 1, "პრესეტები", presetsAllowed);
			sendInfraGrpModalRowItem_B(*(&indexFile), 1, "Infra ", infraRedAllowed);




			break;


		}
		case 1:
		{

			for (uint8_t n = 0; n < ActiveSwitchersCount; n++)
				//for (uint8_t n=0; n < 2; n++)
			{
				//sendRowItemModal( *(& cl), n, n, switcher[n].lbl,switcher[n].enable);
				sendSwitcherRowItemModalB_(*(&indexFile), n);

			}

			if (presetsAllowed)
				sendRowItemModal1_B_select(*(&indexFile), 1);



			break;
		}
		case 2:
		{

			for (uint8_t n = 0; n < 6; n++)
			{
				//sendRowItemModal( *(& cl), n, n, switcher[n].lbl,switcher[n].enable);
				_doOneMPresetInGroup2_B(*(&indexFile), n);

			}
			break;
		}

		case 3:
		{

				//sendRowItemModal( *(& cl), n, n, switcher[n].lbl,switcher[n].enable);
			//sendHtrGrpModalRowItemB(*(&indexFile), 0, "მომხმარებელი", false);

			//sendGrpModalRowItem_(*(&indexFile), 0, "ModalTabUserRow1", 1, "current user", false);
			//sendGrpModalRowItem_(*(&indexFile), 0, "ModalTabUserRow2", 2, "new user", true);
			//sendGrpModalRowItem_(*(&indexFile), 0, "ModalTabUserRow3", 3, "current pass", true);
			//sendGrpModalRowItem_(*(&indexFile), 0, "ModalTabUserRow4", 4, "new pass", true);
			
			
			//sendPrstGrpModalRowItem_B(*(&indexFile), 1, "ძველი პაროლი", false);
			//sendPrstGrpModalRowItem_B(*(&indexFile), 2, "ახალი პაროლი", false);



			break;
		}





		}

		indexFile->print(F("\t\t\t\t\t</div>\t<!-- class=\"row\" -->\n"));
		indexFile->print(F("\t\t\t\t\t</div>\t<!-- role=\"tabpanel\" -->\n\n\n\n"));
	}











	indexFile->print(F("\t\t\t\t</div>\t<!-- class=\"tab-content\" -->\n"));





	indexFile->print(F("\t\t</div>\t<!-- role=\"tabpanel\" -->\n\n"));

	indexFile->print(F("\t\t<div class=\"modal-footer\">\n"));

	indexFile->print(F("\t\t<button type=\"button\" id=\"modalSaveBtn\" class=\"btn btn-secondary btn-lg btn-block\" onClick=\"modalSaveBtnClick()\">Save</button>\n"));
	indexFile->print(F("\t\t<button type=\"button\" id=\"modalCloseBtn\" class=\"btn btn-secondary btn-lg btn-block\" data-dismiss=\"modal\">Close</button>\n"));
	
	/*
	
	indexFile->println(F("\t<div class = \"dropdown\">"));
	indexFile->print(F("\t<button class = \"btn btn-default dropdown-toggle\" type = \"button\" id = \"menu1\" data - toggle = \"dropdown\">save as preset"));
	indexFile->println(F("\t<span class = \"caret\"></span></button>"));
	indexFile->println(F("\t<ul class = \"dropdown-menu\" role = \"menu\" aria - labelledby = \"menu1\">"));
	indexFile->println(F("\t<li role = \"presentation\"><a role = \"menuitem\" tabindex = \"-1\" href = \"#\">HTML</a></li>"));
	indexFile->println(F("\t<li role = \"presentation\"><a role = \"menuitem\" tabindex = \"-1\" href = \"#\">CSS</a></li>"));
	indexFile->println(F("\t<li role = \"presentation\"><a role = \"menuitem\" tabindex = \"-1\" href = \"#\">JavaScript</a></li>"));
	indexFile->println(F("\t<li role = \"presentation\" class = \"divider\"></li>"));
	indexFile->println(F("\t<li role = \"presentation\"><a role = \"menuitem\" tabindex = \"-1\" href = \"#\">About Us</a></li>"));
	indexFile->println(F("\t</ul>"));
	indexFile->println(F("\t</div>"));
	
	
	*/
	
	indexFile->print(F("\t\t</div>\n"));

	indexFile->print(F("\t\t</div>\t<!-- class=\"modal-content\" -->\n"));
	indexFile->print(F("\t\t</div>\t<!-- class=\"modal-dialog\" -->\n"));
	indexFile->print(F("\t\t</div>\t<!-- id=\"basicModal\" -->\n"));







	indexFile->print(F("<!------------------------------------------ MODAL FORM -----------------------------------------------------  END  ---------------->\n"));
}

/*

void sendRowItemModal(EthernetClient * cl, uint8_t i, uint8_t n, String lbl, bool isEnable )
{

			cl->print(F("\t\t\t\t\t\t<div id=\"mitem"));
			cl->print(String(switcher[i].extenderChipNum));
			cl->print(F("_"));
			cl->print(String(switcher[i].extenderChipPinNum));

			cl->print(F("\" style=\"display: block\" class=\"col-md-12 col-sm-12\">\n"));
			cl->print(F("\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">\n"));
			cl->print(F("\t\t\t\t\t\t\t\t<div class=\"input-group input-group-lg\">\n"));



			cl->print(F("\t\t\t\t\t\t\t\t\t<span class=\"input-group-addon\" id=\"iga"));
			cl->print(String(switcher[i].extenderChipNum));
			cl->print(F("_"));
			cl->print(String(switcher[i].extenderChipPinNum));
			cl->print(F("\" onClick=\"mSend_OnClick("));
			cl->print(String(switcher[i].extenderChipNum));
			cl->print(F("_"));
			cl->print(String(switcher[i].extenderChipPinNum));
			cl->print(F(")\">"));
			cl->print(switcher[i].id);

			cl->print(F("</span>\n"));




			cl->print(F("\t\t\t\t\t\t\t\t\t<input id=\"msw"));
			cl->print(String(switcher[i].extenderChipNum));
			cl->print(F("_"));
			cl->print(String(switcher[i].extenderChipPinNum));

			cl->print(F("\" type=\"text\" maxlength=\"10\" class=\"form-control\" value=\""));
			cl->print(lbl);
//			cl->print(SwitchWeblabel[i][n]);

//			cl->print(F("\" aria-describedby=\"iga"));
//			cl->print(String(switcher[i].extenderChipNum));
//			cl->print(F("_"));
//			cl->print(String(switcher[i].extenderChipPinNum));

			cl->print(F("\" onkeypress=\"mcatch13Key(event,"));
			cl->print(String(switcher[i].extenderChipNum));
			cl->print(F("_"));
			cl->print(String(switcher[i].extenderChipPinNum));
			cl->print(F(")\">\n"));



			cl->print(F("\t\t\t\t\t\t\t\t\t<span class=\"input-group-addon\">\n"));
			cl->print(F("\t\t\t\t\t\t\t\t\t<input type=\"checkbox\" id=\"mChBx"));

			cl->print(String(switcher[i].extenderChipNum));
			cl->print(F("_"));
			cl->print(String(switcher[i].extenderChipPinNum));
			cl->print(F("\" "));
			cl->print(F("onClick=\""));
			cl->print(F("mChbx_OnClick(this, "));
			cl->print(String(switcher[i].extenderChipNum));
			cl->print(F("_"));
			cl->print(String(switcher[i].extenderChipPinNum));
			cl->print(F(")\" "));



			if (isEnable)
			//if (SwitchWebVisible[i][n])
			cl->print(F("checked "));

			cl->print(F("aria-label=\"...\">\n"));



			cl->print(F("\t\t\t\t\t\t\t\t\t</span>\n"));



			cl->print(F("\t\t\t\t\t\t\t\t</div>\t <!-- class=\"input-group input-group-lg\" -->\n"));
			cl->print(F("\t\t\t\t\t\t\t</div>\t <!-- class=\"div-text-and-btn-frame\" -->\n"));



			cl->print(F("\t\t\t\t\t\t</div>\t<!-- id=\"mitem\""));
			cl->print(String(switcher[i].extenderChipNum));
			cl->print(F("_"));
			cl->print(String(switcher[i].extenderChipPinNum));
			cl->print(F("\" -->\n\n"));

}
*/


void sendGroupRowItemModalB(File * indexFile, uint8_t i, String lbl, bool isEnable)
{

	indexFile->print(F("\t\t\t\t\t\t<div id=\"mgrp"));
	indexFile->print(String(i));

	indexFile->print(F("\" style=\"display: block\" class=\"col-md-12 col-sm-12\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t<div class=\"input-group input-group-lg\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t<span class=\"input-group-addon\" id=\"igagrp"));
	indexFile->print(String(i));
//	indexFile->print(F("\" onClick=\"mGrpSend_OnClick("));
//	indexFile->print(String(i));
//	indexFile->print(F(")\">"));
	indexFile->print(F("\">"));


	indexFile->print(group[i].id);
	indexFile->print(F("</span>\n"));




	indexFile->print(F("\t\t\t\t\t\t\t\t\t<input id=\"mGrpLbl"));
	indexFile->print(String(i));

	indexFile->print(F("\" type=\"text\" maxlength=\"15\" class=\"form-control\" value=\""));
	indexFile->print(lbl);
	//			indexFile->print(SwitchWeblabel[i][n]);
//	indexFile->print(F("\" aria-describedby=\"iga"));
//	indexFile->print(String(i));

	indexFile->print(F("\" onkeyPress=\"mGrpLblcatch13Key(event,"));
	indexFile->print(String(i));

	indexFile->print(F(")\" onfocusout=\"mGrpLblonfocusout(this,"));
	indexFile->print(String(i));
	indexFile->print(F(")\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t<span class=\"input-group-addon\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t\t<input type=\"checkbox\" id=\"mGrpChBx"));

	indexFile->print(String(i));
	indexFile->print(F("\" "));
	indexFile->print(F("onClick=\""));
	indexFile->print(F("mGrpChbx_OnClick(this, "));
	indexFile->print(String(i));
	indexFile->print(F(")\" "));



	if (isEnable)
		//if (SwitchWebVisible[i][n])
		indexFile->print(F("checked "));

	indexFile->print(F("aria-label=\"...\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t</span>\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t</div>\t <!-- class=\"input-group input-group-lg\" -->\n"));
	indexFile->print(F("\t\t\t\t\t\t\t</div>\t <!-- class=\"div-text-and-btn-frame\" -->\n"));



	indexFile->print(F("\t\t\t\t\t\t</div>\t<!-- id=\"mgrp\""));
	indexFile->print(String(i));
	indexFile->print(F("\" -->\n\n"));

}




void sendSwitcherRowItemModalB_(File * indexFile, uint8_t i)
{

	indexFile->print(F("\t\t\t\t\t\t<div id=\"mitem"));
	indexFile->print(switcher[i].id);
	//indexFile->print(String(switcher[i].extenderChipNum));
	//indexFile->print(String(switcher[i].extenderChipPinNum));

	indexFile->print(F("\" style=\"display: block\" class=\"col-md-12 col-sm-12\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t<div class=\"input-group input-group-lg\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t<span class=\"input-group-addon\" id=\"iga"));
	indexFile->print(switcher[i].id);
//	indexFile->print(String(switcher[i].extenderChipNum));
//	indexFile->print(String(switcher[i].extenderChipPinNum));
	
	indexFile->print(F("\" onClick=\"miga_OnClick("));
	indexFile->print(switcher[i].id);



//	indexFile->print(String(switcher[i].extenderChipNum));
//	indexFile->print(F(","));
//	indexFile->print(String(switcher[i].extenderChipPinNum));

	indexFile->print(F(")\">"));
	//indexFile->print("#" + String(i));
	indexFile->print(switcher[i].id);
	//indexFile->print(TMP_STRING1 = ((i < 10) ? TMP_STRING1 = "#0" + String(i) : TMP_STRING1 = "#" + String(i)));

	indexFile->print(F("</span>\n"));
	//indexFile->printf("%02d",i));




	indexFile->print(F("\t\t\t\t\t\t\t\t\t<input id=\"msw"));
	indexFile->print(switcher[i].id);
	//indexFile->print(String(switcher[i].extenderChipNum));
	//indexFile->print(String(switcher[i].extenderChipPinNum));

	indexFile->print(F("\" type=\"text\" maxlength=\"10\" class=\"form-control\" value=\""));
	indexFile->print(switcher[i].lbl);
	//			indexFile->print(SwitchWeblabel[i][n]);
//	indexFile->print(F("\" aria-describedby=\"iga"));
//	indexFile->print(String(switcher[i].extenderChipNum));	
//	indexFile->print(String(switcher[i].extenderChipPinNum));

	//indexFile->print(F("\" onkeypress=\"mcatch13Key(event,"));
	
	//indexFile->print(switcher[i].id);



	indexFile->print(F("\" onkeyPress=\"mGrpLblcatch13Key(event,"));
	indexFile->print(String(i));

	indexFile->print(F(")\" onfocusout=\"mGrpLblonfocusout(this,"));
	indexFile->print(String(i));
	indexFile->print(F(")\">\n"));

//	indexFile->print(String(switcher[i].extenderChipNum));
//	indexFile->print(F(","));
//	indexFile->print(String(switcher[i].extenderChipPinNum));
	
//	indexFile->print(F(")\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t<span class=\"input-group-addon\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t\t<input type=\"checkbox\" id=\"mChBx"));

	indexFile->print(switcher[i].id);

//	indexFile->print(String(switcher[i].extenderChipNum));
//	indexFile->print(String(switcher[i].extenderChipPinNum));
	
	indexFile->print(F("\" "));
	indexFile->print(F("onClick=\""));
	indexFile->print(F("mSwChbx_OnClick(this,"));

	indexFile->print(String(i));

//	indexFile->print(String(switcher[i].extenderChipNum));
//	indexFile->print(F(","));
//	indexFile->print(String(switcher[i].extenderChipPinNum));
	
	indexFile->print(F(")\" "));



	if (switcher[i].enable)
		//if (SwitchWebVisible[i][n])
		indexFile->print(F("checked "));

	indexFile->print(F("aria-label=\"...\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t</span>\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t</div>\t <!-- class=\"input-group input-group-lg\" -->\n"));
	indexFile->print(F("\t\t\t\t\t\t\t</div>\t <!-- class=\"div-text-and-btn-frame\" -->\n"));



	indexFile->print(F("\t\t\t\t\t\t</div>\t<!-- id=\"mitem\""));
	indexFile->print(switcher[i].id);

//	indexFile->print(String(switcher[i].extenderChipNum));
//	indexFile->print(String(switcher[i].extenderChipPinNum));
	
	indexFile->print(F("\" -->\n\n"));

}




void sendRowItemModal1_B_select(File * indexFile, uint8_t i)
{

	indexFile->print(F("\t\t\t\t\t\t<div id=\"mitemprselect"));
	indexFile->print(F("\" style=\"display: block\" class=\"col-md-12 col-sm-12\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t<div class=\"input-group input-group-lg\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t<span class=\"input-group-addon\" id=\"igaSelect\">"));

	//indexFile->print("#" + String(i));
	indexFile->print(F("შენახვა როგორც პრესეტი.."));

	indexFile->print(F("</span>\n"));
	//indexFile->printf("%02d",i));


	indexFile->print(F("\t\t\t\t\t\t\t\t\t<select class=\"custom-select\" id=\"mPrstSelect\" style=\"width:100%; height:100%\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t\t\t\t<option selected=\"\">აირჩიეთ პრესეტის სახელი</option>\n"));

	for (i = 0; i < 6; i++)
	{
		indexFile->print(F("\t\t\t\t\t\t\t\t\t\t\t<option value=\""));
		indexFile->print(String(i));
		indexFile->print(F("\">"));
		indexFile->print(preset[i].lbl);
		indexFile->print(F("</option>\n"));
	}

	indexFile->print(F("\t\t\t\t\t\t\t\t\t</select>\n"));






	indexFile->print(F("\t\t\t\t\t\t\t\t</div>\t <!-- class=\"input-group input-group-lg\" -->\n"));
	indexFile->print(F("\t\t\t\t\t\t\t</div>\t <!-- class=\"div-text-and-btn-frame\" -->\n"));



	indexFile->print(F("\t\t\t\t\t\t</div>\t<!-- id=\"mitemprselect\" -->\n\n"));

}

void _doOneMPresetInGroup2_B(File * indexFile, uint8_t n)
{
	//aria-describedby=\"inputGroup-sizing-sm\"
	indexFile->println(F("\t\t\t\t\t\t\t<div class=\"col-lg-2 col-md-4 col-sm-6\">"));
	indexFile->println(F("\t\t\t\t\t\t\t\t<div class=\"input-group-prepend\">"));
	indexFile->print(F("\t\t\t\t\t\t\t\t\t<input type=\"text\" maxlength=\"10\" class=\"form-control\" aria-label=\"Small\" id=\"mprst"));
	indexFile->print(String(n));
	indexFile->print(F("_txt\" value=\""));
	indexFile->print(preset[n].lbl);
	indexFile->print(F("\""));
	if (!preset[n].enable)
		indexFile->print(F(" disabled"));
	indexFile->println(F(">"));

	//id=\"inputGroup-sizing-sm\"
	indexFile->println(F("\t\t\t\t\t\t\t\t\t<span class=\"input-group-text\">"));
	indexFile->print(F("\t\t\t\t\t\t\t\t\t<button type=\"button\" class=\"btn btn-block btn-lg btn-default\" onClick=\"mPrst_OnClick(this,"));
	indexFile->print(String(n));
	indexFile->print(F(")\" id=\"mprst"));
	indexFile->print(String(n));
	indexFile->print(F("_lbl\""));
	if (!preset[n].enable)
		indexFile->print(F(" disabled"));
	indexFile->print(F(">"));
	indexFile->print(F("set"));
	indexFile->println(F("</button>"));

	indexFile->println(F("\t\t\t\t\t\t\t\t\t</span>"));
	indexFile->println(F("\t\t\t\t\t\t\t\t</div>"));
	indexFile->println(F("\t\t\t\t\t\t\t</div>"));

}



void sendPrstGrpModalRowItem_B(File * indexFile, uint8_t i, String lbl, bool isEnable)
{

	indexFile->print(F("\t\t\t\t\t\t<div id=\"mGrpPrst"));


	indexFile->print(F("\" style=\"display: block\" class=\"col-md-12 col-sm-12\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t<div class=\"input-group input-group-lg\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t<span class=\"input-group-addon\" id=\"igamGrpPrst"));
	//indexFile->print(String(i));
	indexFile->print(F("\" onClick=\"mGrpPrstSend_OnClick("));
	indexFile->print(F("this"));
	indexFile->print(F(")\">"));
	indexFile->print(F("grp09</span>\n"));




	indexFile->print(F("\t\t\t\t\t\t\t\t\t<input id=\"mGrpPrstlbl"));
	//indexFile->print(String(i));

	indexFile->print(F("\" type=\"text\" maxlength=\"10\" readonly class=\"form-control\" value=\""));
	indexFile->print(lbl);
	//			indexFile->print(SwitchWeblabel[i][n]);
//	indexFile->print(F("\" aria-describedby=\"iga"));
//	indexFile->print(String(i));

	indexFile->print(F("\" onKeyUp=\"mGrpPrstCatchKeyUP("));
	indexFile->print(String(i));
	indexFile->print(F(")\" onkeyPress=\"mGrpPrstCatch13Key(event,"));
	indexFile->print(String(i));

	indexFile->print(F(")\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t<span class=\"input-group-addon\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t\t<input type=\"checkbox\" id=\"mGrpPrstChBx"));

	//indexFile->print(String(i));
	indexFile->print(F("\" "));
	indexFile->print(F("onClick=\""));
	indexFile->print(F("mGrpPrstChbx_OnClick(this, "));
	indexFile->print(String(i));
	indexFile->print(F(")\" "));



	if (presetsAllowed)
		//if (SwitchWebVisible[i][n])
		indexFile->print(F("checked aria-label=\"...\">\n"));
	else
		indexFile->print(F("disabled aria-label=\"...\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t</span>\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t</div>\t <!-- class=\"input-group input-group-lg\" -->\n"));
	indexFile->print(F("\t\t\t\t\t\t\t</div>\t <!-- class=\"div-text-and-btn-frame\" -->\n"));



	indexFile->print(F("\t\t\t\t\t\t</div>\t<!-- id=\"mGrpPrst\""));
	//indexFile->print(String(i));
	indexFile->print(F("\" -->\n\n"));

}



void sendInfraGrpModalRowItem_B(File * indexFile, uint8_t i, String lbl, bool isEnable)
{

	indexFile->print(F("\t\t\t\t\t\t<div id=\"mGrpInfra"));


	indexFile->print(F("\" style=\"display: block\" class=\"col-md-12 col-sm-12\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t<div class=\"input-group input-group-lg\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t<span class=\"input-group-addon\" id=\"igamGrpInfra"));
	//indexFile->print(String(i));
	indexFile->print(F("\" onClick=\"mGrpInfraSend_OnClick("));
	indexFile->print(F("this"));
	indexFile->print(F(")\">"));
	indexFile->print(F("grp10</span>\n"));




	indexFile->print(F("\t\t\t\t\t\t\t\t\t<input id=\"mGrpInfralbl"));
	//indexFile->print(String(i));

	indexFile->print(F("\" type=\"text\" maxlength=\"10\" readonly class=\"form-control\" value=\""));
	indexFile->print(lbl);
	//			indexFile->print(SwitchWeblabel[i][n]);
//	indexFile->print(F("\" aria-describedby=\"iga"));
//	indexFile->print(String(i));

	indexFile->print(F("\" onKeyUp=\"mGrpInfraCatchKeyUP("));
	indexFile->print(String(i));
	indexFile->print(F(")\" onkeyPress=\"mGrpInfraCatch13Key(event,"));
	indexFile->print(String(i));

	indexFile->print(F(")\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t<span class=\"input-group-addon\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t\t<input type=\"checkbox\" id=\"mGrpInfraChBx"));

	indexFile->print(String(i));
	indexFile->print(F("\" "));
	indexFile->print(F("onClick=\""));
	indexFile->print(F("mGrpInfraChbx_OnClick(this, "));
	indexFile->print(String(i));
	indexFile->print(F(")\" "));



	if (infraRedAllowed)
		//if (SwitchWebVisible[i][n])
		indexFile->print(F("checked aria-label=\"...\">\n"));
	else
		indexFile->print(F("disabled aria-label=\"...\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t</span>\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t</div>\t <!-- class=\"input-group input-group-lg\" -->\n"));
	indexFile->print(F("\t\t\t\t\t\t\t</div>\t <!-- class=\"div-text-and-btn-frame\" -->\n"));



	indexFile->print(F("\t\t\t\t\t\t</div>\t<!-- id=\"mGrpInfra\""));
	//indexFile->print(String(i));
	indexFile->print(F("\" -->\n\n"));

}

void sendHtrGrpModalRowItemB(File * indexFile, uint8_t i, String lbl, bool isEnable)
{

	indexFile->print(F("\t\t\t\t\t\t<div id=\"mGrpHtr"));


	indexFile->print(F("\" style=\"display: block\" class=\"col-md-12 col-sm-12\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t<div class=\"input-group input-group-lg\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t<span class=\"input-group-addon\" id=\"igamGrpHtr"));
	//indexFile->print(String(i));
	indexFile->print(F("\" onClick=\"mGrpHtrSend_OnClick("));
	indexFile->print(F("this"));
	indexFile->print(F(")\">"));
	indexFile->print(F("grp08</span>\n"));




	indexFile->print(F("\t\t\t\t\t\t\t\t\t<input id=\"mGrpHtrlbl"));
	//indexFile->print(String(i));

	indexFile->print(F("\" type=\"text\" maxlength=\"10\" readonly class=\"form-control\" value=\""));
	indexFile->print(lbl);
	//			indexFile->print(SwitchWeblabel[i][n]);
	//	indexFile->print(F("\" aria-describedby=\"iga"));
	//	indexFile->print(String(i));

	indexFile->print(F("\" onKeyUp=\"mGrpHtrCatchKeyUP("));
	indexFile->print(String(i));
	indexFile->print(F(")\" onkeyPress=\"mGrpHtrCatch13Key(event,"));
	indexFile->print(String(i));

	indexFile->print(F(")\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t<span class=\"input-group-addon\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t\t<input type=\"checkbox\" id=\"mGrpHtrChBx"));

	//indexFile->print(String(i));
	indexFile->print(F("\" "));
	indexFile->print(F("onClick=\""));
	indexFile->print(F("mGrpHtrChbx_OnClick(this, "));
	indexFile->print(String(i));
	indexFile->print(F(")\" "));



	if (heaterAllowed)
		//if (SwitchWebVisible[i][n])
		indexFile->print(F("checked aria-label=\"...\">\n"));
	else
		indexFile->print(F("disabled aria-label=\"...\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t</span>\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t</div>\t <!-- class=\"input-group input-group-lg\" -->\n"));
	indexFile->print(F("\t\t\t\t\t\t\t</div>\t <!-- class=\"div-text-and-btn-frame\" -->\n"));



	indexFile->print(F("\t\t\t\t\t\t</div>\t<!-- id=\"mGrpHtr\""));
	//indexFile->print(String(i));
	indexFile->print(F("\" -->\n\n"));

}




void sendGrpModalRowItem_(File * indexFile, uint8_t i, String divId, uint8_t RowIndex, String Lbl, bool isEnable)
{

	indexFile->print(F("\t\t\t\t\t\t<div id=\""));
	indexFile->print(divId);
	indexFile->print(F("\""));
		


	indexFile->print(F(" style=\"display: block\" class=\"col-md-12 col-sm-12\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t<div class=\"div-text-and-btn-frame\">\n"));
	indexFile->print(F("\t\t\t\t\t\t\t\t<div class=\"input-group input-group-lg\">\n"));



	indexFile->print(F("\t\t\t\t\t\t\t\t\t<span class=\"input-group-addon\" id=\"ModaltabUserR"));
	indexFile->print(String(RowIndex));
	indexFile->print(F("C1\">"));
	indexFile->print(Lbl);
	indexFile->print(F("</span>\n"));




	indexFile->print(F("\t\t\t\t\t\t\t\t\t<input id=\"ModaltabUserR"));
	indexFile->print(String(RowIndex));
	indexFile->print(F("C2\" type=\"text\" maxlength=\"10\" class=\"form-control\" value=\"\""));
	indexFile->print(" ");
	//			indexFile->print(SwitchWeblabel[i][n]);
	//	indexFile->print(F("\" aria-describedby=\"iga"));
	//	indexFile->print(String(i));

	if (!isEnable)
		indexFile->print(F(" readonly>"));
	else
	{
		indexFile->print(F(" onKeyUp=\"ModaltabUserR"));
		indexFile->print(String(RowIndex));
		indexFile->print(F("C2catchKeyUP("));



		indexFile->print(String(i));
		indexFile->print(F(")\" onkeyPress=\"ModaltabUserR"));
		indexFile->print(String(RowIndex));
		indexFile->print(F("C2catchKeyPress(event,"));

		indexFile->print(String(i));

		indexFile->print(F(")\">\n"));
	}






	indexFile->print(F("\t\t\t\t\t\t\t\t</div>\t <!-- class=\"input-group input-group-lg\" -->\n"));
	indexFile->print(F("\t\t\t\t\t\t\t</div>\t <!-- class=\"div-text-and-btn-frame\" -->\n"));



	indexFile->print(F("\t\t\t\t\t\t</div>\t<!-- id=\""));
	indexFile->print(divId);
	indexFile->print(F("\" -->\n\n"));

}
