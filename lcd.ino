// LCD begin
void LCDbegin() {
   lcd.begin(20,4);                      // initialize the lcd 
  // Print a message to the LCD.
   lcd.backlight();
   //lcd.begin(16, 2);       //// set up the LCD's number of columns and rows: 
   //lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("    SmartCasa.ro");
   lcd.setCursor(0,1);
   lcd.print("   Energy Monitor");
   lcd.setCursor(0,2);
   lcd.print("     emaio v1.0");
   lcd.setCursor(0,3);
   lcd.print("(c)2019 smartcasa.ro");   
   delay(3000);
   //lcd.clear();
   }

void lcdPrintSensors() {
    //lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
    //lcd.backlight();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(input_voltage,2);
    lcd.print("V");
    //Serial.print("Voltage = ");
    //Serial.print(input_voltage);
    //Serial.println("V");
   
    if ((input_current >= 0) && (input_current < 0)) {
        lcd.setCursor(16, 0);        
    }
    if ((input_current >= 10) && (input_current < 100)) {
        lcd.setCursor(14, 0);
    }
    if ((input_current >= 100) && (input_current < 1000)) {
      lcd.setCursor(13, 0);
      } 
    lcd.print(input_current,2);
    lcd.print("A");
    
    lcd.setCursor(0, 1);
    lcd.print(power,2);
    lcd.print("W");

    if ((energy >= 0) && (energy < 10)){
        lcd.setCursor(12, 1);        
    }
    if ((energy >= 10) && (energy < 100)) {
        lcd.setCursor(11, 1);
      }
    if ((energy >= 100) && (energy < 1000)) {
        lcd.setCursor(10, 1);
    }
    if ((energy >= 1000) && (energy < 10000)) {
        lcd.setCursor(9, 1);
    }
    if ((energy >= 10000) && (energy < 100000)) {
        lcd.setCursor(8, 1);
    }
    
    lcd.print(energy,4);
    lcd.print("Wh");

    digitalClockDisplayLCD();
    lcd.setCursor(0, 2);
    lcd.print("               ");
    
    delay(1000);
    }
