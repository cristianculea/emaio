//TIME NTP libraries (TimeLib, Ethernet, EthernetUdp, SPI).
//http-request uses SPI and Ethernet
#include <TimeLib.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <SPI.h>
#include <EmonLib.h>
#include <Wire.h> // pentru I2C

#include <Dns.h>
#include <Time.h>
//#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>

String readString;

//MAC address
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; 

//Static IP address
IPAddress ip(192, 168, 1, 254);
IPAddress myDns(192, 168, 1, 1);

// initialize the EthernetClient library instance:
EthernetClient client;

// NTP Servers:
char timeServer[] = "pool.ntp.org"; 
IPAddress iptimeServer; // pool.ntp.org
// Standard Eastern European Time (DST for EET to do!!!)
const int timeZone = 2;     
// initialize the EthernetUDP library instance:
EthernetUDP Udp;
// local port to listen for UDP packets
unsigned int localPort = 8888;  


// Host of the httpRequest()
char server[] = "www.pvoutput.org";  
//IPAddress server(45, 56, 66, 169);
//HTTP REQUEST vars
unsigned long lastConnectionTime = 0;           // last time you connected to the server, in milliseconds
const unsigned long postingInterval = 2UL*1000;  // delay between updates, in milliseconds


//Sensor data variables
// DC Sensors
float input_voltage = 0.0; // Tension in V
float input_current = 0.0; // Current A
float power = 0.0; // Power in W
float energy = 0.0; // Energy in Wh

unsigned int ADCValue; // digital value from analog read
double Voltage;
double Vcc;

unsigned long startMillis = 0.0; // Start energy counting
unsigned long endMillis = 0.0; // End energy counting

// AC sensors
//EnergyMonitor emon1;
//const int pinVoltage = 1;
//const int pinCurrent = 2;

const int SyncInterval = 61; // NTP time sync interval

time_t prevDisplay = 0; // when the digital clock was displayed

//LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
//LiquidCrystal_I2C lcd(0x27,20,2);
//LiquidCrystal_I2C lcd(0x3F,16,2);
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
//0x3F pentru LCD cu 1 singura linie

void setup() {
  // put your setup code here, to run once:
  serialbegin();
  LCDbegin();
  getIP();
  getIP_for_NTPserver();
  startUDP();
  setSyncProvider(getNtpTime);
  setSyncInterval(SyncInterval);
  digitalClockDisplay();
  digitalClockDisplayLCD();
  delay(2000);
  
//  emon1.voltage(pinVoltage, 234.26, 1.7);  // Voltage: input pin, calibration, phase_shift
//  emon1.current(pinCurrent, 111.1);       // Current: input pin, calibration.
}

void loop() {
  // put your main code here, to run repeatedly: 

  readvccvalue();
  readDC_VoltageSensors();
  readDC_CurrentSensors();
  calcPower_Energy();
  lcdPrintSensors(); 

  data_send_if_modulo5_is0_update_time_display_on_serial();
  //test_http_request_postinginterval(); // Test HTTP request at posting interval defined in global variables.
  webclient_view_incoming_net_data();  //  Shows the server response on serial when client.print("senddatapack").
  
  }
