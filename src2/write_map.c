/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 23:33:03 by fheaton-          #+#    #+#             */
/*   Updated: 2020/11/11 20:04:44 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern int g_error;

int		write_map(t_map *map)
{
	int a;
	int b;

	a = -1;
	b = -1;
	while (++b < map->height)
	{
		while (++a < map->width)
		{
			if (a == 0 && b == 0 && (map->obs_count[a] > map->obs_count[a - 1]))
				ft_putchar(map->obstacle);
			else if (a == 0 && b == 0 && (map->obs_count[a] > map->obs_count[a - 1]))
				ft_putchar(map->empty);
			if (b == 0 && (map->obs_count[a] > map->obs_count[a - 1]))
				ft_putchar(map->obstacle);
			else if (b == 0 && !(map->obs_count[a] > map->obs_count[a - 1]))
				ft_putchar(map->empty);
			if	(a == 0 && (map->obs_count[a] > map->obs_count[a - 1]))
				ft_putchar(map->obstacle);
			else if (b == 0 && !(map->obs_count[a] > map->obs_count[a - 1]))
				ft_putchar(map->empty);
			if ((0 < a < (map->width)) && ((0 < b <(map->width)) && ((map->obs_count[a]) > (map->obs_count[a - 1]))))
				ft_putchar(map->obstacle);
			else if ((0 < a < (map->width)) && (0 < b <(map->width)) && !((map->obs_count[a]) > (map->obs_count[a - 1])))
				ft_putchar(map->empty);
		}
		if (a == map->width && b == map->height)
			ft_putchar('\r');
		else if (a == map->width)
			ft_putchar('\n');
		a = -1;
	}
}