#ifndef STATE_MACHIME_H_
#define STATE_MACHIME_H_

#include "HD44780U.h"

typedef enum machine_state
{
    IDLE_STATE = 0,
    INIT_STATE,
    FULL_OP_STATE
}bc_state;

typedef struct bc_modules
{
    lcd_hd44780u *lcd;
}bc_modules;

void set_modules(lcd_hd44780u *mod_lcd);
void start_bc_state_machine();
bc_state get_bc_state();
void bc_state_machine_routine();

#endif /* STATE_MACHIME_H_ */