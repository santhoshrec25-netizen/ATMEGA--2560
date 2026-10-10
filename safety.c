#include "safety.h"

safety_state_t safety_classify_distance(uint16_t distance_cm)
{
    /*
       Zero means the ultrasonic driver
       did not return a valid distance.
    */
    if(distance_cm == 0)
    {
        return STATE_SENSOR_FAULT;
    }

    if(distance_cm > 50)
    {
        return STATE_SAFE;
    }
    else if(distance_cm > 30)
    {
        return STATE_CAUTION;
    }
    else if(distance_cm >= 15)
    {
        return STATE_WARNING;
    }
    else
    {
        return STATE_STOP;
    }
}