/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 15:13:42 by lilam             #+#    #+#             */
/*   Updated: 2018/04/09 22:27:56 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define RENDER render(mlx); return (0);

void	reset_img(t_mlx *mlx)
{
	set_scale(mlx->map);
	mlx->map->degrees_x = 65;
	mlx->map->degrees_y = 30;
	mlx->map->degrees_z = -15;
	mlx->map->offset_x = 0;
	mlx->map->offset_y = 0;
}

void	zero_img(t_mlx *mlx)
{
	set_scale(mlx->map);
	mlx->map->degrees_x = 0;
	mlx->map->degrees_y = 0;
	mlx->map->degrees_z = 0;
	mlx->map->offset_x = 0;
	mlx->map->offset_y = 0;
	render(mlx);
}

void	shift_img(t_mlx *mlx, int key)
{
	if (key == 126)
		mlx->map->offset_y -= 1;
	else if (key == 125)
		mlx->map->offset_y += 1;
	else if (key == 123)
		mlx->map->offset_x -= 1;
	else if (key == 124)
		mlx->map->offset_x += 1;
}

int		deal_key(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 24 || key == 69)
		mlx->map->scale_factor++;
	else if (key == 78 || key == 27)
		mlx->map->scale_factor--;
	else if (key == 12)
		mlx->map->degrees_x -= 1;
	else if (key == 13)
		mlx->map->degrees_x += 1;
	else if (key == 0)
		mlx->map->degrees_y -= 1;
	else if (key == 1)
		mlx->map->degrees_y += 1;
	else if (key == 6)
		mlx->map->degrees_z += 1;
	else if (key == 7)
		mlx->map->degrees_z -= 1;
	else if (key == 29)
		reset_img(mlx);
	else if (key >= 123 && key <= 126)
		shift_img(mlx, key);
	else
		return (0);
	RENDER;
}

int		mouse(int mouse, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (mouse == 2)
		zero_img(mlx);
	return (0);
}
