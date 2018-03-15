#include "fdf.h"
#include <stdio.h>

// void draw_line(t_mlx *mlx)
// {
//     int x;
//     int y = mlx->map->height;
//     int z;
//     int i;
//
//     x = 0;
//     while (x < mlx->map->width)
//     {
//         z = mlx->map->arr[x][0];
//
//         i = ((x + 1) * 4) + (y * mlx->img->stride);
//         i = i * (WIDTH / (mlx->map->width + 1));
//         mlx->img->img_ptr[i] = 0;
//         mlx->img->img_ptr[++i] = 0;
//         mlx->img->img_ptr[++i] = 255;
//         x++;
//     }
// }


void plot_pixel(t_mlx *mlx, int x, int y)
{
    int i;

    i = (x * 4) + (y * mlx->img->stride);
    // i = i * (WIDTH / (mlx->map->width + 1));
    i = i * 10;
    mlx->img->img_ptr[i] = 0;
    mlx->img->img_ptr[++i] = 0;
    mlx->img->img_ptr[++i] = 255;
}

void draw_line(t_mlx *mlx)
{
    int x;
    int y = mlx->map->height;
    int z;

    x = 0;
    while (x < mlx->map->width)
    {
        z = mlx->map->tmp[x][0];
        plot_pixel(mlx, x + 1, y);
        // if (z == 0)
        //     plot_pixel(mlx, x + 1, y);
        // else
        //     plot_pixel(mlx, x * 256 / z, y * 256 / z);
        x++;
    }
}
