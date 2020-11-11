/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 23:33:03 by fheaton-          #+#    #+#             */
/*   Updated: 2020/11/11 20:42:30 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern int g_error;

int		write_map(t_map *map)
{
	int a;
	int b;
	int c;

	a = -1;
	b = -1;
	while (++b < map->height)
	{
		while (++a < map->width)
		{
			if (a >= (map->pos % map->width) && a <= ((map->pos + map->biggest_size - 1) % map->width)
				&& b >= (map->pos / map->width) && b <= ((map->pos + (map->biggest_size - 1) * map->width) / map->width))
				ft_putchar(map->full);
			else if (a == 0 && b == 0 && (map->obs_count[a] == 1))
				ft_putchar(map->obstacle);
			else if (a == 0 && b == 0)
				ft_putchar(map->empty);

			else if (b == 0 && (map->obs_count[a] > map->obs_count[a - 1]))
				ft_putchar(map->obstacle);
			else if (b == 0 && (map->obs_count[a] == map->obs_count[a - 1]))
				ft_putchar(map->empty);
			else if	(a == 0 && (map->obs_count[b * map->width] > map->obs_count[(b - 1) * map->width]))
				ft_putchar(map->obstacle);
			else if (a == 0 && (map->obs_count[b * map->width] == map->obs_count[(b - 1) * map->width]))
				ft_putchar(map->empty);
			else
			{
				c = map->obs_count[a + b * map->width] - map->obs_count[(a - 1) + b * map->width]
					- map->obs_count[a + (b - 1) * map->width] + map->obs_count[a - 1 + (b - 1) * map->width];
				if (c)
					ft_putchar(map->obstacle);
				else
					ft_putchar(map->empty);
			}
		}
		if (a == map->width && b == map->height)
			ft_putchar('\r');
		else if (a == map->width)
			ft_putchar('\n');
		a = -1;
	}
	return (1);
}
