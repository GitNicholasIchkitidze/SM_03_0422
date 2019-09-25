
#define ETHERNET_SELECT_PIN 10
#define SDCARD_SELECT_PIN 4

// Serial Sender Information
unsigned char START_BYTE = 0x53; // ASCII "S"
unsigned char counterValue = 0;
unsigned char staticValue = 0;
unsigned char checksum = 0;

// Serial Sync Byte flag
boolean syncByteFound = 0;

typedef struct {
	bool SerialEventSuccess;
	unsigned char receivedData;
} serialEventStruct;


serialEventStruct serialEvent;


uint8_t ActiveGroupsCount = 8;
uint8_t ActiveSwitchersCount = 32;

typedef struct  {
  String id;
  uint8_t group;
  uint8_t extenderChipNum;
  uint8_t extenderChipPinNum;
  uint8_t ControllerPinNum;
  bool state;
  bool enable;
  String lbl;
  
} switcherItemStruct;

typedef struct  {
	String id;	
//	uint8_t ControllerPinNum;
	bool enable;
	String lbl;
	
} groupItemStruct;


typedef struct  {
	String vvarName;
	String vvarValue;
	
} variableAndValue;

typedef struct  {
	String id;
	String lbl;
	boolean enable;
	//char states[32];
	String states;
	
} presetItemtruct;



switcherItemStruct switcher[32];
groupItemStruct group[8];
presetItemtruct preset[6];

//File FileIn_SD_filetype;
//char FileIn_SD_chartype[12];
//char *FileIn_SD_Chartype;


// TIMING
uint32_t startTime;
uint32_t stopTime;

String TMP_STRING1 ="";
String TMP_STRING2 ="";
String TMP_STRING3 = "";
String TMP_STRING_LOCAL ="";


boolean heaterAllowed = false;
boolean infraRedAllowed = false;
uint8_t infraRedCmdCount = 0;
boolean presetsAllowed = false;
boolean reIndexFile = true;
String reIndexFileName = "none";
//boolean presetEnabled = true;

boolean useCloud = true;
boolean useI2C = true;
boolean useSerialComm = false;
boolean useIFTTT = false;
	  
String cloudAddress = "chkviani.ge/ard";
String userAgent1 = "002AF51267FA";
String userAgent2 = "002AF51267FA";
String userCookie = "002AF51267FA";

boolean userFromAPP = false;


// Modules
#define MODULE_DISABLE 0
#define MODULE_ENABLE  1
#define NOT_COMPILLED  2
byte moduleNtp = NOT_COMPILLED;


// Time
#define TIME_NONE    0
#define TIME_NETWORK 1
#define TIME_RTC     2
byte timeProvider = TIME_NETWORK;

bool cycle1s = false;
bool cycle5s = false;
bool cycle20s = false;
bool cycle30s = false;
bool cycle1m = false;
bool cycle3m = false;
bool cycle5m = false;

// Time Stamp

//#define STAMP_MILLIS
unsigned long stampMarker = 0;
bool printTimeStamp = false;



//String dataJsonLine = "";

//switcherItemStruct currSwitcher;
