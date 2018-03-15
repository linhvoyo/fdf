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
// void rotation(t_map *map, int **coord)
// {
//     int i = 0;
//     double x;
//     double y;
//     double z;
//
//     while (i < map->width * map->height)
//     {
//         printf("x: %d y: %d z: %d color: %d\n", i % map->width, i / (map->width), map->coords[i][0], map->coords[i][1]);
//
//         x = i % map->width;
//         y = i / (map->width);
//
//         r_x = cos()
//         plot_pixel(mlx, i % map->width, i / (map->width));
//         i++;
//     }
//
//
// }




void plot_pixel(t_mlx *mlx, int x, int y)
{
    int i;
    float scale_factor = 10;
    // if (mlx->map->width >= mlx->map->height)
    //     scale_factor = 600 / mlx->map->width;
    // else
    //     scale_factor = 600 / mlx->map->height;
    //
    // printf("%f", scale_factor);
    //
    float screen_x = scale_factor * x + WIDTH / 2;
    float screen_y = HEIGHT / 2 - scale_factor * y;


    i = (screen_x * 4) + (screen_y * mlx->img->stride);
    // i = (x * 4) + (y * mlx->img->stride);
    // i = i * (WIDTH / (mlx->map->width + 1));
    // if (mlx->map->height >= mlx->map->height)


    // i = x + y * WIDTH;
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
