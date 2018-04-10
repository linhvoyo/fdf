/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 07:02:37 by linh              #+#    #+#             */
/*   Updated: 2018/04/08 15:49:57 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

# define HEIGHT 750
# define WIDTH 1280
# define PI 3.1415

typedef struct      s_map
{
    int             width;
    int             height;
    int             d_min;
    int             d_max;
    float           scale_factor;
    float           degrees_x;
    float           degrees_y;
    float           degrees_z;
    float           offset_x;
    float           offset_y;
    int             **tmp;
    int             **coords;
}                  t_map;

typedef struct      s_img
{
    int             bpp;
    int             stride;
    int             endian;
    void            *img;
    char            *img_ptr;
}                   t_img;

typedef struct      s_mlx
{
    void            *mlx_ptr;
    void            *win_ptr;
    t_img           *img;
    t_map           *map;
}                   t_mlx;


int read_file(int fd, t_map *map, char *hex_color);
int build_map(t_mlx *mlx, int fd, char *hex_color);
// int build_map(t_mlx *mlx, int **arr, char *str);
int **parse_line(char *line, char *hex_color, int **coords);
int **init_arr(int x);
int count_x(char *line);

float degrees_to_radians(float degrees);

void set_scale(t_map *map);

// void plot_pixel(t_mlx *mlx, int x, int y);
void plot_pixel(t_mlx *mlx, int x, int y, float *coord);
int sign(int x);
// void draw_line(t_mlx *mlx, int x1, int y1, int x2, int y2);
void draw_line(t_mlx *mlx, float *coor_current, float *coor_next);
void transform(t_mlx *mlx, float *coord, int i);
void render(t_mlx *mlx);

void reset_img(t_mlx *mlx);
int deal_key(int key, t_mlx *mlx);
int mouse(int mouse, int x, int y, t_mlx *mlx);

void clear_image(t_img *img);

t_img   *init_img(t_mlx *mlx);
t_mlx   *init_mlx(char *str);
t_map *init_map();
void clear_image(t_img *img);



int parse_color(char *str);

void free_array(int **array, int size);

#endif
