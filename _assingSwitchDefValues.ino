void _assignDefValuesToSwitches(boolean TraceLog=false)
{
		
		_printFuncAndMemTrace( 'I', __FUNCTION__, TraceLog);
		

	//id, ControllerPinNum, enable, lbl;
/*	
typedef struct  {
	String id;
	String lbl;
	boolean enable;
	String states;
	
} presetItemtruct;


*/

/*
	preset[0] = (presetItemtruct) {F("preset0"), false, F("")};
	preset[1] = (presetItemtruct) {F("preset1"), false, F("")};
	preset[2] = (presetItemtruct) {F("preset2"), false, F("")};
	preset[3] = (presetItemtruct) {F("preset3"), false, F("")};
	preset[4] = (presetItemtruct) {F("preset4"), false, F("")};
	preset[5] = (presetItemtruct) {F("preset5"), false, F("")};
	*/
	
	preset[0] = (presetItemtruct) { F("prst0"), F("preset0"), false, F("") };
	preset[1] = (presetItemtruct) { F("prst1"), F("preset1"), false, F("") };
	preset[2] = (presetItemtruct) { F("prst2"), F("preset2"), false, F("") };
	preset[3] = (presetItemtruct) { F("prst3"), F("preset3"), false, F("") };
	preset[4] = (presetItemtruct) { F("prst4"), F("preset4"), false, F("") };
	preset[5] = (presetItemtruct) { F("prst5"), F("preset5"), false, F("") };
	
	
	group[0] = (groupItemStruct) {F("grp0"), true, F("ჯგუფი 0")};
	group[1] = (groupItemStruct) {F("grp1"), true, F("ჯგუფი 1")};
	group[2] = (groupItemStruct) {F("grp2"), true, F("ჯგუფი 2")};
	group[3] = (groupItemStruct) {F("grp3"), true, F("ჯგუფი 3")};		
	group[4] = (groupItemStruct) {F("grp4"), true, F("ჯგუფი 4")};
	group[5] = (groupItemStruct) {F("grp5"), true, F("ჯგუფი 5")};
	group[6] = (groupItemStruct) {F("grp6"), true, F("ჯგუფი 6")};
	group[7] = (groupItemStruct) {F("grp7"), true, F("ჯგუფი 7")};
		
		
//{id, group, extenderChipNum, extenderChipPinNum, ControllerPinNum,  state, enable, lbl}


		

	switcher[0]  = (switcherItemStruct) {F("00"), 0, 0, 0, 46, false, true, F("46")};
	switcher[1]  = (switcherItemStruct) {F("01"), 0, 0, 1, 47, false, true, F("47")};
	switcher[2]  = (switcherItemStruct) {F("02"), 0, 0, 2, 48, false, true, F("48")};	
	switcher[3]  = (switcherItemStruct) {F("03"), 0, 0, 3, 49, false, true, F("49")};		
	switcher[4]  = (switcherItemStruct) {F("04"), 1, 0, 4, 17, false, true, F("17")};		
	switcher[5]  = (switcherItemStruct) {F("05"), 1, 0, 5, 16, false, true, F("16")};		
	switcher[6]  = (switcherItemStruct) {F("06"), 1, 0, 6, 15, false, true, F("15")};		
	switcher[7]  = (switcherItemStruct) {F("07"), 1, 0, 7, 14, false, true, F("14")}; 

	switcher[8]  = (switcherItemStruct) {F("08"), 2, 1, 0, 22, false, true, F("22")};
	switcher[9]  = (switcherItemStruct) {F("09"), 2, 1, 1, 23, false, true, F("23")};
	switcher[10] = (switcherItemStruct) {F("10"), 2, 1, 2, 24, false, true, F("24")};
	switcher[11] = (switcherItemStruct) {F("11"), 2, 1, 3, 25, false, true, F("25")};
	switcher[12] = (switcherItemStruct) {F("12"), 3, 1, 4, 26, false, true, F("26")};
	switcher[13] = (switcherItemStruct) {F("13"), 3, 1, 5, 27, false, true, F("27")};
	switcher[14] = (switcherItemStruct) {F("14"), 3, 1, 6, 28, false, true, F("28")};
	switcher[15] = (switcherItemStruct) {F("15"), 3, 1, 7, 29, false, true, F("29")};

 	switcher[16] = (switcherItemStruct) {F("16"), 4, 2, 0, 30, false, true, F("30")};
 	switcher[17] = (switcherItemStruct) {F("17"), 4, 2, 1, 31, false, true, F("31")};
 	switcher[18] = (switcherItemStruct) {F("18"), 4, 2, 2, 32, false, true, F("32")};
 	switcher[19] = (switcherItemStruct) {F("19"), 4, 2, 3, 33, false, true, F("33")};
 	switcher[20] = (switcherItemStruct) {F("20"), 5, 2, 4, 34, false, true, F("34")};
 	switcher[21] = (switcherItemStruct) {F("21"), 5, 2, 5, 35, false, true, F("35")};
 	switcher[22] = (switcherItemStruct) {F("22"), 5, 2, 6, 36, false, true, F("36")};
 	switcher[23] = (switcherItemStruct) {F("23"), 5, 2, 7, 37, false, true, F("37")};

 	switcher[24] = (switcherItemStruct) {F("24"), 6, 3, 0, 38, false, true, F("38")};
 	switcher[25] = (switcherItemStruct) {F("25"), 6, 3, 1, 39, false, true, F("39")};
 	switcher[26] = (switcherItemStruct) {F("26"), 6, 3, 2, 40, false, true, F("40")};
 	switcher[27] = (switcherItemStruct) {F("27"), 6, 3, 3, 41, false, true, F("41")};
 	switcher[28] = (switcherItemStruct) {F("28"), 7, 3, 4, 42, false, true, F("42")};
 	switcher[29] = (switcherItemStruct) {F("29"), 7, 3, 5, 43, false, true, F("43")};
 	switcher[30] = (switcherItemStruct) {F("30"), 7, 3, 6, 44, false, true, F("44")};
 	switcher[31] = (switcherItemStruct) {F("31"), 7, 3, 7, 45, false, true, F("45")};


		#ifdef DEBUG_SERIAL_trace_FUNCandFREEMEM
				_printFuncAndMemTrace( 'O', __FUNCTION__, TraceLog);
		#endif


}
