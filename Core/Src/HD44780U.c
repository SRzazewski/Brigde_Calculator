#include "HD44780U.h"

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