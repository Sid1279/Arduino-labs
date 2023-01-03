/*
Names: Siddarth & Mostafa
Dates: May 11, 2022
Description: Code for interfacing lab 9 - LDR
*/

int ldrPin = 0;
int ldrInput;

int led1 = 11;
int led2 = 10;

int ledBrightness;
int ledBrightnessConstrained;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  pinMode(ldrPin, INPUT);
 
}

void loop() {
  ldrInput = analogRead(ldrPin); //read the amount of light from ldr

  ledBrightness = map(ldrInput, 400, 760, 0, 255); //map LED brightness values from 400 to 760
  ledBrightnessConstrained = constrain(ledBrightness, 0, 255); //constrain brightness values from 0 to 255

  analogWrite(led1, ledBrightnessConstrained); //supply constrained voltage to LED 1
  analogWrite(led2, 255 - ledBrightnessConstrained); //supply voltage OPPOSITE to LED 2
}