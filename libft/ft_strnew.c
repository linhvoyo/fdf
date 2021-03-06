/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:03:49 by lilam             #+#    #+#             */
/*   Updated: 2017/12/01 17:18:35 by lilam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	str = (char*)malloc(size + 1);
	i = 0;
	if (str)
	{
		while (str[i])
		{
			str[i] = '\0';
			i++;
		}
	}
	return (str);
}
