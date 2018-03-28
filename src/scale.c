#include "fdf.h"
#include <stdio.h>

void set_scale(t_map *map)
{
    if (map->width >= map->height)
        map->scale_factor = 600 / map->width;
    else
        map->scale_factor = 600 / map->height;
}
