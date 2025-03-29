#ifndef BRIDGE_COMMON_
#define BRIDGE_COMMON_

typedef enum step
{
    STEP_0,
    STEP_1,
    STEP_2,
    STEP_3,
    STEP_4,
    STEP_5,
    STEP_6,
    STEP_7,
    STEP_8,
    STEP_9,
    STEP_10,
    STEP_11,
    STEP_12,
    STEP_13,
    STEP_14,
    STEP_15,
    STEP_16,
    STEP_17,
    STEP_18,
    STEP_19
}step;

typedef enum module_state
{
    MODULE_IDLE_STATE = 0,
    MODULE_INIT_STATE,
    MODULE_INITIALIZED_STATE,
    MODULE_ERROR_STATE
}mod_state;

#endif /* BRIDGE_COMMON_ */