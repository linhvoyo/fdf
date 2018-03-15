#include "fdf.h"
#include <stdio.h>

void rotate_z(t_mlx *mlx, float theta)
{
    float x;
    float y;

    int i;

    i = 0;
    while (i < mlx->map->width * mlx->map->height)
    {
        x = i % mlx->map->width;
        y = i / mlx->map->width;
        plot_pixel(mlx, x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta));
        i++;
    }
}
//
// void rotate_y(t_mlx *mlx)
// {
//     float x;
//     float z;
//
//     int i;
//
//     i = 0;
//     while (i < mlx->map->width * mlx->map->height)
//     {
//         x = i % mlx->map->width;
//         y = i / mlx->map->width;
//         plot_pixel(mlx, x * cos(0.0524) + z * sin(0.0524), -(x * sin(0.0524)) + z * cos(0.0524));
//         i++;
//     }
// }

void rotate(t_mlx *mlx)
{
    clear_image(mlx->img);
    rotate_z(mlx, 0.5854);
}
