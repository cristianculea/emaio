// Date format prepare: yyyymmdd
String dateformat() {
  time_t t = now();
  String dateformatpack = String('0');
  dateformatpack = year(t);
  if (month(t) < 10)
    dateformatpack = String(dateformatpack + '0' + month(t));
  else
    dateformatpack = String(dateformatpack + month(t));
  if (day(t) < 10)
    dateformatpack = String(dateformatpack + '0' + day(t));
  else
    dateformatpack = String(dateformatpack + day(t));
  return dateformatpack;
  }
  
// Time format prepare: hh:mm
String timeformat() {
  time_t t = now();
  String timeformatpack = String('0');
  if (hour(t) < 10)
    timeformatpack = String('0' + hour(t));
  else
    timeformatpack = String(hour(t));
  if (minute(t) < 10)
    timeformatpack = String(timeformatpack + ':' +'0' + minute(t));
  else
    timeformatpack = String(timeformatpack + ':' + minute(t));
  return timeformatpack;
  }
