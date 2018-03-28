/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:04:38 by linh              #+#    #+#             */
/*   Updated: 2018/03/07 13:05:16 by linh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "unistd.h"
#include "fdf.h"
#include <fcntl.h>
#include <stdio.h>


int		main(int argc, char **argv)
{
    t_map *map;
    t_mlx *mlx;
    int fd;

    fd = open(argv[1], O_RDONLY);

    if (argc != 2 || fd <= 0)
    {
        ft_putstr("MAP_ERROR\n");
        return (0);
    }
    printf("int fd %d\n", fd);
    mlx = init_mlx(argv[1]);
    map = init_map();
    mlx->map = map;
    read_file(fd, map);
    build_map(mlx, map->coords = init_arr(map->width * map->height), fd = open(argv[1], O_RDONLY));
    set_scale(map);
    printf("width: %d | height: %d | d_min: %d | d_max: %d\n", map->width, map->height, map->d_min, map->d_max);


    render(mlx);
    mlx_key_hook(mlx->win_ptr, deal_key, mlx);
    mlx_mouse_hook(mlx->win_ptr, mouse_up, mlx);
    // mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img->img, 0 , 0);
    mlx_loop(mlx->mlx_ptr);
    return (0);
}
