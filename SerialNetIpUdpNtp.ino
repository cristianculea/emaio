/* Serial begin */
  void serialbegin() {
    Serial.begin(9600);
    while (!Serial) ; // Needed for Leonardo only
    delay(1);
  }

/* Get IP **************************************************************************************/
void getIP() {
  Serial.println("SmartCasa.ro NTP sync & Clock");
  Serial.println("Initialize Ethernet with DHCP:");
  lcd.setCursor(0,2);
  lcd.print("NTP sync clock      ");
  delay(500);
  lcd.setCursor(0,3);
  lcd.print("Initialize Ethernet ");
  delay(0);
  //if (Ethernet.begin(mac) == 0) {
    // no point in carrying on, so do nothing forevermore:
    //while (1) {
      //Serial.println("Failed to configure Ethernet using DHCP");
//      delay(0);
      //}
    // Check for Ethernet hardware present
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      //Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
      //while (true) {
        //delay(1); // do nothing, no point running without Ethernet hardware
        //}
    //}
    //if (Ethernet.linkStatus() == LinkOFF) {
      //Serial.println("Ethernet cable is not connected.");
    //}
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip, myDns);
    Serial.print("My IP address: ");
    Serial.println(Ethernet.localIP());
    lcd.clear();
    lcd.print("My IP address: ");
    lcd.setCursor(0, 1);
    lcd.print(Ethernet.localIP());
    delay(1000);

  } else {
    Serial.print("  DHCP assigned IP ");
    Serial.println(Ethernet.localIP());
    lcd.clear();
    lcd.print("DHCP assigned IP: ");
    lcd.println(Ethernet.localIP());
    delay(1000);

  }
  // give the Ethernet shield a second to initialize:
  delay(1000);
  }
// Get ip for the NTP server
void getIP_for_NTPserver() {
  DNSClient dns;
  dns.begin(Ethernet.dnsServerIP());
  dns.getHostByName(timeServer, iptimeServer);
  Serial.print("NTP IP from the pool: ");
  Serial.println(iptimeServer);
  lcd.clear();
  lcd.print("NTP IP is: ");
  lcd.setCursor(0, 1);
  lcd.print(iptimeServer);
  delay(2000);

}

/* Start UDP ********************************************************************************/
void startUDP() {
  Udp.begin(localPort);
  Serial.println("Waiting for time sync");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Waiting for");
  lcd.setCursor(0,1);
  lcd.print("NTP time sync");
  delay(1000);
  }

/*-------- NTP code ----------*************************************************************************************/

const int NTP_PACKET_SIZE = 48; // NTP time is in the first 48 bytes of message
byte packetBuffer[NTP_PACKET_SIZE]; //buffer to hold incoming & outgoing packets

time_t getNtpTime()
{
  while (Udp.parsePacket() > 0) ; // discard any previously received packets
  Serial.println();
  Serial.println();
  Serial.println("Transmit NTP Request");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Transmit NTP Request");
  delay(1000);
  sendNTPpacket(iptimeServer);
  uint32_t beginWait = millis();
  while (millis() - beginWait < 1500) {
//    Serial.print("beginWait = ");
//    Serial.println(beginWait);
//    Serial.print("millis = ");
//    Serial.println(millis());
    int size = Udp.parsePacket();
    if (size >= NTP_PACKET_SIZE) {
        Serial.println("Receive NTP Response");
        lcd.setCursor(0,1);
        lcd.print("Receive NTP Response");
        delay(1000);
      Udp.read(packetBuffer, NTP_PACKET_SIZE);  // read packet into the buffer
//      Serial.println(NTP_PACKET_SIZE);
//      if (NTP_PACKET_SIZE < 48) {time_t getNtpTime();}
      unsigned long secsSince1900;
      // convert four bytes starting at location 40 to a long integer
      secsSince1900 =  (unsigned long)packetBuffer[40] << 24;
      secsSince1900 |= (unsigned long)packetBuffer[41] << 16;
      secsSince1900 |= (unsigned long)packetBuffer[42] << 8;
      secsSince1900 |= (unsigned long)packetBuffer[43];
      return secsSince1900 - 2208988800UL + timeZone * SECS_PER_HOUR;
      }
  }
  Serial.println("No NTP Response :-(");
  lcd.clear();
  lcd.setCursor(0, 2);
  lcd.print("No NTP Response :-(");
  delay(1000);
  return 0; // return 0 if unable to get the time
}

/* Send an NTP request to the time server at the given address ********************************************************/
void sendNTPpacket(IPAddress &address)
{
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;
  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:                 
  Udp.beginPacket(address, 123); //NTP requests are to port 123
  Udp.write(packetBuffer, NTP_PACKET_SIZE);
  Udp.endPacket();
}
