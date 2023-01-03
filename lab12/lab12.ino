/*
Names: Siddarth & Mostafa
Dates: May 11, 2022
Description: Code for interfacing lab 12 - Motors
*/
const int motor[2][2] = {{6,10}, {9,11}}; //2D array to declare pin numbers for motors

void straight(bool forward = true, int time = 3000, bool off = false) {
    int forVar = forward ? 255 : 0; 

    analogWrite(motor[0][0], (off ? 0 : forVar));
    analogWrite(motor[0][1], (off ? 0 : 255-forVar));
    analogWrite(motor[1][0], (off ? 0 : forVar));
    analogWrite(motor[1][1], (off ? 0 : 255-forVar));
    delay(time);
}

void side(bool forward = true, bool right = true, int time = 3000) {
    int leftVar = right ? 75 : 255;
    int rightVar = right ? 255 : 75;
    int forVar = forward ? 1 : 0;

    analogWrite(motor[0][1-forVar], rightVar); 
    analogWrite(motor[0][forVar], 0);
    analogWrite(motor[1][1-forVar], leftVar);
    analogWrite(motor[1][forVar], 0);
    delay(time);
}

void setup() {
    pinMode(motor[0][0], OUTPUT);
    pinMode(motor[0][1], OUTPUT);
    pinMode(motor[1][0], OUTPUT);
    pinMode(motor[1][1], OUTPUT);

    for (int i = 0; i < 2; i ++){
        for (int j = 0; j < 2; j++){
            straight(i);
            side(i, j);
        }
    }
    straight(true, 3000, true);
}