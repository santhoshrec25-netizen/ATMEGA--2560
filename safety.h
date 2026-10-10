#ifndef SAFETY_H
#define SAFETY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef enum
{
    STATE_SAFE,
    STATE_CAUTION,
    STATE_WARNING,
    STATE_STOP,
    STATE_SENSOR_FAULT
} safety_state_t;

safety_state_t safety_classify_distance(uint16_t distance_cm);

#ifdef __cplusplus
}
#endif
#endif