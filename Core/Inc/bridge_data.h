#ifndef BRIDGE_DATA_H_
#define BRIDGE_DATA_H_

#include <stdint.h>

typedef enum update_notification
{
    UPDATE_IS_NOT_NEEDED = 0,
    UPDATE_IS_NEEDED
}update_notifi;

typedef struct display_data
{
    char line1[16];
    char line2[16];
    uint8_t line1_start;
}display_data;

void display_update_needed();
void display_updated();

#endif  /* HD44780U_H_ */