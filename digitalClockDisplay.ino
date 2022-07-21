  
/* Digital clock display of the time and send data to server function **************************************************************************/
void digitalClockDisplay(){
  Serial.print("Time is ");
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(". Date is ");
  Serial.print(day());
  Serial.print("/");
  Serial.print(month());
  Serial.print("/");
  Serial.print(year()); 
  Serial.println(".");
  //Serial.println(dateformat()); //  yyyymmdd
  //Serial.println(timeformat()); //  hh:mm
  }
  
void digitalClockDisplayLCD(){
  lcd.setCursor(0, 3);
  if (hour() <= 10) {
      lcd.print("0");
      lcd.print(hour());
      }
  else {lcd.print(hour());}
  
  lcd.print(":");
  
  if (minute() <= 10) {
      lcd.print("0");
      lcd.print(minute());
      }
  else {lcd.print(minute());}
  
  lcd.print(":");
  
  if (second() <= 10) {
      lcd.print("0");
      lcd.print(second());
      }
  else {lcd.print(second());}

  lcd.setCursor(10, 3);
  if (day() <= 10) {
      lcd.print("0");
      lcd.print(day());
      }
  else {lcd.print(day());}
  
  lcd.print(".");
  
  if (month() <= 10) {
      lcd.print("0");
      lcd.print(month());
      }
  else {lcd.print(month());}
  
  lcd.print(".");
  
  if (year() <= 10) {
      lcd.print("0");
      lcd.print(year());
      }
  else {lcd.print(year());}
  
  //delay(2000);
  //Serial.println(dateformat()); //  yyyymmdd
  //Serial.println(timeformat()); //  hh:mm
  }
