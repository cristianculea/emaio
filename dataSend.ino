/* Data send only if modulo 5 minute = 0 and second is 0. *********************************************************************/
void data_send_if_modulo5_is0_update_time_display_on_serial() {
    if (timeStatus() != timeNotSet) {
    if (now() != prevDisplay) { //update the display only if time has changed
      prevDisplay = now();
      //digitalClockDisplay();
//    datasendifmodulo5is0();
                    // Send data if minute() % 5 == 0 and second() == 0  
                        if ((minute() % 5) == 0 && second() == 0) {
                    //  if ((minute() % 1) == 0 && (second() % 10) == 0) {
                            lcd.setCursor(0, 2);
                            lcd.print("Sending data...");
                            delay(1000);
                          //Serial.println("Minut divizibil cu 5 si secunda este zero. Trimit date catre server.");
                          httpRequest();
                          }
                          else {
                            //Serial.println(" ");
                            //Serial.println("Minut nu este divizibil cu 5. NU trimit date!");
                            }
      
      }
     }
  }
