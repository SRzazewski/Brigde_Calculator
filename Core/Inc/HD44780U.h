#ifndef HD44780U
#define HD44780U

#include "stdint.h"

#define RESET_OUTPUT 0
#define SET_OUTPUT 1

enum interface_mode 
{
    mode_4_bits = 0x0,
    mode_8_bits = 0x1
};

enum increment_mode 
{
    decrement = 0,
    increment = 1
};

enum line_mode 
{
    one_line = 0,
    two_lines = 1
};

struct lcd_pinout
{
    uint32_t *enable_port;
    uint16_t enable_pin;
    uint32_t *rs_port;
    uint16_t rs_pin;
    uint32_t *db7_port;
    uint16_t db7_pin;
    uint32_t *db6_port;
    uint16_t db6_pin;
    uint32_t *db5_port;
    uint16_t db5_pin;
    uint32_t *db4_port;
    uint16_t db4_pin;
};

struct lcd_hd44780u
{
    enum interface_mode if_mode;
    struct lcd_pinout pinout;

    void (*delay)(uint32_t);
};

void init_lcd(struct lcd_hd44780u *lcd);
#endif
