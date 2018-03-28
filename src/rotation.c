#include "fdf.h"
#include <stdio.h>


float degrees_to_radians(float degrees)
{
    float radians;

    radians = degrees * (PI / 180);
    return radians;
}
