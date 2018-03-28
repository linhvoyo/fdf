#include "fdf.h"
#include <stdio.h>


void plot_pixel(t_mlx *mlx, int x, int y)
{
    int i;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;

    i = (x * 4) + (y * mlx->img->stride);
    mlx->img->img_ptr[i] = 0;
    mlx->img->img_ptr[++i] = 0;
    mlx->img->img_ptr[++i] = 255;
}


int sign(int x)
{
    if (x > 0)
        return (1);
    else if (x < 0)
        return (-1);
    else
        return (0);

}

void draw_line(t_mlx *mlx, int x1, int y1, int x2, int y2)
{
    int x;
    int y;
    int dx;
    int dy;
    int swap;
    int temp;
    int s1;
    int s2;
    int p;
    int i;

    x = x1;
    y = y1;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    s1 = sign(x2 - x1);
    s2 = sign(y2 - y1);
    swap = 0;
    plot_pixel(mlx, x1, y1);
    if (dy > dx)
    {
        temp = dx;
        dx = dy;
        dy = temp;
        swap = 1;
    }
    p = 2 * dy - dx;
    i = 0;
    while (i < dx)
    {
        plot_pixel(mlx,x,y);
        while (p >= 0)
        {
            p = p - 2 * dx;
            if (swap)
                x += s1;
            else
                y += s2;
        }
        p = p + 2 * dy;
        if (swap)
            y = y + s2;
        else
            x = x + s1;
        i++;
    }
    plot_pixel(mlx,x2,y2);
    // mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img->img, 0 , 0);
}


// if (row < map->width && y < map->height)
// {
//     printf("x: %f y: %f \n", x, y);
//     printf("x2: %f y2: %f \n", x , y + 1);
//     row++;
// }
// else if (row == map->width)
// {
//     printf("\n");
//     row = 0;
//     i--;
// }


void transform(t_mlx *mlx, float *coord, int i)
{
    float x;
    float y;
    float z;
    float theta;

    x = i % mlx->map->width;
    y = i / mlx->map->width;
    z = mlx->map->coords[i][0];

    //scale image
    x = x * mlx->map->scale_factor;
    y = y * mlx->map->scale_factor;
    z = z * mlx->map->scale_factor;

    //rotate_x;
    theta = degrees_to_radians(mlx->map->degrees_x);
    y = y * cos(theta) - z * sin(theta);
    z = y * cos(theta) + z * sin(theta);

    //rotate_y:
    theta = degrees_to_radians(mlx->map->degrees_y);
    x = x * cos(theta) + z * sin(theta);
    z = -(x * sin(theta)) + z * cos(theta);

    //rotate_z;
    theta = degrees_to_radians(mlx->map->degrees_z);
    x = x * cos(theta) - y * sin(theta);
    y = y * sin(theta) + y * cos(theta);

    // center
    x = x + WIDTH / 2 - (mlx->map->width * mlx->map->scale_factor / 2) + mlx->map->offset_x;
    // y = HEIGHT / 2 + y + mlx->map->offset_y;
    y = HEIGHT / 2 + (mlx->map->height * mlx->map->scale_factor / 2) + y + mlx->map->offset_y;

    coord[0] = x;
    coord[1] = y;
    coord[2] = z;

}

void render(t_mlx *mlx)
{
    float *coord_current;
    float *coord_next;
    int i;
    int row;
    int column;

    coord_current = malloc(sizeof(float) * 4);
    coord_next = malloc(sizeof(float) * 4);

    i = 0;
    row = 0;
    column = 0;
    clear_image(mlx->img);

    printf("degrees_x %f degrees_y %f degrees_z %f\n", mlx->map->degrees_x, mlx->map->degrees_y, mlx->map->degrees_z);
    while (i < mlx->map->width * mlx->map->height)
    {
        transform(mlx, coord_current, i);
        if ((row < mlx->map->width) && (column < mlx->map->height))
        {
            if (row != mlx->map->width - 1)
            {
                transform(mlx, coord_next, i + 1);
                draw_line(mlx, coord_current[0], coord_current[1], coord_next[0], coord_next[1]);
                // printf("x: %f y: %f \n", coord_current[0], coord_current[1]);
            }
            if ((row != mlx->map->width) && (column != mlx->map->height - 1))
            {
                transform(mlx, coord_next, i + mlx->map->width);
                draw_line(mlx, coord_current[0], coord_current[1], coord_next[0], coord_next[1]);
                // printf("x: %f y: %f \n", coord_next[0], coord_next[1]);
            }
            row++;
        }
        if (row == mlx->map->width && (column = column + 1))
            row = 0;
        i++;
    }
    free(coord_current);
    free(coord_next);
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img->img, 0 , 0);
}
