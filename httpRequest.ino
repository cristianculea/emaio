// HTTP request to the server:
void httpRequest() {
  // close any connection before send a new request.
  // This will free the socket on the WiFi shield
  client.stop();

  // if there's a successful connection:
  if (client.connect(server, 80)) {
    Serial.println("   ");
    Serial.println("   ");
    Serial.println("connecting...");
    // send the HTTP request:
//    client.println("GET /service/r2/getstatus.jsp?sid=54214&key=0c4e413c7624641a990c5f6ccee7f624ded4c864&d=20190103&t=11:20 HTTP/1.1");
//    client.println("GET /service/r2/addstatus.jsp?sid=54214&key=0c4e413c7624641a990c5f6ccee7f624ded4c864&d=20190103&t=12:50&v1=340&v2=250&v3=40&v4=30&v5=3&v6=53 HTTP/1.1");
//      Serial.print("client.print primeste: ");
      Serial.println(createdata());
      client.println(createdata());
      client.println("Host: www.pvoutput.org");
      client.println("Connection: close");
      client.println();

    // note the time that the connection was made:
    lastConnectionTime = millis();
//    Serial.println(lastConnectionTime);
  } 
  else {
    // if you couldn't make a connection:
    Serial.println("connection failed");
  }
    //lcd.clear();
    //lcd.setCursor(0, 0);
    //lcd.print("Sending data...");
    //delay(1000);
}
