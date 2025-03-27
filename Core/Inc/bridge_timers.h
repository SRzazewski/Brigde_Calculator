#ifndef BRIDGE_TIMERS_
#define BRIDGE_TIMERS_

#include <stdint.h>
#include <stdbool.h>

typedef struct bridge_timer
{
  uint32_t current_value;
  const uint32_t start_value;
  bool is_running;
  bool is_reached;
}bridge_timer;

typedef enum timer_err
{
    NO_ERR = 0,
    ERR_TIM_IS_RUNNING,
    ERR_TIM_IS_NOT_RUNNING,
    ERR_TIM_NOT_EXIST
}timer_err;

typedef enum bridge_timers
{
    INIT_TIMER_40MS = 0,
    INIT_TIMER_5MS,
    INIT_TIMER_1MS,
    TIMERS_NUM
}bridge_timers;

timer_err timer_start(bridge_timers timer);
timer_err timer_stop(bridge_timers timer);
bool is_timer_reached(bridge_timers timer);
timer_err timer_reset(bridge_timers timer);
timer_err timers_update();

#endif /* BRIDGE_TIMERS_ */