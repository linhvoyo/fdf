/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 22:29:11 by lilam             #+#    #+#             */
/*   Updated: 2018/04/09 22:30:16 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_scale(t_map *map)
{
	int width;
	int height;

	width = WIDTH / (map->width * 2);
	if (map->d_max > map->height)
		height = HEIGHT / (map->d_max * 2);
	else
		height = HEIGHT / (map->height * 2);
	if (height <= width)
		map->scale_factor = height;
	else
		map->scale_factor = width;
	if (map->scale_factor < 1)
		map->scale_factor = 1;
}
