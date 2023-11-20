#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin definitions
const int gasSensorPin = A0;   // Analog pin for MQ-5 sensor
const int buzzerPin = 8;       // Digital pin for the buzzer
const int greenLedPin = 9;     // Digital pin for green LED
const int redLedPin = 10;      // Digital pin for red LED

// Threshold value for gas detection
const int threshold = 300;    // Adjust this value according to your needs

// Initialize the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Change 0x27 to your display's address

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  lcd.init();                      // Initialize the LCD
  lcd.backlight();                 // Turn on the backlight
  lcd.setCursor(0, 0);
  lcd.print("Gas Value: ");
  Serial.begin(9600);
}

void loop() {
  int gasValue = analogRead(gasSensorPin);

  // Display the gas value on the LCD
  lcd.setCursor(11, 0);
  lcd.print("     "); // Clear the previous reading
  lcd.setCursor(11, 0);
  lcd.print(gasValue);

  // Print the gas value to the serial monitor
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  // Check if the gas value is above the threshold
  if (gasValue > threshold) {
    // Gas detected, activate the buzzer and red LED
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
  } else {
    // No gas detected, turn off the buzzer and red LED, turn on the green LED
    digitalWrite(buzzerPin, LOW);
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
  }

 
