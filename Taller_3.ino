#include <LiquidCrystal.h>

const int ledPin = 13; 
const int motorPin = 10;
const int temperaturaPin = A0;

int segundos = 0;
float temperaturaC = 0.0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Temp: ");
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  int lecturaTemperatura = analogRead(temperaturaPin);
  temperaturaC = (lecturaTemperatura * 5.0 * 100.0) / 1024.0;

  if (temperaturaC <= 10.0) {
    digitalWrite(ledPin, HIGH); 
    digitalWrite(motorPin, LOW); 
    delay(500);
    digitalWrite(ledPin, LOW); 
    delay(500); 
  } else if (temperaturaC >= 11.0 && temperaturaC <= 25.0) {
    digitalWrite(ledPin, LOW); 
    digitalWrite(motorPin, LOW); 
  } else {
    digitalWrite(ledPin, HIGH); 
    digitalWrite(motorPin, HIGH); 
  }

  lcd.setCursor(6, 0); 
  lcd.print(temperaturaC); 
  lcd.print(" C"); 
  lcd.setCursor(0, 1); 
  lcd.print("Segundos: ");
  lcd.print(segundos);
  delay(1000);
  segundos++; 
}
