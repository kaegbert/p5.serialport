const int buttonPin = 31;      // digital input 
 
 void setup() {
   // configure the serial connection:
   Serial.begin(9600);
   // configure the digital input:
   pinMode(buttonPin, INPUT);
 }
 
void loop() {
   // read the X axis:
   int sensorValue = analogRead(A0);
   // print the results:
   Serial.print(sensorValue);
   Serial.print(",");
 
   // read the y axis:
   sensorValue = analogRead(A1);
   // print the results:
   Serial.print(sensorValue);
   Serial.print(",");

      // read the y axis:
   sensorValue = analogRead(A2);
   // print the results:
   Serial.print(sensorValue);
   Serial.print(",");

      // read the y axis:
   sensorValue = analogRead(A3);
   // print the results:
   Serial.print(sensorValue);
   Serial.print(",");

      // read the y axis:
   sensorValue = analogRead(A4);
   // print the results:
   Serial.print(sensorValue);
   Serial.print(",");

      // read the y axis:
   sensorValue = analogRead(A5);
   // print the results:
   Serial.print(sensorValue);
   Serial.print(",");
 
   // read the button:
   sensorValue = digitalRead(buttonPin);
   // print the results:
   Serial.println(sensorValue);
}

