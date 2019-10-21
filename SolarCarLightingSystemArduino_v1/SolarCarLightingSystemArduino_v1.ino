////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// By: Brandon Hickey
// SIUE SOLAR CAR DESIGN
// Date: 10/21/2019
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: 
// All of the input and output pins are hard-coded to the PCB design.
// So if you change the PCB you will need to change these hard-coded values and vice versa.
// The code simply goes through and reads all input pins and makes the corresponding changes on the output
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() 
{
  /////////////////////////////
  // Input Pins
    int BPS_IN=A5;
    int HAZARD_IN=A4;
    int RIGHTBLINK_IN=A3;
    int LEFTBLINK_IN=A2;
    int HEADLIGHT_IN=A1;
    int BREAK_IN=A0;
  // Input Pin Setup
    pinMode(BPS_IN,INPUT);
    pinMode(HAZARD_IN,INPUT);
    pinMode(RIGHTBLINK_IN,INPUT);
    pinMode(LEFTBLINK_IN,INPUT);
    pinMode(HEADLIGHT_IN,INPUT);
    pinMode(BREAK_IN,INPUT);
  /////////////////////////////

  /////////////////////////////
  // Output Pins
    int RIGHTBLINK=2;
    int LEFTBLINK=3;
    int BREAK=4;
    int BPS=5;
    int HEADLIGHT=6;
  // Output Pin Setup
    pinMode(RIGHTBLINK,OUTPUT);
    pinMode(LEFTBLINK,OUTPUT);
    pinMode(BREAK,OUTPUT);
    pinMode(BPS,OUTPUT);
    pinMode(HEADLIGHT,OUTPUT);
  /////////////////////////////
}


void loop() {
  /////////////////////////////
  // Read Pins and Send Signals
    checkRightTurn();
    checkLeftTurn();
    checkBreak();
    checkBPS();
    checkHeadlight();
  /////////////////////////////
}


void checkRightTurn()
{
  /////////////////////////////
  // Description:
  // Read the signal coming from the hazard and right blink switch, if either are HIGH(~5V) turn the RIGHTBLINK output pin HIGH
  // If neither are high then go LOW (~0V)
  // Inputs(Pin):
  //    HAZARD_IN(A4)
  //    RIGHTBLINK_IN(A3)
  // Outputs(Pin):
  //    RIGHTBLINK(2)
  /////////////////////////////
  if(digitalRead(HAZARD_IN)==1 || digitalRead(RIGHTBLINK_IN)==1){
    digitalWrite(RIGHTBLINK,HIGH);
  }
  else{
    digitalWrite(RIGHTBLINK,LOW); //else goes low
  }
}


void checkLeftTurn()
{
  /////////////////////////////
  // Description:
  // Read the signal coming from the hazard and left blink switch, if either are HIGH(~5V) turn the LEFTBLINK output pin HIGH
  // If neither are high then go LOW (~0V)
  // Inputs(Pin):
  //    HAZARD_IN(A4)
  //    LEFTBLINK_IN(A2)
  // Outputs(Pin):
  //    LEFTBLINK(3)
  /////////////////////////////
  if(digitalRead(HAZARD_IN)==1 || digitalRead(LEFTBLINK_IN)==1){
    digitalWrite(LEFTBLINK,HIGH);
  }
  else{
    digitalWrite(LEFTBLINK,LOW);
  }
}


void checkBreak()
{
  /////////////////////////////
  // Description:
  // Read the signal coming from the break switch, if HIGH(~5V) turn the BREAK output pin HIGH
  // Else go LOW (~0V)
  // Inputs(Pin):
  //    BREAK_IN(A0)
  // Outputs(Pin):
  //    BREAK(4)
  /////////////////////////////
  if(digitalRead(BREAK_IN)==1){
    digitalWrite(BREAK,HIGH);
  }
  else{
    digitalWrite(BREAK,LOW);
  }
}


checkBPS()
{
  /////////////////////////////
  // Description:
  // Read the signal coming from the BPS pin, if LOW(~0V) turn the BPS output pin HIGH
  // if HIGH(~5V) input, turn BPS output pin LOW
  // Inputs(Pin):
  //    BPS_IN(A5)
  // Outputs(Pin):
  //    BPS(5)
  /////////////////////////////
  if(digitalRead(BPS_IN)==0){
    digitalWrite(BPS,HIGH);
  }
  else{
    digitalWrite(BPS,LOW);
  }
}


checkHeadlight()
{
  /////////////////////////////
  // Description:
  // Read the signal coming from the headlight switch, if HIGH(~5V) turn the HEADLIGHT output pin HIGH
  // Else go LOW (~0V)
  // Inputs(Pin):
  //    HEADLIGHT_IN(A1)
  // Outputs(Pin):
  //    HEADLIGHT(6)
  /////////////////////////////
  if(digitalRead(HEADLIGHT_IN)==1){
    digitalWrite(HEADLIGHT,HIGH);
  }
  else{
    digitalWrite(HEADLIGHT,LOW);
  }
}
