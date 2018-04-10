/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 22:31:56 by lilam             #+#    #+#             */
/*   Updated: 2018/04/09 22:37:23 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	clear_image(t_img *img)
{
	ft_bzero(img->img_ptr, WIDTH * HEIGHT * img->bpp);
}
