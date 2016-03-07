#include "ESP8266DigitalPin.hpp"

void togglePin(uint8_t pin) { digitalWrite(pin, !digitalRead(pin)); }

ESP8266DigitalPin::ESP8266DigitalPin(uint8_t _pin) {
    pin = _pin;
    pinMode(pin, OUTPUT);
    setOff();
}

ESP8266DigitalPin::~ESP8266DigitalPin() {
    if (eventAttached) {
        ticker.detach();
    }
}

void ESP8266DigitalPin::setOn() { digitalWrite(pin, HIGH); }

void ESP8266DigitalPin::setOff() { digitalWrite(pin, LOW); }

void ESP8266DigitalPin::toggle() { digitalWrite(pin, !digitalRead(pin)); }

void ESP8266DigitalPin::pulseOn(uint8_t period) {
    // you don't need to call pulseOff before period change
    if (eventAttached) {
        pulseOff();
    }

    eventAttached = true;
    ticker.attach_ms(period, togglePin, pin);
}

void ESP8266DigitalPin::pulseOff() {
    if (eventAttached) {
        ticker.detach();
        eventAttached = false;
        digitalWrite(pin, LOW);
    }
}
