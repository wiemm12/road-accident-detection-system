
const char simPIN[]   = "0000";
#define SMS_TARGET  "+21650193511"
#define TINY_GSM_MODEM_SIM800      // Modem is SIM800
#define TINY_GSM_RX_BUFFER   1024  // Set RX buffer to 1Kb
#include <TinyGPSPlus.h>
static const int RXPin = 15, TXPin = 2;
static const uint32_t GPSBaud = 9600;
// Create a TinyGPS++ object
TinyGPSPlus gps;

#include <Wire.h>
#include <TinyGsmClient.h>

#define MODEM_RST            5
#define MODEM_PWKEY          4
#define MODEM_POWER_ON       23
#define MODEM_TX             27
#define MODEM_RX             26
#define I2C_SDA              21
#define I2C_SCL              22


#define SerialMon Serial

#define SerialAT  Serial1


#ifdef DUMP_AT_COMMANDS
  #include <StreamDebugger.h>
  StreamDebugger debugger(SerialAT, SerialMon);
  TinyGsm modem(debugger);
#else
  TinyGsm modem(SerialAT);
#endif

#define IP5306_ADDR          0x75
#define IP5306_REG_SYS_CTL0  0x00

bool setPowerBoostKeepOn(int en){
  Wire.beginTransmission(IP5306_ADDR);
  Wire.write(IP5306_REG_SYS_CTL0);
  if (en) {
    Wire.write(0x37); 
  } else {
    Wire.write(0x35); 
  }
  return Wire.endTransmission() == 0;
}

void setup() {
  
  SerialMon.begin(115200);
  // Initialize the GPS module
SerialMon.println("Initializing GPS module...");
SerialAT.println("AT+CGNSPWR=1"); // Enable GPS power
delay(1000);
SerialAT.println("AT+CGNSSEQ=\"RMC\""); // Configure NMEA sentence
delay(1000);
SerialAT.println("AT+CGNSINF"); // Request GPS information
delay(1000);


  
  Wire.begin(I2C_SDA, I2C_SCL);
  bool isOk = setPowerBoostKeepOn(1);
  SerialMon.println(String("IP5306 KeepOn ") + (isOk ? "OK" : "FAIL"));

 
  pinMode(MODEM_PWKEY, OUTPUT);
  pinMode(MODEM_RST, OUTPUT);
  pinMode(MODEM_POWER_ON, OUTPUT);
  digitalWrite(MODEM_PWKEY, LOW);
  digitalWrite(MODEM_RST, HIGH);
  digitalWrite(MODEM_POWER_ON, HIGH);

  
  SerialAT.begin(115200, SERIAL_8N1, MODEM_RX, MODEM_TX);
  delay(3000);

  
  SerialMon.println("Initializing modem...");
  modem.restart();
  
  if (strlen(simPIN) && modem.getSimStatus() != 3 ) {
    modem.simUnlock(simPIN);
  }

  
  String smsMessage = "Hello !";
  if(modem.sendSMS(SMS_TARGET, smsMessage)){
    SerialMon.println(smsMessage);
  }
  else{
    SerialMon.println("SMS failed to send");
  }
}

void loop() {
  // Check if new GPS data is available
while (SerialAT.available()) {
  char c = SerialAT.read();
  if (gps.encode(c)) {
    // If GPS data is valid, extract latitude and longitude
    if (gps.location.isValid()) {
      float latitude = gps.location.lat();
     

  delay(1);
} 
  }
}
}
