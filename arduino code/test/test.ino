//zoomkat 3-5-12 simple delimited ',' string  
//from serial port input (via serial monitor)
//and print result out serial port

String readString, data;
int CD, CM, CT, CS, BR; 

void setup() {
  Serial.begin(9600);
  Serial.println("serial delimit test 1.0"); // so I can keep track of what is loaded
}

void loop() {

  //expect a string like CD01,CM01,CT01,CS03,BR255,
  //AZ123.4 EL134.5 AZ90.3 EL2.3 

  if (Serial.available())  {
    char c = Serial.read();  //gets one byte from serial buffer
    
    if (c == ' ') {
      Serial.println(readString); //prints string to serial port out
      
      if(readString.indexOf("AZ") >=0) {
        data=readString.substring(2);
        Serial.print("AZ is: ");
        Serial.println(data);
        CD = data.toInt();
        Serial.println(CD);
        Serial.println();
      }
      if(readString.indexOf("EL") >=0) {
        readString=readString.substring(2);
        Serial.print("EL is: ");
        Serial.println(readString);
        CM = readString.toInt();
        Serial.println(CM);
        Serial.println();
      }
      if(readString.indexOf("CT") >=0) {
        readString=readString.substring(2);
        Serial.print("CT is: ");
        Serial.println(readString);
        CT = readString.toInt();
        Serial.println(CT);
        Serial.println();
      }
       if(readString.indexOf("CS") >=0) {
        readString=readString.substring(2);
        Serial.print("CS is: ");
        Serial.println(readString);
        CS = readString.toInt();
        Serial.println(CS);
        Serial.println();
      }
       if(readString.indexOf("BR") >=0) {
        readString=readString.substring(2);
        Serial.print("BR is: ");
        Serial.println(readString);
        BR = readString.toInt();
        Serial.println(BR);
        Serial.println();
      }
      
      //do some stuff

      readString=""; //clears variable for new input
      data=""; 

    }  
    else {     
      readString += c; //makes the string readString
    }
  }
}
