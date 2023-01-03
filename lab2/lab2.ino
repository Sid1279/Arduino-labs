/* Names: Siddarth & Mostafa
Date: April 20, 2022
Description: Code for Lab 2
LEDs turn on one by one, and stay on (starting from the left). 
Once all four are ON, they turn OFF, one by one (starting from the left) until they are all off
This will keep repeating in a loop
*/

void setup()
{
    //Sets pins 4, 5, 7, 8 as an OUTPUT pins
    pinMode(4, OUTPUT); 
    pinMode(5, OUTPUT);
    pinMode(7, OUTPUT); 
    pinMode(8, OUTPUT); 
}

void loop()
{
    digitalWrite(4, HIGH); // Sets pin 4 on
    delay(500); // Delays program for 500 milliseconds

    digitalWrite(5, HIGH); // Sets pin 5 on
    delay(500); // Delays program for 500 milliseconds

    digitalWrite(7, HIGH); // Sets pin 7 on
    delay(500); // Delays program for 500 milliseconds

    digitalWrite(8, HIGH); // Sets pin 8 on
    delay(500); // Delays program for 500 milliseconds

    digitalWrite(4, LOW); // Sets pin 4 off
    delay(500); // Delays program for 500 milliseconds

    digitalWrite(5, LOW); // Sets pin 5 off
    delay(500); // Delays program for 500 milliseconds

    digitalWrite(7, LOW); // Sets pin 7 off
    delay(500); // Delays program for 500 milliseconds

    digitalWrite(8, LOW); // Sets pin 8 off
    delay(500); // Delays program for 500 milliseconds
}