#include "ESP8266DigitalPin.hpp"

void togglePin(uint8_t pin) { digitalWrite(pin, !digitalRead(pin)); }

ESP8266DigitalPin::ESP8266DigitalPin(uint8_t _pin) {
    pin = _pin;
    pinMode(pin, OUTPUT);
    setOff();
}

ESP8266DigitalPin::~ESP8266DigitalPin() {
    detachEvent();
    pinMode(pin, INPUT);
}

void ESP8266DigitalPin::setOn() {
    detachEvent();
    digitalWrite(pin, HIGH);
}

void ESP8266DigitalPin::setOff() {
    detachEvent();
    digitalWrite(pin, LOW);
}

void ESP8266DigitalPin::toggle() { digitalWrite(pin, !digitalRead(pin)); }

void ESP8266DigitalPin::pulseOn(uint16_t period) {
    // you don't need to call pulseOff before period change
    detachEvent();

    eventAttached = true;
    ticker.attach_ms(period, togglePin, pin);
}

void ESP8266DigitalPin::pulseOff() {
    detachEvent();
    digitalWrite(pin, LOW);
}

bool ESP8266DigitalPin::detachEvent() {
    if (eventAttached) {
        ticker.detach();
        eventAttached = false;
        return true;
    }
    return false;
}
