


#define DOWN 5
#define LEFT 4
#define RIGHT 6
#define UP 3
int sensorPin=  A0;

int readU=0;
int readD=0;
int readL=0;
int readR=0;
int analogval=0;
bool flag=true;
//0705111601

#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(UP,INPUT);
  pinMode(DOWN,INPUT);
  pinMode(LEFT,INPUT);
  pinMode(RIGHT,INPUT);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Control Panel");
}

void loop() {
  // put your main code here, to run repeatedly:
  readU=digitalRead(UP);
  readR=digitalRead(RIGHT);
  readD=digitalRead(DOWN);
  readL=digitalRead(LEFT);
  /*if(readU==HIGH && readR==LOW && readD==LOW && readL==LOW){
    Serial.println("UP");
  }
  else if(readU==LOW && readR==LOW && readD==LOW && readL==HIGH){
    Serial.println("LEFT");
  }
  else if(readU==LOW && readR==HIGH && readD==LOW && readL==LOW){
    Serial.println("RIGHT");
  }
  else if(readU==LOW && readR==LOW && readD==HIGH && readL==LOW){
    Serial.println("DOWN");
  }
  else if(readU==LOW && readR==LOW && readD==LOW && readL==LOW){
  }
  else{
    Serial.println("UNDEF");
  }*/
  if(analogval<100){
    flag=true;
    lcd.setCursor(0, 0);
    lcd.print("Control Panel");
  if(readU==LOW && readR==HIGH && readD==HIGH && readL==HIGH){
    
    lcd.setCursor(0, 1);
  // print the number of seconds since reset:
    lcd.print("Moving Up");
  }
  else if(readU==HIGH && readR==HIGH && readD==HIGH && readL==LOW){
    lcd.setCursor(0, 1);
     lcd.print("Moving LEFT");
  }
  else if(readU==HIGH && readR==LOW && readD==HIGH && readL==HIGH){
    lcd.setCursor(0, 1);
    lcd.print("Moving RIGHT");
  }
  else if(readU==HIGH && readR==HIGH && readD==LOW && readL==HIGH){
    lcd.setCursor(0, 1);
    lcd.print("Moving DOWN");
  }
  else if(readU==HIGH && readR==HIGH && readD==HIGH && readL==HIGH){
   // Serial.println("ÄLLHIGH");
  }
  else{
   //Serial.println("UNDEF");
  }
  Serial.println(readU);
  Serial.println(readD);
  Serial.println(readL);
  Serial.println(readR);
  Serial.println("\n\n\n");
  delay(100);
  readU=0;
  readR=0;
  readD=0;
  readL=0;
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.clear();
  lcd.print("                        ");
  }
  analogval= 1.0*(analogRead(sensorPin));
  Serial.println(analogval);
  if(analogval>100 && flag)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("First Question");
  delay(200);
  // print the number of seconds since reset:
  lcd.clear();
  lcd.print("2+3?");
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.clear();
  lcd.print("4 5 6 7");
  delay(200);
  flag=false;
}
}

