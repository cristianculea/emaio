/*
 /service/r2/addstatus.jsp?sid=54214&key=0c4e413c7624641a990c5f6ccee7f624ded4c864&d=20190103&t=12:50&v1=150&v2=200&v3=40&v4=30&v5=3&v6=53 HTTP/1.1
 */

// Test incoming net data and send to serial post for debugging
void webclient_view_incoming_net_data() {
  // if there's incoming data from the net connection.
  // send it out the serial port.  This is for debugging
  // purposes only:
  while (client.available()) {
    char c = client.read();
    //Serial.write(c);
    readString += c; //places captured byte in readString
    }
    //Serial.println("HTTP REQUEST RECEIVED.");
    Serial.print(readString); //prints readString to serial monitor 
    readString=""; //clear readString variable
  }
  


 /* Test http request with posting interval*/
void test_http_request_postinginterval() {
  // if 10 seconds have passed since your last connection,
  // then connect again and send data:
  if (millis() - lastConnectionTime > postingInterval) {
    httpRequest();
    }
  }
