// Create data for http request
 String createdata() {
  String createdatapack;
  String GET = String("GET ");
  String service = String("/service/r2/addstatus.jsp?");
  String sid = "sid=" + String("54214");
  String apikey = "&key=" + String("0c4e413c7624641a990c5f6ccee7f624ded4c864");
  
  String senddate = "&d=" + String(dateformat());  // date
  String sendtime = "&t=" + String(timeformat());  // time
  String energygeneration = "&v1=" + String(energy);  // Energy Generation - v1
  String powergeneration = "&v2=" + String(power);  // Power Generation - v2
  String energyconsumption = "&v3=" + String(0);  // Energy Consumption - v3
  String powerconsumption = "&v4=" + String(0);  // Power Consumption - v4
  String temperature = "&v5=" + String(0);  // Temperature - v5
  String voltage = "&v6=" + String(input_voltage);  // Voltage - v6
  //    Serial.println("GET /service/r2/addstatus.jsp?sid=54214&key=0c4e413c7624641a990c5f6ccee7f624ded4c864&d=20190103&t=11:20&v1=40&v2=250&v3=40&v4=30&v5=3&v6=53 HTTP/1.1");
  
  String c1; // Cumulative Flag 
  String netflag;  // Net Flag
  String netdelay; // Net Delay
  String value7; // Extended Value 1  
  String value8; // Extended Value 2
  String value9; // Extended Value 3
  String value10;  // Extended Value 4
  String value11;  // Extended Value 5
  String value12;  // Extended Value 6
  String message1; // Text Message 1
  
  String HTTP = " HTTP/1.1";
  
  createdatapack = String( GET + service + sid + apikey + senddate + sendtime + energygeneration + powergeneration + energyconsumption + powerconsumption + temperature + voltage + HTTP); 
  //Serial.println(createdatapack);

  //String sidapi = String("sid=54214&key=0c4e413c7624641a990c5f6ccee7f624ded4c864");
  //String datetime = String("&d=20190103&t=13:20&v1=150&v2=100&v3=40&v4=30&v5=3&v6=53 HTTP/1.1");

  // x createdatapack = String( GET + service + sidapi + datetime );

//    client.println("GET /service/r2/addstatus.jsp?sid=54214&key=0c4e413c7624641a990c5f6ccee7f624ded4c864&d=20190103&t=11:20&v1=40&v2=250&v3=40&v4=30&v5=3&v6=53 HTTP/1.1");
// /service/r2/getstatus.jsp?sid=54214&key=0c4e413c7624641a990c5f6ccee7f624ded4c864&d=20190103&t=11:20 HTTP/1.1
//  Serial.print("Send data trimite: ");
  //Serial.println(createdatapack);
  return createdatapack;
  }
