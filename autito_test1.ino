
byte tiltSensor = '0';

int ledPin = 13;
int tiltPin = 7;


void setup() 
{

 Serial.begin(9600);
 
 pinMode(tiltPin, INPUT);
 pinMode(ledPin, OUTPUT);
 
}

void loop() 
{
  // Read sensors 
  if(digitalRead(tiltPin) == HIGH)
    tiltSensor = '1';
  else
    tiltSensor = '0';
  
  // Send data 
  Serial.write("tilt:");
  Serial.write(tiltSensor);
  Serial.println();
 
  // Delay 
  //delay(200);
}

void serialEvent()
{
  byte newValue = -1;
  while(Serial.available())
  {
    byte newValue = Serial.read();
    
    newValue = newValue - '0';
    if(newValue == 0)
      digitalWrite(13, LOW);
    else if(newValue == 1)
      digitalWrite(13, HIGH);
   
    Serial.flush();
  }
}
