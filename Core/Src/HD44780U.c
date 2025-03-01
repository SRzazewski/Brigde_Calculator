#include "HD44780U.h"
#include "HD44780U_A00_signs.h"

#include <stddef.h>

static void write_data_4_bits(struct lcd_hd44780u *lcd, uint8_t data)
{
    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db7_port, lcd->pinout.db7_pin, (0x80 & data) >> 7);
    HAL_GPIO_WritePin(lcd->pinout.db6_port, lcd->pinout.db6_pin, (0x40 & data) >> 6);
    HAL_GPIO_WritePin(lcd->pinout.db5_port, lcd->pinout.db5_pin, (0x20 & data) >> 5);
    HAL_GPIO_WritePin(lcd->pinout.db4_port, lcd->pinout.db4_pin, (0x10 & data) >> 4);
    (lcd->delay)(450);
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
    (lcd->delay)(40000);
    HAL_GPIO_WritePin(lcd->pinout.rs_port, lcd->pinout.rs_pin, RESET_OUTPUT);
    write_data_4_bits(lcd, 0x30);
	(lcd->delay)(5000);

    HAL_GPIO_WritePin(lcd->pinout.rs_port, lcd->pinout.rs_pin, RESET_OUTPUT);
    write_data_4_bits(lcd, 0x30);
	(lcd->delay)(1000);

    HAL_GPIO_WritePin(lcd->pinout.rs_port, lcd->pinout.rs_pin, RESET_OUTPUT);
    write_data_4_bits(lcd, 0x30);
	(lcd->delay)(1000);

    HAL_GPIO_WritePin(lcd->pinout.rs_port, lcd->pinout.rs_pin, RESET_OUTPUT);
    write_data_4_bits(lcd, 0x20);
	(lcd->delay)(1000);

    write_data(lcd, instruction_register, 0x28);
	(lcd->delay)(1000);

    write_data(lcd, instruction_register, 0x0E);
	(lcd->delay)(1000);

    write_data(lcd, instruction_register, 0x06);
	(lcd->delay)(1000);
}

void clean_display(struct lcd_hd44780u *lcd)
{
    write_data(lcd, instruction_register, 0x01);
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
    if(0 < string_size)
    {
        for(size_t i = 0; i < string_size; ++i)
        {
            if(' ' == string[i])
            {
                write_data(lcd, data_register, WHITESPACE);
            }
            else if(',' == string[i])
            {
                write_data(lcd, data_register, COMMA);
            }
            else if('.' == string[i])
            {
                write_data(lcd, data_register, FULL_STOP);
            }
            else if('0' == string[i])
            {
                write_data(lcd, data_register, NUM_0);
            }
            else if('1' == string[i])
            {
                write_data(lcd, data_register, NUM_1);
            }
            else if('2' == string[i])
            {
                write_data(lcd, data_register, NUM_2);
            }
            else if('3' == string[i])
            {
                write_data(lcd, data_register, NUM_3);
            }
            else if('4' == string[i])
            {
                write_data(lcd, data_register, NUM_4);
            }
            else if('5' == string[i])
            {
                write_data(lcd, data_register, NUM_5);
            }
            else if('6' == string[i])
            {
                write_data(lcd, data_register, NUM_6);
            }
            else if('7' == string[i])
            {
                write_data(lcd, data_register, NUM_7);
            }
            else if('8' == string[i])
            {
                write_data(lcd, data_register, NUM_8);
            }
            else if('9' == string[i])
            {
                write_data(lcd, data_register, NUM_9);
            }
            else if(':' == string[i])
            {
                write_data(lcd, data_register, COLON);
            }
            else if(';' == string[i])
            {
                write_data(lcd, data_register, SEMICOLON);
            }
            else
            {

            }
        }
    }
}