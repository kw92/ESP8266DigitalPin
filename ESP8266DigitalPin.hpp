#include <Arduino.h>
#include <Ticker.h>
#include <stdint.h>

class ESP8266DigitalPin {
  private:
    Ticker ticker;
    uint8_t pin;
    bool eventAttached = false;

  public:
    ESP8266DigitalPin(uint8_t _pin);
    virtual ~ESP8266DigitalPin();
    void setOn();
    void setOff();
    void toggle();
    void pulseOn(uint8_t period);
    void pulseOff();
};
