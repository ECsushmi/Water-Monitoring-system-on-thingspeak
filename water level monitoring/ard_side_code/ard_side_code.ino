#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(11,10,9,2,3,4,7); //Create Liquid Crystal Object called LCD
#include <SoftwareSerial.h>

#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

#define trigPin 13 //Sensor Echo pin connected to Arduino pin 13
#define echoPin 12 //Sensor Trig pin connected to Arduino pin 12
#define buzPin 8 // buzzer positive to Arduino pin 8

SoftwareSerial espSerial(5, 6);

String str;

void setup()
{
  Serial.begin(115200);
  espSerial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzPin, OUTPUT);
  LCD.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD
  LCD.setCursor(0,0); //Set LCD cursor to upper left corner, column 0, row 0
  LCD.print("Water level:"); //Print Message on First Row
}
void loop() 
{
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * SOUND_SPEED/2;


  LCD.setCursor(0,1); //Set cursor to first column of second row
  LCD.print(" "); //Print blanks to clear the row
  LCD.setCursor(0,1); //Set Cursor again to first column of second row
  LCD.print(distance);
 //Print measured distance
  
  //Print your units.
  Serial.println(distance);
  str =String(distance);
  espSerial.println(str);
  delay(2000); //pause to let things settle
}
