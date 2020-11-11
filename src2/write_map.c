/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 23:33:03 by fheaton-          #+#    #+#             */
/*   Updated: 2020/11/11 23:18:12 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern int g_error;

int		put_full(int a, int b, t_map *map)
{
	if (a >= (map->pos % map->width) && a <= ((map->pos + map->biggest_size - 1) % map->width)
		&& b >= (map->pos / map->width) && b <= ((map->pos + (map->biggest_size - 1) * map->width) / map->width))
		return (1);
	else
		return (0);
}

int		put_obstacle(int a, int b, t_map *map)
{
	if ((a == 0 && b == 0 && (map->obs_count[a] == 1)) || (b == 0 && (map->obs_count[a] > map->obs_count[a - 1])) || \
				(a == 0 && (map->obs_count[b * map->width] > map->obs_count[(b - 1) * map->width])))
		return (1);
	else
		return (0);
}

int		put_empty(int a, int b, t_map *map)
{
	if ((a == 0 && b == 0) || (b == 0 && (map->obs_count[a] == map->obs_count[a - 1])) || \
		(a == 0 && (map->obs_count[b * map->width] == map->obs_count[(b - 1) * map->width])))
		return (1);
	else
		return (0);
}

int		write_map(t_map *map)
{
	int a;
	int b;

	b = -1;
	while (++b < map->height)
	{
		a = -1;
		while (++a < map->width)
		{
			if (put_full(a, b, map))
				ft_putchar(map->full);
			else if (put_obstacle(a, b, map))
				ft_putchar(map->obstacle);
			else if (put_empty(a, b, map))
				ft_putchar(map->empty);
			else
				if (map->obs_count[a + b * map->width] - map->obs_count[(a - 1) + b * map->width]
					- map->obs_count[a + (b - 1) * map->width] + map->obs_count[a - 1 + (b - 1) * map->width])
					ft_putchar(map->obstacle);
				else
					ft_putchar(map->empty);
		}
		ft_putchar('\n');
	}
	return (1);
}
