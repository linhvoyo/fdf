#include "fdf.h"
#include <stdio.h>


float degrees_to_radians(float degrees)
{
    float radians;

    if (degrees == 0)
        return 0;
    radians = degrees * (PI / 180);
    // printf("radiant: %f\n", radians);
    return radians;
}
