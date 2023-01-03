// Names: Siddarth & Mostafa
// Dates: Apr, 19, 2022
// Description: Code for interfacing unit lab 4

int greenPin1 = 2;
int orangePin1 = 3;
int redPin1 = 4;

int greenPin2 = 7;
int orangePin2 = 8;
int redPin2 = 9;

int whiteLed = 5;

int ledPins[][3] = {{greenPin1, orangePin1, redPin1},{greenPin2, orangePin2, redPin2}};

int sensorPin1 = 0;
int sensorPin2 = 1;

int sensorValue1, sensorValue2;

void setup() {
    // Sets the LED pins to output
    for (int i = 0; i < sizeof(ledPins)/sizeof(int); i++)
    {
        for (int j = 0; j < sizeof(ledPins[i])/sizeof(int); j++)
        {
            pinMode(ledPins[i][j], OUTPUT);
        }
    }
    pinMode(whiteLed, OUTPUT);
}

void loop(){
    sensorValue1 = analogRead(sensorPin1);
    sensorValue2 = analogRead(sensorPin2);

    int sensorValues[2] = {sensorValue1, sensorValue2};

    if (sensorValue1 > 50 && sensorValue2 > 50)
    {
        digitalWrite(whiteLed, HIGH);
    }
    else
    {
        digitalWrite(whiteLed, LOW);
    }

    for (int j = 0; j < sizeof(sensorValues)/sizeof(int); j++)
    {
        int currentSensorValue = sensorValues[j];
        int currentLeds[3];

        for (int i = 0; i < sizeof(ledPins[j])/sizeof(int); i++)
        {
            currentLeds[i] = ledPins[j][i];
        }

        if (currentSensorValue > 40)
        {
            for (int i = 0; i < sizeof(currentLeds)/sizeof(int); i++)
            {
                if (currentLeds[i] == redPin1 || currentLeds[i] == redPin2)
                {
                    digitalWrite(currentLeds[i], HIGH);
                }
                else
                {
                    digitalWrite(currentLeds[i], LOW);
                }
            }
        }
        else if (currentSensorValue > 25){
            for (int i = 0; i < sizeof(currentLeds)/sizeof(int); i++)
            {
                if (currentLeds[i] == orangePin1 || currentLeds[i] == orangePin2)
                {
                    digitalWrite(currentLeds[i], HIGH);
                }
                else
                {
                    digitalWrite(currentLeds[i], LOW);
                }
            }
        }
        else
        {
            for (int i = 0; i < sizeof(currentLeds)/sizeof(int); i++)
            {
                if (currentLeds[i] == greenPin1 || currentLeds[i] == greenPin2)
                {
                    digitalWrite(currentLeds[i], HIGH);
                }
                else
                {
                    digitalWrite(currentLeds[i], LOW);
                }
            }
        }
    }


}