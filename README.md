# PIR Motion Intruder Alarm System

## 📌 Introduction
This project is a simple security system built with **Arduino Uno**.  
It uses a **PIR sensor** to detect motion. When an intruder is detected:  
- A **buzzer** sounds,  
- A **red LED** lights up,  
- An **LCD** displays "Intruder Alert!".  

When no motion is detected, the LCD shows "Monitoring...".

---

## 🎯 Objective
- Detect unauthorized entry using a PIR sensor.  
- Trigger alarms (buzzer + LED) when motion is detected.  
- Display warning messages on LCD for user awareness.  

---

## 🔧 Components
- Arduino Uno  
- PIR Motion Sensor  
- Buzzer  
- Red LED + Resistor (220Ω)  
- LCD 16x2 with I2C module  
- Breadboard + Jumper wires  

---

## 🔌 Circuit Connections
- **PIR Sensor**:  
  - VCC → 5V  
  - GND → GND  
  - OUT → Pin 2  

- **Buzzer**:  
  - + → Pin 7  
  - – → GND  

- **LED**:  
  - Anode (+) → Pin 8 (with 220Ω resistor)  
  - Cathode (–) → GND  

- **LCD (I2C)**:  
  - GND → GND  
  - VCC → 5V  
  - SDA → A4  
  - SCL → A5  

---

## 💻 Arduino Code
```ino
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd_1(0x27, 16, 2);

int redLed = 8;
int buzzerPin = 7;
int pirPin = 2;

void setup() {
  lcd_1.init();
  lcd_1.backlight();
  lcd_1.setCursor(0, 0);
  lcd_1.print("System Ready");
  delay(3000);
  lcd_1.clear();

  pinMode(redLed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(pirPin, INPUT);

  digitalWrite(redLed, LOW);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  int pirState = digitalRead(pirPin);

  if (pirState == HIGH) {
    digitalWrite(redLed, HIGH);
    digitalWrite(buzzerPin, HIGH);

    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Intruder Alert!");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Motion Detected");
    delay(500);
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(buzzerPin, LOW);

    lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Monitoring...");
    delay(500);
  }
}
