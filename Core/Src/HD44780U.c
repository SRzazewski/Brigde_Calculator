#include "HD44780U.h"
#include "bridge_timers.h"
#include <stddef.h>

const lcd_sign_val sign_array[] = 
{
    {' ', WHITESPACE},
    {',', COMMA},
    {'.', FULL_STOP},
    {'0', NUM_0},
    {'1', NUM_1},
    {'2', NUM_2},
    {'3', NUM_3},
    {'4', NUM_4},
    {'5', NUM_5},
    {'6', NUM_6},
    {'7', NUM_7},
    {'8', NUM_8},
    {'9', NUM_9},
    {':', COLON},
    {';', SEMICOLON},
    {'A', LETTER_A},
    {'B', LETTER_B},
    {'C', LETTER_C},
    {'D', LETTER_D},
    {'E', LETTER_E},
    {'F', LETTER_F},
    {'G', LETTER_G},
    {'H', LETTER_H},
    {'I', LETTER_I},
    {'J', LETTER_J},
    {'K', LETTER_K},
    {'L', LETTER_L},
    {'M', LETTER_M},
    {'N', LETTER_N},
    {'O', LETTER_O},
    {'P', LETTER_P},
    {'Q', LETTER_Q},
    {'R', LETTER_R},
    {'S', LETTER_S},
    {'T', LETTER_T},
    {'U', LETTER_U},
    {'V', LETTER_V},
    {'W', LETTER_W},
    {'X', LETTER_X},
    {'Y', LETTER_Y},
    {'Z', LETTER_Z},
    {'a', LETTER_a},
    {'b', LETTER_b},
    {'c', LETTER_c},
    {'d', LETTER_d},
    {'e', LETTER_e},
    {'f', LETTER_f},
    {'g', LETTER_g},
    {'h', LETTER_h},
    {'i', LETTER_i},
    {'j', LETTER_j},
    {'k', LETTER_k},
    {'l', LETTER_l},
    {'m', LETTER_m},
    {'n', LETTER_n},
    {'o', LETTER_o},
    {'p', LETTER_p},
    {'q', LETTER_q},
    {'r', LETTER_r},
    {'s', LETTER_s},
    {'t', LETTER_t},
    {'u', LETTER_u},
    {'v', LETTER_v},
    {'w', LETTER_w},
    {'x', LETTER_x},
    {'y', LETTER_y},
    {'z', LETTER_z}
};

static void write_data_4_bits(struct lcd_hd44780u *lcd, uint8_t data)
{
    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db7_port, lcd->pinout.db7_pin, (0x80 & data) >> 7);
    HAL_GPIO_WritePin(lcd->pinout.db6_port, lcd->pinout.db6_pin, (0x40 & data) >> 6);
    HAL_GPIO_WritePin(lcd->pinout.db5_port, lcd->pinout.db5_pin, (0x20 & data) >> 5);
    HAL_GPIO_WritePin(lcd->pinout.db4_port, lcd->pinout.db4_pin, (0x10 & data) >> 4);
    (lcd->delay)(1000);
    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, RESET_OUTPUT);
}

void write_data(struct lcd_hd44780u *lcd, enum rs_mode rs, uint8_t data)
{
    if(lcd->interface == mode_4_bits)
    {
        HAL_GPIO_WritePin(lcd->pinout.rs_port, lcd->pinout.rs_pin, rs);
        write_data_4_bits(lcd, data);
        write_data_4_bits(lcd, data << 4);
    }
    else
    {

    }
}

void init_lcd(struct lcd_hd44780u *lcd)
{
    (void)timer_start(INIT_TIMER_40MS);
    while(!is_timer_reached(INIT_TIMER_40MS)){}
    (void)timer_reset(INIT_TIMER_40MS);

    HAL_GPIO_WritePin(lcd->pinout.rs_port, lcd->pinout.rs_pin, RESET_OUTPUT);
    write_data_4_bits(lcd, 0x30);
    (void)timer_start(INIT_TIMER_5MS);
    while(!is_timer_reached(INIT_TIMER_5MS)){}
    (void)timer_reset(INIT_TIMER_5MS);

    HAL_GPIO_WritePin(lcd->pinout.rs_port, lcd->pinout.rs_pin, RESET_OUTPUT);
    write_data_4_bits(lcd, 0x30);
    (void)timer_start(INIT_TIMER_1MS);
    while(!is_timer_reached(INIT_TIMER_1MS)){}
    (void)timer_reset(INIT_TIMER_1MS);

    HAL_GPIO_WritePin(lcd->pinout.rs_port, lcd->pinout.rs_pin, RESET_OUTPUT);
    write_data_4_bits(lcd, 0x30);
    (void)timer_start(INIT_TIMER_1MS);
    while(!is_timer_reached(INIT_TIMER_1MS)){}
    (void)timer_reset(INIT_TIMER_1MS);

    HAL_GPIO_WritePin(lcd->pinout.rs_port, lcd->pinout.rs_pin, RESET_OUTPUT);
    write_data_4_bits(lcd, 0x20);
    (void)timer_start(INIT_TIMER_1MS);
    while(!is_timer_reached(INIT_TIMER_1MS)){}
    (void)timer_reset(INIT_TIMER_1MS);

    write_data(lcd, instruction_register, 0x28);
    (void)timer_start(INIT_TIMER_1MS);
    while(!is_timer_reached(INIT_TIMER_1MS)){}
    (void)timer_reset(INIT_TIMER_1MS);

    write_data(lcd, instruction_register, 0x0E);
    (void)timer_start(INIT_TIMER_1MS);
    while(!is_timer_reached(INIT_TIMER_1MS)){}
    (void)timer_reset(INIT_TIMER_1MS);

    write_data(lcd, instruction_register, 0x06);
    (void)timer_start(INIT_TIMER_1MS);
    while(!is_timer_reached(INIT_TIMER_1MS)){}
    (void)timer_reset(INIT_TIMER_1MS);
}

void clean_display(struct lcd_hd44780u *lcd)
{
    write_data(lcd, instruction_register, 0x01);
    (lcd->delay)(1600);
}

void reset_address_counter(struct lcd_hd44780u *lcd)
{
    write_data(lcd, instruction_register, 0x02);
}

void set_address_counter(struct lcd_hd44780u *lcd, uint8_t data)
{
    if(0x80 == (0x80 & data))
    {
        write_data(lcd, instruction_register, data);
    }
}

void display_control(struct lcd_hd44780u *lcd, uint8_t data)
{
    if(0x08 == (0xF8 & data))
    {
        write_data(lcd, instruction_register, data);
    }
}

void display_string(struct lcd_hd44780u *lcd, char *string, size_t string_size)
{
    clean_display(lcd);
    if(0 < string_size)
    {
        for(size_t i = 0; i < string_size; ++i)
        {
            for(size_t j = 0; j < (sizeof(sign_array)/sizeof(lcd_sign_val)); ++j)
            {
                if(string[i] == sign_array[j].sign)
                {
                    write_data(lcd, data_register, sign_array[j].val);
                    break;
                }
            }
        }
    }
}