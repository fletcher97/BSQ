/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:14:22 by mgueifao          #+#    #+#             */
/*   Updated: 2020/11/11 21:14:22 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check(int r, int c, t_map *map)
{
	int current;

	if (r + map->biggest_size >= map->height)
		return (3);
	if (c + map->biggest_size >= map->width)
		return (2);
	current = map->obs_count[c + map->biggest_size + ((r + map->biggest_size) * map->width)];
	if (c == 0 && r == 0 && current != 0)
		return (1);
	else if (c != 0 && r == 0 && (current - map->obs_count[(c - 1) + (r + map->biggest_size) * map->width]))
		return (1);
	else if (c == 0 && r != 0 && (current - map->obs_count[c + map->biggest_size + (r - 1) * map->width]))
		return (1);
	else if (c != 0 && r != 0 && (((current - (map->obs_count[(c - 1) + (r + map->biggest_size) * map->width]))\
		- (map->obs_count[c + map->biggest_size + (r - 1) * map->width]))\
		+ (map->obs_count[c - 1 + (r - 1) * map->width])))
		return (1);
	return (0);
}

int	process(t_map *map)
{
	int i;
	int j;
	int done;

	i = -1;
	done = 0;
	while (++i < map->height && done < 3)
	{
		j = -1;
		done = 0;
		while (++j < map->width && done < 2)
			while(!(done = check(i, j, map)))
			{
				map->biggest_size++;
				map->pos = i * map->width + j;
			}
	}
	return (1);
}
