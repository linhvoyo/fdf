/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:04:38 by linh              #+#    #+#             */
/*   Updated: 2018/04/09 23:09:45 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "unistd.h"
#include "fdf.h"
#include <fcntl.h>
#include <stdio.h>


int     parse_color(char *str)
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

t_img	*init_img(t_mlx *mlx)
{
	t_img	*tmp;

	if (!(tmp = malloc(sizeof(t_img))))
		return (NULL);
	tmp->img = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	tmp->img_ptr = mlx_get_data_addr(tmp->img,
			&tmp->bpp, &tmp->stride, &tmp->endian);
	tmp->bpp = tmp->bpp / 8;
	return (tmp);
}

t_mlx	*init_mlx(char *str)
{
	t_mlx *tmp;

	tmp = malloc(sizeof(t_mlx));
	if (!tmp)
		return (NULL);
	tmp->mlx_ptr = mlx_init();
	tmp->win_ptr = mlx_new_window(tmp->mlx_ptr, WIDTH, HEIGHT, str);
	tmp->img = init_img(tmp);
	return (tmp);
}

t_map	*init_map(void)
{
	t_map *tmp;

	tmp = malloc(sizeof(t_map));
	if (!tmp)
		return (NULL);
	else
		tmp->height = 0;
	tmp->d_min = 0;
	tmp->d_max = 0;
	tmp->scale_factor = 0;
	tmp->degrees_z = -15;
	tmp->degrees_y = 30;
	tmp->degrees_x = 65;
	tmp->offset_x = 0;
	tmp->offset_y = 0;
	return (tmp);
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
    else if ((mlx = init_mlx(argv[1])) && (map = init_map()))
    {
        mlx->map = map;
        !argv[2] ? hex_color = "0xFFFFFF" : (hex_color = argv[2]);
        if (!read_file(fd, map, hex_color))
            ft_putstr("MAP_ERROR\n");
        else if ((map->coords = init_arr(map->width * map->height)))
        {
            build_map(mlx, fd = open(argv[1], O_RDONLY), hex_color);
            set_scale(map);
            printf("width: %d | height: %d | d_min: %d | d_max: %d\n", map->width, map->height, map->d_min, map->d_max);
            render(mlx);
            mlx_key_hook(mlx->win_ptr, deal_key, mlx);
            mlx_mouse_hook(mlx->win_ptr, mouse, mlx);
            mlx_loop(mlx->mlx_ptr);
        }
    }
    return (0);
}
