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

void test(char *color)
{
    // printf("%d\n", 0xFFFFFFF);
    // printf("%d\n", 0xFF0000 );

    //
    // char *color = "0xFFFAFA";
    //

    while (*color)
    {
        if (*color == 'x')
        {
            color++;
            break;
        }
        color++;
    }

    printf("%s\n", color);
    int i = 0;

    int power = 16;
    int num = 0;
    int val;

    while(i < 2)
    {
        val = color[i] - 'A' + 10;
        num = num + val * power;
        power = power / power;
        i++;
    }
    printf("%d\n", color[i] - 'A' + 10);
    printf("%d\n", num);


    printf("hello there \n\n");

    //
    // printf("%d\n", (int)"0xFFFFFFF");
    // printf("%s\n", (char)(4775720));



    // color = color + 4;
    //     int test = parse_color(color);
    //     printf("%d %s\n", test, color);

    //
    // printf("hello there \n\n");



    while (*color)
    {
        int test = parse_color(color);
        printf("%d %s\n", test, color);
        color = color + 2;
    }



}


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

    // test("0x810202");

    mlx = init_mlx(argv[1]);
    map = init_map();
    mlx->map = map;
    // test_plot_pixel(mlx, 542, 325, 0xFFFFFFF);

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
