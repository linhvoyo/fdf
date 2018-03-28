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

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;


    // float scale_factor = 10;
    // // if (mlx->map->width >= mlx->map->height)
    // //     scale_factor = 600 / mlx->map->width;
    // // else
    // //     scale_factor = 600 / mlx->map->height;
    // //
    // // printf("%f", scale_factor);
    // //
    // float screen_x = scale_factor * x + WIDTH / 2;
    // float screen_y = HEIGHT / 2 - scale_factor * y;

    i = (x * 4) + (y * mlx->img->stride);
    // i = (x * 4) + (y * mlx->img->stride);
    // i = i * (WIDTH / (mlx->map->width + 1));
    // if (mlx->map->height >= mlx->map->height)

    // i = x + y * WIDTH;
    mlx->img->img_ptr[i] = 0;
    mlx->img->img_ptr[++i] = 0;
    mlx->img->img_ptr[++i] = 255;
}


// void draw_line(t_mlx *mlx)
// {
//     int x;
//     int y = mlx->map->height;
//     int z;
//
//     x = 0;
//     while (x < mlx->map->width)
//     {
//         z = mlx->map->tmp[x][0];
//         plot_pixel(mlx, x + 1, y);
//         // if (z == 0)
//         //     plot_pixel(mlx, x + 1, y);
//         // else
//         //     plot_pixel(mlx, x * 256 / z, y * 256 / z);
//         x++;
//     }
// }

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

// void draw_line(t_mlx *mlx, int x1, int y1, int x2, int y2)
// {
//     int dx;
//     int dy;
//     int temp;
//     int x;
//     int y;
//
//     dx = x2 - x1;
//     dy = y2 - y1;
//
//     x = x1;
//     y = y1;
//
//     temp = 2 * dy - dx;
//     while (x < x2)
//     {
//         if (temp < 0)
//             temp = temp + 2 * dy;
//         else
//         {
//             y = y + 1;
//             temp = temp + 2 * dy - 2 * dx;
//         }
//         plot_pixel(mlx, x, y);
//         x++;
//     }
//     mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img->img, 0 , 0);
// }


// void draw_line(t_mlx *mlx, int x1, int y1, int x2, int y2)
// {
//     float rise;
//     float run;
//     float tmp;
//     float m;
//
//     float adjust;
//     float offset;
//     float threshold;
//     float delta;
//     int y;
//     int x;
//
//     rise = y2 - y1;
//     run = x2 - x1;
//     if (run == 0)
//     {
//         if (y2 < y1)
//         {
//             tmp = y1;
//             y1 = y2;
//             y2 = tmp;
//         }
//         while (y1 <= y2)
//             plot_pixel(mlx, x1, y1++);
//     }
//     else
//     {
//         m = rise / run;
//         if (m >= 0)
//             adjust = 0;
//         else
//             adjust = -1;
//         offset = 0;
//         threshold = 0.5;
//         if (m <= 1 && m >= -1)
//         {
//             delta = fabsf(m);
//             y = y1;
//             if (x2 < x1)
//             {
//                 tmp = x1;
//                 x1 = x2;
//                 x2 = x1;
//                 y = y2;
//             }
//             while (x1 < x2)
//             {
//                 plot_pixel(mlx, x1++, y);
//                 offset = offset + delta;
//                 if (offset >= threshold)
//                 {
//                     y = y + adjust;
//                     threshold = threshold + 1;
//                 }
//             }
//         }
//         else
//         {
//             delta = fabsf(run / rise);
//             x = x1;
//             if (y2 < y1)
//             {
//                 tmp = y1;
//                 y1 = y2;
//                 y2 = y1;
//                 x = x2;
//             }
//             while (y1 < y2)
//             {
//                 plot_pixel(mlx, x, y1++);
//                 offset = offset + delta;
//                 if (offset >= threshold)
//                 {
//                     x = x + adjust;
//                     threshold = threshold + 1;
//                 }
//             }
//         }
//     }
//     mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img->img, 0 , 0);
// }

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

float x_coor(t_mlx *mlx, int i)
{
    float x = i % mlx->map->width;

    //scale
    x = x * mlx->map->scale_factor;

    //center
    x = x + WIDTH / 2 - (mlx->map->width * mlx->map->scale_factor) /2;


    return (x);
}

float z_coor(t_mlx *mlx, int i)
{
    float z = mlx->map->coords[i][0];

    //scale
    z = z * mlx->map->scale_factor;


    return (z);
}

float y_coor(t_mlx *mlx, int i)
{
    float y;
    float theta;

    y = i / mlx->map->width;

    //scale
    y = y * mlx->map->scale_factor;

    //center
    y = HEIGHT / 2 + y;

    // //rotate_x
    // theta = degrees_to_radians(90);
    //
    // y = y * cos(theta) - z_coor(mlx, i) * sin(theta);

    return (y);
}

// void plot_coor(t_mlx *mlx, int i)
// {
//     float x;
//     float y;
//     float z;
//     float theta;
//
//     x = i % mlx->map->width;
//     y = i / mlx->map->width;
//     z = mlx->map->coords[i][0];
//
//     //scale image
//     x = x * mlx->map->scale_factor;
//     y = y * mlx->map->scale_factor;
//     z = z * mlx->map->scale_factor;
//
//     //center
//     x = x + WIDTH / 2 - (mlx->map->width * mlx->map->scale_factor) /2;
//     y = HEIGHT / 2 + y;
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
    theta = degrees_to_radians(90);
    y = y * cos(theta) - z * sin(theta);
    z = y * cos(theta) + z * sin(theta);

    //center
    x = x + WIDTH / 2 - (mlx->map->width * mlx->map->scale_factor) /2;
    y = HEIGHT / 2 + y;

    coord[0] = x;
    coord[1] = y;
    coord[2] = z;

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
    while (i < mlx->map->width * mlx->map->height)
    {

        transform(mlx, coord_current, i);
        plot_pixel(mlx, coord_current[0], coord_current[1]);

        if ((row < mlx->map->width) && (column < mlx->map->height))
        {
            if (row != mlx->map->width - 1)
            {
                transform(mlx, coord_next, i + 1);
                draw_line(mlx, coord_current[0], coord_current[1], coord_next[0], coord_next[1]);
                printf("x: %f y: %f \n", coord_current[0], coord_current[1]);
            }
            if ((row != mlx->map->width) && (column != mlx->map->height - 1))
            {
                transform(mlx, coord_next, i + mlx->map->width);
                draw_line(mlx, coord_current[0], coord_current[1], coord_next[0], coord_next[1]);
                printf("x: %f y: %f \n", coord_next[0], coord_next[1]);
            }
            row++;
        }
        if (row == mlx->map->width)
        {
            printf("zero\n");
            row = 0;
            column++;
        }
        i++;
    }
    free(coord_current);
    free(coord_next);
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img->img, 0 , 0);
}
//

// void render(t_mlx *mlx)
// {
//     float x;
//     float y;
//     float z;
//     float theta;
//     int i;
//     int row;
//     int column;
//
//     clear_image(mlx->img);
//     printf("render scale_factor: %f\n", mlx->map->scale_factor);
//     i = 0;
//     row = 0;
//     column = 0;
//
//     float y_column;
//
//     float x_below;
//     float y_below;
//     float x2;
//     float y2;
//     // mlx->map->scale_factor = 1;
//     while (i < mlx->map->width * mlx->map->height)
//     {
//         x = i % mlx->map->width;
//         y = i / mlx->map->width;
//         z = mlx->map->coords[i][0];
//         y_column = y + 1;
//
//         // //scale image
//         // x = x * mlx->map->scale_factor;
//         // y = y * mlx->map->scale_factor;
//         // z = z * mlx->map->scale_factor;
//         // y_column = y_column * mlx->map->scale_factor;
//
//
//
//         //draw_line(mlx, x_coor(mlx, i), y_coor(mlx, i), x_coor(mlx, i + 1), y_coor(mlx, i + 1));
//
//
//
//         // // x = x_coor(mlx, i);
//         // // y = y_coor(mlx, i);
//         //
//         // x = i % mlx->map->width;
//         // y = i / mlx->map->width;
//         // z = mlx->map->coords[i][0];
//         // // z = mlx->map->coords[i][0];
//         // // y_column = y + 1;
//         //
//         //
//         // // x2 = x_coor(mlx, i + 1);
//         // // y2 = y_coor(mlx, i + 1);
//         // x2 = (i + 1) % mlx->map->width;
//         // y2 = (i + 1) / mlx->map->width;
//         //
//         // // x_below = x_coor(mlx, i + mlx->map->width);
//         // // y_below = y_coor(mlx, i + mlx->map->width);
//         //
//         // x_below = (i + mlx->map->width) % mlx->map->width;
//         // y_below = (i + mlx->map->width) / mlx->map->width;
//         //
//         //
//         // //scale image
//         // x = x * mlx->map->scale_factor;
//         // y = y * mlx->map->scale_factor;
//         // z = z * mlx->map->scale_factor;
//         // x2 = x2 * mlx->map->scale_factor;
//         // y2 = y2 * mlx->map->scale_factor;
//         // x_below = x_below * mlx->map->scale_factor;
//         // y_below = y_below * mlx->map->scale_factor;
//         //
//         // //center
//         // x = x + WIDTH / 2 - (mlx->map->width * mlx->map->scale_factor) /2;
//         // x2 = x2 + WIDTH / 2 - (mlx->map->width * mlx->map->scale_factor) /2;
//         // x_below = x_below + WIDTH / 2 - (mlx->map->width * mlx->map->scale_factor) /2;
//         // y = HEIGHT / 2 + y;
//         // y2 = HEIGHT / 2 + y2;
//         // y_below = HEIGHT / 2 + y_below;
//         //
//         // //rotate_x;
//         // theta = degrees_to_radians(90);
//         // y = y * cos(theta) - z * sin(theta);
//         // y2 = y2 * cos(theta) - z * sin(theta);
//         // y_below = y_below * cos(theta) - z * sin(theta);
//         //
//         //
//         // if (row < mlx->map->width && column < mlx->map->height)
//         // {
//         //     if (row != mlx->map->width - 1)
//         //     {
//         //         // draw_line(mlx, x_coor(mlx, i), y_coor(mlx, i), x_coor(mlx, i + 1), y_coor(mlx, i + 1));
//         //
//         //
//         //         draw_line(mlx, x, y, x2, y2);
//         //         // if (column != mlx->map->height - 1)
//         //         //     draw_line(mlx, x_coor(mlx, i), y_coor(mlx, i), x_coor(mlx, i + mlx->map->width), y_coor(mlx, i + mlx->map->width));
//         //         printf("x: %f y: %f \n", x_coor(mlx, i), y_coor(mlx,i));
//         //     }
//         //     if (column != mlx->map->height - 1)
//         //     {
//         //         draw_line(mlx, x, y, x_below, y_below);
//         //     }
//         //         // draw_line(mlx, x_coor(mlx, i), y_coor(mlx, i), x_coor(mlx, i + mlx->map->width), y_coor(mlx, i + mlx->map->width));
//         //     // printf("x2: %f y2: %f \n", x , y + 1);
//         //     row++;
//         // }
//         // else if (row == mlx->map->width)
//         // {
//         //     printf("\n");
//         //     row = 0;
//         //     column++;
//         //     printf("%d\n", column);
//         //     i--;
//         // }
//
//
//
//
//         float x_prev;
//         float y_prev;
//         if ((row < mlx->map->width) && y <= mlx->map->height)
//         {
//             //scale image
//             x = x * mlx->map->scale_factor;
//             y = y * mlx->map->scale_factor;
//             z = z * mlx->map->scale_factor;
//             y_column = y_column * mlx->map->scale_factor;
//
//             //rotate_x;
//             theta = degrees_to_radians(90);
//             y = y * cos(theta) - z * sin(theta);
//             z = y * cos(theta) + z * sin(theta);
//             y_column = y_column * cos(theta) - z * sin(theta);
//
//             x = x + WIDTH / 2 - (mlx->map->width * mlx->map->scale_factor) /2;
//             y = HEIGHT / 2 + y;
//             y_column = HEIGHT / 2 + y_column;
//
//             // draw_line(mlx, x_coor(mlx, i), y_coor(mlx, i), x_coor(mlx, i + 1), y_coor(mlx, i + 1));
//             // printf("x: %f y: %f x_column: %f y_column: %f\n", x, y, x, y_column);
//
//             if (row > 0)
//             {
//                 draw_line(mlx, x_prev, y_prev, x , y);
//                 if (column != mlx->map->height)
//                     draw_line(mlx, x, y, x, y_column);
//                 printf("x: %f y: %f x_column: %f y_column: %f\n", x, y, x, y_column);
//                 x_prev = x;
//                 y_prev = y;
//             }
//             else if (row == 0)
//             {
//                 x_prev = x;
//                 y_prev = y;
//
//                 if (column != mlx->map->height - 1)
//                     draw_line(mlx, x, y, x, y_column);
//                 column++;
//             }
//             // if (column < mlx->map->height)
//             //     draw_line(mlx, x, y, x, y_column);
//             // printf("x: %f y: %f z: %f\n", x, y, z);
//             // plot_pixel(mlx,x,y);
//             row++;
//         }
//         if ((row == mlx->map->width) && (row = 0))
//             i = i - 2;
//
//
//         //
//         // //scale image
//         // x = x * mlx->map->scale_factor;
//         // y = y * mlx->map->scale_factor;
//         // z = z * mlx->map->scale_factor;
//         //
//         // //rotate_x;
//         // theta = degrees_to_radians(90);
//         // y = y * cos(theta) - z * sin(theta);
//         // z = y * cos(theta) + z * sin(theta);
//         //
//         // //center
//         // x = x + WIDTH / 2 - (mlx->map->width * mlx->map->scale_factor) /2;
//         // y = HEIGHT / 2 + y;
//         // // printf("x:%f y:%f ", x, y);
//         // plot_pixel(mlx, x, y);
//
//         i++;
//         printf("\n");
//     }
//     mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img->img, 0 , 0);
// }

// void render(t_mlx *mlx)
// {
//     float x;
//     float y;
//     float z;
//     float theta;
//     int i;
//
//     clear_image(mlx->img);
//     printf("render scale_factor: %f\n", mlx->map->scale_factor);
//     i = 0;
//     while (i < mlx->map->width * mlx->map->height)
//     {
//         x = i % mlx->map->width;
//         y = i / mlx->map->width;
//         z = mlx->map->coords[i][0];
//
//         //scale image
//         x = x * mlx->map->scale_factor;
//         y = y * mlx->map->scale_factor;
//         z = z * mlx->map->scale_factor;
//
//         //rotate_x;
//         theta = degrees_to_radians(90);
//         y = y * cos(theta) - z * sin(theta);
//         z = y * cos(theta) + z * sin(theta);
//
//         //center
//         x = x + WIDTH / 2 - (mlx->map->width * mlx->map->scale_factor) /2;
//         y = HEIGHT / 2 + y;
//         // printf("x:%f y:%f ", x, y);
//         plot_pixel(mlx, x, y);
//
//         i++;
//     }
//     mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img->img, 0 , 0);
// }
