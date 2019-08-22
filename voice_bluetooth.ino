#include <SoftwareSerial.h>
SoftwareSerial mySerial(4, 2); // RX, TX

String data;
short mark = 0;
int LED = 7;
void led_on(){
  digitalWrite(LED, HIGH);
}
void led_off(){
  digitalWrite(LED, LOW);
}
void setup() {
  pinMode(LED, OUTPUT);
  // Open serial communications:
  Serial.begin(9600);  
  // The HC-06 defaults to 9600 according to the datasheet.
  mySerial.begin(9600);
}

void loop() {
  // Read user input if available.
  while (mySerial.available()){
    delay(10); // The delay is necessary to get this working!
    char c = mySerial.read();
    if(c == '#'){break;}
    data += c;
  }
  if (data.length() > 0) { 
    
    if(data == "mở"){
      led_on();
      mySerial.print("1");
    }
    if(data == ""){
      led_off();
      mySerial.print("3");
    }
  }
  data="";
}
