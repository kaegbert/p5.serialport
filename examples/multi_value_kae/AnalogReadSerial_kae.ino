void setup() {
  // configure the serial connection:
  Serial.begin(9600);
}

void loop() {
  for (int thisSensor = 0; thisSensor < 6; thisSensor++) {
    int sensorValue = analogRead(thisSensor);
    int val = map(sensorValue, 0, 1023, 0, 255);
    Serial.print(val);
    // if you're on the last sensor value, end with a println()
    // otherwise, print a comma
    if (thisSensor == 5) {
      Serial.println();
    } else {
      Serial.print(",");
    }
  }
  delay(1000);
}

