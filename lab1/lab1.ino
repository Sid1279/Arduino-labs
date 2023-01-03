// Names: Siddarth & Mostafa
// Date: April 20, 2022
// Description: Code for lab 1 
// LED blinks on and off repeatedly with a delay period of 1 second (1000 milliseconds).LED stays on for 1000 ms, turns off for 1000 ms, and repeats.

void setup() //setup code (runs once)
{
   pinMode(9, OUTPUT); //Set the pin 9 (the LED pin) as an OUTPUT pin
}

void loop() //loop code (runs repeatedly)
{
    digitalWrite(9, HIGH); //LED connected to pin 9 turns ON
    delay(1000); //delay for 1000 milliseconds
    digitalWrite(9, LOW); //LED connected to pin 9 turns OFF
    delay(1000); //delay for 1000 milliseconds
}