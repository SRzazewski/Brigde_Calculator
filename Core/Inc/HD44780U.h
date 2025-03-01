#ifndef HD44780U_H_
#define HD44780U_H_

#include "HD44780U_A00_signs.h"
#include <stdint.h>
#include <stddef.h>

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

enum rs_mode 
{
    instruction_register = RESET_OUTPUT,
    data_register = SET_OUTPUT
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
    enum interface_mode interface;
    struct lcd_pinout pinout;

    void (*delay)(uint32_t);
};

typedef struct
{
    char sign;
    uint8_t val;
} lcd_sign_val;

void write_data(struct lcd_hd44780u *lcd, enum rs_mode rs, uint8_t data);
void init_lcd(struct lcd_hd44780u *lcd);
void clean_display(struct lcd_hd44780u *lcd);
void reset_address_counter(struct lcd_hd44780u *lcd);
void set_address_counter(struct lcd_hd44780u *lcd, uint8_t data);
void display_control(struct lcd_hd44780u *lcd, uint8_t data);
void display_string(struct lcd_hd44780u *lcd, char *string, size_t string_size);

#endif  /* HD44780U_H_ */
