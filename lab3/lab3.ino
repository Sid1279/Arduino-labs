int ledPins[] = {1,5,2,6,3,7,4,8}; // Array of the led pins organized in the order that they should light up
int ledPinsSize = sizeof(ledPins)/sizeof(int); // Gets the size of the array by dividing number of bytes in the array by
// the number of bytes in a single element of the array (where that is
// sizeof(int) since each element in the array is an int)

void setup(){
    // For loop to iterate through the ledPins array
    for (int i = 0; i < ledPinsSize; i++)
    {
        // For each pin in the ledPins array, this sets those pins as OUTPUT pins
        pinMode(ledPins[i],OUTPUT);
    }
}

void loop(){
    // For loop to decrease the delay time. Starting at 500 and dropping to 100, decerementing by 100 each time
    for (int j = 500; j >= 100; j -= 100)
    {
        // For loop to iterate through the pins to turn them on first
        for (int i = 0; i < ledPinsSize; i++)
        {
            digitalWrite(ledPins[i],HIGH); // Sets each pin to HIGH to turn the LED's connected on
            delay(j); // Uses a delay in ms after each LED is turned on with length j (varies based on the encompasing for loop)
        }
        // For loop to iterate through the pins to turn them off after they are on
        for (int i = 0; i < ledPinsSize; i++)
        {
            digitalWrite(ledPins[i], LOW); // Sets each pin to LOW to turn the LED's connected off
            delay(j); // Delay in ms after each LED is turned on, also with length j
        }
    }
    // For loop to increase the delay time. Starting at 100 and increasing to 500, incrementing by 100 each time.
    for (int j = 100; j <= 500; j += 100)
    {
        // For loop to iterate through the pins to turn them on first
        for (int i = 0; i < ledPinsSize; i++)
        {
            digitalWrite(ledPins[i],HIGH); // Sets each pin to HIGH to turn the LED's connected on
            delay(j); // Uses a delay in ms after each LED is turned on with length j (varies based on the encompasing for loop)
        }
        // For loop to iterate through the pins to turn them off after they are on
        for (int i = 0; i < ledPinsSize; i++)
        {
            digitalWrite(ledPins[i], LOW); // Sets each pin to LOW to turn the LED's connected off
            delay(j); // Delay in ms after each LED is turned on, also with length j
        }
    }
}