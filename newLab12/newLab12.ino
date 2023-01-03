const int Rmotor[2] = {6, 10};
const int Lmotor[2] = {9, 11};

char serialIn;

void setup() {
  pinMode(Rmotor[0], OUTPUT);
  pinMode(Rmotor[1], OUTPUT);
  pinMode(Lmotor[0], OUTPUT);
  pinMode(Lmotor[1], OUTPUT);

  Serial.begin(9600);
}


void straight(bool forward = true, bool off = false) {
  int forVar = forward ? 255 : 0;
  // right motor
  analogWrite(Rmotor[0], (off ? 0 : forVar));
  analogWrite(Rmotor[1], (off ? 0 : 255 - forVar));
  // left motor
  analogWrite(Lmotor[0], (off ? 0 : forVar));
  analogWrite(Lmotor[1], (off ? 0 : 255 - forVar));
}

void side(bool forward = true, bool right = true) {
  int leftVar = right ? 255 : 255;
  int rightVar = right ? 255 : 255;
  int forVar = forward ? 1 : 0;
  // right motor
  analogWrite(Rmotor[1 - forVar], rightVar);
  analogWrite(Rmotor[forVar], 0);
  // left motor
  analogWrite(Lmotor[forVar], leftVar);
  analogWrite(Lmotor[1-forVar], 0);
}

void loop() {
  while (Serial.available() > 0) {
    serialIn = Serial.read();
  }

  if (serialIn == 'F') {
    straight();
  } else if (serialIn == 'B') {
    //back
    straight(false);
  } else if (serialIn == 'R') {
    //right
    side();
  } else if (serialIn == 'L') {
    // left
    side(false);
  } else {
    straight(true, true);
  }
}
