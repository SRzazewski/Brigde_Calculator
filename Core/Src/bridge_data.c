#include "bridge_data.h"

update_notifi update_display = UPDATE_IS_NOT_NEEDED;
display_data data_to_display;

void display_update_needed(display_data data)
{
    data_to_display = data;
    update_display = UPDATE_IS_NEEDED;
}

void display_updated()
{
    update_display = UPDATE_IS_NEEDED;
}