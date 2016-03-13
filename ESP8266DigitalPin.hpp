#include <Arduino.h>
#include <Ticker.h>
#include <stdint.h>

class ESP8266DigitalPin {
  private:
    Ticker ticker;
    uint8_t pin;
    bool eventAttached = false;
    uint8_t onState = HIGH;

  public:
    ESP8266DigitalPin(uint8_t _pin, uint8_t _onState = HIGH);
    virtual ~ESP8266DigitalPin();
    void setOn();
    void setOff();
    void toggle();
    void pulseOn(uint16_t period);
    void pulseOff();

  private:
    bool detachEvent();
};
