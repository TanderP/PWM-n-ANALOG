#include <Arduino.h>


#define ledPin 27 // The PWM pin connected to the LED


int brightness = 0; // Initialize brightness to 0 (off)
int fadeAmount = 5; // Amount to change brightness

void setup() {
  Serial.begin(115200);
  Serial.println("ESP START");
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
}

void loop() {
  analogWrite(ledPin, brightness); // Set the LED brightness (0-255)

  brightness = brightness + fadeAmount; // Change the brightness
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount; // Reverse the fade direction
  }
  
  delay(30); // Wait 30 milliseconds to see the dimming effect
}