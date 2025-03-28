#ifndef BRIDGE_TIMERS_
#define BRIDGE_TIMERS_

#include <stdint.h>
#include <stdbool.h>

#define STEP_DELAY 1

#define INIT_TIMER_40MS_TIME            (40 - STEP_DELAY)
#define INIT_TIMER_5MS_TIME             (5 - STEP_DELAY)
#define INIT_TIMER_1MS_TIME             (1 - STEP_DELAY)
#define CLEAN_DISPLAY_TIMER_TIME        (2 - STEP_DELAY)
#define WRITE_DATA_4_BITS_TIMER_TIME    (1 - STEP_DELAY)
#define ADC_MESUR_TIMER_TIME            (50)

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
    CLEAN_DISPLAY_TIMER,
    WRITE_DATA_4_BITS_TIMER,
    ADC_MESUR_TIMER,
    TIMERS_NUM
}bridge_timers;

timer_err timer_start(bridge_timers timer);
timer_err timer_stop(bridge_timers timer);
bool is_timer_reached(bridge_timers timer);
timer_err timer_reset(bridge_timers timer);
timer_err timers_update();

#endif /* BRIDGE_TIMERS_ */