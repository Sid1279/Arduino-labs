// declare variables for pins

int trig = 7;
int echo = 8;
int rgbLed[] = {5,4,3};

float distance, duration;

void setup()
{
    for(int i = 3; i < 6; i++)
    {
        pinMode(i,OUTPUT);
    }
    pinMode(echo, INPUT);
    pinMode(trig, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    /************ Start US Measurement Section ***********/
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance = duration * 0.034/2;
    /************** End US Measurement Section ***********/
    Serial.println(distance);
    if (distance > 200)
    {
        digitalWrite(rgbLed[0], HIGH);
        digitalWrite(rgbLed[1], LOW);
        digitalWrite(rgbLed[2], LOW);
    }
    else if (distance > 175)
    {
        digitalWrite(rgbLed[0], HIGH);
        digitalWrite(rgbLed[1], HIGH);
        digitalWrite(rgbLed[2], LOW);
    }
    else if (distance > 150){
        digitalWrite(rgbLed[0], LOW);
        digitalWrite(rgbLed[1], HIGH);
        digitalWrite(rgbLed[2], LOW);
    }
    else if (distance > 125)
    {
        digitalWrite(rgbLed[0], LOW);
        digitalWrite(rgbLed[1], HIGH);
        digitalWrite(rgbLed[2], HIGH);
    }
    else if (distance > 100)
    {
        digitalWrite(rgbLed[0], LOW);
        digitalWrite(rgbLed[1], LOW);
        digitalWrite(rgbLed[2], HIGH);
    }
    else if (distance > 50)
    {
        digitalWrite(rgbLed[0], HIGH);
        digitalWrite(rgbLed[1], LOW);
        digitalWrite(rgbLed[2], HIGH);
    }
    else
    {
        digitalWrite(rgbLed[0], HIGH);
        digitalWrite(rgbLed[1], HIGH);
        digitalWrite(rgbLed[2], HIGH);
    }

    delay(10); // small delay to save system resources
}