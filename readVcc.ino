// Read Vcc value in V
void readvccvalue() {
  Vcc = readVcc()/1000.0 - 0.06;
  ADCValue = analogRead(0);
  Voltage = (ADCValue / 1024.0) * Vcc; //For accurate measurements, divide the ADC value by the ADC maximum value and multiply by the resultant ADV value.
  }
  
long readVcc() {
  long result;
  // Read 1.1V reference against AVcc
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA,ADSC));
  result = ADCL;
  result |= ADCH<<8;
  result = 1125300L / result; // Back-calculate AVcc in mV
  return result;
}
