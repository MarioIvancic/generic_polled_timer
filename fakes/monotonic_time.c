// monotonic_time.c
#include "monotonic_time.h"

static uint32_t next_value;

void set_monotonic_time(uint32_t v)
{
    next_value = v;
}

uint32_t get_monotonic_time(void)
{
    return next_value;
}
