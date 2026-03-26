#include "oled_display.hpp"

OLED_DISPLAY::OLED_DISPLAY(uint32_t sda_pin , uint32_t scl_pin , uint8_t width, uint8_t height) : i2c_obj(0) ,oled_obj(width,height,&this->i2c_obj),sda(sda_pin),scl(scl_pin){

};

void OLED_DISPLAY::init() {
  i2c_obj.begin(sda,scl);
  // Initialize the SSD1306 display (address 0x3C is common)
  if(!oled_obj.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C or 0x3D
    this->~OLED_DISPLAY();
  }
  oled_obj.clearDisplay();
  oled_obj.setTextSize(1);
  oled_obj.setTextColor(SSD1306_WHITE);
  oled_obj.setCursor(0,0);
}


OLED_DISPLAY::~OLED_DISPLAY(){
  this->i2c_obj.~TwoWire();
  this->oled_obj.~Adafruit_SSD1306();

}
void OLED_DISPLAY::print_string(const char *text){
  oled_obj.print(*text);
  oled_obj.display(); 
}

void OLED_DISPLAY::println_string(const char *text){
  oled_obj.println(*text);
  oled_obj.display();   //will be modified
}

void OLED_DISPLAY::print_char(char character){
  oled_obj.print(character);
  oled_obj.display(); 
}

void OLED_DISPLAY::println_char(char character){
  oled_obj.println(character);
  oled_obj.display();   //will be modified
}


void OLED_DISPLAY::clear(){
  oled_obj.clearDisplay();
  oled_obj.display();   //will be modified
}