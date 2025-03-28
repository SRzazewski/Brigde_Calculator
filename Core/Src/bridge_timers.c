#include "bridge_timers.h"
#include <stdbool.h>

bridge_timer timers[] = 
{
/*current_value,start_value,                is_running, is_counted*/
    {0,         INIT_TIMER_40MS_TIME,           false,      false}, //INIT_TIMER_40MS
    {0,         INIT_TIMER_5MS_TIME,            false,      false}, //INIT_TIMER_5MS
    {0,         INIT_TIMER_1MS_TIME,            false,      false}, //INIT_TIMER_1MS
    {0,         CLEAN_DISPLAY_TIMER_TIME,       false,      false}, //CLEAN_DISPLAY_TIMER
    {0,         WRITE_DATA_4_BITS_TIMER_TIME,   false,      false}, //WRITE_DATA_4_BITS_TIMER
    {0,         ADC_MESUR_TIMER_TIME,           false,      false}  //WRITE_DATA_4_BITS_TIMER
};

timer_err timer_start(bridge_timers timer)
{
    if (timer >= TIMERS_NUM)
    {
        return ERR_TIM_NOT_EXIST;
    }

    if (false != timers[timer].is_running)
    {
        return ERR_TIM_IS_RUNNING;
    }

    timers[timer].current_value = timers[timer].start_value;
    timers[timer].is_running = true;
    timers[timer].is_reached = false;

    return NO_ERR;
}

timer_err timer_stop(bridge_timers timer)
{
    if (timer >= TIMERS_NUM)
    {
        return ERR_TIM_NOT_EXIST;
    }

    timers[timer].is_running = false;

    return NO_ERR;
}

bool is_timer_reached(bridge_timers timer)
{
    return timers[timer].is_reached;
}

timer_err timer_reset(bridge_timers timer)
{
    if (timer >= TIMERS_NUM)
    {
        return ERR_TIM_NOT_EXIST;
    }

    timers[timer].current_value = 0;
    timers[timer].is_running = false;
    timers[timer].is_reached = false;

    return NO_ERR;
}

timer_err timers_update()
{
    for (uint8_t i = 0; i < TIMERS_NUM; ++i)
    {
        if (true == timers[i].is_running)
        {
            if  (0 == timers[i].current_value)
            {
                timers[i].is_reached = true;
            }
            else
            {
                timers[i].current_value--;
            }
        }
    }

    return NO_ERR;
}