// declare variables for pins
int trig = 7;
int echo = 8;
int greenLed = 4;
int redLed = 5;
int buzzer = 6;

float distance, duration;


int musicalNotes[][2] = {{415,500},{261,500},{415,500},{261,500},{392,500},{261,500},{392,500},{261,500},{415,500},{261,500},{415,500},{261,500},{392,500},{261,500},{392,500},{261,500},{415,500},{261,500},{415,500},{261,500},{467,500},{261,500},{467,500},{261,500},{527,500},{261,500},{527,500},{261,500},{527,2000}};

void setup()
{
    for(int i = 4; i < 7; i++)
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
    if (distance < 50)
    {
        digitalWrite(redLed, HIGH);
        digitalWrite(greenLed, LOW);
        for(int i = 0; i < sizeof(musicalNotes)/sizeof(musicalNotes[0]); i++)
        {
          tone(buzzer,musicalNotes[i][0]);
          delay(musicalNotes[i][1]);
        }
       
    }
    else if (distance < 70)
    {
        digitalWrite(redLed, LOW);
        digitalWrite(greenLed, HIGH);
        tone(buzzer, 430);
    }
    else if (distance < 90)
    {
        digitalWrite(redLed, LOW);
        digitalWrite(greenLed, HIGH);
        tone(buzzer, 370);
    }
    else if (distance < 110)
    {
        digitalWrite(redLed, LOW);
        digitalWrite(greenLed, HIGH);
        tone(buzzer, 340);
    }
    else
    {
      noTone(buzzer);
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, HIGH);
    }

    delay(10); // small delay to save system resources
}