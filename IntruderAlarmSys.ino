#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd_1(32, 16, 2);

int redLed = 8;
int buzzerPin = 7;
int pirPin = 2;

void setup() {
  // put your setup code here, to run once:
  lcd_1.init();
  lcd_1.setCursor(0, 0);
  lcd_1.backlight();
  lcd_1.display();
  lcd_1.print("Hello forks");
  delay(4000);
  lcd_1.clear();
  pinMode(redLed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(pirPin, INPUT);

  digitalWrite(redLed, LOW);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pirState = digitalRead(pirPin);
  if (pirState == HIGH) {
    // Motion detected
    digitalWrite(redLed, HIGH);
    digitalWrite(buzzerPin, HIGH);

    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Intruder Alert!");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Motion Detected");
    delay(1000);
  } else {
    // No motion
    digitalWrite(redLed, LOW);
    digitalWrite(buzzerPin, LOW);

    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Monitoring...");
    delay(1000);
  }
}
