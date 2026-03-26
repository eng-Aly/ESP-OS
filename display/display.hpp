#ifndef DISPLAY_HPP
#define DISPLAY_HPP
class display{
    public:
    virtual void init();

    virtual void print_string(const char* text);
    virtual void println_string(const char* text);
   
    virtual void print_char(char character);
    virtual void println_char(char character);
    virtual void clear();

    virtual ~display();
};
#endif