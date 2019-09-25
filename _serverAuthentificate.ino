

void a3_to_a4(unsigned char * a4, unsigned char * a3);
void a4_to_a3(unsigned char * a3, unsigned char * a4);

//unsigned char b64_lookup(char c);

int base64_encode(char *output, char *input, int inputLen) {
	const char b64_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	int i = 0, j = 0, encLen = 0;
	unsigned char a3[3], a4[4];

	while (inputLen--) {
		a3[i++] = *(input++);
		if (i == 3) {
			a3_to_a4(a4, a3);
			for (i = 0; i < 4; i++) { output[encLen++] = b64_alphabet[a4[i]]; }
			i = 0;
		}
	}

	if (i) {
		for (j = i; j < 3; j++) { a3[j] = '\0'; }
		a3_to_a4(a4, a3);
		for (j = 0; j < i + 1; j++) { output[encLen++] = b64_alphabet[a4[j]]; }
		while ((i++ < 3)) { output[encLen++] = '='; }
	}
	output[encLen] = '\0';
	return encLen;
}


void a3_to_a4(unsigned char * a4, unsigned char * a3) {
	a4[0] = (a3[0] & 0xfc) >> 2;
	a4[1] = ((a3[0] & 0x03) << 4) + ((a3[1] & 0xf0) >> 4);
	a4[2] = ((a3[1] & 0x0f) << 2) + ((a3[2] & 0xc0) >> 6);
	a4[3] = (a3[2] & 0x3f);
}

/*
unsigned char b64_lookup(char c) {
  if(c >='A' && c <='Z') return c - 'A';
  if(c >='a' && c <='z') return c - 71;
  if(c >='0' && c <='9') return c + 4;
  if(c == '+') return 62;
  if(c == '/') return 63;
  return -1;
}
*/

boolean check_Auto_HASH(String request)
{
	//SERIALPRINTLN("check_Auto_HASH");
	//SERIALPRINTLN(request);


	// #ifdef DEBUG_SERIAL_base64
	//   printFunctionTrace("check_Auto_HASH", 1);
	// #endif


	bool TmpBool = false;

	//TmpStringVar.reserve(35);
	for (uint8_t i = 0; i < REGISTERED_USER_COUNT; i++)
	{

		/*
		 *     if ((user[i].length() == 0) || (passw[i].length() == 0))
			{
			   #ifdef DEBUG_SERIAL_base64
						SPrint(F("\nblank user or Password:\t"));

			   #endif
			   TmpBool = false;
			   break;
			}
			*/

		TMP_STRING1 = validate_user(user[i], passw[i]);

#ifdef DEBUG_SERIAL_base64    
		SPrint(F("\ncheck_Auto_HASH in...\t\n"));
		SPrint(request);


#endif        

		if (request.lastIndexOf("Authorization: Basic " + TMP_STRING1) > -1)
		{

#ifdef DEBUG_SERIAL_base64    
			SPrint(F("\ncheck_Auto_HASH\tuser:\t"));
			SPrint(user[i]);
			SPrint(F("\tpassword:\t"));
			SPrint(passw[i]);
			SPrint(F("\tencoded:\t"));
			SPrint(TmpStringVar);


#endif        

			TmpBool = true;
			currentUser = user[i];
			break;
		}
	}


	//#ifdef DEBUG_SERIAL_base64
	//  printFunctionTrace("check_Auto_HASH", 0);
	//#endif


	return TmpBool;
}

String validate_user(String user, String passw)
//boolean validate_user(char * data)
{


	//#ifdef DEBUG_SERIAL_base64
	// printFunctionTrace("validate_user", 1);
	//#endif

	char user_and_passw[] = "Admin:SmartHome";

	userandpassw = user + ':' + passw;

#ifdef DEBUG_SERIAL_base64    
	SPrint(F("\nvalidate_user\tuser:\t"));
	SPrint(user);
	SPrint(F("\tpassword:\t"));
	SPrint(passw);
#endif

	//user_and_passw = user + passw;


	userandpassw.toCharArray(user_and_passw, userandpassw.length() + 1);
	int t = strlen(user_and_passw);

	int tamanhoEnc = (((t - 1) / 3) + 1) * 4;   //tamanho da string codificada // for encoding the string;
	//int tamanhoEnc = (((t-1) / 3) + 1) * 2;   //tamanho da string codificada // for encoding the string;
	char out[tamanhoEnc];
	base64_encode(out, user_and_passw, t + 1);

#ifdef DEBUG_SERIAL_base64
	SPrint(F("\tuser_and_passw:\t"));
	SPrint(user_and_passw);
	SPrint(F("\tout:\t"));
	SPrint(out);

#endif

	//---desconta � usado pra eliminar os caracteres '=' Variable used for excluding Chars
	int desconta = 0;
	if ((t % 3) == 1) { desconta = 2; }
	if ((t % 3) == 2) { desconta = 1; }

	char out2[tamanhoEnc - desconta];

	byte i;
	for (i = 0; i < (tamanhoEnc - desconta); i++) { out2[i] = out[i]; }
	out2[i] = '\0';

	//  SPrint(user + "\t" + passw + "\t" + out2 +"\n");                         
	//  SPrint(String(data) +"\n");                         

#ifdef DEBUG_SERIAL_base64    
	SPrint(F("\tencoded:\t"));
	SPrint(out2);
#endif



#ifdef DEBUG_SERIAL_base64
	printFunctionTrace("validate_user", 0);
#endif


	return out2;
}
