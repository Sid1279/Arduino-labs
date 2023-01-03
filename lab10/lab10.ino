/*
Names: Siddarth & Mostafa
Dates: May 11, 2022
Description: Code for interfacing lab 10 - Temperature Sensor
*/
int temperaturePin = 0;
int ledPin = 2;
float voltage;
float degreesC;
float degreesF;

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  voltage = analogRead(temperaturePin) * 0.004882814;
  degreesC = (voltage - 0.5) * 100.0;
  degreesF = degreesC * (9.0/5.0) + 32.0;
  
  Serial.print("voltage: ");
  Serial.print(voltage);
  Serial.print("  deg C: ");
  Serial.print(degreesC);
  Serial.print("  deg F: ");
  Serial.println(degreesF);
  
  //Temperature is greater than 38 degrees Celsius
  if(degreesC > 38)
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED is ON!");
  }

  //Temperature is less than or equal to 38 degrees Celsius
  else 
  {
    digitalWrite(ledPin, LOW);
    Serial.println("LED is OFF!");
  }
  delay(1000);
}
