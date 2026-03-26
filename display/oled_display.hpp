#ifndef OLED_DISPLAY_HPP
#define OLED_DISPLAY_HPP
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "display.hpp"
class OLED_DISPLAY : public display{
  private:
  Adafruit_SSD1306 oled_obj;
  TwoWire i2c_obj;
  uint32_t sda;
  uint32_t scl;
  public:
   OLED_DISPLAY(uint32_t sda_pin , uint32_t scl_pin , uint8_t width, uint8_t height);
   void init() override;

   void print_string(const char* text) override;
   void println_string(const char* text) override;

   void print_char(char character) override;
   void println_char(char character) override;

  void clear() override;

  ~OLED_DISPLAY();

};
#endif