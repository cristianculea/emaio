//Citire senzor tensiune
void readDC_VoltageSensors() {
   int analog_value = analogRead(A1);
   delay(1);
   input_voltage = (float)((analog_value)*Vcc)/1024; 
   input_voltage = input_voltage * 16;
   
   if (input_voltage < 0.1) 
   {
     input_voltage=0.0;
   }
} 
   
//Citire senzor curent
void readDC_CurrentSensors() {
  int sensorValue = analogRead(A2);  // read analog input pin 2 curent fotovoltaice senzor SOCAN 100A
     delay(1);
     if (sensorValue<5) {sensorValue=0.0;}
     input_current=(float)(sensorValue)*100/1024;
}

//Citire senzor curent
void calcPower_Energy() {
    power=input_voltage*input_current; // power=voltage*current
    //Serial.print("startMillis = ");
    //Serial.print(startMillis/1000);
    //Serial.print("; ");
    endMillis = millis();
    unsigned long time = endMillis - startMillis;
    
    energy = energy + (power * (time/3600000.00));    //Calculate kilowatt hours used
    
    startMillis = millis();
    //Serial.print("endMillis = ");
    //Serial.print(endMillis/1000);
    //Serial.print("; ");
    //Serial.print("time = ");
    //Serial.print(time/1000);
    //Serial.print("; ");
    /*Serial.print("Vcc = ");
    Serial.print(Vcc);
    Serial.print("; ");
    Serial.print("V = ");
    Serial.print(input_voltage);
    Serial.print("; ");
    Serial.print("A = ");
    Serial.print(input_current);
    Serial.print("; ");
    Serial.print("P = ");
    Serial.print(power);
    Serial.print("; "); 
    Serial.print("E = ");
    Serial.print(energy);
    Serial.println();*/
}
