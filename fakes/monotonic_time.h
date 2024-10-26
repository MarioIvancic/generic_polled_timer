// monotonic_time.h

#ifndef MONOTONIC_TIME_H_INCLUDED
#define MONOTONIC_TIME_H_INCLUDED

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void set_monotonic_time(uint32_t v);
uint32_t get_monotonic_time(void);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MONOTONIC_TIME_H_INCLUDED
