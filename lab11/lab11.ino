/*
Names: Siddarth & Mostafa
Dates: May 11, 2022
Description: Code for interfacing lab 11 - Servos
*/

#include <Servo.h>
Servo servo1, servo2;

void setup()
{
    servo1.attach(10);
    servo2.attach(9);
}

void loop()
{
    servo1.write(90);
    servo2.write(90);
    delay(2000);

    servo1.write(180);
    servo2.write(0);
    delay(2000);
    
    servo1.write(0);
    servo2.write(180);
    delay(2000);
    
    //sweep 1
    for(int position = 0; position < 180; position += 2)
    {
        servo1.write(position);
        servo2.write(180-position);
        delay(111);
    }
    
    //sweep 2
    for(int position = 180; position >= 0; position -= 1)
    {                                
        servo1.write(position);
        servo2.write(180-position);
        delay(55);
    }
}