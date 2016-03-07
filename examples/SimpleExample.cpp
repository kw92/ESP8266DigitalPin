#include "ESP8266DigitalPin.hpp"

#define BUZZER_PIN 0

ESP8266DigitalPin buzzer(BUZZER_PIN);

void setup() {
    buzzer.setOn();
    delay(5000);
    buzzer.setOff();
    delay(5000);
    buzzer.pulseOn(100); // 100ms on, 100ms off
    delay(5000);
    buzzer.pulseOff();
}

void loop() {}
