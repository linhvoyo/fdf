/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 22:30:44 by lilam             #+#    #+#             */
/*   Updated: 2018/04/09 22:31:40 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	degrees_to_radians(float degrees)
{
	float radians;

	if (degrees == 0)
		return (0);
	radians = degrees * (PI / 180);
	return (radians);
}
