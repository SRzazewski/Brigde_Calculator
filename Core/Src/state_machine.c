#include "state_machine.h"
#include "HD44780U.h"

bc_modules modules;
bc_state curr_state = IDLE_STATE;

void set_modules(lcd_hd44780u *mod_lcd)
{
    modules.lcd = mod_lcd;
}

void start_bc_state_machine()
{
    curr_state = INIT_STATE;
}

bc_state get_bc_state()
{
    return curr_state;
}

void bc_state_machine_routine()
{
    switch (curr_state)
    {
    case IDLE_STATE:
        
        break;

    case INIT_STATE:
        if (1 == init_lcd(modules.lcd))
        {
            curr_state = FULL_OP_STATE;
        }
        break;

    case FULL_OP_STATE:
        
        break;

    default:
        break;
    }
}