// KECEPATAN CONVEYOR = 175

#include "HX711.h"
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// L298N
#define IN1 10
#define IN2 9
#define ENA 11

// Sensor Infrared
const int ir = 8;
int hasil;

// Sensor LDR
byte ldr = A2;
int nilai_ldr;

// LED HPL
int led = 13;

// Relay Vacuum Gripper
const int relay = 12;

// HX711 Load Cell
#define DOUT A0
#define CLK A1
HX711 scale(DOUT, CLK);
float calibration_factor = 1150.00;  // Nilai kalibrasi (sesuaikan dengan program kalibrasi sensor)
int GRAM;

// Servo Robot Lengan
Servo servo1;
Servo servo2;
//Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

int pos1, pos2, pos3, pos4, pos5, pos6;
int kecepatanServo = 30;
int kecepatanServoDefault = 10;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  pinMode(ir, INPUT);
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);

  // HX711 Load Cell
  scale.set_scale();
  scale.tare();

  // deklarasi pin servo
  servo1.attach(2);       // kanan kiri
  servo2.attach(3);       // maju mundur
  //servo3.attach(4);     // maju mundur
  servo4.attach(5);       // naik turun
  servo5.attach(6);       // putar
  servo6.attach(7);       // End Effector

  // posisi derajat servo (default)
  servo1.write(85);
  servo2.write(180);
  //servo3.write(90);
  servo4.write(10);
  servo5.write(120);
  servo6.write(180);
}

/*==========================================================================================*/

void conveyorJalan() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 175);
}

void conveyorBerhenti() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
}

// Posisi Default (Standby) Robot
void posisiDefault() {
  servo1.write(85);
  servo2.write(180);
  //servo3.write(90);
  servo4.write(10);
  servo5.write(120);
  servo6.write(180);
}

// Wadah A (Telur Kualitas Baik dan Besar)
void telurBaikBesar() {
  for (pos1 = 85; pos1 <= 142; pos1++){
    servo1.write(pos1);
    delay(kecepatanServo);
  }
  return;
}

void telurBaikBesarDefault() {
  for (pos1 = 142; pos1 >= 85; pos1--){
    servo1.write(pos1);
    delay(kecepatanServoDefault);
  }
  return;
}

void telurBaikBesarMajuAmbil() {
  for (pos2 = 180; pos2 >= 145; pos2--){
    servo2.write(pos2);
    delay(kecepatanServo);
  }
  return;
}

void telurBaikBesarMundurAmbil() {
  for (pos2 = 145; pos2 <= 180; pos2++){
    servo2.write(pos2);
    delay(kecepatanServo);
  }
  return;
}

void telurBaikBesarMajuLetak() {
  for (pos2 = 180; pos2 >= 138; pos2--){
    servo2.write(pos2);
    delay(kecepatanServo);
  }
  return;
}

void telurBaikBesarMundurLetak() {
  for (pos2 = 138; pos2 <= 180; pos2++){
    servo2.write(pos2);
    delay(kecepatanServo);
  }
  return;
}

void telurBaikBesarNaik() {
  for (pos4 = 13; pos4 >= 10; pos4--){
    servo4.write(pos4);
    delay(kecepatanServo);
  }
  return;
}

void telurBaikBesarTurun() {
  for (pos4 = 10; pos4 <= 13; pos4++){
    servo4.write(pos4);
    delay(kecepatanServo);
  }
  return;
}

// Wadah B (Telur Kualitas Baik dan Sedang)
void telurBaikSedang() {                  // Bergerak ke tempatnya
  for (pos1 = 88; pos1 >= 30; pos1--){
    servo1.write(pos1);
    delay(kecepatanServo);
  }
  return;
}

void telurBaikSedangDefault() {
  for (pos1 = 30; pos1 <= 88; pos1++){
    servo1.write(pos1);
    delay(kecepatanServoDefault);
  }
  return;
}

void telurBaikSedangMajuAmbil() {
  for (pos2 = 180; pos2 >= 145; pos2--){
    servo2.write(pos2);
    delay(kecepatanServo);
  }
  return;
}

void telurBaikSedangMundurAmbil() {
  for (pos2 = 145; pos2 <= 180; pos2++){
    servo2.write(pos2);
    delay(kecepatanServo);
  }
  return;
}

void telurBaikSedangMajuLetak() {
  for (pos2 = 180; pos2 >= 138; pos2--){
    servo2.write(pos2);
    delay(kecepatanServo);
  }
  return;
}

void telurBaikSedangMundurLetak() {
  for (pos2 = 138; pos2 <= 180; pos2++){
    servo2.write(pos2);
    delay(kecepatanServo);
  }
  return;
}

void telurBaikSedangNaik() {
  for (pos4 = 15; pos4 >= 10; pos4--){
    servo4.write(pos4);
    delay(kecepatanServo);
  }
  return;
}

void telurBaikSedangTurun() {
  for (pos4 = 10; pos4 <= 15; pos4++){
    servo4.write(pos4);
    delay(kecepatanServo);
  }
  return;
}

// Wadah C (Telur Kualitas Baik dan Kecil)
void telurBaikKecil() {
  for (pos1 = 88; pos1 >= 0; pos1--){
    servo1.write(pos1);
    delay(kecepatanServo);
  }
  return;
}

void telurBaikKecilDefault() {
  for (pos1 = 0; pos1 <= 88; pos1++){
    servo1.write(pos1);
    delay(kecepatanServoDefault);
  }
  return;
}

void telurBaikKecilMajuAmbil() {
  for (pos2 = 180; pos2 >= 142; pos2--){
    servo2.write(pos2);
    delay(kecepatanServo);
  }
  return;
}

void telurBaikKecilMundurAmbil() {
  for (pos2 = 142; pos2 <= 180; pos2++){
    servo2.write(pos2);
    delay(kecepatanServo);
  }
  return;
}

void telurBaikKecilMajuLetak() {
  for (pos2 = 180; pos2 >= 135; pos2--){
    servo2.write(pos2);
    delay(kecepatanServo);
  }
  return;
}

void telurBaikKecilMundurLetak() {
  for (pos2 = 135; pos2 <= 180; pos2++){
    servo2.write(pos2);
    delay(kecepatanServo);
  }
  return;
}

void telurBaikKecilNaik() {
  for (pos4 = 20; pos4 >= 10; pos4--){
    servo4.write(pos4);
    delay(kecepatanServo);
  }
  return;
}

void telurBaikKecilTurun() {
  for (pos4 = 10; pos4 <= 20; pos4++){
    servo4.write(pos4);
    delay(kecepatanServo);
  }
  return;
}

// Wadah D (Telur Kualitas Buruk)
void telurBuruk() {
  for (pos1 = 88; pos1 <= 170; pos1++){
    servo1.write(pos1);
    delay(kecepatanServo);
  }
  return;
}

void telurBurukDefault() {
  for (pos1 = 170; pos1 >= 88; pos1--){
    servo1.write(pos1);
    delay(kecepatanServoDefault);
  }
  return;
}

void telurBurukMajuAmbil() {
  for (pos2 = 170; pos2 >= 142; pos2--){
    servo2.write(pos2);
    delay(kecepatanServo);
  }
  return;
}

void telurBurukMundurAmbil() {
  for (pos2 = 142; pos2 <= 180; pos2++){
    servo2.write(pos2);
    delay(kecepatanServo);
  }
  return;
}

void telurBurukMajuLetak() {
  for (pos2 = 180; pos2 >= 135; pos2--){
    servo2.write(pos2);
    delay(kecepatanServo);
  }
  return;
}

void telurBurukMundurLetak() {
  for (pos2 = 135; pos2 <= 180; pos2++){
    servo2.write(pos2);
    delay(kecepatanServo);
  }
  return;
}

void telurBurukNaik() {
  for (pos4 = 15; pos4 >= 10; pos4--){
    servo4.write(pos4);
    delay(kecepatanServo);
  }
  return;
}

void telurBurukTurun() {
  for (pos4 = 10; pos4 <= 15; pos4++){
    servo4.write(pos4);
    delay(kecepatanServo);
  }
  return;
}

void statusTelurBaikBesar() {
  Serial.print("Telur Baik Besar");
  lcd.setCursor(0,0);
  lcd.print("LDR:");
  lcd.setCursor(4,0);
  lcd.print(nilai_ldr);
  lcd.setCursor(10,0);
  lcd.print("Baik");
  lcd.setCursor(0,1);
  lcd.print("Brt:");
  lcd.setCursor(4,1);
  lcd.print(GRAM);
  lcd.setCursor(7,1);
  lcd.print("G");
  lcd.setCursor(10,1);
  lcd.print("Besar");
}

void statusTelurBaikSedang() {
  Serial.print("Telur Baik Sedang");
  lcd.setCursor(0,0);
  lcd.print("LDR:");
  lcd.setCursor(4,0);
  lcd.print(nilai_ldr);
  lcd.setCursor(10,0);
  lcd.print("Baik");
  lcd.setCursor(0,1);
  lcd.print("Brt:");
  lcd.setCursor(4,1);
  lcd.print(GRAM);
  lcd.setCursor(7,1);
  lcd.print("G");
  lcd.setCursor(10,1);
  lcd.print("Sedang");
}

void statusTelurBaikKecil() {
  Serial.print("Telur Baik Kecil");
  lcd.setCursor(0,0);
  lcd.print("LDR:");
  lcd.setCursor(4,0);
  lcd.print(nilai_ldr);
  lcd.setCursor(10,0);
  lcd.print("Baik");
  lcd.setCursor(0,1);
  lcd.print("Brt:");
  lcd.setCursor(4,1);
  lcd.print(GRAM);
  lcd.setCursor(7,1);
  lcd.print("G");
  lcd.setCursor(10,1);
  lcd.print("Kecil");
}

void statusTelurBuruk() {
  Serial.print("Telur Buruk");
  lcd.setCursor(0,0);
  lcd.print("LDR:");
  lcd.setCursor(4,0);
  lcd.print(nilai_ldr);
  lcd.setCursor(10,0);
  lcd.print("Buruk");
}

/*==========================================================================================*/

void loop() {
  posisiDefault();

  // Mulai Pendeteksian Telur
  hasil = digitalRead(ir);
  if (hasil == LOW) {
    conveyorBerhenti();
    delay(1000);
    
    analogWrite(led, 255);
    delay(1000);
    
    nilai_ldr = analogRead(ldr);
    Serial.write(nilai_ldr);
    //Serial.println(nilai_ldr);
    delay(1000);

    // Telur Kualitas Buruk
    if (nilai_ldr > 700) {
      statusTelurBuruk();
      delay(3000);
      analogWrite(led, 0);
      delay(1000);
      conveyorJalan();
      delay(700);
      conveyorBerhenti();
      digitalWrite(relay, HIGH);
      telurBurukMajuAmbil();
      servo6.write(170);
      telurBurukTurun();
      delay(3000);
      telurBurukNaik();
      telurBurukMundurAmbil();
      telurBuruk();
      //digitalWrite(relay, HIGH);
      telurBurukMajuLetak();
      servo6.write(165);
      digitalWrite(relay, LOW);
      //delay(500);
      telurBurukMundurLetak();
      digitalWrite(relay, HIGH);
      telurBurukDefault();
      posisiDefault();
    }

    // Telur Baik
    else if (nilai_ldr > 300) {
      scale.set_scale(calibration_factor);
      GRAM = scale.get_units(), 4;
      Serial.write(GRAM);
      //Serial.println(GRAM);
      delay(1000);

      // Pengelompokan Ukuran Telur Berdasarkan Berat Telur
      // Telur Besar
      if (GRAM > 35) {
        statusTelurBaikBesar();
        delay(3000);
        analogWrite(led, 0);
        delay(1000);
        conveyorJalan();
        delay(700);
        conveyorBerhenti();
        digitalWrite(relay, HIGH);
        telurBaikBesarMajuAmbil();
        servo6.write(170);
        telurBaikBesarTurun();
        delay(3000);
        telurBaikBesarNaik();
        telurBaikBesarMundurAmbil();
        telurBaikBesar();
        //digitalWrite(relay, HIGH);
        telurBaikBesarMajuLetak();
        servo6.write(165);
        digitalWrite(relay, LOW);
        //delay(500);
        telurBaikBesarMundurLetak();
        digitalWrite(relay, HIGH);
        telurBaikBesarDefault();
        posisiDefault();
      }
      
      // Telur Sedang
      else if (GRAM > 25) {
        statusTelurBaikSedang();
        delay(3000);
        analogWrite(led, 0);
        delay(1000);
        conveyorJalan();
        delay(650);
        conveyorBerhenti();
        digitalWrite(relay, HIGH);
        telurBaikSedangMajuAmbil();
        servo6.write(175);
        telurBaikSedangTurun();
        delay(3000);
        telurBaikSedangNaik();
        telurBaikSedangMundurAmbil();
        telurBaikSedang();
        //digitalWrite(relay, HIGH);
        telurBaikSedangMajuLetak();
        servo6.write(165);
        digitalWrite(relay, LOW);
        //delay(500);
        telurBaikSedangMundurLetak();
        digitalWrite(relay, HIGH);
        telurBaikSedangDefault();
        posisiDefault();
      }

      // Telur Kecil
      else if (GRAM > 5) {
        statusTelurBaikKecil();
        delay(3000);
        analogWrite(led, 0);
        delay(1000);
        conveyorJalan();
        delay(620);
        conveyorBerhenti();
        digitalWrite(relay, HIGH);
        telurBaikKecilMajuAmbil();
        servo6.write(175);
        telurBaikKecilTurun();
        delay(3000);
        telurBaikKecilNaik();
        telurBaikKecilMundurAmbil();
        telurBaikKecil();
        //digitalWrite(relay, HIGH);
        telurBaikKecilMajuLetak();
        servo6.write(165);
        digitalWrite(relay, LOW);
        //delay(500);
        telurBaikKecilMundurLetak();
        digitalWrite(relay, HIGH);
        telurBaikKecilDefault();
        posisiDefault();
      }
      lcd.clear();
    }

    else {
      lcd.setCursor(0,0);
      lcd.print("Telur Tidak Pas");
      lcd.setCursor(0,1);
      lcd.print("Pada Posisinya");
      delay(2000);
      conveyorJalan();
    }
    lcd.clear();
  }
  
  if (hasil == HIGH) {
    digitalWrite(led, LOW);
    lcd.setCursor(0,0);
    lcd.print("");
    conveyorJalan();
  }
  //delay(100);
}
