#include <LiquidCrystal.h>

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
String commandString = "";

#define DOWN 5
#define LEFT 4
#define RIGHT 6
#define UP 3

int sensorPin =A0;
int readU=0;
int readD=0;
int readL=0;
int readR=0;
int analogval=0;
boolean isConnected = false;

LiquidCrystal lcd(7,8,9,10,11,12); 


void setup() {
  
  Serial.begin(9600);
  pinMode(UP,INPUT);
  pinMode(DOWN,INPUT);
  pinMode(LEFT,INPUT);
  pinMode(RIGHT,INPUT);
  initDisplay();
}

void loop() {

if(stringComplete)
{
  stringComplete = false;
  getCommand();
  
  if(commandString.equals("STAR"))
  {
    lcd.clear();
  }
  if(commandString.equals("STOP"))
  {
    lcd.clear();
    lcd.print("Ready to connect");    
  }
  else if(commandString.equals("TEX1"))
  {
    String text = getTextToPrint();
    printText(text,0);
  }
  else if(commandString.equals("TEX2"))
  {
    String text = getTextToPrint();
    printText(text,1);
  }
  
  inputString = "";
}
button_detect();
analogval= analogRead(sensorPin)/5.0*1024;
if(analogval<800)
{
  
}
}

void initDisplay()
{
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ready to connect");
}

void button_detect(){
  readU=digitalRead(UP);
  readR=digitalRead(RIGHT);
  readD=digitalRead(DOWN);
  readL=digitalRead(LEFT);
  if(readU==LOW && readR==HIGH && readD==HIGH && readL==HIGH){
    Serial.println("UP");
  }
  else if(readU==HIGH && readR==HIGH && readD==HIGH && readL==LOW){
    Serial.println("LEFT");
  }
  else if(readU==HIGH && readR==LOW && readD==HIGH && readL==HIGH){
    Serial.println("RIGHT");
  }
  else if(readU==HIGH && readR==HIGH && readD==LOW && readL==HIGH){
    Serial.println("DOWN");
  }
  else if(readU==HIGH && readR==HIGH && readD==HIGH && readL==HIGH){
   // Serial.println("ÄLLHIGH");
  }
  else{
   Serial.println("UNDEF");
  }
  readU=0;
  readR=0;
  readD=0;
  readL=0;
}

void getCommand()
{
  if(inputString.length()>0)
  {
     commandString = inputString.substring(1,5);
  }
}



String getTextToPrint()
{
  String value = inputString.substring(5,inputString.length()-2);
  return value;
}

void printText(String text,int cursor)
{
  lcd.clear();
  lcd.setCursor(0,cursor);
    if(text.length()<16)
    {
      lcd.print(text);
    }else
    {
      lcd.print(text.substring(0,16));
      lcd.setCursor(0,1);
      lcd.print(text.substring(16,32));
    }
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

