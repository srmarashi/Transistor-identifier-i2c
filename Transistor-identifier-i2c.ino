//Transistor Identifier by: Seyed Roohollah marashi
//Srmarashi@yahoo.com    vitapour Gmbh Austria, Wien
// ATT: some special Transistors will not be detect with this project because of when the number of HFE are too close
// to each other. surely the component tester are more advanced and usefull  but this is very fast way to
// identifie Transistors.........Thanks for your time

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int No1;
int No2;
int No3;


int case1 = 0;
int case2 = 0;
int case3 = 0;
int case4 = 0;
int case5 = 0;
int case6 = 0;
int case7 = 0;
int case8 = 0;

LiquidCrystal_I2C lcd(0x3f, 20, 4);

void setup() {

  lcd.init();                      // initialize the lcd
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();


  // initialize digital pin LED_BUILTIN as an output.
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("Transistor ");
  lcd.setCursor(0, 1);
  lcd.print("    Identifier");



  Serial.print("case #1 ->");
  digitalWrite(8, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(9, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(10, HIGH);
  No1 = analogRead(A0);
  No2 = analogRead(A1);
  No3 = analogRead(A2);
  Serial.print(No1);
  Serial.print("-");
  Serial.print(No2);
  Serial.print("-");
  Serial.println(No3);
  //N-channel  Mosfet  S-D-G
  if ((No1 >= 150) and (No2 >= 400) and (No3 >= 800)) case1 = 1;

  //N-channel  Mosfet  G-D-S
  if ((No1 <= 5) and (No2 >= 800) and (No3 >= 800)) case1 = 2;
  if ((No1 >= 800) and (No2 >= 800) and (No3 <= 100)) case1 = 3;
  

  delay(200);  tone(7, 1000);


  Serial.print("case #2 ->");
  digitalWrite(8, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(10, HIGH);
  No1 = analogRead(A0);
  No2 = analogRead(A1);
  No3 = analogRead(A2);
  Serial.print(No1);
  Serial.print("-");
  Serial.print(No2);
  Serial.print("-");
  Serial.println(No3);

  //N-channel  Mosfet  S-D-G
  if ((No1 > 150) and (No2 >= 100) and (No3 > 900)) case2 = 1;
   if ((No1 > 150) and (No2 <= 50) and (No3 <=  50)) case2 = 4;

  //N-channel  Mosfet  G-D-S
  if ((No1 == 0) and (No2 >= 300) and (No3 > 400)) case2 = 2;

  delay(200);  tone(7, 1500);

  Serial.print("case #3 ->");
  digitalWrite(8, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(10, LOW);
  No1 = analogRead(A0);
  No2 = analogRead(A1);
  No3 = analogRead(A2);
  Serial.print(No1);
  Serial.print("-");
  Serial.print(No2);
  Serial.print("-");
  Serial.println(No3);
  //N-channel  Mosfet  S-D-G
  if ((No1 <= 5) and (No2 <= 5) and (No3 >= 0)) case3 = 1;
  //N-channel  Mosfet  G-D-S
  if ((No1 <= 5) and (No2 >= 1) and (No3 == 0)) case3 = 2;


  delay(200);  tone(7, 1800);

  Serial.print("case #4 ->");
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(10, LOW);
  No1 = analogRead(A0);
  No2 = analogRead(A1);
  No3 = analogRead(A2);
  Serial.print(No1);
  Serial.print("-");
  Serial.print(No2);
  Serial.print("-");
  Serial.println(No3);
  //N-channel  Mosfet  S-D-G
  if ((No1 > 200) and (No2 > 200) and (No3 >= 0)) case4 = 1;
  //N-channel  Mosfet  G-D-S
  if ((No1 > 300) and (No2 == 0) and (No3 == 0)) case4 = 2;
if ((No1 < 200) and (No2 < 300) and (No3 >= 0)) case4 = 5;
if ((No1 == 0) and (No2 == 0) and (No3 >= 0)) case4 = 6;

  delay(200);  tone(7, 2000);


  Serial.print("case #5 ->");
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(10, HIGH);
  No1 = analogRead(A0);
  No2 = analogRead(A1);
  No3 = analogRead(A2);
  Serial.print(No1);
  Serial.print("-");
  Serial.print(No2);
  Serial.print("-");
  Serial.println(No3);

  //N-channel  Mosfet  S-D-G
  if ((No1 > 200) and (No1 < 900) and (No2 > 200) and (No3 > 800)) case5 = 1;

  //N-channel  Mosfet  G-D-D
  if ((No1 > 900) and (No2 > 200) and (No3 > 300)) case5 = 2;
  delay(200);  tone(7, 1500);

  Serial.print("case #6 ->");
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(9, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(10, HIGH);
  No1 = analogRead(A0);
  No2 = analogRead(A1);
  No3 = analogRead(A2);
  Serial.print(No1);
  Serial.print("-");
  Serial.print(No2);
  Serial.print("-");
  Serial.println(No3);

  //N-channel  Mosfet  S-D-G
  if ((No1 > 500) and (No2 > 900) and (No3 > 900)) case6 = 1;
  //N-channel  Mosfet  G-D-S
  if ((No1 > 800) and (No2 > 800) and (No3 > 800) and (case5 = 2)) case6 = 2;

  delay(200);  tone(7, 3000);


  Serial.print("case #7 ->");
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(9, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(10, LOW);
  No1 = analogRead(A0);
  No2 = analogRead(A1);
  No3 = analogRead(A2);
  Serial.print(No1);
  Serial.print("-");
  Serial.print(No2);
  Serial.print("-");
  Serial.println(No3);

  //N-channel  Mosfet  S-D-G
  if ((No1 > 900) and (No2 > 900) and (No3 > 0)) case7 = 1;

  //N-channel  Mosfet  G-D-S
  if ((No1 > 700) and (No2 > 400) and (No3 > 200) and (case4 == 2)) case7 = 2;



  delay(200);  tone(7, 3100);


  Serial.print("case #8 ->");
  digitalWrite(8, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(9, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(10, LOW);
  No1 = analogRead(A0);
  No2 = analogRead(A1);
  No3 = analogRead(A2);
  Serial.print(No1);
  Serial.print("-");
  Serial.print(No2);
  Serial.print("-");
  Serial.println(No3);
  //N-channel  Mosfet  S-D-G
  if ((No1 > 150) and (No2 > 900) and (No3 >= 0)) case8 = 1;

  //N-channel  Mosfet  G-D-S
  if ((No1 > 150) and (No2 > 900) and (No3 == 0)  and (case2 == 2)) case8 = 2;


  noTone(7);

  // Print Case # amount
  Serial.print(case1);
  Serial.print("-");
  Serial.print(case2);
  Serial.print("-");
  Serial.print(case3);
  Serial.print("-");
  Serial.print(case4);
  Serial.print("-");
  Serial.print(case5);
  Serial.print("-");
  Serial.print(case6);
  Serial.print("-");
  Serial.print(case7);
  Serial.print("-");
  Serial.println(case8);

  //NO Component or UnKnown item
  if ((case1 == 2) and (case2 == 0) and (case3 == 1) and (case4 == 2) and (case5 == 2) and (case6 == 2) and (case7 == 1) and (case8 == 1))
  {
    Serial.println("UnKnown Component or Socket Empty");
    lcd.setCursor(0, 0);
    lcd.print("!UnKnown item!");
    lcd.setCursor(0, 1);
    lcd.print("Socket Empty  ");
  }

  if ((case1 == 3) and (case2 == 4) and (case3 == 1) and (case4 == 6) and (case5 == 2) and (case6 == 2) and (case7 == 0) and (case8 == 0))
  {
    Serial.println("UnKnown Component or Socket Empty");
    lcd.setCursor(0, 0);
    lcd.print("UnKnown Component");
    lcd.setCursor(0, 1);
    lcd.print("Socket Empty");
  }

  //N-channel  Mosfet  S-D-G ANswer
  if ((case1 == 3) and (case2 == 0) and (case3 == 1) and (case4 == 6) and (case5 == 2) and (case6 == 2) and (case7 == 0) and (case8 == 0))
  {
    Serial.println("N-Channel MOSFET  1=Source 2=Drain 3=Gate");
    lcd.setCursor(0, 0);
    lcd.print("N-Ch MOSFET");
    lcd.setCursor(0, 1);
    lcd.print("1=Src 2=Drn 3=Gte");
  }

  //N-channel  Mosfet  G-D-S ANswer
  if ((case1 == 0) and (case2 == 4) and (case3 == 1) and (case4 == 0) and (case5 == 2) and (case6 == 2) and (case7 == 0) and (case8 == 0))
  {
    Serial.println("N-Channel MOSFET  1=Gate 2=Drain 3=Source");
    lcd.setCursor(0, 0);
    lcd.print("N-Ch MOSFET");
    lcd.setCursor(0, 1);
    lcd.print("1=Gte 2=Drn 3=Src");;
  }


  //P-channel  Mosfet  S-D-G ANswer
  if ((case1 == 3) and (case2 == 0) and (case3 == 1) and (case4 == 5) and (case5 == 2) and (case6 == 2) and (case7 == 0) and (case8 == 0))
  {
    Serial.println("P-Channel MOSFET  1=Source 2=Drain 3=Gate");
    lcd.setCursor(0, 0);
    lcd.print("P-Ch MOSFET");
    lcd.setCursor(0, 1);
    lcd.print("1=Src 2=Drn 3=Gte");;
  }
 

  //P-channel  Mosfet  G-D-S ANswer
  if ((case1 == 0) and (case2 == 4) and (case3 == 1) and (case4 == 5) and (case5 == 2) and (case6 == 2) and (case7 == 0) and (case8 == 0))
  {
    Serial.println("P-Channel MOSFET  1=Gate 2=Drain 3=Source");
    lcd.setCursor(0, 0);
    lcd.print("P-Ch MOSFET");
    lcd.setCursor(0, 1);
    lcd.print("1=Gte 2=Drn 3=Src");;
  }

  //PNP  General Transistor E-B-C ANswer
  if ((case1 == 3) and (case2 == 0) and (case3 == 1) and (case4 == 1) and (case5 == 2) and (case6 == 2) and (case7 == 0) and (case8 == 0))
  {
    Serial.println("PNP General  1=E 2=B 3=C");
    lcd.setCursor(0, 0);
    lcd.print("*** PNP ***");
    lcd.setCursor(0, 1);
    lcd.print(" 1=E 2=B 3=C");
  }

  //NPN  General Transistor  E-B-C ANswer
  if ((case1 == 0) and (case2 == 4) and (case3 == 1) and (case4 == 6) and (case5 == 2) and (case6 == 2) and (case7 == 0) and (case8 == 0))
  {
    Serial.println("NPN General  1=E 2=B 3=C");
    lcd.setCursor(0, 0);
    lcd.print("*** NPN ***");
    lcd.setCursor(0, 1);
    lcd.print(" 1=E 2=B 3=C");
  }

 if ((case1 == 0) and (case2 == 0) and (case3 == 1) and (case4 == 0) and (case5 == 2) and (case6 == 2) and (case7 == 0) and (case8 == 0))
  {
    Serial.println("5v Regulator 1-in 2-gnd 3-out");
    lcd.setCursor(0, 0);
    lcd.print("5V REG");
    lcd.setCursor(0, 1);
    lcd.print("1-IN 2-G 3-OUT");
  }

}


void loop() {
  // here is empty because of we need to run script once, when reset button pressed

}
