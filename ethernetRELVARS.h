
      #define ETHERNET_SELECT_PIN 10
      #define SDCARD_SELECT_PIN 4
	  boolean isSdOK = false;

      
      byte SERVER_MAC[] = { 0x00, 0x2A, 0xF5, 0x12, 0x67, 0xFA };
      byte SERVER_IP[] = { 192, 168, 50, 100 };
      uint16_t SERVER_PORT = 8188;
      uint8_t WEB_IMPULSE_DURATION = 50 ;

	  EthernetServer server(SERVER_PORT);
	  unsigned long connectTime[MAX_SOCK_NUM];
	  unsigned long thisTime = millis();

	  //EthernetClient client;


	  //unsigned int requestNumber = 0;

	  //unsigned long connectTime[MAX_SOCK_NUM];
      
	  
	  // free sockets
      #define FREE_SOCKETS_ZERO 0
      #define FREE_SOCKETS_ONE  1
      //#define FREE_SOCKETS_THREE  3
      byte freeSockets = FREE_SOCKETS_ONE;
	  
    // Authorization
    #define REGISTERED_USER_COUNT 3

    String user[REGISTERED_USER_COUNT] = {
	    "admin",
	    "demo",
		"user2"
    };
    
    String passw[REGISTERED_USER_COUNT] = {
	    "nikanika",
		"demo",
		"user2"
    };

    
    #define AUTH_OFF 0
    #define AUTH_ON  1
    byte authMode = AUTH_OFF;
    // Online encode to Base64: base64encode.org
    String AUTH_HASH = "Authorization: Basic YWRtaW46YW1z"; // admin:ams
    String currentUser = "";
    String userandpassw;
	
	 char serverVersion[4] = "ABC";
	 String sysMsg = "";


boolean dndEnable = true;			// Drug&Drop Enable on the site

#define REQ_BUF_SIZE 256//384
//char HTTP_req[REQ_BUF_SIZE] = { 0 }; // null terminated string
uint16_t reqIndex = 0;

// String request
#define MAX_LEN_STRING 128
String Buffrequest = "";

   #define MAX_BUFFER_SIZE 512
	//#define MAX_BUFFER_SIZE 2048
   uint16_t rsize;
   uint8_t buff[MAX_BUFFER_SIZE];
   
   #define GET           "GET /"
