const int buttonPin = 53;      // digital input
int ledPin = 31;      // select the pin for the LED
int ledPin2 = 33;      // select the pin for the LED
int ledPin3 = 35;      // select the pin for the LED
int ledPin4 = 37;      // select the pin for the LED
int ledPin5 = 39;      // select the pin for the LED
int ledPin6 = 41;      // select the pin for the LED

void setup() {
  // configure the serial connection:
  Serial.begin(9600);
  // configure the digital input:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
}

void loop() {
  // read the X axis:
  int sensorValue = analogRead(A0);
  // print the results:
  Serial.print(sensorValue);
  Serial.print(",");

  if (sensorValue < 10) {
    digitalWrite(31, HIGH);
  }

  else {
    digitalWrite(31, LOW);
  }

  sensorValue = analogRead(A1);
  // print the results:
  Serial.print(sensorValue);
  Serial.print(",");

  if (sensorValue < 10) {
    digitalWrite(ledPin2, HIGH);
  }

  else {
    digitalWrite(ledPin2, LOW);
  }

  // PHOTOCELL 3
  sensorValue = analogRead(A2);
  // print the results:
  Serial.print(sensorValue);
  Serial.print(",");

  if (sensorValue < 15) {
    digitalWrite(ledPin3, HIGH);
  }

  else {
    digitalWrite(ledPin3, LOW);
  }


  // PHOTOCELL 4
  sensorValue = analogRead(A3);
  // print the results:
  Serial.print(sensorValue);
  Serial.print(",");

  if (sensorValue < 10) {
    digitalWrite(37, HIGH);
  }

  else {
    digitalWrite(37, LOW);
  }

  sensorValue = analogRead(A4);
  // print the results:
  Serial.print(sensorValue);
  Serial.print(",");

  if (sensorValue < 10) {
    digitalWrite(39, HIGH);
  }

  else {
    digitalWrite(39, LOW);
  }

  sensorValue = analogRead(A5);
  // print the results:
  Serial.print(sensorValue);
  Serial.print(",");

  if (sensorValue < 10) {
    digitalWrite(41, HIGH);
  }

  else {
    digitalWrite(41, LOW);
  }

  // read the button:
  sensorValue = digitalRead(buttonPin);
  // print the results:
  Serial.println(sensorValue);
}

