#include "HD44780U.h"

void init_lcd(struct lcd_hd44780u *lcd)
{
    (lcd->delay)(40000);
    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.rs_port, lcd->pinout.rs_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db7_port, lcd->pinout.db7_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db6_port, lcd->pinout.db6_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db5_port, lcd->pinout.db5_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db4_port, lcd->pinout.db4_pin, SET_OUTPUT);
    (lcd->delay)(450);
    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, RESET_OUTPUT);
	(lcd->delay)(5000);

    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.rs_port, lcd->pinout.rs_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db7_port, lcd->pinout.db7_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db6_port, lcd->pinout.db6_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db5_port, lcd->pinout.db5_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db4_port, lcd->pinout.db4_pin, SET_OUTPUT);
    (lcd->delay)(450);
    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, RESET_OUTPUT);
	(lcd->delay)(1000);

    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.rs_port, lcd->pinout.rs_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db7_port, lcd->pinout.db7_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db6_port, lcd->pinout.db6_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db5_port, lcd->pinout.db5_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db4_port, lcd->pinout.db4_pin, SET_OUTPUT);
    (lcd->delay)(450);
    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, RESET_OUTPUT);
	(lcd->delay)(1000);

    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.rs_port, lcd->pinout.rs_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db7_port, lcd->pinout.db7_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db6_port, lcd->pinout.db6_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db5_port, lcd->pinout.db5_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db4_port, lcd->pinout.db4_pin, RESET_OUTPUT);
    (lcd->delay)(450);
    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, RESET_OUTPUT);
	(lcd->delay)(1000);

    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.rs_port, lcd->pinout.rs_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db7_port, lcd->pinout.db7_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db6_port, lcd->pinout.db6_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db5_port, lcd->pinout.db5_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db4_port, lcd->pinout.db4_pin, RESET_OUTPUT);
    (lcd->delay)(450);
    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, RESET_OUTPUT);
    (lcd->delay)(450);
    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.rs_port, lcd->pinout.rs_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db7_port, lcd->pinout.db7_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db6_port, lcd->pinout.db6_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db5_port, lcd->pinout.db5_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db4_port, lcd->pinout.db4_pin, RESET_OUTPUT);
    (lcd->delay)(450);
    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, RESET_OUTPUT);
	(lcd->delay)(1000);

    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.rs_port, lcd->pinout.rs_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db7_port, lcd->pinout.db7_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db6_port, lcd->pinout.db6_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db5_port, lcd->pinout.db5_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db4_port, lcd->pinout.db4_pin, RESET_OUTPUT);
    (lcd->delay)(450);
    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, RESET_OUTPUT);
    (lcd->delay)(450);
    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.rs_port, lcd->pinout.rs_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db7_port, lcd->pinout.db7_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db6_port, lcd->pinout.db6_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db5_port, lcd->pinout.db5_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db4_port, lcd->pinout.db4_pin, RESET_OUTPUT);
    (lcd->delay)(450);
    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, RESET_OUTPUT);
	(lcd->delay)(1000);

    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.rs_port, lcd->pinout.rs_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db7_port, lcd->pinout.db7_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db6_port, lcd->pinout.db6_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db5_port, lcd->pinout.db5_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db4_port, lcd->pinout.db4_pin, RESET_OUTPUT);
    (lcd->delay)(450);
    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, RESET_OUTPUT);
    (lcd->delay)(450);
    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.rs_port, lcd->pinout.rs_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db7_port, lcd->pinout.db7_pin, RESET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db6_port, lcd->pinout.db6_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db5_port, lcd->pinout.db5_pin, SET_OUTPUT);
    HAL_GPIO_WritePin(lcd->pinout.db4_port, lcd->pinout.db4_pin, RESET_OUTPUT);
    (lcd->delay)(450);
    HAL_GPIO_WritePin(lcd->pinout.enable_port, lcd->pinout.enable_pin, RESET_OUTPUT);
	(lcd->delay)(1000);
}