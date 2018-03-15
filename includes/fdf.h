/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 07:02:37 by linh              #+#    #+#             */
/*   Updated: 2018/02/24 07:02:39 by linh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
#include <fcntl.h>
# define HEIGHT 750
# define WIDTH 1280

typedef struct      s_coord
{
    int             **arr;
    struct s_coord  *next;
}                   t_coord;


t_coord *get_coord(int size);

typedef double v4si __attribute__((vector_size(16)));


typedef struct      s_map
{
    int             width;
    int             height;
    int             d_min;
    int             d_max;
    int             **tmp;
    int             **coords;
    // struct t_coord  *coords;
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
    double		    **zbuf;
}                   t_mlx;

// int read_file(int fd, t_map *map);
int read_file(int fd, t_map *map);
void draw_line(t_mlx *mlx);
// void add_to_list(t_coord **list, t_coord *new);
void add_to_list(t_coord **list, t_coord *new);
int **init_arr(int x);
int build_map(t_mlx *mlx, int **arr, int fd);

#endif
