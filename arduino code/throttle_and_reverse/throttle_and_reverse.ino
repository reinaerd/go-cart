
//+ => forwards
//- => backwards

int movementSpeed = 0;

const int reverse = 37;
int speedPin = DAC0;

int var = 0;





void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);
  pinMode(reverse, OUTPUT);
  pinMode(speedPin, OUTPUT);
}

void loop() {

  if ( Serial.available() > 0) {

    movementSpeed = Serial.parseInt();






    if (movementSpeed > 0) {
      digitalWrite(reverse, HIGH);
      analogWrite(speedPin, movementSpeed);
      Serial.println("i am high");

    }
    else {
      digitalWrite(reverse, LOW);
      analogWrite(speedPin, abs(movementSpeed));
      Serial.println("i am low");
    }

  }

}
