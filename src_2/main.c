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


int parse_color(char *str)
{
    int power;
    int i;
    int num;
    int val;

    i = 0;
    power = 16;
    num = 0;
    while(i < 2)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            val = str[i] - 'A' + 10;
        else if (str[i] >= 'a' && str[i] <= 'z')
            val = str[i] - 'a' + 10;
        else
            val = str[i] - '0';
        num = num + val * power;
        power = power / power;
        i++;
    }
    return (num);
}

int		main(int argc, char **argv)
{
    t_map *map;
    t_mlx *mlx;
    int fd;
    char *hex_color;

    fd = open(argv[1], O_RDONLY);
    if (argc > 3 || fd <= 0 )
        ft_putstr("MAP_ERROR\n");
    else
    {
        mlx = init_mlx(argv[1]);
        map = init_map();
        mlx->map = map;
        if (!argv[2])
            hex_color = "0xFFFFFF";
        else
            hex_color = argv[2];
        if (!read_file(fd, map, hex_color))
            ft_putstr("INVALID_FILE\n");
        else
        {
            build_map(mlx, map->coords = init_arr(map->width * map->height), fd = open(argv[1], O_RDONLY), hex_color);
            set_scale(map);
            printf("width: %d | height: %d | d_min: %d | d_max: %d\n", map->width, map->height, map->d_min, map->d_max);
            render(mlx);
            mlx_key_hook(mlx->win_ptr, deal_key, mlx);
            mlx_mouse_hook(mlx->win_ptr, mouse_up, mlx);
            mlx_loop(mlx->mlx_ptr);
        }
    }
    // if (!read_file(fd, map, hex_color))
    // {
    //     ft_putstr("INVALID_FILE\n");
    //     return (0);
    // }
    //
    // build_map(mlx, map->coords = init_arr(map->width * map->height), fd = open(argv[1], O_RDONLY), hex_color);
    // set_scale(map);
    // printf("width: %d | height: %d | d_min: %d | d_max: %d\n", map->width, map->height, map->d_min, map->d_max);
    //
    // render(mlx);
    //
    //
    // mlx_key_hook(mlx->win_ptr, deal_key, mlx);
    // mlx_mouse_hook(mlx->win_ptr, mouse_up, mlx);
    // mlx_loop(mlx->mlx_ptr);
    return (0);
}
