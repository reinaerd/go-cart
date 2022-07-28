 #include <Servo.h>

Servo myservo;
String input = "<a180s50>";
String num1 ;
String num2;
String sign;
int pos = 0;
int angle = 90;
int s;
String sp;
int idx = 0;
unsigned long messageReceived = 0;
int sens = 1; //1 = marche avant; 0 = marche arrière

int movementSpeed = 0;

const int reverse = 37;
int speedPin = DAC0;

int var = 0;


void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial1.setTimeout(10);
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object

  pinMode(reverse, OUTPUT);
  pinMode(speedPin, OUTPUT);
  myservo.write(90);
}

void loop() {


  /*for (pos = 0; pos <= angle; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(s);                       // waits 15ms for the servo to reach the position

    }*/




  if ( Serial1.available() > 0) {
    input = Serial1.readString();
    Serial.println(input);

    idx = input.indexOf(';');
    num1 = input.substring(0, idx);
    num2 = input.substring(idx + 1);
    //sign = input.substring(idx + 4, idx + 5);
    //sp = input.substring(idx + 5);



    angle = num1.toInt();
    s = num2.toInt();
    //movementSpeed = sp.toInt();
    //Serial1.println(angle);
    myservo.write(angle);
    //Serial1.println(s);
    //delay(s);

    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print(" and Speed: ");
    Serial.println(s);

    if (sens == 1 && s <=0){
      sens = 0;
      digitalWrite(reverse, LOW);
      delay(500);

    }
    else if (sens == 0 && s >= 0){
      sens = 1;
      digitalWrite(reverse, HIGH);    
      delay(500);  
    }

    analogWrite(speedPin, abs(s));
    messageReceived = millis();
  }

  if ((millis() - messageReceived) > 1000 && abs(s) > 0){
    myservo.write(90);
    s = 0;
    analogWrite(speedPin, s);
  }



}


//180;+90
//180;-90
//180; 15; +0
