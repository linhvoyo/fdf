#include "fdf.h"
#include <stdio.h>

void set_scale(t_map *map)
{
    int width;
    int height;

    width = WIDTH / (map->width * 2);

    if (map->d_max > map->height)
        height = HEIGHT / (map->d_max * 2);
    else
        height = HEIGHT / (map->height * 2);

    if (height <= width)
        map->scale_factor = height;
    else
        map->scale_factor = width;

    if (map->scale_factor < 1)
        map->scale_factor = 1;
    // if (map->width >= map->height)
    //     map->scale_factor = 600 / map->width;
    // else
    //     map->scale_factor = 600 / map->height;
}
