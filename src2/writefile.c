/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writefile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 23:33:03 by fheaton-          #+#    #+#             */
/*   Updated: 2020/11/11 19:09:59 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern int g_error;

int		write_file(t_map *map)
{
	int a;
	int b;
	char *str;

	a = -1;
	b = -1;
	if (!(str = malloc((map->height) * (map->width))))
	{
		return (0);
		g_error = 2;
	}
	while (b++ < map->height)
	{
		while (a++ < map->width)
		{
			if (b == 0 && (map->obs_count[a] > map->obs_count[a - 1]))
			{
				str[a] = (map->obstacle);
			}
			else
			{
				str[a] = (map->empty);
			}
			if	(a == 0 && (map->obs_count[a] > map->obs_count[a - 1]))
			{
				str[a] = (map->obstacle);
			}
			else
			{
				str[a] = (map->empty);
			}
			if ((0 < a < (map->width)) && ((0 < b <(map->width)) && ((map->obs_count[a]) > (map->obs_count[a - 1]))))
			{
				str[a] = (map->obstacle);
			}
			else
			{
				str[a] = (map->empty);
			}
			a++;
		}
		b++;
	}
	
}
