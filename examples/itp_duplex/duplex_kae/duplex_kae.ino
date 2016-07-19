const int buttonPin = 31;      // digital input

int ledPin = 31;      // select the pin for the LED

void setup() {
  // configure the serial connection:
  Serial.begin(9600);
  // configure the digital input:
  pinMode(buttonPin, INPUT);
//  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  // print the results:
  Serial.print(sensorValue);
  Serial.print(",");
//
//  if (sensorValue < 10) {
//    digitalWrite(ledPin, HIGH);
//  }
//
//  else {
//    digitalWrite(31, LOW);
  }

  sensorValue = analogRead(A1);
  // print the results:
  Serial.print(sensorValue);
  Serial.print(",");

  sensorValue = analogRead(A2);
  // print the results:
  Serial.print(sensorValue);
  Serial.print(",");

  sensorValue = analogRead(A3);
  // print the results:
  Serial.print(sensorValue);
  Serial.print(",");

  sensorValue = analogRead(A4);
  // print the results:
  Serial.print(sensorValue);
  Serial.print(",");

  sensorValue = analogRead(A5);
  // print the results:
  Serial.print(sensorValue);
  Serial.println();
  delay(1000);

     // read the button:
     sensorValue = digitalRead(buttonPin);
     // print the results:
     Serial.println(sensorValue);
}

